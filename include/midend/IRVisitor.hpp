#ifndef FRONTEND_IRVISITOR_HPP
#define FRONTEND_IRVISITOR_HPP

#include "midend/Constant.hpp"
#include "midend/Function.hpp"
#include "midend/Module.hpp"
#include "midend/Scope.hpp"
#include "SysYParser.h"
#include "SysYParserBaseVisitor.h"
#include <iostream>
#include <map>
#include <memory>

class IRVisitor : public SysYParserBaseVisitor {
private:
    std::unique_ptr<Scope> current_scope =
        std::make_unique<Scope>("globalScope", nullptr, nullptr);
    std::map<std::string, int> constant_int_map;
    std::map<std::string, float> constant_float_map;
    Function *current_function{nullptr};
    BasicBlock *current_bb{nullptr};
    std::string current_bb_name{nullptr};
    int local_scope_counter{0};
    bool array_addr{false};
    std::unique_ptr<Module> module;
    // irbuilder交由每个类自己输出
    // 管理ptr, type*, array, constant
    ConstManager *const_manager_ = Constant::getManager();
    std::map<Type *, PointerType *> pointer_map_;
    std::map<std::pair<Type *, int>, ArrayType *> array_map_;
    std::map<std::pair<Type *, std::vector<Type *>>, FunctionType *>
        function_map_;

    /* 数组专用 */
    std::list<Value *> init_array_list;
    std::list<Value *> element_dimension;
    int cur_dim{0};

private:
    void addLibs();

public:
    IRVisitor(std::string source);

    std::any visitProgram(SysYParser::ProgramContext *ctx) override;

    std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override;

    std::any visitDecl(SysYParser::DeclContext *ctx) override;

    std::any visitConstDecl(SysYParser::ConstDeclContext *ctx) override;

    std::any visitBType(SysYParser::BTypeContext *ctx) override;

    std::any visitConstDef(SysYParser::ConstDefContext *ctx) override;

    std::any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override;

    std::any visitVarDecl(SysYParser::VarDeclContext *ctx) override;

    std::any visitVarDef(SysYParser::VarDefContext *ctx) override;

    std::any visitInitVal(SysYParser::InitValContext *ctx) override;

    std::any visitFuncDef(SysYParser::FuncDefContext *ctx) override;

    std::any visitFuncType(SysYParser::FuncTypeContext *ctx) override;

    std::any visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override;

    std::any visitFuncFParam(SysYParser::FuncFParamContext *ctx) override;

    std::any visitBlock(SysYParser::BlockContext *ctx) override;

    std::any visitBlockItem(SysYParser::BlockItemContext *ctx) override;

    std::any
    visitStmt_with_assign(SysYParser::Stmt_with_assignContext *ctx) override;

    std::any visitStmt_with_exp(SysYParser::Stmt_with_expContext *ctx) override;

    std::any
    visitStmt_with_block(SysYParser::Stmt_with_blockContext *ctx) override;

    std::any visitStmt_with_if(SysYParser::Stmt_with_ifContext *ctx) override;

    std::any
    visitStmt_with_while(SysYParser::Stmt_with_whileContext *ctx) override;

    std::any
    visitStmt_with_break(SysYParser::Stmt_with_breakContext *ctx) override;

    std::any visitStmt_with_continue(
        SysYParser::Stmt_with_continueContext *ctx) override;

    std::any
    visitStmt_with_return(SysYParser::Stmt_with_returnContext *ctx) override;

    std::any visitReturnStmt(SysYParser::ReturnStmtContext *ctx) override;

    std::any visitExp_with_plus_and_mius(
        SysYParser::Exp_with_plus_and_miusContext *ctx) override;

    std::any
    visitExp_with_unaryOp(SysYParser::Exp_with_unaryOpContext *ctx) override;

    std::any
    visitExp_with_symbol(SysYParser::Exp_with_symbolContext *ctx) override;

    std::any visitExp_with_lval(SysYParser::Exp_with_lvalContext *ctx) override;

    std::any
    visitExp_with_Paren(SysYParser::Exp_with_ParenContext *ctx) override;

    std::any visitExp_with_num(SysYParser::Exp_with_numContext *ctx) override;

    std::any visitExp_with_funcRParams(
        SysYParser::Exp_with_funcRParamsContext *ctx) override;

    std::any visitCond(SysYParser::CondContext *ctx) override;

    std::any visitLVal(SysYParser::LValContext *ctx) override;

    std::any visitNumber(SysYParser::NumberContext *ctx) override;

    std::any visitUnaryOp(SysYParser::UnaryOpContext *ctx) override;

    std::any visitFuncRParams(SysYParser::FuncRParamsContext *ctx) override;

    std::any visitParam(SysYParser::ParamContext *ctx) override;

    std::any visitConstExp(SysYParser::ConstExpContext *ctx) override;
    // MARK: Tools
    Type *parseStr2Ty(std::string type_name);
    int32_t parseIntLiteral(std::string const &text);
    float parseFloatLiteral(std::string const &text);
};

#endif
