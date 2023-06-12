grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' instruction* return_stmt '}' ;

instruction: declaration | affectation;

declaration:
    'int' NAME ';' #declaration_simple
    |'int' NAME '=' (CONST | NAME) ';' #declaration_affectation;
affectation: NAME '=' (CONST | NAME) ';' ;

return_stmt: RETURN (CONST | NAME) ';' ;

RETURN : 'return' ;
CONST : [0-9]+ ;
NAME : '_'[A-Za-z][A-Za-z_0-9]* | [A-Za-z][A-Za-z_0-9]* ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
