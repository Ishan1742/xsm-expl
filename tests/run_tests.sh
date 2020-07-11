#!/bin/bash

set -e

cd ..
cd src/

cd parser
yacc -d parser.y
cd ..

cd lexer
lex lexer.l
cd ..

gcc parser/y.tab.c lexer/lex.yy.c util/*.c -o compiler

cd label
lex label.l
gcc lex.yy.c -o label
cd ..

for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19; do
    echo -e test$i
    ./compiler ../tests/test$i.expl >> test.log
    cd label
    ./label >> ../test.log
    cd ..
    cat test.log > ../tests/test$i.log
    rm test.log
    if diff test.o ../tests/test$i.o >/dev/null ; then
        echo -e "Success."
    else
        echo -e "Failed."
        diff test.o ../tests/test$i.o
    fi
    echo ""
done