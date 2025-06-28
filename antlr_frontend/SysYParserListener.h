
// Generated from SysYParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SysYParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SysYParser.
 */
class  SysYParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(SysYParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(SysYParser::ProgramContext *ctx) = 0;

  virtual void enterCompUnit(SysYParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(SysYParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(SysYParser::DeclContext *ctx) = 0;
  virtual void exitDecl(SysYParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(SysYParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(SysYParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(SysYParser::BTypeContext *ctx) = 0;
  virtual void exitBType(SysYParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef(SysYParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(SysYParser::ConstDefContext *ctx) = 0;

  virtual void enterConstInitVal(SysYParser::ConstInitValContext *ctx) = 0;
  virtual void exitConstInitVal(SysYParser::ConstInitValContext *ctx) = 0;

  virtual void enterVarDecl(SysYParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(SysYParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(SysYParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(SysYParser::VarDefContext *ctx) = 0;

  virtual void enterInitVal(SysYParser::InitValContext *ctx) = 0;
  virtual void exitInitVal(SysYParser::InitValContext *ctx) = 0;

  virtual void enterFuncDef(SysYParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(SysYParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(SysYParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(SysYParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParams(SysYParser::FuncFParamsContext *ctx) = 0;
  virtual void exitFuncFParams(SysYParser::FuncFParamsContext *ctx) = 0;

  virtual void enterFuncFParam(SysYParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(SysYParser::FuncFParamContext *ctx) = 0;

  virtual void enterBlock(SysYParser::BlockContext *ctx) = 0;
  virtual void exitBlock(SysYParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(SysYParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(SysYParser::BlockItemContext *ctx) = 0;

  virtual void enterStmt_with_assign(SysYParser::Stmt_with_assignContext *ctx) = 0;
  virtual void exitStmt_with_assign(SysYParser::Stmt_with_assignContext *ctx) = 0;

  virtual void enterStmt_with_exp(SysYParser::Stmt_with_expContext *ctx) = 0;
  virtual void exitStmt_with_exp(SysYParser::Stmt_with_expContext *ctx) = 0;

  virtual void enterStmt_with_block(SysYParser::Stmt_with_blockContext *ctx) = 0;
  virtual void exitStmt_with_block(SysYParser::Stmt_with_blockContext *ctx) = 0;

  virtual void enterStmt_with_if(SysYParser::Stmt_with_ifContext *ctx) = 0;
  virtual void exitStmt_with_if(SysYParser::Stmt_with_ifContext *ctx) = 0;

  virtual void enterStmt_with_while(SysYParser::Stmt_with_whileContext *ctx) = 0;
  virtual void exitStmt_with_while(SysYParser::Stmt_with_whileContext *ctx) = 0;

  virtual void enterStmt_with_break(SysYParser::Stmt_with_breakContext *ctx) = 0;
  virtual void exitStmt_with_break(SysYParser::Stmt_with_breakContext *ctx) = 0;

  virtual void enterStmt_with_continue(SysYParser::Stmt_with_continueContext *ctx) = 0;
  virtual void exitStmt_with_continue(SysYParser::Stmt_with_continueContext *ctx) = 0;

  virtual void enterStmt_with_return(SysYParser::Stmt_with_returnContext *ctx) = 0;
  virtual void exitStmt_with_return(SysYParser::Stmt_with_returnContext *ctx) = 0;

  virtual void enterReturnStmt(SysYParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(SysYParser::ReturnStmtContext *ctx) = 0;

  virtual void enterExp_with_plus_and_mius(SysYParser::Exp_with_plus_and_miusContext *ctx) = 0;
  virtual void exitExp_with_plus_and_mius(SysYParser::Exp_with_plus_and_miusContext *ctx) = 0;

  virtual void enterExp_with_unaryOp(SysYParser::Exp_with_unaryOpContext *ctx) = 0;
  virtual void exitExp_with_unaryOp(SysYParser::Exp_with_unaryOpContext *ctx) = 0;

  virtual void enterExp_with_symbol(SysYParser::Exp_with_symbolContext *ctx) = 0;
  virtual void exitExp_with_symbol(SysYParser::Exp_with_symbolContext *ctx) = 0;

  virtual void enterExp_with_lval(SysYParser::Exp_with_lvalContext *ctx) = 0;
  virtual void exitExp_with_lval(SysYParser::Exp_with_lvalContext *ctx) = 0;

  virtual void enterExp_with_Paren(SysYParser::Exp_with_ParenContext *ctx) = 0;
  virtual void exitExp_with_Paren(SysYParser::Exp_with_ParenContext *ctx) = 0;

  virtual void enterExp_with_num(SysYParser::Exp_with_numContext *ctx) = 0;
  virtual void exitExp_with_num(SysYParser::Exp_with_numContext *ctx) = 0;

  virtual void enterExp_with_funcRParams(SysYParser::Exp_with_funcRParamsContext *ctx) = 0;
  virtual void exitExp_with_funcRParams(SysYParser::Exp_with_funcRParamsContext *ctx) = 0;

  virtual void enterCond(SysYParser::CondContext *ctx) = 0;
  virtual void exitCond(SysYParser::CondContext *ctx) = 0;

  virtual void enterLVal(SysYParser::LValContext *ctx) = 0;
  virtual void exitLVal(SysYParser::LValContext *ctx) = 0;

  virtual void enterNumber(SysYParser::NumberContext *ctx) = 0;
  virtual void exitNumber(SysYParser::NumberContext *ctx) = 0;

  virtual void enterUnaryOp(SysYParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(SysYParser::UnaryOpContext *ctx) = 0;

  virtual void enterFuncRParams(SysYParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(SysYParser::FuncRParamsContext *ctx) = 0;

  virtual void enterParam(SysYParser::ParamContext *ctx) = 0;
  virtual void exitParam(SysYParser::ParamContext *ctx) = 0;

  virtual void enterConstExp(SysYParser::ConstExpContext *ctx) = 0;
  virtual void exitConstExp(SysYParser::ConstExpContext *ctx) = 0;


};

