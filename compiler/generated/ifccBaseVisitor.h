
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccVisitor.h"


/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ifccBaseVisitor : public ifccVisitor {
public:

  virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstruction(ifccParser::InstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration_simple(ifccParser::Declaration_simpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration_affectation(ifccParser::Declaration_affectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStmt(ifccParser::ExpressionStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDivision(ifccParser::DivisionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParentheses(ifccParser::ParenthesesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarExpr(ifccParser::VarExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubtraction(ifccParser::SubtractionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplication(ifccParser::MultiplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstExpr(ifccParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddition(ifccParser::AdditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }


};

