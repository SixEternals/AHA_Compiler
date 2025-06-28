#include "midend/IRVisitor.hpp"
#include "midend/IRContext.hpp"
#include "midend/Type.hpp"
#include "midend/Value.hpp"
#include <any>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

IRVisitor::IRVisitor(std::string source) {}

void IRVisitor::addLibs() {
    // todo
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

std::any IRVisitor::visitConstDef(SysYParser::ConstDefContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitConstInitVal(SysYParser::ConstInitValContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitVarDecl(SysYParser::VarDeclContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitVarDef(SysYParser::VarDefContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitInitVal(SysYParser::InitValContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitFuncDef(SysYParser::FuncDefContext *ctx) {
    // 打印函数定义的树形AST结构
    std::cout << "FunctionDef" << std::endl;

    // 1. 函数返回类型
    std::string returnTypeStr = "void";
    if (ctx->funcType()) {
        if (ctx->funcType()->INT()) {
            returnTypeStr = "int";
        } else if (ctx->funcType()->FLOAT()) {
            returnTypeStr = "float";
        }
    }
    printASTNode("", "ReturnType", returnTypeStr, false);

    // 2. 函数名
    std::string funcName = ctx->IDENT() ? ctx->IDENT()->getText() : "<unknown>";
    printASTNode("", "FunctionName", funcName, false);

    // 3. 函数参数
    if (ctx->funcFParams()) {
        auto params = ctx->funcFParams()->funcFParam();
        printASTNode("", "Parameters", false);

        for (size_t i = 0; i < params.size(); i++) {
            auto param = params[i];
            std::string paramType = param->bType()->getText();
            std::string paramName = param->IDENT()->getText();

            std::string paramPrefix = "    ";
            bool isLastParam = (i == params.size() - 1);

            printASTNode(paramPrefix, "Parameter", false);
            printASTNode(paramPrefix + "    ", "Type", paramType, false);
            printASTNode(paramPrefix + "    ", "Name", paramName, false);

            // 如果是数组参数
            if (!param->L_BRACKT().empty()) {
                printASTNode(paramPrefix + "    ", "ArrayDimensions", false);
                for (size_t j = 0; j < param->L_BRACKT().size(); j++) {
                    std::string dimPrefix = paramPrefix + "        ";
                    bool isLastDim = (j == param->L_BRACKT().size() - 1);
                    if (j < param->exp().size()) {
                        printASTNode(dimPrefix, "Dimension", "expression",
                                     isLastDim);
                    } else {
                        printASTNode(dimPrefix, "Dimension", "[]", isLastDim);
                    }
                }
            }
        }
    } else {
        printASTNode("", "Parameters", "none", false);
    }

    // 4. 函数体
    printASTNode("", "FunctionBody", "{ ... }", true);

    std::cout << std::endl;

    // 原有的类型处理逻辑（简化版）
    Type *returnType;
    if (ctx->funcType() && ctx->funcType()->INT()) {
        returnType = Type::getInt32Type();
    } else if (ctx->funcType() && ctx->funcType()->FLOAT()) {
        returnType = Type::getFloatType();
    } else {
        returnType = Type::getVoidType();
    }

    // 构造形参类型列表
    std::vector<Type *> paramTypes;
    if (ctx->funcFParams()) {
        auto params = ctx->funcFParams()->funcFParam();
        for (auto param: params) {
            std::string paramTypeName = param->bType()->getText();
            if (paramTypeName == "int") {
                paramTypes.push_back(Type::getInt32Type());
            } else if (paramTypeName == "float") {
                paramTypes.push_back(Type::getFloatType());
            }
        }
    }

    // 构造函数类型
    FunctionType *functionType = FunctionType::get(returnType, paramTypes);

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

std::any IRVisitor::visitBlock(SysYParser::BlockContext *ctx) {
    // 按照Java版本的逻辑修改
    // currentBlockName = currentBlockName + localScopeCounter;
    // localScopeCounter++;
    // currentScope = new Scope(currentBlockName, currentScope, currentBlock);

    // 打印Block的AST结构
    std::cout << "Block" << std::endl;
    printASTNode("", "BlockBody", "{ ... }", true);

    // IRValueRef ret = super.visitBlock(ctx);
    std::any ret = visitChildren(ctx);

    // currentScope = currentScope.getFatherScope();

    return ret;
}

std::any IRVisitor::visitBlockItem(SysYParser::BlockItemContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitStmt_with_assign(SysYParser::Stmt_with_assignContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitStmt_with_exp(SysYParser::Stmt_with_expContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitStmt_with_block(SysYParser::Stmt_with_blockContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitStmt_with_if(SysYParser::Stmt_with_ifContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitStmt_with_while(SysYParser::Stmt_with_whileContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitStmt_with_break(SysYParser::Stmt_with_breakContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitStmt_with_continue(SysYParser::Stmt_with_continueContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitStmt_with_return(SysYParser::Stmt_with_returnContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitReturnStmt(SysYParser::ReturnStmtContext *ctx) {
    std::cout << "ReturnStmt" << std::endl;
    // 生产返回值，根据返回值
    // bug：这段有可能访问空
    // if (ctx->exp()) {
    //     printASTNode("  ", "ReturnExpr", false);
    //     auto result = std::any_cast<Value *>(visit(ctx->exp()));

    // }
    return visitChildren(ctx);
}

std::any IRVisitor::visitExp_with_plus_and_mius(
    SysYParser::Exp_with_plus_and_miusContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitExp_with_unaryOp(SysYParser::Exp_with_unaryOpContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitExp_with_symbol(SysYParser::Exp_with_symbolContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitExp_with_lval(SysYParser::Exp_with_lvalContext *ctx) {
    return visitChildren(ctx);
}

std::any
IRVisitor::visitExp_with_Paren(SysYParser::Exp_with_ParenContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitExp_with_num(SysYParser::Exp_with_numContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitExp_with_funcRParams(
    SysYParser::Exp_with_funcRParamsContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitCond(SysYParser::CondContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitLVal(SysYParser::LValContext *ctx) {
    return visitChildren(ctx);
}

std::any IRVisitor::visitNumber(SysYParser::NumberContext *ctx) {
    return visitChildren(ctx);
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
