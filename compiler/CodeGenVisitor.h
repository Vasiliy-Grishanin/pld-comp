#pragma once


#include <unordered_map>
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "Name.h"


class  CodeGenVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override ;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        // Déclaration/affectation
        virtual antlrcpp::Any visitDeclaration_simple(ifccParser::Declaration_simpleContext *ctx) override;
        virtual antlrcpp::Any visitDeclaration_affectation(ifccParser::Declaration_affectationContext *ctx) override;
        virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *ctx) override;
        // Expressions
        virtual antlrcpp::Any visitMoinsUnaire(ifccParser::MoinsUnaireContext *ctx) override;

        virtual antlrcpp::Any visitConstExpr(ifccParser::ConstExprContext *ctx) override;
        virtual antlrcpp::Any visitVarExpr(ifccParser::VarExprContext *ctx) override;

        virtual antlrcpp::Any visitParentheses(ifccParser::ParenthesesContext *ctx) override;

        virtual antlrcpp::Any visitAdd_sub(ifccParser::Add_subContext *ctx) override;
        virtual antlrcpp::Any visitMult_div(ifccParser::Mult_divContext *ctx) override;

        virtual antlrcpp::Any visitInverse(ifccParser::InverseContext *ctx) override;

        virtual antlrcpp::Any visitSupp_inf_strict(ifccParser::Supp_inf_strictContext *ctx) override;
        static std::unordered_map<std::string, Name> namesMap;
};

