%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "../parser/y.tab.h"
	#include "../util/header.h"
%}

%option yylineno
%option noyywrap

%%

"type"					{return TYPE;}
"endtype"				{return ENDTYPE;}


"class"					{return CLASS;}
"endclass"				{return ENDCLASS;}

"extends"				{return EXTENDS;}
"self"					{return SELF;}
"new"					{return NEW;}
"delete"				{return DELETE;}

"initialize"			{return INITIALIZE;}
"alloc"					{return ALLOC;}
"free"					{return FREE;}
"null"					{return _NULL;}

"main"					{return MAIN;}
"decl"					{return DECL;}
"enddecl"				{return ENDDECL;}
"begin"					{return _BEGIN;}
"end"					{return END;}
"return"				{return RETURN;}

"read"					{return READ;}
"write"					{return WRITE;}
"breakpoint" 			{return BRKP;}

"if"					{return IF;}
"then"					{return THEN;}
"else"					{return ELSE;}
"endif"					{return ENDIF;}

"do"					{return DO;}
"while"					{return WHILE;}
"endwhile"				{return ENDWHILE;}
"repeat"				{return REPEAT;}
"until"					{return UNTIL;}

"break"					{return BREAK;}
"continue"				{return CONTINUE;}

"int"					{return INT;}
"str"					{return STR;}

[a-zA-Z_][_a-zA-Z0-9]*	{
							// variable names
							yylval.tree_node = create_ast_node(type_find("integer"),strdup(yytext),ID_NODE,NULL,NULL,NULL);
							return ID;
						}


[0-9]+ 					{
							// positive digits
							yylval.tree_node = create_ast_node(type_find("integer"),NULL,NUM_NODE,NULL,NULL,NULL);
							yylval.tree_node->constant.int_val = atoi(yytext);
							return NUM;
						}

\"(\\.|[^\\"])*\"		{
							// strings
							char *str=strdup(yytext+1);
							str[yyleng-2]='\0';
							yylval.tree_node = create_ast_node(type_find("string"),NULL,STR_NODE,NULL,NULL,NULL);
							yylval.tree_node->constant.str_val = str;
							return STRING;
						}

\/\/.*                  {;/*single line comment*/}

"="						{return ASSIGN;}
"+" 					{return PLUS;}
"-" 					{return MINUS;}
"*" 					{return MUL;}
"/" 					{return DIV;}
"%"						{return MOD;}
"<"						{return LT;}
">"						{return GT;}
"<="					{return LE;}
">="					{return GE;}
"!="					{return NE;}
"=="					{return EQ;}
"&&"					{return AND;}
"||"					{return OR;}
"!"						{return NOT;}

"["     				{return *yytext;}
"]"						{return *yytext;}
"{"                     {return *yytext;}
"}"                     {return *yytext;}
"("                     {return *yytext;}
")"                     {return *yytext;}
"&"                     {return *yytext;}
"."                     {return *yytext;}
","                     {return *yytext;}
":"                     {return *yytext;}
";"                     {return *yytext;}
\"                      {return *yytext;}

[\n \t] 				{;}

.						{
							printf("line: %d unknown character: %s\n", yylineno, yytext);
							exit(EXIT_FAILURE);
						}

%%