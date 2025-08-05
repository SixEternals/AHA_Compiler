#ifndef SCOPE_H
#define SCOPE_H

#include "midend/BasicBlock.hpp"
#include "midend/Constant.hpp"
#include "midend/Type.hpp"
#include "midend/Value.hpp"
#include <map>
#include <string>
#include <vector>

class Scope {
public:
    Scope(std::string scope_name, Scope *father, BasicBlock *bb)
        : scope_name(scope_name),
          father_scope(father),
          current_bb(bb) {}

public:
    void enter() {
        lookup_var_table.push_back({});
        lookup_func_table.push_back({});
        lookup_array_size_table.push_back({});
        lookup_array_const_table.push_back({});
    }

    void exit() {
        lookup_var_table.pop_back();
        lookup_func_table.pop_back();
        lookup_array_size_table.pop_back();
        lookup_array_const_table.pop_back();
    }

    bool inGlobal() {
        return lookup_var_table.size() == 1;
    }

    bool push(std::string name, Value *val) {
        auto result =
            lookup_var_table[lookup_var_table.size() - 1].insert({name, val});
        return result.second;
    }

    Value *find(std::string name) {
        for (auto v = lookup_var_table.rbegin(); v != lookup_var_table.rend();
             v++) {
            auto iter = v->find(name);
            if (iter != v->end()) {
                return iter->second;
            }
        }

        return nullptr;
    }

    bool pushFunc(std::string name, Value *val) {
        auto result =
            lookup_func_table[lookup_func_table.size() - 1].insert({name, val});
        return result.second;
    }

    Value *findFunc(std::string name) {
        for (auto v = lookup_func_table.rbegin(); v != lookup_func_table.rend();
             v++) {
            auto iter = v->find(name);
            if (iter != v->end()) {
                return iter->second;
            }
        }

        return nullptr;
    }

    bool pushSize(std::string name, std::vector<int> size) {
        auto result =
            lookup_array_size_table[lookup_array_size_table.size() - 1].insert(
                {name, size});
        return result.second;
    }

    std::vector<int> findSize(std::string name) {
        for (auto v = lookup_array_size_table.rbegin();
             v != lookup_array_size_table.rend(); v++) {
            auto iter = v->find(name);
            if (iter != v->end()) {
                return iter->second;
            }
        }

        return {};
    }

    bool pushConst(std::string name, ConstantArray *array) {
        auto result =
            lookup_array_const_table[lookup_array_const_table.size() - 1]
                .insert({name, array});
        return result.second;
    }

    ConstantArray *findConst(std::string name) {
        for (auto v = lookup_array_const_table.rbegin();
             v != lookup_array_const_table.rend(); v++) {
            auto iter = v->find(name);
            if (iter != v->end()) {
                return iter->second;
            }
        }

        return nullptr;
    }

    Scope *getFather() {
        return father_scope;
    }

private:
    std::vector<std::map<std::string, Value *>>
        lookup_var_table;                                /* 变量作用域栈 */
    std::vector<std::map<std::string, Value *>>
        lookup_func_table;                               /* 函数作用域栈 */
    std::vector<std::map<std::string, std::vector<int>>> /* 数组维度栈 */
        lookup_array_size_table;
    std::vector<std::map<std::string, ConstantArray *>>  /* 数组初始值栈 */
        lookup_array_const_table;
    Scope *father_scope; /* 父作用域，如果是全局作用域，则为null */
    std::string scope_name;
    BasicBlock *current_bb;
    std::map<std::string, Value *> varMap; // 当前作用域的符号表
};
#endif
