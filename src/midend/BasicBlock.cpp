#include "midend/BasicBlock.hpp"
#include "midend/Function.hpp"
#include "midend/Instruction.hpp"

int BasicBlock::baseBlockCounter = 0;

BasicBlock::BasicBlock(std::string const &name, Function *parent = nullptr)
    : Value(Type::getLabelType(), name),
      parent_(parent) {
    assert(parent && "currently parent should not be a nullptr");
    parent_->addBasicBlock(this);
}

std::string BasicBlock::print() {}

BasicBlock *BasicBlock::create(std::string const &name, Function *parent) {
    auto label = name.empty() ? "" : "label_";
    return new BasicBlock(label, parent);
}

Instruction const *BasicBlock::getVaildTerminator() const {
    if (instr_list_.empty()) {
        return nullptr;
    }
    //
    switch (instr_list_.back()->getInstrType()) {
    case Instruction::OpID::ret:    return instr_list_.back();
    case Instruction::OpID::br:     return instr_list_.back();
    case Instruction::OpID::cmpbr:  return instr_list_.back();
    case Instruction::OpID::fcmpbr: return instr_list_.back();
    default:                        return nullptr;
    }
}
