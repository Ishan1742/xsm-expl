/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include "parser_helper.c"

	extern int yylex(void);
	extern FILE *yyin;
	extern int yylineno;

#line 79 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 243 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_PLUS = 4,                       /* PLUS  */
  YYSYMBOL_MINUS = 5,                      /* MINUS  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_MOD = 8,                        /* MOD  */
  YYSYMBOL_LT = 9,                         /* LT  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_LE = 11,                        /* LE  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NE = 14,                        /* NE  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_ID = 18,                        /* ID  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL__BEGIN = 20,                    /* _BEGIN  */
  YYSYMBOL_END = 21,                       /* END  */
  YYSYMBOL_DECL = 22,                      /* DECL  */
  YYSYMBOL_ENDDECL = 23,                   /* ENDDECL  */
  YYSYMBOL_BRKP = 24,                      /* BRKP  */
  YYSYMBOL_READ = 25,                      /* READ  */
  YYSYMBOL_WRITE = 26,                     /* WRITE  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_THEN = 28,                      /* THEN  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_ENDIF = 30,                     /* ENDIF  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_DO = 32,                        /* DO  */
  YYSYMBOL_ENDWHILE = 33,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 34,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 36,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 37,                     /* UNTIL  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_MAIN = 39,                      /* MAIN  */
  YYSYMBOL_TYPE = 40,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 41,                   /* ENDTYPE  */
  YYSYMBOL_INITIALIZE = 42,                /* INITIALIZE  */
  YYSYMBOL_ALLOC = 43,                     /* ALLOC  */
  YYSYMBOL_FREE = 44,                      /* FREE  */
  YYSYMBOL__NULL = 45,                     /* _NULL  */
  YYSYMBOL_CLASS = 46,                     /* CLASS  */
  YYSYMBOL_ENDCLASS = 47,                  /* ENDCLASS  */
  YYSYMBOL_EXTENDS = 48,                   /* EXTENDS  */
  YYSYMBOL_NEW = 49,                       /* NEW  */
  YYSYMBOL_DELETE = 50,                    /* DELETE  */
  YYSYMBOL_SELF = 51,                      /* SELF  */
  YYSYMBOL_INT = 52,                       /* INT  */
  YYSYMBOL_STR = 53,                       /* STR  */
  YYSYMBOL_STRING = 54,                    /* STRING  */
  YYSYMBOL_55_ = 55,                       /* '{'  */
  YYSYMBOL_56_ = 56,                       /* '}'  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* '('  */
  YYSYMBOL_59_ = 59,                       /* ')'  */
  YYSYMBOL_60_ = 60,                       /* ','  */
  YYSYMBOL_61_ = 61,                       /* '['  */
  YYSYMBOL_62_ = 62,                       /* ']'  */
  YYSYMBOL_63_ = 63,                       /* '.'  */
  YYSYMBOL_64_ = 64,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_typedefblock = 67,              /* typedefblock  */
  YYSYMBOL_typedeflist = 68,               /* typedeflist  */
  YYSYMBOL_typedef = 69,                   /* typedef  */
  YYSYMBOL_70_1 = 70,                      /* $@1  */
  YYSYMBOL_fielddecllist = 71,             /* fielddecllist  */
  YYSYMBOL_fielddecl = 72,                 /* fielddecl  */
  YYSYMBOL_typename = 73,                  /* typename  */
  YYSYMBOL_classdefblock = 74,             /* classdefblock  */
  YYSYMBOL_classdeflist = 75,              /* classdeflist  */
  YYSYMBOL_classdef = 76,                  /* classdef  */
  YYSYMBOL_classname = 77,                 /* classname  */
  YYSYMBOL_classfieldlist = 78,            /* classfieldlist  */
  YYSYMBOL_classfield = 79,                /* classfield  */
  YYSYMBOL_classfuncdecllist = 80,         /* classfuncdecllist  */
  YYSYMBOL_classfuncdecl = 81,             /* classfuncdecl  */
  YYSYMBOL_classfuncdefs = 82,             /* classfuncdefs  */
  YYSYMBOL_gdeclblock = 83,                /* gdeclblock  */
  YYSYMBOL_gdecllist = 84,                 /* gdecllist  */
  YYSYMBOL_gdecl = 85,                     /* gdecl  */
  YYSYMBOL_type = 86,                      /* type  */
  YYSYMBOL_gidlist = 87,                   /* gidlist  */
  YYSYMBOL_gid = 88,                       /* gid  */
  YYSYMBOL_fdefblock = 89,                 /* fdefblock  */
  YYSYMBOL_functype = 90,                  /* functype  */
  YYSYMBOL_fdef = 91,                      /* fdef  */
  YYSYMBOL_mainblock = 92,                 /* mainblock  */
  YYSYMBOL_paramlist = 93,                 /* paramlist  */
  YYSYMBOL_param = 94,                     /* param  */
  YYSYMBOL_paramtype = 95,                 /* paramtype  */
  YYSYMBOL_ldeclblock = 96,                /* ldeclblock  */
  YYSYMBOL_ldecllist = 97,                 /* ldecllist  */
  YYSYMBOL_ldecl = 98,                     /* ldecl  */
  YYSYMBOL_idlist = 99,                    /* idlist  */
  YYSYMBOL_body = 100,                     /* body  */
  YYSYMBOL_stmtlist = 101,                 /* stmtlist  */
  YYSYMBOL_stmt = 102,                     /* stmt  */
  YYSYMBOL_inputstmt = 103,                /* inputstmt  */
  YYSYMBOL_outputstmt = 104,               /* outputstmt  */
  YYSYMBOL_assignstmt = 105,               /* assignstmt  */
  YYSYMBOL_ifstmt = 106,                   /* ifstmt  */
  YYSYMBOL_whilestmt = 107,                /* whilestmt  */
  YYSYMBOL_breakstmt = 108,                /* breakstmt  */
  YYSYMBOL_continuestmt = 109,             /* continuestmt  */
  YYSYMBOL_debugstmt = 110,                /* debugstmt  */
  YYSYMBOL_returnstmt = 111,               /* returnstmt  */
  YYSYMBOL_arglist = 112,                  /* arglist  */
  YYSYMBOL_field = 113,                    /* field  */
  YYSYMBOL_fieldfunction = 114,            /* fieldfunction  */
  YYSYMBOL_expr = 115                      /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   768

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  340

#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,     2,
      58,    59,     2,     2,    60,     2,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    37,    39,    41,    46,    49,    53,    54,
      59,    58,    67,    68,    72,    78,    80,    82,    87,    90,
      94,    95,    99,   111,   113,   118,   119,   123,   128,   129,
     133,   138,   139,   143,   145,   150,   151,   155,   159,   161,
     163,   168,   169,   173,   175,   177,   179,   181,   186,   187,
     191,   193,   195,   200,   209,   218,   219,   220,   224,   226,
     231,   233,   235,   240,   241,   245,   246,   250,   254,   256,
     258,   260,   265,   267,   272,   274,   279,   281,   283,   285,
     287,   289,   291,   293,   298,   300,   302,   304,   306,   311,
     316,   318,   320,   322,   324,   326,   328,   330,   332,   334,
     336,   338,   340,   345,   347,   352,   354,   356,   361,   366,
     371,   376,   381,   383,   386,   390,   392,   394,   399,   401,
     403,   408,   410,   412,   414,   416,   418,   420,   422,   424,
     426,   428,   430,   432,   434,   436,   438,   440,   442,   444,
     446,   448,   450,   452,   454,   456,   458,   460
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "EQ", "NE", "OR", "AND",
  "NOT", "ID", "ASSIGN", "_BEGIN", "END", "DECL", "ENDDECL", "BRKP",
  "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "RETURN", "MAIN",
  "TYPE", "ENDTYPE", "INITIALIZE", "ALLOC", "FREE", "_NULL", "CLASS",
  "ENDCLASS", "EXTENDS", "NEW", "DELETE", "SELF", "INT", "STR", "STRING",
  "'{'", "'}'", "';'", "'('", "')'", "','", "'['", "']'", "'.'", "'&'",
  "$accept", "program", "typedefblock", "typedeflist", "typedef", "$@1",
  "fielddecllist", "fielddecl", "typename", "classdefblock",
  "classdeflist", "classdef", "classname", "classfieldlist", "classfield",
  "classfuncdecllist", "classfuncdecl", "classfuncdefs", "gdeclblock",
  "gdecllist", "gdecl", "type", "gidlist", "gid", "fdefblock", "functype",
  "fdef", "mainblock", "paramlist", "param", "paramtype", "ldeclblock",
  "ldecllist", "ldecl", "idlist", "body", "stmtlist", "stmt", "inputstmt",
  "outputstmt", "assignstmt", "ifstmt", "whilestmt", "breakstmt",
  "continuestmt", "debugstmt", "returnstmt", "arglist", "field",
  "fieldfunction", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   123,   125,    59,    40,    41,
      44,    91,    93,    46,    38
};
#endif

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -29,     3,    32,    -7,  -133,    46,  -133,  -133,    64,    -9,
      34,  -133,  -133,    80,     2,  -133,    60,    10,   150,    24,
    -133,    28,   116,  -133,  -133,   174,  -133,  -133,  -133,  -133,
      90,  -133,    61,   143,  -133,   150,  -133,    24,   271,  -133,
    -133,  -133,  -133,  -133,    -8,  -133,   276,  -133,  -133,  -133,
    -133,   286,    59,   133,  -133,   237,  -133,  -133,   247,  -133,
    -133,   250,    87,  -133,   120,   303,  -133,    61,   253,   120,
    -133,  -133,   104,  -133,   291,  -133,  -133,  -133,   117,  -133,
     105,   248,  -133,   290,   222,   127,  -133,   295,   230,  -133,
     120,   296,  -133,   254,   114,   297,   261,  -133,    22,  -133,
     260,  -133,   120,  -133,  -133,   316,  -133,   108,   145,  -133,
     552,   264,   290,  -133,  -133,   231,   259,   304,  -133,   159,
    -133,  -133,   305,    -2,  -133,   266,   324,   325,   327,   658,
    -133,  -133,   658,   130,   328,   329,   326,   552,  -133,   331,
     333,   334,   335,   337,   338,   339,   340,   372,   -10,  -133,
     297,   342,  -133,  -133,  -133,   135,   381,    67,   130,   383,
      -4,   130,   130,   130,   689,   583,  -133,   399,   385,    25,
    -133,   341,  -133,   130,   387,   343,  -133,   518,     5,     6,
     389,  -133,   390,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,   101,   392,   352,  -133,   394,  -133,   130,   355,
     356,   357,   737,   221,  -133,   398,    88,   -51,   350,   364,
     420,   359,   360,  -133,  -133,   130,   130,   401,   402,   434,
    -133,   403,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,  -133,    95,   115,   404,
     132,  -133,  -133,   408,   410,   737,  -133,  -133,  -133,   737,
     363,   411,   451,    -3,   412,  -133,   130,  -133,  -133,   444,
     441,   130,   130,   233,   737,   235,   416,   417,  -133,   418,
     278,   278,   460,   460,   460,   751,   751,   751,   751,   751,
     751,   201,   206,   460,  -133,  -133,  -133,   419,   462,  -133,
    -133,   422,   130,   130,  -133,   249,   658,   658,   448,   504,
    -133,   130,   421,   130,   130,   130,  -133,   424,  -133,   737,
     263,   103,   530,   605,   441,  -133,   737,   130,   239,   241,
     243,  -133,   465,  -133,   130,   658,  -133,  -133,   322,  -133,
    -133,  -133,   130,   336,   636,  -133,   737,   426,  -133,  -133
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,    19,    10,     0,     9,     1,     0,     5,
       0,     6,     8,    23,     0,    21,     0,     0,     0,     0,
       4,     0,     0,    18,    20,     0,    40,    34,    38,    39,
       0,    36,     0,     0,    52,    50,    51,     0,     0,    49,
       3,    17,    15,    16,     0,    13,     0,    24,    26,    33,
      35,     0,    43,     0,    42,     0,    48,     2,     0,    11,
      12,     0,     0,    46,    57,     0,    37,     0,     0,    57,
      14,    25,     0,    29,     0,    62,    60,    61,     0,    56,
       0,     0,    41,     0,     0,     0,    28,     0,     0,    47,
       0,     0,    58,    44,     0,     0,     0,    50,     0,    32,
       0,    27,    57,    55,    59,     0,    64,     0,     0,    66,
       0,     0,     0,    22,    31,     0,     0,     0,    70,     0,
      63,    65,     0,     0,   110,     0,     0,     0,     0,     0,
     108,   109,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,    45,    71,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,   141,
     138,     0,   137,     0,     0,   139,   140,     0,     0,     0,
       0,    74,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    73,     0,     0,     0,    30,     0,    68,     0,     0,
       0,     0,    90,     0,   115,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   144,   114,     0,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,   117,    72,     0,     0,    96,   116,    53,    69,    93,
       0,     0,     0,     0,     0,    84,     0,    88,    89,     0,
       0,     0,     0,     0,   113,     0,   115,   117,   126,   116,
     121,   122,   123,   124,   125,   131,   132,   129,   130,   127,
     128,   134,   133,   135,    98,    99,   102,     0,     0,    94,
      95,     0,     0,     0,    87,     0,     0,     0,     0,     0,
     146,     0,   142,   114,   114,   114,    97,     0,   100,    91,
       0,     0,     0,     0,   107,   106,   112,     0,     0,     0,
       0,   101,     0,    85,     0,     0,   104,   105,     0,   118,
     119,   120,     0,     0,     0,   143,    92,     0,   103,    86
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,  -133,   481,  -133,  -133,   443,  -133,  -133,
    -133,   474,  -133,  -133,  -133,  -133,   423,  -133,  -133,  -133,
     459,   -57,  -133,   425,  -133,  -133,   -33,    -1,   -31,   400,
    -133,   379,  -133,   386,  -133,   346,  -126,  -130,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,   361,   -83,  -110,  -133,
    -132
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    10,    44,    45,    46,     9,
      14,    15,    16,    62,    71,    72,    73,    98,    19,    30,
      31,    32,    53,    54,    37,    38,    39,    20,    78,    79,
      80,    95,   108,   109,   119,   111,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   263,   175,   176,
     264
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     148,   177,   205,   164,    56,    74,   165,   181,   257,   192,
      41,     1,   193,    17,   206,    87,   292,   157,    40,   148,
      13,     4,   148,   237,   239,   202,   203,   148,    26,   208,
     209,   210,     7,    27,   181,   181,    57,   107,    84,     8,
      34,   219,    34,    18,    42,    43,    41,   136,    59,    23,
     207,   107,    99,   193,   148,   148,   136,   136,   293,   158,
     245,   159,    28,    29,     4,   114,   249,    51,   238,   240,
     166,   115,   167,   168,    97,    36,    35,    36,   113,    52,
      42,    43,    13,   215,   265,   169,   216,    11,   217,    21,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   166,    26,   167,   168,    26,   199,
     200,    91,   170,    49,   117,    25,   201,    64,   171,   169,
      65,   172,    26,    92,   295,   173,   118,    85,    22,   298,
     299,   174,    26,   166,    47,   167,   168,   106,    75,    28,
      29,   196,    28,    29,   243,    34,   170,   255,   169,   256,
     244,   159,   171,   197,   284,   172,    28,    29,   159,   173,
     309,   310,   323,    26,   324,   174,    28,    29,   120,   316,
     312,   313,    76,    77,   285,   170,    89,    90,   193,    97,
      36,   171,   181,   181,   172,   328,   148,   148,   173,    33,
      66,   286,   333,    67,   174,   193,    48,    28,    29,   334,
     336,    55,   148,   148,   181,   222,   223,   224,   225,   226,
     222,   223,   224,   225,   226,   148,   154,   234,   235,   155,
     318,   319,   320,   235,   148,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    96,    90,   253,   224,   225,   226,   101,   102,    58,
     151,    90,   300,   301,    61,   235,    68,   302,   329,   301,
     330,   301,   331,   301,    63,    69,    81,    70,    83,    88,
      93,   311,    94,   100,   104,   105,   112,   110,   102,   116,
     149,   152,   153,   156,   160,   322,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   161,   162,   335,   163,   178,   179,   183,   180,
     184,   185,   186,   191,   187,   188,   189,   190,   337,   195,
     198,   204,   213,   214,   218,   220,   221,   241,   247,   258,
     246,   242,   248,   250,   251,   252,   254,   261,   262,   266,
     267,   269,   289,   259,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   287,   159,   288,   291,
     290,   294,   296,   297,   303,   304,   305,   235,   306,   260,
     307,   308,   317,   321,   332,   339,    12,    60,    24,    50,
     103,   150,    82,   268,   121,    86,   194,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,   314,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   122,   325,
     326,   128,   129,   315,   130,   131,   132,     0,     0,     0,
     123,     0,     0,     0,   134,   236,   124,   125,   126,   127,
     135,   136,     0,   128,   129,     0,   130,   131,   132,   122,
     133,     0,     0,     0,     0,     0,   134,     0,     0,     0,
       0,   123,   135,   136,     0,     0,     0,   124,   125,   126,
     127,   122,     0,     0,   128,   129,     0,   130,   131,   132,
     212,     0,     0,   123,     0,     0,     0,   134,     0,   124,
     125,   126,   127,   135,   136,     0,   128,   129,   327,   130,
     131,   132,   122,     0,     0,     0,     0,     0,     0,   134,
       0,     0,     0,     0,   123,   135,   136,     0,     0,     0,
     124,   125,   126,   127,   122,     0,   338,   128,   129,     0,
     130,   131,   132,     0,     0,     0,   123,     0,     0,     0,
     134,     0,   124,   125,   126,   127,   135,   136,     0,   128,
     129,     0,   130,   131,   132,   122,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,   123,   135,   136,
       0,     0,     0,   124,   125,   126,   127,     0,     0,     0,
     211,   129,     0,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     0,   135,
     136,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   222,   223,   224,   225,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   234,   235
};

static const yytype_int16 yycheck[] =
{
     110,   133,     6,   129,    37,    62,   132,   137,    59,    19,
      18,    40,    63,    22,    18,    72,    19,    19,    19,   129,
      18,    18,   132,    18,    18,   157,   158,   137,    18,   161,
     162,   163,     0,    23,   164,   165,    37,    94,    69,    46,
      18,   173,    18,    52,    52,    53,    18,    51,    56,    47,
     160,   108,    85,    63,   164,   165,    51,    51,    61,    61,
     192,    63,    52,    53,    18,    98,   198,     6,   178,   179,
       3,   102,     5,     6,    52,    53,    52,    53,    56,    18,
      52,    53,    18,    58,   216,    18,    61,    41,    63,    55,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,     3,    18,     5,     6,    18,    42,
      43,     6,    45,    23,     6,    55,    49,    58,    51,    18,
      61,    54,    18,    18,   256,    58,    18,    23,    48,   261,
     262,    64,    18,     3,    18,     5,     6,    23,    18,    52,
      53,     6,    52,    53,    43,    18,    45,    59,    18,    61,
      49,    63,    51,    18,    59,    54,    52,    53,    63,    58,
     292,   293,    59,    18,    61,    64,    52,    53,    23,   301,
     296,   297,    52,    53,    59,    45,    59,    60,    63,    52,
      53,    51,   312,   313,    54,   317,   296,   297,    58,    39,
      57,    59,   324,    60,    64,    63,    22,    52,    53,   325,
     332,    58,   312,   313,   334,     4,     5,     6,     7,     8,
       4,     5,     6,     7,     8,   325,    57,    16,    17,    60,
     303,   304,   305,    17,   334,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    59,    60,    62,     6,     7,     8,    57,    58,    18,
      59,    60,    59,    60,    18,    17,    59,    62,    59,    60,
      59,    60,    59,    60,    18,    58,     3,    57,    55,    18,
      62,    62,    22,    18,    18,    61,    55,    20,    58,     3,
      56,    62,    18,    18,    58,    62,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    58,    58,    62,    58,    58,    58,    57,    63,
      57,    57,    57,    21,    57,    57,    57,    57,    62,    57,
      19,    18,     3,    18,    63,    18,    63,    18,    56,    59,
      18,    21,    18,    58,    58,    58,    18,    58,    58,    18,
      18,    18,    59,    59,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    58,    63,    58,    18,
      59,    59,    28,    32,    58,    58,    58,    17,    59,    59,
      18,    59,    61,    59,    19,    59,     5,    44,    14,    30,
      90,   112,    67,    59,   108,    72,   150,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,     6,    29,
      30,    31,    32,    59,    34,    35,    36,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    44,    57,    24,    25,    26,    27,
      50,    51,    -1,    31,    32,    -1,    34,    35,    36,     6,
      38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    18,    50,    51,    -1,    -1,    -1,    24,    25,    26,
      27,     6,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    -1,    -1,    18,    -1,    -1,    -1,    44,    -1,    24,
      25,    26,    27,    50,    51,    -1,    31,    32,    33,    34,
      35,    36,     6,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    18,    50,    51,    -1,    -1,    -1,
      24,    25,    26,    27,     6,    -1,    30,    31,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      44,    -1,    24,    25,    26,    27,    50,    51,    -1,    31,
      32,    -1,    34,    35,    36,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    18,    50,    51,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,
      51,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    66,    67,    18,    68,    69,     0,    46,    74,
      70,    41,    69,    18,    75,    76,    77,    22,    52,    83,
      92,    55,    48,    47,    76,    55,    18,    23,    52,    53,
      84,    85,    86,    39,    18,    52,    53,    89,    90,    91,
      92,    18,    52,    53,    71,    72,    73,    18,    22,    23,
      85,     6,    18,    87,    88,    58,    91,    92,    18,    56,
      72,    18,    78,    18,    58,    61,    57,    60,    59,    58,
      57,    79,    80,    81,    86,    18,    52,    53,    93,    94,
      95,     3,    88,    55,    93,    23,    81,    86,    18,    59,
      60,     6,    18,    62,    22,    96,    59,    52,    82,    91,
      18,    57,    58,    94,    18,    61,    23,    86,    97,    98,
      20,   100,    55,    56,    91,    93,     3,     6,    18,    99,
      23,    98,     6,    18,    24,    25,    26,    27,    31,    32,
      34,    35,    36,    38,    44,    50,    51,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   113,    56,
      96,    59,    62,    18,    57,    60,    18,    19,    61,    63,
      58,    58,    58,    58,   101,   101,     3,     5,     6,    18,
      45,    51,    54,    58,    64,   113,   114,   115,    58,    58,
      63,   102,   111,    57,    57,    57,    57,    57,    57,    57,
      57,    21,    19,    63,   100,    57,     6,    18,    19,    42,
      43,    49,   115,   115,    18,     6,    18,   113,   115,   115,
     115,    31,    37,     3,    18,    58,    61,    63,    63,   115,
      18,    63,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    57,    18,   113,    18,
     113,    18,    21,    43,    49,   115,    18,    56,    18,   115,
      58,    58,    58,    62,    18,    59,    61,    59,    59,    59,
      59,    58,    58,   112,   115,   115,    18,    18,    59,    18,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,    59,    59,    59,    58,    58,    59,
      59,    18,    19,    61,    59,   115,    28,    32,   115,   115,
      59,    60,    62,    58,    58,    58,    59,    18,    59,   115,
     115,    62,   101,   101,    59,    59,   115,    61,   112,   112,
     112,    59,    62,    59,    61,    29,    30,    33,   115,    59,
      59,    59,    19,   115,   101,    62,   115,    62,    30,    59
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    67,    67,    68,    68,
      70,    69,    71,    71,    72,    73,    73,    73,    74,    74,
      75,    75,    76,    77,    77,    78,    78,    79,    80,    80,
      81,    82,    82,    83,    83,    84,    84,    85,    86,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    90,    91,    92,    93,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    97,    97,    98,    99,    99,
      99,    99,   100,   100,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   106,   106,   107,   107,   107,   108,   109,
     110,   111,   112,   112,   112,   113,   113,   113,   114,   114,
     114,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     2,     3,     0,     2,     1,
       0,     5,     2,     1,     3,     1,     1,     1,     3,     0,
       2,     1,     8,     1,     3,     2,     0,     3,     2,     1,
       6,     2,     1,     3,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     4,     7,     2,     4,     2,     1,
       1,     1,     1,     9,     8,     3,     1,     0,     2,     3,
       1,     1,     1,     3,     2,     2,     1,     3,     3,     4,
       1,     2,     4,     3,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     7,    10,     5,     4,     4,
       3,     6,     9,     4,     5,     5,     3,     5,     4,     4,
       6,     6,     4,     9,     7,     7,     6,     6,     1,     1,
       1,     3,     3,     1,     0,     3,     3,     3,     6,     6,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     4,     7,     2,     2,     4,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 36 "parser.y"
                        { return 1; }
#line 1928 "y.tab.c"
    break;

  case 3:
#line 38 "parser.y"
                        { return 1; }
#line 1934 "y.tab.c"
    break;

  case 4:
#line 40 "parser.y"
                        { return 1; }
#line 1940 "y.tab.c"
    break;

  case 5:
#line 42 "parser.y"
                        { return 1; }
#line 1946 "y.tab.c"
    break;

  case 6:
#line 47 "parser.y"
                        { print_type_table(); }
#line 1952 "y.tab.c"
    break;

  case 7:
#line 49 "parser.y"
                        { print_type_table(); /*Default types exist*/ }
#line 1958 "y.tab.c"
    break;

  case 10:
#line 59 "parser.y"
                        { type_insert((yyvsp[0].tree_node)->var_name,0,NULL); }
#line 1964 "y.tab.c"
    break;

  case 11:
#line 63 "parser.y"
                        { global_type = define_type((yyvsp[-4].tree_node)->var_name); }
#line 1970 "y.tab.c"
    break;

  case 14:
#line 73 "parser.y"
                        { field_insert(global_type,(yyvsp[-1].tree_node)->var_name); }
#line 1976 "y.tab.c"
    break;

  case 15:
#line 79 "parser.y"
                        { global_type = type_find("integer"); }
#line 1982 "y.tab.c"
    break;

  case 16:
#line 81 "parser.y"
                        { global_type = type_find("string"); }
#line 1988 "y.tab.c"
    break;

  case 17:
#line 83 "parser.y"
                        { global_type = type_find((yyvsp[0].tree_node)->var_name);}
#line 1994 "y.tab.c"
    break;

  case 18:
#line 88 "parser.y"
                        { create_virtual_function_table(); }
#line 2000 "y.tab.c"
    break;

  case 19:
#line 90 "parser.y"
                        { _LABEL_DEC(start); }
#line 2006 "y.tab.c"
    break;

  case 22:
#line 107 "parser.y"
                        { check_class_constraints(); }
#line 2012 "y.tab.c"
    break;

  case 23:
#line 112 "parser.y"
                        { current_class = create_class((yyvsp[0].tree_node), NULL); }
#line 2018 "y.tab.c"
    break;

  case 24:
#line 114 "parser.y"
                        { current_class = create_class((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2024 "y.tab.c"
    break;

  case 27:
#line 124 "parser.y"
                        { class_field_helper((yyvsp[-1].tree_node), global_var_type, global_class); }
#line 2030 "y.tab.c"
    break;

  case 30:
#line 134 "parser.y"
                        { class_func_helper((yyvsp[-4].tree_node), global_var_type, global_class); }
#line 2036 "y.tab.c"
    break;

  case 33:
#line 144 "parser.y"
                        { global_decl_helper(); }
#line 2042 "y.tab.c"
    break;

  case 34:
#line 146 "parser.y"
                        { global_decl_helper(); }
#line 2048 "y.tab.c"
    break;

  case 38:
#line 160 "parser.y"
                        { set_variable_type("integer"); }
#line 2054 "y.tab.c"
    break;

  case 39:
#line 162 "parser.y"
                        { set_variable_type("string"); }
#line 2060 "y.tab.c"
    break;

  case 40:
#line 164 "parser.y"
                        { set_variable_type((yyvsp[0].tree_node)->var_name); }
#line 2066 "y.tab.c"
    break;

  case 43:
#line 174 "parser.y"
                        { gst_insert((yyvsp[0].tree_node)->var_name,global_var_type,global_class,1,1,ID_NODE,NULL); }
#line 2072 "y.tab.c"
    break;

  case 44:
#line 176 "parser.y"
                        { gst_insert((yyvsp[-3].tree_node)->var_name,global_var_type,NULL,(yyvsp[-1].tree_node)->constant.int_val,1,ARRAY_NODE,NULL); }
#line 2078 "y.tab.c"
    break;

  case 45:
#line 178 "parser.y"
                        { gst_insert((yyvsp[-6].tree_node)->var_name,global_var_type,NULL,(yyvsp[-4].tree_node)->constant.int_val,(yyvsp[-1].tree_node)->constant.int_val,MATRIX_NODE,NULL); }
#line 2084 "y.tab.c"
    break;

  case 46:
#line 180 "parser.y"
                        { gst_insert((yyvsp[0].tree_node)->var_name,global_var_type,NULL,1,1,PTR_NODE,NULL); }
#line 2090 "y.tab.c"
    break;

  case 47:
#line 182 "parser.y"
                        { gst_insert((yyvsp[-3].tree_node)->var_name,global_var_type,NULL,0,0,FUNC_NODE,param_head); param_head=param_tail=NULL; }
#line 2096 "y.tab.c"
    break;

  case 50:
#line 192 "parser.y"
                        { set_function_type("integer"); }
#line 2102 "y.tab.c"
    break;

  case 51:
#line 194 "parser.y"
                        { set_function_type("string"); }
#line 2108 "y.tab.c"
    break;

  case 52:
#line 196 "parser.y"
                        { set_function_type((yyvsp[0].tree_node)->var_name); }
#line 2114 "y.tab.c"
    break;

  case 53:
#line 205 "parser.y"
                        { define_function((yyvsp[-7].tree_node),(yyvsp[-1].tree_node)); }
#line 2120 "y.tab.c"
    break;

  case 54:
#line 214 "parser.y"
                        { define_main_function((yyvsp[-1].tree_node)); }
#line 2126 "y.tab.c"
    break;

  case 58:
#line 225 "parser.y"
                        { create_function_param((yyvsp[0].tree_node)->var_name); }
#line 2132 "y.tab.c"
    break;

  case 59:
#line 227 "parser.y"
                        { create_function_param((yyvsp[0].tree_node)->var_name); }
#line 2138 "y.tab.c"
    break;

  case 60:
#line 232 "parser.y"
                        { set_param_type("integer"); }
#line 2144 "y.tab.c"
    break;

  case 61:
#line 234 "parser.y"
                        { set_param_type("string"); }
#line 2150 "y.tab.c"
    break;

  case 62:
#line 236 "parser.y"
                        { set_param_type((yyvsp[0].tree_node)->var_name); }
#line 2156 "y.tab.c"
    break;

  case 68:
#line 255 "parser.y"
                        {lst_insert((yyvsp[0].tree_node)->var_name,global_var_type,ID_NODE);}
#line 2162 "y.tab.c"
    break;

  case 69:
#line 257 "parser.y"
                        {lst_insert((yyvsp[0].tree_node)->var_name,global_var_type,PTR_NODE);}
#line 2168 "y.tab.c"
    break;

  case 70:
#line 259 "parser.y"
                        {lst_insert((yyvsp[0].tree_node)->var_name,global_var_type,ID_NODE);}
#line 2174 "y.tab.c"
    break;

  case 71:
#line 261 "parser.y"
                        {lst_insert((yyvsp[0].tree_node)->var_name,global_var_type,PTR_NODE);}
#line 2180 "y.tab.c"
    break;

  case 72:
#line 266 "parser.y"
                        {(yyval.tree_node) = create_ast_node(type_find("void"),NULL,BODY_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[-1].tree_node));}
#line 2186 "y.tab.c"
    break;

  case 73:
#line 268 "parser.y"
                        {(yyval.tree_node) = create_ast_node(type_find("void"),NULL,BODY_NODE,NULL,NULL,(yyvsp[-1].tree_node));}
#line 2192 "y.tab.c"
    break;

  case 74:
#line 273 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,BODY_NODE,(yyvsp[-1].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2198 "y.tab.c"
    break;

  case 75:
#line 275 "parser.y"
                        { (yyval.tree_node)=(yyvsp[0].tree_node); }
#line 2204 "y.tab.c"
    break;

  case 76:
#line 280 "parser.y"
                        { (yyval.tree_node)=(yyvsp[-1].tree_node); }
#line 2210 "y.tab.c"
    break;

  case 77:
#line 282 "parser.y"
                        { (yyval.tree_node)=(yyvsp[-1].tree_node); }
#line 2216 "y.tab.c"
    break;

  case 78:
#line 284 "parser.y"
                        { (yyval.tree_node)=(yyvsp[-1].tree_node); }
#line 2222 "y.tab.c"
    break;

  case 79:
#line 286 "parser.y"
                        { (yyval.tree_node)=(yyvsp[-1].tree_node); }
#line 2228 "y.tab.c"
    break;

  case 80:
#line 288 "parser.y"
                        { (yyval.tree_node)=(yyvsp[-1].tree_node); }
#line 2234 "y.tab.c"
    break;

  case 81:
#line 290 "parser.y"
                        { (yyval.tree_node)=(yyvsp[-1].tree_node); }
#line 2240 "y.tab.c"
    break;

  case 82:
#line 292 "parser.y"
                        { (yyval.tree_node)=(yyvsp[-1].tree_node); }
#line 2246 "y.tab.c"
    break;

  case 83:
#line 294 "parser.y"
                        { (yyval.tree_node)=(yyvsp[-1].tree_node); }
#line 2252 "y.tab.c"
    break;

  case 84:
#line 299 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,READ_NODE,(yyvsp[-1].tree_node),NULL,NULL); }
#line 2258 "y.tab.c"
    break;

  case 85:
#line 301 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,READ_ARRAY_NODE,(yyvsp[-4].tree_node),(yyvsp[-2].tree_node),NULL); }
#line 2264 "y.tab.c"
    break;

  case 86:
#line 303 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,READ_MATRIX_NODE,(yyvsp[-7].tree_node),(yyvsp[-5].tree_node),(yyvsp[-2].tree_node)); }
#line 2270 "y.tab.c"
    break;

  case 87:
#line 305 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,READ_PTR_NODE,(yyvsp[-1].tree_node),NULL,NULL); }
#line 2276 "y.tab.c"
    break;

  case 88:
#line 307 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,READ_FIELD_NODE,(yyvsp[-1].tree_node),NULL,NULL); }
#line 2282 "y.tab.c"
    break;

  case 89:
#line 312 "parser.y"
                        {(yyval.tree_node) = create_ast_node(type_find("void"),NULL,WRITE_NODE,(yyvsp[-1].tree_node),NULL,NULL);}
#line 2288 "y.tab.c"
    break;

  case 90:
#line 317 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2294 "y.tab.c"
    break;

  case 91:
#line 319 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_ARRAY_NODE,(yyvsp[-5].tree_node),(yyvsp[-3].tree_node),(yyvsp[0].tree_node)); }
#line 2300 "y.tab.c"
    break;

  case 92:
#line 321 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_MATRIX_NODE,(yyvsp[-8].tree_node),create_ast_node(type_find("void"),NULL,BODY_NODE,(yyvsp[-6].tree_node),(yyvsp[-3].tree_node),NULL),(yyvsp[0].tree_node)); }
#line 2306 "y.tab.c"
    break;

  case 93:
#line 323 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_PTR_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2312 "y.tab.c"
    break;

  case 94:
#line 325 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_NODE,(yyvsp[-4].tree_node),NULL,create_ast_node(type_find("integer"),NULL,INIT_NODE,NULL,NULL,NULL)); }
#line 2318 "y.tab.c"
    break;

  case 95:
#line 327 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_NODE,(yyvsp[-4].tree_node),NULL,create_ast_node(type_find("type"),NULL,ALLOC_NODE,NULL,NULL,NULL)); }
#line 2324 "y.tab.c"
    break;

  case 96:
#line 329 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_FIELD_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2330 "y.tab.c"
    break;

  case 97:
#line 331 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_FIELD_NODE,(yyvsp[-4].tree_node),NULL,create_ast_node(type_find("type"),NULL,ALLOC_NODE,NULL,NULL,NULL)); }
#line 2336 "y.tab.c"
    break;

  case 98:
#line 333 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,FREE_NODE,(yyvsp[-1].tree_node),NULL,NULL); }
#line 2342 "y.tab.c"
    break;

  case 99:
#line 335 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,FREE_NODE,(yyvsp[-1].tree_node),NULL,NULL); }
#line 2348 "y.tab.c"
    break;

  case 100:
#line 337 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_NODE,(yyvsp[-5].tree_node),(yyvsp[-1].tree_node),create_ast_node(type_find("type"),NULL,ALLOC_NODE,NULL,NULL,NULL)); }
#line 2354 "y.tab.c"
    break;

  case 101:
#line 339 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ASSIGN_FIELD_NODE,(yyvsp[-5].tree_node),(yyvsp[-1].tree_node),create_ast_node(type_find("type"),NULL,ALLOC_NODE,NULL,NULL,NULL)); }
#line 2360 "y.tab.c"
    break;

  case 102:
#line 341 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,FREE_NODE,(yyvsp[-1].tree_node),NULL,NULL); }
#line 2366 "y.tab.c"
    break;

  case 103:
#line 346 "parser.y"
                        { (yyval.tree_node)=create_ast_node(type_find("void"),NULL,ELIF_NODE,(yyvsp[-6].tree_node),(yyvsp[-3].tree_node),(yyvsp[-1].tree_node)); }
#line 2372 "y.tab.c"
    break;

  case 104:
#line 348 "parser.y"
                        { (yyval.tree_node)=create_ast_node(type_find("void"),NULL,IF_NODE,(yyvsp[-4].tree_node),(yyvsp[-1].tree_node),NULL); }
#line 2378 "y.tab.c"
    break;

  case 105:
#line 353 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,WHILE_NODE,(yyvsp[-4].tree_node),NULL,(yyvsp[-1].tree_node)); }
#line 2384 "y.tab.c"
    break;

  case 106:
#line 355 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,REPEAT_NODE,(yyvsp[-1].tree_node),NULL,(yyvsp[-4].tree_node)); }
#line 2390 "y.tab.c"
    break;

  case 107:
#line 357 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,DOWHILE_NODE,(yyvsp[-1].tree_node),NULL,(yyvsp[-4].tree_node)); }
#line 2396 "y.tab.c"
    break;

  case 108:
#line 362 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,BREAK_NODE,NULL,NULL,NULL); }
#line 2402 "y.tab.c"
    break;

  case 109:
#line 367 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,CONTINUE_NODE,NULL,NULL,NULL); }
#line 2408 "y.tab.c"
    break;

  case 110:
#line 372 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,BRKP_NODE,NULL,NULL,NULL); }
#line 2414 "y.tab.c"
    break;

  case 111:
#line 377 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,RET_NODE,(yyvsp[-1].tree_node),NULL,NULL); }
#line 2420 "y.tab.c"
    break;

  case 112:
#line 382 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ARG_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2426 "y.tab.c"
    break;

  case 113:
#line 384 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("void"),NULL,ARG_NODE,NULL,NULL,(yyvsp[0].tree_node)); }
#line 2432 "y.tab.c"
    break;

  case 114:
#line 386 "parser.y"
                        { (yyval.tree_node) = NULL; }
#line 2438 "y.tab.c"
    break;

  case 115:
#line 391 "parser.y"
                        { (yyval.tree_node) = field_type1((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2444 "y.tab.c"
    break;

  case 116:
#line 393 "parser.y"
                        { (yyval.tree_node) = field_type2((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); (yyval.tree_node)->var_type = (yyvsp[0].tree_node)->var_type; }
#line 2450 "y.tab.c"
    break;

  case 117:
#line 395 "parser.y"
                        { (yyval.tree_node) = field_type3((yyvsp[0].tree_node)); }
#line 2456 "y.tab.c"
    break;

  case 118:
#line 400 "parser.y"
                        { (yyval.tree_node) = field_function_type1((yyvsp[-5].tree_node), (yyvsp[-3].tree_node), (yyvsp[-1].tree_node)); }
#line 2462 "y.tab.c"
    break;

  case 119:
#line 402 "parser.y"
                        { (yyval.tree_node) = field_function_type2((yyvsp[-3].tree_node), (yyvsp[-1].tree_node)); }
#line 2468 "y.tab.c"
    break;

  case 120:
#line 404 "parser.y"
                        { (yyval.tree_node) = field_function_type3((yyvsp[-5].tree_node), (yyvsp[-3].tree_node), (yyvsp[-1].tree_node)); }
#line 2474 "y.tab.c"
    break;

  case 121:
#line 409 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("integer"), NULL,PLUS_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2480 "y.tab.c"
    break;

  case 122:
#line 411 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("integer"), NULL,MINUS_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2486 "y.tab.c"
    break;

  case 123:
#line 413 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("integer"), NULL,MUL_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2492 "y.tab.c"
    break;

  case 124:
#line 415 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("integer"), NULL,DIV_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2498 "y.tab.c"
    break;

  case 125:
#line 417 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("integer"), NULL,MOD_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2504 "y.tab.c"
    break;

  case 126:
#line 419 "parser.y"
                        { (yyval.tree_node) = (yyvsp[-1].tree_node); }
#line 2510 "y.tab.c"
    break;

  case 127:
#line 421 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,EQ_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2516 "y.tab.c"
    break;

  case 128:
#line 423 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,NE_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2522 "y.tab.c"
    break;

  case 129:
#line 425 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,LE_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2528 "y.tab.c"
    break;

  case 130:
#line 427 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,GE_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2534 "y.tab.c"
    break;

  case 131:
#line 429 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,LT_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2540 "y.tab.c"
    break;

  case 132:
#line 431 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,GT_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2546 "y.tab.c"
    break;

  case 133:
#line 433 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,AND_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2552 "y.tab.c"
    break;

  case 134:
#line 435 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,OR_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2558 "y.tab.c"
    break;

  case 135:
#line 437 "parser.y"
                        { (yyval.tree_node) = create_ast_node( type_find("boolean"), NULL,NOT_NODE,(yyvsp[-2].tree_node),NULL,(yyvsp[0].tree_node)); }
#line 2564 "y.tab.c"
    break;

  case 136:
#line 439 "parser.y"
                        { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2570 "y.tab.c"
    break;

  case 137:
#line 441 "parser.y"
                        { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2576 "y.tab.c"
    break;

  case 138:
#line 443 "parser.y"
                        { (yyval.tree_node) = create_ast_node(type_find("type"), NULL, NULL_NODE, NULL, NULL, NULL); }
#line 2582 "y.tab.c"
    break;

  case 139:
#line 445 "parser.y"
                        { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2588 "y.tab.c"
    break;

  case 140:
#line 447 "parser.y"
                        { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2594 "y.tab.c"
    break;

  case 141:
#line 449 "parser.y"
                        { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2600 "y.tab.c"
    break;

  case 142:
#line 451 "parser.y"
                        { (yyval.tree_node) = create_ast_node((yyvsp[-3].tree_node)->var_type,(yyvsp[-3].tree_node)->var_name,ARRAY_NODE,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node),NULL); }
#line 2606 "y.tab.c"
    break;

  case 143:
#line 453 "parser.y"
                        { (yyval.tree_node) = create_ast_node((yyvsp[-6].tree_node)->var_type,(yyvsp[-6].tree_node)->var_name,MATRIX_NODE,(yyvsp[-6].tree_node),(yyvsp[-4].tree_node),(yyvsp[-1].tree_node)); }
#line 2612 "y.tab.c"
    break;

  case 144:
#line 455 "parser.y"
                        { (yyval.tree_node) = create_ast_node((yyvsp[0].tree_node)->var_type,(yyvsp[0].tree_node)->var_name,PTR_NODE,(yyvsp[0].tree_node),NULL,NULL); }
#line 2618 "y.tab.c"
    break;

  case 145:
#line 457 "parser.y"
                        { (yyval.tree_node) = create_ast_node((yyvsp[0].tree_node)->var_type,(yyvsp[0].tree_node)->var_name,ADDR_NODE,(yyvsp[0].tree_node),NULL,NULL); }
#line 2624 "y.tab.c"
    break;

  case 146:
#line 459 "parser.y"
                        { (yyval.tree_node) = create_ast_node((yyvsp[-3].tree_node)->var_type,(yyvsp[-3].tree_node)->var_name,FUNC_NODE,(yyvsp[-3].tree_node),NULL,(yyvsp[-1].tree_node)); }
#line 2630 "y.tab.c"
    break;

  case 147:
#line 461 "parser.y"
                        { (yyvsp[0].tree_node)->constant.int_val = - ((yyvsp[0].tree_node)->constant.int_val); (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2636 "y.tab.c"
    break;


#line 2640 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 464 "parser.y"


int yyerror(char const *s)
{
	printf("line: %d error: %s\n",yylineno, s);
	exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
	// initialise global varibales
	global_register=-1;
	label=0;
	flabel=0;
	current_addr_bind=4096;
	local_addr_bind=1;
	param_addr_bind=1;
	global_field_index=0;
	global_class_index=0;
	start=0;

	FILE *fp = fopen(argv[1],"r");
	if(fp)
	{
			yyin=fp;
	}
	else
	{
		printf("file not found\n");
		exit(EXIT_FAILURE);
	}
	target_file=fopen("test.xsm","w");
	start=get_label();
	fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file, "JMP L%d\n", start);
	type_table_create();
	yyparse();
	return 0;
}
