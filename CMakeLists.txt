cmake_minimum_required(VERSION 3.23)
project(pld_comp)

set(CMAKE_CXX_STANDARD 14)

include_directories(compiler)
include_directories(compiler/generated)

add_executable(pld_comp
        compiler/build/CodeGenVisitor.d
        compiler/build/CodeGenVisitor.o
        compiler/build/ifccBaseListener.class
        compiler/build/ifccBaseVisitor.d
        compiler/build/ifccBaseVisitor.o
        compiler/build/ifccLexer.class
        compiler/build/ifccLexer.d
        compiler/build/ifccLexer.o
        compiler/build/ifccListener.class
        compiler/build/ifccParser\$AxiomContext.class
        compiler/build/ifccParser\$ProgContext.class
        compiler/build/ifccParser\$Return_stmtContext.class
        compiler/build/ifccParser.class
        compiler/build/ifccParser.d
        compiler/build/ifccParser.o
        compiler/build/ifccVisitor.d
        compiler/build/ifccVisitor.o
        compiler/build/main.d
        compiler/build/main.o
        compiler/generated/ifccBaseVisitor.cpp
        compiler/generated/ifccBaseVisitor.h
        compiler/generated/ifccLexer.cpp
        compiler/generated/ifccLexer.h
        compiler/generated/ifccParser.cpp
        compiler/generated/ifccParser.h
        compiler/generated/ifccVisitor.cpp
        compiler/generated/ifccVisitor.h
        compiler/inputs/ret42.c
        compiler/inputs/ret42aff.c
        compiler/CodeGenVisitor.cpp
        compiler/CodeGenVisitor.h
        compiler/ifcc
        compiler/ifcc.g4
        compiler/main.cpp
        compiler/Makefile
        compiler/Name.cpp
        compiler/Name.h compiler/inputs/test.c compiler/inputs/IfSimple.c tests/testfiles/IfImbrique.c compiler/inputs/WhileSimple.c)
