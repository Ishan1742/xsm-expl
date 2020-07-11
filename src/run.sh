set -e

# compile parser.y
cd parser
yacc -d parser.y
cd ..

# compile lexer.l
cd lexer
lex lexer.l
cd ..

# generate bin files
gcc -g parser/y.tab.c lexer/lex.yy.c util/*.c -o compiler

# generate code without label translation
./compiler $1

# compile lable.l
cd label
lex label.l
gcc lex.yy.c

# generate label translated code
# reads ../test.xsm
./a.out
rm a.out
cd ..
cd ..
if [ "$2" == "--compile" ]; then
    exit 1
fi

# run code normally or in debug mode
if [ "$2" == "--debug" ]; then
    ./xsm -l ./library.lib -e src/test.o --debug
else
    ./xsm -l ./library.lib -e src/test.o
fi