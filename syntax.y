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
%type <str> TYPE 
%token mc_import mc_io mc_lang mc_isil mc_programme mc_debut mc_dec mc_fin mc_final <str> mc_int <str> mc_float
%token point pvg separateur parenthese_ouv parenthese_fer aff
%token sym_mul sym_div sym_plus sym_moins
%token mc_for mc_do mc_endfor mc_if mc_endif mc_else mc_input mc_write
%token <str> idf <entier> cst_entier <reel> cst_reel
%token oper_et oper_ou oper_negation
%token oper_sup_egal oper_inf_egal oper_sup oper_inf oper_inegalite oper_egalite
%token err
%start S
%%


%%
main() {
    yyparse();
    return 0;
}
yywrap(){}

void yyerror(char *msg) {
    printf("Erreur syntaxique, a la ligne %d, colonne %d\n", nb_ligne, col);
}