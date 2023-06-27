#include <iostream>
#include "FirstPassVisitor.h"
#include "Name.h"

using namespace std;

list<string> FirstPassVisitor::fonctionNames;

antlrcpp::Any FirstPassVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    string fonctionName = ctx->NAME()->getText();
    auto it = std::find(fonctionNames.begin(), fonctionNames.end(), fonctionName);
    if (it != fonctionNames.end()) {
        // la fonction a déjà été declarée
        exit(8);
    }
    // tout va bien, on insère le nom de la fonction dans la liste
    fonctionNames.push_back(fonctionName);

    return 0;
}

void FirstPassVisitor::checkMain() {
    auto it = std::find(fonctionNames.begin(), fonctionNames.end(), "main");
    if (it == fonctionNames.end()) {
        // il n'y a pas de fonction main
        exit(9);
    }
}
