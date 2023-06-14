#include <iostream>
#include "CodeGenVisitor.h"
#include "Name.h"

std::unordered_map<std::string, Name> CodeGenVisitor::namesMap;

int positionToAssembler (int position) {
    return (position+1)*(-4);
}

int getPosition (std::string varName) {
    auto it = CodeGenVisitor::namesMap.find(varName);
    if (it != CodeGenVisitor::namesMap.end()) {
        return it->second.getPosition();
    } else {
        // variable varName non définie
        exit (5);
    }
}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    std::cout<< ".globl main\n" ;
    std::cout<< " main: \n" ;

    std::cout << "    # prologue\n";
    std::cout << "    pushq %rbp    # save %rbp on the stack\n";
    std::cout << "    movq %rsp, %rbp    # define %rbp for the current function\n";

    std::cout << "    # body\n";
    this->visitChildren(ctx);

    std::cout << "\n    # epilogue\n";
    std::cout << "    popq %rbp    # restore %rbp from the stack\n";

    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    if (ctx->CONST()) {
        int retval = stoi(ctx->CONST()->getText());
        std::cout << "    movl $"<<retval<<", %eax\n" ;
    } else if (ctx->NAME()) {
        int varPosition = getPosition(ctx->NAME()->getText());
        std::cout << "    movl "<<positionToAssembler(varPosition)<<"(%rbp), %eax\n" ;
    } else {
        exit(7);
    }



    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_simple(ifccParser::Declaration_simpleContext *ctx) {
    std::string varName = ctx->NAME()->getText();
    if (namesMap.count(varName) > 0) {
        // La variable a déjà été déclarée
        exit(2);
    }
    namesMap.insert(std::make_pair(varName, Name(varName, namesMap.size())));
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_affectation(ifccParser::Declaration_affectationContext *ctx) {
    std::string varName = ctx->NAME(0)->getText();
    int varNameCount = namesMap.count(varName);
    if (varNameCount > 0) {
        // La variable a déjà été déclarée
        exit(4);
    }
    int namesCount = namesMap.size();
    auto var = new Name(varName, namesCount);
    namesMap.insert(std::make_pair(varName, Name(varName, namesMap.size())));
    if(ctx->CONST()) {
        int varVal = stoi(ctx->CONST()->getText());

        std::cout << "    movl $"<<varVal<<", " << positionToAssembler(namesCount) <<"(%rbp)\n" ;
    } else if (ctx->NAME(1)) {
        std::string otherVar = ctx->NAME(1)->getText();
        int otherVarPosition = getPosition(otherVar);

        std::cout << "    movl " << positionToAssembler(otherVarPosition) <<"(%rbp), %eax\n" ;
        std::cout << "    movl %eax, "<<positionToAssembler(namesCount)<<"(%rbp)\n" ;
    } else {
        // erreur dans la grammaire. Ni CONST ni NAME(1) n'est défini
        exit(3);
    }
    return 0;
}
// NAME '=' (CONST | NAME) ';' ;
antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx) {
    std::string varName = ctx->NAME(0)->getText();
    int varPosition = getPosition(varName);
    auto it = namesMap.find(varName);
    if (ctx->NAME(1)) {
        std::string otherVar = ctx->NAME(1)->getText();
        int otherVarPosition = getPosition(otherVar);
        std::cout << "    movl " << positionToAssembler(otherVarPosition) <<"(%rbp), %eax\n" ;
        std::cout << "    movl %eax, "<<positionToAssembler(varPosition)<<"(%rbp)\n" ;

    } else if (ctx->CONST()) {
        std::string constValue = ctx->CONST()->getText();
        std::cout << "    movl $" << constValue << ", "<<positionToAssembler(varPosition)<<"(%rbp)\n" ;
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
