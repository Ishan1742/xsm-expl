/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    PLUS = 259,                    /* PLUS  */
    MINUS = 260,                   /* MINUS  */
    MUL = 261,                     /* MUL  */
    DIV = 262,                     /* DIV  */
    MOD = 263,                     /* MOD  */
    LT = 264,                      /* LT  */
    GT = 265,                      /* GT  */
    LE = 266,                      /* LE  */
    GE = 267,                      /* GE  */
    EQ = 268,                      /* EQ  */
    NE = 269,                      /* NE  */
    OR = 270,                      /* OR  */
    AND = 271,                     /* AND  */
    NOT = 272,                     /* NOT  */
    ID = 273,                      /* ID  */
    ASSIGN = 274,                  /* ASSIGN  */
    _BEGIN = 275,                  /* _BEGIN  */
    END = 276,                     /* END  */
    DECL = 277,                    /* DECL  */
    ENDDECL = 278,                 /* ENDDECL  */
    BRKP = 279,                    /* BRKP  */
    READ = 280,                    /* READ  */
    WRITE = 281,                   /* WRITE  */
    IF = 282,                      /* IF  */
    THEN = 283,                    /* THEN  */
    ELSE = 284,                    /* ELSE  */
    ENDIF = 285,                   /* ENDIF  */
    WHILE = 286,                   /* WHILE  */
    DO = 287,                      /* DO  */
    ENDWHILE = 288,                /* ENDWHILE  */
    BREAK = 289,                   /* BREAK  */
    CONTINUE = 290,                /* CONTINUE  */
    REPEAT = 291,                  /* REPEAT  */
    UNTIL = 292,                   /* UNTIL  */
    RETURN = 293,                  /* RETURN  */
    MAIN = 294,                    /* MAIN  */
    TYPE = 295,                    /* TYPE  */
    ENDTYPE = 296,                 /* ENDTYPE  */
    INITIALIZE = 297,              /* INITIALIZE  */
    ALLOC = 298,                   /* ALLOC  */
    FREE = 299,                    /* FREE  */
    _NULL = 300,                   /* _NULL  */
    CLASS = 301,                   /* CLASS  */
    ENDCLASS = 302,                /* ENDCLASS  */
    EXTENDS = 303,                 /* EXTENDS  */
    NEW = 304,                     /* NEW  */
    DELETE = 305,                  /* DELETE  */
    SELF = 306,                    /* SELF  */
    INT = 307,                     /* INT  */
    STR = 308,                     /* STR  */
    STRING = 309                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define LT 264
#define GT 265
#define LE 266
#define GE 267
#define EQ 268
#define NE 269
#define OR 270
#define AND 271
#define NOT 272
#define ID 273
#define ASSIGN 274
#define _BEGIN 275
#define END 276
#define DECL 277
#define ENDDECL 278
#define BRKP 279
#define READ 280
#define WRITE 281
#define IF 282
#define THEN 283
#define ELSE 284
#define ENDIF 285
#define WHILE 286
#define DO 287
#define ENDWHILE 288
#define BREAK 289
#define CONTINUE 290
#define REPEAT 291
#define UNTIL 292
#define RETURN 293
#define MAIN 294
#define TYPE 295
#define ENDTYPE 296
#define INITIALIZE 297
#define ALLOC 298
#define FREE 299
#define _NULL 300
#define CLASS 301
#define ENDCLASS 302
#define EXTENDS 303
#define NEW 304
#define DELETE 305
#define SELF 306
#define INT 307
#define STR 308
#define STRING 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "parser.y"

	struct ast_node *tree_node;

#line 178 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
