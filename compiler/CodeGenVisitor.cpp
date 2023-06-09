#include <iostream>
#include "CodeGenVisitor.h"
#include "Name.h"

using namespace std;

unordered_map<string, Name> CodeGenVisitor::namesMap;
list<int> CodeGenVisitor::listIfStatment;
string argsRegisters[6] = {"%edi", "%esi", "%edx", "%ecx", "%r8d", "%r9d"};

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
        cout << "VarName not found " << varName << endl;
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
    string fonctionName = ctx->NAME(0)->getText();
    if (fonctionName == "main") {
        cout<< ".globl main\n" ;
    }
    cout<< fonctionName << ": \n" ;

    cout << "    # " << fonctionName <<" prologue\n";
    cout << "    pushq %rbp    # save %rbp on the stack\n";
    cout << "    movq %rsp, %rbp    # define %rbp for the current function\n";
    cout << "    subq $16, %rsp\n";

    // mise en memoire d'éventuels arguments
    for (int i = 1; i < 7; ++i) {

        if (ctx->NAME(i)) {
            string nomArgument = ctx->NAME(i)->getText();
            //createTmpVar(argsRegisters[i-1]);
            int sizeStack = namesMap.size();
            auto var = new Name(nomArgument, sizeStack, true);
            namesMap.insert(make_pair(nomArgument, *var));
            cout << "    movl "<<argsRegisters[i-1]<< ", " << getAssemblerFromVarName(nomArgument)<< "(%rbp)\n";
        } else {
            break;
        }
    }


    cout << "    # " << fonctionName <<" body\n";
    this->visitChildren(ctx);

    cout << "\n    # " << fonctionName <<" epilogue\n";
    cout << "    leave    # restore %rbp from the stack\n";

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

// NAME '=' expression ';' ;
antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx) {
    string varName = ctx->NAME()->getText();
    setVarInitializedTrue(varName);

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
    string exp0 = visit(ctx->expression(0)); //65
    string exp1 = visit(ctx->expression(1)); //91

    int assemblerPosExp0 = getAssemblerFromVarName(exp0);
    int assemblerPosExp1 = getAssemblerFromVarName(exp1);
    string op = ctx->children[1]->getText();
    cout << "    movl " << assemblerPosExp0 << "(%rbp), %eax\n";
    if(op == ">"){
        cout << "    cmpl    " <<  assemblerPosExp1 << "(%rbp), %eax\n";
        cout << "    setg    %al\n";
        cout << "    movzbl  %al, %eax\n";
    }else{
        cout << "    cmpl    " <<  assemblerPosExp1 << "(%rbp), %eax\n";
        cout << "    setl    %al\n";
        cout << "    movzbl  %al, %eax\n";
    }
    //cout << "BEFORE < > "<< endl;
    //cout << "0" <<endl;
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

antlrcpp::Any CodeGenVisitor::visitIf_else_stmt(ifccParser::If_else_stmtContext *ctx){
    visit(ctx->expression());

    string op = ctx->expression()->children[1]->getText();
    listIfStatment.push_back(listIfStatment.size());
    string then1 = "then" + to_string(listIfStatment.size());
    string else1 = "else" + to_string(listIfStatment.size());
    string endif1 = "endif" + to_string(listIfStatment.size());
    //cout << "." << then1 << "\n";
    int saveLabel = listIfStatment.size() +1;
    if(op == ">"){
        cout << "    jle .L" << saveLabel << "\n";
    }else if(op == "<"){
        cout << "    jge .L" << saveLabel << "\n";
    }else if(op == "==") {
        cout << "    jne .L" << saveLabel << "\n";
    }else if(op == "!=") {
        cout << "    je .L" << saveLabel << "\n";
    }
    visit(ctx->bloc(0));
    if(ctx->bloc(1)){
        //cout << "TESTTTT" << endl;
        //cout << ctx->bloc(1)->instruction(0) << endl;
        //ctx->c
        //cout <<  << endl;
        listIfStatment.push_back(listIfStatment.size());
        int saveLabel1 =  listIfStatment.size() +1;
        cout << "   jmp   .L" << saveLabel1 << "\n";
        cout << ".L" << saveLabel << ":\n";
        visit(ctx->bloc(1));
        cout << ".L" << saveLabel1 <<":\n";
        return 0;
    }
    cout << ".L" << saveLabel << ":\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitWhile_stmt(ifccParser::While_stmtContext *ctx){
    listIfStatment.push_back(listIfStatment.size());
    int saveLabel1 = listIfStatment.size() +1;
    //cout << "    jmp .L" << saveLabel1 << "\n";
    listIfStatment.push_back(listIfStatment.size());
    int saveLabel2 = listIfStatment.size() +1;
    cout << "jmp   .L"<<saveLabel1<<"\n";
    cout << ".L" << saveLabel2 << ":\n";
    visit(ctx->bloc());
    cout << ".L" << saveLabel1 << ":\n";
    visit(ctx->expression());
    cout << "    jl .L" << saveLabel2 << "\n";



    return 0;
}

// NAME '(' ')' #fctCallWithoutArgs
antlrcpp::Any CodeGenVisitor::visitFctCallWithoutArgs(ifccParser::FctCallWithoutArgsContext *ctx) {
    string functionName = ctx->NAME()->getText();
    cout << "    movl $0, %eax\n";
    cout << "    call " << functionName << "\n";
    return createTmpVar("%eax");
}

antlrcpp::Any CodeGenVisitor::visitFctCallWithArgs(ifccParser::FctCallWithArgsContext *ctx) {
    string argsNames[6];
    for (int i = 0; i < 6; ++i) {
        auto expression = ctx->expression(i);
        if (expression) {
            string varNameExpression = visit(expression);
            argsNames[i] = varNameExpression;
        }
    }

    for (int i = 5; i >= 0; --i) {
        auto expression = ctx->expression(i);
        if (expression) {

            cout << "    movl " << getAssemblerFromVarName(argsNames[i]) << "(%rbp), "
                 << argsRegisters[i] << "\n";
        }
    }

    string functionName = ctx->NAME()->getText();
    cout << "    call " << functionName << "\n";

    return createTmpVar("%eax");
}