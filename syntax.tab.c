
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

// Declaration des varibales globales
int isFloat, typeRecuIsFloat, indiceTableau;
int isTableau;
char valeur[10];
char nom[18];

// variable globale pour afficher les erreurs
char error[20];

// varaibles globles pour les instructions d'entree/sortie
int cpt_signe_format = 0;
int cpt_idf_ES = 0;
int list_signe_format[20];
int list_type_idf_ES[20];

// Déclaration des fonctions d'erreur
void yyerror(const char *msg);
void erreur_semantique(const char *msg);


/* Line 189 of yacc.c  */
#line 103 "syntax.tab.c"

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
#line 32 "syntax.y"

    struct entite {
        char *nom;
        int isFloat;
        int isTableau;
        char valeur[10];
    };

    struct constante {
        int isFloat;
        char valeur[10];
    };



/* Line 209 of yacc.c  */
#line 143 "syntax.tab.c"

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
     inc = 278,
     oper_initialisation = 279,
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
     err = 304,
     chaine_caractere = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 46 "syntax.y"

    int entier;
    float real;
    char* str;
    // definir un nouveau type complexe (struct)
    struct entite entite;
    struct constante constante;



/* Line 214 of yacc.c  */
#line 221 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 233 "syntax.tab.c"

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
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    13,    14,    16,    18,    24,    27,
      30,    31,    35,    39,    41,    44,    48,    51,    52,    57,
      59,    63,    67,    69,    71,    73,    75,    80,    83,    84,
      86,    88,    90,    92,    97,   101,   105,   107,   111,   115,
     117,   121,   123,   125,   128,   132,   133,   141,   147,   151,
     155,   157,   161,   163,   167,   172,   174,   178,   182,   186,
     190,   194,   198,   200,   202,   204,   207,   215,   225,   228,
     231,   237,   241,   244,   250,   254
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    55,    -1,     3,     6,    14,    54,
      15,    53,    -1,    -1,     5,    -1,     4,    -1,     7,    37,
       9,    56,    66,    -1,    57,    56,    -1,    61,    56,    -1,
      -1,    65,    58,    15,    -1,    59,    17,    58,    -1,    59,
      -1,    37,    60,    -1,    18,    38,    19,    -1,    24,    64,
      -1,    -1,    11,    65,    62,    15,    -1,    63,    -1,    63,
      17,    62,    -1,    37,    24,    64,    -1,    38,    -1,    39,
      -1,    13,    -1,    12,    -1,     8,    67,    10,    14,    -1,
      68,    67,    -1,    -1,    69,    -1,    75,    -1,    84,    -1,
      85,    -1,    73,    22,    70,    15,    -1,    71,    27,    70,
      -1,    71,    28,    70,    -1,    71,    -1,    72,    25,    71,
      -1,    72,    26,    71,    -1,    72,    -1,    20,    70,    21,
      -1,    64,    -1,    73,    -1,    37,    74,    -1,    18,    38,
      19,    -1,    -1,    29,    20,    76,    21,    30,    67,    31,
      -1,    77,    15,    78,    15,    83,    -1,    37,    22,    70,
      -1,    79,    41,    78,    -1,    79,    -1,    80,    40,    79,
      -1,    80,    -1,    20,    78,    21,    -1,    42,    20,    78,
      21,    -1,    81,    -1,    82,    46,    81,    -1,    82,    44,
      81,    -1,    82,    45,    81,    -1,    82,    43,    81,    -1,
      82,    48,    81,    -1,    82,    47,    81,    -1,    82,    -1,
      73,    -1,    64,    -1,    37,    23,    -1,    32,    20,    78,
      21,    30,    67,    33,    -1,    32,    20,    78,    21,    30,
      67,    34,    67,    33,    -1,    86,    15,    -1,    88,    15,
      -1,    35,    20,    50,    87,    21,    -1,    16,    73,    87,
      -1,    16,    73,    -1,    36,    20,    50,    89,    21,    -1,
      16,    73,    89,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    78,    78,    82,    89,    98,   103,   104,
     104,   108,   111,   112,   114,   133,   137,   139,   146,   149,
     150,   152,   170,   177,   188,   189,   193,   194,   194,   198,
     199,   200,   201,   203,   226,   238,   250,   256,   268,   286,
     297,   301,   305,   310,   353,   357,   362,   364,   372,   409,
     410,   413,   414,   417,   418,   419,   422,   429,   436,   443,
     450,   457,   464,   467,   470,   472,   477,   478,   481,   492,
     504,   557,   569,   582,   623,   627
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
  "crochet_fer", "parenthese_ouv", "parenthese_fer", "aff", "inc",
  "oper_initialisation", "sym_mul", "sym_div", "sym_plus", "sym_moins",
  "mc_for", "mc_do", "mc_endfor", "mc_if", "mc_endif", "mc_else",
  "mc_input", "mc_write", "idf", "cst_entier", "cst_reel", "oper_et",
  "oper_ou", "oper_negation", "oper_sup_egal", "oper_inf_egal", "oper_sup",
  "oper_inf", "oper_inegalite", "oper_egalite", "err", "chaine_caractere",
  "$accept", "S", "Block_LIB", "NOM_BIB", "Block_Prog", "Block_DEC",
  "Block_DEC_Var", "List_Idf_V_T", "V_T", "SUITE_VT", "Block_DEC_Const",
  "LIST_AFF", "Affect_FINALE", "CST_TYPE", "Type", "PARTIE_INTRUCTIONS",
  "BLOC_INSTRUCTIONS", "INSTRUCTION", "INSTRUCTION_AFFECTATION",
  "EXPRESSION_ARITHMETIQUE", "EXPRESSION_1", "EXPRESSION_2", "VARIABLE",
  "SUITE_IDF", "INSTRUCTION_FOR", "PARAMETRE_BOUCLE",
  "INITIALISATION_COMPTEUR", "CONDITION", "CONDITION1", "CONDITION2",
  "COMPARAISON", "COMPARAISON1", "INCREMENTATION_COMPTEUR",
  "INSTRUCTION_IF", "INSTRUCTION_ENTREE_SORTIE", "INSTRUCTION_ENTREE",
  "IDF_INPUT", "INSTRUCTION_SORTIE", "IDF_WRITE", 0
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
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    56,    56,
      56,    57,    58,    58,    59,    60,    60,    60,    61,    62,
      62,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    68,    68,    69,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    73,    74,    74,    75,    76,    77,    78,
      78,    79,    79,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    84,    84,    85,    85,
      86,    87,    87,    88,    89,    89
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
       3,     3,     1,     1,     1,     2,     7,     9,     2,     2,
       5,     3,     2,     5,     3,     0
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
      16,    12,    21,    20,     0,     0,     0,     0,     0,    64,
      63,     0,    50,    52,    55,    62,     0,    75,     0,    26,
       0,    41,     0,    36,    39,    42,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,    33,     0,     0,
       0,     0,    48,    28,     0,    53,     0,    28,    49,    51,
      59,    57,    58,    56,    61,    60,    72,    70,    75,    73,
      40,    34,    35,    37,    38,     0,     0,    54,     0,    71,
      74,    46,     0,    47,    66,    28,    65,     0,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    12,     7,    18,    19,    29,    30,    50,
      20,    32,    33,    79,    21,    25,    39,    40,    41,    92,
      93,    94,    80,    61,    43,    75,    76,    81,    82,    83,
      84,    85,   153,    44,    45,    46,   112,    47,   114
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int8 yypact[] =
{
       8,    19,    27,    26,    31,   -88,    41,   -88,     3,    70,
     -88,   -88,    65,     2,     8,     6,   -88,   -88,    73,     2,
       2,    45,   -88,    46,    12,   -88,   -88,   -88,   -12,    71,
      68,    66,    76,    75,    78,    80,    81,    82,    86,    83,
      12,   -88,    84,   -88,   -88,   -88,    90,    92,    72,    -9,
     -88,   -88,    45,    -9,   -88,    46,    74,    -3,    58,    59,
      77,   -88,    98,   -88,   -16,   -88,   -88,    94,   -88,   -88,
     -88,   -88,   -88,   -88,    95,    93,   103,    -3,    99,   -88,
     -88,   100,    79,    85,   -88,    11,   106,   107,   105,   -88,
     -16,   -88,   111,    10,    17,   -88,   -88,   -16,    97,    -3,
     108,    -3,   102,    -3,    -3,    13,    13,    13,    13,    13,
      13,    91,   109,    91,   112,   -88,   113,   -88,   -16,   -16,
     -16,   -16,   -88,    12,   120,   -88,   115,    12,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   106,   -88,   107,   -88,
     -88,   -88,   -88,   -88,   -88,   110,   101,   -88,    34,   -88,
     -88,   -88,   114,   -88,   -88,    12,   -88,   116,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   125,   -88,   -88,    50,   -88,    88,   -88,   -88,
     -88,    87,   -88,   -44,   128,   -88,   -39,   -88,   -88,   -87,
     -49,   -88,   -24,   -88,   -88,   -88,   -88,   -75,    40,   -88,
     -45,   -88,   -88,   -88,   -88,   -88,     9,   -88,    14
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      42,    63,   100,   116,    90,    70,    48,    10,    11,    72,
     122,     1,    49,    15,    16,    17,    42,    77,    16,    17,
      91,    38,    68,    69,   124,     4,   126,     5,   128,    68,
      69,   141,   142,     6,    38,    68,    69,   118,   119,    78,
      95,    34,   120,   121,    35,     8,    91,    36,    37,    38,
      38,    68,    69,    91,   105,   106,   107,   108,   109,   110,
     130,   131,   132,   133,   134,   135,    95,   154,   155,    26,
      27,   143,   144,    95,    91,    91,    91,    91,     9,    13,
      14,    24,    28,    31,   145,    52,    51,   136,   148,   138,
      53,    54,    55,    62,    95,    95,    95,    95,    56,    42,
      57,    58,    59,    42,    60,    65,    64,    66,    86,    87,
      67,    74,    89,    96,    98,    88,   157,    97,    99,   101,
     103,   102,   111,   113,   115,   104,   117,   123,    38,   125,
     137,    42,   127,   139,   140,   146,   147,   156,   152,    22,
      71,   151,    73,    23,   129,   149,     0,     0,     0,   158,
       0,     0,   150
};

static const yytype_int16 yycheck[] =
{
      24,    40,    77,    90,    20,    49,    18,     4,     5,    53,
      97,     3,    24,    11,    12,    13,    40,    20,    12,    13,
      64,    37,    38,    39,    99,     6,   101,     0,   103,    38,
      39,   118,   119,     7,    37,    38,    39,    27,    28,    42,
      64,    29,    25,    26,    32,    14,    90,    35,    36,    37,
      37,    38,    39,    97,    43,    44,    45,    46,    47,    48,
     105,   106,   107,   108,   109,   110,    90,    33,    34,    19,
      20,   120,   121,    97,   118,   119,   120,   121,    37,     9,
      15,     8,    37,    37,   123,    17,    15,   111,   127,   113,
      24,    15,    17,    10,   118,   119,   120,   121,    20,   123,
      20,    20,    20,   127,    18,    15,    22,    15,    50,    50,
      38,    37,    14,    19,    21,    38,   155,    22,    15,    20,
      41,    21,    16,    16,    19,    40,    15,    30,    37,    21,
      21,   155,    30,    21,    21,    15,    21,    23,    37,    14,
      52,    31,    55,    15,   104,   136,    -1,    -1,    -1,    33,
      -1,    -1,   138
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    53,     6,     0,     7,    55,    14,    37,
       4,     5,    54,     9,    15,    11,    12,    13,    56,    57,
      61,    65,    53,    65,     8,    66,    56,    56,    37,    58,
      59,    37,    62,    63,    29,    32,    35,    36,    37,    67,
      68,    69,    73,    75,    84,    85,    86,    88,    18,    24,
      60,    15,    17,    24,    15,    17,    20,    20,    20,    20,
      18,    74,    10,    67,    22,    15,    15,    38,    38,    39,
      64,    58,    64,    62,    37,    76,    77,    20,    42,    64,
      73,    78,    79,    80,    81,    82,    50,    50,    38,    14,
      20,    64,    70,    71,    72,    73,    19,    22,    21,    15,
      78,    20,    21,    41,    40,    43,    44,    45,    46,    47,
      48,    16,    87,    16,    89,    19,    70,    15,    27,    28,
      25,    26,    70,    30,    78,    21,    78,    30,    78,    79,
      81,    81,    81,    81,    81,    81,    73,    21,    73,    21,
      21,    70,    70,    71,    71,    67,    15,    21,    67,    87,
      89,    31,    37,    83,    33,    34,    23,    67,    33
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
#line 74 "syntax.y"
    { printf("Programme Correcte.\n"); YYACCEPT; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 82 "syntax.y"
    {
        // la bibliotheque est deja declare
        if (!declarer_biblio_lang()) {
            erreur_semantique("La bibliotheque lang est deja declaree");
            return;
        }
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 89 "syntax.y"
    {
        if (!declarer_biblio_io()) {
            erreur_semantique("La bibliotheque io est deja declaree");
            return;
        }
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 114 "syntax.y"
    {
    char *typeAttendu = (isFloat == 1) ? "Float" : "Integer";
    if (isFloat != typeRecuIsFloat && isTableau == 0) {
        sprintf(error, "Erreur sémantique : type incompatible. Attendu '%s'.", typeAttendu);
        erreur_semantique(error);
        return;
    }

    int status = remplir_variable((yyvsp[(1) - (2)].str), "identificateur", isFloat, valeur, 0, isTableau);

    if (status == 0) {
        sprintf(error, "Double declaration de l'identificateur: %s", (yyvsp[(1) - (2)].str));
        erreur_semantique(error);
        return;
    }
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 133 "syntax.y"
    {
        isTableau = 1;
        sprintf(valeur, "%d", (yyvsp[(2) - (3)].entier));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 137 "syntax.y"
    {
        isTableau = 0;
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 139 "syntax.y"
    {
        isTableau = 0;
        strcpy(valeur, " ");
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 152 "syntax.y"
    {
    char *typeAttendu = (isFloat == 1) ? "Float" : "Integer";
    if (isFloat != typeRecuIsFloat) {
        sprintf(error, "Erreur sémantique : type incompatible. Attendu '%s'.", typeAttendu);
        erreur_semantique(error);
        return;
    }
    int status = remplir_variable((yyvsp[(1) - (3)].str), "identificateur", isFloat, valeur, 1, 0);

    if (status == 0) {
        sprintf(error, "Double declaration de l'identificateur: %s", (yyvsp[(1) - (3)].str));
        erreur_semantique(error);
        return;
    }
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 170 "syntax.y"
    {
        typeRecuIsFloat = 0;
        (yyval.constante).isFloat = 0;

        sprintf(valeur, "%d", (yyvsp[(1) - (1)].entier)); // copier la valeur entiere dans une chaine de caractere
        strcpy((yyval.constante).valeur, valeur);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 177 "syntax.y"
    {
        typeRecuIsFloat = 1;
        (yyval.constante).isFloat = 1;

        gcvt((yyvsp[(1) - (1)].real), 10, valeur); // copier la valeur reelle dans une chaine de caractere
        strcpy((yyval.constante).valeur, valeur);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 188 "syntax.y"
    {isFloat = 1;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 189 "syntax.y"
    {isFloat = 0;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 203 "syntax.y"
    {
    
    if (!(yyvsp[(1) - (4)].entite).isTableau) {
        if (verifier_modification_const((yyvsp[(1) - (4)].entite).nom) == -1) {
            sprintf(error, "Modification de la valeur d'une constante %s", (yyvsp[(1) - (4)].entite).nom);
            erreur_semantique(error);
            return;
        }
    }
    
    int type = (yyvsp[(1) - (4)].entite).isFloat;
    // verifier la non compatibilite de type
    if (type != (yyvsp[(3) - (4)].constante).isFloat) {
        char* typeAttendu = type ? "Float" : "Integer";
        char* typeRecu = (yyvsp[(3) - (4)].constante).isFloat ? "Float" : "Integer";

        sprintf(error, "Non compatibilite de type, type attendu (l'identificateur %s): %s, type recu: %s", (yyvsp[(1) - (4)].entite).nom, typeAttendu, typeRecu);
        erreur_semantique(error);
        return;
    }
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 226 "syntax.y"
    {
        // verifier la non-compatibilite de type

        if ((yyvsp[(1) - (3)].constante).isFloat != (yyvsp[(3) - (3)].constante).isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (3)].constante).isFloat; // passer la valeur au non-terminale suivant
        strcpy((yyval.constante).valeur, "1");
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 238 "syntax.y"
    {
        // verifier la non-compatibilite de type

        if ((yyvsp[(1) - (3)].constante).isFloat != (yyvsp[(3) - (3)].constante).isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (3)].constante).isFloat; // passer la valeur au non-terminale suivant
        strcpy((yyval.constante).valeur, "1");
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 250 "syntax.y"
    {
        (yyval.constante).isFloat = (yyvsp[(1) - (1)].constante).isFloat;
        strcpy((yyval.constante).valeur, (yyvsp[(1) - (1)].constante).valeur);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 256 "syntax.y"
    {
        // verifier la non-compatibilite de type

        if ((yyvsp[(1) - (3)].constante).isFloat != (yyvsp[(3) - (3)].constante).isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (3)].constante).isFloat; // passer la valeur au non-terminale suivant
        strcpy((yyval.constante).valeur, "1");
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 268 "syntax.y"
    {
        // verifier la non-compatibilite de type

        if ((yyvsp[(1) - (3)].constante).isFloat != (yyvsp[(3) - (3)].constante).isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }

        // division par zero
        if (strcmp((yyvsp[(3) - (3)].constante).valeur, "0") == 0) {
            yyerror("Division par 0");
            return;            
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (3)].constante).isFloat; // passer la valeur au non-terminale suivant
        strcpy((yyval.constante).valeur, "1");
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 286 "syntax.y"
    {
        if (!verifier_biblio_lang_declaree()) {
            erreur_semantique("La bibliotheque lang n'est pas declaree");
            return;
        }

        (yyval.constante).isFloat = (yyvsp[(1) - (1)].constante).isFloat;
        strcpy((yyval.constante).valeur, (yyvsp[(1) - (1)].constante).valeur);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 297 "syntax.y"
    {
        (yyval.constante) = (yyvsp[(2) - (3)].constante);
        strcpy((yyval.constante).valeur, (yyvsp[(2) - (3)].constante).valeur);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 301 "syntax.y"
    {
        (yyval.constante).isFloat = (yyvsp[(1) - (1)].constante).isFloat; // copier le type de la constante
        strcpy((yyval.constante).valeur, (yyvsp[(1) - (1)].constante).valeur); // copier la valeur de la constante
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 305 "syntax.y"
    {
        (yyval.constante).isFloat = (yyvsp[(1) - (1)].entite).isFloat; // copier le type de la variable Integer ou Float
        strcpy((yyval.constante).valeur, "1"); // on suppose que la valeur de la variable ne nous concerne pas si elle est egale a 0
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 310 "syntax.y"
    {
    // non declaration
    if (verifier_non_declaration((yyvsp[(1) - (2)].str))) {
        sprintf(error, "Non declaration de l'identificateur %s", (yyvsp[(1) - (2)].str));
        erreur_semantique(error);
        return;
    };

    // si l'entite est un tableau
    if (isTableau == 1) {
        int taille;
        // verifier le depassement de la taille
        taille = verifier_taille_tableau((yyvsp[(1) - (2)].str), indiceTableau);

        // traitement des erreurs semantiques
        if (taille == -1) {
            sprintf(error, "Depassement de la taille du tableau %s", (yyvsp[(1) - (2)].str));
            erreur_semantique(error);
            return;
        } else if (taille == -2) {
            sprintf(error, "Variable %s n'est pas un tableau", (yyvsp[(1) - (2)].str));
            erreur_semantique(error);
            return;
        }

        (yyval.entite).isFloat = taille;
    } else {

        // verifier si l'identificateur est un tableau
        if (est_tableau((yyvsp[(1) - (2)].str))) {
            sprintf(error, "Variable %s est un tableau", (yyvsp[(1) - (2)].str));
            erreur_semantique(error);
            return;
        }

        (yyval.entite).isFloat = type_variable((yyvsp[(1) - (2)].str));
    }

    strcpy((yyval.entite).nom, (yyvsp[(1) - (2)].str));
    (yyval.entite).isTableau = isTableau;
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 353 "syntax.y"
    {
        isTableau = 1;
        indiceTableau = (yyvsp[(2) - (3)].entier);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 357 "syntax.y"
    {
        isTableau = 0; // mettre tableau a faux
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 364 "syntax.y"
    {
    if (strcmp((yyvsp[(1) - (5)].str), (yyvsp[(5) - (5)].str)) != 0) {
        sprintf(error, "La varaible %s de la partie initialisation doit etre incrementee", (yyvsp[(1) - (5)].str));
        erreur_semantique(error);
        return;
    }
;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 372 "syntax.y"
    {
    int type = type_variable((yyvsp[(1) - (3)].str));

    // verifier l'inexistance
    if (type == -1) {
        sprintf(error, "Non declaration de l'identificateur %s", (yyvsp[(1) - (3)].str));
        erreur_semantique(error);
        return;
    }
    
    // verifier s'il s'agit d'un tableau
    if (est_tableau((yyvsp[(1) - (3)].str))) {
        sprintf(error, "Compteur %s ne doit pas etre un tableau", (yyvsp[(1) - (3)].str));
        erreur_semantique(error);
        return;
    }

    // le compteur doit etre un Integer
    if (type == 1) {
        sprintf(error, "Compteur %s doit etre un Integer", (yyvsp[(1) - (3)].str));
        erreur_semantique(error);
        return;
    }

    // l'affectation recue est de type Float
    if (type != (yyvsp[(3) - (3)].constante).isFloat) {
        char* typeAttendu = type ? "Float" : "Integer";
        char* typeRecu = (yyvsp[(3) - (3)].constante).isFloat ? "Float" : "Integer";

        sprintf(error, "Non compatibilite de type, type attendu (l'identificateur %s): %s, type recu: %s", (yyvsp[(1) - (3)].str), typeAttendu, typeRecu);
        erreur_semantique(error);
        return;
    }

    (yyval.str) = (yyvsp[(1) - (3)].str);
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 422 "syntax.y"
    {
        if ((yyvsp[(1) - (3)].entier) != (yyvsp[(3) - (3)].entier)) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 429 "syntax.y"
    {
        if ((yyvsp[(1) - (3)].entier) != (yyvsp[(3) - (3)].entier)) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 436 "syntax.y"
    {
        if ((yyvsp[(1) - (3)].entier) != (yyvsp[(3) - (3)].entier)) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 443 "syntax.y"
    {
        if ((yyvsp[(1) - (3)].entier) != (yyvsp[(3) - (3)].entier)) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 450 "syntax.y"
    {
        if ((yyvsp[(1) - (3)].entier) != (yyvsp[(3) - (3)].entier)) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 457 "syntax.y"
    {
        if ((yyvsp[(1) - (3)].entier) != (yyvsp[(3) - (3)].entier)) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", (yyvsp[(2) - (3)].str));
            erreur_semantique(error);
            return;
        }
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 464 "syntax.y"
    {(yyval.entier) = (yyvsp[(1) - (1)].entier);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 467 "syntax.y"
    {
        (yyval.entier) = type_variable((yyvsp[(1) - (1)].entite).nom);
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 470 "syntax.y"
    {(yyval.entier) = (yyvsp[(1) - (1)].constante).isFloat;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 472 "syntax.y"
    {
    (yyval.str) = (yyvsp[(1) - (2)].str);
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 481 "syntax.y"
    {
        // verifier si la bib io est declaree
        if (!verifier_biblio_io_declaree()) {
            erreur_semantique("La bibliotheque io n'est pas declaree");
            return;
        }

        // initialiser les compteurs
        cpt_idf_ES = 0;
        cpt_signe_format = 0;
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 492 "syntax.y"
    {
        // verifier si la bib io est declaree
        if (!verifier_biblio_io_declaree()) {
            erreur_semantique("La bibliotheque io n'est pas declaree");
            return;
        }

        // initialiser les compteurs
        cpt_idf_ES = 0;
        cpt_signe_format = 0;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 504 "syntax.y"
    {
    int i;

    // parcourir la chaine de caractere pour compter les signes de formattage
    for (i = 0; i < strlen((yyvsp[(3) - (5)].str)) - 1; i++) {
        if ((yyvsp[(3) - (5)].str)[i] == '%') {
            // un entier
            if ((yyvsp[(3) - (5)].str)[i + 1] == 'd') {
                list_signe_format[cpt_signe_format] = 0;
                cpt_signe_format++;
                i++;
            } 
            // un reel
            else if ((yyvsp[(3) - (5)].str)[i + 1] == 'f') {
                list_signe_format[cpt_signe_format] = 1;
                cpt_signe_format++;
                i++;
            } 
            // signe invalid
            else {
                sprintf(error, "Signe de formattage inexistant %c%c", '%', (yyvsp[(3) - (5)].str)[i + 1]);
                erreur_semantique(error);
                return;
            }
        } 
        // si la chaine contient autre que les blancs et les signes
        else if ((yyvsp[(3) - (5)].str)[i] != ' '){
            // sauter les espaces
            erreur_semantique("Input doit contenir que les signes de formattage");
            return;
        }
    }

    // verifier si les nombres de signes de formattage est egale au nombre d'idf 
    if (cpt_signe_format != cpt_idf_ES) {
        sprintf(error, "Nombre de signe de formattage %d n'égale pas au nombre de variable %d dans Input", cpt_signe_format,cpt_idf_ES) ;
        erreur_semantique(error);
        return;
    }

    // parcourir les deux tableaux pour verifier la compatibilite de type entre les idf et les signes de formattage
    for (i = 0; i < cpt_signe_format; i++) {
        // parcourir le tableau des idf a partir du dernier type inserer
        // parcourir le tableau des signes a partir du premier type inserer 
        if (list_signe_format[i] != list_type_idf_ES[20 - cpt_idf_ES + i]) {
            sprintf(error, " Signe de formattage  incompatible avec le type  de variable dans Input");
            erreur_semantique(error);
            return;
        }
    }
;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 557 "syntax.y"
    {
        // verifier si l'idf est une constante
        if (verifier_modification_const((yyvsp[(2) - (3)].entite).nom) == -1) {
            sprintf(error, "Modification de la valeur d'une constante %s", (yyvsp[(2) - (3)].entite).nom);
            erreur_semantique(error);
            return;
        }

        // inserer les types dans la fin du tableau
        list_type_idf_ES[19 - cpt_idf_ES] = type_variable((yyvsp[(2) - (3)].entite).nom);
        cpt_idf_ES++;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 569 "syntax.y"
    {
        // verifier si l'idf est une constante
        if (verifier_modification_const((yyvsp[(2) - (2)].entite).nom) == -1) {
            sprintf(error, "Modification de la valeur d'une constante %s", (yyvsp[(2) - (2)].entite).nom);
            erreur_semantique(error);
            return;
        }

        // inserer les types dans la fin du tableau
        list_type_idf_ES[19 - cpt_idf_ES] = type_variable((yyvsp[(2) - (2)].entite).nom);
        cpt_idf_ES++;
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 582 "syntax.y"
    {
    int i;

    for (i = 0; i < strlen((yyvsp[(3) - (5)].str)); i++) {
        // compter les signes de formattage
        if ((yyvsp[(3) - (5)].str)[i] == '%' && i < strlen((yyvsp[(3) - (5)].str)) - 1) {
            // un entier
            if ((yyvsp[(3) - (5)].str)[i + 1] == 'd') {
                list_signe_format[cpt_signe_format] = 0;
                cpt_signe_format++;
                i++;
            } 
            // un reel
            else if ((yyvsp[(3) - (5)].str)[i + 1] == 'f') {
                list_signe_format[cpt_signe_format] = 1;
                cpt_signe_format++;
                i++;
            }
        }
    }

    // verifier si les nombres de signes de formattage est egale au nombre d'idf 
    if (cpt_signe_format != cpt_idf_ES) {
        sprintf(error, "Nombre de signe de formattage %d n'égale pas au nombre de variable %d dans Write", cpt_signe_format,cpt_idf_ES) ;
        erreur_semantique(error);
        return;
    }

    // parcourir les deux tableaux pour verifier la compatibilite de type entre les idf et les signes de formattage
    for (i = 0; i < cpt_signe_format; i++) {
        // parcourir le tableau des idf a partir du dernier type inserer
        // parcourir le tableau des signes a partir du premier type inserer 
        if (list_signe_format[i] != list_type_idf_ES[20 - cpt_idf_ES + i]) {
            sprintf(error, " Signe de formattage incompatible avec le type de variable dans Write");
            erreur_semantique(error);
            return;
        }
    }
;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 623 "syntax.y"
    {
        // inserer les types dans la fin du tableau
        list_type_idf_ES[19 - cpt_idf_ES] = type_variable((yyvsp[(2) - (3)].entite).nom);
        cpt_idf_ES++;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2289 "syntax.tab.c"
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
#line 628 "syntax.y"


int main() {
    yyparse();
    afficher_table_separateur_mot();
    afficher_table_variables();
    return 0;
}
yywrap () {}

void yyerror(const char *msg) {
    printf("Erreur syntaxique : %s à la ligne %d, colonne %d", msg, nb_ligne, col);
}

void erreur_semantique(const char *msg) {
    printf("Erreur semantique : %s à la ligne %d, colonne %d", msg, nb_ligne, col);
}
