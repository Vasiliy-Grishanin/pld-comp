#pragma once


#include <unordered_map>
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "Name.h"
#include <list>


class  CodeGenVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override ;
        virtual antlrcpp::Any visitBloc(ifccParser::BlocContext *ctx) override;
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

        //Opérations arithmétiques
        virtual antlrcpp::Any visitAdd_sub(ifccParser::Add_subContext *ctx) override;
        virtual antlrcpp::Any visitMult_div(ifccParser::Mult_divContext *ctx) override;

        //Comparaisons
        virtual antlrcpp::Any visitInverse(ifccParser::InverseContext *ctx) override;
        virtual antlrcpp::Any visitSupp_inf_strict(ifccParser::Supp_inf_strictContext *ctx) override;
        virtual antlrcpp::Any visitEgal_diff(ifccParser::Egal_diffContext *ctx) override;
        virtual antlrcpp::Any visitIf_else_stmt(ifccParser::If_else_stmtContext *ctx) override;
        virtual antlrcpp::Any visitWhile_stmt(ifccParser::While_stmtContext *ctx) override;

        //Bit à bit
        virtual antlrcpp::Any visitOperation_bit(ifccParser::Operation_bitContext *ctx) override;

        //function call
        virtual antlrcpp::Any visitFctCallWithoutArgs(ifccParser::FctCallWithoutArgsContext *ctx) override;
        virtual antlrcpp::Any visitFctCallWithArgs(ifccParser::FctCallWithArgsContext *ctx) override;
        static std::unordered_map<std::string, Name> namesMap;
        static std::list<int> listIfStatment;
};