#ifndef USER_HPP
#define USER_HPP

#include "midend/Value.hpp"
#include <string>
#include <vector>

class User : public Value {
public:
    User(Type *ty, std::string const &name = "", size_t num_ops = 0);
    ~User() = default;

    void replaceOperand(size_t i, Value *v);
    Value *getOperand(size_t i) const;   //& start from 0
    void setOperand(size_t i, Value *v); //& start from 0
    void addOperand(Value *v);

    std::vector<Value *> &getOperands();
    size_t getNumOperands() const noexcept;

    /*
    removeAllOperand移除并清空所有operands，用于删除指令
    removeOperands移除指定范围的operands，用于优化
    removeUseOfOps 解除Use关系但不修改operands，用于优化，暂时解除依赖关系
    */
    void removeAllOperand();
    void removeOperands(int index1, int index2);
    void removeUseOfOps();

private:
    // 操作数，数量不限
    std::vector<Value *> operands_; //& operands of this value
    // size_t num_ops_;
};
#endif // USER_HPP
