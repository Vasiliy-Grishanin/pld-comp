#pragma once


#include <unordered_map>
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "Name.h"


class  CodeGenVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override ;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        virtual antlrcpp::Any visitDeclaration_simple(ifccParser::Declaration_simpleContext *ctx) override;
        virtual antlrcpp::Any visitDeclaration_affectation(ifccParser::Declaration_affectationContext *ctx) override;
        virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *ctx) override;

        static std::unordered_map<std::string, Name> namesMap;
};

