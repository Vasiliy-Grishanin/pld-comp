grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' block '}' ;

block : '{' instruction* return_stmt '}' ;

instruction: declaration | affectation | expression;

declaration:
    'int' NAME ';' #declaration_simple
    |'int' NAME '=' expression ';' #declaration_affectation;

affectation: NAME '=' expression ';' ;

expression:
    CONST                      #constExpr
    | NAME                       #varExpr
    ;

return_stmt: 'return' expression ';' ;

RETURN : 'return' ;
CONST : [0-9]+ ;
NAME : '_'[A-Za-z][A-Za-z_0-9]* | [A-Za-z][A-Za-z_0-9]* ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
