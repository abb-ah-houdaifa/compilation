%{
    #include "syntax.tab.h"
    #include "TS.h"

    extern YYSTYPE yylval;
    extern int nb_ligne;
    extern int col;
%}

chiffre [0-9]
lettre_maj [A-Z]
lettre {lettre_maj}|[a-z]
SIGNE [\+-]
ENTIER ({chiffre}+|(\({SIGNE}{chiffre}+\))) 
REEL ({ENTIER}"."{ENTIER})|(\({SIGNE}{ENTIER}"."{ENTIER}\))
tiret _
IDF {lettre_maj}(({lettre}|{chiffre})|({tiret}|({lettre}|{chiffre})))*
COMMENTAIRE1 #.*
COMMENTAIRE2 \/\/.*
COMMENTAIRE3 "/*"(.|\n)*"*/"
COMMENTAIRE {COMMENTAIRE1}|{COMMENTAIRE2}|{COMMENTAIRE3}
CHAINE_CARACTERE (^[\"\n])+

%%
import      {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_import; };
ISIL        {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_isil; };
io          {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_io; };
lang        {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_lang; };

PDec        {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_dec; };
Programme   {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_programme; };
InDebut     {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_debut;};
InFin       {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_fin; };

final       {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_final; };
Integer     {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_int; };
Float       {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_float; };

Input       {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_input; };
Write       {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_write; };

For         {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_for; };
ENDFOR      {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_endfor; };

IF          {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_if; };
DO          {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_do; };
ELSE        {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_else; };
ENDIF       {col += yyleng; inserer_mots_separateurs(0, yytext); return mc_endif; };

{REEL} {
    // si la valeur est signee : contient les parentheses
    if (yytext[0] == '(') {
        yytext[yyleng - 1] = '\0'; // ecraser la derniere parenthese avec le caractere fin de chaine de caracteres
        yytext = yytext + 1; // sauter la premiere parethese
    }
    
    yylval.real = atof(yytext);
    col += yyleng;
    return cst_reel;
};
{ENTIER} {
    // si la valeur est signee : contient les parentheses
    if (yytext[0] == '(') {
        yytext[yyleng - 1] = '\0'; // ecraser la derniere parenthese avec le caractere fin de chaine de caracteres
        yytext = yytext + 1; // sauter la premiere parethese
    }

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

    inserer_variable(yytext);
    yylval.str=strdup(yytext);
    return idf;
};

\" return double_quote;

{CHAINE_CARACTERE} {
    col += yyleng; 
    yylval.str = strdup(yytext); 
    printf("%s", yytext); 
    return chaine_caractere;
};

{COMMENTAIRE} {
    int i;
    // parcourir la chaine pour localiser les sauts de ligne
    for (i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') {
            nb_ligne++;
            col = 1;
        } else {
            col++;
        }
    }
};

"+" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return sym_plus;}
"-" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return sym_moins;}

"=" {col += yyleng; inserer_mots_separateurs(1,yytext); return oper_initialisation;}
"<--" {col += yyleng; inserer_mots_separateurs(1,yytext); return aff;}
"++" {col += yyleng; inserer_mots_separateurs(1,yytext); return inc;}

"," {col += yyleng; inserer_mots_separateurs(1,yytext); return vg;}
";" {col += yyleng; inserer_mots_separateurs(1,yytext); return pvg;}
"." {col += yyleng; inserer_mots_separateurs(1,yytext); return point;}

"|" {col += yyleng; inserer_mots_separateurs(1,yytext); return separateur;}

"(" {col += yyleng; inserer_mots_separateurs(1,yytext); return parenthese_ouv;}
")" {col += yyleng; inserer_mots_separateurs(1,yytext); return parenthese_fer;}

"[" {col += yyleng; inserer_mots_separateurs(1,yytext); return crochet_ouv;}
"]" {col += yyleng; inserer_mots_separateurs(1,yytext); return crochet_fer;}

"*" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return sym_mul;}
"/" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return sym_div;}

"||" {col += yyleng; inserer_mots_separateurs(1,yytext); return oper_ou;}
"&&" {col += yyleng; inserer_mots_separateurs(1,yytext); return oper_et;}
"!" {col += yyleng; inserer_mots_separateurs(1,yytext); return oper_negation;}

">=" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return oper_sup_egal;}
"<=" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return oper_inf_egal;}
">" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return oper_sup;}
"<" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return oper_inf;}
"!=" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return oper_inegalite;}
"==" {col += yyleng; yylval.str=strdup(yytext); inserer_mots_separateurs(1,yytext); return oper_egalite;}

"%d" {col += yyleng; inserer_mots_separateurs(1,yytext); return signe_formattage_entier;}
"%f" {col += yyleng; inserer_mots_separateurs(1,yytext); return signe_formattage_reel;}

\n {nb_ligne++; col = 1;}
[ \t] {col += yyleng;}

. {printf("Erreur lexicale a la ligne %d dans la chaine %s\n", nb_ligne, yytext); return err;}
%%