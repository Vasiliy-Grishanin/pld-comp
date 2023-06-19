grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' instruction* return_stmt '}' ;

instruction: declaration | affectation;

declaration:
    'int' NAME ';' #declaration_simple
    |'int' NAME '=' expression ';' #declaration_affectation;

affectation: NAME '=' expression ';' ;

expression:
      '-' expression             #moinsUnaire
    | expression '*' expression  #multiplication
    | expression '/' expression  #division
    | expression ('+' | '-') expression  #add_sub
    | '(' expression ')'         #parentheses
    | CONST                      #constExpr
    | NAME                       #varExpr
    ;

return_stmt: RETURN expression ';' ;

RETURN : 'return' ;
CONST : [0-9]+ ;
NAME : '_'[A-Za-z][A-Za-z_0-9]* | [A-Za-z][A-Za-z_0-9]* ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
