#ifndef BASICBLOCK_HPP
#define BASICBLOCK_HPP
#include "midend/Value.hpp"
#include <list>
#include <sstream>

class Function;
class Instruction;
class Module;

/*
BasicBlock格式为
```LLVMIR
; <label>:entry
  %a = alloca i32
  store i32 42, i32* %a
  %val = load i32, i32* %a
  %cmp = icmp eq i32 %val, 0
  br i1 %cmp, label %if.then, label %if.else
```

（其他诸如函数名，形参列表等，由[`function`]负责）
*/

class BasicBlock : public Value {
private:
    Function *parent_;
    int loop_depth = 0; // 分析用
    std::list<BasicBlock *> pre_bbs_;
    std::list<BasicBlock *> succ_bbs_;
    static int baseBlockCounter;
    int baseBlockId;
    std::ostringstream IRCodeBuilder;
    std::string label;
    std::list<Instruction *> instr_list_;

private:
    explicit BasicBlock(std::string const &name, Function *parent);

public:
    static BasicBlock *create(std::string const &name, Function *parent);

    // basic methods
    bool empty() {
        return instr_list_.empty();
    }

    int getNumOfInstrs() {
        return instr_list_.size();
    }

    std::list<Instruction *> &getInstructions() {
        return instr_list_;
    }

    Function *getParent() {
        return parent_;
    }

    virtual std::string print() override;

    __attribute__((always_inline)) void addInstruction(Instruction *ins) {
        instr_list_.push_back(ins);
    }

    // CFG serial
    std::list<BasicBlock *> &getPreBasicBlocks() {
        return pre_bbs_;
    }

    std::list<BasicBlock *> &getSuccBasicBlocks() {
        return succ_bbs_;
    }

    void addPreBasicBlock(BasicBlock *bb) {
        pre_bbs_.push_back(bb);
    }
    void addSuccBasicBlock(BasicBlock *bb) {
        succ_bbs_.push_back(bb);
    }
    void removePreBasicBlock(BasicBlock *bb) {
        pre_bbs_.remove(bb);
    }
    void removeSuccBasicBlock(BasicBlock *bb) {
        succ_bbs_.remove(bb);
    }

    // Iterator
    __attribute__((always_inline)) std::list<Instruction *>::iterator
    findInstruction(Instruction *instr) {
        return std::find(instr_list_.begin(), instr_list_.end(), instr);
    }

    void replaceWithNewInstr(Instruction *old_ins, Instruction *new_ins);
    // 消除依赖关系
    void eraseFromParent();
    BasicBlock *copyBB();

    // 用于获取当前基本块（BasicBlock）的“终结指令”（terminator
    // instruction），例如 ret、br、cmpbr、fcmpbr 等控制流指令。它返回的是指向
    // Instruction 的指针。
    Instruction const *getVaildTerminator() const;

    void addInstrBeforeTeminator(Instruction *instr);
    void addInstrAfterPhiInst(Instruction *instr);
    void deleteInstr(Instruction *instr);

    using InstrListIter = ::std::list<Instruction *>::iterator ;
    InstrListIter eraseInstr(InstrListIter instr_iter);
    InstrListIter InsertInstr(InstrListIter instr_iter, Instruction *instr);

    Instruction const *getTerminator() const;
    Instruction *getTerminator() {
        return const_cast<Instruction *>(
            static_cast<BasicBlock const *>(this)->getTerminator());
    }
};
#endif
