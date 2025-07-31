#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP
#include "midend/Type.hpp"
#include "midend/User.hpp"
#include "midend/Value.hpp"
#include <memory>
#include <string>

class Module;
class BasicBlock;
class Function;

class Instruction : public User {
public:
    enum class OpID {
        //& Terminator Instructions
        /*
        其他还有switchInst,
        */
        ret,
        br,
        //& Standard binary operators 算术/位运算
        add,
        sub,
        mul,
        mul64,
        sdiv, // 有符号除
        srem, // 有符号取模
        //& float binary operators
        fadd,
        fsub,
        fmul,
        fdiv,
        //& Memory operators
        alloca,
        load,
        store,
        memset,
        //& Other operators
        cmp,
        fcmp,
        phi,
        call,
        getelementptr,
        //& Logical operators
        land,
        lor,
        lxor,
        //& Shift operators
        asr, // 算数右移
        shl, // 左移
        lsr, // 逻辑右移
        asr64,
        shl64,
        lsr64,
        //& Zero extend
        // 零扩展位，如i8 -> i32，需要在前面补零
        zext,
        //& type cast bewteen float and singed integer
        fptosi, // float point to signed integer，即`截断`
        sitofp, // signed integer to float point，用于让整数参与浮点数计算
        //& LIR operators
        cmpbr,      // Compare + Branch，`比较`两个值，然后按结果`跳转`
        fcmpbr,
        loadoffset, // load offset，从地址`base +
                    // offset`中加载内存。作用：为数组、结构体成员、栈帧生成偏移访问代码
        storeoffset,
        select,  // 三元运算符
        loadimm, // Load Immediate，加载一个立即数/字面量常量
        bitcast, // 强制类型转换，但是只能大小相同的类型转换
    };

public:
    OpID getInstrType() {
        return op_id_;
    }

    /// get Instruction name by String
    static std::string getInstrOpName(OpID id) {
        switch (id) {
        case OpID::ret: return "ret"; break;
        case OpID::br:  return "br"; break;

        case OpID::add:   return "add"; break;
        case OpID::sub:   return "sub"; break;
        case OpID::mul:   return "mul"; break;
        case OpID::mul64: return "mulh64"; break;
        case OpID::sdiv:  return "sdiv"; break;
        case OpID::srem:  return "srem"; break;

        case OpID::fadd: return "fadd"; break;
        case OpID::fsub: return "fsub"; break;
        case OpID::fmul: return "fmul"; break;
        case OpID::fdiv: return "fdiv"; break;

        case OpID::alloca: return "alloca"; break;
        case OpID::load:   return "load"; break;
        case OpID::store:  return "store"; break;
        case OpID::memset: return "memset"; break;

        case OpID::cmp:           return "cmp"; break;
        case OpID::fcmp:          return "fcmp"; break;
        case OpID::phi:           return "phi"; break;
        case OpID::call:          return "call"; break;
        case OpID::getelementptr: return "getelementptr"; break;

        case OpID::land: return "and"; break;
        case OpID::lor:  return "or"; break;
        case OpID::lxor: return "xor"; break;

        case OpID::asr:   return "ashr"; break;
        case OpID::shl:   return "shl"; break;
        case OpID::lsr:   return "lshr"; break;
        case OpID::asr64: return "asr64"; break;
        case OpID::shl64: return "shl64"; break;
        case OpID::lsr64: return "lsr64"; break;

        case OpID::zext: return "zext"; break;

        case OpID::fptosi: return "fptosi"; break;
        case OpID::sitofp: return "sitofp"; break;

        case OpID::cmpbr:       return "cmpbr"; break;
        case OpID::fcmpbr:      return "fcmpbr"; break;
        case OpID::loadoffset:  return "loadoffset"; break;
        case OpID::storeoffset: return "storeoffset"; break;
        case OpID::select:      return "select"; break;
        case OpID::loadimm:     return "loadimm"; break;
        default:                return ""; break;
        }
    }

public:
    //& create instruction, auto insert to bb, ty here is result type
    Instruction(Type *ty, OpID id, unsigned num_ops, BasicBlock *parent);
    Instruction(Type *ty, OpID id, unsigned num_ops);

    inline BasicBlock const *getParent() const {
        return parent_;
    }

    inline BasicBlock *getParent() {
        return parent_;
    }

    void setParent(BasicBlock *parent) {
        this->parent_ = parent;
    }

    //// Return the function this instruction belongs to.
    Function *getFunction();

    bool isVoid() {
        return ((op_id_ == OpID::ret) || (op_id_ == OpID::br) ||
                (op_id_ == OpID::store) || (op_id_ == OpID::cmpbr) ||
                (op_id_ == OpID::fcmpbr) || (op_id_ == OpID::storeoffset) ||
                (op_id_ == OpID::memset) ||
                (op_id_ == OpID::call && this->getType()->isVoidType()));
    }

    bool isRet() {
        return op_id_ == OpID::ret;
    }

    bool isBr() {
        return op_id_ == OpID::br;
    }

    bool isAdd() {
        return op_id_ == OpID::add;
    }

    bool isSub() {
        return op_id_ == OpID::sub;
    }

    bool isMul() {
        return op_id_ == OpID::mul;
    }

    bool isMul64() {
        return op_id_ == OpID::mul64;
    }

    bool isDiv() {
        return op_id_ == OpID::sdiv;
    }

    bool isRem() {
        return op_id_ == OpID::srem;
    }

    bool isFAdd() {
        return op_id_ == OpID::fadd;
    }

    bool isFSub() {
        return op_id_ == OpID::fsub;
    }

    bool isFMul() {
        return op_id_ == OpID::fmul;
    }

    bool isFDiv() {
        return op_id_ == OpID::fdiv;
    }

    bool isAlloca() {
        return op_id_ == OpID::alloca;
    }

    bool isLoad() {
        return op_id_ == OpID::load;
    }

    bool isStore() {
        return op_id_ == OpID::store;
    }

    bool isMemset() {
        return op_id_ == OpID::memset;
    }

    bool isCmp() {
        return op_id_ == OpID::cmp;
    }

    bool isFCmp() {
        return op_id_ == OpID::fcmp;
    }

    bool isPhi() {
        return op_id_ == OpID::phi;
    }

    bool isCall() {
        return op_id_ == OpID::call;
    }

    bool isGep() {
        return op_id_ == OpID::getelementptr;
    }

    bool isAnd() {
        return op_id_ == OpID::land;
    }

    bool isOr() {
        return op_id_ == OpID::lor;
    }

    bool isXor() {
        return op_id_ == OpID::lxor;
    }

    bool isAsr() {
        return op_id_ == OpID::asr;
    }

    bool isLsl() {
        return op_id_ == OpID::shl;
    }

    bool isLsr() {
        return op_id_ == OpID::lsr;
    }

    bool isAsr64() {
        return op_id_ == OpID::asr64;
    }

    bool isLsl64() {
        return op_id_ == OpID::shl64;
    }

    bool isLsr64() {
        return op_id_ == OpID::lsr64;
    }

    bool isZext() {
        return op_id_ == OpID::zext;
    }

    bool isFptosi() {
        return op_id_ == OpID::fptosi;
    }

    bool isSitofp() {
        return op_id_ == OpID::sitofp;
    }

    bool isCmpBr() {
        return op_id_ == OpID::cmpbr;
    }

    bool isFCmpBr() {
        return op_id_ == OpID::fcmpbr;
    }

    bool isLoadOffset() {
        return op_id_ == OpID::loadoffset;
    }

    bool isStoreOffset() {
        return op_id_ == OpID::storeoffset;
    }

    bool isExtendBr() {
        return (op_id_ == OpID::br || op_id_ == OpID::cmpbr ||
                op_id_ == OpID::fcmpbr);
    }

    bool isExtendCondBr() const {
        return getNumOperands() == 3 || getNumOperands() == 4;
    }

    bool isIntBinary() {
        return (isAdd() || isSub() || isMul() || isDiv() || isRem() ||
                isMul64() || isAnd() || isOr() || isXor() || isAsr() ||
                isLsl() || isLsr() || isAsr64() || isLsl64() || isLsr64()) &&
               (getNumOperands() == 2);
    }

    bool isFloatBinary() {
        return (isFAdd() || isFSub() || isFMul() || isFDiv()) &&
               (getNumOperands() == 2);
    }

    bool isBinary() {
        return isIntBinary() || isFloatBinary();
    }

    bool isTerminator() {
        return isBr() || isRet() || isCmpBr() || isFCmpBr();
    }

    bool isWriteMem() {
        return isStore() || isStoreOffset();
    }

    bool isSelect() {
        return op_id_ == OpID::select;
    }

    bool isLoadImm() {
        return op_id_ == OpID::loadimm;
    }

    // void setId(int id) { id_ = id; }
    // int getId() { return id_; }

    virtual Instruction *copyInst(BasicBlock *bb) = 0;

    // todo:
    // 后端遍历
    // virtual void accept(IRVisitor &visitor) = 0;

private:
    OpID op_id_;
    // unsigned num_ops_;
    BasicBlock *parent_;
};

class BinaryInst : public Instruction {
public:
    static BinaryInst *create(OpID id, Value *v1, Value *v2);

    static BinaryInst *createAdd(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createSub(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createMul(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createMul64(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createSDiv(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createSRem(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createFAdd(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createFSub(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createFMul(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createFDiv(Value *v1, Value *v2, BasicBlock *bb);

    static BinaryInst *createAnd(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createOr(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createXor(Value *v1, Value *v2, BasicBlock *bb);

    static BinaryInst *createAsr(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createLsl(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createLsr(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createAsr64(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createLsl64(Value *v1, Value *v2, BasicBlock *bb);
    static BinaryInst *createLsr64(Value *v1, Value *v2, BasicBlock *bb);

    virtual std::string print() override;

    Instruction *copyInst(BasicBlock *bb) override final {
        return new BinaryInst(getType(), getInstrType(), getOperand(0),
                              getOperand(1), bb);
    }

    bool isNeg();

    // 后端遍历
    // todo
    // virtual void accept(IRVisitor &visitor) final;

private:
    BinaryInst(Type *ty, OpID id, Value *v1, Value *v2, BasicBlock *bb);
    BinaryInst(Type *ty, OpID id, Value *v1, Value *v2);
};

enum CmpOp {
    EQ, // ==
    NE, // !=
    GT, // >
    GE, // >=
    LT, // <
    LE  // <=
};

class CmpInst : public Instruction {
public:
    static CmpInst *createCmp(CmpOp op, Value *lhs, Value *rhs, BasicBlock *bb);

    CmpOp getCmpOp() {
        return cmp_op_;
    }

    void negation();

    virtual std::string print() override;

    Instruction *copyInst(BasicBlock *bb) override final {
        return new CmpInst(getType(), cmp_op_, getOperand(0), getOperand(1),
                           bb);
    }

    // todo: 后端遍历
    // virtual void accept(IRVisitor &visitor) final;

private:
    CmpInst(Type *ty, CmpOp op, Value *lhs, Value *rhs, BasicBlock *bb);
    //~ void assert_valid();

private:
    CmpOp cmp_op_;
};

class FCmpInst : public Instruction {
public:
    static FCmpInst *createFCmp(CmpOp op, Value *lhs, Value *rhs,
                                BasicBlock *bb);

    CmpOp getCmpOp() {
        return cmp_op_;
    }

    void negation();

    virtual std::string print() override;

    Instruction *copyInst(BasicBlock *bb) override final {
        return new FCmpInst(getType(), cmp_op_, getOperand(0), getOperand(1),
                            bb);
    }

    // todo: 后端遍历
    // virtual void accept(IRVisitor &visitor) final;

private:
    FCmpInst(Type *ty, CmpOp op, Value *lhs, Value *rhs, BasicBlock *bb);

    //~ void assert_valid();

private:
    CmpOp cmp_op_;
};

class CallInst : public Instruction {
public:
    static CallInst *createCall(Function *func, std::vector<Value *> args,
                                BasicBlock *bb);

    FunctionType *getFunctionType() const {
        return static_cast<FunctionType *>(getOperand(0)->getType());
    }

    virtual std::string print() override;

    Instruction *copyInst(BasicBlock *bb) override final {
        std::vector<Value *> args;
        for (auto i = 1; i < getNumOperands(); i++) {
            args.push_back(getOperand(i));
        }
        auto new_inst =
            new CallInst(getFunctionType()->getReturnType(), args, bb);
        new_inst->setOperand(0, getOperand(0));
        return new_inst;
    }

    // todo: 后端遍历
    // virtual void accept(IRVisitor &visitor) final;

protected:
    CallInst(Function *func, std::vector<Value *> args, BasicBlock *bb);
    CallInst(Type *ret_ty, std::vector<Value *> args, BasicBlock *bb);
};

class BranchInst : public Instruction {
public:
    static BranchInst *createCondBr(Value *cond, BasicBlock *if_true,
                                    BasicBlock *if_false, BasicBlock *bb);
    static BranchInst *createBr(BasicBlock *if_true, BasicBlock *bb);

    bool isCondBr() const {
        return getNumOperands() == 3;
    }

    // bool is_extend_cond_br() const { return get_num_operands() == 3 ||
    // get_num_operands() == 4; }

    virtual std::string print() override;

    Instruction *copyInst(BasicBlock *bb) override final {
        if (getNumOperands() == 1) {
            auto new_inst = new BranchInst(bb);
            new_inst->setOperand(0, getOperand(0));
            return new_inst;
        } else {
            auto new_inst = new BranchInst(getOperand(0), bb);
            new_inst->setOperand(1, getOperand(1));
            new_inst->setOperand(2, getOperand(2));
            return new_inst;
        }
    }

    // todo: 后端遍历
    // virtual void accept(IRVisitor &visitor) final;

private:
    BranchInst(Value *cond, BasicBlock *if_true, BasicBlock *if_false,
               BasicBlock *bb);
    BranchInst(BasicBlock *if_true, BasicBlock *bb);
    BranchInst(BasicBlock *bb);
    BranchInst(Value *cond, BasicBlock *bb);
};

class ReturnInst : public Instruction {
public:
    static ReturnInst *createRet(Value *val, BasicBlock *bb);
    static ReturnInst *createVoidRet(BasicBlock *bb);

    bool isVoidRet() const {
        return getNumOperands() == 0;
    }

    Type *getRetType() const {
        return getOperand(0)->getType();
    }

    virtual std::string print() override;

    Instruction *copyInst(BasicBlock *bb) override final {
        if (isVoidRet()) {
            return new ReturnInst(bb);
        } else {
            return new ReturnInst(getOperand(0), bb);
        }
    }

    // todo: 后端遍历
    // virtual void accept(IRVisitor &visitor) final;

private:
    ReturnInst(Value *val, BasicBlock *bb);
    ReturnInst(BasicBlock *bb);
};

class GetElementPtrInst : public Instruction {
public:
    static Type *getElementType(Value *ptr, std::vector<Value *> idxs);
    static GetElementPtrInst *createGep(Value *ptr, std::vector<Value *> idxs,
                                        BasicBlock *bb);

    Type *getElementType() const {
        return element_ty_;
    }

    virtual std::string print() override;

    Instruction *copyInst(BasicBlock *bb) override final {
        std::vector<Value *> idxs;
        for (auto i = 1; i < getNumOperands(); i++) {
            idxs.push_back(getOperand(i));
        }
        return new GetElementPtrInst(getOperand(0), idxs, bb);
    }

    // todo: 后端遍历
    // virtual void accept(IRVisitor &visitor) final;

private:
    GetElementPtrInst(Value *ptr, std::vector<Value *> idxs, BasicBlock *bb);

private:
    Type *element_ty_;
};

class StoreInst : public Instruction {};

//& 加速使用全0初始化数组的代码优化分析和代码生成
class MemsetInst : public Instruction {};

class LoadInst : public Instruction {};

class AllocaInst : public Instruction {};

class ZextInst : public Instruction {};

class SiToFpInst : public Instruction {};

class FpToSiInst : public Instruction {};

class PhiInst : public Instruction {};

class CmpBrInst : public Instruction {};

class FCmpBrInst : public Instruction {};

class LoadOffsetInst : public Instruction {};

class StoreOffsetInst : public Instruction {};

class SelectInst : public Instruction {};

class LoadImmInst : public Instruction {};

class CastInst : public Instruction {};
#endif
