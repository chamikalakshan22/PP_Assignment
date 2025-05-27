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
     FORM = 258,
     META = 259,
     SECTION = 260,
     FIELD = 261,
     VALIDATE = 262,
     IF = 263,
     ERROR = 264,
     TEXT = 265,
     TEXTAREA = 266,
     NUMBER_TYPE = 267,
     EMAIL = 268,
     DATE = 269,
     CHECKBOX = 270,
     DROPDOWN = 271,
     RADIO = 272,
     PASSWORD = 273,
     FILE_FIELD = 274,
     REQUIRED = 275,
     PATTERN = 276,
     DEFAULT = 277,
     MIN = 278,
     MAX = 279,
     ROWS = 280,
     COLS = 281,
     OPTIONS = 282,
     ACCEPT = 283,
     LBRACE = 284,
     RBRACE = 285,
     LBRACKET = 286,
     RBRACKET = 287,
     LPAREN = 288,
     RPAREN = 289,
     SEMICOLON = 290,
     COMMA = 291,
     COLON = 292,
     EQUALS = 293,
     LT = 294,
     GT = 295,
     LE = 296,
     GE = 297,
     EQ = 298,
     NE = 299,
     IDENTIFIER = 300,
     STRING = 301,
     NUMBER = 302,
     BOOLEAN = 303
   };
#endif
/* Tokens.  */
#define FORM 258
#define META 259
#define SECTION 260
#define FIELD 261
#define VALIDATE 262
#define IF 263
#define ERROR 264
#define TEXT 265
#define TEXTAREA 266
#define NUMBER_TYPE 267
#define EMAIL 268
#define DATE 269
#define CHECKBOX 270
#define DROPDOWN 271
#define RADIO 272
#define PASSWORD 273
#define FILE_FIELD 274
#define REQUIRED 275
#define PATTERN 276
#define DEFAULT 277
#define MIN 278
#define MAX 279
#define ROWS 280
#define COLS 281
#define OPTIONS 282
#define ACCEPT 283
#define LBRACE 284
#define RBRACE 285
#define LBRACKET 286
#define RBRACKET 287
#define LPAREN 288
#define RPAREN 289
#define SEMICOLON 290
#define COMMA 291
#define COLON 292
#define EQUALS 293
#define LT 294
#define GT 295
#define LE 296
#define GE 297
#define EQ 298
#define NE 299
#define IDENTIFIER 300
#define STRING 301
#define NUMBER 302
#define BOOLEAN 303




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int line_num;
void yyerror(const char *s);

FILE *output_file;

// Data structures for form representation
typedef struct {
    char *key;
    char *value;
} MetaData;

typedef struct {
    char *name;
    char *value;
} Attribute;

typedef struct {
    char *name;
    char *type;
    Attribute attributes[20];
    int attr_count;
} Field;

typedef struct {
    char *name;
    Field fields[50];
    int field_count;
} Section;

typedef struct {
    char *field_name;
    char *operator;
    double value;
    char *error_msg;
} ValidationRule;

typedef struct {
    char *name;
    MetaData metadata[10];
    int meta_count;
    Section sections[20];
    int section_count;
    ValidationRule validations[10];
    int validation_count;
} Form;

Form current_form;
Section current_section;
Field current_field;
ValidationRule current_validation;

// Function prototypes
void add_metadata(char *key, char *value);
void add_section(char *name);
void add_field(char *name, char *type);
void add_attribute(char *name, char *value);
void add_validation(char *field, char *op, double val, char *error);
void generate_html();
char* strip_quotes(char *str);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 68 "parser.y"
{
    char *str;
    double num;
    int boolean;
}
/* Line 193 of yacc.c.  */
#line 265 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 278 "parser.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNRULES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    11,    14,    18,    20,    23,    24,
      27,    33,    35,    38,    39,    46,    48,    51,    58,    64,
      66,    68,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    89,    91,    95,    99,   103,   107,   111,   115,   119,
     123,   129,   133,   135,   139,   144,   146,   149,   159,   169,
     179,   189,   199
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,     3,    45,    29,    52,    30,
      -1,    53,    55,    -1,    53,    55,    64,    -1,    55,    -1,
      55,    64,    -1,    -1,    53,    54,    -1,     4,    45,    38,
      46,    35,    -1,    56,    -1,    55,    56,    -1,    -1,     5,
      45,    29,    57,    58,    30,    -1,    59,    -1,    58,    59,
      -1,     6,    45,    37,    60,    61,    35,    -1,     6,    45,
      37,    60,    35,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1,    62,    -1,    61,    62,    -1,    20,
      -1,    21,    38,    46,    -1,    22,    38,    46,    -1,    22,
      38,    47,    -1,    22,    38,    48,    -1,    23,    38,    47,
      -1,    24,    38,    47,    -1,    25,    38,    47,    -1,    26,
      38,    47,    -1,    27,    38,    31,    63,    32,    -1,    28,
      38,    46,    -1,    46,    -1,    63,    36,    46,    -1,     7,
      29,    65,    30,    -1,    66,    -1,    65,    66,    -1,     8,
      45,    39,    47,    29,     9,    46,    35,    30,    -1,     8,
      45,    40,    47,    29,     9,    46,    35,    30,    -1,     8,
      45,    41,    47,    29,     9,    46,    35,    30,    -1,     8,
      45,    42,    47,    29,     9,    46,    35,    30,    -1,     8,
      45,    43,    47,    29,     9,    46,    35,    30,    -1,     8,
      45,    44,    47,    29,     9,    46,    35,    30,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   101,   108,   109,   110,   111,   114,   116,
     120,   128,   129,   133,   133,   140,   141,   145,   150,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   171,
     172,   176,   179,   183,   187,   192,   195,   200,   205,   210,
     215,   219,   226,   230,   240,   244,   245,   249,   254,   259,
     264,   269,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FORM", "META", "SECTION", "FIELD",
  "VALIDATE", "IF", "ERROR", "TEXT", "TEXTAREA", "NUMBER_TYPE", "EMAIL",
  "DATE", "CHECKBOX", "DROPDOWN", "RADIO", "PASSWORD", "FILE_FIELD",
  "REQUIRED", "PATTERN", "DEFAULT", "MIN", "MAX", "ROWS", "COLS",
  "OPTIONS", "ACCEPT", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "LPAREN", "RPAREN", "SEMICOLON", "COMMA", "COLON", "EQUALS", "LT", "GT",
  "LE", "GE", "EQ", "NE", "IDENTIFIER", "STRING", "NUMBER", "BOOLEAN",
  "$accept", "program", "form", "form_body", "meta_list", "meta_stmt",
  "section_list", "section_stmt", "@1", "field_list", "field_stmt",
  "field_type", "attribute_list", "attribute", "string_list",
  "validate_block", "validation_rules", "validation_rule", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    52,    52,    52,    53,    53,
      54,    55,    55,    57,    56,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    65,    65,    66,    66,    66,
      66,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     2,     3,     1,     2,     0,     2,
       5,     1,     2,     0,     6,     1,     2,     6,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     3,     1,     3,     4,     1,     2,     9,     9,     9,
       9,     9,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     8,     0,     0,     0,
       6,    11,     0,     3,     0,     9,     4,     0,    12,     7,
      13,     0,     5,     0,     0,     0,     0,     0,    45,     0,
       0,    15,     0,     0,    44,    46,     0,    14,    16,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    30,     0,     0,
       0,     0,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    41,     0,     0,     0,     0,     0,     0,
      42,     0,    47,    48,    49,    50,    51,    52,    40,     0,
      43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    15,    10,    11,    24,    30,
      31,    63,    80,    81,   121,    19,    27,    28
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int8 yypact[] =
{
      10,   -23,    53,   -28,    25,   -28,    50,    11,    27,    47,
       9,   -28,    29,   -28,    14,   -28,     9,    32,   -28,   -28,
     -28,    22,   -28,    54,    57,    18,    20,    -7,   -28,    21,
      -6,   -28,    33,    -5,   -28,   -28,    30,   -28,   -28,   -28,
      23,    24,    26,    28,    34,    35,    31,    40,    43,    45,
      48,    49,    51,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -18,    67,    70,    74,    75,    76,    77,
     -28,    52,    55,    56,    58,    59,    60,    61,    62,   -28,
       5,   -28,    41,    42,    46,    63,    64,    65,    66,   -27,
      44,    68,    69,    71,    72,    73,   -28,   -28,    78,    79,
      82,    85,    86,    87,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,    80,   -28,    93,    94,    95,    97,    98,    99,
     -28,   -21,   -28,   -28,   -28,   -28,   -28,   -28,   -28,    84,
     -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,   -28,   -28,   -28,   -28,    92,     2,   -28,   -28,
     101,   -28,   -28,    15,   -28,    88,   -28,    81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      29,    26,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   128,    18,     1,     7,   129,    17,    79,    18,   105,
     106,   107,     4,    34,    37,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    40,    41,    42,    43,    44,    45,
      96,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    14,     7,     5,     6,     7,    12,    13,    20,    21,
      25,    23,    26,    29,    32,    33,    36,    46,    39,    64,
      47,    48,    65,    49,    66,    50,    82,    67,    68,    83,
      69,    51,    52,    84,    85,    86,    87,    98,    99,     0,
      88,   108,   100,    89,    90,    97,    91,    92,    93,    94,
      95,    16,     0,   112,    22,     0,     0,     0,    35,   101,
     102,   103,   104,   114,   115,   109,   110,   116,   111,   113,
     117,   118,   119,   122,   123,   124,   120,   125,   126,   127,
     130,    38
};

static const yytype_int8 yycheck[] =
{
       6,     8,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    32,    10,     3,     5,    36,     7,    35,    16,    46,
      47,    48,    45,    30,    30,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    39,    40,    41,    42,    43,    44,
      35,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     4,     5,     0,    29,     5,    45,    30,    29,    45,
      38,    29,     8,     6,    46,    45,    45,    37,    35,    29,
      47,    47,    29,    47,    29,    47,     9,    29,    29,     9,
      29,    47,    47,     9,     9,     9,     9,    46,    46,    -1,
      38,    47,    46,    38,    38,    80,    38,    38,    38,    38,
      38,     9,    -1,    31,    16,    -1,    -1,    -1,    27,    46,
      46,    46,    46,    35,    35,    47,    47,    35,    47,    46,
      35,    35,    35,    30,    30,    30,    46,    30,    30,    30,
      46,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    51,    45,     0,    29,     5,    52,    53,
      55,    56,    45,    30,     4,    54,    55,     7,    56,    64,
      29,    45,    64,    29,    57,    38,     8,    65,    66,     6,
      58,    59,    46,    45,    30,    66,    45,    30,    59,    35,
      39,    40,    41,    42,    43,    44,    37,    47,    47,    47,
      47,    47,    47,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    60,    29,    29,    29,    29,    29,    29,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    35,
      61,    62,     9,     9,     9,     9,     9,     9,    38,    38,
      38,    38,    38,    38,    38,    38,    35,    62,    46,    46,
      46,    46,    46,    46,    46,    46,    47,    48,    47,    47,
      47,    47,    31,    46,    35,    35,    35,    35,    35,    35,
      46,    63,    30,    30,    30,    30,    30,    30,    32,    36,
      46
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
#line 94 "parser.y"
    {
        generate_html();
        
    ;}
    break;

  case 3:
#line 101 "parser.y"
    {
        current_form.name = strdup((yyvsp[(2) - (5)].str));
        free((yyvsp[(2) - (5)].str));
    ;}
    break;

  case 10:
#line 120 "parser.y"
    {
        add_metadata((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
        free((yyvsp[(2) - (5)].str));
        free((yyvsp[(4) - (5)].str));
    ;}
    break;

  case 13:
#line 133 "parser.y"
    {
        add_section((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 17:
#line 145 "parser.y"
    {
        add_field((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].str));
        free((yyvsp[(2) - (6)].str));
        free((yyvsp[(4) - (6)].str));
    ;}
    break;

  case 18:
#line 150 "parser.y"
    {
        add_field((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
        free((yyvsp[(2) - (5)].str));
        free((yyvsp[(4) - (5)].str));
    ;}
    break;

  case 19:
#line 158 "parser.y"
    { (yyval.str) = strdup("text"); ;}
    break;

  case 20:
#line 159 "parser.y"
    { (yyval.str) = strdup("textarea"); ;}
    break;

  case 21:
#line 160 "parser.y"
    { (yyval.str) = strdup("number"); ;}
    break;

  case 22:
#line 161 "parser.y"
    { (yyval.str) = strdup("email"); ;}
    break;

  case 23:
#line 162 "parser.y"
    { (yyval.str) = strdup("date"); ;}
    break;

  case 24:
#line 163 "parser.y"
    { (yyval.str) = strdup("checkbox"); ;}
    break;

  case 25:
#line 164 "parser.y"
    { (yyval.str) = strdup("select"); ;}
    break;

  case 26:
#line 165 "parser.y"
    { (yyval.str) = strdup("radio"); ;}
    break;

  case 27:
#line 166 "parser.y"
    { (yyval.str) = strdup("password"); ;}
    break;

  case 28:
#line 167 "parser.y"
    { (yyval.str) = strdup("file"); ;}
    break;

  case 31:
#line 176 "parser.y"
    {
        add_attribute("required", "required");
    ;}
    break;

  case 32:
#line 179 "parser.y"
    {
        add_attribute("pattern", (yyvsp[(3) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 33:
#line 183 "parser.y"
    {
        add_attribute("value", (yyvsp[(3) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 34:
#line 187 "parser.y"
    {
        char buf[50];
        sprintf(buf, "%.0f", (yyvsp[(3) - (3)].num));
        add_attribute("value", buf);
    ;}
    break;

  case 35:
#line 192 "parser.y"
    {
        add_attribute("checked", (yyvsp[(3) - (3)].boolean) ? "checked" : "");
    ;}
    break;

  case 36:
#line 195 "parser.y"
    {
        char buf[50];
        sprintf(buf, "%.0f", (yyvsp[(3) - (3)].num));
        add_attribute("min", buf);
    ;}
    break;

  case 37:
#line 200 "parser.y"
    {
        char buf[50];
        sprintf(buf, "%.0f", (yyvsp[(3) - (3)].num));
        add_attribute("max", buf);
    ;}
    break;

  case 38:
#line 205 "parser.y"
    {
        char buf[50];
        sprintf(buf, "%.0f", (yyvsp[(3) - (3)].num));
        add_attribute("rows", buf);
    ;}
    break;

  case 39:
#line 210 "parser.y"
    {
        char buf[50];
        sprintf(buf, "%.0f", (yyvsp[(3) - (3)].num));
        add_attribute("cols", buf);
    ;}
    break;

  case 40:
#line 215 "parser.y"
    {
        add_attribute("options", (yyvsp[(4) - (5)].str));
        free((yyvsp[(4) - (5)].str));
    ;}
    break;

  case 41:
#line 219 "parser.y"
    {
        add_attribute("accept", (yyvsp[(3) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 42:
#line 226 "parser.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 43:
#line 230 "parser.y"
    {
        char *result = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 2);
        sprintf(result, "%s,%s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 47:
#line 249 "parser.y"
    {
        add_validation((yyvsp[(2) - (9)].str), "<", (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].str));
        free((yyvsp[(2) - (9)].str));
        free((yyvsp[(7) - (9)].str));
    ;}
    break;

  case 48:
#line 254 "parser.y"
    {
        add_validation((yyvsp[(2) - (9)].str), ">", (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].str));
        free((yyvsp[(2) - (9)].str));
        free((yyvsp[(7) - (9)].str));
    ;}
    break;

  case 49:
#line 259 "parser.y"
    {
        add_validation((yyvsp[(2) - (9)].str), "<=", (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].str));
        free((yyvsp[(2) - (9)].str));
        free((yyvsp[(7) - (9)].str));
    ;}
    break;

  case 50:
#line 264 "parser.y"
    {
        add_validation((yyvsp[(2) - (9)].str), ">=", (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].str));
        free((yyvsp[(2) - (9)].str));
        free((yyvsp[(7) - (9)].str));
    ;}
    break;

  case 51:
#line 269 "parser.y"
    {
        add_validation((yyvsp[(2) - (9)].str), "==", (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].str));
        free((yyvsp[(2) - (9)].str));
        free((yyvsp[(7) - (9)].str));
    ;}
    break;

  case 52:
#line 274 "parser.y"
    {
        add_validation((yyvsp[(2) - (9)].str), "!=", (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].str));
        free((yyvsp[(2) - (9)].str));
        free((yyvsp[(7) - (9)].str));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1847 "parser.tab.c"
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


#line 281 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Parse error at line %d: %s\n", line_num, s);
}

void add_metadata(char *key, char *value) {
    if (current_form.meta_count < 10) {
        current_form.metadata[current_form.meta_count].key = strdup(key);
        current_form.metadata[current_form.meta_count].value = strdup(strip_quotes(value));
        current_form.meta_count++;
    }
}

void add_section(char *name) {
    if (current_form.section_count < 20) {
        current_section.name = strdup(name);
        current_section.field_count = 0;
    }
}

void add_field(char *name, char *type) {
    if (current_section.field_count < 50) {
        current_field.name = strdup(name);
        current_field.type = strdup(type);
        current_field.attr_count = 0;
        
        // Add the field to current section
        current_section.fields[current_section.field_count] = current_field;
        current_section.field_count++;
        
        // Add section to form if this is the first field
        if (current_section.field_count == 1 || 
            current_form.section_count == 0 || 
            strcmp(current_form.sections[current_form.section_count-1].name, current_section.name) != 0) {
            current_form.sections[current_form.section_count] = current_section;
            current_form.section_count++;
        } else {
            // Update existing section
            current_form.sections[current_form.section_count-1] = current_section;
        }
    }
}

void add_attribute(char *name, char *value) {
    if (current_field.attr_count < 20) {
        current_field.attributes[current_field.attr_count].name = strdup(name);
        current_field.attributes[current_field.attr_count].value = strdup(value);
        current_field.attr_count++;
    }
}

void add_validation(char *field, char *op, double val, char *error) {
    if (current_form.validation_count < 10) {
        current_validation.field_name = strdup(field);
        current_validation.operator = strdup(op);
        current_validation.value = val;
        current_validation.error_msg = strdup(strip_quotes(error));
        current_form.validations[current_form.validation_count] = current_validation;
        current_form.validation_count++;
    }
}

char* strip_quotes(char *str) {
    if (str[0] == '"' && str[strlen(str)-1] == '"') {
        str[strlen(str)-1] = '\0';
        return str + 1;
    }
    return str;
}

void generate_html() {
    output_file = fopen("output.html", "w");
    if (!output_file) {
        fprintf(stderr, "Error: Cannot create output.html\n");
        return;
    }
    
    // HTML header
    fprintf(output_file, "<!DOCTYPE html>\n");
    fprintf(output_file, "<html lang=\"en\">\n");
    fprintf(output_file, "<head>\n");
    fprintf(output_file, "    <meta charset=\"UTF-8\">\n");
    fprintf(output_file, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(output_file, "    <title>%s</title>\n", current_form.name);
    fprintf(output_file, "    <style>\n");
    fprintf(output_file, "        body { font-family: Arial, sans-serif; max-width: 600px; margin: 0 auto; padding: 20px; }\n");
    fprintf(output_file, "        .section { margin-bottom: 30px; padding: 20px; border: 1px solid #ddd; border-radius: 5px; }\n");
    fprintf(output_file, "        .section h2 { margin-top: 0; color: #333; }\n");
    fprintf(output_file, "        .field { margin-bottom: 15px; }\n");
    fprintf(output_file, "        label { display: block; margin-bottom: 5px; font-weight: bold; }\n");
    fprintf(output_file, "        input, textarea, select { width: 100%%; padding: 8px; border: 1px solid #ccc; border-radius: 4px; box-sizing: border-box; }\n");
    fprintf(output_file, "        input[type=\"checkbox\"], input[type=\"radio\"] { width: auto; margin-right: 5px; }\n");
    fprintf(output_file, "        .radio-group { margin-top: 5px; }\n");
    fprintf(output_file, "        .radio-option { margin-bottom: 5px; }\n");
    fprintf(output_file, "        .error { color: red; font-size: 0.9em; margin-top: 5px; }\n");
    fprintf(output_file, "    </style>\n");
    fprintf(output_file, "</head>\n");
    fprintf(output_file, "<body>\n");
    
    // Form metadata as comments
    for (int i = 0; i < current_form.meta_count; i++) {
        fprintf(output_file, "<!-- %s: %s -->\n", 
                current_form.metadata[i].key, current_form.metadata[i].value);
    }
    
    fprintf(output_file, "    <h1>%s</h1>\n", current_form.name);
    fprintf(output_file, "    <form name=\"%s\" id=\"%s\">\n", current_form.name, current_form.name);
    
    // Generate sections and fields
    for (int i = 0; i < current_form.section_count; i++) {
        Section sec = current_form.sections[i];
        fprintf(output_file, "        <div class=\"section\">\n");
        fprintf(output_file, "            <h2>%s</h2>\n", sec.name);

        for (int j = 0; j < sec.field_count; j++) {
            Field field = sec.fields[j];
            fprintf(output_file, "            <div class=\"field\">\n");

            if (strcmp(field.type, "radio") == 0) {
                // Handle radio buttons
                fprintf(output_file, "                <label>%s:</label>\n", field.name);
                fprintf(output_file, "                <div class=\"radio-group\">\n");
                // Find options attribute
                char *options = NULL;
                for (int k = 0; k < field.attr_count; k++) {
                    if (strcmp(field.attributes[k].name, "options") == 0) {
                        options = field.attributes[k].value;
                        break;
                    }
                }
                if (options) {
                    char *opt_copy = strdup(options);
                    char *token = strtok(opt_copy, ",");
                    while (token) {
                        char *clean_token = strip_quotes(token);
                        fprintf(output_file, "                    <div class=\"radio-option\">\n");
                        fprintf(output_file, "                        <input type=\"radio\" name=\"%s\" value=\"%s\" id=\"%s_%s\">\n", 
                                field.name, clean_token, field.name, clean_token);
                        fprintf(output_file, "                        <label for=\"%s_%s\">%s</label>\n", 
                                field.name, clean_token, clean_token);
                        fprintf(output_file, "                    </div>\n");
                        token = strtok(NULL, ",");
                    }
                    free(opt_copy);
                }
                fprintf(output_file, "                </div>\n");

            } else if (strcmp(field.type, "checkbox") == 0) {
                // Handle checkbox
                fprintf(output_file, "                <label>\n");
                fprintf(output_file, "                    <input type=\"checkbox\" name=\"%s\"", field.name);
                // Add attributes
                for (int k = 0; k < field.attr_count; k++) {
                    if (strcmp(field.attributes[k].name, "checked") == 0 && 
                        strlen(field.attributes[k].value) > 0) {
                        fprintf(output_file, " checked");
                    }
                }
                fprintf(output_file, ">\n");
                fprintf(output_file, "                    %s\n", field.name);
                fprintf(output_file, "                </label>\n");

            } else if (strcmp(field.type, "textarea") == 0) {
                // Handle textarea
                fprintf(output_file, "                <label for=\"%s\">%s:</label>\n", field.name, field.name);
                fprintf(output_file, "                <textarea name=\"%s\" id=\"%s\"", field.name, field.name);
                // Add attributes
                for (int k = 0; k < field.attr_count; k++) {
                    if (strcmp(field.attributes[k].name, "value") != 0) {
                        fprintf(output_file, " %s=\"%s\"", 
                                field.attributes[k].name, field.attributes[k].value);
                    }
                }
                fprintf(output_file, ">");
                // Add default value inside textarea
                for (int k = 0; k < field.attr_count; k++) {
                    if (strcmp(field.attributes[k].name, "value") == 0) {
                        fprintf(output_file, "%s", field.attributes[k].value);
                        break;
                    }
                }
                fprintf(output_file, "</textarea>\n");

            } else if (strcmp(field.type, "select") == 0) {
                // Handle dropdown/select
                fprintf(output_file, "                <label for=\"%s\">%s:</label>\n", field.name, field.name);
                fprintf(output_file, "                <select name=\"%s\" id=\"%s\">\n", field.name, field.name);
                char *options = NULL;
                for (int k = 0; k < field.attr_count; k++) {
                    if (strcmp(field.attributes[k].name, "options") == 0) {
                        options = field.attributes[k].value;
                        break;
                    }
                }
                if (options) {
                    char *opt_copy = strdup(options);
                    char *token = strtok(opt_copy, ",");
                    while (token) {
                        char *clean_token = strip_quotes(token); // remove quotes and whitespace
                        fprintf(output_file, "                    <option value=\"%s\">%s</option>\n", clean_token, clean_token);
                        token = strtok(NULL, ",");
                    }
                    free(opt_copy);
                }
                fprintf(output_file, "                </select>\n");

            } else {
                // Handle regular input fields
                fprintf(output_file, "                <label for=\"%s\">%s:</label>\n", field.name, field.name);
                fprintf(output_file, "                <input type=\"%s\" name=\"%s\" id=\"%s\"", 
                        field.type, field.name, field.name);
                // Add attributes
                for (int k = 0; k < field.attr_count; k++) {
                    if (strcmp(field.attributes[k].name, "options") != 0) {
                        fprintf(output_file, " %s=\"%s\"", 
                                field.attributes[k].name, field.attributes[k].value);
                    }
                }
                fprintf(output_file, ">\n");
            }

            fprintf(output_file, "            </div>\n");
        }

        fprintf(output_file, "        </div>\n");
    }

    fprintf(output_file, "        <button type=\"submit\">Submit</button>\n");
    fprintf(output_file, "    </form>\n");
    
    // Add JavaScript validation if needed
    if (current_form.validation_count > 0) {
        fprintf(output_file, "    <script>\n");
        fprintf(output_file, "        document.getElementById('%s').addEventListener('submit', function(e) {\n", current_form.name);
        fprintf(output_file, "            let isValid = true;\n");
        fprintf(output_file, "            let errors = [];\n");
        
        for (int i = 0; i < current_form.validation_count; i++) {
            ValidationRule rule = current_form.validations[i];
            fprintf(output_file, "            let %s = parseFloat(document.getElementById('%s').value);\n", 
                    rule.field_name, rule.field_name);
            fprintf(output_file, "            if (%s %s %.0f) {\n", 
                    rule.field_name, rule.operator, rule.value);
            fprintf(output_file, "                errors.push('%s');\n", rule.error_msg);
            fprintf(output_file, "                isValid = false;\n");
            fprintf(output_file, "            }\n");
        }
        
        fprintf(output_file, "            if (!isValid) {\n");
        fprintf(output_file, "                e.preventDefault();\n");
        fprintf(output_file, "                alert('Validation errors:\\n' + errors.join('\\n'));\n");
        fprintf(output_file, "            }\n");
        fprintf(output_file, "        });\n");
        fprintf(output_file, "    </script>\n");
    }
    
    fprintf(output_file, "</body>\n");
    fprintf(output_file, "</html>\n");
    
    fclose(output_file);
}

int main() {
    // Initialize form structure
    current_form.name = NULL;
    current_form.meta_count = 0;
    current_form.section_count = 0;
    current_form.validation_count = 0;
    
    
    int result = yyparse();
    
    if (result == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing failed with errors.\n");
        return 1;
    }
    
    return 0;
}
