#ifndef PLD_COMP_FIRSTPASSVISITOR_H
#define PLD_COMP_FIRSTPASSVISITOR_H

#pragma once

#include <list>
#include <string>
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"


class  FirstPassVisitor : public ifccBaseVisitor {
public:

    // méthodes réellement implémentées
    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    void checkMain();
    static std::list<std::string> fonctionNames;
};

#endif //PLD_COMP_FIRSTPASSVISITOR_H
