#include "midend/Function.hpp"
#include "midend/BasicBlock.hpp"
#include "midend/Instruction.hpp"
#include "midend/Module.hpp"
#include <cstddef>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>

// MARK: Function
Function *Function::create(FunctionType *ty, std::string const &name,
                           Module *parent) {
    return new Function(ty, name, parent);
}

void Function::buildArgs() {
    auto function_type = getFunctionType();
    size_t num_args = getNumOfArgs();
    for (size_t i{0}; i < num_args; ++i) {
        auto arg = new Argument(function_type->getParamType(i), "", this, i);
        arguments_.push_back(arg);
        if (arg->getType()->isFloatType()) {
            f_args_.push_back(arg);
        } else if (arg->getType()->isIntegerType()) {
            i_args_.push_back(arg);
        }
    }
}

Function::Function(FunctionType *ty, std::string const &name, Module *parent)
    : Value(ty, name),
      parent_(parent),
      seq_cnt_(0) {
    parent->addFunction(this);
    buildArgs();
}

Function::~Function() {
    for (auto *arg: arguments_) {
        delete arg;
    }
}

/* 为函数的参数、基本块和指令分配唯一的名称。
1. 遍历函数的参数、基本块和指令。
2. 为每个对象分配一个唯一的名称，便于调试和可视化。
3. 使用一个计数器（seq_cnt_）确保名称的唯一性。

调试模式下：名称格式为 <函数名>_op_<序列号>。
非调试模式下：名称格式为 op<序列号>。
*/
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
    for (auto &bb1: basic_blocks_) {
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
        for (auto &instr: bb->getInstructions()) {
            if (!instr->isVoid() && seq.find(instr) == seq.end()) {
                auto seq_num = seq.size() + seq_cnt_;
#ifdef DEBUG
                std::string f_name = this->getName();
                if (instr->setName(f_name + "_op_" + std::to_string(seq_num))) {
                    seq.insert({instr, seq_num});
                }
#else
                if (instr->setName("op" + std::to_string(seq_num))) {
                    seq.insert({instr, seq_num});
                }
#endif
            }
        }
    }
    seq_cnt_ += seq.size();
}

/* 构造 CFG 并返回 dot 格式字符串表示
void foo() {
entry:
    if (x) goto A; else goto B;
A:
    goto C;
B:
    goto C;
C:
    return;
}
以上的CFG逻辑如下
entry → A → C
      ↘ B ↗

那么输出的dot为
entry;
A;
B;
C;
entry->A;
entry->B;
A->C;
B->C;
*/
std::string Function::printGra() {
    ::std::ostringstream f_dot;
    setInstrName();
    ::std::set<BasicBlock *> bb_set;
    ::std::map<BasicBlock *, ::std::set<BasicBlock *>> graph;
    for (auto bb: getBasicBlocks()) {
        bb_set.insert(bb);
    }
    auto entry = getEntryBlock();
    ::std::function<void(BasicBlock *,
                         ::std::map<BasicBlock *, ::std::set<BasicBlock *>> &)>
        draw =
            [&draw](BasicBlock *bb,
                    ::std::map<BasicBlock *, ::std::set<BasicBlock *>> &graph) {
                if (graph.find(bb) != graph.end()) {
                    return;
                }

                auto it = graph.insert({bb, {}}).first;
                for (auto succ_bb: bb->getSuccBasicBlocks()) {
                    if (it->second.find(succ_bb) != it->second.end()) {
                        throw std::runtime_error(
                            "Duplicate edge detected in control flow graph for "
                            "basic block: " +
                            bb->getName());
                    }
                    it->second.insert(succ_bb);
                }

                for (auto succ_bb: bb->getSuccBasicBlocks()) {
                    draw(succ_bb, graph);
                }
            };

    draw(entry, graph);

    for (auto bb: bb_set) {
        f_dot << bb->getName();
        f_dot << ";\n";
    }
    for (auto [bb, bbset]: graph) {
        for (auto succ_bb: bbset) {
            f_dot << bb->getName() + "->" + succ_bb->getName() + ";\n";
        }
    }

    return f_dot.str();
}

std::string Function::print() {
    setInstrName();
    std::ostringstream func_ir;
    assert(this->getReturnType() && "Function has no return type.");
    assert(this->getType() && "Function type is invalid.");

    bool is_decl = isDeclaration();
    if (is_decl) {
        func_ir << "declare ";
    } else {
        func_ir << "define ";
    }

    func_ir << this->getReturnType()->print();
    func_ir << " ";
    func_ir << "@" + this->getName();
    func_ir << "(";

    //// print arg
    if (is_decl) {
        for (int i = 0; i < this->getNumOfArgs(); i++) {
            if (i) {
                func_ir << ", ";
            }
            func_ir << static_cast<FunctionType *>(this->getType())
                           ->getParamType(i)
                           ->print();
        }
    } else {
        for (auto arg = this->argBegin(); arg != argEnd(); arg++) {
            if (arg != this->argBegin()) {
                func_ir << ", ";
            }
            func_ir << (*arg)->print();
        }
    }
    func_ir << ")";

    //// print bb
    if (is_decl) {
        func_ir << "\n";
    } else {
        func_ir << " {";
        func_ir << "\n";
        for (auto &bb: this->getBasicBlocks()) {
            func_ir << bb->print();
        }
        func_ir << "}";
    }

    return func_ir.str();
}

void Function::addBasicBlock(BasicBlock *bb) {
    basic_blocks_.push_back(bb);
}

void Function::removeBasicBlock(BasicBlock *bb) {
    basic_blocks_.erase(
        std::find(basic_blocks_.begin(), basic_blocks_.end(), bb));

    for (auto pre: bb->getPreBasicBlocks()) {
        pre->removeSuccBasicBlock(bb);
    }
    for (auto succ: bb->getSuccBasicBlocks()) {
        succ->removePreBasicBlock(bb);
    }
}

BasicBlock *Function::getRetBlock() const {
    for (auto b: basic_blocks_) {
        if (b->getSuccBasicBlocks().empty()) {
            return b;
        }
    }
    return nullptr;
}

void Function::updateCFGForCopiedBlock(BasicBlock *originalBB,
                                       BasicBlock *newBB) {}

// MARK: Argument
std::string Argument::print() {
    return this->getType()->print() + " %" + this->getName();
}
