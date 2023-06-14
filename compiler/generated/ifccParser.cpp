
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
    setState(16);
    prog();
    setState(17);
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
    setState(19);
    match(ifccParser::T__0);
    setState(20);
    match(ifccParser::T__1);
    setState(21);
    match(ifccParser::T__2);
    setState(22);
    match(ifccParser::T__3);
    setState(23);
    match(ifccParser::T__4);
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__0)
      | (1ULL << ifccParser::T__2)
      | (1ULL << ifccParser::CONST)
      | (1ULL << ifccParser::NAME))) != 0)) {
      setState(24);
      instruction();
      setState(29);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(30);
    return_stmt();
    setState(31);
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

ifccParser::ExpressionStmtContext* ifccParser::InstructionContext::expressionStmt() {
  return getRuleContext<ifccParser::ExpressionStmtContext>(0);
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
    setState(36);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(33);
      declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(34);
      affectation();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(35);
      expressionStmt();
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

tree::TerminalNode* ifccParser::Declaration_affectationContext::NAME() {
  return getToken(ifccParser::NAME, 0);
}

ifccParser::ExpressionContext* ifccParser::Declaration_affectationContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<ifccParser::Declaration_simpleContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(38);
      match(ifccParser::T__0);
      setState(39);
      match(ifccParser::NAME);
      setState(40);
      match(ifccParser::T__6);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<ifccParser::Declaration_affectationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(41);
      match(ifccParser::T__0);
      setState(42);
      match(ifccParser::NAME);
      setState(43);
      match(ifccParser::T__7);
      setState(44);
      expression(0);
      setState(45);
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

tree::TerminalNode* ifccParser::AffectationContext::NAME() {
  return getToken(ifccParser::NAME, 0);
}

ifccParser::ExpressionContext* ifccParser::AffectationContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(ifccParser::NAME);
    setState(50);
    match(ifccParser::T__7);
    setState(51);
    expression(0);
    setState(52);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStmtContext ------------------------------------------------------------------

ifccParser::ExpressionStmtContext::ExpressionStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ExpressionContext* ifccParser::ExpressionStmtContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}


size_t ifccParser::ExpressionStmtContext::getRuleIndex() const {
  return ifccParser::RuleExpressionStmt;
}

antlrcpp::Any ifccParser::ExpressionStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExpressionStmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExpressionStmtContext* ifccParser::expressionStmt() {
  ExpressionStmtContext *_localctx = _tracker.createInstance<ExpressionStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleExpressionStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    expression(0);
    setState(55);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ifccParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::ExpressionContext::getRuleIndex() const {
  return ifccParser::RuleExpression;
}

void ifccParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DivisionContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::DivisionContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::DivisionContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::DivisionContext::DivisionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::DivisionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDivision(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesesContext ------------------------------------------------------------------

ifccParser::ExpressionContext* ifccParser::ParenthesesContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::ParenthesesContext::ParenthesesContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::ParenthesesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitParentheses(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarExprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::VarExprContext::NAME() {
  return getToken(ifccParser::NAME, 0);
}

ifccParser::VarExprContext::VarExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::VarExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVarExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubtractionContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::SubtractionContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::SubtractionContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::SubtractionContext::SubtractionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::SubtractionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitSubtraction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicationContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::MultiplicationContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::MultiplicationContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::MultiplicationContext::MultiplicationContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::MultiplicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMultiplication(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstExprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ConstExprContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ConstExprContext::ConstExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::ConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitConstExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditionContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::AdditionContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::AdditionContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::AdditionContext::AdditionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::AdditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAddition(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExpressionContext* ifccParser::expression() {
   return expression(0);
}

ifccParser::ExpressionContext* ifccParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ifccParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  ifccParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, ifccParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(64);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__2: {
        _localctx = _tracker.createInstance<ParenthesesContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(58);
        match(ifccParser::T__2);
        setState(59);
        expression(0);
        setState(60);
        match(ifccParser::T__3);
        break;
      }

      case ifccParser::CONST: {
        _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(62);
        match(ifccParser::CONST);
        break;
      }

      case ifccParser::NAME: {
        _localctx = _tracker.createInstance<VarExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(63);
        match(ifccParser::NAME);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(80);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(78);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(66);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(67);
          match(ifccParser::T__8);
          setState(68);
          expression(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivisionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(69);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(70);
          match(ifccParser::T__9);
          setState(71);
          expression(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AdditionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(72);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(73);
          match(ifccParser::T__10);
          setState(74);
          expression(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<SubtractionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(75);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(76);
          match(ifccParser::T__11);
          setState(77);
          expression(5);
          break;
        }

        } 
      }
      setState(82);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
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

ifccParser::ExpressionContext* ifccParser::Return_stmtContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
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
  enterRule(_localctx, 14, ifccParser::RuleReturn_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(ifccParser::RETURN);
    setState(84);
    expression(0);
    setState(85);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ifccParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "prog", "instruction", "declaration", "affectation", "expressionStmt", 
  "expression", "return_stmt"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "';'", "'='", "'*'", 
  "'/'", "'+'", "'-'", "'return'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "RETURN", "CONST", 
  "NAME", "COMMENT", "DIRECTIVE", "WS"
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
    0x3, 0x14, 0x5a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x1c, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1f, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x27, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x32, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x43, 0xa, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x51, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0x54, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x2, 0x3, 0xe, 0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x2, 0x2, 0x2, 0x5b, 0x2, 0x12, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x6, 0x26, 0x3, 0x2, 0x2, 0x2, 0x8, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x33, 0x3, 0x2, 0x2, 0x2, 0xc, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x42, 0x3, 0x2, 0x2, 0x2, 0x10, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x13, 0x5, 0x4, 0x3, 0x2, 0x13, 0x14, 0x7, 0x2, 0x2, 0x3, 
    0x14, 0x3, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 0x3, 0x2, 0x2, 0x16, 
    0x17, 0x7, 0x4, 0x2, 0x2, 0x17, 0x18, 0x7, 0x5, 0x2, 0x2, 0x18, 0x19, 
    0x7, 0x6, 0x2, 0x2, 0x19, 0x1d, 0x7, 0x7, 0x2, 0x2, 0x1a, 0x1c, 0x5, 
    0x6, 0x4, 0x2, 0x1b, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x20, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x21, 0x5, 0x10, 0x9, 0x2, 0x21, 0x22, 0x7, 0x8, 0x2, 0x2, 0x22, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x23, 0x27, 0x5, 0x8, 0x5, 0x2, 0x24, 0x27, 
    0x5, 0xa, 0x6, 0x2, 0x25, 0x27, 0x5, 0xc, 0x7, 0x2, 0x26, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x7, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x3, 0x2, 
    0x2, 0x29, 0x2a, 0x7, 0x11, 0x2, 0x2, 0x2a, 0x32, 0x7, 0x9, 0x2, 0x2, 
    0x2b, 0x2c, 0x7, 0x3, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x11, 0x2, 0x2, 0x2d, 
    0x2e, 0x7, 0xa, 0x2, 0x2, 0x2e, 0x2f, 0x5, 0xe, 0x8, 0x2, 0x2f, 0x30, 
    0x7, 0x9, 0x2, 0x2, 0x30, 0x32, 0x3, 0x2, 0x2, 0x2, 0x31, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x32, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x34, 0x7, 0x11, 0x2, 0x2, 0x34, 0x35, 0x7, 0xa, 0x2, 
    0x2, 0x35, 0x36, 0x5, 0xe, 0x8, 0x2, 0x36, 0x37, 0x7, 0x9, 0x2, 0x2, 
    0x37, 0xb, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x5, 0xe, 0x8, 0x2, 0x39, 
    0x3a, 0x7, 0x9, 0x2, 0x2, 0x3a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 
    0x8, 0x8, 0x1, 0x2, 0x3c, 0x3d, 0x7, 0x5, 0x2, 0x2, 0x3d, 0x3e, 0x5, 
    0xe, 0x8, 0x2, 0x3e, 0x3f, 0x7, 0x6, 0x2, 0x2, 0x3f, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x43, 0x7, 0x10, 0x2, 0x2, 0x41, 0x43, 0x7, 0x11, 0x2, 
    0x2, 0x42, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x52, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x45, 0xc, 0x9, 0x2, 0x2, 0x45, 0x46, 0x7, 0xb, 0x2, 0x2, 0x46, 0x51, 
    0x5, 0xe, 0x8, 0xa, 0x47, 0x48, 0xc, 0x8, 0x2, 0x2, 0x48, 0x49, 0x7, 
    0xc, 0x2, 0x2, 0x49, 0x51, 0x5, 0xe, 0x8, 0x9, 0x4a, 0x4b, 0xc, 0x7, 
    0x2, 0x2, 0x4b, 0x4c, 0x7, 0xd, 0x2, 0x2, 0x4c, 0x51, 0x5, 0xe, 0x8, 
    0x8, 0x4d, 0x4e, 0xc, 0x6, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0xe, 0x2, 0x2, 
    0x4f, 0x51, 0x5, 0xe, 0x8, 0x7, 0x50, 0x44, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0xf, 0x2, 
    0x2, 0x56, 0x57, 0x5, 0xe, 0x8, 0x2, 0x57, 0x58, 0x7, 0x9, 0x2, 0x2, 
    0x58, 0x11, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1d, 0x26, 0x31, 0x42, 0x50, 0x52, 
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
