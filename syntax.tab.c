
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables globales pour la gestion des erreurs
int nb_ligne = 1;
int col = 1;

// Déclaration de la fonction d'erreur
void yyerror(const char *msg);


/* Line 189 of yacc.c  */
#line 87 "syntax.tab.c"

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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 17 "syntax.y"

    struct entite {
        char *nom;
        int isFloat;
        int isTableau;
        char valeur[10];
        int index;
        struct entite* suivant;
    };

    struct tableau {
        int tableau;
        int index;
    };

    struct constante {
        int isFloat;
        char valeur[10];
    };



/* Line 209 of yacc.c  */
#line 134 "syntax.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_import = 258,
     mc_io = 259,
     mc_lang = 260,
     mc_isil = 261,
     mc_programme = 262,
     mc_debut = 263,
     mc_dec = 264,
     mc_fin = 265,
     mc_final = 266,
     mc_int = 267,
     mc_float = 268,
     point = 269,
     pvg = 270,
     vg = 271,
     separateur = 272,
     crochet_ouv = 273,
     crochet_fer = 274,
     parenthese_ouv = 275,
     parenthese_fer = 276,
     aff = 277,
     oper_initialisation = 278,
     double_quote = 279,
     sym_mul = 280,
     sym_div = 281,
     sym_plus = 282,
     sym_moins = 283,
     mc_for = 284,
     mc_do = 285,
     mc_endfor = 286,
     mc_if = 287,
     mc_endif = 288,
     mc_else = 289,
     mc_input = 290,
     mc_write = 291,
     idf = 292,
     cst_entier = 293,
     cst_reel = 294,
     oper_et = 295,
     oper_ou = 296,
     oper_negation = 297,
     oper_sup_egal = 298,
     oper_inf_egal = 299,
     oper_sup = 300,
     oper_inf = 301,
     oper_inegalite = 302,
     oper_egalite = 303,
     signe_formattage_entier = 304,
     signe_formattage_reel = 305,
     err = 306,
     chaine_caractere = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 38 "syntax.y"

    int entier;
    float real;
    char* str;
    // definir un nouveau type complexe (struct)
    struct entite entite;
    struct tableau tableau;
    struct constante constante;



/* Line 214 of yacc.c  */
#line 215 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 227 "syntax.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    13,    14,    16,    18,    24,    27,
      30,    31,    35,    39,    41,    44,    48,    51,    52,    57,
      59,    63,    67,    69,    71,    73,    75,    80,    83,    84,
      86,    88,    90,    92,    97,   101,   105,   107,   111,   115,
     117,   121,   123,   125,   128,   132,   133,   141,   147,   151,
     155,   157,   161,   163,   167,   172,   174,   178,   182,   186,
     190,   194,   198,   200,   202,   204,   208,   216,   226,   229,
     232,   241,   249,   253,   254,   256
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    57,    -1,     3,     6,    14,    56,
      15,    55,    -1,    -1,     5,    -1,     4,    -1,     7,    37,
       9,    58,    68,    -1,    59,    58,    -1,    63,    58,    -1,
      -1,    67,    60,    15,    -1,    61,    17,    60,    -1,    61,
      -1,    37,    62,    -1,    18,    38,    19,    -1,    23,    66,
      -1,    -1,    11,    67,    64,    15,    -1,    65,    -1,    65,
      17,    64,    -1,    37,    23,    66,    -1,    38,    -1,    39,
      -1,    13,    -1,    12,    -1,     8,    69,    10,    14,    -1,
      70,    69,    -1,    -1,    71,    -1,    77,    -1,    86,    -1,
      87,    -1,    75,    22,    72,    15,    -1,    73,    27,    72,
      -1,    73,    28,    72,    -1,    73,    -1,    74,    25,    73,
      -1,    74,    26,    73,    -1,    74,    -1,    20,    72,    21,
      -1,    66,    -1,    75,    -1,    37,    76,    -1,    18,    38,
      19,    -1,    -1,    29,    20,    78,    21,    30,    69,    31,
      -1,    79,    15,    80,    15,    85,    -1,    37,    22,    72,
      -1,    81,    41,    80,    -1,    81,    -1,    82,    40,    81,
      -1,    82,    -1,    20,    80,    21,    -1,    42,    20,    80,
      21,    -1,    83,    -1,    84,    46,    83,    -1,    84,    44,
      83,    -1,    84,    45,    83,    -1,    84,    43,    83,    -1,
      84,    48,    83,    -1,    84,    47,    83,    -1,    84,    -1,
      37,    -1,    66,    -1,    37,    27,    27,    -1,    32,    20,
      80,    21,    30,    69,    33,    -1,    32,    20,    80,    21,
      30,    69,    34,    69,    33,    -1,    88,    15,    -1,    89,
      15,    -1,    35,    20,    24,    91,    24,    16,    37,    21,
      -1,    36,    20,    24,    52,    24,    90,    21,    -1,    16,
      37,    90,    -1,    -1,    49,    -1,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    70,    70,    74,    75,    79,    84,    85,
      85,    90,   147,   151,   162,   175,   181,   186,   196,   222,
     232,   236,   245,   249,   256,   257,   261,   262,   262,   266,
     267,   268,   269,   271,   328,   341,   354,   360,   373,   392,
     398,   402,   406,   411,   455,   459,   463,   465,   467,   469,
     470,   473,   474,   477,   478,   479,   482,   483,   484,   485,
     486,   487,   488,   491,   492,   495,   498,   499,   502,   503,
     505,   507,   509,   509,   512,   512
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_import", "mc_io", "mc_lang",
  "mc_isil", "mc_programme", "mc_debut", "mc_dec", "mc_fin", "mc_final",
  "mc_int", "mc_float", "point", "pvg", "vg", "separateur", "crochet_ouv",
  "crochet_fer", "parenthese_ouv", "parenthese_fer", "aff",
  "oper_initialisation", "double_quote", "sym_mul", "sym_div", "sym_plus",
  "sym_moins", "mc_for", "mc_do", "mc_endfor", "mc_if", "mc_endif",
  "mc_else", "mc_input", "mc_write", "idf", "cst_entier", "cst_reel",
  "oper_et", "oper_ou", "oper_negation", "oper_sup_egal", "oper_inf_egal",
  "oper_sup", "oper_inf", "oper_inegalite", "oper_egalite",
  "signe_formattage_entier", "signe_formattage_reel", "err",
  "chaine_caractere", "$accept", "S", "Block_LIB", "NOM_BIB", "Block_Prog",
  "Block_DEC", "Block_DEC_Var", "List_Idf_V_T", "V_T", "B",
  "Block_DEC_Const", "LIST_AFF", "Affect_FINALE", "CST_TYPE", "Type",
  "PARTIE_INTRUCTIONS", "BLOC_INSTRUCTIONS", "INSTRUCTION",
  "INSTRUCTION_AFFECTATION", "EXPRESSION_ARITHMETIQUE", "EXPRESSION_1",
  "EXPRESSION_2", "VARIABLE", "SUITE_IDF", "INSTRUCTION_FOR",
  "PARAMETRE_BOUCLE", "INITIALISATION_COMPTEUR", "CONDITION", "CONDITION1",
  "CONDITION2", "COMPARAISON", "COMPARAISON1", "INCREMENTATION_COMPTEUR",
  "INSTRUCTION_IF", "INSTRUCTION_ENTREE_SORTIE", "INSTRUCTION_ENTREE",
  "INSTRUCTION_SORTIE", "IDF_WRITE", "SIGNE_FORMATTAGE", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    58,    58,
      58,    59,    60,    60,    61,    62,    62,    62,    63,    64,
      64,    65,    66,    66,    67,    67,    68,    69,    69,    70,
      70,    70,    70,    71,    72,    72,    72,    73,    73,    73,
      74,    74,    74,    75,    76,    76,    77,    78,    79,    80,
      80,    81,    81,    82,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    86,    86,    87,    87,
      88,    89,    90,    90,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     6,     0,     1,     1,     5,     2,     2,
       0,     3,     3,     1,     2,     3,     2,     0,     4,     1,
       3,     3,     1,     1,     1,     1,     4,     2,     0,     1,
       1,     1,     1,     4,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     2,     3,     0,     7,     5,     3,     3,
       1,     3,     1,     3,     4,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     7,     9,     2,     2,
       8,     7,     3,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       6,     5,     0,    10,     4,     0,    25,    24,     0,    10,
      10,     0,     3,     0,    28,     7,     8,     9,    17,     0,
      13,     0,     0,    19,     0,     0,     0,     0,    45,     0,
      28,    29,     0,    30,    31,    32,     0,     0,     0,     0,
      14,    11,     0,     0,    18,     0,     0,     0,     0,     0,
       0,    43,     0,    27,     0,    68,    69,     0,    22,    23,
      16,    12,    21,    20,     0,     0,     0,     0,    63,     0,
      64,     0,    50,    52,    55,    62,     0,     0,     0,    26,
       0,    41,     0,    36,    39,    42,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,     0,     0,    44,     0,    33,     0,     0,
       0,     0,    48,    28,     0,    53,     0,    28,    49,    51,
      59,    57,    58,    56,    61,    60,     0,    73,    40,    34,
      35,    37,    38,     0,     0,    54,     0,     0,     0,     0,
      46,     0,    47,    66,    28,     0,    73,    71,     0,     0,
      70,    72,    65,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    12,     7,    18,    19,    29,    30,    50,
      20,    32,    33,    80,    21,    25,    39,    40,    41,    92,
      93,    94,    95,    61,    43,    75,    76,    81,    82,    83,
      84,    85,   152,    44,    45,    46,    47,   149,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int8 yypact[] =
{
      22,     5,    29,    35,    33,   -88,    41,   -88,     4,    68,
     -88,   -88,    64,     2,    22,    21,   -88,   -88,    72,     2,
       2,    44,   -88,    45,     9,   -88,   -88,   -88,   -11,    70,
      66,    63,    74,    73,    67,    71,    75,    76,    79,    82,
       9,   -88,    78,   -88,   -88,   -88,    83,    86,    55,     1,
     -88,   -88,    44,     1,   -88,    45,    57,   -15,    80,    81,
      69,   -88,    88,   -88,    -2,   -88,   -88,    87,   -88,   -88,
     -88,   -88,   -88,   -88,    89,    91,    93,   -15,   -88,    90,
     -88,    92,    77,    84,   -88,     8,    -1,    62,    97,   -88,
      -2,   -88,    94,    36,    40,   -88,   -88,    -2,    95,   -15,
      96,   -15,    98,   -15,   -15,   -18,   -18,   -18,   -18,   -18,
     -18,   -88,   -88,    99,   102,   -88,   100,   -88,    -2,    -2,
      -2,    -2,   -88,     9,   104,   -88,   101,     9,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   111,   113,   -88,   -88,
     -88,   -88,   -88,   103,   105,   -88,    34,   106,   107,   110,
     -88,   108,   -88,   -88,     9,   112,   113,   -88,   109,   114,
     -88,   -88,   -88,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   118,   -88,   -88,    50,   -88,    85,   -88,   -88,
     -88,    65,   -88,   -47,   123,   -88,   -39,   -88,   -88,   -87,
     -45,   -88,   -24,   -88,   -88,   -88,   -88,   -73,    37,   -88,
     -48,   -88,   -88,   -88,   -88,   -88,   -88,   -17,   -88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      42,    63,    70,   116,   100,    77,    72,    48,    10,    11,
     122,     4,    49,    15,    16,    17,    42,    91,    90,    78,
      68,    69,    78,    68,    69,     1,   124,    79,   126,     5,
     128,   139,   140,    16,    17,    38,    68,    69,    34,    68,
      69,    35,     6,    91,    36,    37,    38,     8,   111,   112,
      91,   105,   106,   107,   108,   109,   110,   130,   131,   132,
     133,   134,   135,   118,   119,   120,   121,   153,   154,    26,
      27,    91,    91,    91,    91,   141,   142,    13,     9,    14,
      24,    28,    31,    52,   143,    51,    53,    56,   146,    54,
      55,    57,    62,    67,    74,    58,    59,    60,    65,    42,
      64,    66,    89,    42,    86,    87,    96,    88,    99,   117,
     101,    97,    98,   102,   114,   159,   115,   125,   103,   144,
      73,   138,   145,   136,   104,   123,   137,   147,   127,   148,
      42,   157,    22,   160,   150,   158,   162,    71,    23,   161,
       0,   129,   151,   155,   156,     0,     0,   163
};

static const yytype_int16 yycheck[] =
{
      24,    40,    49,    90,    77,    20,    53,    18,     4,     5,
      97,     6,    23,    11,    12,    13,    40,    64,    20,    37,
      38,    39,    37,    38,    39,     3,    99,    42,   101,     0,
     103,   118,   119,    12,    13,    37,    38,    39,    29,    38,
      39,    32,     7,    90,    35,    36,    37,    14,    49,    50,
      97,    43,    44,    45,    46,    47,    48,   105,   106,   107,
     108,   109,   110,    27,    28,    25,    26,    33,    34,    19,
      20,   118,   119,   120,   121,   120,   121,     9,    37,    15,
       8,    37,    37,    17,   123,    15,    23,    20,   127,    15,
      17,    20,    10,    38,    37,    20,    20,    18,    15,   123,
      22,    15,    14,   127,    24,    24,    19,    38,    15,    15,
      20,    22,    21,    21,    52,   154,    19,    21,    41,    15,
      55,    21,    21,    24,    40,    30,    24,    16,    30,    16,
     154,    21,    14,    21,    31,    27,    27,    52,    15,   156,
      -1,   104,    37,    37,    37,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,     6,     0,     7,    57,    14,    37,
       4,     5,    56,     9,    15,    11,    12,    13,    58,    59,
      63,    67,    55,    67,     8,    68,    58,    58,    37,    60,
      61,    37,    64,    65,    29,    32,    35,    36,    37,    69,
      70,    71,    75,    77,    86,    87,    88,    89,    18,    23,
      62,    15,    17,    23,    15,    17,    20,    20,    20,    20,
      18,    76,    10,    69,    22,    15,    15,    38,    38,    39,
      66,    60,    66,    64,    37,    78,    79,    20,    37,    42,
      66,    80,    81,    82,    83,    84,    24,    24,    38,    14,
      20,    66,    72,    73,    74,    75,    19,    22,    21,    15,
      80,    20,    21,    41,    40,    43,    44,    45,    46,    47,
      48,    49,    50,    91,    52,    19,    72,    15,    27,    28,
      25,    26,    72,    30,    80,    21,    80,    30,    80,    81,
      83,    83,    83,    83,    83,    83,    24,    24,    21,    72,
      72,    73,    73,    69,    15,    21,    69,    16,    16,    90,
      31,    37,    85,    33,    34,    37,    37,    21,    27,    69,
      21,    90,    27,    33
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 66 "syntax.y"
    { printf("Programme Correcte.\n"); YYACCEPT; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 90 "syntax.y"
    {
    // garder l'@ du premier identificateur apres le mot cle du type
    struct entite* ptr = &((yyvsp[(2) - (3)].entite));

    // parcourir la liste des identificateur declares
    while (ptr != NULL) {
        
        //verifier l'incompatibilite de type en cas d'affectation d'une valeur initiale
        // si isFloat = -1 alors il n'y a pas une affectation
        if ((ptr->isFloat != -1) && (ptr->isFloat != (yyvsp[(1) - (3)].entier))) {

            char *typeAttendu = ((yyvsp[(1) - (3)].entier)) ? "Float" : "Integer";
            printf("Erreur sémantique : type incompatible pour '%s'. Attendu '%s'.\n", ptr->nom, typeAttendu);
            YYABORT;
        }

        // verifier si l'idf est un tableau
        if (ptr->isTableau) {
            char taille[10]; // convertir la taille du tableau (index) en une chaine de caracteres
            sprintf(taille, "%d", ptr->index);

            // l'inserer dans la table des tableaux
            int status = remplir_variable(ptr->nom, "identificateur", (yyvsp[(1) - (3)].entier), taille, 0, 1);

            // verifier s'il est deja declare
            if (status == 0) {
                YYABORT;
            }
        } 
        // la variable est simple idf
        else {
            // verifier si aucune valeur est affecte a l'idf
            if (strcmp(ptr->valeur, " ") == 0) {
                // l'inserer dans la table des variables sans valeur
                int status = remplir_variable(ptr->nom, "identificateur", ptr->isFloat, NULL, 0, 0);

                // verifier s'il est deja declare
                if (status == 0) {
                    YYABORT;
                }
            }
            // une valeur initiale est affectee a l'idf
            else {
                //printf("%s tableau %d valeur %s\n", ptr->nom, ptr->isTableau, ptr->valeur);
                int status = remplir_variable(ptr->nom, "identificateur", ptr->isFloat, ptr->valeur, 0, 0);

                // verifier s'il est deja declare
                if (status == 0) {
                    YYABORT;
                }
            }
        }
        ptr = ptr->suivant;
    }
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 147 "syntax.y"
    {
        // creer le chainage
        (yyval.entite).suivant = &(yyvsp[(3) - (3)].entite);
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 151 "syntax.y"
    {
        // copier les infos necessaire
        // si l'idf est le dernier dans la liste de declaration ou il est tout seul
        (yyval.entite).nom = strdup((yyvsp[(1) - (1)].entite).nom);
        (yyval.entite).isFloat = (yyvsp[(1) - (1)].entite).isFloat;
        (yyval.entite).isTableau = (yyvsp[(1) - (1)].entite).isTableau;
        (yyval.entite).index = (yyvsp[(1) - (1)].entite).index;
        strcpy((yyval.entite).valeur, (yyvsp[(1) - (1)].entite).valeur);
        (yyval.entite).suivant = NULL;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 162 "syntax.y"
    {
    // copier le nom de l'entite
    (yyval.entite).nom = strdup((yyvsp[(1) - (2)].str));

    // copier les champs necessaires
    (yyval.entite).isFloat = (yyvsp[(2) - (2)].entite).isFloat;
    (yyval.entite).isTableau = (yyvsp[(2) - (2)].entite).isTableau;
    (yyval.entite).index = (yyvsp[(2) - (2)].entite).index;
    strcpy((yyval.entite).valeur, (yyvsp[(2) - (2)].entite).valeur);
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 175 "syntax.y"
    {
        // cas de declaration d'un tableau
        (yyval.entite).isTableau = 1;
        (yyval.entite).index = (yyvsp[(2) - (3)].entier);
        (yyval.entite).isFloat = -1;
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 181 "syntax.y"
    {
        // cas d'initialisation d'une variable simple
        (yyval.entite).isFloat = (yyvsp[(2) - (2)].constante).isFloat;
        (yyval.entite).isTableau = 0;
        strcpy((yyval.entite).valeur, (yyvsp[(2) - (2)].constante).valeur);
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 186 "syntax.y"
    {
        // cas d'une declaration sans initialisation
        (yyval.entite).isTableau = 0;
        (yyval.entite).isFloat = -1; // la valeur de la variable n'est pas initialiser encore
            // -1 veut dire qu'on n'a pas besoin de comparer le type de la variable
        strcpy((yyval.entite).valeur, " "); // 
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 196 "syntax.y"
    {
    // garder l'@ du premier identificateur apres le mot cle du type
    struct entite* ptr = &((yyvsp[(3) - (4)].entite));

    while (ptr != NULL) {
        // comparer la valeur recue et le type declare
        if ((yyvsp[(2) - (4)].entier) != ptr->isFloat) {
            
            // incompatible
            char *typeAttendu = ((yyvsp[(2) - (4)].entier)) ? "Float" : "Integer";
            printf("Erreur sémantique : type incompatible pour '%s'. Attendu '%s'.\n", ptr->nom, typeAttendu);
            YYABORT;
        }else {
            int status = remplir_variable(ptr->nom, "identificateur", ptr->isFloat, ptr->valeur, 1, 0);

            // verifier s'il est deja declare
            if (status == 0) {
                YYABORT;
            }
        }

        ptr = ptr->suivant;
    }
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 222 "syntax.y"
    {
        // copier les infos necessaire
        // si l'idf est le dernier dans la liste de declaration ou il est tout seul
        (yyval.entite).nom = strdup((yyvsp[(1) - (1)].entite).nom);
        (yyval.entite).isFloat = (yyvsp[(1) - (1)].entite).isFloat;
        (yyval.entite).isTableau = (yyvsp[(1) - (1)].entite).isTableau;
        (yyval.entite).index = (yyvsp[(1) - (1)].entite).index;
        strcpy((yyval.entite).valeur, (yyvsp[(1) - (1)].entite).valeur);
        (yyval.entite).suivant = NULL;
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 232 "syntax.y"
    {
        (yyval.entite).suivant = &(yyvsp[(3) - (3)].entite);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 236 "syntax.y"
    {
    (yyval.entite).nom = (yyvsp[(1) - (3)].str);
    
    (yyval.entite).isFloat = (yyvsp[(3) - (3)].constante).isFloat;
    (yyval.entite).isTableau = 0;
    strcpy((yyval.entite).valeur, (yyvsp[(3) - (3)].constante).valeur);
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 245 "syntax.y"
    {
        (yyval.constante).isFloat = 0;
        sprintf((yyval.constante).valeur, "%d", (yyvsp[(1) - (1)].entier)); // copier la valeur entiere dans une chaine de caractere
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 249 "syntax.y"
    {
        (yyval.constante).isFloat = 1;
        gcvt((yyvsp[(1) - (1)].real), 10, (yyval.constante).valeur); // copier la valeur reel dans une chaine de caractere
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 256 "syntax.y"
    {(yyval.entier) = 1;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 257 "syntax.y"
    {(yyval.entier) = 0;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 271 "syntax.y"
    {
    char error[20];

    // verifier si l'identificateur est une constante
    int type = verifier_modification_const((yyvsp[(1) - (4)].entite).nom);

    if (type == -1) {
        sprintf(error, "Modification de la taille d'une constante %s", (yyvsp[(1) - (4)].entite));
        yyerror(error);
        YYABORT;
    }

    // verifier la non compatibilite de type
    if (type != (yyvsp[(3) - (4)].constante).isFloat) {
        char* typeAttendu = type ? "Float" : "Integer";
        char* typeRecu = (yyvsp[(3) - (4)].constante).isFloat ? "Float" : "Integer";

        sprintf(error, "Non compatibilite de type, type attendu (l'identificateur %s): %s, type recu: %s", (yyvsp[(1) - (4)].entite).nom, typeAttendu, typeRecu);
        yyerror(error);
        YYABORT;
    }
    /*
    int taille;
    // si l'entite est un tableau
    if ($2.tableau) {
        // verifier le depassement de la taille
        taille = verifier_taille_tableau($1, $2.index);

        // traitement des erreurs semantiques
        if (taille == -1) {
            sprintf(error, "Depassement de la taille du tableau %s", $1);
            yyerror(error);
            YYABORT;
        } else if (taille == -2) {
            sprintf(error, "Variable %s n'est pas un tableau", $1);
            yyerror(error);
            YYABORT;
        }
    } else {
        taille = verifier_modification_const($1);

        // traitements des erreurs semantiques
        if (taille == -2) {
            sprintf(error, "Variable %s est un tableau", $1);
            yyerror(error);
            YYABORT;
        }
        if (taille == -1) {
            sprintf(error, "Modification de la taille d'une constante %s", $1);
            yyerror(error);
            YYABORT;
        }
    }
    */
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 328 "syntax.y"
    {
        // verifier la non-compatibilite de type
        char error[20];

        if ((yyvsp[(1) - (3)].constante).isFloat != (yyvsp[(3) - (3)].constante).isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", (yyvsp[(2) - (3)].str));
            yyerror(error);
            YYABORT;
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (3)].constante).isFloat; // passer la valeur au non-terminale suivant
        strcpy((yyval.constante).valeur, "1");
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 341 "syntax.y"
    {
        // verifier la non-compatibilite de type
        char error[20];

        if ((yyvsp[(1) - (3)].constante).isFloat != (yyvsp[(3) - (3)].constante).isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", (yyvsp[(2) - (3)].str));
            yyerror(error);
            YYABORT;
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (3)].constante).isFloat; // passer la valeur au non-terminale suivant
        strcpy((yyval.constante).valeur, "1");
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 354 "syntax.y"
    {
        (yyval.constante).isFloat = (yyvsp[(1) - (1)].constante).isFloat;
        strcpy((yyval.constante).valeur, (yyvsp[(1) - (1)].constante).valeur);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 360 "syntax.y"
    {
        // verifier la non-compatibilite de type
        char error[20];

        if ((yyvsp[(1) - (3)].constante).isFloat != (yyvsp[(3) - (3)].constante).isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", (yyvsp[(2) - (3)].str));
            yyerror(error);
            YYABORT;
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (3)].constante).isFloat; // passer la valeur au non-terminale suivant
        strcpy((yyval.constante).valeur, "1");
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 373 "syntax.y"
    {
        // verifier la non-compatibilite de type
        char error[20];

        if ((yyvsp[(1) - (3)].constante).isFloat != (yyvsp[(3) - (3)].constante).isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", (yyvsp[(2) - (3)].str));
            yyerror(error);
            YYABORT;
        }

        // division par zero
        if (strcmp((yyvsp[(3) - (3)].constante).valeur, "0") == 0) {
            yyerror("Division par 0");
            YYABORT;            
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (3)].constante).isFloat; // passer la valeur au non-terminale suivant
        strcpy((yyval.constante).valeur, "1");
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 392 "syntax.y"
    {
        (yyval.constante).isFloat = (yyvsp[(1) - (1)].constante).isFloat;
        strcpy((yyval.constante).valeur, (yyvsp[(1) - (1)].constante).valeur);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 398 "syntax.y"
    {
        (yyval.constante).isFloat = (yyvsp[(2) - (3)].constante).isFloat;
        strcpy((yyval.constante).valeur, (yyvsp[(2) - (3)].constante).valeur);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 402 "syntax.y"
    {
        (yyval.constante).isFloat = (yyvsp[(1) - (1)].constante).isFloat; // copier le type de la constante
        strcpy((yyval.constante).valeur, (yyvsp[(1) - (1)].constante).valeur); // copier la valeur de la constante
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 406 "syntax.y"
    {
        (yyval.constante).isFloat = (yyvsp[(1) - (1)].entite).isFloat; // copier le type de la variable Integer ou Float
        strcpy((yyval.constante).valeur, "1"); // on suppose que la valeur de la variable ne nous concerne pas si elle est egale a 0
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 411 "syntax.y"
    {
    char error[30];
    // non declaration
    if (verifier_non_declaration((yyvsp[(1) - (2)].str))) {
        sprintf(error, "Non declaration de l'identificateur %s", (yyvsp[(1) - (2)].str));
        yyerror(error);
        YYABORT;
    };

    strcpy((yyval.entite).nom, (yyvsp[(1) - (2)].str));
    int taille;
    // si l'entite est un tableau
    if ((yyvsp[(2) - (2)].tableau).tableau) {
        // verifier le depassement de la taille
        taille = verifier_taille_tableau((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].tableau).index);

        // traitement des erreurs semantiques
        if (taille == -1) {
            sprintf(error, "Depassement de la taille du tableau %s", (yyvsp[(1) - (2)].str));
            yyerror(error);
            YYABORT;
        } else if (taille == -2) {
            sprintf(error, "Variable %s n'est pas un tableau", (yyvsp[(1) - (2)].str));
            yyerror(error);
            YYABORT;
        }

        (yyval.entite).isFloat = taille;
        printf("isFloat : %d\n", taille);
    } else {
        taille = verifier_modification_const((yyvsp[(1) - (2)].str));

        // verifier si l'identificateur est un tableau
        if (verifier_si_tableau((yyvsp[(1) - (2)].str))) {
            sprintf(error, "Variable %s est un tableau", (yyvsp[(1) - (2)].str));
            yyerror(error);
            YYABORT;
        }

        (yyval.entite).isFloat = type_identificateur((yyvsp[(1) - (2)].str));
    }
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 455 "syntax.y"
    {
        (yyval.tableau).tableau = 1; // mettre tableau a vrai
        (yyval.tableau).index = (yyvsp[(2) - (3)].entier); // remplir la taille du tableau
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 459 "syntax.y"
    {
        (yyval.tableau).tableau = 0; // mettre tableau a faux
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2076 "syntax.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 513 "syntax.y"


int main() {
    yyparse();
    // afficher_table_separateur_mot();
    afficher_table_variables();
    return 0;
}
yywrap () {}

void yyerror(const char *msg) {
    printf("Erreur syntaxique : %s à la ligne %d, colonne %d\n", msg, nb_ligne, col);
}
