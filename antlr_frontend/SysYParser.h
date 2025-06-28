
// Generated from SysYParser.g4 by ANTLR 4.13.0

#pragma once

#include "antlr4-runtime.h"

class SysYParser : public antlr4::Parser {
public:
    enum {
        CONST = 1,
        INT = 2,
        FLOAT = 3,
        VOID = 4,
        IF = 5,
        ELSE = 6,
        WHILE = 7,
        BREAK = 8,
        CONTINUE = 9,
        RETURN = 10,
        PLUS = 11,
        MINUS = 12,
        MUL = 13,
        DIV = 14,
        MOD = 15,
        ASSIGN = 16,
        EQ = 17,
        NEQ = 18,
        LT = 19,
        GT = 20,
        LE = 21,
        GE = 22,
        NOT = 23,
        AND = 24,
        OR = 25,
        L_PAREN = 26,
        R_PAREN = 27,
        L_BRACE = 28,
        R_BRACE = 29,
        L_BRACKT = 30,
        R_BRACKT = 31,
        COMMA = 32,
        SEMICOLON = 33,
        IDENT = 34,
        INTEGER_CONST = 35,
        FLOAT_CONST = 36,
        DecimalFloatingConstant = 37,
        HexadecimalFloatingConstant = 38,
        WS = 39,
        LINE_COMMENT = 40,
        MULTILINE_COMMENT = 41
    };

    enum {
        RuleProgram = 0,
        RuleCompUnit = 1,
        RuleDecl = 2,
        RuleConstDecl = 3,
        RuleBType = 4,
        RuleConstDef = 5,
        RuleConstInitVal = 6,
        RuleVarDecl = 7,
        RuleVarDef = 8,
        RuleInitVal = 9,
        RuleFuncDef = 10,
        RuleFuncType = 11,
        RuleFuncFParams = 12,
        RuleFuncFParam = 13,
        RuleBlock = 14,
        RuleBlockItem = 15,
        RuleStmt = 16,
        RuleReturnStmt = 17,
        RuleExp = 18,
        RuleCond = 19,
        RuleLVal = 20,
        RuleNumber = 21,
        RuleUnaryOp = 22,
        RuleFuncRParams = 23,
        RuleParam = 24,
        RuleConstExp = 25
    };

    explicit SysYParser(antlr4::TokenStream *input);

    SysYParser(antlr4::TokenStream *input,
               antlr4::atn::ParserATNSimulatorOptions const &options);

    ~SysYParser() override;

    std::string getGrammarFileName() const override;

    antlr4::atn::ATN const &getATN() const override;

    std::vector<std::string> const &getRuleNames() const override;

    antlr4::dfa::Vocabulary const &getVocabulary() const override;

    antlr4::atn::SerializedATNView getSerializedATN() const override;

    class ProgramContext;
    class CompUnitContext;
    class DeclContext;
    class ConstDeclContext;
    class BTypeContext;
    class ConstDefContext;
    class ConstInitValContext;
    class VarDeclContext;
    class VarDefContext;
    class InitValContext;
    class FuncDefContext;
    class FuncTypeContext;
    class FuncFParamsContext;
    class FuncFParamContext;
    class BlockContext;
    class BlockItemContext;
    class StmtContext;
    class ReturnStmtContext;
    class ExpContext;
    class CondContext;
    class LValContext;
    class NumberContext;
    class UnaryOpContext;
    class FuncRParamsContext;
    class ParamContext;
    class ConstExpContext;

    class ProgramContext : public antlr4::ParserRuleContext {
    public:
        ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        CompUnitContext *compUnit();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ProgramContext *program();

    class CompUnitContext : public antlr4::ParserRuleContext {
    public:
        CompUnitContext(antlr4::ParserRuleContext *parent,
                        size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *EOF();
        std::vector<FuncDefContext *> funcDef();
        FuncDefContext *funcDef(size_t i);
        std::vector<DeclContext *> decl();
        DeclContext *decl(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    CompUnitContext *compUnit();

    class DeclContext : public antlr4::ParserRuleContext {
    public:
        DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ConstDeclContext *constDecl();
        VarDeclContext *varDecl();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    DeclContext *decl();

    class ConstDeclContext : public antlr4::ParserRuleContext {
    public:
        ConstDeclContext(antlr4::ParserRuleContext *parent,
                         size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *CONST();
        BTypeContext *bType();
        std::vector<ConstDefContext *> constDef();
        ConstDefContext *constDef(size_t i);
        antlr4::tree::TerminalNode *SEMICOLON();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ConstDeclContext *constDecl();

    class BTypeContext : public antlr4::ParserRuleContext {
    public:
        BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *INT();
        antlr4::tree::TerminalNode *FLOAT();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    BTypeContext *bType();

    class ConstDefContext : public antlr4::ParserRuleContext {
    public:
        ConstDefContext(antlr4::ParserRuleContext *parent,
                        size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *IDENT();
        antlr4::tree::TerminalNode *ASSIGN();
        ConstInitValContext *constInitVal();
        std::vector<antlr4::tree::TerminalNode *> L_BRACKT();
        antlr4::tree::TerminalNode *L_BRACKT(size_t i);
        std::vector<ConstExpContext *> constExp();
        ConstExpContext *constExp(size_t i);
        std::vector<antlr4::tree::TerminalNode *> R_BRACKT();
        antlr4::tree::TerminalNode *R_BRACKT(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ConstDefContext *constDef();

    class ConstInitValContext : public antlr4::ParserRuleContext {
    public:
        ConstInitValContext(antlr4::ParserRuleContext *parent,
                            size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ConstExpContext *constExp();
        antlr4::tree::TerminalNode *L_BRACE();
        antlr4::tree::TerminalNode *R_BRACE();
        std::vector<ConstInitValContext *> constInitVal();
        ConstInitValContext *constInitVal(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ConstInitValContext *constInitVal();

    class VarDeclContext : public antlr4::ParserRuleContext {
    public:
        VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        BTypeContext *bType();
        std::vector<VarDefContext *> varDef();
        VarDefContext *varDef(size_t i);
        antlr4::tree::TerminalNode *SEMICOLON();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    VarDeclContext *varDecl();

    class VarDefContext : public antlr4::ParserRuleContext {
    public:
        VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *IDENT();
        std::vector<antlr4::tree::TerminalNode *> L_BRACKT();
        antlr4::tree::TerminalNode *L_BRACKT(size_t i);
        std::vector<ConstExpContext *> constExp();
        ConstExpContext *constExp(size_t i);
        std::vector<antlr4::tree::TerminalNode *> R_BRACKT();
        antlr4::tree::TerminalNode *R_BRACKT(size_t i);
        antlr4::tree::TerminalNode *ASSIGN();
        InitValContext *initVal();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    VarDefContext *varDef();

    class InitValContext : public antlr4::ParserRuleContext {
    public:
        InitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpContext *exp();
        antlr4::tree::TerminalNode *L_BRACE();
        antlr4::tree::TerminalNode *R_BRACE();
        std::vector<InitValContext *> initVal();
        InitValContext *initVal(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    InitValContext *initVal();

    class FuncDefContext : public antlr4::ParserRuleContext {
    public:
        FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        FuncTypeContext *funcType();
        antlr4::tree::TerminalNode *IDENT();
        antlr4::tree::TerminalNode *L_PAREN();
        antlr4::tree::TerminalNode *R_PAREN();
        BlockContext *block();
        FuncFParamsContext *funcFParams();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    FuncDefContext *funcDef();

    class FuncTypeContext : public antlr4::ParserRuleContext {
    public:
        FuncTypeContext(antlr4::ParserRuleContext *parent,
                        size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *VOID();
        antlr4::tree::TerminalNode *INT();
        antlr4::tree::TerminalNode *FLOAT();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    FuncTypeContext *funcType();

    class FuncFParamsContext : public antlr4::ParserRuleContext {
    public:
        FuncFParamsContext(antlr4::ParserRuleContext *parent,
                           size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<FuncFParamContext *> funcFParam();
        FuncFParamContext *funcFParam(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    FuncFParamsContext *funcFParams();

    class FuncFParamContext : public antlr4::ParserRuleContext {
    public:
        FuncFParamContext(antlr4::ParserRuleContext *parent,
                          size_t invokingState);
        virtual size_t getRuleIndex() const override;
        BTypeContext *bType();
        antlr4::tree::TerminalNode *IDENT();
        std::vector<antlr4::tree::TerminalNode *> L_BRACKT();
        antlr4::tree::TerminalNode *L_BRACKT(size_t i);
        std::vector<antlr4::tree::TerminalNode *> R_BRACKT();
        antlr4::tree::TerminalNode *R_BRACKT(size_t i);
        std::vector<ExpContext *> exp();
        ExpContext *exp(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    FuncFParamContext *funcFParam();

    class BlockContext : public antlr4::ParserRuleContext {
    public:
        BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *L_BRACE();
        antlr4::tree::TerminalNode *R_BRACE();
        std::vector<BlockItemContext *> blockItem();
        BlockItemContext *blockItem(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    BlockContext *block();

    class BlockItemContext : public antlr4::ParserRuleContext {
    public:
        BlockItemContext(antlr4::ParserRuleContext *parent,
                         size_t invokingState);
        virtual size_t getRuleIndex() const override;
        DeclContext *decl();
        StmtContext *stmt();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    BlockItemContext *blockItem();

    class StmtContext : public antlr4::ParserRuleContext {
    public:
        StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        StmtContext() = default;
        void copyFrom(StmtContext *context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class Stmt_with_expContext : public StmtContext {
    public:
        Stmt_with_expContext(StmtContext *ctx);

        antlr4::tree::TerminalNode *SEMICOLON();
        ExpContext *exp();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Stmt_with_continueContext : public StmtContext {
    public:
        Stmt_with_continueContext(StmtContext *ctx);

        antlr4::tree::TerminalNode *CONTINUE();
        antlr4::tree::TerminalNode *SEMICOLON();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Stmt_with_ifContext : public StmtContext {
    public:
        Stmt_with_ifContext(StmtContext *ctx);

        antlr4::tree::TerminalNode *IF();
        antlr4::tree::TerminalNode *L_PAREN();
        CondContext *cond();
        antlr4::tree::TerminalNode *R_PAREN();
        std::vector<StmtContext *> stmt();
        StmtContext *stmt(size_t i);
        antlr4::tree::TerminalNode *ELSE();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Stmt_with_returnContext : public StmtContext {
    public:
        Stmt_with_returnContext(StmtContext *ctx);

        ReturnStmtContext *returnStmt();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Stmt_with_assignContext : public StmtContext {
    public:
        Stmt_with_assignContext(StmtContext *ctx);

        LValContext *lVal();
        antlr4::tree::TerminalNode *ASSIGN();
        ExpContext *exp();
        antlr4::tree::TerminalNode *SEMICOLON();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Stmt_with_whileContext : public StmtContext {
    public:
        Stmt_with_whileContext(StmtContext *ctx);

        antlr4::tree::TerminalNode *WHILE();
        antlr4::tree::TerminalNode *L_PAREN();
        CondContext *cond();
        antlr4::tree::TerminalNode *R_PAREN();
        StmtContext *stmt();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Stmt_with_blockContext : public StmtContext {
    public:
        Stmt_with_blockContext(StmtContext *ctx);

        BlockContext *block();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Stmt_with_breakContext : public StmtContext {
    public:
        Stmt_with_breakContext(StmtContext *ctx);

        antlr4::tree::TerminalNode *BREAK();
        antlr4::tree::TerminalNode *SEMICOLON();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    StmtContext *stmt();

    class ReturnStmtContext : public antlr4::ParserRuleContext {
    public:
        ReturnStmtContext(antlr4::ParserRuleContext *parent,
                          size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *RETURN();
        antlr4::tree::TerminalNode *SEMICOLON();
        ExpContext *exp();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ReturnStmtContext *returnStmt();

    class ExpContext : public antlr4::ParserRuleContext {
    public:
        ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        ExpContext() = default;
        void copyFrom(ExpContext *context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class Exp_with_plus_and_miusContext : public ExpContext {
    public:
        Exp_with_plus_and_miusContext(ExpContext *ctx);

        std::vector<ExpContext *> exp();
        ExpContext *exp(size_t i);
        antlr4::tree::TerminalNode *PLUS();
        antlr4::tree::TerminalNode *MINUS();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Exp_with_unaryOpContext : public ExpContext {
    public:
        Exp_with_unaryOpContext(ExpContext *ctx);

        UnaryOpContext *unaryOp();
        ExpContext *exp();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Exp_with_symbolContext : public ExpContext {
    public:
        Exp_with_symbolContext(ExpContext *ctx);

        std::vector<ExpContext *> exp();
        ExpContext *exp(size_t i);
        antlr4::tree::TerminalNode *MUL();
        antlr4::tree::TerminalNode *DIV();
        antlr4::tree::TerminalNode *MOD();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Exp_with_lvalContext : public ExpContext {
    public:
        Exp_with_lvalContext(ExpContext *ctx);

        LValContext *lVal();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Exp_with_ParenContext : public ExpContext {
    public:
        Exp_with_ParenContext(ExpContext *ctx);

        antlr4::tree::TerminalNode *L_PAREN();
        ExpContext *exp();
        antlr4::tree::TerminalNode *R_PAREN();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Exp_with_numContext : public ExpContext {
    public:
        Exp_with_numContext(ExpContext *ctx);

        NumberContext *number();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    class Exp_with_funcRParamsContext : public ExpContext {
    public:
        Exp_with_funcRParamsContext(ExpContext *ctx);

        antlr4::tree::TerminalNode *IDENT();
        antlr4::tree::TerminalNode *L_PAREN();
        antlr4::tree::TerminalNode *R_PAREN();
        FuncRParamsContext *funcRParams();
        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ExpContext *exp();
    ExpContext *exp(int precedence);

    class CondContext : public antlr4::ParserRuleContext {
    public:
        CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpContext *exp();
        std::vector<CondContext *> cond();
        CondContext *cond(size_t i);
        antlr4::tree::TerminalNode *LT();
        antlr4::tree::TerminalNode *GT();
        antlr4::tree::TerminalNode *LE();
        antlr4::tree::TerminalNode *GE();
        antlr4::tree::TerminalNode *EQ();
        antlr4::tree::TerminalNode *NEQ();
        antlr4::tree::TerminalNode *AND();
        antlr4::tree::TerminalNode *OR();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    CondContext *cond();
    CondContext *cond(int precedence);

    class LValContext : public antlr4::ParserRuleContext {
    public:
        LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *IDENT();
        std::vector<antlr4::tree::TerminalNode *> L_BRACKT();
        antlr4::tree::TerminalNode *L_BRACKT(size_t i);
        std::vector<ExpContext *> exp();
        ExpContext *exp(size_t i);
        std::vector<antlr4::tree::TerminalNode *> R_BRACKT();
        antlr4::tree::TerminalNode *R_BRACKT(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    LValContext *lVal();

    class NumberContext : public antlr4::ParserRuleContext {
    public:
        NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *INTEGER_CONST();
        antlr4::tree::TerminalNode *FLOAT_CONST();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    NumberContext *number();

    class UnaryOpContext : public antlr4::ParserRuleContext {
    public:
        UnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *PLUS();
        antlr4::tree::TerminalNode *MINUS();
        antlr4::tree::TerminalNode *NOT();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    UnaryOpContext *unaryOp();

    class FuncRParamsContext : public antlr4::ParserRuleContext {
    public:
        FuncRParamsContext(antlr4::ParserRuleContext *parent,
                           size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<ParamContext *> param();
        ParamContext *param(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    FuncRParamsContext *funcRParams();

    class ParamContext : public antlr4::ParserRuleContext {
    public:
        ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpContext *exp();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ParamContext *param();

    class ConstExpContext : public antlr4::ParserRuleContext {
    public:
        ConstExpContext(antlr4::ParserRuleContext *parent,
                        size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpContext *exp();

        virtual void
        enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void
        exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual std::any
        accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ConstExpContext *constExp();

    bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex,
                 size_t predicateIndex) override;

    bool expSempred(ExpContext *_localctx, size_t predicateIndex);
    bool condSempred(CondContext *_localctx, size_t predicateIndex);

    // By default the static state used to implement the parser is lazily
    // initialized during the first call to the constructor. You can call this
    // function if you wish to initialize the static state ahead of time.
    static void initialize();

private:
};
