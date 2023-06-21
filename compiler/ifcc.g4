grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' instruction* return_stmt '}' ;

instruction: declaration | affectation;

declaration:
    'int' NAME ';' #declaration_simple
    |'int' NAME '=' expression ';' #declaration_affectation;

affectation: NAME '=' expression ';' ;

expression:
    '!' expression #inverse
    | '-' expression             #moinsUnaire
    | expression ('+' | '-') expression  #add_sub
    | '(' expression ')'         #parentheses
    | expression ('*' | '/') expression  #mult_div
    | CONST                      #constExpr
    | NAME                       #varExpr
    ;


return_stmt: RETURN expression ';' ;

RETURN : 'return' ;
CONST : [0-9]+ ;
NAME : '_'[A-Za-z][A-Za-z_0-9]* | [A-Za-z][A-Za-z_0-9]* ;
COMMENT : '/*' .*? '*/' -> skip ;
COMMENT_BLOC : '/*' .*? '*/' -> channel(HIDDEN) ;
COMMENT_BIS : '//' .*? '\n'-> skip;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);