#include <iostream>
#include "CodeGenVisitor.h"
#include "Name.h"

using namespace std;

unordered_map<string, Name> CodeGenVisitor::namesMap;

int positionToAssembler (int position) {
    return (position+1)*(-4);
}

int getPosition (string varName) {
    auto it = CodeGenVisitor::namesMap.find(varName);
    if (it != CodeGenVisitor::namesMap.end()) {
        return it->second.getPosition();
    } else {
        // variable varName non définie
        exit (5);
    }
}

int getAssemblerFromVarName (string varName) {
    int position = getPosition(varName);
    return positionToAssembler(position);
}

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

    return (antlrcpp::Any)returnVar;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_simple(ifccParser::Declaration_simpleContext *ctx) {
    string varName = ctx->NAME()->getText();
    if (namesMap.count(varName) > 0) {
        // La variable a déjà été déclarée
        exit(2);
    }
    namesMap.insert(make_pair(varName, Name(varName, namesMap.size())));
    return (antlrcpp::Any)varName;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_affectation(ifccParser::Declaration_affectationContext *ctx) {
    string returnVar = visit(ctx->expression());
    int assemblerPos = getAssemblerFromVarName(returnVar);
    int varNameCount = namesMap.count(returnVar);
    if (varNameCount > 0) {
        // La variable a déjà été déclarée
        exit(4);
    }
    int sizeStack = namesMap.size();
    auto var = new Name(returnVar, sizeStack);
    namesMap.insert(make_pair(returnVar, *var));
    //movl    -4(%rbp), %eax
    //movl    %eax, -8(%rbp)

    cout << "    movl " << assemblerPos<<"(%rbp), %eax\n";
    cout << "    movl " << positionToAssembler(var->getPosition())<<"(%rbp)\n";

    return (antlrcpp::Any)var->getName();
}
// NAME '=' (CONST | NAME) ';' ;
antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx) {
    string varName = ctx->NAME(0)->getText();
    int varPosition = getPosition(varName);
    auto it = namesMap.find(varName);
    if (ctx->NAME(1)) {
        string otherVar = ctx->NAME(1)->getText();
        int otherVarPosition = getPosition(otherVar);
        cout << "    movl " << positionToAssembler(otherVarPosition) <<"(%rbp), %eax\n" ;
        cout << "    movl %eax, "<<positionToAssembler(varPosition)<<"(%rbp)\n" ;

    } else if (ctx->CONST()) {
        string constValue = ctx->CONST()->getText();
        cout << "    movl $" << constValue << ", "<<positionToAssembler(varPosition)<<"(%rbp)\n" ;
    } else {
        // erreur dans la grammaire. NAME(1) n'est pas défini
        exit(6);
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAddition(ifccParser::AdditionContext *ctx) {
    visit(ctx->expression(0));
    std::cout << "    push %rax\n";  // sauvegarder la valeur de la première opérande
    visit(ctx->expression(1));
    std::cout << "    pop %rbx\n";   // récupérer la valeur de la première opérande
    std::cout << "    add %rbx, %rax\n";  // ajouter les deux opérandes
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitSubtraction(ifccParser::SubtractionContext *ctx) {
    visit(ctx->expression(0));
    cout << "    push %rax\n";  // sauvegarder la valeur de la première opérande
    visit(ctx->expression(1));
    cout << "    pop %rbx\n";   // récupérer la valeur de la première opérande
    cout << "    sub %rbx, %rax\n";  // soustraire la deuxième opérande de la première
    return 0;
}
