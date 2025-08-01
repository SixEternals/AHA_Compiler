#include "midend/Function.hpp"
#include <map>
#include <memory>

Function::Function(std::string functionName, FunctionType *type)
    : Value(type),
      functionName(functionName) {
    int count = 0;

    // buildArgs
    auto paramType = type->paramBegin();
    int i = 0;
    for (; paramType != type->paramEnd(); paramType++, i++) {
        // Argument *valRegister = new Argument(
        //     paramType, std::to_string(count++) + "_" + functionName, this,
        //     i);
        // paramsValue.push_back(valRegister);
        // auto t = new Argument(
        //     paramType, std::to_string(count++) + "_" + functionName, this,
        //     i);
    }
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
