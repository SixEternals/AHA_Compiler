#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include "midend/BasicBlock.hpp"
#include "midend/Type.hpp"
#include "midend/Value.hpp"
#include <assert.h>
#include <list>
#include <memory>
#include <string>
#include <vector>

class Argument;

class Function : public Value {
private:
    std::string functionName;
    Type *type;
    std::list<BasicBlock *> baseBlocks;
    std::list<Argument *> paramsValue;
    std::list<Value *> caller;
    std::list<Value *> callee;
    std::list<BasicBlock> retBlocks;
    unsigned seq_cnt_;

public:
    Function(std::string functionName, FunctionType *type);

    FunctionType *getFunctionType() const {
        return static_cast<FunctionType *>(getType());
    }

    unsigned getNumOfArgs() const {
        return getFunctionType()->getNumOfArgs();
    }

    Type *getReturnType() const {
        return getFunctionType()->getReturnType();
    }

    std::list<Argument *> &getArgs() {
        return paramsValue;
    }

    bool isDeclaration() {
        return baseBlocks.empty();
    }

    void setInstrName();
    std::string print() override;
    void addBasicBlock(BasicBlock *bb);
};

class Argument : public Value {
public:
    // Argument constructor.
    explicit Argument(Type *ty, std::string const &name = "",
                      Function *f = nullptr, unsigned arg_no = 0)
        : Value(ty, name),
          parent_(f),
          arg_no_(arg_no) {}

    virtual ~Argument() {}

    inline Function const *getParent() const {
        return parent_;
    }

    inline Function *getParent() {
        return parent_;
    }

    // For example in "void foo(int a, float b)" a is 0 and b is 1.
    unsigned getArgNo() const {
        assert(parent_ && "can't get number of unparented arg");
        return arg_no_;
    }

    virtual std::string print() override;

private:
    Function *parent_;
    unsigned arg_no_; //& argument No.
};
#endif
