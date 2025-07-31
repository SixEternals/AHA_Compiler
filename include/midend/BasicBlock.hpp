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
    int loop_depth = 0;
    std::list<BasicBlock *> pre_bbs_;
    std::list<BasicBlock *> succ_bbs_;
    static int baseBlockCounter;
    int baseBlockId;
    std::ostringstream IRCodeBuilder;
    std::string label;
    std::list<Instruction *> instr_list_;
    // std::list<>
private:
    explicit BasicBlock(std::string const &name, Function *parent);

public:
    static BasicBlock *create(std::string const &name, Function *parent);

    Function *getParent() {
        return parent_;
    }

    void addPreBasicBlock(BasicBlock *bb) {
        pre_bbs_.push_back(bb);
    }

    void addSuccBasicBlock(BasicBlock *bb) {
        succ_bbs_.push_back(bb);
    }

    virtual std::string print() override;

    __attribute__((always_inline)) void addInstruction(Instruction *ins) {
        instr_list_.push_back(ins);
    }
};
#endif
