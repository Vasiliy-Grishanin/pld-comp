# Pentanôme N°2 : Gharib, Grishanin, Luvison, Soucasse, Voilliot

# Projet Compilateur C

Ce PLD est un compilateur pour un sous-ensemble du langage C, écrit en 
C++ en utilisant ANTLR4. 

## Organisation du Projet

Le projet est organisé en deux dossiers principaux : `compilier` et 
`tests`.

### Compiler

Ce dossier contient le code du compilateur. Il comprend les fichiers 
suivants :

- `FirstPassVisitor.cpp` et `FirstPassVisitor.h` : Ces fichiers contiennent la 
classe `FirstPassVisitor` qui fait une première passe pour vérifier l'**absence de doublons dans les noms de fonctions**, ainsi que la **présence d'une fonction 'main'**.
- `CodeGenVisitor.cpp` et `CodeGenVisitor.h` : Ces fichiers contiennent la 
classe `CodeGenVisitor` qui gère la **génération de code**.
- `Name.cpp` et `Name.h` : Ces fichiers contiennent la 
classe `Name` qui permet de stocker le nom d'une variable, son état (initialisée ou non) et sa position dans la table des symboles.
- `ifcc.g4` : Ce fichier contient la grammaire du langage utilisé par le 
compilateur.
- `main.cpp` : Ce fichier contient le point d'entrée du compilateur.

### Tests

Ce dossier contient les tests du compilateur. Il comprend le fichier 
`ifcc-test.py` pour exécuter les tests et un sous-dossier `testfiles` qui 
contient les fichiers de test individuels. Voici la représentation de la hiérarchie du dossier `testfiles` :
.
├── EgalDiffSimple.c
├── IfImbrique.c
├── IfSimple.c
├── InferieurStrictSimple.c
├── Integration
│   ├── alphabet.c
│   ├── ifElseImbrique.c
│   ├── ifElseImbrique2.c
│   └── ifElseImbrique3.c
├── InverseSimple.c
├── InverseSimpleBis.c
├── OperatorAndOr.c
├── OperatorBitOr.c
├── OperatorXorBit.c
├── WhileSimple.c
├── invalid
│   ├── arithmetics
│   │   ├── arith_identifier.c
│   │   ├── assign_to_num.c
│   │   ├── div_zero.c
│   │   ├── func_multiply.c
│   │   ├── invalid_operation.c
│   │   ├── keyword_id.c
│   │   ├── string_mult.c
│   │   └── undeclared_var_mutli.c
│   ├── basic
│   │   ├── forget_semicolon.c
│   │   ├── invalid_variable_assignment.c
│   │   ├── invalid_variable_assignment2.c
│   │   ├── missing_main.c
│   │   ├── multiple_return.c
│   │   ├── undeclared_variable.c
│   │   └── variable_redeclaration.c
│   ├── bitwise
│   │   └── invalid_bitwise.c
│   └── conditional
│       ├── assign_instead_compare.c
│       ├── assign_instead_compare_while.C
│       ├── syntax_error_if.c
│       ├── undeclared_var.c
│       └── undeclared_var_while.c
├── test.c
└── valid
    ├── arithmetics
    │   ├── addition_division.c
    │   ├── addition_subtraction_priority.c
    │   ├── difficult_test.c
    │   ├── difficult_test_p.c
    │   ├── multiple_div.c
    │   ├── multiple_express.c
    │   ├── multiplication.c
    │   ├── simple_addition.c
    │   ├── substraction_simple.c
    │   └── subtraction_and_multiplication.c
    ├── basic
    │   ├── comment.c
    │   ├── comment2.c
    │   └── bitwise_xor.c
    ├── conditional
    │   ├── nested_if_else.c
    │   ├── simple_if_else.c
    │   └── simple_while.c
    ├── expressions
    │   ├── test_comparaison_simple.c
    │   └── test_comparison.c
    └── functions
        └── sixArgsDefAndCall.c



## Fonctionnalités prises en charge



### Types

Que ce soit pour les types de fonctions ou les types de variables, le seul type pris en charge est **int**.

### Opérations arithmétiques
Le compilateur prend en charge les opérations arithmétiques telles que **l'addition**, la **soustraction**, la **multiplication** et la **division**. Il y a également **l'inverse**, le **moins unaire** et le **parenthésage**.

### Opérations logiques
Vous pouvez comparer 2 constantes ou 2 variables ou une constante et une variable avec les opérateurs suivants : **<**, **>**, **==**, **!=**

### Opérations bit à bit
Le compilateur prend en charge les opérations bit à bit, telles que l'**ET logique**, le **OU logique** et le **OU exclusif**.

### Assignation de variables
Vous pouvez assigner des valeurs à des variables dans votre code source. Le compilateur prend en charge les assignations de variables simples. Avec c**ontrôle de doublon** de variable et **utilisation d'une variable non initialisée** ou **non déclarée**. Cependant, les **virgules ne sont pas prises en charge** dans les déclarations.
Il y a également **qu'une seule table des symboles**. Donc le compilateur **ne prend pas en charge le scope** ou le **shadowing**.

### Création de fonctions
Le compilateur vous permet de **créer des fonctions personnalisées**. Vous pouvez définir des fonctions **jusqu'à 6 arguments** et des instructions à exécuter.
Le compilateur se chargera également de faire une **première passe** pour **vérifier l'absence de doublons** dans les noms de fonctions et la **présence d'une fonction 'main'**.

### Appel de fonctions
Vous pouvez **appeler des fonctions** que vous avez **définies dans votre code source** ou bien des **fonctions définies de base en C** comme *getchar* ou *putchar*. Les paramètres peuvent être passés aux fonctions **(6 paramètres max)** et vous **pouvez utiliser les valeurs retournées**.

### Structure de contrôle "if-then-else"
Vous pouvez utiliser la structure de contrôle "if-then-else" pour effectuer des actions conditionnelles dans votre code source. N'oubliez pas d'**utiliser des crochets pour délimiter les blocs de code**.

### Boucle "while"
Le compilateur prend en charge la boucle "while" qui permet de répéter un bloc de code tant que la condition est vraie. Comme pour le if, **les crochets sont également obligatoires.**




## Fonctionnalités Non Prises en Charge et Bugs Résolus

- **Non pris en charge** : Le `while` ne fonctionne pas dans certains cas 
où la variable dans la condition est décrémentée. 
- **Bug résolu** : Pour l'appel de fonction, il était auparavant 
obligatoire d'avoir une affectation, par exemple `int a = putchar('a')`. 
Ce bug a été corrigé et maintenant, **aucune affectation n'est requise pour** 
**appeler une fonction**.
- **Bug résolu** : Le programme présenté en **démo pour afficher l'alphabet** 
**fonctionne** maintenant. Vous pouvez le trouver dans le fichier 
`tests/testfiles/Integration/alphabet.c`.



## Compilation et Exécution

Pour compiler et exécuter le compilateur, utilisez les commandes suivantes en vous trouvant dans le dossier *compiler* :

```shell
make
./ifcc your_file.c
```



## Tests

Pour exécuter les tests, utilisez la commande suivante toujours en étant dans le dossier *compiler* :

```shell
make test
```

Les fichiers de test sont situés dans le dossier `testfiles`. Ils 
contiennent des exemples de programmes écrits dans le sous-ensemble du 
langage C pris en charge ou non par le compilateur.
