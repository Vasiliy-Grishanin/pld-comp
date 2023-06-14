
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ifccVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */
    virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(ifccParser::InstructionContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration_simple(ifccParser::Declaration_simpleContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration_affectation(ifccParser::Declaration_affectationContext *context) = 0;

    virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStmt(ifccParser::ExpressionStmtContext *context) = 0;

    virtual antlrcpp::Any visitDivision(ifccParser::DivisionContext *context) = 0;

    virtual antlrcpp::Any visitParentheses(ifccParser::ParenthesesContext *context) = 0;

    virtual antlrcpp::Any visitVarExpr(ifccParser::VarExprContext *context) = 0;

    virtual antlrcpp::Any visitSubtraction(ifccParser::SubtractionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplication(ifccParser::MultiplicationContext *context) = 0;

    virtual antlrcpp::Any visitConstExpr(ifccParser::ConstExprContext *context) = 0;

    virtual antlrcpp::Any visitAddition(ifccParser::AdditionContext *context) = 0;

    virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *context) = 0;


};

