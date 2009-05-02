/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ERROR_ = 258,
     _SYMB_0 = 259,
     _SYMB_1 = 260,
     _SYMB_2 = 261,
     _SYMB_3 = 262,
     _SYMB_4 = 263,
     _SYMB_5 = 264,
     _SYMB_6 = 265,
     _SYMB_7 = 266,
     _SYMB_8 = 267,
     _SYMB_9 = 268,
     _SYMB_10 = 269,
     _SYMB_11 = 270,
     _SYMB_12 = 271,
     _SYMB_13 = 272,
     _SYMB_14 = 273,
     _SYMB_15 = 274,
     _SYMB_16 = 275,
     _SYMB_17 = 276,
     _SYMB_18 = 277,
     _SYMB_19 = 278,
     _SYMB_20 = 279,
     _SYMB_21 = 280,
     _SYMB_22 = 281,
     _SYMB_23 = 282,
     _SYMB_24 = 283,
     _SYMB_25 = 284,
     _SYMB_26 = 285,
     _SYMB_27 = 286,
     _SYMB_28 = 287,
     _SYMB_29 = 288,
     _SYMB_30 = 289,
     _SYMB_31 = 290,
     _SYMB_32 = 291,
     _SYMB_33 = 292,
     _SYMB_34 = 293,
     _STRING_ = 294,
     _INTEGER_ = 295,
     _DOUBLE_ = 296,
     _IDENT_ = 297
   };
#endif
/* Tokens.  */
#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _SYMB_32 291
#define _SYMB_33 292
#define _SYMB_34 293
#define _STRING_ 294
#define _INTEGER_ 295
#define _DOUBLE_ 296
#define _IDENT_ 297




/* Copy the first part of user declarations.  */
#line 3 "Javalette.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
int yyparse(void);
int yylex(void);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  std::cout << "line " << yy_mylinenumber << std::endl ;
  fprintf(stderr,"error: %s\n",str);
}


Prog* YY_RESULT_Prog_ = 0;
Prog* pProg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Prog_;
  }
}

FunDef* YY_RESULT_FunDef_ = 0;
FunDef* pFunDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FunDef_;
  }
}

Type* YY_RESULT_Type_ = 0;
Type* pType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}

Arg* YY_RESULT_Arg_ = 0;
Arg* pArg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Arg_;
  }
}

Instr* YY_RESULT_Instr_ = 0;
Instr* pInstr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Instr_;
  }
}

Decl* YY_RESULT_Decl_ = 0;
Decl* pDecl(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Decl_;
  }
}

Expr* YY_RESULT_Expr_ = 0;
Expr* pExpr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expr_;
  }
}

Literal* YY_RESULT_Literal_ = 0;
Literal* pLiteral(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Literal_;
  }
}

ListFunDef* YY_RESULT_ListFunDef_ = 0;
ListFunDef* pListFunDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFunDef_;
  }
}

ListArg* YY_RESULT_ListArg_ = 0;
ListArg* pListArg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArg_;
  }
}

ListInstr* YY_RESULT_ListInstr_ = 0;
ListInstr* pListInstr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListInstr_;
  }
}

ListDecl* YY_RESULT_ListDecl_ = 0;
ListDecl* pListDecl(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDecl_;
  }
}

ListExpr* YY_RESULT_ListExpr_ = 0;
ListExpr* pListExpr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpr_;
  }
}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 224 "Javalette.y"
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Prog* prog_;
  FunDef* fundef_;
  Type* type_;
  Arg* arg_;
  Instr* instr_;
  Decl* decl_;
  Expr* expr_;
  Literal* literal_;
  ListFunDef* listfundef_;
  ListArg* listarg_;
  ListInstr* listinstr_;
  ListDecl* listdecl_;
  ListExpr* listexpr_;

}
/* Line 187 of yacc.c.  */
#line 421 "Parser.C"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 434 "Parser.C"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    12,    14,    16,    18,    20,    23,
      27,    29,    31,    33,    36,    40,    44,    50,    58,    61,
      71,    77,    79,    83,    88,    92,    99,   101,   104,   107,
     109,   114,   116,   120,   122,   126,   128,   132,   136,   138,
     142,   146,   150,   154,   156,   160,   164,   166,   170,   174,
     178,   180,   183,   186,   189,   191,   196,   198,   203,   205,
     207,   211,   213,   215,   217,   219,   221,   224,   225,   227,
     231,   232,   235,   237,   241,   242,   244
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    65,    -1,    46,    42,     4,    66,     5,
      48,    -1,    34,    -1,    30,    -1,    36,    -1,    29,    -1,
      46,    42,    -1,     6,    67,     7,    -1,    50,    -1,    45,
      -1,    48,    -1,    35,     8,    -1,    35,    52,     8,    -1,
      46,    68,     8,    -1,    33,     4,    52,     5,    50,    -1,
      33,     4,    52,     5,    50,    31,    50,    -1,    52,     8,
      -1,    32,     4,    51,     8,    52,     8,    52,     5,    50,
      -1,    37,     4,    52,     5,    50,    -1,    42,    -1,    42,
       9,    52,    -1,    42,    10,    52,    11,    -1,    42,     9,
      52,    -1,    42,    10,    52,    11,     9,    52,    -1,    53,
      -1,    42,    12,    -1,    42,    13,    -1,    54,    -1,     4,
      46,     5,    63,    -1,    55,    -1,    55,    14,    56,    -1,
      56,    -1,    56,    15,    57,    -1,    57,    -1,    57,    16,
      58,    -1,    57,    17,    58,    -1,    58,    -1,    58,    18,
      59,    -1,    58,    19,    59,    -1,    58,    20,    59,    -1,
      58,    21,    59,    -1,    59,    -1,    59,    22,    60,    -1,
      59,    23,    60,    -1,    60,    -1,    60,    24,    61,    -1,
      60,    25,    61,    -1,    60,    26,    61,    -1,    61,    -1,
      27,    61,    -1,    22,    61,    -1,    23,    61,    -1,    62,
      -1,    42,     4,    69,     5,    -1,    63,    -1,    42,    10,
      52,    11,    -1,    42,    -1,    64,    -1,     4,    52,     5,
      -1,    40,    -1,    41,    -1,    39,    -1,    38,    -1,    45,
      -1,    45,    65,    -1,    -1,    47,    -1,    47,    28,    66,
      -1,    -1,    67,    49,    -1,    51,    -1,    51,    28,    68,
      -1,    -1,    52,    -1,    52,    28,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   315,   315,   317,   319,   320,   321,   322,   324,   326,
     328,   329,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   341,   342,   343,   345,   346,   347,   349,   350,   351,
     353,   354,   356,   357,   359,   360,   362,   363,   364,   366,
     367,   368,   369,   370,   372,   373,   374,   376,   377,   378,
     379,   381,   382,   383,   384,   386,   387,   389,   390,   391,
     392,   394,   395,   396,   397,   399,   400,   402,   403,   404,
     406,   407,   409,   410,   412,   413,   414
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "\"(\"", "\")\"", "\"{\"",
  "\"}\"", "\";\"", "\"=\"", "\"[\"", "\"]\"", "\"--\"", "\"++\"",
  "\"||\"", "\"&&\"", "\"==\"", "\"!=\"", "\"<\"", "\">\"", "\"<=\"",
  "\">=\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"!\"", "\",\"",
  "\"boolean\"", "\"double\"", "\"else\"", "\"for\"", "\"if\"", "\"int\"",
  "\"return\"", "\"void\"", "\"while\"", "_SYMB_34", "_STRING_",
  "_INTEGER_", "_DOUBLE_", "_IDENT_", "$accept", "Prog", "FunDef", "Type",
  "Arg", "Instr1", "Instr2", "Instr", "Decl", "Expr", "Expr1", "Expr2",
  "Expr3", "Expr4", "Expr5", "Expr6", "Expr7", "Expr8", "Expr9", "Expr10",
  "Expr11", "Literal", "ListFunDef", "ListArg", "ListInstr2", "ListDecl",
  "ListExpr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    46,    46,    46,    47,    48,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    51,    52,    52,    52,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    64,    65,    65,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     2,     3,     3,     5,     7,     2,     9,
       5,     1,     3,     4,     3,     6,     1,     2,     2,     1,
       4,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     1,     4,     1,     4,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     0,     1,     3,
       0,     2,     1,     3,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     5,     4,     6,     0,    65,     0,     2,     1,
      66,     0,    67,     0,    68,     0,     8,    67,     0,    69,
      70,     3,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,    64,    63,    61,    62,    58,    11,     0,    12,
      71,    10,     0,    26,    29,    31,    33,    35,    38,    43,
      46,    50,    54,    56,    59,     0,     0,     0,    58,    52,
      53,    51,     0,     0,    13,     0,     0,    74,     0,     0,
      27,    28,    21,    72,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,    21,     0,     0,    14,     0,    75,     0,    24,
       0,     0,     0,     0,    15,    32,    34,    36,    37,    39,
      40,    41,    42,    44,    45,    47,    48,    49,    58,    30,
       0,     0,     0,     0,    74,    55,    57,    22,     0,    73,
      57,     0,     0,    16,    20,    76,     0,    23,     0,     0,
      25,     0,    17,     0,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,   132,    14,    39,    40,    41,    73,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     8,    15,    22,    74,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -115
static const yytype_int16 yypact[] =
{
      -6,  -115,  -115,  -115,  -115,     5,    -6,   -20,  -115,  -115,
    -115,    14,    -6,    -5,    24,    72,  -115,    -6,    50,  -115,
    -115,  -115,    53,   117,  -115,    31,    31,    31,    77,    80,
       9,    95,  -115,  -115,  -115,  -115,     2,  -115,    65,  -115,
    -115,  -115,   106,  -115,  -115,   108,   105,     3,    85,    19,
      41,  -115,  -115,  -115,  -115,   119,   122,   138,    51,  -115,
    -115,  -115,    99,   138,  -115,   135,   138,   138,   138,   138,
    -115,  -115,    29,   124,   137,  -115,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    70,
    -115,   138,    87,   142,   149,  -115,   157,   136,   158,  -115,
     159,   138,   138,    99,  -115,   105,     3,    85,    85,    19,
      19,    19,    19,    41,    41,  -115,  -115,  -115,   161,  -115,
     162,   138,    96,    96,   138,  -115,   163,  -115,   164,  -115,
    -115,   166,    99,   150,  -115,  -115,   138,  -115,   138,    96,
    -115,   177,  -115,    96,  -115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,   165,     4,  -115,   167,  -115,  -114,   121,   -23,
    -115,  -115,  -115,   110,   107,    38,    86,    64,   -24,  -115,
     100,  -115,   182,   173,  -115,    88,    68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      56,    59,    60,    61,     7,     9,    67,    65,   133,   134,
       7,    68,    69,    23,    70,    71,    13,    64,    12,    78,
      79,    13,    11,     1,     2,   142,    38,    55,     3,   144,
       4,    25,    26,    12,    56,    57,    27,    16,   101,   102,
      94,    84,    85,    96,    97,    99,   100,    32,    33,    34,
      35,    36,    17,    25,    26,    67,    20,    23,    27,    20,
      24,    91,   115,   116,   117,    86,    87,    88,   120,    32,
      33,    34,    35,    58,    57,    25,    26,    18,   127,   128,
      27,    62,     1,     2,    63,    28,    29,     3,    30,     4,
      31,    32,    33,    34,    35,    36,   101,   102,   131,    66,
      23,    97,    20,    80,    81,    82,    83,    72,    32,    33,
      34,    35,   118,   140,    75,   141,   107,   108,    25,    26,
      77,    23,    76,    27,    89,     1,     2,    90,    28,    29,
       3,    30,     4,    31,    32,    33,    34,    35,    36,    25,
      26,    92,    23,    95,    27,   104,     1,     2,   113,   114,
     121,     3,   103,     4,   122,    32,    33,    34,    35,    36,
      25,    26,   123,   125,   124,    27,   109,   110,   111,   112,
     126,    91,   136,   130,   138,   137,    32,    33,    34,    35,
      36,   139,   143,    93,   106,    21,   105,    37,    10,   119,
      19,   129,   135
};

static const yytype_uint8 yycheck[] =
{
      23,    25,    26,    27,     0,     0,     4,    30,   122,   123,
       6,     9,    10,     4,    12,    13,    12,     8,     4,    16,
      17,    17,    42,    29,    30,   139,    22,    23,    34,   143,
      36,    22,    23,     4,    57,     4,    27,    42,     9,    10,
      63,    22,    23,    66,    67,    68,    69,    38,    39,    40,
      41,    42,    28,    22,    23,     4,     6,     4,    27,     6,
       7,    10,    86,    87,    88,    24,    25,    26,    91,    38,
      39,    40,    41,    42,     4,    22,    23,     5,   101,   102,
      27,     4,    29,    30,     4,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     9,    10,   121,     4,
       4,   124,     6,    18,    19,    20,    21,    42,    38,    39,
      40,    41,    42,   136,     8,   138,    78,    79,    22,    23,
      15,     4,    14,    27,     5,    29,    30,     5,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    22,
      23,    42,     4,     8,    27,     8,    29,    30,    84,    85,
       8,    34,    28,    36,     5,    38,    39,    40,    41,    42,
      22,    23,     5,     5,    28,    27,    80,    81,    82,    83,
      11,    10,     9,    11,     8,    11,    38,    39,    40,    41,
      42,    31,     5,    62,    77,    18,    76,    22,     6,    89,
      17,   103,   124
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    30,    34,    36,    44,    45,    46,    65,     0,
      65,    42,     4,    46,    47,    66,    42,    28,     5,    66,
       6,    48,    67,     4,     7,    22,    23,    27,    32,    33,
      35,    37,    38,    39,    40,    41,    42,    45,    46,    48,
      49,    50,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    46,    52,     4,    42,    61,
      61,    61,     4,     4,     8,    52,     4,     4,     9,    10,
      12,    13,    42,    51,    68,     8,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     5,
       5,    10,    42,    51,    52,     8,    52,    52,    69,    52,
      52,     9,    10,    28,     8,    56,    57,    58,    58,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    42,    63,
      52,     8,     5,     5,    28,     5,    11,    52,    52,    68,
      11,    52,    46,    50,    50,    69,     9,    11,     8,    31,
      52,    52,    50,     5,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 315 "Javalette.y"
    {  std::reverse((yyvsp[(1) - (1)].listfundef_)->begin(),(yyvsp[(1) - (1)].listfundef_)->end()) ;(yyval.prog_) = new Program((yyvsp[(1) - (1)].listfundef_)); (yyval.prog_)->line_number = yy_mylinenumber; YY_RESULT_Prog_= (yyval.prog_); ;}
    break;

  case 3:
#line 317 "Javalette.y"
    {  std::reverse((yyvsp[(4) - (6)].listarg_)->begin(),(yyvsp[(4) - (6)].listarg_)->end()) ;(yyval.fundef_) = new Function((yyvsp[(1) - (6)].type_), (yyvsp[(2) - (6)].string_), (yyvsp[(4) - (6)].listarg_), (yyvsp[(6) - (6)].instr_)); (yyval.fundef_)->line_number = yy_mylinenumber;  ;}
    break;

  case 4:
#line 319 "Javalette.y"
    {  (yyval.type_) = new IntType(); (yyval.type_)->line_number = yy_mylinenumber;  ;}
    break;

  case 5:
#line 320 "Javalette.y"
    {  (yyval.type_) = new DoubleType(); (yyval.type_)->line_number = yy_mylinenumber;  ;}
    break;

  case 6:
#line 321 "Javalette.y"
    {  (yyval.type_) = new VoidType(); (yyval.type_)->line_number = yy_mylinenumber;  ;}
    break;

  case 7:
#line 322 "Javalette.y"
    {  (yyval.type_) = new BoolType(); (yyval.type_)->line_number = yy_mylinenumber;  ;}
    break;

  case 8:
#line 324 "Javalette.y"
    {  (yyval.arg_) = new FunctionArg((yyvsp[(1) - (2)].type_), (yyvsp[(2) - (2)].string_)); (yyval.arg_)->line_number = yy_mylinenumber;  ;}
    break;

  case 9:
#line 326 "Javalette.y"
    {  (yyval.instr_) = new CompoundInstr((yyvsp[(2) - (3)].listinstr_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 10:
#line 328 "Javalette.y"
    {  (yyval.instr_) = (yyvsp[(1) - (1)].instr_);  ;}
    break;

  case 11:
#line 329 "Javalette.y"
    {  (yyval.instr_) = new InnerFunction((yyvsp[(1) - (1)].fundef_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 12:
#line 331 "Javalette.y"
    {  (yyval.instr_) = (yyvsp[(1) - (1)].instr_);  ;}
    break;

  case 13:
#line 332 "Javalette.y"
    {  (yyval.instr_) = new ReturnInstr(); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 14:
#line 333 "Javalette.y"
    {  (yyval.instr_) = new ReturnExprInstr((yyvsp[(2) - (3)].expr_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 15:
#line 334 "Javalette.y"
    {  std::reverse((yyvsp[(2) - (3)].listdecl_)->begin(),(yyvsp[(2) - (3)].listdecl_)->end()) ;(yyval.instr_) = new DeclInstr((yyvsp[(1) - (3)].type_), (yyvsp[(2) - (3)].listdecl_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 16:
#line 335 "Javalette.y"
    {  (yyval.instr_) = new ConditionalIf((yyvsp[(3) - (5)].expr_), (yyvsp[(5) - (5)].instr_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 17:
#line 336 "Javalette.y"
    {  (yyval.instr_) = new ConditionalIfElse((yyvsp[(3) - (7)].expr_), (yyvsp[(5) - (7)].instr_), (yyvsp[(7) - (7)].instr_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 18:
#line 337 "Javalette.y"
    {  (yyval.instr_) = new ExpressionInstr((yyvsp[(1) - (2)].expr_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 19:
#line 338 "Javalette.y"
    {  (yyval.instr_) = new ForLoop((yyvsp[(3) - (9)].decl_), (yyvsp[(5) - (9)].expr_), (yyvsp[(7) - (9)].expr_), (yyvsp[(9) - (9)].instr_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 20:
#line 339 "Javalette.y"
    {  (yyval.instr_) = new WhileLoop((yyvsp[(3) - (5)].expr_), (yyvsp[(5) - (5)].instr_)); (yyval.instr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 21:
#line 341 "Javalette.y"
    {  (yyval.decl_) = new OnlyDeclarator((yyvsp[(1) - (1)].string_)); (yyval.decl_)->line_number = yy_mylinenumber;  ;}
    break;

  case 22:
#line 342 "Javalette.y"
    {  (yyval.decl_) = new InitDeclarator((yyvsp[(1) - (3)].string_), (yyvsp[(3) - (3)].expr_)); (yyval.decl_)->line_number = yy_mylinenumber;  ;}
    break;

  case 23:
#line 343 "Javalette.y"
    {  (yyval.decl_) = new ArrayDeclarator((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].expr_)); (yyval.decl_)->line_number = yy_mylinenumber;  ;}
    break;

  case 24:
#line 345 "Javalette.y"
    {  (yyval.expr_) = new IdentAssigment((yyvsp[(1) - (3)].string_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 25:
#line 346 "Javalette.y"
    {  (yyval.expr_) = new ArrayAssigment((yyvsp[(1) - (6)].string_), (yyvsp[(3) - (6)].expr_), (yyvsp[(6) - (6)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 26:
#line 347 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 27:
#line 349 "Javalette.y"
    {  (yyval.expr_) = new PostDecrement((yyvsp[(1) - (2)].string_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 28:
#line 350 "Javalette.y"
    {  (yyval.expr_) = new PostIncrement((yyvsp[(1) - (2)].string_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 29:
#line 351 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 30:
#line 353 "Javalette.y"
    {  (yyval.expr_) = new Cast((yyvsp[(2) - (4)].type_), (yyvsp[(4) - (4)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 31:
#line 354 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 32:
#line 356 "Javalette.y"
    {  (yyval.expr_) = new LogExprOr((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 33:
#line 357 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 34:
#line 359 "Javalette.y"
    {  (yyval.expr_) = new LogExprAnd((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 35:
#line 360 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 36:
#line 362 "Javalette.y"
    {  (yyval.expr_) = new LogExprEq((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 37:
#line 363 "Javalette.y"
    {  (yyval.expr_) = new LogExprNeq((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 38:
#line 364 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 39:
#line 366 "Javalette.y"
    {  (yyval.expr_) = new RelExprL((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 40:
#line 367 "Javalette.y"
    {  (yyval.expr_) = new RelExprG((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 41:
#line 368 "Javalette.y"
    {  (yyval.expr_) = new RelExprLe((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 42:
#line 369 "Javalette.y"
    {  (yyval.expr_) = new RelExprGe((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 43:
#line 370 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 44:
#line 372 "Javalette.y"
    {  (yyval.expr_) = new AddExpr((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 45:
#line 373 "Javalette.y"
    {  (yyval.expr_) = new DecExpr((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 46:
#line 374 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 47:
#line 376 "Javalette.y"
    {  (yyval.expr_) = new MulExpr((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 48:
#line 377 "Javalette.y"
    {  (yyval.expr_) = new DivExpr((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 49:
#line 378 "Javalette.y"
    {  (yyval.expr_) = new ModExpr((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 50:
#line 379 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 51:
#line 381 "Javalette.y"
    {  (yyval.expr_) = new NegExpr((yyvsp[(2) - (2)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 52:
#line 382 "Javalette.y"
    {  (yyval.expr_) = new PlusExpr((yyvsp[(2) - (2)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 53:
#line 383 "Javalette.y"
    {  (yyval.expr_) = new MinusExpr((yyvsp[(2) - (2)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 54:
#line 384 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 55:
#line 386 "Javalette.y"
    {  std::reverse((yyvsp[(3) - (4)].listexpr_)->begin(),(yyvsp[(3) - (4)].listexpr_)->end()) ;(yyval.expr_) = new FunctionCall((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].listexpr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 56:
#line 387 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  ;}
    break;

  case 57:
#line 389 "Javalette.y"
    {  (yyval.expr_) = new ArrayAccess((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 58:
#line 390 "Javalette.y"
    {  (yyval.expr_) = new IdentExpr((yyvsp[(1) - (1)].string_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 59:
#line 391 "Javalette.y"
    {  (yyval.expr_) = new LiteralExpr((yyvsp[(1) - (1)].literal_)); (yyval.expr_)->line_number = yy_mylinenumber;  ;}
    break;

  case 60:
#line 392 "Javalette.y"
    {  (yyval.expr_) = (yyvsp[(2) - (3)].expr_);  ;}
    break;

  case 61:
#line 394 "Javalette.y"
    {  (yyval.literal_) = new LiteralInteger((yyvsp[(1) - (1)].int_)); (yyval.literal_)->line_number = yy_mylinenumber;  ;}
    break;

  case 62:
#line 395 "Javalette.y"
    {  (yyval.literal_) = new LiteralDouble((yyvsp[(1) - (1)].double_)); (yyval.literal_)->line_number = yy_mylinenumber;  ;}
    break;

  case 63:
#line 396 "Javalette.y"
    {  (yyval.literal_) = new LiteralString((yyvsp[(1) - (1)].string_)); (yyval.literal_)->line_number = yy_mylinenumber;  ;}
    break;

  case 64:
#line 397 "Javalette.y"
    {  (yyval.literal_) = new LiteralBoolean((yyvsp[(1) - (1)].string_)); (yyval.literal_)->line_number = yy_mylinenumber;  ;}
    break;

  case 65:
#line 399 "Javalette.y"
    {  (yyval.listfundef_) = new ListFunDef() ; (yyval.listfundef_)->push_back((yyvsp[(1) - (1)].fundef_));  ;}
    break;

  case 66:
#line 400 "Javalette.y"
    {  (yyvsp[(2) - (2)].listfundef_)->push_back((yyvsp[(1) - (2)].fundef_)) ; (yyval.listfundef_) = (yyvsp[(2) - (2)].listfundef_) ;  ;}
    break;

  case 67:
#line 402 "Javalette.y"
    {  (yyval.listarg_) = new ListArg();  ;}
    break;

  case 68:
#line 403 "Javalette.y"
    {  (yyval.listarg_) = new ListArg() ; (yyval.listarg_)->push_back((yyvsp[(1) - (1)].arg_));  ;}
    break;

  case 69:
#line 404 "Javalette.y"
    {  (yyvsp[(3) - (3)].listarg_)->push_back((yyvsp[(1) - (3)].arg_)) ; (yyval.listarg_) = (yyvsp[(3) - (3)].listarg_) ;  ;}
    break;

  case 70:
#line 406 "Javalette.y"
    {  (yyval.listinstr_) = new ListInstr();  ;}
    break;

  case 71:
#line 407 "Javalette.y"
    {  (yyvsp[(1) - (2)].listinstr_)->push_back((yyvsp[(2) - (2)].instr_)) ; (yyval.listinstr_) = (yyvsp[(1) - (2)].listinstr_) ;  ;}
    break;

  case 72:
#line 409 "Javalette.y"
    {  (yyval.listdecl_) = new ListDecl() ; (yyval.listdecl_)->push_back((yyvsp[(1) - (1)].decl_));  ;}
    break;

  case 73:
#line 410 "Javalette.y"
    {  (yyvsp[(3) - (3)].listdecl_)->push_back((yyvsp[(1) - (3)].decl_)) ; (yyval.listdecl_) = (yyvsp[(3) - (3)].listdecl_) ;  ;}
    break;

  case 74:
#line 412 "Javalette.y"
    {  (yyval.listexpr_) = new ListExpr();  ;}
    break;

  case 75:
#line 413 "Javalette.y"
    {  (yyval.listexpr_) = new ListExpr() ; (yyval.listexpr_)->push_back((yyvsp[(1) - (1)].expr_));  ;}
    break;

  case 76:
#line 414 "Javalette.y"
    {  (yyvsp[(3) - (3)].listexpr_)->push_back((yyvsp[(1) - (3)].expr_)) ; (yyval.listexpr_) = (yyvsp[(3) - (3)].listexpr_) ;  ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2141 "Parser.C"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



