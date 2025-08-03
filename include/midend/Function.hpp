#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include "Type.hpp"
#include "Value.hpp"
#include <assert.h>
#include <list>
#include <memory>
#include <string>
#include <vector>
class Argument;
class BasicBlock;
class Type;
class FunctionType;
class Value;
class Module;

class Function : public Value {
private:
    std::string functionName;
    Type *type;
    std::list<BasicBlock *> basic_blocks_;
    std::list<Argument *> arguments_;
    std::list<Value *> caller;
    std::list<Value *> callee;
    std::list<BasicBlock> retBlocks;
    size_t seq_cnt_;
    // 分开设计有利于整点和浮点reg的分配
    std::vector<Argument *> i_args_;
    std::vector<Argument *> f_args_;
    Module *parent_;

public:
    static Function *create(FunctionType *ty, std::string const &name,
                            Module *parent);

    Function(FunctionType *ty, std::string const &name, Module *parent);
    ~Function();

    FunctionType *getFunctionType() const {
        return static_cast<FunctionType *>(getType());
    }

    size_t getNumOfArgs() const {
        return getFunctionType()->getNumOfArgs();
    }

    Type *getReturnType() const {
        return getFunctionType()->getReturnType();
    }

    std::list<Argument *> &getArgs() {
        return arguments_;
    }

    bool isDeclaration() {
        return basic_blocks_.empty();
    }

    void setInstrName();
    std::string print() override;
    void buildArgs();
    std::string printGra();

    std::list<BasicBlock *> &getBasicBlocks() {
        return basic_blocks_;
    }

    unsigned getNumBasicBlocks() const {
        return basic_blocks_.size();
    }

    BasicBlock *getEntryBlock() const {
        return *basic_blocks_.begin();
    }

    BasicBlock *getRetBlock() const;

    void addBasicBlock(BasicBlock *bb);
    void removeBasicBlock(BasicBlock *bb);
    void updateCFGForCopiedBlock(BasicBlock *originalBB, BasicBlock *newBB);

    std::list<Argument *>::iterator argBegin() {
        return arguments_.begin();
    }

    std::list<Argument *>::iterator argEnd() {
        return arguments_.end();
    }
};

class Argument : public Value {
public:
    // Argument constructor.
    explicit Argument(Type *ty, std::string const &name = "",
                      Function *f = nullptr, size_t arg_no = 0)
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
    size_t getArgNo() const {
        assert(parent_ && "can't get number of unparented arg");
        return arg_no_;
    }

    virtual std::string print() override;

private:
    Function *parent_;
    size_t arg_no_; //& argument No.
};
#endif
