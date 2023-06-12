
// Generated from ifcc.g4 by ANTLR 4.7.2


#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;
using namespace antlr4;

ifccParser::ifccParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ifccParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
}

tree::TerminalNode* ifccParser::AxiomContext::EOF() {
  return getToken(ifccParser::EOF, 0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}

antlrcpp::Any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    prog();
    setState(13);
    match(ifccParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Return_stmtContext* ifccParser::ProgContext::return_stmt() {
  return getRuleContext<ifccParser::Return_stmtContext>(0);
}

std::vector<ifccParser::InstructionContext *> ifccParser::ProgContext::instruction() {
  return getRuleContexts<ifccParser::InstructionContext>();
}

ifccParser::InstructionContext* ifccParser::ProgContext::instruction(size_t i) {
  return getRuleContext<ifccParser::InstructionContext>(i);
}


size_t ifccParser::ProgContext::getRuleIndex() const {
  return ifccParser::RuleProg;
}

antlrcpp::Any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(15);
    match(ifccParser::T__0);
    setState(16);
    match(ifccParser::T__1);
    setState(17);
    match(ifccParser::T__2);
    setState(18);
    match(ifccParser::T__3);
    setState(19);
    match(ifccParser::T__4);
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__0

    || _la == ifccParser::NAME) {
      setState(20);
      instruction();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(26);
    return_stmt();
    setState(27);
    match(ifccParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

ifccParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::DeclarationContext* ifccParser::InstructionContext::declaration() {
  return getRuleContext<ifccParser::DeclarationContext>(0);
}

ifccParser::AffectationContext* ifccParser::InstructionContext::affectation() {
  return getRuleContext<ifccParser::AffectationContext>(0);
}


size_t ifccParser::InstructionContext::getRuleIndex() const {
  return ifccParser::RuleInstruction;
}

antlrcpp::Any ifccParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::InstructionContext* ifccParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(31);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(29);
        declaration();
        break;
      }

      case ifccParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(30);
        affectation();
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

//----------------- DeclarationContext ------------------------------------------------------------------

ifccParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::DeclarationContext::getRuleIndex() const {
  return ifccParser::RuleDeclaration;
}

void ifccParser::DeclarationContext::copyFrom(DeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Declaration_affectationContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> ifccParser::Declaration_affectationContext::NAME() {
  return getTokens(ifccParser::NAME);
}

tree::TerminalNode* ifccParser::Declaration_affectationContext::NAME(size_t i) {
  return getToken(ifccParser::NAME, i);
}

tree::TerminalNode* ifccParser::Declaration_affectationContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::Declaration_affectationContext::Declaration_affectationContext(DeclarationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::Declaration_affectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclaration_affectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Declaration_simpleContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::Declaration_simpleContext::NAME() {
  return getToken(ifccParser::NAME, 0);
}

ifccParser::Declaration_simpleContext::Declaration_simpleContext(DeclarationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::Declaration_simpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclaration_simple(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::DeclarationContext* ifccParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(41);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<ifccParser::Declaration_simpleContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(33);
      match(ifccParser::T__0);
      setState(34);
      match(ifccParser::NAME);
      setState(35);
      match(ifccParser::T__6);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<ifccParser::Declaration_affectationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(36);
      match(ifccParser::T__0);
      setState(37);
      match(ifccParser::NAME);
      setState(38);
      match(ifccParser::T__7);
      setState(39);
      _la = _input->LA(1);
      if (!(_la == ifccParser::CONST

      || _la == ifccParser::NAME)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(40);
      match(ifccParser::T__6);
      break;
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

//----------------- AffectationContext ------------------------------------------------------------------

ifccParser::AffectationContext::AffectationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ifccParser::AffectationContext::NAME() {
  return getTokens(ifccParser::NAME);
}

tree::TerminalNode* ifccParser::AffectationContext::NAME(size_t i) {
  return getToken(ifccParser::NAME, i);
}

tree::TerminalNode* ifccParser::AffectationContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}


size_t ifccParser::AffectationContext::getRuleIndex() const {
  return ifccParser::RuleAffectation;
}

antlrcpp::Any ifccParser::AffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AffectationContext* ifccParser::affectation() {
  AffectationContext *_localctx = _tracker.createInstance<AffectationContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleAffectation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(ifccParser::NAME);
    setState(44);
    match(ifccParser::T__7);
    setState(45);
    _la = _input->LA(1);
    if (!(_la == ifccParser::CONST

    || _la == ifccParser::NAME)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(46);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

ifccParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::Return_stmtContext::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

tree::TerminalNode* ifccParser::Return_stmtContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

tree::TerminalNode* ifccParser::Return_stmtContext::NAME() {
  return getToken(ifccParser::NAME, 0);
}


size_t ifccParser::Return_stmtContext::getRuleIndex() const {
  return ifccParser::RuleReturn_stmt;
}

antlrcpp::Any ifccParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Return_stmtContext* ifccParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleReturn_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(ifccParser::RETURN);
    setState(49);
    _la = _input->LA(1);
    if (!(_la == ifccParser::CONST

    || _la == ifccParser::NAME)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(50);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "prog", "instruction", "declaration", "affectation", "return_stmt"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "';'", "'='", "'return'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "RETURN", "CONST", "NAME", "COMMENT", 
  "DIRECTIVE", "WS"
};

dfa::Vocabulary ifccParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ifccParser::_tokenNames;

ifccParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x10, 0x37, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x18, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1b, 0xb, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x22, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x2c, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x2, 0x2, 0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 0x3, 0x3, 0x2, 
    0xc, 0xd, 0x2, 0x33, 0x2, 0xe, 0x3, 0x2, 0x2, 0x2, 0x4, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x21, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x32, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 
    0x5, 0x4, 0x3, 0x2, 0xf, 0x10, 0x7, 0x2, 0x2, 0x3, 0x10, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x11, 0x12, 0x7, 0x3, 0x2, 0x2, 0x12, 0x13, 0x7, 0x4, 0x2, 
    0x2, 0x13, 0x14, 0x7, 0x5, 0x2, 0x2, 0x14, 0x15, 0x7, 0x6, 0x2, 0x2, 
    0x15, 0x19, 0x7, 0x7, 0x2, 0x2, 0x16, 0x18, 0x5, 0x6, 0x4, 0x2, 0x17, 
    0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1c, 0x3, 
    0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x5, 0xc, 
    0x7, 0x2, 0x1d, 0x1e, 0x7, 0x8, 0x2, 0x2, 0x1e, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x1f, 0x22, 0x5, 0x8, 0x5, 0x2, 0x20, 0x22, 0x5, 0xa, 0x6, 0x2, 
    0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0x3, 0x2, 0x2, 0x24, 0x25, 
    0x7, 0xd, 0x2, 0x2, 0x25, 0x2c, 0x7, 0x9, 0x2, 0x2, 0x26, 0x27, 0x7, 
    0x3, 0x2, 0x2, 0x27, 0x28, 0x7, 0xd, 0x2, 0x2, 0x28, 0x29, 0x7, 0xa, 
    0x2, 0x2, 0x29, 0x2a, 0x9, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x7, 0x9, 0x2, 
    0x2, 0x2b, 0x23, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x26, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0xd, 0x2, 0x2, 0x2e, 
    0x2f, 0x7, 0xa, 0x2, 0x2, 0x2f, 0x30, 0x9, 0x2, 0x2, 0x2, 0x30, 0x31, 
    0x7, 0x9, 0x2, 0x2, 0x31, 0xb, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x7, 
    0xb, 0x2, 0x2, 0x33, 0x34, 0x9, 0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 0x9, 
    0x2, 0x2, 0x35, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5, 0x19, 0x21, 0x2b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ifccParser::Initializer ifccParser::_init;
