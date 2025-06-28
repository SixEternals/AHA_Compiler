
// Generated from SysYParser.g4 by ANTLR 4.13.0


#include "SysYParserListener.h"
#include "SysYParserVisitor.h"

#include "SysYParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SysYParserStaticData final {
  SysYParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SysYParserStaticData(const SysYParserStaticData&) = delete;
  SysYParserStaticData(SysYParserStaticData&&) = delete;
  SysYParserStaticData& operator=(const SysYParserStaticData&) = delete;
  SysYParserStaticData& operator=(SysYParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sysyparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
SysYParserStaticData *sysyparserParserStaticData = nullptr;

void sysyparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (sysyparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(sysyparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SysYParserStaticData>(
    std::vector<std::string>{
      "program", "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
      "varDecl", "varDef", "initVal", "funcDef", "funcType", "funcFParams", 
      "funcFParam", "block", "blockItem", "stmt", "returnStmt", "exp", "cond", 
      "lVal", "number", "unaryOp", "funcRParams", "param", "constExp"
    },
    std::vector<std::string>{
      "", "'const'", "'int'", "'float'", "'void'", "'if'", "'else'", "'while'", 
      "'break'", "'continue'", "'return'", "'+'", "'-'", "'*'", "'/'", "'%'", 
      "'='", "'=='", "'!='", "'<'", "'>'", "'<='", "'>='", "'!'", "'&&'", 
      "'||'", "'('", "')'", "'{'", "'}'", "'['", "']'", "','", "';'"
    },
    std::vector<std::string>{
      "", "CONST", "INT", "FLOAT", "VOID", "IF", "ELSE", "WHILE", "BREAK", 
      "CONTINUE", "RETURN", "PLUS", "MINUS", "MUL", "DIV", "MOD", "ASSIGN", 
      "EQ", "NEQ", "LT", "GT", "LE", "GE", "NOT", "AND", "OR", "L_PAREN", 
      "R_PAREN", "L_BRACE", "R_BRACE", "L_BRACKT", "R_BRACKT", "COMMA", 
      "SEMICOLON", "IDENT", "INTEGER_CONST", "FLOAT_CONST", "DecimalFloatingConstant", 
      "HexadecimalFloatingConstant", "WS", "LINE_COMMENT", "MULTILINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,309,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,1,0,1,1,1,1,4,1,57,8,1,
  	11,1,12,1,58,1,1,1,1,1,2,1,2,3,2,65,8,2,1,3,1,3,1,3,1,3,1,3,5,3,72,8,
  	3,10,3,12,3,75,9,3,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,5,1,5,5,5,86,8,5,10,
  	5,12,5,89,9,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,5,6,99,8,6,10,6,12,6,102,
  	9,6,3,6,104,8,6,1,6,3,6,107,8,6,1,7,1,7,1,7,1,7,5,7,113,8,7,10,7,12,7,
  	116,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,5,8,125,8,8,10,8,12,8,128,9,8,1,8,
  	1,8,3,8,132,8,8,1,9,1,9,1,9,1,9,1,9,5,9,139,8,9,10,9,12,9,142,9,9,3,9,
  	144,8,9,1,9,3,9,147,8,9,1,10,1,10,1,10,1,10,3,10,153,8,10,1,10,1,10,1,
  	10,1,11,1,11,1,12,1,12,1,12,5,12,163,8,12,10,12,12,12,166,9,12,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,5,13,176,8,13,10,13,12,13,179,9,13,3,
  	13,181,8,13,1,14,1,14,5,14,185,8,14,10,14,12,14,188,9,14,1,14,1,14,1,
  	15,1,15,3,15,194,8,15,1,16,1,16,1,16,1,16,1,16,1,16,3,16,202,8,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,213,8,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,226,8,16,1,17,1,17,3,17,
  	230,8,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,
  	3,18,244,8,18,1,18,1,18,1,18,1,18,3,18,250,8,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,5,18,258,8,18,10,18,12,18,261,9,18,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,278,8,19,10,19,12,
  	19,281,9,19,1,20,1,20,1,20,1,20,1,20,5,20,288,8,20,10,20,12,20,291,9,
  	20,1,21,1,21,1,22,1,22,1,23,1,23,1,23,5,23,300,8,23,10,23,12,23,303,9,
  	23,1,24,1,24,1,25,1,25,1,25,0,2,36,38,26,0,2,4,6,8,10,12,14,16,18,20,
  	22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,0,8,1,0,2,3,1,0,2,4,1,0,
  	13,15,1,0,11,12,1,0,19,22,1,0,17,18,1,0,35,36,2,0,11,12,23,23,325,0,52,
  	1,0,0,0,2,56,1,0,0,0,4,64,1,0,0,0,6,66,1,0,0,0,8,78,1,0,0,0,10,80,1,0,
  	0,0,12,106,1,0,0,0,14,108,1,0,0,0,16,119,1,0,0,0,18,146,1,0,0,0,20,148,
  	1,0,0,0,22,157,1,0,0,0,24,159,1,0,0,0,26,167,1,0,0,0,28,182,1,0,0,0,30,
  	193,1,0,0,0,32,225,1,0,0,0,34,227,1,0,0,0,36,249,1,0,0,0,38,262,1,0,0,
  	0,40,282,1,0,0,0,42,292,1,0,0,0,44,294,1,0,0,0,46,296,1,0,0,0,48,304,
  	1,0,0,0,50,306,1,0,0,0,52,53,3,2,1,0,53,1,1,0,0,0,54,57,3,20,10,0,55,
  	57,3,4,2,0,56,54,1,0,0,0,56,55,1,0,0,0,57,58,1,0,0,0,58,56,1,0,0,0,58,
  	59,1,0,0,0,59,60,1,0,0,0,60,61,5,0,0,1,61,3,1,0,0,0,62,65,3,6,3,0,63,
  	65,3,14,7,0,64,62,1,0,0,0,64,63,1,0,0,0,65,5,1,0,0,0,66,67,5,1,0,0,67,
  	68,3,8,4,0,68,73,3,10,5,0,69,70,5,32,0,0,70,72,3,10,5,0,71,69,1,0,0,0,
  	72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,76,1,0,0,0,75,73,1,0,0,0,
  	76,77,5,33,0,0,77,7,1,0,0,0,78,79,7,0,0,0,79,9,1,0,0,0,80,87,5,34,0,0,
  	81,82,5,30,0,0,82,83,3,50,25,0,83,84,5,31,0,0,84,86,1,0,0,0,85,81,1,0,
  	0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,90,1,0,0,0,89,87,1,0,
  	0,0,90,91,5,16,0,0,91,92,3,12,6,0,92,11,1,0,0,0,93,107,3,50,25,0,94,103,
  	5,28,0,0,95,100,3,12,6,0,96,97,5,32,0,0,97,99,3,12,6,0,98,96,1,0,0,0,
  	99,102,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,104,1,0,0,0,102,100,
  	1,0,0,0,103,95,1,0,0,0,103,104,1,0,0,0,104,105,1,0,0,0,105,107,5,29,0,
  	0,106,93,1,0,0,0,106,94,1,0,0,0,107,13,1,0,0,0,108,109,3,8,4,0,109,114,
  	3,16,8,0,110,111,5,32,0,0,111,113,3,16,8,0,112,110,1,0,0,0,113,116,1,
  	0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,117,1,0,0,0,116,114,1,0,0,0,
  	117,118,5,33,0,0,118,15,1,0,0,0,119,126,5,34,0,0,120,121,5,30,0,0,121,
  	122,3,50,25,0,122,123,5,31,0,0,123,125,1,0,0,0,124,120,1,0,0,0,125,128,
  	1,0,0,0,126,124,1,0,0,0,126,127,1,0,0,0,127,131,1,0,0,0,128,126,1,0,0,
  	0,129,130,5,16,0,0,130,132,3,18,9,0,131,129,1,0,0,0,131,132,1,0,0,0,132,
  	17,1,0,0,0,133,147,3,36,18,0,134,143,5,28,0,0,135,140,3,18,9,0,136,137,
  	5,32,0,0,137,139,3,18,9,0,138,136,1,0,0,0,139,142,1,0,0,0,140,138,1,0,
  	0,0,140,141,1,0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,143,135,1,0,0,0,143,
  	144,1,0,0,0,144,145,1,0,0,0,145,147,5,29,0,0,146,133,1,0,0,0,146,134,
  	1,0,0,0,147,19,1,0,0,0,148,149,3,22,11,0,149,150,5,34,0,0,150,152,5,26,
  	0,0,151,153,3,24,12,0,152,151,1,0,0,0,152,153,1,0,0,0,153,154,1,0,0,0,
  	154,155,5,27,0,0,155,156,3,28,14,0,156,21,1,0,0,0,157,158,7,1,0,0,158,
  	23,1,0,0,0,159,164,3,26,13,0,160,161,5,32,0,0,161,163,3,26,13,0,162,160,
  	1,0,0,0,163,166,1,0,0,0,164,162,1,0,0,0,164,165,1,0,0,0,165,25,1,0,0,
  	0,166,164,1,0,0,0,167,168,3,8,4,0,168,180,5,34,0,0,169,170,5,30,0,0,170,
  	177,5,31,0,0,171,172,5,30,0,0,172,173,3,36,18,0,173,174,5,31,0,0,174,
  	176,1,0,0,0,175,171,1,0,0,0,176,179,1,0,0,0,177,175,1,0,0,0,177,178,1,
  	0,0,0,178,181,1,0,0,0,179,177,1,0,0,0,180,169,1,0,0,0,180,181,1,0,0,0,
  	181,27,1,0,0,0,182,186,5,28,0,0,183,185,3,30,15,0,184,183,1,0,0,0,185,
  	188,1,0,0,0,186,184,1,0,0,0,186,187,1,0,0,0,187,189,1,0,0,0,188,186,1,
  	0,0,0,189,190,5,29,0,0,190,29,1,0,0,0,191,194,3,4,2,0,192,194,3,32,16,
  	0,193,191,1,0,0,0,193,192,1,0,0,0,194,31,1,0,0,0,195,196,3,40,20,0,196,
  	197,5,16,0,0,197,198,3,36,18,0,198,199,5,33,0,0,199,226,1,0,0,0,200,202,
  	3,36,18,0,201,200,1,0,0,0,201,202,1,0,0,0,202,203,1,0,0,0,203,226,5,33,
  	0,0,204,226,3,28,14,0,205,206,5,5,0,0,206,207,5,26,0,0,207,208,3,38,19,
  	0,208,209,5,27,0,0,209,212,3,32,16,0,210,211,5,6,0,0,211,213,3,32,16,
  	0,212,210,1,0,0,0,212,213,1,0,0,0,213,226,1,0,0,0,214,215,5,7,0,0,215,
  	216,5,26,0,0,216,217,3,38,19,0,217,218,5,27,0,0,218,219,3,32,16,0,219,
  	226,1,0,0,0,220,221,5,8,0,0,221,226,5,33,0,0,222,223,5,9,0,0,223,226,
  	5,33,0,0,224,226,3,34,17,0,225,195,1,0,0,0,225,201,1,0,0,0,225,204,1,
  	0,0,0,225,205,1,0,0,0,225,214,1,0,0,0,225,220,1,0,0,0,225,222,1,0,0,0,
  	225,224,1,0,0,0,226,33,1,0,0,0,227,229,5,10,0,0,228,230,3,36,18,0,229,
  	228,1,0,0,0,229,230,1,0,0,0,230,231,1,0,0,0,231,232,5,33,0,0,232,35,1,
  	0,0,0,233,234,6,18,-1,0,234,235,5,26,0,0,235,236,3,36,18,0,236,237,5,
  	27,0,0,237,250,1,0,0,0,238,250,3,40,20,0,239,250,3,42,21,0,240,241,5,
  	34,0,0,241,243,5,26,0,0,242,244,3,46,23,0,243,242,1,0,0,0,243,244,1,0,
  	0,0,244,245,1,0,0,0,245,250,5,27,0,0,246,247,3,44,22,0,247,248,3,36,18,
  	3,248,250,1,0,0,0,249,233,1,0,0,0,249,238,1,0,0,0,249,239,1,0,0,0,249,
  	240,1,0,0,0,249,246,1,0,0,0,250,259,1,0,0,0,251,252,10,2,0,0,252,253,
  	7,2,0,0,253,258,3,36,18,3,254,255,10,1,0,0,255,256,7,3,0,0,256,258,3,
  	36,18,2,257,251,1,0,0,0,257,254,1,0,0,0,258,261,1,0,0,0,259,257,1,0,0,
  	0,259,260,1,0,0,0,260,37,1,0,0,0,261,259,1,0,0,0,262,263,6,19,-1,0,263,
  	264,3,36,18,0,264,279,1,0,0,0,265,266,10,4,0,0,266,267,7,4,0,0,267,278,
  	3,38,19,5,268,269,10,3,0,0,269,270,7,5,0,0,270,278,3,38,19,4,271,272,
  	10,2,0,0,272,273,5,24,0,0,273,278,3,38,19,3,274,275,10,1,0,0,275,276,
  	5,25,0,0,276,278,3,38,19,2,277,265,1,0,0,0,277,268,1,0,0,0,277,271,1,
  	0,0,0,277,274,1,0,0,0,278,281,1,0,0,0,279,277,1,0,0,0,279,280,1,0,0,0,
  	280,39,1,0,0,0,281,279,1,0,0,0,282,289,5,34,0,0,283,284,5,30,0,0,284,
  	285,3,36,18,0,285,286,5,31,0,0,286,288,1,0,0,0,287,283,1,0,0,0,288,291,
  	1,0,0,0,289,287,1,0,0,0,289,290,1,0,0,0,290,41,1,0,0,0,291,289,1,0,0,
  	0,292,293,7,6,0,0,293,43,1,0,0,0,294,295,7,7,0,0,295,45,1,0,0,0,296,301,
  	3,48,24,0,297,298,5,32,0,0,298,300,3,48,24,0,299,297,1,0,0,0,300,303,
  	1,0,0,0,301,299,1,0,0,0,301,302,1,0,0,0,302,47,1,0,0,0,303,301,1,0,0,
  	0,304,305,3,36,18,0,305,49,1,0,0,0,306,307,3,36,18,0,307,51,1,0,0,0,32,
  	56,58,64,73,87,100,103,106,114,126,131,140,143,146,152,164,177,180,186,
  	193,201,212,225,229,243,249,257,259,277,279,289,301
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sysyparserParserStaticData = staticData.release();
}

}

SysYParser::SysYParser(TokenStream *input) : SysYParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SysYParser::SysYParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SysYParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sysyparserParserStaticData->atn, sysyparserParserStaticData->decisionToDFA, sysyparserParserStaticData->sharedContextCache, options);
}

SysYParser::~SysYParser() {
  delete _interpreter;
}

const atn::ATN& SysYParser::getATN() const {
  return *sysyparserParserStaticData->atn;
}

std::string SysYParser::getGrammarFileName() const {
  return "SysYParser.g4";
}

const std::vector<std::string>& SysYParser::getRuleNames() const {
  return sysyparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& SysYParser::getVocabulary() const {
  return sysyparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SysYParser::getSerializedATN() const {
  return sysyparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

SysYParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::CompUnitContext* SysYParser::ProgramContext::compUnit() {
  return getRuleContext<SysYParser::CompUnitContext>(0);
}


size_t SysYParser::ProgramContext::getRuleIndex() const {
  return SysYParser::RuleProgram;
}

void SysYParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void SysYParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any SysYParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ProgramContext* SysYParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SysYParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    compUnit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompUnitContext ------------------------------------------------------------------

SysYParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::CompUnitContext::EOF() {
  return getToken(SysYParser::EOF, 0);
}

std::vector<SysYParser::FuncDefContext *> SysYParser::CompUnitContext::funcDef() {
  return getRuleContexts<SysYParser::FuncDefContext>();
}

SysYParser::FuncDefContext* SysYParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<SysYParser::FuncDefContext>(i);
}

std::vector<SysYParser::DeclContext *> SysYParser::CompUnitContext::decl() {
  return getRuleContexts<SysYParser::DeclContext>();
}

SysYParser::DeclContext* SysYParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<SysYParser::DeclContext>(i);
}


size_t SysYParser::CompUnitContext::getRuleIndex() const {
  return SysYParser::RuleCompUnit;
}

void SysYParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void SysYParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}


std::any SysYParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CompUnitContext* SysYParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 2, SysYParser::RuleCompUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(56);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(54);
        funcDef();
        break;
      }

      case 2: {
        setState(55);
        decl();
        break;
      }

      default:
        break;
      }
      setState(58); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30) != 0));
    setState(60);
    match(SysYParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

SysYParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstDeclContext* SysYParser::DeclContext::constDecl() {
  return getRuleContext<SysYParser::ConstDeclContext>(0);
}

SysYParser::VarDeclContext* SysYParser::DeclContext::varDecl() {
  return getRuleContext<SysYParser::VarDeclContext>(0);
}


size_t SysYParser::DeclContext::getRuleIndex() const {
  return SysYParser::RuleDecl;
}

void SysYParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void SysYParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


std::any SysYParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::DeclContext* SysYParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SysYParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(62);
        constDecl();
        break;
      }

      case SysYParser::INT:
      case SysYParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(63);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

SysYParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDeclContext::CONST() {
  return getToken(SysYParser::CONST, 0);
}

SysYParser::BTypeContext* SysYParser::ConstDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::ConstDefContext *> SysYParser::ConstDeclContext::constDef() {
  return getRuleContexts<SysYParser::ConstDefContext>();
}

SysYParser::ConstDefContext* SysYParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<SysYParser::ConstDefContext>(i);
}

tree::TerminalNode* SysYParser::ConstDeclContext::SEMICOLON() {
  return getToken(SysYParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDeclContext::COMMA() {
  return getTokens(SysYParser::COMMA);
}

tree::TerminalNode* SysYParser::ConstDeclContext::COMMA(size_t i) {
  return getToken(SysYParser::COMMA, i);
}


size_t SysYParser::ConstDeclContext::getRuleIndex() const {
  return SysYParser::RuleConstDecl;
}

void SysYParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void SysYParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}


std::any SysYParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDeclContext* SysYParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, SysYParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(SysYParser::CONST);
    setState(67);
    bType();
    setState(68);
    constDef();
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::COMMA) {
      setState(69);
      match(SysYParser::COMMA);
      setState(70);
      constDef();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    match(SysYParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

SysYParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::BTypeContext::INT() {
  return getToken(SysYParser::INT, 0);
}

tree::TerminalNode* SysYParser::BTypeContext::FLOAT() {
  return getToken(SysYParser::FLOAT, 0);
}


size_t SysYParser::BTypeContext::getRuleIndex() const {
  return SysYParser::RuleBType;
}

void SysYParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void SysYParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}


std::any SysYParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BTypeContext* SysYParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, SysYParser::RuleBType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    _la = _input->LA(1);
    if (!(_la == SysYParser::INT

    || _la == SysYParser::FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

SysYParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDefContext::IDENT() {
  return getToken(SysYParser::IDENT, 0);
}

tree::TerminalNode* SysYParser::ConstDefContext::ASSIGN() {
  return getToken(SysYParser::ASSIGN, 0);
}

SysYParser::ConstInitValContext* SysYParser::ConstDefContext::constInitVal() {
  return getRuleContext<SysYParser::ConstInitValContext>(0);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDefContext::L_BRACKT() {
  return getTokens(SysYParser::L_BRACKT);
}

tree::TerminalNode* SysYParser::ConstDefContext::L_BRACKT(size_t i) {
  return getToken(SysYParser::L_BRACKT, i);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::ConstDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::ConstDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDefContext::R_BRACKT() {
  return getTokens(SysYParser::R_BRACKT);
}

tree::TerminalNode* SysYParser::ConstDefContext::R_BRACKT(size_t i) {
  return getToken(SysYParser::R_BRACKT, i);
}


size_t SysYParser::ConstDefContext::getRuleIndex() const {
  return SysYParser::RuleConstDef;
}

void SysYParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void SysYParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
}


std::any SysYParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDefContext* SysYParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 10, SysYParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(SysYParser::IDENT);
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::L_BRACKT) {
      setState(81);
      match(SysYParser::L_BRACKT);
      setState(82);
      constExp();
      setState(83);
      match(SysYParser::R_BRACKT);
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(SysYParser::ASSIGN);
    setState(91);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

SysYParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstExpContext* SysYParser::ConstInitValContext::constExp() {
  return getRuleContext<SysYParser::ConstExpContext>(0);
}

tree::TerminalNode* SysYParser::ConstInitValContext::L_BRACE() {
  return getToken(SysYParser::L_BRACE, 0);
}

tree::TerminalNode* SysYParser::ConstInitValContext::R_BRACE() {
  return getToken(SysYParser::R_BRACE, 0);
}

std::vector<SysYParser::ConstInitValContext *> SysYParser::ConstInitValContext::constInitVal() {
  return getRuleContexts<SysYParser::ConstInitValContext>();
}

SysYParser::ConstInitValContext* SysYParser::ConstInitValContext::constInitVal(size_t i) {
  return getRuleContext<SysYParser::ConstInitValContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::ConstInitValContext::COMMA() {
  return getTokens(SysYParser::COMMA);
}

tree::TerminalNode* SysYParser::ConstInitValContext::COMMA(size_t i) {
  return getToken(SysYParser::COMMA, i);
}


size_t SysYParser::ConstInitValContext::getRuleIndex() const {
  return SysYParser::RuleConstInitVal;
}

void SysYParser::ConstInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitVal(this);
}

void SysYParser::ConstInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitVal(this);
}


std::any SysYParser::ConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitConstInitVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstInitValContext* SysYParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 12, SysYParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::PLUS:
      case SysYParser::MINUS:
      case SysYParser::NOT:
      case SysYParser::L_PAREN:
      case SysYParser::IDENT:
      case SysYParser::INTEGER_CONST:
      case SysYParser::FLOAT_CONST: {
        enterOuterAlt(_localctx, 1);
        setState(93);
        constExp();
        break;
      }

      case SysYParser::L_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(94);
        match(SysYParser::L_BRACE);

        setState(103);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 120603023360) != 0)) {
          setState(95);
          constInitVal();
          setState(100);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SysYParser::COMMA) {
            setState(96);
            match(SysYParser::COMMA);
            setState(97);
            constInitVal();
            setState(102);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(105);
        match(SysYParser::R_BRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

SysYParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::VarDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::VarDefContext *> SysYParser::VarDeclContext::varDef() {
  return getRuleContexts<SysYParser::VarDefContext>();
}

SysYParser::VarDefContext* SysYParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<SysYParser::VarDefContext>(i);
}

tree::TerminalNode* SysYParser::VarDeclContext::SEMICOLON() {
  return getToken(SysYParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> SysYParser::VarDeclContext::COMMA() {
  return getTokens(SysYParser::COMMA);
}

tree::TerminalNode* SysYParser::VarDeclContext::COMMA(size_t i) {
  return getToken(SysYParser::COMMA, i);
}


size_t SysYParser::VarDeclContext::getRuleIndex() const {
  return SysYParser::RuleVarDecl;
}

void SysYParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void SysYParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any SysYParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDeclContext* SysYParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, SysYParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    bType();
    setState(109);
    varDef();
    setState(114);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::COMMA) {
      setState(110);
      match(SysYParser::COMMA);
      setState(111);
      varDef();
      setState(116);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(117);
    match(SysYParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

SysYParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::VarDefContext::IDENT() {
  return getToken(SysYParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> SysYParser::VarDefContext::L_BRACKT() {
  return getTokens(SysYParser::L_BRACKT);
}

tree::TerminalNode* SysYParser::VarDefContext::L_BRACKT(size_t i) {
  return getToken(SysYParser::L_BRACKT, i);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::VarDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::VarDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::VarDefContext::R_BRACKT() {
  return getTokens(SysYParser::R_BRACKT);
}

tree::TerminalNode* SysYParser::VarDefContext::R_BRACKT(size_t i) {
  return getToken(SysYParser::R_BRACKT, i);
}

tree::TerminalNode* SysYParser::VarDefContext::ASSIGN() {
  return getToken(SysYParser::ASSIGN, 0);
}

SysYParser::InitValContext* SysYParser::VarDefContext::initVal() {
  return getRuleContext<SysYParser::InitValContext>(0);
}


size_t SysYParser::VarDefContext::getRuleIndex() const {
  return SysYParser::RuleVarDef;
}

void SysYParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void SysYParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}


std::any SysYParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDefContext* SysYParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 16, SysYParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(SysYParser::IDENT);
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::L_BRACKT) {
      setState(120);
      match(SysYParser::L_BRACKT);
      setState(121);
      constExp();
      setState(122);
      match(SysYParser::R_BRACKT);
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(131);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::ASSIGN) {
      setState(129);
      match(SysYParser::ASSIGN);
      setState(130);
      initVal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitValContext ------------------------------------------------------------------

SysYParser::InitValContext::InitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::InitValContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

tree::TerminalNode* SysYParser::InitValContext::L_BRACE() {
  return getToken(SysYParser::L_BRACE, 0);
}

tree::TerminalNode* SysYParser::InitValContext::R_BRACE() {
  return getToken(SysYParser::R_BRACE, 0);
}

std::vector<SysYParser::InitValContext *> SysYParser::InitValContext::initVal() {
  return getRuleContexts<SysYParser::InitValContext>();
}

SysYParser::InitValContext* SysYParser::InitValContext::initVal(size_t i) {
  return getRuleContext<SysYParser::InitValContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::InitValContext::COMMA() {
  return getTokens(SysYParser::COMMA);
}

tree::TerminalNode* SysYParser::InitValContext::COMMA(size_t i) {
  return getToken(SysYParser::COMMA, i);
}


size_t SysYParser::InitValContext::getRuleIndex() const {
  return SysYParser::RuleInitVal;
}

void SysYParser::InitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitVal(this);
}

void SysYParser::InitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitVal(this);
}


std::any SysYParser::InitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitInitVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::InitValContext* SysYParser::initVal() {
  InitValContext *_localctx = _tracker.createInstance<InitValContext>(_ctx, getState());
  enterRule(_localctx, 18, SysYParser::RuleInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::PLUS:
      case SysYParser::MINUS:
      case SysYParser::NOT:
      case SysYParser::L_PAREN:
      case SysYParser::IDENT:
      case SysYParser::INTEGER_CONST:
      case SysYParser::FLOAT_CONST: {
        enterOuterAlt(_localctx, 1);
        setState(133);
        exp(0);
        break;
      }

      case SysYParser::L_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(134);
        match(SysYParser::L_BRACE);
        setState(143);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 120603023360) != 0)) {
          setState(135);
          initVal();
          setState(140);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SysYParser::COMMA) {
            setState(136);
            match(SysYParser::COMMA);
            setState(137);
            initVal();
            setState(142);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(145);
        match(SysYParser::R_BRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

SysYParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::FuncTypeContext* SysYParser::FuncDefContext::funcType() {
  return getRuleContext<SysYParser::FuncTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncDefContext::IDENT() {
  return getToken(SysYParser::IDENT, 0);
}

tree::TerminalNode* SysYParser::FuncDefContext::L_PAREN() {
  return getToken(SysYParser::L_PAREN, 0);
}

tree::TerminalNode* SysYParser::FuncDefContext::R_PAREN() {
  return getToken(SysYParser::R_PAREN, 0);
}

SysYParser::BlockContext* SysYParser::FuncDefContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::FuncFParamsContext* SysYParser::FuncDefContext::funcFParams() {
  return getRuleContext<SysYParser::FuncFParamsContext>(0);
}


size_t SysYParser::FuncDefContext::getRuleIndex() const {
  return SysYParser::RuleFuncDef;
}

void SysYParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void SysYParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}


std::any SysYParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncDefContext* SysYParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 20, SysYParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    funcType();
    setState(149);
    match(SysYParser::IDENT);
    setState(150);
    match(SysYParser::L_PAREN);
    setState(152);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::INT

    || _la == SysYParser::FLOAT) {
      setState(151);
      funcFParams();
    }
    setState(154);
    match(SysYParser::R_PAREN);
    setState(155);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

SysYParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::FuncTypeContext::VOID() {
  return getToken(SysYParser::VOID, 0);
}

tree::TerminalNode* SysYParser::FuncTypeContext::INT() {
  return getToken(SysYParser::INT, 0);
}

tree::TerminalNode* SysYParser::FuncTypeContext::FLOAT() {
  return getToken(SysYParser::FLOAT, 0);
}


size_t SysYParser::FuncTypeContext::getRuleIndex() const {
  return SysYParser::RuleFuncType;
}

void SysYParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void SysYParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}


std::any SysYParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncTypeContext* SysYParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 22, SysYParser::RuleFuncType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 28) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

SysYParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncFParamContext *> SysYParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<SysYParser::FuncFParamContext>();
}

SysYParser::FuncFParamContext* SysYParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<SysYParser::FuncFParamContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFParamsContext::COMMA() {
  return getTokens(SysYParser::COMMA);
}

tree::TerminalNode* SysYParser::FuncFParamsContext::COMMA(size_t i) {
  return getToken(SysYParser::COMMA, i);
}


size_t SysYParser::FuncFParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParams;
}

void SysYParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void SysYParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}


std::any SysYParser::FuncFParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitFuncFParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFParamsContext* SysYParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 24, SysYParser::RuleFuncFParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    funcFParam();
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::COMMA) {
      setState(160);
      match(SysYParser::COMMA);
      setState(161);
      funcFParam();
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

SysYParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::FuncFParamContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncFParamContext::IDENT() {
  return getToken(SysYParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFParamContext::L_BRACKT() {
  return getTokens(SysYParser::L_BRACKT);
}

tree::TerminalNode* SysYParser::FuncFParamContext::L_BRACKT(size_t i) {
  return getToken(SysYParser::L_BRACKT, i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFParamContext::R_BRACKT() {
  return getTokens(SysYParser::R_BRACKT);
}

tree::TerminalNode* SysYParser::FuncFParamContext::R_BRACKT(size_t i) {
  return getToken(SysYParser::R_BRACKT, i);
}

std::vector<SysYParser::ExpContext *> SysYParser::FuncFParamContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::FuncFParamContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}


size_t SysYParser::FuncFParamContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParam;
}

void SysYParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void SysYParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}


std::any SysYParser::FuncFParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitFuncFParam(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFParamContext* SysYParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 26, SysYParser::RuleFuncFParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    bType();
    setState(168);
    match(SysYParser::IDENT);
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::L_BRACKT) {
      setState(169);
      match(SysYParser::L_BRACKT);
      setState(170);
      match(SysYParser::R_BRACKT);
      setState(177);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SysYParser::L_BRACKT) {
        setState(171);
        match(SysYParser::L_BRACKT);
        setState(172);
        exp(0);
        setState(173);
        match(SysYParser::R_BRACKT);
        setState(179);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SysYParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::BlockContext::L_BRACE() {
  return getToken(SysYParser::L_BRACE, 0);
}

tree::TerminalNode* SysYParser::BlockContext::R_BRACE() {
  return getToken(SysYParser::R_BRACE, 0);
}

std::vector<SysYParser::BlockItemContext *> SysYParser::BlockContext::blockItem() {
  return getRuleContexts<SysYParser::BlockItemContext>();
}

SysYParser::BlockItemContext* SysYParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<SysYParser::BlockItemContext>(i);
}


size_t SysYParser::BlockContext::getRuleIndex() const {
  return SysYParser::RuleBlock;
}

void SysYParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void SysYParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any SysYParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockContext* SysYParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 28, SysYParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(SysYParser::L_BRACE);
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 129192959918) != 0)) {
      setState(183);
      blockItem();
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(189);
    match(SysYParser::R_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

SysYParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::DeclContext* SysYParser::BlockItemContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::StmtContext* SysYParser::BlockItemContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}


size_t SysYParser::BlockItemContext::getRuleIndex() const {
  return SysYParser::RuleBlockItem;
}

void SysYParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void SysYParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


std::any SysYParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockItemContext* SysYParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 30, SysYParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(193);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::CONST:
      case SysYParser::INT:
      case SysYParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(191);
        decl();
        break;
      }

      case SysYParser::IF:
      case SysYParser::WHILE:
      case SysYParser::BREAK:
      case SysYParser::CONTINUE:
      case SysYParser::RETURN:
      case SysYParser::PLUS:
      case SysYParser::MINUS:
      case SysYParser::NOT:
      case SysYParser::L_PAREN:
      case SysYParser::L_BRACE:
      case SysYParser::SEMICOLON:
      case SysYParser::IDENT:
      case SysYParser::INTEGER_CONST:
      case SysYParser::FLOAT_CONST: {
        enterOuterAlt(_localctx, 2);
        setState(192);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

SysYParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::StmtContext::getRuleIndex() const {
  return SysYParser::RuleStmt;
}

void SysYParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Stmt_with_expContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::Stmt_with_expContext::SEMICOLON() {
  return getToken(SysYParser::SEMICOLON, 0);
}

SysYParser::ExpContext* SysYParser::Stmt_with_expContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::Stmt_with_expContext::Stmt_with_expContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::Stmt_with_expContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_with_exp(this);
}
void SysYParser::Stmt_with_expContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_with_exp(this);
}

std::any SysYParser::Stmt_with_expContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitStmt_with_exp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stmt_with_continueContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::Stmt_with_continueContext::CONTINUE() {
  return getToken(SysYParser::CONTINUE, 0);
}

tree::TerminalNode* SysYParser::Stmt_with_continueContext::SEMICOLON() {
  return getToken(SysYParser::SEMICOLON, 0);
}

SysYParser::Stmt_with_continueContext::Stmt_with_continueContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::Stmt_with_continueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_with_continue(this);
}
void SysYParser::Stmt_with_continueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_with_continue(this);
}

std::any SysYParser::Stmt_with_continueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitStmt_with_continue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stmt_with_ifContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::Stmt_with_ifContext::IF() {
  return getToken(SysYParser::IF, 0);
}

tree::TerminalNode* SysYParser::Stmt_with_ifContext::L_PAREN() {
  return getToken(SysYParser::L_PAREN, 0);
}

SysYParser::CondContext* SysYParser::Stmt_with_ifContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

tree::TerminalNode* SysYParser::Stmt_with_ifContext::R_PAREN() {
  return getToken(SysYParser::R_PAREN, 0);
}

std::vector<SysYParser::StmtContext *> SysYParser::Stmt_with_ifContext::stmt() {
  return getRuleContexts<SysYParser::StmtContext>();
}

SysYParser::StmtContext* SysYParser::Stmt_with_ifContext::stmt(size_t i) {
  return getRuleContext<SysYParser::StmtContext>(i);
}

tree::TerminalNode* SysYParser::Stmt_with_ifContext::ELSE() {
  return getToken(SysYParser::ELSE, 0);
}

SysYParser::Stmt_with_ifContext::Stmt_with_ifContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::Stmt_with_ifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_with_if(this);
}
void SysYParser::Stmt_with_ifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_with_if(this);
}

std::any SysYParser::Stmt_with_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitStmt_with_if(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stmt_with_returnContext ------------------------------------------------------------------

SysYParser::ReturnStmtContext* SysYParser::Stmt_with_returnContext::returnStmt() {
  return getRuleContext<SysYParser::ReturnStmtContext>(0);
}

SysYParser::Stmt_with_returnContext::Stmt_with_returnContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::Stmt_with_returnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_with_return(this);
}
void SysYParser::Stmt_with_returnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_with_return(this);
}

std::any SysYParser::Stmt_with_returnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitStmt_with_return(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stmt_with_assignContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::Stmt_with_assignContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

tree::TerminalNode* SysYParser::Stmt_with_assignContext::ASSIGN() {
  return getToken(SysYParser::ASSIGN, 0);
}

SysYParser::ExpContext* SysYParser::Stmt_with_assignContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

tree::TerminalNode* SysYParser::Stmt_with_assignContext::SEMICOLON() {
  return getToken(SysYParser::SEMICOLON, 0);
}

SysYParser::Stmt_with_assignContext::Stmt_with_assignContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::Stmt_with_assignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_with_assign(this);
}
void SysYParser::Stmt_with_assignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_with_assign(this);
}

std::any SysYParser::Stmt_with_assignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitStmt_with_assign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stmt_with_whileContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::Stmt_with_whileContext::WHILE() {
  return getToken(SysYParser::WHILE, 0);
}

tree::TerminalNode* SysYParser::Stmt_with_whileContext::L_PAREN() {
  return getToken(SysYParser::L_PAREN, 0);
}

SysYParser::CondContext* SysYParser::Stmt_with_whileContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

tree::TerminalNode* SysYParser::Stmt_with_whileContext::R_PAREN() {
  return getToken(SysYParser::R_PAREN, 0);
}

SysYParser::StmtContext* SysYParser::Stmt_with_whileContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}

SysYParser::Stmt_with_whileContext::Stmt_with_whileContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::Stmt_with_whileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_with_while(this);
}
void SysYParser::Stmt_with_whileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_with_while(this);
}

std::any SysYParser::Stmt_with_whileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitStmt_with_while(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stmt_with_blockContext ------------------------------------------------------------------

SysYParser::BlockContext* SysYParser::Stmt_with_blockContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::Stmt_with_blockContext::Stmt_with_blockContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::Stmt_with_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_with_block(this);
}
void SysYParser::Stmt_with_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_with_block(this);
}

std::any SysYParser::Stmt_with_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitStmt_with_block(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stmt_with_breakContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::Stmt_with_breakContext::BREAK() {
  return getToken(SysYParser::BREAK, 0);
}

tree::TerminalNode* SysYParser::Stmt_with_breakContext::SEMICOLON() {
  return getToken(SysYParser::SEMICOLON, 0);
}

SysYParser::Stmt_with_breakContext::Stmt_with_breakContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::Stmt_with_breakContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_with_break(this);
}
void SysYParser::Stmt_with_breakContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_with_break(this);
}

std::any SysYParser::Stmt_with_breakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitStmt_with_break(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::StmtContext* SysYParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 32, SysYParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::Stmt_with_assignContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(195);
      lVal();
      setState(196);
      match(SysYParser::ASSIGN);
      setState(197);
      exp(0);
      setState(198);
      match(SysYParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::Stmt_with_expContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(201);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 120334587904) != 0)) {
        setState(200);
        exp(0);
      }
      setState(203);
      match(SysYParser::SEMICOLON);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SysYParser::Stmt_with_blockContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(204);
      block();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SysYParser::Stmt_with_ifContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(205);
      match(SysYParser::IF);
      setState(206);
      match(SysYParser::L_PAREN);
      setState(207);
      cond(0);
      setState(208);
      match(SysYParser::R_PAREN);
      setState(209);
      stmt();
      setState(212);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
      case 1: {
        setState(210);
        match(SysYParser::ELSE);
        setState(211);
        stmt();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SysYParser::Stmt_with_whileContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(214);
      match(SysYParser::WHILE);
      setState(215);
      match(SysYParser::L_PAREN);
      setState(216);
      cond(0);
      setState(217);
      match(SysYParser::R_PAREN);
      setState(218);
      stmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SysYParser::Stmt_with_breakContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(220);
      match(SysYParser::BREAK);
      setState(221);
      match(SysYParser::SEMICOLON);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SysYParser::Stmt_with_continueContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(222);
      match(SysYParser::CONTINUE);
      setState(223);
      match(SysYParser::SEMICOLON);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SysYParser::Stmt_with_returnContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(224);
      returnStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

SysYParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ReturnStmtContext::RETURN() {
  return getToken(SysYParser::RETURN, 0);
}

tree::TerminalNode* SysYParser::ReturnStmtContext::SEMICOLON() {
  return getToken(SysYParser::SEMICOLON, 0);
}

SysYParser::ExpContext* SysYParser::ReturnStmtContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}


size_t SysYParser::ReturnStmtContext::getRuleIndex() const {
  return SysYParser::RuleReturnStmt;
}

void SysYParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void SysYParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}


std::any SysYParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ReturnStmtContext* SysYParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, SysYParser::RuleReturnStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(SysYParser::RETURN);
    setState(229);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 120334587904) != 0)) {
      setState(228);
      exp(0);
    }
    setState(231);
    match(SysYParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

SysYParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::ExpContext::getRuleIndex() const {
  return SysYParser::RuleExp;
}

void SysYParser::ExpContext::copyFrom(ExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Exp_with_plus_and_miusContext ------------------------------------------------------------------

std::vector<SysYParser::ExpContext *> SysYParser::Exp_with_plus_and_miusContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::Exp_with_plus_and_miusContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}

tree::TerminalNode* SysYParser::Exp_with_plus_and_miusContext::PLUS() {
  return getToken(SysYParser::PLUS, 0);
}

tree::TerminalNode* SysYParser::Exp_with_plus_and_miusContext::MINUS() {
  return getToken(SysYParser::MINUS, 0);
}

SysYParser::Exp_with_plus_and_miusContext::Exp_with_plus_and_miusContext(ExpContext *ctx) { copyFrom(ctx); }

void SysYParser::Exp_with_plus_and_miusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp_with_plus_and_mius(this);
}
void SysYParser::Exp_with_plus_and_miusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp_with_plus_and_mius(this);
}

std::any SysYParser::Exp_with_plus_and_miusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitExp_with_plus_and_mius(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Exp_with_unaryOpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext* SysYParser::Exp_with_unaryOpContext::unaryOp() {
  return getRuleContext<SysYParser::UnaryOpContext>(0);
}

SysYParser::ExpContext* SysYParser::Exp_with_unaryOpContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::Exp_with_unaryOpContext::Exp_with_unaryOpContext(ExpContext *ctx) { copyFrom(ctx); }

void SysYParser::Exp_with_unaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp_with_unaryOp(this);
}
void SysYParser::Exp_with_unaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp_with_unaryOp(this);
}

std::any SysYParser::Exp_with_unaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitExp_with_unaryOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Exp_with_symbolContext ------------------------------------------------------------------

std::vector<SysYParser::ExpContext *> SysYParser::Exp_with_symbolContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::Exp_with_symbolContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}

tree::TerminalNode* SysYParser::Exp_with_symbolContext::MUL() {
  return getToken(SysYParser::MUL, 0);
}

tree::TerminalNode* SysYParser::Exp_with_symbolContext::DIV() {
  return getToken(SysYParser::DIV, 0);
}

tree::TerminalNode* SysYParser::Exp_with_symbolContext::MOD() {
  return getToken(SysYParser::MOD, 0);
}

SysYParser::Exp_with_symbolContext::Exp_with_symbolContext(ExpContext *ctx) { copyFrom(ctx); }

void SysYParser::Exp_with_symbolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp_with_symbol(this);
}
void SysYParser::Exp_with_symbolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp_with_symbol(this);
}

std::any SysYParser::Exp_with_symbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitExp_with_symbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Exp_with_lvalContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::Exp_with_lvalContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::Exp_with_lvalContext::Exp_with_lvalContext(ExpContext *ctx) { copyFrom(ctx); }

void SysYParser::Exp_with_lvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp_with_lval(this);
}
void SysYParser::Exp_with_lvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp_with_lval(this);
}

std::any SysYParser::Exp_with_lvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitExp_with_lval(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Exp_with_ParenContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::Exp_with_ParenContext::L_PAREN() {
  return getToken(SysYParser::L_PAREN, 0);
}

SysYParser::ExpContext* SysYParser::Exp_with_ParenContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

tree::TerminalNode* SysYParser::Exp_with_ParenContext::R_PAREN() {
  return getToken(SysYParser::R_PAREN, 0);
}

SysYParser::Exp_with_ParenContext::Exp_with_ParenContext(ExpContext *ctx) { copyFrom(ctx); }

void SysYParser::Exp_with_ParenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp_with_Paren(this);
}
void SysYParser::Exp_with_ParenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp_with_Paren(this);
}

std::any SysYParser::Exp_with_ParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitExp_with_Paren(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Exp_with_numContext ------------------------------------------------------------------

SysYParser::NumberContext* SysYParser::Exp_with_numContext::number() {
  return getRuleContext<SysYParser::NumberContext>(0);
}

SysYParser::Exp_with_numContext::Exp_with_numContext(ExpContext *ctx) { copyFrom(ctx); }

void SysYParser::Exp_with_numContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp_with_num(this);
}
void SysYParser::Exp_with_numContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp_with_num(this);
}

std::any SysYParser::Exp_with_numContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitExp_with_num(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Exp_with_funcRParamsContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::Exp_with_funcRParamsContext::IDENT() {
  return getToken(SysYParser::IDENT, 0);
}

tree::TerminalNode* SysYParser::Exp_with_funcRParamsContext::L_PAREN() {
  return getToken(SysYParser::L_PAREN, 0);
}

tree::TerminalNode* SysYParser::Exp_with_funcRParamsContext::R_PAREN() {
  return getToken(SysYParser::R_PAREN, 0);
}

SysYParser::FuncRParamsContext* SysYParser::Exp_with_funcRParamsContext::funcRParams() {
  return getRuleContext<SysYParser::FuncRParamsContext>(0);
}

SysYParser::Exp_with_funcRParamsContext::Exp_with_funcRParamsContext(ExpContext *ctx) { copyFrom(ctx); }

void SysYParser::Exp_with_funcRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp_with_funcRParams(this);
}
void SysYParser::Exp_with_funcRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp_with_funcRParams(this);
}

std::any SysYParser::Exp_with_funcRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitExp_with_funcRParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ExpContext* SysYParser::exp() {
   return exp(0);
}

SysYParser::ExpContext* SysYParser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  SysYParser::ExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, SysYParser::RuleExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(249);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Exp_with_ParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(234);
      match(SysYParser::L_PAREN);
      setState(235);
      exp(0);
      setState(236);
      match(SysYParser::R_PAREN);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Exp_with_lvalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(238);
      lVal();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Exp_with_numContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(239);
      number();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Exp_with_funcRParamsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(240);
      match(SysYParser::IDENT);
      setState(241);
      match(SysYParser::L_PAREN);
      setState(243);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 120334587904) != 0)) {
        setState(242);
        funcRParams();
      }
      setState(245);
      match(SysYParser::R_PAREN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Exp_with_unaryOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(246);
      unaryOp();
      setState(247);
      exp(3);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(257);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Exp_with_symbolContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(251);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(252);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 57344) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(253);
          exp(3);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Exp_with_plus_and_miusContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(254);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(255);
          _la = _input->LA(1);
          if (!(_la == SysYParser::PLUS

          || _la == SysYParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(256);
          exp(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(261);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

SysYParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::CondContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

std::vector<SysYParser::CondContext *> SysYParser::CondContext::cond() {
  return getRuleContexts<SysYParser::CondContext>();
}

SysYParser::CondContext* SysYParser::CondContext::cond(size_t i) {
  return getRuleContext<SysYParser::CondContext>(i);
}

tree::TerminalNode* SysYParser::CondContext::LT() {
  return getToken(SysYParser::LT, 0);
}

tree::TerminalNode* SysYParser::CondContext::GT() {
  return getToken(SysYParser::GT, 0);
}

tree::TerminalNode* SysYParser::CondContext::LE() {
  return getToken(SysYParser::LE, 0);
}

tree::TerminalNode* SysYParser::CondContext::GE() {
  return getToken(SysYParser::GE, 0);
}

tree::TerminalNode* SysYParser::CondContext::EQ() {
  return getToken(SysYParser::EQ, 0);
}

tree::TerminalNode* SysYParser::CondContext::NEQ() {
  return getToken(SysYParser::NEQ, 0);
}

tree::TerminalNode* SysYParser::CondContext::AND() {
  return getToken(SysYParser::AND, 0);
}

tree::TerminalNode* SysYParser::CondContext::OR() {
  return getToken(SysYParser::OR, 0);
}


size_t SysYParser::CondContext::getRuleIndex() const {
  return SysYParser::RuleCond;
}

void SysYParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void SysYParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


std::any SysYParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}


SysYParser::CondContext* SysYParser::cond() {
   return cond(0);
}

SysYParser::CondContext* SysYParser::cond(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, parentState);
  SysYParser::CondContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, SysYParser::RuleCond, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(263);
    exp(0);
    _ctx->stop = _input->LT(-1);
    setState(279);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(277);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<CondContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleCond);
          setState(265);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(266);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 7864320) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(267);
          cond(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<CondContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleCond);
          setState(268);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(269);
          _la = _input->LA(1);
          if (!(_la == SysYParser::EQ

          || _la == SysYParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(270);
          cond(4);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<CondContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleCond);
          setState(271);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(272);
          match(SysYParser::AND);
          setState(273);
          cond(3);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<CondContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleCond);
          setState(274);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(275);
          match(SysYParser::OR);
          setState(276);
          cond(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(281);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

SysYParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::LValContext::IDENT() {
  return getToken(SysYParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> SysYParser::LValContext::L_BRACKT() {
  return getTokens(SysYParser::L_BRACKT);
}

tree::TerminalNode* SysYParser::LValContext::L_BRACKT(size_t i) {
  return getToken(SysYParser::L_BRACKT, i);
}

std::vector<SysYParser::ExpContext *> SysYParser::LValContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::LValContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::LValContext::R_BRACKT() {
  return getTokens(SysYParser::R_BRACKT);
}

tree::TerminalNode* SysYParser::LValContext::R_BRACKT(size_t i) {
  return getToken(SysYParser::R_BRACKT, i);
}


size_t SysYParser::LValContext::getRuleIndex() const {
  return SysYParser::RuleLVal;
}

void SysYParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void SysYParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}


std::any SysYParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LValContext* SysYParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 40, SysYParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(282);
    match(SysYParser::IDENT);
    setState(289);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(283);
        match(SysYParser::L_BRACKT);
        setState(284);
        exp(0);
        setState(285);
        match(SysYParser::R_BRACKT); 
      }
      setState(291);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

SysYParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::NumberContext::INTEGER_CONST() {
  return getToken(SysYParser::INTEGER_CONST, 0);
}

tree::TerminalNode* SysYParser::NumberContext::FLOAT_CONST() {
  return getToken(SysYParser::FLOAT_CONST, 0);
}


size_t SysYParser::NumberContext::getRuleIndex() const {
  return SysYParser::RuleNumber;
}

void SysYParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void SysYParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


std::any SysYParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::NumberContext* SysYParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 42, SysYParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    _la = _input->LA(1);
    if (!(_la == SysYParser::INTEGER_CONST

    || _la == SysYParser::FLOAT_CONST)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::UnaryOpContext::PLUS() {
  return getToken(SysYParser::PLUS, 0);
}

tree::TerminalNode* SysYParser::UnaryOpContext::MINUS() {
  return getToken(SysYParser::MINUS, 0);
}

tree::TerminalNode* SysYParser::UnaryOpContext::NOT() {
  return getToken(SysYParser::NOT, 0);
}


size_t SysYParser::UnaryOpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryOp;
}

void SysYParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void SysYParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}


std::any SysYParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::UnaryOpContext* SysYParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 44, SysYParser::RuleUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8394752) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

SysYParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::ParamContext *> SysYParser::FuncRParamsContext::param() {
  return getRuleContexts<SysYParser::ParamContext>();
}

SysYParser::ParamContext* SysYParser::FuncRParamsContext::param(size_t i) {
  return getRuleContext<SysYParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncRParamsContext::COMMA() {
  return getTokens(SysYParser::COMMA);
}

tree::TerminalNode* SysYParser::FuncRParamsContext::COMMA(size_t i) {
  return getToken(SysYParser::COMMA, i);
}


size_t SysYParser::FuncRParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncRParams;
}

void SysYParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void SysYParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}


std::any SysYParser::FuncRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitFuncRParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncRParamsContext* SysYParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 46, SysYParser::RuleFuncRParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    param();
    setState(301);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::COMMA) {
      setState(297);
      match(SysYParser::COMMA);
      setState(298);
      param();
      setState(303);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

SysYParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::ParamContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}


size_t SysYParser::ParamContext::getRuleIndex() const {
  return SysYParser::RuleParam;
}

void SysYParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void SysYParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}


std::any SysYParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ParamContext* SysYParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 48, SysYParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

SysYParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::ConstExpContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}


size_t SysYParser::ConstExpContext::getRuleIndex() const {
  return SysYParser::RuleConstExp;
}

void SysYParser::ConstExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExp(this);
}

void SysYParser::ConstExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExp(this);
}


std::any SysYParser::ConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYParserVisitor*>(visitor))
    return parserVisitor->visitConstExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstExpContext* SysYParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 50, SysYParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SysYParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 18: return expSempred(antlrcpp::downCast<ExpContext *>(context), predicateIndex);
    case 19: return condSempred(antlrcpp::downCast<CondContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SysYParser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::condSempred(CondContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void SysYParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  sysyparserParserInitialize();
#else
  ::antlr4::internal::call_once(sysyparserParserOnceFlag, sysyparserParserInitialize);
#endif
}
