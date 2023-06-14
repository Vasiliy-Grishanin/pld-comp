# required packages (fedora 34): antlr4 and antlr4-cpp-runtime-devel
# make ANTLRJAR=/usr/share/java/antlr4/antlr4.jar:/usr/share/java/antlr3-runtime.jar:/usr/share/java/antlr4/antlr4-runtime.jar:/usr/share/java/stringtemplate4/ST4.jar:/usr/share/java/treelayout/org.abego.treelayout.core.jar ANTLRINC=/usr/include/antlr4-runtime ANTLRLIB=/usr/lib64/libantlr4-runtime.so "$@"

# ANTLRJAR=/usr/share/java/stringtemplate4.jar:/usr/share/java/antlr4.jar:/usr/share/java/antlr4-runtime.jar:/usr/share/java/antlr3-runtime.jar/:/usr/share/java/treelayout.jar
ANTLRINC=/usr/include/antlr4-runtime
ANTLRLIB=/usr/lib64/libantlr4-runtime.so
ANTLR=antlr4
ANTLRJAR=/usr/share/java/antlr4/antlr4.jar:/usr/share/java/antlr4/antlr4-runtime.jar:/home/antonin/Téléchargements/org.abego.treelayout.core-1.0.3.jar
