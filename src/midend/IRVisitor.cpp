#include "midend/IRVisitor.hpp"
#include "midend/Constant.hpp"
#include "midend/GlobalVariable.hpp"
#include "midend/IRContext.hpp"
#include "midend/Scope.hpp"
#include "midend/Type.hpp"
#include "midend/Value.hpp"
#include <any>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
static Type *VOID_T;
static Type *INT1_T;
static Type *INT32_T;
static Type *FLOAT_T;
static Type *INT32PTR_T;
static Type *FLOATPTR_T;

/* =============== static区域 =============== */
struct true_false_BB {
    BasicBlock *trueBB = nullptr;
    BasicBlock *falseBB = nullptr;
}; //& used for backpatching
static std::vector<true_false_BB> IF_WHILE_COND_STACK; //& used for Cond
static std::vector<true_false_BB> WHILE_STACK; //& used for break and continue
static Function *cur_fun = nullptr;            //& function that is being built
// static BasicBlock *entry_block_of_cur_fun;
static BasicBlock *cur_block_of_cur_fun; //& used for add instruction
// static bool has_global_init;
// static BasicBlock *global_init_block;
static bool is_init_const_array = false;
static int arr_total_size = 1;
static std::vector<int> array_bounds;
static std::vector<int> array_sizes;
// static std::vector<int> array_sizes;
// pair( the pos when into {, the offset bettween { and } )
static std::vector<std::pair<int, int>> array_pos;
static int cur_pos;
static int cur_depth;
static std::map<int, Value *> init_val_map;
static std::vector<Constant *> init_val; //& used for constant initializer
static BasicBlock *ret_BB;
static Value *ret_addr;             //& ret BB
static Value *tmp_val = nullptr;    //& store tmp value
static Type *cur_type = nullptr;    //& store current type
static bool require_lvalue = false; //& whether require lvalue
#define CONST_INT(num) ConstantInt::get(num)
#define CONST_FP(num)  ConstantFP::get(num)
enum class IfWhileEnum {
    IN_IF = 333,
    IN_WHILE = 777,
};
static bool real_ret = 0;
static std::vector<IfWhileEnum> if_while_stack;
// 当前指令是否在if或while里
bool inIfStmt() {
    if (find(if_while_stack.begin(), if_while_stack.end(),
             IfWhileEnum::IN_IF) != if_while_stack.end()) {
        return true;
    }
    return false;
}
bool inWhileStmt() {
    if (find(if_while_stack.begin(), if_while_stack.end(),
             IfWhileEnum::IN_WHILE) != if_while_stack.end()) {
        return true;
    }
    return false;
}
#define LOG(msg) assert(0 && msg);
/* =============== static区域 end =============== */

IRVisitor::IRVisitor(std::string source) {
    module = std::make_unique<Module>("AHA");
}

void IRVisitor::addLibs() {
    VOID_T = Type::getVoidType();
    INT1_T = Type::getInt1Type();
    INT32_T = Type::getInt32Type();
    INT32PTR_T = Type::getInt32PtrType();
    FLOAT_T = Type::getFloatType();
    FLOATPTR_T = Type::getFloatPtrType();
    auto input_type = FunctionType::get(INT32_T, {});
    auto get_int = Function::create(input_type, "getint", module.get());

    input_type = FunctionType::get(FLOAT_T, {});
    auto get_float = Function::create(input_type, "getfloat", module.get());

    input_type = FunctionType::get(INT32_T, {});
    auto get_char = Function::create(input_type, "getch", module.get());

    std::vector<Type *> input_params;
    std::vector<Type *>().swap(input_params);
    input_params.push_back(INT32PTR_T);
    input_type = FunctionType::get(INT32_T, input_params);
    auto get_array = Function::create(input_type, "getarray", module.get());

    std::vector<Type *>().swap(input_params);
    input_params.push_back(FLOATPTR_T);
    input_type = FunctionType::get(INT32_T, input_params);
    auto get_farray = Function::create(input_type, "getfarray", module.get());

    std::vector<Type *> output_params;
    std::vector<Type *>().swap(output_params);
    output_params.push_back(INT32_T);
    auto output_type = FunctionType::get(VOID_T, output_params);
    auto put_int = Function::create(output_type, "putint", module.get());

    std::vector<Type *>().swap(output_params);
    output_params.push_back(FLOAT_T);
    output_type = FunctionType::get(VOID_T, output_params);
    auto put_float = Function::create(output_type, "putfloat", module.get());

    std::vector<Type *>().swap(output_params);
    output_params.push_back(INT32_T);
    output_type = FunctionType::get(VOID_T, output_params);
    auto put_char = Function::create(output_type, "putch", module.get());

    std::vector<Type *>().swap(output_params);
    output_params.push_back(INT32_T);
    output_params.push_back(INT32PTR_T);
    output_type = FunctionType::get(VOID_T, output_params);
    auto put_array = Function::create(output_type, "putarray", module.get());

    std::vector<Type *>().swap(output_params);
    output_params.push_back(INT32_T);
    output_params.push_back(FLOATPTR_T);
    output_type = FunctionType::get(VOID_T, output_params);
    auto put_farray = Function::create(output_type, "putfarray", module.get());

    std::vector<Type *>().swap(input_params);
    input_params.push_back(INT32_T);
    auto time_type = FunctionType::get(VOID_T, input_params);
    auto start_time =
        Function::create(time_type, "_sysy_starttime", module.get());

    std::vector<Type *>().swap(input_params);
    input_params.push_back(INT32_T);
    time_type = FunctionType::get(VOID_T, input_params);
    auto stop_time =
        Function::create(time_type, "_sysy_stoptime", module.get());

    std::vector<Type *>().swap(input_params);
    input_params.push_back(INT32PTR_T);
    input_params.push_back(INT32_T);
    auto mem_type_i = FunctionType::get(VOID_T, input_params);
    auto memset_i = Function::create(mem_type_i, "memset_i", module.get());

    std::vector<Type *>().swap(input_params);
    input_params.push_back(FLOATPTR_T);
    input_params.push_back(INT32_T);
    auto mem_type_f = FunctionType::get(VOID_T, input_params);
    auto memset_f = Function::create(mem_type_f, "memset_f", module.get());

    current_scope->enter();
    current_scope->pushFunc("getint", get_int);
    current_scope->pushFunc("getfloat", get_float);
    current_scope->pushFunc("getch", get_char);
    current_scope->pushFunc("getarray", get_array);
    current_scope->pushFunc("getfarray", get_farray);
    current_scope->pushFunc("putint", put_int);
    current_scope->pushFunc("putfloat", put_float);
    current_scope->pushFunc("putch", put_char);
    current_scope->pushFunc("putarray", put_array);
    current_scope->pushFunc("putfarray", put_farray);
    current_scope->pushFunc("starttime", start_time);
    current_scope->pushFunc("stoptime", stop_time);

    current_scope->pushFunc("memset_i", memset_i);
    current_scope->pushFunc("memset_f", memset_f);
}

// 辅助函数：打印树形结构的AST
void printASTNode(std::string const &prefix, std::string const &nodeName,
                  bool isLast = true) {
    std::cout << prefix;
    if (isLast) {
        std::cout << "└── ";
    } else {
        std::cout << "├── ";
    }
    std::cout << nodeName << std::endl;
}

void printASTNode(std::string const &prefix, std::string const &nodeName,
                  std::string const &value, bool isLast = true) {
    std::cout << prefix;
    if (isLast) {
        std::cout << "└── ";
    } else {
        std::cout << "├── ";
    }
    std::cout << nodeName << ": " << value << std::endl;
}

std::any IRVisitor::visitProgram(SysYParser::ProgramContext *ctx) {
    addLibs();
    return visitChildren(ctx);
}

std::any IRVisitor::visitCompUnit(SysYParser::CompUnitContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitDecl(SysYParser::DeclContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitConstDecl(SysYParser::ConstDeclContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitBType(SysYParser::BTypeContext *ctx) {
    return visitChildren(ctx);
}

/*
1. 获取变量名（并截断到 20 个字符以内）。
2. 获取变量类型。
3. 访问初值（constInitVal），得到一个 Value*。
4. 做类型转换，如果初值类型与目标类型不一致则强制转换。
5. 推入作用域（current_scope）。
6. 返回子节点的访问结果。
*/
std::any IRVisitor::visitConstDef(SysYParser::ConstDefContext *ctx) {
    std::string var_name = ctx->IDENT()->getText();
    if (var_name.length() > 20) {
        var_name = var_name.substr(0, 20);
    }

    Type *cur_type = parseStr2Ty(ctx->parent->children[1]->getText());
    Value *tmp_val{nullptr};
    if (ctx->constInitVal()) {
        auto value = visit(ctx->constInitVal()); // 递归访问初值
        tmp_val = std::any_cast<Value *>(value);
        auto tmp_int32_val = dynamic_cast<ConstantInt *>(tmp_val);
        auto tmp_float_val = dynamic_cast<ConstantFP *>(tmp_val);

        if (cur_type == INT32_T && tmp_float_val != nullptr) {
            tmp_val =
                ConstantInt::get(static_cast<int>(tmp_float_val->getValue()));
        } else if (cur_type == FLOAT_T && tmp_int32_val != nullptr) {
            tmp_val =
                ConstantFP::get(static_cast<float>(tmp_int32_val->getValue()));
        } else if (!tmp_int32_val && !tmp_float_val) {
            assert(tmp_int32_val ||
                   tmp_float_val && "init value must be constant int or float");
        }

    } else {
        assert(0 && "const value must be init!");
    }
    current_scope->push(var_name, tmp_val);
    // return visitChildren(ctx);
    return nullptr;
}

std::any IRVisitor::visitConstInitVal(SysYParser::ConstInitValContext *ctx) {
    cur_depth++;

    // 当前维度超过声明维度，只取第一个值
    if (array_sizes.size() - 1 < cur_depth) {
        auto val = visit(ctx->constExp());
        tmp_val = std::any_cast<Value *>(val);

        assert(
            (!current_scope->inGlobal() || dynamic_cast<Constant *>(tmp_val)) &&
            "global array's initval must be const!");

        cur_depth--;
        if (array_sizes.size() - 1 == cur_depth) {
            init_val_map[cur_pos++] = tmp_val;
        }
        return nullptr;
    }

    if (cur_pos >= arr_total_size) {
        assert(0 && "element num in array greater than array bound!");
    }

    // 保存当前数组段位置
    array_pos.push_back({cur_pos, array_sizes[cur_depth - 1]});
    int count = 0;
    for (auto sub_ctx: ctx->constInitVal()) {
        visit(sub_ctx); // 递归访问子 initval
        assert(
            (!current_scope->inGlobal() || dynamic_cast<Constant *>(tmp_val)) &&
            "global array's initval must be const!");

        if (sub_ctx->constExp() == nullptr) {
            continue;
        }

        if (cur_pos >= arr_total_size) {
            assert(0 && "element num in array greater than array bound!");
        }

        auto tmp_int32_val = dynamic_cast<ConstantInt *>(tmp_val);
        auto tmp_float_val = dynamic_cast<ConstantFP *>(tmp_val);

        // 类型安全性检查
        if (!tmp_int32_val && !tmp_float_val) {
            if (is_init_const_array) {
                assert(0 && "const array using a no const to init!");
            }

            if (cur_type == INT32_T && tmp_val->getType() == FLOAT_T) {
                assert(0 && "float var can't init int array!");
            } else if (cur_type == FLOAT_T && tmp_val->getType() == INT32_T) {
                assert(0 && "int var can't init float array!");
            }
        } else {
            if (cur_type == INT32_T && tmp_float_val != nullptr) {
                assert(0 && "float const can't init int array!");
            } else if (cur_type == FLOAT_T && tmp_int32_val != nullptr) {
                tmp_val =
                    CONST_FP(static_cast<float>(tmp_int32_val->getValue()));
            }
        }

        init_val_map[cur_pos++] = tmp_val;
        count++;
    }

    // 补全空缺的 0
    int expected = array_pos.back().first + array_pos.back().second;
    while (cur_pos < expected) {
        if (cur_type == INT32_T) {
            init_val_map[cur_pos++] = CONST_INT(0);
        } else {
            init_val_map[cur_pos++] = CONST_FP(0.0);
        }
    }

    array_pos.pop_back();
    cur_depth--;
    // return visitChildren(ctx);
    return nullptr;
}

std::any IRVisitor::visitVarDecl(SysYParser::VarDeclContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitVarDef(SysYParser::VarDefContext *ctx) {
    std::string var_name = ctx->IDENT()->getText();
    if (var_name.length() > 20) {
        var_name = var_name.substr(0, 20);
    }

    // 1. 类型推导（int/float）
    Type *base_ty = parseStr2Ty(ctx->parent->children[1]->getText());

    // 2. 是否是数组（根据维度判断）
    std::vector<int> shape;
    for (auto exp: ctx->constExp()) {
        auto v = std::any_cast<Value *>(visit(exp));
        auto c = dynamic_cast<ConstantInt *>(v);
        assert(c && "Array dimension must be const int");
        shape.push_back(static_cast<int>(c->getValue()));
    }

    // 3. 构造变量类型（标量或数组）
    Type *ty = base_ty;
    for (auto it = shape.rbegin(); it != shape.rend(); ++it) {
        ty = ArrayType::get(ty, *it);
    }

    // 4. 全局变量逻辑
    if (current_scope->inGlobal()) {
        Constant *init = nullptr;
        if (ctx->initVal()) {
            auto value = std::any_cast<Value *>(visit(ctx->initVal()));
            auto const_array = dynamic_cast<ConstantArray *>(value);
            if (const_array) {
                init = const_array;
            } else {
                init = dynamic_cast<Constant *>(value);
                assert(init && "global init must be constant");
            }
        } else {
            init = ConstantZero::get(ty);
        }
        GlobalVariable::create(var_name, module.get(), ty, /*is_const=*/false,
                               init);
        return nullptr; // 不生成局部变量的 AllocaInst
    }

    // 5. 局部变量逻辑
    Value *alloc = AllocaInst::createAlloca(ty, current_bb);
    current_scope->push(var_name, alloc);
    current_scope->pushSize(var_name, shape);

    if (ctx->initVal()) {
        auto value = std::any_cast<Value *>(visit(ctx->initVal()));
        if (auto const_array = dynamic_cast<ConstantArray *>(value)) {
            // 展平数组 + GEP + Store
            std::vector<Value *> flat_vals;
            size_t array_size = const_array->getSizeOfArray();
            for (size_t i = 0; i < array_size; ++i) {
                auto element = const_array->getElementValue(i);
                assert(element && "Array element must not be null");
                flat_vals.push_back(element);
            }

            int idx = 0;
            for (Value *v: flat_vals) {
                std::vector<Value *> gep_indices = {ConstantInt::get(0),
                                                    ConstantInt::get(idx++)};
                auto gep = GetElementPtrInst::createGep(alloc, gep_indices,
                                                        current_bb);
                StoreInst::createStore(v, gep, current_bb);
            }
        } else {
            // 标量初始化
            auto const_val = dynamic_cast<Constant *>(value);
            assert(const_val && "init value must be constant");
            StoreInst::createStore(const_val, alloc, current_bb);
        }
    }

    return nullptr;
}

std::any IRVisitor::visitInitVal(SysYParser::InitValContext *ctx) {
    cur_depth++;

    int max_depth = static_cast<int>(array_sizes.size()) - 1;

    // 情况一：到底层了，直接取第一个元素
    if (cur_depth > max_depth) {
        auto value = visit(ctx->initVal(0));
        assert((!current_scope->inGlobal() || dynamic_cast<Constant *>(tmp_val)) &&
               "global array's initval must be const!");
        cur_depth--;
        if (cur_depth == max_depth) {
            init_val_map[cur_pos++] = tmp_val;
        }
        return nullptr;
    }

    if (cur_pos >= arr_total_size) {
        LOG("element num in array greater than array bound!");
    }

    array_pos.push_back({cur_pos, array_sizes[cur_depth - 1]});

    for (auto *subInit: ctx->initVal()) {
        if (subInit->exp() != nullptr) {
            // 表达式 initVal
            auto value = visit(subInit->exp());
            assert((!current_scope->inGlobal() || dynamic_cast<Constant *>(tmp_val)) &&
                   "global array's initval must be const!");

            auto tmp_int = dynamic_cast<ConstantInt *>(tmp_val);
            auto tmp_fp = dynamic_cast<ConstantFP *>(tmp_val);

            if (!tmp_int && !tmp_fp) {
                if (is_init_const_array) {
                    LOG("const array using a non-const to init!");
                }

                if (cur_type == INT32_T && tmp_val->getType() == FLOAT_T) {
                    LOG("float var can't init int array!");
                } else if (cur_type == FLOAT_T &&
                           tmp_val->getType() == INT32_T) {
                    LOG("int var can't init float array!");
                }
            } else {
                if (cur_type == INT32_T && tmp_fp) {
                    LOG("float const can't init int array!");
                } else if (cur_type == FLOAT_T && tmp_int) {
                    tmp_val = CONST_FP(float(tmp_int->getValue()));
                }
            }

            init_val_map[cur_pos++] = tmp_val;
        } else {
            // 嵌套 initVal { ... }
            visitInitVal(subInit);
        }

        if (cur_pos >= arr_total_size) {
            LOG("element num in array greater than array bound!");
        }
    }

    // 更新 cur_pos: 补齐当前维度
    cur_pos = array_pos.back().first + array_pos.back().second;
    array_pos.pop_back();
    cur_depth--;

    // return visitChildren(ctx);
    return nullptr;
}

// todo
std::any IRVisitor::visitFuncDef(SysYParser::FuncDefContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitFuncType(SysYParser::FuncTypeContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitFuncFParams(SysYParser::FuncFParamsContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitFuncFParam(SysYParser::FuncFParamContext *ctx) {
    return visitChildren(ctx);
}

// todo
std::any IRVisitor::visitBlock(SysYParser::BlockContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitBlockItem(SysYParser::BlockItemContext *ctx) {
    return visitChildren(ctx);
}

/* 功能：
左值/右值语义区分（require_lvalue）
类型自动转换（int/float）
常量优化（常量折叠、溢出检查）
类型安全检查
Store 指令生成
支持链式赋值（a = b = c）
visitChildren 调用保留（可选，视语义是否继续访问其他节点）
*/
std::any
IRVisitor::visitStmt_with_assign(SysYParser::Stmt_with_assignContext *ctx) {
    // 1. 访问右值表达式（exp）
    bool old_flag = require_lvalue; // 保存旧值
    require_lvalue = false;         // 设置为右值模式
    visit(ctx->exp());
    require_lvalue = old_flag;      // 恢复旧值
    Value *result = tmp_val;

    // 2. 访问左值表达式（lVal）
    require_lvalue = true;          // 设置为左值模式
    visit(ctx->lVal());
    require_lvalue = old_flag;      // 恢复旧值
    Value *addr = tmp_val;

    // 3. 检查 addr 的合法性
    assert(addr && "Left-hand side (lVal) must resolve to a valid address");

    // 4. 推导地址指针类型（ptr -> base type）
    Type *target_ty = addr->getType()->getPointerElementType();
    Type *src_ty = result->getType();

    // 5. 类型转换（float -> int / int -> float）
    if (target_ty->isIntegerType() && src_ty->isFloatType()) {
        if (auto const_fp = dynamic_cast<ConstantFP *>(result)) {
            // 检查范围，避免溢出
            double value = const_fp->getValue();
            assert(value >= INT32_MIN && value <= INT32_MAX && "...");
            assert(value >= INT32_MIN && value <= INT32_MAX &&
                   "Float value out of int range");
            result = CONST_INT(static_cast<int>(value));
        } else {
            result = FpToSiInst::createFpToSi(result, INT32_T, current_bb);
        }
    } else if (target_ty->isFloatType() && src_ty->isIntegerType()) {
        if (auto const_int = dynamic_cast<ConstantInt *>(result)) {
            result = CONST_FP(static_cast<float>(const_int->getValue()));
        } else {
            result = SiToFpInst::createSiToFp(result, FLOAT_T, current_bb);
        }
    } else {
        // 增加类型兼容性检查
        assert(((target_ty->isIntegerType() && src_ty->isIntegerType()) ||
                (target_ty->isFloatType() && src_ty->isFloatType())) &&
               "Incompatible types for assignment");
    }

    // 6. 生成 Store 指令
    StoreInst::createStore(result, addr, current_bb);

    // 7. 可用于表达式链式赋值（如 a = b = c）
    tmp_val = result;
    return result;
}

std::any IRVisitor::visitStmt_with_exp(SysYParser::Stmt_with_expContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitStmt_with_block(SysYParser::Stmt_with_blockContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitStmt_with_if(SysYParser::Stmt_with_ifContext *ctx) {
    // 1. 生成条件值
    bool old_flag = require_lvalue; // 保存旧值
    require_lvalue = false;
    auto cond_val_any = visit(ctx->cond());
    Value *cond_val = std::any_cast<Value *>(cond_val_any);
    require_lvalue = old_flag; // 恢复旧值

    // 2. 进行类型转换（int32/float → int1）
    if (cond_val->getType() == INT32_T) {
        cond_val = CmpInst::createCmp(CmpOp::NE, cond_val, ConstantInt::get(0),
                                      current_bb);
    } else if (cond_val->getType() == FLOAT_T) {
        cond_val = FCmpInst::createFCmp(CmpOp::NE, cond_val,
                                        ConstantFP::get(0), current_bb);
    }

    // 3. 创建基本块
    auto true_bb = BasicBlock::create("if.true", current_function);
    auto false_bb = BasicBlock::create("if.false", current_function);
    auto end_bb = BasicBlock::create("if.end", current_function);

    // 4. 条件跳转指令
    BranchInst::createCondBr(cond_val, true_bb, false_bb, current_bb);

    // 5. 构造 then 分支语句
    current_bb = true_bb;
    current_scope->enter();
    visit(ctx->stmt(0));
    current_scope->exit();
    assert(current_bb && "current_bb must not be null");
    if (current_bb->getTerminator() == nullptr) {
        BranchInst::createBr(end_bb, current_bb);
    }

    // 6. 构造 else 分支语句（如果有）
    bool has_else = ctx->stmt().size() == 2;
    if (has_else) {
        current_bb = false_bb;
        current_scope->enter();
        visit(ctx->stmt(1));
        current_scope->exit();
        assert(current_bb && "current_bb must not be null");
        if (current_bb->getTerminator() == nullptr) {
            BranchInst::createBr(end_bb, current_bb);
        }
    } else {
        // 无 else，则 false_bb 直接跳转到 end_bb
        BranchInst::createBr(end_bb, false_bb);
    }

    // 7. 设置后继基本块
    current_bb = end_bb;
    // return visitChildren(ctx);
    return nullptr;
}

std::any
IRVisitor::visitStmt_with_while(SysYParser::Stmt_with_whileContext *ctx) {
    if_while_stack.push_back(IfWhileEnum::IN_WHILE);
    auto pred_bb = BasicBlock::create("", cur_fun);
    auto iter_bb = BasicBlock::create("", cur_fun);
    auto next_bb = BasicBlock::create("", cur_fun);

    if (cur_block_of_cur_fun->getTerminator() == nullptr) {
        BranchInst::createBr(pred_bb, cur_block_of_cur_fun);
    }
    cur_block_of_cur_fun = pred_bb;
    IF_WHILE_COND_STACK.push_back({iter_bb, next_bb});

    bool old_flag = require_lvalue;
    // 从 ctx 获取条件表达式
    if (ctx->cond()) {
        require_lvalue = false;
        auto pred_value = visit(ctx->cond());
        tmp_val = std::any_cast<Value *>(pred_value);
        require_lvalue = old_flag; // 恢复
    } else {
        assert(0 && "Predicate expression is missing in while statement");
    }

    IF_WHILE_COND_STACK.pop_back();
    WHILE_STACK.push_back({pred_bb, next_bb});
    Value *inst_cmp;
    if (tmp_val->getType() == INT1_T) {
        inst_cmp = tmp_val;
    } else if (tmp_val->getType() == INT32_T) {
        auto tmp_val_const = dynamic_cast<ConstantInt *>(tmp_val);
        if (tmp_val_const) {
            inst_cmp = ConstantInt::get(tmp_val_const->getValue() != 0);
        } else {
            inst_cmp = CmpInst::createCmp(NE, tmp_val, ConstantInt::get(0),
                                          cur_block_of_cur_fun);
        }
    } else if (tmp_val->getType() == FLOAT_T) {
        auto tmp_val_const = dynamic_cast<ConstantFP *>(tmp_val);
        if (tmp_val_const) {
            inst_cmp = ConstantInt::get(tmp_val_const->getValue() != 0);
        } else {
            inst_cmp = FCmpInst::createFCmp(NE, tmp_val, ConstantFP::get(0),
                                            cur_block_of_cur_fun);
        }
    } else {
        assert(0 && "Illegal type");
    }

    BranchInst::createCondBr(inst_cmp, iter_bb, next_bb, cur_block_of_cur_fun);
    cur_block_of_cur_fun = iter_bb;

    // 从 ctx 获取循环体
    require_lvalue = false; // 循环体内部表达式也是右值
    if (ctx->stmt()) {
        visit(ctx->stmt());
    } else {
        current_scope->enter();
        visit(ctx->stmt());
        current_scope->exit();
    }
    require_lvalue = old_flag; // 恢复
    // if (ctx->stmt()) {
    //     auto loop_stmt = ctx->stmt();
    //     if (dynamic_cast<SysYParser::BlockItemContext *>(loop_stmt)) {
    //         visit(loop_stmt);
    //     } else {
    //         current_scope->enter();
    //         visit(loop_stmt);
    //         current_scope->exit();
    //     }
    // } else {
    //     assert(0 && "Loop body is missing in while statement");
    // }

    if (cur_block_of_cur_fun->getTerminator() == nullptr) {
        BranchInst::createBr(pred_bb, cur_block_of_cur_fun);
    }
    cur_block_of_cur_fun = next_bb;
    WHILE_STACK.pop_back();

    if_while_stack.pop_back();
    return nullptr;
}

// todo
std::any
IRVisitor::visitStmt_with_break(SysYParser::Stmt_with_breakContext *ctx) {
    return visitChildren(ctx);
}

// todo
std::any
IRVisitor::visitStmt_with_continue(SysYParser::Stmt_with_continueContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitStmt_with_return(SysYParser::Stmt_with_returnContext *ctx) {
    return visitChildren(ctx);
}

// todo
std::any IRVisitor::visitReturnStmt(SysYParser::ReturnStmtContext *ctx) {
    return visitChildren(ctx);
}

// todo
std::any IRVisitor::visitExp_with_plus_and_mius(
    SysYParser::Exp_with_plus_and_miusContext *ctx) {
    return visitChildren(ctx);
}

// todo
std::any
IRVisitor::visitExp_with_unaryOp(SysYParser::Exp_with_unaryOpContext *ctx) {
    return visitChildren(ctx);
}

// todo
std::any
IRVisitor::visitExp_with_symbol(SysYParser::Exp_with_symbolContext *ctx) {
    return visitChildren(ctx);
}

// todo
std::any IRVisitor::visitExp_with_lval(SysYParser::Exp_with_lvalContext *ctx) {
    return visitChildren(ctx);
}

// todo
std::any
IRVisitor::visitExp_with_Paren(SysYParser::Exp_with_ParenContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitExp_with_num(SysYParser::Exp_with_numContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitExp_with_funcRParams(
    SysYParser::Exp_with_funcRParamsContext *ctx) {
    std::string func_name = ctx->IDENT()->getText();
    std::vector<Value *> params_list;
    std::vector<Value *> args;
    std::vector<Type *> arg_types;

    // 1. 解析参数
    if (ctx->funcRParams()) {
        // 修复：使用 funcRParams()->param() 获取参数列表
        for (auto param_ctx: ctx->funcRParams()->param()) {
            bool old_flag = require_lvalue; // 保存 require_lvalue 的旧值
            require_lvalue = false;         // 设置为右值模式
            param_ctx->accept(this);        // tmp_val, cur_type 设置
            require_lvalue = old_flag;      // 恢复 require_lvalue 的值

            args.push_back(tmp_val);
            arg_types.push_back(cur_type);
        }
    }

    // 2. 查找函数
    // 修复：使用 current_scope 查找函数，而不是 module->getFunction
    Function *callee_func =
        static_cast<Function *>(current_scope->find(func_name));
    if (!callee_func) {
        LOG(("Function not found: " + func_name).c_str());
    }

    // 3. 参数类型匹配（可选）
    auto func_type = callee_func->getFunctionType();
    auto const &param_types = callee_func->getArgs(); // ?
    if (param_types.size() != arg_types.size()) {
        LOG("Function argument count mismatch");
    }

    // 你可以补充类型转换逻辑，例如 int -> float 隐式转换

    // 4. 生成调用
    tmp_val = CallInst::createCall(callee_func, args, cur_block_of_cur_fun);
    cur_type = func_type->getReturnType();

    return tmp_val;
}

// todo
std::any IRVisitor::visitCond(SysYParser::CondContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitLVal(SysYParser::LValContext *ctx) {
    std::string var_name = ctx->IDENT()->getText();
    if (var_name.length() > 20) {
        var_name = var_name.substr(0, 20);
    }

    // 获取变量 IR 指针（即 lVal 指向的内存地址）
    Value *var = current_scope->find(var_name);
    assert(var && "Variable used before declaration");

    Type *elem_type = var->getType();
    if (elem_type->isPointerType()) {
        elem_type = elem_type->getPointerElementType();
    }
    if (dynamic_cast<FunctionType *>(elem_type)) {
        elem_type = static_cast<FunctionType *>(elem_type)->getReturnType();
    }

    bool should_return_lvalue = require_lvalue;
    require_lvalue = false;

    // 没有数组索引：普通变量或指针解引用
    if (ctx->exp().empty()) {
        if (elem_type->isIntegerType() || elem_type->isFloatType()) {
            // 普通变量，直接返回 lval
            tmp_val = var;
        } else if (elem_type->isPointerType()) {
            // 是一个 int* 或 float* 变量
            tmp_val = var;
        } else if (elem_type->isArrayType()) {
            // 访问数组变量本体
            tmp_val = GetElementPtrInst::createGep(
                var, {CONST_INT(0), CONST_INT(0)}, cur_block_of_cur_fun);
        } else {
            LOG("Unknown lval type without indexing");
            tmp_val = var;
        }

        if (!should_return_lvalue && tmp_val->getType()->isPointerType()) {
            tmp_val = LoadInst::createLoad(
                static_cast<PointerType *>(tmp_val->getType())
                    ->getElementType(),
                tmp_val, cur_block_of_cur_fun);
        }

        return tmp_val;
    }

    // 有数组索引：可能是 a[1] 或 a[1][2] 等
    std::vector<Value *> indices;

    // 首先获取 const 数组维度信息（例如 {6000, 200, 10, 1}）
    std::vector<int> shape = current_scope->findSize(var_name);
    Value *linear_index = nullptr;
    while (indices.size() < shape.size()) {
        indices.push_back(CONST_INT(0));
    }

    assert(ctx->exp().size() <= shape.size() &&
           "Index count exceeds array dimensions");
    if (shape.empty()) {
        // 直接走普通变量逻辑
        tmp_val = var;
        if (!should_return_lvalue && tmp_val->getType()->isPointerType()) {
            tmp_val = LoadInst::createLoad(
                static_cast<PointerType *>(tmp_val->getType())
                    ->getElementType(),
                tmp_val, cur_block_of_cur_fun);
        }
        return tmp_val;
    }
    for (int i = 0; i < ctx->exp().size(); ++i) {
        tmp_val = std::any_cast<Value *>(ctx->exp(i)->accept(this)); // 修复调用
        Value *cur_index = tmp_val;

        Value *scaled_index = nullptr;
        int stride = 1;
        if (auto const_val = dynamic_cast<ConstantInt *>(cur_index)) {
            for (int d = i + 1; d < shape.size(); ++d) {
                stride *= shape[d];
            }
            scaled_index = CONST_INT(const_val->getValue() * stride);
        } else {
            // scaled_index = BinaryInst::createMul(
            //     cur_index, CONST_INT(shape[i + 1]), cur_block_of_cur_fun);
            scaled_index = BinaryInst::createMul(cur_index, CONST_INT(stride),
                                                 cur_block_of_cur_fun);
        }

        if (!linear_index) {
            linear_index = scaled_index;
        } else if (auto c1 = dynamic_cast<ConstantInt *>(linear_index),
                   c2 = dynamic_cast<ConstantInt *>(scaled_index);
                   c1 && c2) {
            linear_index = CONST_INT(c1->getValue() + c2->getValue());
        } else {
            linear_index = BinaryInst::createAdd(linear_index, scaled_index,
                                                 cur_block_of_cur_fun);
        }
    }

    // 如果这是一个 const 数组并且下标常量可解开
    if (auto const_array = current_scope->findConst(var_name)) {
        if (auto ci = dynamic_cast<ConstantInt *>(linear_index)) {
            tmp_val = const_array->getElementValue(ci->getValue());
            return tmp_val;
        } else {
            LOG("Partial constant index optimization not implemented");
        }
    }

    // 变量是 int** 或 float**（数组指针）
    if (var->getType()->getPointerElementType()->isPointerType()) {
        Value *tmp_load = LoadInst::createLoad(
            var->getType()->getPointerElementType(), var, cur_block_of_cur_fun);
        tmp_val = GetElementPtrInst::createGep(tmp_load, {linear_index},
                                               cur_block_of_cur_fun);
    } else if (var->getType()->getPointerElementType()->isArrayType()) {
        tmp_val = GetElementPtrInst::createGep(
            var, {CONST_INT(0), linear_index}, cur_block_of_cur_fun);
    } else {
        tmp_val = GetElementPtrInst::createGep(var, {linear_index},
                                               cur_block_of_cur_fun);
    }

    // 如果是右值访问，需要加载实际值
    if (!should_return_lvalue) {
        tmp_val = LoadInst::createLoad(
            static_cast<PointerType *>(tmp_val->getType())->getElementType(),
            tmp_val, cur_block_of_cur_fun);
    }

    return tmp_val;
}

std::any IRVisitor::visitNumber(SysYParser::NumberContext *ctx) {
    if (ctx->INTEGER_CONST()) {
        std::string num_text = ctx->getText();
        try {
            int32_t value = parseIntLiteral(num_text);
            tmp_val = CONST_INT(value);
        } catch (std::exception const &e) {
            LOG(("Error parsing integer literal: " + num_text).c_str());
            throw;
        }
    } else if (ctx->FLOAT_CONST()) {
        std::string num_text = ctx->getText();
        try {
            float value = parseFloatLiteral(num_text);
            tmp_val = CONST_FP(value);
        } catch (std::exception const &e) {
            LOG(("Error parsing float literal: " + num_text).c_str());
            throw;
        }
    } else {
        LOG("Unexpected number context: neither INTEGER_CONST nor FLOAT_CONST");
        LOG("Invalid number context");
    }
    return tmp_val;
}

std::any IRVisitor::visitUnaryOp(SysYParser::UnaryOpContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitFuncRParams(SysYParser::FuncRParamsContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitParam(SysYParser::ParamContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitConstExp(SysYParser::ConstExpContext *ctx) {
    return visitChildren(ctx);
}

// MARK: Tools
Type *IRVisitor::parseStr2Ty(std::string type_name) {
    if (type_name.find("int") != std::string::npos) {
        return INT32_T;
    } else if (type_name.find("float") != std::string::npos) {
        return FLOAT_T;
    }
    return VOID_T;
}

int32_t IRVisitor::parseIntLiteral(std::string const &text) {
    int base = 10;
    size_t offset = 0;
    if (text.size() > 2 && text[0] == '0') {
        if (text[1] == 'x' || text[1] == 'X') {
            base = 16;
            offset = 2;
        } else {
            base = 8;
            offset = 1;
        }
    }
    return static_cast<int32_t>(std::stoi(text.substr(offset), nullptr, base));
}

float IRVisitor::parseFloatLiteral(std::string const &text) {
    return std::stof(text);
}
