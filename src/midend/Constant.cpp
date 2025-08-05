#include "midend/Constant.hpp"
#include "midend/Instruction.hpp"
#include "midend/Type.hpp"
#include <cassert>
#include <iostream>
#include <memory>
#include <sstream>

//& ConstantInt
// 全局单例
ConstManager *Constant::getManager() {
    static ConstManager manager;
    return &manager;
}

ConstantInt *ConstantInt::get(int val) {
    auto manager = Constant::getManager();
    if (manager->cached_int.find(val) != manager->cached_int.end()) {
        return manager->cached_int[val].get();
    }
    return (manager->cached_int[val] = std::unique_ptr<ConstantInt>(
                new ConstantInt(Type::getInt32Type(), val)))
        .get();
}

ConstantInt *ConstantInt::get(bool val) {
    auto manager = Constant::getManager();
    if (manager->cached_bool.find(val) != manager->cached_bool.end()) {
        return manager->cached_bool[val].get();
    }
    return (manager->cached_bool[val] = std::unique_ptr<ConstantInt>(
                new ConstantInt(Type::getInt1Type(), val ? 1 : 0)))
        .get();
}

Constant *Constant::get(Constant *lhs, Instruction::OpID bin_op,
                        Constant *rhs) {
    Constant *ret = 0;
    if (ConstantInt *ilhs = dynamic_cast<ConstantInt *>(lhs),
        *irhs = dynamic_cast<ConstantInt *>(rhs);
        ilhs && irhs) {
        ret = ConstantInt::getFromBin(ilhs, bin_op, irhs);
    } else if (ConstantFP *flhs = dynamic_cast<ConstantFP *>(lhs),
               *frhs = dynamic_cast<ConstantFP *>(rhs);
               flhs && frhs) {
        ret = ConstantFP::getFromBin(flhs, bin_op, frhs);
    }
    return ret;
}

ConstantInt *ConstantInt::getFromBin(ConstantInt *lhs, Instruction::OpID bin_op,
                                     ConstantInt *rhs) {
    ConstantInt *ret;
    switch (bin_op) {
    case Instruction::OpID::add:
        ret = get(lhs->getValue() + rhs->getValue());
        break;
    case Instruction::OpID::sub:
        ret = get(lhs->getValue() - rhs->getValue());
        break;
    case Instruction::OpID::mul:
        ret = get(lhs->getValue() * rhs->getValue());
        break;
    case Instruction::OpID::sdiv:
        ret = get(lhs->getValue() / rhs->getValue());
        break;
    case Instruction::OpID::srem:
        ret = get(lhs->getValue() % rhs->getValue());
        break;
    case Instruction::OpID::lor:
        ret = get(lhs->getValue() | rhs->getValue());
        break;
    case Instruction::OpID::lxor:
        ret = get(lhs->getValue() ^ rhs->getValue());
        break;
    case Instruction::OpID::land:
        ret = get(lhs->getValue() & rhs->getValue());
        break;
    case Instruction::OpID::asr:
        ret = get(lhs->getValue() >> rhs->getValue());
        break;
    case Instruction::OpID::shl:
        ret = get(lhs->getValue() << rhs->getValue());
        break;
    case Instruction::OpID::lsr:
        ret = get((int32_t)(((uint32_t)lhs->getValue()) >> rhs->getValue()));
        break;
    default: ret = 0; break;
    }
    return ret;
}

/*enum CmpOp {
    EQ, // ==
    NE, // !=
    GT, // >
    GE, // >=
    LT, // <
    LE  // <=
};
*/
ConstantInt *ConstantInt::getFromCmp(Constant *lhs, CmpOp cmp_op,
                                     Constant *rhs) {
    ConstantInt *ret;
    if (ConstantInt *ilhs = dynamic_cast<ConstantInt *>(lhs),
        *irhs = dynamic_cast<ConstantInt *>(rhs);
        ilhs && irhs) {
        ret = ConstantInt::getFromICmp(ilhs, cmp_op, irhs);
    } else if (ConstantFP *flhs = dynamic_cast<ConstantFP *>(lhs),
               *frhs = dynamic_cast<ConstantFP *>(rhs);
               flhs && frhs) {
        ret = ConstantInt::getFromFCmp(flhs, cmp_op, frhs);
    } else {
        ret = 0;
    }
    assert(ret != 0);
    return ret;
}

ConstantInt *ConstantInt::getFromICmp(ConstantInt *lhs, CmpOp cmp_op,
                                      ConstantInt *rhs) {
    ConstantInt *ret;
    switch (cmp_op) {
    case CmpOp::EQ: ret = get(lhs->getValue() == rhs->getValue()); break;
    case CmpOp::NE: ret = get(lhs->getValue() != rhs->getValue()); break;
    case CmpOp::GT: ret = get(lhs->getValue() > rhs->getValue()); break;
    case CmpOp::GE: ret = get(lhs->getValue() >= rhs->getValue()); break;
    case CmpOp::LT: ret = get(lhs->getValue() < rhs->getValue()); break;
    case CmpOp::LE: ret = get(lhs->getValue() <= rhs->getValue()); break;
    default:        ret = 0; break;
    }
    return ret;
}

ConstantInt *ConstantInt::getFromFCmp(ConstantFP *lhs, CmpOp cmp_op,
                                      ConstantFP *rhs) {
    ConstantInt *ret;
    switch (cmp_op) {
    case CmpOp::EQ: ret = get(lhs->getValue() == rhs->getValue()); break;
    case CmpOp::NE: ret = get(lhs->getValue() != rhs->getValue()); break;
    case CmpOp::GT: ret = get(lhs->getValue() > rhs->getValue()); break;
    case CmpOp::GE: ret = get(lhs->getValue() >= rhs->getValue()); break;
    case CmpOp::LT: ret = get(lhs->getValue() < rhs->getValue()); break;
    case CmpOp::LE: ret = get(lhs->getValue() <= rhs->getValue()); break;
    default:        ret = 0; break;
    }
    return ret;
}

std::string ConstantInt::print() {
    std::string const_ir;
    Type *ty = this->getType();
    if (ty->isIntegerType() &&
        static_cast<IntegerType *>(ty)->getNumBits() == 1) {
        const_ir += (this->getValue() == 0) ? "false" : "true"; //&  int1
    } else {
        const_ir += std::to_string(this->getValue());           //& int32
    }
    return const_ir;
}

ConstantFP *ConstantFP::getFromBin(ConstantFP *lhs, Instruction::OpID bin_op,
                                   ConstantFP *rhs) {
    ConstantFP *ret;
    switch (bin_op) {
    case Instruction::OpID::fadd:
        ret = get(lhs->getValue() + rhs->getValue());
        break;
    case Instruction::OpID::fsub:
        ret = get(lhs->getValue() - rhs->getValue());
        break;
    case Instruction::OpID::fmul:
        ret = get(lhs->getValue() * rhs->getValue());
        break;
    case Instruction::OpID::fdiv:
        ret = get(lhs->getValue() / rhs->getValue());
        break;
    default: ret = 0;
    }
    return ret;
}

//& ConstantFP
ConstantFP *ConstantFP::get(float val) {
    auto manager = Constant::getManager();
    if (manager->cached_float.find(val) != manager->cached_float.end()) {
        return manager->cached_float[val].get();
    }
    return (manager->cached_float[val] = std::unique_ptr<ConstantFP>(
                new ConstantFP(Type::getFloatType(), val)))
        .get();
}

std::string ConstantFP::print() {
    std::stringstream fp_ir_ss;
    std::string fp_ir;
    double val = this->getValue();
    fp_ir_ss << "0x" << std::hex << *(uint64_t *)&val << std::endl;
    fp_ir_ss >> fp_ir;
    return fp_ir;
}

//& ConstantZero
ConstantZero *ConstantZero::get(Type *ty) {
    auto manager = Constant::getManager();
    if (not manager->cached_zero[ty]) {
        manager->cached_zero[ty] =
            std::unique_ptr<ConstantZero>(new ConstantZero(ty));
    }
    return manager->cached_zero[ty].get();
}

std::string ConstantZero::print() {
    return "zeroinitializer";
}

//& ConstantArray
ConstantArray::ConstantArray(ArrayType *ty, std::map<int, Value *> const &vals,
                             size_t size)
    : Constant(ty, "", size) {
    for (int i = 0; i < size; i++) {
        if (vals.find(i) != vals.end()) {
            setOperand(i, vals.find(i)->second);
        } else {
            auto def_it = vals.find(-1);
            if (def_it != vals.end()) {
                setOperand(i, def_it->second);
            } else {
                // 如果没有提供默认值，则使用 ConstantZero
                setOperand(i, ConstantZero::get(ty->getElementType()));
            }
        }
    }
    array_size = size;
    this->init_val_map = vals;
}

ConstantArray *ConstantArray::get(ArrayType *ty,
                                  std::map<int, Value *> const &vals_map,
                                  size_t size) {
    return new ConstantArray(ty, vals_map, size);
}

std::string ConstantArray::print() {
    std::string const_ir;
    const_ir += "[";
    auto elem_ty_str = this->getType()->getArrayElementType()->print();

    if (this->getSizeOfArray() > 0) {
        const_ir += elem_ty_str;
        const_ir += " ";
        auto val = getElementValue(0);
        if (val) {
            const_ir += val->print();
        } else {
            const_ir += "undef"; // or some other indicator of null
        }
    }

    for (int i = 1; i < this->getSizeOfArray(); i++) {
        const_ir += ", ";
        const_ir += elem_ty_str;
        const_ir += " ";
        auto val = getElementValue(i);
        if (val) {
            const_ir += val->print();
        } else {
            const_ir += "undef"; // or some other indicator of null
        }
    }
    const_ir += "]";
    return const_ir;
}
