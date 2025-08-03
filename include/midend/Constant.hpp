#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "Instruction.hpp"
#include "User.hpp"
#include "Value.hpp"
#include <cassert>
#include <cstdint>
#include <map>
#include <memory>

class Instruction;
class Type;
class ArrayType;
class ConstantInt;
class ConstantFP;
class ConstantZero;

struct ConstManager {
public:
    std::unordered_map<int, std::unique_ptr<ConstantInt>> cached_int;
    std::unordered_map<bool, std::unique_ptr<ConstantInt>> cached_bool;
    std::unordered_map<float, std::unique_ptr<ConstantFP>> cached_float;
    std::unordered_map<Type *, std::unique_ptr<ConstantZero>> cached_zero;

    void clear() {
        cached_int.clear();
        cached_bool.clear();
        cached_float.clear();
        cached_zero.clear();
    }
};

class Constant : public User {
public:
    static ConstManager *manager_;
    static ConstManager *getManager();
    // [`static`]
    // 根据两个 Constant 对象（lhs 和 rhs）以及一个操作符（bin_op），生成一个新的 Constant 对象。
    // 会匹配lhs和rhs是不是同一类型
    static Constant *get(Constant *lhs, Instruction::OpID bin_op,
                         Constant *rhs);

    Constant(Type *ty, std::string const &name = "", size_t num_ops = 0)
        : User(ty, name, num_ops) {}

    ~Constant() = default;

private:
};

class ConstantInt : public Constant {
public:
    static ConstantInt *get(int val);
    static ConstantInt *get(bool val);

    static ConstantInt *getFromBin(ConstantInt *lhs, Instruction::OpID bin_op,
                                   ConstantInt *rhs);
    static ConstantInt *getFromCmp(Constant *lhs, CmpOp, Constant *rhs);
    static ConstantInt *getFromICmp(ConstantInt *lhs, CmpOp, ConstantInt *rhs);
    static ConstantInt *getFromFCmp(ConstantFP *lhs, CmpOp, ConstantFP *rhs);

    static int &getValue(ConstantInt *const_val) {
        return const_val->val_;
    }

    int getValue() {
        return val_;
    }

    virtual std::string print() override;

    virtual ~ConstantInt() {}

private:
    ConstantInt(Type *ty, int val) : Constant(ty, "", 0), val_(val) {}

private:
    int val_;
};

class ConstantFP : public Constant {
public:
    static ConstantFP *get(float val);
    static ConstantFP *getFromBin(ConstantFP *lhs, Instruction::OpID bin_op,
                                  ConstantFP *rhs);

    float &getValue() {
        return val_;
    }

    virtual std::string print() override;

    virtual ~ConstantFP() {}

private:
    ConstantFP(Type *ty, float val) : Constant(ty, "", 0), val_(val) {}

private:
    float val_;
};

class ConstantZero : public Constant {
public:
    static ConstantZero *get(Type *ty);

    virtual std::string print() override;

private:
    ConstantZero(Type *ty) : Constant(ty, "", 0) {}
};

class ConstantArray : public Constant {
public:
    ~ConstantArray() = default;

    static ConstantArray *
    get(ArrayType *ty, std::map<int, Value *> const &vals_map, size_t size);

    Constant *getElementValue(int index) {
        if (init_val_map[index]) {
            return dynamic_cast<Constant *>(init_val_map[index]);
        }
        return dynamic_cast<Constant *>(init_val_map[-1]);
    };

    size_t getSizeOfArray() {
        return array_size;
    }

    virtual std::string print() override;

private:
    ConstantArray(ArrayType *ty, std::map<int, Value *> const &vals,
                  size_t size);

private:
    std::map<int, Value *> init_val_map;
    int array_size;
};

#endif
