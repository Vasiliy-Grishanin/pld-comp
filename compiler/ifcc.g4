grammar ifcc;

axiom : prog* EOF ;

prog : 'int' NAME '(' ')' bloc
    | 'int' NAME '(' 'int' NAME (',' 'int' NAME)*  ')' bloc
;

instruction: declaration | affectation | if_else_stmt | return_stmt | (expression ';') | while_stmt;

bloc : '{' instruction* '}';

declaration:
    'int' NAME ';' #declaration_simple
    |'int' NAME '=' expression ';' #declaration_affectation;

affectation: NAME '=' expression ';' ;

if_else_stmt: 'if' '(' expression ')' bloc ('else' bloc)? ;

while_stmt: 'while' '(' expression ')' bloc ;

expression:
    '!' expression                  #inverse
    |  '-' expression             #moinsUnaire
    | NAME '(' ')' #fctCallWithoutArgs
    | NAME '(' expression (',' expression)* ')' #fctCallWithArgs
    | '(' expression ')'         #parentheses
    | expression ('*' | '/') expression  #mult_div
    | expression ('+' | '-') expression  #add_sub
    | expression ('<' | '>') expression #supp_inf_strict
    | expression ('!=' | '==') expression #egal_diff
    | expression ('|' | '&' | '^') expression #operation_bit
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

