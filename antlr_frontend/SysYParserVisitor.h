
// Generated from SysYParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SysYParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SysYParser.
 */
class  SysYParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SysYParser.
   */
    virtual std::any visitProgram(SysYParser::ProgramContext *context) = 0;

    virtual std::any visitCompUnit(SysYParser::CompUnitContext *context) = 0;

    virtual std::any visitDecl(SysYParser::DeclContext *context) = 0;

    virtual std::any visitConstDecl(SysYParser::ConstDeclContext *context) = 0;

    virtual std::any visitBType(SysYParser::BTypeContext *context) = 0;

    virtual std::any visitConstDef(SysYParser::ConstDefContext *context) = 0;

    virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *context) = 0;

    virtual std::any visitVarDecl(SysYParser::VarDeclContext *context) = 0;

    virtual std::any visitVarDef(SysYParser::VarDefContext *context) = 0;

    virtual std::any visitInitVal(SysYParser::InitValContext *context) = 0;

    virtual std::any visitFuncDef(SysYParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncType(SysYParser::FuncTypeContext *context) = 0;

    virtual std::any visitFuncFParams(SysYParser::FuncFParamsContext *context) = 0;

    virtual std::any visitFuncFParam(SysYParser::FuncFParamContext *context) = 0;

    virtual std::any visitBlock(SysYParser::BlockContext *context) = 0;

    virtual std::any visitBlockItem(SysYParser::BlockItemContext *context) = 0;

    virtual std::any visitStmt_with_assign(SysYParser::Stmt_with_assignContext *context) = 0;

    virtual std::any visitStmt_with_exp(SysYParser::Stmt_with_expContext *context) = 0;

    virtual std::any visitStmt_with_block(SysYParser::Stmt_with_blockContext *context) = 0;

    virtual std::any visitStmt_with_if(SysYParser::Stmt_with_ifContext *context) = 0;

    virtual std::any visitStmt_with_while(SysYParser::Stmt_with_whileContext *context) = 0;

    virtual std::any visitStmt_with_break(SysYParser::Stmt_with_breakContext *context) = 0;

    virtual std::any visitStmt_with_continue(SysYParser::Stmt_with_continueContext *context) = 0;

    virtual std::any visitStmt_with_return(SysYParser::Stmt_with_returnContext *context) = 0;

    virtual std::any visitReturnStmt(SysYParser::ReturnStmtContext *context) = 0;

    virtual std::any visitExp_with_plus_and_mius(SysYParser::Exp_with_plus_and_miusContext *context) = 0;

    virtual std::any visitExp_with_unaryOp(SysYParser::Exp_with_unaryOpContext *context) = 0;

    virtual std::any visitExp_with_symbol(SysYParser::Exp_with_symbolContext *context) = 0;

    virtual std::any visitExp_with_lval(SysYParser::Exp_with_lvalContext *context) = 0;

    virtual std::any visitExp_with_Paren(SysYParser::Exp_with_ParenContext *context) = 0;

    virtual std::any visitExp_with_num(SysYParser::Exp_with_numContext *context) = 0;

    virtual std::any visitExp_with_funcRParams(SysYParser::Exp_with_funcRParamsContext *context) = 0;

    virtual std::any visitCond(SysYParser::CondContext *context) = 0;

    virtual std::any visitLVal(SysYParser::LValContext *context) = 0;

    virtual std::any visitNumber(SysYParser::NumberContext *context) = 0;

    virtual std::any visitUnaryOp(SysYParser::UnaryOpContext *context) = 0;

    virtual std::any visitFuncRParams(SysYParser::FuncRParamsContext *context) = 0;

    virtual std::any visitParam(SysYParser::ParamContext *context) = 0;

    virtual std::any visitConstExp(SysYParser::ConstExpContext *context) = 0;


};

