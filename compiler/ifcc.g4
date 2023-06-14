grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' instruction* return_stmt '}' ;

instruction: declaration | affectation | expressionStmt;

declaration:
    'int' NAME ';' #declaration_simple
    |'int' NAME '=' expression ';' #declaration_affectation;

affectation: NAME '=' expression ';' ;

expressionStmt: expression ';' ;

expression:
      expression '*' expression  #multiplication
    | expression '/' expression  #division
    | expression '+' expression  #addition
    | expression '-' expression  #subtraction
    | '(' expression ')'         #parentheses
    | CONST                      #constExpr
    | NAME                       #varExpr
    ;

return_stmt: 'return' expression ';' ;

RETURN : 'return' ;
CONST : [0-9]+ ;
NAME : '_'[A-Za-z][A-Za-z_0-9]* | [A-Za-z][A-Za-z_0-9]* ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
