
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 18 "syntax.y"

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



/* Line 1676 of yacc.c  */
#line 63 "syntax.tab.h"

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
     double_quote = 280,
     sym_mul = 281,
     sym_div = 282,
     sym_plus = 283,
     sym_moins = 284,
     mc_for = 285,
     mc_do = 286,
     mc_endfor = 287,
     mc_if = 288,
     mc_endif = 289,
     mc_else = 290,
     mc_input = 291,
     mc_write = 292,
     idf = 293,
     cst_entier = 294,
     cst_reel = 295,
     oper_et = 296,
     oper_ou = 297,
     oper_negation = 298,
     oper_sup_egal = 299,
     oper_inf_egal = 300,
     oper_sup = 301,
     oper_inf = 302,
     oper_inegalite = 303,
     oper_egalite = 304,
     signe_formattage_entier = 305,
     signe_formattage_reel = 306,
     err = 307,
     chaine_caractere = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 39 "syntax.y"

    int entier;
    float real;
    char* str;
    // definir un nouveau type complexe (struct)
    struct entite entite;
    struct tableau tableau;
    struct constante constante;



/* Line 1676 of yacc.c  */
#line 145 "syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


