#include "midend/Function.hpp"
#include <cstddef>
#include <map>
#include <memory>

void Function::buildArgs(){
  auto function_type = getFunctionType();
  size_t num_args = getNumOfArgs();
  for(size_t i{0}; i< num_args; ++i){
    auto arg = new Argument(function_type->getParamType(i), "",this,i);
    arguments_.push_back(arg);
    if(arg->getType()->isFloatType()){
        f_args_.push_back(arg);
    }else if(arg->getType()->isIntegerType()){
        i_args_.push_back(arg);
    }
  }
}

Function::Function(FunctionType *ty, std::string const &name, Module *parent)
    : Value(ty, name),
      parent_(parent),
      seq_cnt_(0) {
    // parent->addFunction(this);
    buildArgs();
}
void Function::setInstrName() {
    std::map<Value *, int> seq;
    for (auto const &arg: this->getArgs()) {
        if (seq.find(&*arg) == seq.end()) {
            auto seq_num = seq.size() + seq_cnt_;
            if (arg->setName("arg" + std::to_string(seq_num))) {
                seq.insert({&*arg, seq_num});
            }
        }
    }
    for (auto &bb1: baseBlocks) {
        auto bb = bb1;
        if (seq.find(bb) == seq.end()) {
            auto seq_num = seq.size() + seq_cnt_;
#ifdef DEBUG
            std::string f_name = this->getName();
            if (bb->setName(f_name + "_label_" + std::to_string(seq_num))) {
                seq.insert({bb, seq_num});
            }
#else
            if (bb->setName("label" + std::to_string(seq_num))) {
                seq.insert({bb, seq_num});
            }
#endif
        }
        // todo: 没写完Instruction
        //         for (auto &instr: bb->getInstructions()) {
        //             if (!instr->isVoid() && seq.find(instr) == seq.end()) {
        //                 auto seq_num = seq.size() + seq_cnt_;
        // #ifdef DEBUG
        //                 std::string f_name = this->getName();
        //                 if (instr->setName(f_name + "_op_" +
        //                 std::to_string(seq_num))) {
        //                     seq.insert({instr, seq_num});
        //                 }
        // #else
        //                 if (instr->setName("op" + std::to_string(seq_num))) {
        //                     seq.insert({instr, seq_num});
        //                 }
        // #endif
        //             }
        //         }
    }
    seq_cnt_ += seq.size();
}

std::string Function::print() {
    setInstrName();
    std::string func_ir;
    if (this->isDeclaration()) {
        func_ir += "declare ";
    } else {
        func_ir += "define ";
    }

    // func_ir += this->getReturnType()->print();
    // func_ir += " ";
    // func_ir += "@" + this->getName();
    // func_ir += "(";

    // //// print arg
    // if (this->isDeclaration()) {
    //     for (int i = 0; i < this->getNumOfArgs(); i++) {
    //         if (i) {
    //             func_ir += ", ";
    //         }
    //         func_ir += static_cast<FunctionType *>(this->getType())
    //                        ->getParamType(i)
    //                        ->print();
    //     }
    // } else {
    //     for (auto arg = this->argBegin(); arg != argEnd(); arg++) {
    //         if (arg != this->argBegin()) {
    //             func_ir += ", ";
    //         }
    //         func_ir += (*arg)->print();
    //     }
    // }
    func_ir += ")";

    //// print bb
    if (this->isDeclaration()) {
        func_ir += "\n";
    } else {
        func_ir += " {";
        func_ir += "\n";
        // for (auto &bb: this->getBasicBlocks()) {
        //     func_ir += bb->print();
        // }
        func_ir += "}";
    }

    return func_ir;
}

void Function::addBasicBlock(BasicBlock *bb) {
    baseBlocks.push_back(bb);
}


void Function::removeBasicBlock(BasicBlock *bb) {
  baseBlocks.erase(std::find(baseBlocks.begin(), baseBlocks.end(), bb));
  // 删除依赖关系
  for (auto pre : bb->getPreBasicBlocks()){
    pre->removePreBasicBlock(bb);
  }
  for(auto succ : bb->getSuccBasicBlocks()){
    succ->removeSuccBasicBlock(bb);
  }
}