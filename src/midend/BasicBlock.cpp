#include "midend/BasicBlock.hpp"
#include "midend/Function.hpp"

int BasicBlock::baseBlockCounter = 0;

BasicBlock::BasicBlock(std::string const &name, Function *parent = nullptr)
    : Value(Type::getLabelType(), name),
      parent_(parent) {
    assert(parent && "currently parent should not be nullptr");
    // parent_->addBasicBlock(this);
}

std::string BasicBlock::print() {}
