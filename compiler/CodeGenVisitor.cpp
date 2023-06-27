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
        if (it->second.isInitialized()) {
            return it->second.getPosition();
        } else {
            //TODO: Warning "Utilisation d'une variable non initialisée"
            exit(6);
        }
    } else {
        cout << "VarName " << varName << endl;
        // variable varName non définie
        exit(5);
    }
}

int getAssemblerFromVarName (string varName) {
    int position = getMapPos(varName);
    return mapPosToAssembler(position);
}

void setVarInitializedTrue (string varName) {
    auto it = CodeGenVisitor::namesMap.find(varName);
    if (it != CodeGenVisitor::namesMap.end()) {
        if (!it->second.isInitialized()) {
            it->second.setInitialized(true);
        }
    } else {
        // variable varName non définie
        exit(7);
    }
}

string createTmpVar(int value) {
    int sizeStack = CodeGenVisitor::namesMap.size();
    string varName = "tmp" + to_string(sizeStack);
    CodeGenVisitor::namesMap.insert(make_pair(varName, Name(varName, sizeStack, true)));
    cout << "    movl $" << value << ", " << mapPosToAssembler(sizeStack) << "(%rbp)\n";
    return varName;
}

string createTmpVar(string registre) {
    int sizeStack = CodeGenVisitor::namesMap.size();
    string varName = "tmp" + to_string(sizeStack);
    CodeGenVisitor::namesMap.insert(make_pair
                                            (varName, Name(varName, sizeStack, true)));
    cout << "    movl " << registre << ", " << mapPosToAssembler(sizeStack) << "(%rbp)\n";
    return varName;
}

// Visiteurs

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    cout<< ".globl main\n" ;
    string fonctionName = ctx->NAME()->getText();
    cout<< fonctionName << ": \n" ;

    cout << "    # " << fonctionName <<" prologue\n";
    cout << "    pushq %rbp    # save %rbp on the stack\n";
    cout << "    movq %rsp, %rbp    # define %rbp for the current function\n";

    cout << "    # " << fonctionName <<" body\n";
    this->visitChildren(ctx);

    cout << "\n    # " << fonctionName <<" epilogue\n";
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
    auto var = new Name(varName, sizeStack, true);
    namesMap.insert(make_pair(varName, *var));

    int assemblerPosVar = getAssemblerFromVarName(varName);

    cout << "    movl " << assemblerPosExpr << "(%rbp), %eax\n";
    cout << "    movl %eax, " << mapPosToAssembler(sizeStack) << "(%rbp)\n";

    return varName;
}

antlrcpp::Any CodeGenVisitor::visitFunction_call(ifccParser::Function_callContext *ctx) {
    //CAS APPL DE FUNCTION QUI RETOURNE RIEN int a = putchar(97)
    string functionName = ctx->NAME()->getText();
    string expressionName = visit(ctx->arguments());
    // cout << "expression name " << expressionName << endl;
    cout <<"    movl %eax, %edi\n";
    cout <<"    call "<< functionName << "\n";
    return createTmpVar("%eax");
}

antlrcpp::Any CodeGenVisitor::visitFunctionCallExpr(ifccParser::FunctionCallExprContext *ctx) {
    string resultFunctionCall = visit(ctx->function_call());
    return resultFunctionCall;
}

antlrcpp::Any CodeGenVisitor::visitArguments(ifccParser::ArgumentsContext *ctx) {
    return visit(ctx->expression(0));
}

// NAME '=' expression ';' ;
antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx) {
    if(ctx->children[1]->getText() == "="){
        string varName = ctx->NAME()->getText();
        setVarInitializedTrue(varName);

        string expressionName = visit(ctx->expression());
        int assemblerPosExpr = getAssemblerFromVarName(expressionName);
        int assemblerPosVar = getAssemblerFromVarName(varName);

        cout << "    movl " << assemblerPosExpr << "(%rbp), %eax\n";
        cout << "    movl %eax, " << assemblerPosVar <<"(%rbp)\n";

        return varName;
    }else{
        //CAS APPL DE FUNCTION QUI RETOURNE RIEN putchar(97)
        string functionName = ctx->NAME()->getText();
        string expressionName = visit(ctx->expression());
       // cout << "expression name " << expressionName << endl;
        cout <<"    movl %eax, %edi\n";
        cout <<"    call "<< functionName << "\n";
        return createTmpVar("%eax");
    }

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

antlrcpp::Any CodeGenVisitor::visitMoinsUnaire(ifccParser::MoinsUnaireContext *ctx) {
    string exp = visit(ctx->expression());
    int assemblerPosExp = getAssemblerFromVarName(exp);

    cout << "    movl " << assemblerPosExp << "(%rbp), %eax\n";
    cout << "    negl %eax\n";

    return createTmpVar("%eax");
}

antlrcpp::Any CodeGenVisitor::visitAdd_sub(ifccParser::Add_subContext *ctx) {
    string exp0 = visit(ctx->expression(0));
    string exp1 = visit(ctx->expression(1));

    int assemblerPosExp0 = getAssemblerFromVarName(exp0);
    int assemblerPosExp1 = getAssemblerFromVarName(exp1);

    cout << "    movl " << assemblerPosExp0 << "(%rbp), %eax\n";

    string op = ctx->children[1]->getText();
    if (op == "+") {
        cout << "    addl " <<assemblerPosExp1<<  "(%rbp), %eax\n";
    } else { // "-" soustraction
        cout << "    subl " <<assemblerPosExp1<<  "(%rbp), %eax\n";
    }

    return createTmpVar("%eax");
}

antlrcpp::Any CodeGenVisitor::visitInverse(ifccParser::InverseContext *ctx){
    string exp = visit(ctx->expression());
    //cout << "exp " << exp << endl;
    int assemblerPosExp = getAssemblerFromVarName(exp);
    cout << "    cmpl    $0, " <<  assemblerPosExp << "(%rbp)\n";
    cout << "    sete    %al\n";
    cout << "    movzbl  %al, %eax\n";
    cout << "    movl    %eax, " << assemblerPosExp << "(%rbp)\n";
    return exp;
}

antlrcpp::Any CodeGenVisitor::visitMult_div(ifccParser::Mult_divContext *ctx) {
    string exp0 = visit(ctx->expression(0));
    string exp1 = visit(ctx->expression(1));

    int assemblerPosExp0 = getAssemblerFromVarName(exp0);
    int assemblerPosExp1 = getAssemblerFromVarName(exp1);

    cout << "    movl " << assemblerPosExp0 << "(%rbp), %eax\n";
    string op = ctx->children[1]->getText();
    if (op == "*") {
        cout << "    imull " <<assemblerPosExp1<<  "(%rbp), %eax\n";
    } else { // "/" division
        cout << "    cltd\n";
        cout << "    idivl " <<assemblerPosExp1<<  "(%rbp)\n";
    }

    return createTmpVar("%eax");
}

antlrcpp::Any CodeGenVisitor::visitSupp_inf_strict(ifccParser::Supp_inf_strictContext *ctx){
    string exp0 = visit(ctx->expression(0));
    string exp1 = visit(ctx->expression(1));

    int assemblerPosExp0 = getAssemblerFromVarName(exp0);
    int assemblerPosExp1 = getAssemblerFromVarName(exp1);
    cout << "    movl " << assemblerPosExp0 << "(%rbp), %eax\n";
    string op = ctx->children[1]->getText();
    if(op == ">"){
        cout << "    cmpl    " <<  assemblerPosExp1 << "(%rbp), %eax\n";
        cout << "    setg    %al\n";
        cout << "    movzbl  %al, %eax\n";
    }else{
        cout << "    cmpl    " <<  assemblerPosExp1 << "(%rbp), %eax\n";
        cout << "    setl    %al\n";
        cout << "    movzbl  %al, %eax\n";
    }

    return createTmpVar("%eax");
}

antlrcpp::Any CodeGenVisitor::visitEgal_diff(ifccParser::Egal_diffContext *ctx){
    string exp0 = visit(ctx->expression(0));
    string exp1 = visit(ctx->expression(1));

    int assemblerPosExp0 = getAssemblerFromVarName(exp0);
    int assemblerPosExp1 = getAssemblerFromVarName(exp1);
    cout << "    movl " << assemblerPosExp0 << "(%rbp), %eax\n";
    string op = ctx->children[1]->getText();
    if(op == "!="){
        cout << "    cmpl    " <<  assemblerPosExp1 << "(%rbp), %eax\n";
        cout << "    setne    %al\n";
        cout << "    movzbl  %al, %eax\n";
    }else{
        cout << "    cmpl    " <<  assemblerPosExp1 << "(%rbp), %eax\n";
        cout << "    sete    %al\n";
        cout << "    movzbl  %al, %eax\n";
    }

    return createTmpVar("%eax");
}

antlrcpp::Any CodeGenVisitor::visitOperation_bit(ifccParser::Operation_bitContext *ctx){
    string exp0 = visit(ctx->expression(0));
    string exp1 = visit(ctx->expression(1));

    int assemblerPosExp0 = getAssemblerFromVarName(exp0);
    int assemblerPosExp1 = getAssemblerFromVarName(exp1);
    cout << "    movl " << assemblerPosExp0 << "(%rbp), %eax\n";
    string op = ctx->children[1]->getText();
    if(op == "|"){
        cout << "orl    " << assemblerPosExp1 <<"(%rbp), %eax\n";
    }
    else if(op == "&"){
        cout << "andl    " << assemblerPosExp1 <<"(%rbp), %eax\n";
    }else{
        cout << "xorl    " << assemblerPosExp1 <<"(%rbp), %eax\n";
    }
    return createTmpVar("%eax");
}

antlrcpp::Any CodeGenVisitor::visitBloc(ifccParser::BlocContext *ctx) {
    visitChildren(ctx);
    return 0;
}
