%{
    int nb_ligne = 1;
    int col = 1;
    void yyerror(char *msg);
%}
%union {
    int entier;
    char* str;
    float reel;
}

%token mc_import mc_io mc_lang mc_isil mc_programme mc_debut mc_dec mc_fin mc_final <str> mc_int <str> mc_float
%token point pvg vg separateur crochet_ouv crochet_fer parenthese_ouv parenthese_fer aff oper_initialisation double_quote
%token sym_mul sym_div sym_plus sym_moins
%token mc_for mc_do mc_endfor mc_if mc_endif mc_else mc_input mc_write
%token <str> idf <entier> cst_entier <reel> cst_reel
%token oper_et oper_ou oper_negation
%token oper_sup_egal oper_inf_egal oper_sup oper_inf oper_inegalite oper_egalite
%token signe_formattage_entier signe_formattage_reel
%token err
%start S
%left sym_mul sym_div sym_plus sym_moins

%type VALEUR_CST
%%

S: mc_debut BLOC_INSTRUCTIONS mc_fin point {printf("Programme correcte syntaxiquement.\n"); YYACCEPT;};
BLOC_INSTRUCTIONS: INSTRUCTION BLOC_INSTRUCTIONS |
    ;

INSTRUCTION: 
    INSTRUCTION_AFFECTATION |
    INSTRUCTION_FOR |
    INSTRUCTION_IF |
    INSTRUCTION_ENTREE_SORTIE;

INSTRUCTION_AFFECTATION: VARIABLE aff EXPRESSION_ARITHMETIQUE pvg;

EXPRESSION_ARITHMETIQUE: 
    EXPRESSION_1 sym_plus EXPRESSION_ARITHMETIQUE | 
    EXPRESSION_1 sym_moins EXPRESSION_ARITHMETIQUE |
    EXPRESSION_1;

EXPRESSION_1: 
    EXPRESSION_2 sym_mul EXPRESSION_1 | 
    EXPRESSION_2 sym_div EXPRESSION_1 |
    EXPRESSION_2;

EXPRESSION_2: 
    parenthese_ouv EXPRESSION_ARITHMETIQUE parenthese_fer |
    VALEUR_CST |
    VARIABLE;

VALEUR_CST: 
    cst_reel | 
    cst_entier ;

VARIABLE: idf SUITE_IDF;

SUITE_IDF: crochet_ouv cst_entier crochet_fer|

INSTRUCTION_FOR: mc_for parenthese_ouv PARAMETRE_BOUCLE parenthese_fer mc_do BLOC_INSTRUCTIONS mc_endfor;

PARAMETRE_BOUCLE: INITIALISATION_COMPTEUR pvg CONDITION pvg INCREMENTATION_COMPTEUR;

INITIALISATION_COMPTEUR: idf aff EXPRESSION_ARITHMETIQUE;

CONDITION: CONDITION1 oper_ou CONDITION |
    CONDITION1;

CONDITION1:
    CONDITION2 oper_et CONDITION1 |
    CONDITION2;

CONDITION2: 
    parenthese_ouv CONDITION parenthese_fer |
    oper_negation parenthese_ouv CONDITION parenthese_fer |
    COMPARAISON;

COMPARAISON: 
    COMPARAISON1 oper_inf COMPARAISON |
    COMPARAISON1 oper_inf_egal COMPARAISON |
    COMPARAISON1 oper_sup COMPARAISON |
    COMPARAISON1 oper_sup_egal COMPARAISON |
    COMPARAISON1 oper_egalite COMPARAISON |
    COMPARAISON1 oper_inegalite COMPARAISON |
    COMPARAISON1;

COMPARAISON1:
    idf |
    VALEUR_CST;
    
INCREMENTATION_COMPTEUR: 
    idf sym_plus sym_plus;

INSTRUCTION_IF: 
    mc_if parenthese_ouv CONDITION parenthese_fer mc_do BLOC_INSTRUCTIONS mc_endif |
    mc_if parenthese_ouv CONDITION parenthese_fer mc_do BLOC_INSTRUCTIONS mc_else BLOC_INSTRUCTIONS mc_endif;

INSTRUCTION_ENTREE_SORTIE:
    INSTRUCTION_ENTREE pvg|
    INSTRUCTION_SORTIE pvg;

INSTRUCTION_ENTREE: mc_input parenthese_ouv double_quote SIGNE_FORMATTAGE double_quote vg idf parenthese_fer;

INSTRUCTION_SORTIE: mc_write parenthese_ouv parenthese_fer;

SIGNE_FORMATTAGE: signe_formattage_entier | signe_formattage_reel;

%%
main() {
    yyparse();
    return 0;
}
yywrap(){}

void yyerror(char *msg) {
    printf("Erreur syntaxique, a la ligne %d, colonne %d\n", nb_ligne, col);
}