/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         cool_yyparse
#define yylex           cool_yylex
#define yyerror         cool_yyerror
#define yydebug         cool_yydebug
#define yynerrs         cool_yynerrs

#define yylval          cool_yylval
#define yychar          cool_yychar

/* Copy the first part of user declarations.  */
#line 6 "cool.y" /* yacc.c:339  */

#include <iostream>
#include "cool-tree.h"
#include "stringtab.h"
#include "utilities.h"

/* Add your own C declarations here */


/************************************************************************/
/*                DONT CHANGE ANYTHING IN THIS SECTION                  */

extern int yylex();           /* the entry point to the lexer  */
extern int curr_lineno;
extern char *curr_filename;
Program ast_root;            /* the result of the parse  */
Classes parse_results;       /* for use in semantic analysis */
int omerrs = 0;              /* number of errors in lexing and parsing */

/*
   The parser will always call the yyerror function when it encounters a parse
   error. The given yyerror implementation (see below) justs prints out the
   location in the file where the error was found. You should not change the
   error message of yyerror, since it will be used for grading puproses.
*/
void yyerror(const char *s);

/*
   The VERBOSE_ERRORS flag can be used in order to provide more detailed error
   messages. You can use the flag like this:

     if (VERBOSE_ERRORS)
       fprintf(stderr, "semicolon missing from end of declaration of class\n");

   By default the flag is set to 0. If you want to set it to 1 and see your
   verbose error messages, invoke your parser with the -v flag.

   You should try to provide accurate and detailed error messages. A small part
   of your grade will be for good quality error messages.
*/
extern int VERBOSE_ERRORS;


#line 118 "cool.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cool.tab.h".  */
#ifndef YY_COOL_YY_COOL_TAB_H_INCLUDED
# define YY_COOL_YY_COOL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int cool_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ELSE = 259,
    FI = 260,
    IF = 261,
    IN = 262,
    INHERITS = 263,
    LET = 264,
    LOOP = 265,
    POOL = 266,
    THEN = 267,
    WHILE = 268,
    CASE = 269,
    ESAC = 270,
    OF = 271,
    DARROW = 272,
    NEW = 273,
    ISVOID = 274,
    STR_CONST = 275,
    INT_CONST = 276,
    BOOL_CONST = 277,
    TYPEID = 278,
    OBJECTID = 279,
    ASSIGN = 280,
    NOT = 281,
    LE = 282,
    ERROR = 283
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274
#define STR_CONST 275
#define INT_CONST 276
#define BOOL_CONST 277
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "cool.y" /* yacc.c:355  */

  Boolean boolean;
  Symbol symbol;
  Program program;
  Class_ class_;
  Classes classes;
  Feature feature;
  Features features;
  Formal formal;
  Formals formals;
  Case case_;
  Cases cases;
  Expression expression;
  Expressions expressions;
  char *error_msg;

#line 231 "cool.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE cool_yylval;

int cool_yyparse (void);

#endif /* !YY_COOL_YY_COOL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 248 "cool.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   389

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    33,    31,    44,    32,    37,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    38,
      29,    30,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,    35,     2,     2,     2,
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
      25,    26,    27,    28,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   129,   131,   133,   138,   141,   147,   150,
     153,   155,   157,   162,   164,   166,   171,   173,   176,   179,
     184,   186,   191,   193,   195,   198,   201,   202,   206,   208,
     212,   214,   220,   224,   226,   228,   230,   233,   235,   239,
     243,   247,   251,   253,   255,   257,   261,   263,   265,   267,
     270,   274,   276,   278,   282,   284,   288,   290,   292,   294,
     296
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IN",
  "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "OF",
  "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST", "BOOL_CONST",
  "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR", "'<'", "'='",
  "'+'", "'-'", "'*'", "'/'", "'~'", "'@'", "'.'", "';'", "'{'", "'}'",
  "'('", "')'", "':'", "','", "$accept", "program", "class_list", "class",
  "feature_list", "non_empty_feature_list", "feature", "formal_list",
  "formal", "case_list", "let", "assign", "expression_list",
  "expression_list2", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   284,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    60,
      61,    43,    45,    42,    47,   126,    64,    46,    59,   123,
     125,    40,    41,    58,    44
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -27

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-27)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      53,   -28,    -9,    20,    24,  -111,  -111,    -6,  -111,  -111,
      13,    11,   -16,    10,    18,    15,    36,    39,    11,  -111,
      57,    61,    52,    55,  -111,    49,    48,    25,  -111,    70,
    -111,  -111,    58,    75,    56,    57,   177,  -111,  -111,    78,
    -111,  -111,   177,     2,   177,   177,    79,   177,  -111,  -111,
    -111,   -20,   177,   177,   177,   177,   341,    67,   244,  -111,
      64,  -111,   221,   256,  -111,    51,   177,    44,   341,    51,
     153,   293,   267,   177,   177,   177,   177,   177,   177,   177,
      93,    90,   177,   177,    95,   177,    96,   341,  -111,    29,
     341,  -111,   305,  -111,  -111,   352,   352,   352,    -5,    -5,
      51,    51,    82,    80,   281,   196,     0,   232,    81,    -2,
    -111,   177,  -111,    98,    91,  -111,   177,  -111,   177,     8,
    -111,   102,  -111,    84,   341,    88,  -111,    30,   208,   341,
     177,     2,   117,   114,   122,  -111,  -111,   341,  -111,   177,
     121,  -111,    34,   317,   177,  -111,  -111,   329,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     5,     0,     1,     4,
       0,     0,     0,     0,     0,     0,     8,     0,     0,    12,
      18,     0,     0,     0,    10,     0,     0,     0,    17,    14,
       6,    11,     0,     0,     0,     0,     0,     7,    19,     0,
      16,    60,     0,     0,     0,     0,     0,     0,    58,    57,
      59,    56,     0,     0,     0,     0,    15,     0,     0,    24,
       0,    42,     0,     0,    44,    45,     0,     0,    54,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    35,     0,
      28,    41,     0,    30,    55,    52,    51,    53,    46,    47,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,    31,     0,     0,    13,     0,    27,     0,     0,
      40,     0,    43,     0,    29,     0,    33,     0,     0,    25,
       0,     0,     0,     0,     0,    34,    39,    22,    23,     0,
       0,    37,     0,     0,     0,    38,    20,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,   135,   127,  -111,   131,  -111,   115,  -111,
      21,  -111,  -110,  -111,   -36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    15,    16,    17,    27,    28,   109,
      61,   119,    89,    70,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   117,    10,    59,   127,    66,    58,   -26,    62,    63,
       6,    65,    13,   122,     7,   130,    68,    69,    71,    72,
       8,    67,   123,    18,   142,   118,    60,     2,    78,    79,
      87,    80,    81,    11,    92,    14,    12,    95,    96,    97,
      98,    99,   100,   101,   -26,    41,   104,   105,    19,   107,
      42,    -9,   131,    43,     1,    22,     2,    44,    45,    20,
      14,    21,    46,    47,    48,    49,    50,    34,    51,    35,
      52,   110,   135,   111,   111,   124,   145,    24,   111,    53,
     128,    26,   129,    54,    29,    55,    88,    80,    81,    32,
      30,    33,    41,    31,   137,    36,    37,    42,    38,    39,
      43,    57,    64,   143,    44,    45,    82,    84,   147,    46,
      47,    48,    49,    50,   103,    51,   102,    52,   106,   113,
     108,   114,   125,    41,   121,   132,    53,   133,    42,   134,
      54,    43,    55,   126,   139,    44,    45,   140,   144,     9,
      46,    47,    48,    49,    50,    25,    51,    23,    52,     0,
      40,     0,   138,     0,    41,     0,     0,    53,     0,    42,
       0,    54,    43,    55,   141,     0,    44,    45,     0,     0,
       0,    46,    47,    48,    49,    50,     0,    51,    41,    52,
       0,     0,     0,    42,     0,     0,    43,     0,    53,     0,
      44,    45,    54,    91,    55,    46,    47,    48,    49,    50,
     116,    51,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,    53,   136,     0,     0,    54,     0,    55,     0,
       0,     0,     0,    73,     0,    74,    75,    76,    77,    78,
      79,    85,    80,    81,     0,    73,     0,    74,    75,    76,
      77,    78,    79,   120,    80,    81,     0,     0,    73,     0,
      74,    75,    76,    77,    78,    79,    83,    80,    81,    73,
       0,    74,    75,    76,    77,    78,    79,     0,    80,    81,
       0,    73,    86,    74,    75,    76,    77,    78,    79,     0,
      80,    81,     0,    73,     0,    74,    75,    76,    77,    78,
      79,     0,    80,    81,    73,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,     0,    73,    94,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
      73,   115,    74,    75,    76,    77,    78,    79,     0,    80,
      81,    93,    73,     0,    74,    75,    76,    77,    78,    79,
       0,    80,    81,   112,    73,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,   146,    73,     0,    74,    75,
      76,    77,    78,    79,     0,    80,    81,   148,    73,     0,
      74,    75,    76,    77,    78,    79,     0,    80,    81,   -27,
       0,   -27,   -27,    76,    77,    78,    79,     0,    80,    81
};

static const yytype_int16 yycheck[] =
{
      36,     1,     8,     1,   114,    25,    42,     7,    44,    45,
      38,    47,     1,    15,    23,     7,    52,    53,    54,    55,
       0,    41,    24,    39,   134,    25,    24,     3,    33,    34,
      66,    36,    37,    39,    70,    24,    23,    73,    74,    75,
      76,    77,    78,    79,    44,     1,    82,    83,    38,    85,
       6,    40,    44,     9,     1,    40,     3,    13,    14,    41,
      24,    43,    18,    19,    20,    21,    22,    42,    24,    44,
      26,    42,    42,    44,    44,   111,    42,    38,    44,    35,
     116,    24,   118,    39,    23,    41,    42,    36,    37,    40,
      38,    43,     1,    38,   130,    25,    38,     6,    23,    43,
       9,    23,    23,   139,    13,    14,    39,    43,   144,    18,
      19,    20,    21,    22,    24,    24,    23,    26,    23,    37,
      24,    41,    24,     1,    43,    23,    35,    43,     6,    41,
      39,     9,    41,    42,    17,    13,    14,    23,    17,     4,
      18,    19,    20,    21,    22,    18,    24,    16,    26,    -1,
      35,    -1,   131,    -1,     1,    -1,    -1,    35,    -1,     6,
      -1,    39,     9,    41,    42,    -1,    13,    14,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    24,     1,    26,
      -1,    -1,    -1,     6,    -1,    -1,     9,    -1,    35,    -1,
      13,    14,    39,    40,    41,    18,    19,    20,    21,    22,
       4,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,     5,    -1,    -1,    39,    -1,    41,    -1,
      -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    10,    36,    37,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    11,    36,    37,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    12,    36,    37,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      -1,    27,    16,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    27,    42,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    -1,
      27,    40,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    46,    47,    48,    38,    23,     0,    48,
       8,    39,    23,     1,    24,    49,    50,    51,    39,    38,
      41,    43,    40,    51,    38,    49,    24,    52,    53,    23,
      38,    38,    40,    43,    42,    44,    25,    38,    23,    43,
      53,     1,     6,     9,    13,    14,    18,    19,    20,    21,
      22,    24,    26,    35,    39,    41,    59,    23,    59,     1,
      24,    55,    59,    59,    23,    59,    25,    41,    59,    59,
      58,    59,    59,    27,    29,    30,    31,    32,    33,    34,
      36,    37,    39,    12,    43,    10,    16,    59,    42,    57,
      59,    40,    59,    38,    42,    59,    59,    59,    59,    59,
      59,    59,    23,    24,    59,    59,    23,    59,    24,    54,
      42,    44,    38,    37,    41,    40,     4,     1,    25,    56,
      11,    43,    15,    24,    59,    24,    42,    57,    59,    59,
       7,    44,    23,    43,    41,    42,     5,    59,    55,    17,
      23,    42,    57,    59,    17,    42,    38,    59,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    51,    52,    52,    52,    53,
      54,    54,    55,    55,    55,    56,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     6,     8,     1,     0,
       2,     3,     2,     9,     3,     5,     3,     1,     0,     3,
       6,     7,     6,     6,     1,     2,     0,     1,     1,     3,
       2,     3,     3,     5,     6,     3,     4,     7,     8,     7,
       5,     3,     2,     5,     2,     2,     3,     3,     3,     3,
       2,     3,     3,     3,     2,     3,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 125 "cool.y" /* yacc.c:1646  */
    { ast_root = program((yyvsp[0].classes)); }
#line 1465 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 130 "cool.y" /* yacc.c:1646  */
    { (yyval.classes) = single_Classes((yyvsp[0].class_)); }
#line 1471 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 132 "cool.y" /* yacc.c:1646  */
    { (yyval.classes) = append_Classes((yyvsp[-1].classes),single_Classes((yyvsp[0].class_))); }
#line 1477 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 134 "cool.y" /* yacc.c:1646  */
    { (yyval.classes) = nil_Classes();}
#line 1483 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 139 "cool.y" /* yacc.c:1646  */
    { (yyval.class_) = class_((yyvsp[-4].symbol),idtable.add_string("Object"),(yyvsp[-2].features),
                              stringtable.add_string(curr_filename)); }
#line 1490 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 142 "cool.y" /* yacc.c:1646  */
    { (yyval.class_) = class_((yyvsp[-6].symbol),(yyvsp[-4].symbol),(yyvsp[-2].features),stringtable.add_string(curr_filename)); }
#line 1496 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "cool.y" /* yacc.c:1646  */
    { (yyval.features) = (yyvsp[0].features);}
#line 1502 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 150 "cool.y" /* yacc.c:1646  */
    {  (yyval.features) = nil_Features(); }
#line 1508 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 154 "cool.y" /* yacc.c:1646  */
    { (yyval.features) = single_Features((yyvsp[-1].feature)); }
#line 1514 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "cool.y" /* yacc.c:1646  */
    { (yyval.features) = append_Features((yyvsp[-2].features), single_Features((yyvsp[-1].feature))); }
#line 1520 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "cool.y" /* yacc.c:1646  */
    { (yyval.features) = nil_Features(); }
#line 1526 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "cool.y" /* yacc.c:1646  */
    { (yyval.feature) = method((yyvsp[-8].symbol), (yyvsp[-6].formals), (yyvsp[-3].symbol), (yyvsp[-1].expression));}
#line 1532 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 165 "cool.y" /* yacc.c:1646  */
    { (yyval.feature) = attr((yyvsp[-2].symbol), (yyvsp[0].symbol), no_expr());}
#line 1538 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 167 "cool.y" /* yacc.c:1646  */
    { (yyval.feature) = attr((yyvsp[-4].symbol), (yyvsp[-2].symbol), (yyvsp[0].expression));}
#line 1544 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 172 "cool.y" /* yacc.c:1646  */
    { (yyval.formals) = append_Formals((yyvsp[-2].formals), single_Formals((yyvsp[0].formal)));}
#line 1550 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 174 "cool.y" /* yacc.c:1646  */
    { (yyval.formals) = single_Formals((yyvsp[0].formal));}
#line 1556 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 176 "cool.y" /* yacc.c:1646  */
    { (yyval.formals) = nil_Formals();}
#line 1562 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 180 "cool.y" /* yacc.c:1646  */
    { (yyval.formal) = formal((yyvsp[-2].symbol), (yyvsp[0].symbol));}
#line 1568 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 185 "cool.y" /* yacc.c:1646  */
    { (yyval.cases) = single_Cases(branch((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression)));}
#line 1574 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 187 "cool.y" /* yacc.c:1646  */
    { (yyval.cases) = append_Cases((yyvsp[-6].cases), single_Cases(branch((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression))));}
#line 1580 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 192 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = let((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1586 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 194 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = let((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1592 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 195 "cool.y" /* yacc.c:1646  */
    {}
#line 1598 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 199 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression);}
#line 1604 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 201 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = no_expr();}
#line 1610 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 202 "cool.y" /* yacc.c:1646  */
    {}
#line 1616 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 207 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = single_Expressions((yyvsp[0].expression));}
#line 1622 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 209 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression)));}
#line 1628 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 213 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = single_Expressions((yyvsp[-1].expression));}
#line 1634 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 215 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[-1].expression)));}
#line 1640 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 221 "cool.y" /* yacc.c:1646  */
    {(yyval.expression) = assign((yyvsp[-2].symbol), (yyvsp[0].expression));}
#line 1646 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 225 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = dispatch((yyvsp[-4].expression), (yyvsp[-2].symbol), nil_Expressions());}
#line 1652 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 227 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = dispatch((yyvsp[-5].expression), (yyvsp[-3].symbol), (yyvsp[-1].expressions));}
#line 1658 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 229 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = dispatch( object(idtable.add_string("self")), (yyvsp[-2].symbol), nil_Expressions());}
#line 1664 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 231 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = dispatch( object(idtable.add_string("self")), (yyvsp[-3].symbol), (yyvsp[-1].expressions));}
#line 1670 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 234 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = static_dispatch((yyvsp[-6].expression), (yyvsp[-4].symbol), (yyvsp[-2].symbol), nil_Expressions());}
#line 1676 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 236 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = static_dispatch((yyvsp[-7].expression), (yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expressions));}
#line 1682 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 240 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = cond((yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression));}
#line 1688 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 244 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = loop((yyvsp[-3].expression), (yyvsp[-1].expression));}
#line 1694 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = block((yyvsp[-1].expressions));}
#line 1700 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 252 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression);}
#line 1706 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 254 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = typcase((yyvsp[-3].expression), (yyvsp[-1].cases));}
#line 1712 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 256 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = new_((yyvsp[0].symbol));}
#line 1718 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 258 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = isvoid((yyvsp[0].expression));}
#line 1724 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 262 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = plus((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1730 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 264 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = sub((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1736 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 266 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = mul((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1742 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 268 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = divide((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1748 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 271 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = neg((yyvsp[0].expression));}
#line 1754 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 275 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = lt((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1760 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 277 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = leq((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1766 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 279 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = eq((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1772 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 283 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = comp((yyvsp[0].expression));}
#line 1778 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 285 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1784 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 289 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = object((yyvsp[0].symbol));}
#line 1790 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 291 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = int_const((yyvsp[0].symbol));}
#line 1796 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 293 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = string_const((yyvsp[0].symbol));}
#line 1802 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 295 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = bool_const((yyvsp[0].boolean));}
#line 1808 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 296 "cool.y" /* yacc.c:1646  */
    {}
#line 1814 "cool.tab.c" /* yacc.c:1646  */
    break;


#line 1818 "cool.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
  return yyresult;
}
#line 299 "cool.y" /* yacc.c:1906  */


/* This function is called automatically when Bison detects a parse error. */
void yyerror(const char *s)
{
  cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
    << s << " at or near ";
  print_cool_token(yychar);
  cerr << endl;
  omerrs++;

  if(omerrs>20) {
      if (VERBOSE_ERRORS)
         fprintf(stderr, "More than 20 errors\n");
      exit(1);
  }
}
