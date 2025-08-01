#ifndef USER_HPP
#define USER_HPP

#include "midend/Value.hpp"
#include <string>
#include <vector>

class User : public Value {
public:
    User(Type *ty, std::string const &name = "", unsigned num_ops = 0);
    ~User() = default;

    void replaceOperand(unsigned i, Value *v);
    Value *getOperand(unsigned i) const;   //& start from 0
    void setOperand(unsigned i, Value *v); //& start from 0
    void addOperand(Value *v);

    std::vector<Value *> &getOperands();
    unsigned getNumOperands() const noexcept;

    void removeAllOperand();
    void removeOperands(int index1, int index2);
    void removeUseOfOps();

private:
    // 操作数，数量不限
    std::vector<Value *> operands_; //& operands of this value
    // unsigned num_ops_;
};
#endif // USER_HPP
