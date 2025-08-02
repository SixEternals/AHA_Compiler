#include "midend/BasicBlock.hpp"
#include "midend/Function.hpp"
#include "midend/Instruction.hpp"
#include <cassert>
#include <map>
#include <ostream>

int BasicBlock::baseBlockCounter = 0;

BasicBlock::BasicBlock(std::string const &name, Function *parent = nullptr)
    : Value(Type::getLabelType(), name),
      parent_(parent) {
    assert(parent && "currently parent should not be a nullptr");
    parent_->addBasicBlock(this);
}

/*
输出示例：
entry:                                                ; preds = %bb1, %bb2
  %1 = add i32 %a, %b                                       ↑注释
  %2 = mul i32 %1, %c
*/
std::string BasicBlock::print() {
  // 关于oss，比较推荐创建局部变量，如果是作为成员变量的话，不好处理多线程冲突
  std::ostringstream bb_ir;
  bb_ir << getName() << ":";
  auto pre_bbs = this->getPreBasicBlocks();
  if(!pre_bbs.empty()){
      bb_ir << "                                                ; preds = ";
  }

  bool first{true};
  for (auto bb: pre_bbs){
    if(!first){
      bb_ir << ", ";
    }
    bb_ir << "%" << bb->getName();
    first = false;
  }
  if (!this->getParent()){
      bb_ir << "\n; Error: Block without parent!";
      assert(false && "Error: Block without parent!");
  }
  bb_ir << "\n";

  for(auto instr : this->getInstructions()){
      bb_ir << "  " << instr->print() << '\n';
  }
  return bb_ir.str();
}

/*
BB不可以直接暴力复制，特别是对于Br和PHI这类涉及到basicblock跳转的指令
不然会跳回到原来的旧BB
*/
BasicBlock* BasicBlock::copyBB(){
  auto new_bb = BasicBlock::create("", this->getParent());
  // instruction mapping
  std::map<Instruction*, Instruction*> instMap;
  // [`direct`] mapping
  for (auto instr: instr_list_){
    auto new_instr = instr->copyInst(new_bb);
    if(instr->isPhi()){
      // PHI put together
      new_bb->addInstrAfterPhiInst(new_instr);
    }else{
      // other insert directly
      new_bb->addInstruction(new_instr);
    }
    instMap[instr] = new_instr;
  }
  // replace with coresponding [`operands`] in new instruction
  for(auto instr: new_bb->getInstructions()){
    auto& ops = instr->getOperands();
    for(int i = 0; i < ops.size(); ++i){
        if(auto oldInstr = dynamic_cast<Instruction*>(ops[i])){
          // operands也需要更新为对应的
          if(instMap.count(oldInstr)){
            instr->replaceOperand(i, instMap[oldInstr]);
          }
        }
    }
  }

  // update pred and succ BBs
  // but i don't think this is a good maneuver
  // [`逻辑外移到Function的updateCFGForCopiedBlock()`]
  // for(auto bb: getPreBasicBlocks()){
  //   new_bb->addPreBasicBlock(bb);
  // }
  // for(auto bb: getSuccBasicBlocks()){
  //   new_bb->addSuccBasicBlock(bb);
  // }

  // 特殊处理Br和PHI
  for (Instruction *newInst: new_bb->getInstructions()) {
      if (newInst->isBr() || newInst->isCmp()) {
          // 如果是跳转指令，更新目标基本块
          auto &ops = newInst->getOperands();
          for (int i = 0; i < ops.size(); ++i) {
              if (auto *targetBB = dynamic_cast<BasicBlock *>(ops[i])) {
                  if (targetBB == this) {
                      newInst->replaceOperand(i, new_bb); // 替换目标为新基本块
                  }
              }
          }
      } else if (newInst->isPhi()) {
          // 如果是 PHI 指令，更新来自前驱基本块的值
          auto &ops = newInst->getOperands();
          for (int i = 0; i < ops.size(); i += 2) {
              if (auto *bb = dynamic_cast<BasicBlock *>(ops[i + 1])) {
                  if (bb == this) {
                      newInst->replaceOperand(
                          i + 1, new_bb); // 替换来源基本块为新基本块
                  }
              }
          }
      }
  }
  return new_bb; 
}

BasicBlock *BasicBlock::create(std::string const &name, Function *parent) {
    auto label = name.empty() ? "" : "label_";
    return new BasicBlock(label, parent);
}

Instruction const *BasicBlock::getVaildTerminator() const {
    if (instr_list_.empty()) {
        return nullptr;
    }
    //
    switch (instr_list_.back()->getInstrType()) {
    case Instruction::OpID::ret:    return instr_list_.back();
    case Instruction::OpID::br:     return instr_list_.back();
    case Instruction::OpID::cmpbr:  return instr_list_.back();
    case Instruction::OpID::fcmpbr: return instr_list_.back();
    default:                        return nullptr;
    }
}
void BasicBlock::addInstrBeforeTeminator(Instruction *instr){
  instr->setParent(this);
  auto terminator = instr_list_.back();
  instr_list_.pop_back();

  if(auto *br = dynamic_cast<BranchInst*>(terminator)){
    if(br->isCondBr()){
      auto cmp = instr_list_.back();
      if (dynamic_cast<CmpInst *>(cmp) || dynamic_cast<FCmpInst *>(cmp)){
        instr_list_.pop_back();
        instr_list_.push_back(instr);
        instr_list_.push_back(cmp);
        instr_list_.push_back(terminator);
        return;
      }
    }
    instr_list_.push_back(instr);
    instr_list_.push_back(terminator);
    return;
  }
  // 其他类型的terminator，如RetInst, CmpBrInst, SwitchInst...
  instr_list_.push_back(instr);
  instr_list_.push_back(terminator);
}

void BasicBlock::addInstrAfterPhiInst(Instruction* instr){
  instr->setParent(this);
  auto pos = std::find_if_not(instr_list_.begin(), instr_list_.end(), [](Instruction* instr){
    return instr->isPhi();
  });
  instr_list_.insert(pos, instr);
}

// todo 待测试
void BasicBlock::deleteInstr(Instruction *instr) {
    // 先清理引用关系再删除指令
    instr->removeUseOfOps();
    auto iterator = findInstruction(instr);
    if(iterator!= instr_list_.end()){
      instr_list_.erase(iterator);
      delete instr;
    }
}

using InstrListIter = ::std::list<Instruction *>::iterator;
InstrListIter BasicBlock::eraseInstr(InstrListIter instr_iter){
  auto instr = *instr_iter;
  auto ret = instr_list_.erase(instr_iter);
  instr->removeUseOfOps();
  delete instr;
  return ret;
}
InstrListIter BasicBlock::InsertInstr(InstrListIter instr_iter, Instruction *instr){
  return instr_list_.insert(instr_iter, instr);
}

void BasicBlock::replaceWithNewInstr(Instruction *old_ins, Instruction *new_ins){
  auto iter = findInstruction(old_ins);
  *iter = new_ins;
  new_ins->setParent(this);
  old_ins->replaceAllUseWith(new_ins); // ▲
  delete old_ins;
}
void BasicBlock::eraseFromParent(){
  // this->getParent()->removeBasicBlock(this);
  auto parent = this->getParent();
  if(parent){
    parent->removeBasicBlock(this);
  }else{
      assert(false && "This BasicBlock has no parent to erase from!");
  }
}

