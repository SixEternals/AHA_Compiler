
// Generated from SysYParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SysYParserVisitor.h"


/**
 * This class provides an empty implementation of SysYParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SysYParserBaseVisitor : public SysYParserVisitor {
public:

  virtual std::any visitProgram(SysYParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(SysYParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(SysYParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBType(SysYParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(SysYParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(SysYParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(SysYParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitVal(SysYParser::InitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(SysYParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(SysYParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParam(SysYParser::FuncFParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(SysYParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItem(SysYParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_with_assign(SysYParser::Stmt_with_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_with_exp(SysYParser::Stmt_with_expContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_with_block(SysYParser::Stmt_with_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_with_if(SysYParser::Stmt_with_ifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_with_while(SysYParser::Stmt_with_whileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_with_break(SysYParser::Stmt_with_breakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_with_continue(SysYParser::Stmt_with_continueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_with_return(SysYParser::Stmt_with_returnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(SysYParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_with_plus_and_mius(SysYParser::Exp_with_plus_and_miusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_with_unaryOp(SysYParser::Exp_with_unaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_with_symbol(SysYParser::Exp_with_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_with_lval(SysYParser::Exp_with_lvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_with_Paren(SysYParser::Exp_with_ParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_with_num(SysYParser::Exp_with_numContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_with_funcRParams(SysYParser::Exp_with_funcRParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond(SysYParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLVal(SysYParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(SysYParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOp(SysYParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncRParams(SysYParser::FuncRParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(SysYParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExp(SysYParser::ConstExpContext *ctx) override {
    return visitChildren(ctx);
  }


};

