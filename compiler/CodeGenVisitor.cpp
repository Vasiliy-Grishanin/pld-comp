#include <iostream>
#include "CodeGenVisitor.h"
#include "Name.h"

using namespace std;

unordered_map<string, Name> CodeGenVisitor::namesMap;

// Utils
int mapPosToAssembler (int position) {
    return (position+1)*(-4);
}

int getMapPos (string varName) {
    auto it = CodeGenVisitor::namesMap.find(varName);
    if (it != CodeGenVisitor::namesMap.end()) {
        return it->second.getPosition();
    } else {
        // variable varName non définie
        exit(5);
    }
}

int getAssemblerFromVarName (string varName) {
    int position = getMapPos(varName);
    return mapPosToAssembler(position);
}

string createTmpVar(int value) {
    int sizeStack = CodeGenVisitor::namesMap.size();
    string varName = "tmp" + to_string(sizeStack);
    CodeGenVisitor::namesMap.insert(make_pair(varName, Name(varName, sizeStack)));
    cout << "    movl $" << value << ", " << mapPosToAssembler(sizeStack) << "(%rbp)\n";
    return varName;
}

string createTmpVar(string registre) {
    int sizeStack = CodeGenVisitor::namesMap.size();
    string varName = "tmp" + to_string(sizeStack);
    CodeGenVisitor::namesMap.insert(make_pair
                                            (varName, Name(varName, sizeStack)));
    cout << "    movl " << registre << ", " << mapPosToAssembler(sizeStack) << "(%rbp)\n";
    return varName;
}

// Visiteurs

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    cout<< ".globl main\n" ;
    cout<< " main: \n" ;

    cout << "    # prologue\n";
    cout << "    pushq %rbp    # save %rbp on the stack\n";
    cout << "    movq %rsp, %rbp    # define %rbp for the current function\n";

    cout << "    # body\n";
    this->visitChildren(ctx);

    cout << "\n    # epilogue\n";
    cout << "    popq %rbp    # restore %rbp from the stack\n";

    cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    string returnVar = visit(ctx->expression());
    int assemblerPos = getAssemblerFromVarName(returnVar);
    cout << "    movl "<<assemblerPos<<"(%rbp), %eax\n" ;

    return returnVar;
}

// int NAME;
antlrcpp::Any CodeGenVisitor::visitDeclaration_simple(ifccParser::Declaration_simpleContext *ctx) {
    string varName = ctx->NAME()->getText();
    if (namesMap.count(varName) > 0) {
        // La variable a déjà été déclarée
        exit(2);
    }
    namesMap.insert(make_pair(varName, Name(varName, namesMap.size())));
    return varName;
}

// int NAME '=' expression ';' ;
antlrcpp::Any CodeGenVisitor::visitDeclaration_affectation(ifccParser::Declaration_affectationContext *ctx) {
    string varName = ctx->NAME()->getText();
    string expressionName = visit(ctx->expression());
    int assemblerPosExpr = getAssemblerFromVarName(expressionName);

    int varNameCount = namesMap.count(varName);
    if (varNameCount > 0) {
        // La variable a déjà été déclarée
        exit(4);
    }
    int sizeStack = namesMap.size();
    auto var = new Name(varName, sizeStack);
    namesMap.insert(make_pair(varName, *var));

    int assemblerPosVar = getAssemblerFromVarName(varName);

    cout << "    movl " << assemblerPosExpr << "(%rbp), %eax\n";
    cout << "    movl %eax, " << mapPosToAssembler(sizeStack) << "(%rbp)\n";

    return varName;
}

// NAME '=' expression ';' ;
antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx) {
    string varName = ctx->NAME()->getText();
    string expressionName = visit(ctx->expression());
    int assemblerPosExpr = getAssemblerFromVarName(expressionName);
    int assemblerPosVar = getAssemblerFromVarName(varName);

    cout << "    movl " << assemblerPosExpr << "(%rbp), %eax\n";
    cout << "    movl %eax, " << assemblerPosVar <<"(%rbp)\n";

    return varName;
}

antlrcpp::Any CodeGenVisitor::visitParentheses(ifccParser::ParenthesesContext *ctx){
    return visit(ctx->expression());
}

antlrcpp::Any CodeGenVisitor::visitConstExpr(ifccParser::ConstExprContext *ctx) {
    int constValue = stoi(ctx->CONST()->getText());

    string varName = createTmpVar(constValue);

    return varName;
}

antlrcpp::Any CodeGenVisitor::visitVarExpr(ifccParser::VarExprContext *ctx){
    return ctx->NAME()->getText();
}

antlrcpp::Any CodeGenVisitor::visitAddition(ifccParser::AdditionContext *ctx) {
    string exp0 = visit(ctx->expression(0));
    string exp1 = visit(ctx->expression(1));

    int assemblerPosExp0 = getAssemblerFromVarName(exp0);
    int assemblerPosExp1 = getAssemblerFromVarName(exp1);

    cout << "    movl " << assemblerPosExp0 << "(%rbp), %eax\n";
    //cout << "    movl " << assemblerPosExp1 << "(%rbp), %eax\n";
    cout << "    addl " <<assemblerPosExp1<<  "(%rbp), %eax\n";

    string resultVar = createTmpVar("%eax");

    return resultVar;
}

antlrcpp::Any CodeGenVisitor::visitSubtraction(ifccParser::SubtractionContext *ctx) {
    string expr1 = visit(ctx->expression(0));
    string expr2 = visit(ctx->expression(1));
    //cout << "expr1 " << expr1 << endl;
    //cout << "expr2 " << expr2 << endl;
    int assemblerPosExpr = getAssemblerFromVarName(expr1);
    //cout << "assembler 1 " << assemblerPosExpr << endl;
    int assemblerPosExpr2 = getAssemblerFromVarName(expr2);
    //cout << "assembler 2 " << assemblerPosExpr2 << endl;

    cout << "    movl " << assemblerPosExpr << "(%rbp), %eax\n";
    //cout << "    movl " << assemblerPosExpr2 << "(%rbp), %eax\n";
    cout << "    subl " <<assemblerPosExpr2<<  "(%rbp), %eax\n";

    string resultVar = createTmpVar("%eax");

    return resultVar;
}