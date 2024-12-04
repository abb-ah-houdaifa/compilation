%{
    #include "syntax.tab.h"

    extern YYSTYPE yylval;
    extern int nb_ligne;
    extern int col;
%}

chiffre [0-9]
lettre_maj [A-Z]
lettre {lettre_maj}|[a-z]
SIGNE [\+-]?
ENTIER {SIGNE}{chiffre}+ 
REEL {SIGNE}{ENTIER}"."{ENTIER}
tiret _
IDF {lettre_maj}(({lettre}|{chiffre})|({tiret}|({lettre}|{chiffre})))*
COMMENTAIRE1 #.*
COMMENTAIRE2 \/\/.*
COMMENTAIRE3 "/*"(.|\n)*"*/"
COMMENTAIRE {COMMENTAIRE1}|{COMMENTAIRE2}|{COMMENTAIRE3}
CHAINE_CARACTERE ({lettre}|{chiffre})*

%%
import      {col += yyleng; return mc_import;};
ISIL        {col += yyleng; return mc_isil;};
io          {col += yyleng; return mc_io;};
lang        {col += yyleng; return mc_lang;};

PDec        {col += yyleng; return mc_dec;};
Programme   {col += yyleng; return mc_programme;};
InDebut     {col += yyleng; return mc_debut;}
InFin       {col += yyleng; return mc_fin;};

final       {col += yyleng; return mc_final;};
Integer     {col += yyleng; return mc_int;};
Float       {col += yyleng; return mc_float;};

Input       {col += yyleng; return mc_input;};
Write       {col += yyleng; return mc_write;};

For         {col += yyleng; return mc_for;};
ENDFOR      {col += yyleng; return mc_endfor;};

IF          {col += yyleng; return mc_if;};
DO          {col += yyleng; return mc_do;};
ELSE        {col += yyleng; return mc_else;};
ENDIF       {col += yyleng; return mc_endif;};

{REEL} {
    yylval.real = atof(yytext);
    col += yyleng;
    return cst_reel;
};
{ENTIER} {
    int valeur = atoi(yytext);
    col += yyleng;
    if (valeur > 32767 || valeur < -32768) {
        printf("La valeur de l'entier doit etre entre -32768 et 32767.\n");
        return err;
    }

    yylval.entier = valeur;
    return cst_entier;
};

{IDF} {
    col += yyleng;
    if (yyleng > 18) {
        printf("La taille de l'identificateur depasse 10 carateres.\n");
        return err;
    }
    yylval.str=strdup(yytext);
    return idf;
};

{CHAINE_CARACTERE} {return chaine_caractere;};

{COMMENTAIRE} {nb_ligne++; col = 0;};

"+" return sym_plus;
"-" return sym_moins;

"=" return oper_initialisation;
"<--" return aff;

"," return vg;
";" return pvg;
"." return point;

"|" return separateur;

"(" return parenthese_ouv;
")" return parenthese_fer;

"[" return crochet_ouv;
"]" return crochet_fer;

"*" return sym_mul;
"/" return sym_div;

"||" return oper_ou;
"&&" return oper_et;
"!" return oper_negation;

">=" return oper_sup_egal;
"<=" return oper_inf_egal;
">" return oper_sup;
"<" return oper_inf;
"!=" return oper_inegalite;
"==" return oper_egalite;

"%d" return signe_formattage_entier;
"%f" return signe_formattage_reel;

\" return double_quote;

\n {nb_ligne++; col = 1;}
[ \t] {col += yyleng;}

. {printf("Erreur lexicale a la ligne %d dans la chaine %s\n", nb_ligne, yytext); return err;}
%%