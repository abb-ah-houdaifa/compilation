%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"


// Variables globales pour la gestion des erreurs
int nb_ligne = 1;
int col = 1;

// Déclaration de la fonction d'erreur
void yyerror(const char *msg);
%}

// ajouter la declaration de la structure entite dans syntax.tab.h
%code requires {
    struct entite {
        char *nom;
        int isFloat;
        int isTableau;
        char valeur[10];
        int index;
        struct entite* suivant;
    };
}

// Déclaration de l'union avec le type Entite
%union {
    int entier;
    float real;
    char* str;
    // definir un nouveau type complexe (struct)
    struct entite entite;
}

%token mc_import mc_io mc_lang mc_isil mc_programme mc_debut mc_dec mc_fin mc_final <str> mc_int <str> mc_float
%token point pvg vg separateur crochet_ouv crochet_fer parenthese_ouv parenthese_fer aff oper_initialisation double_quote
%token sym_mul sym_div sym_plus sym_moins
%token mc_for mc_do mc_endfor mc_if mc_endif mc_else mc_input mc_write
%token <str> idf <entier> cst_entier <real> cst_reel
%token oper_et oper_ou oper_negation
%token oper_sup_egal oper_inf_egal oper_sup oper_inf oper_inegalite oper_egalite
%token signe_formattage_entier signe_formattage_reel
%token err
%token chaine_caractere
%start S
%left sym_mul sym_div sym_plus sym_moins
%right aff
%type <entier> Type
%type <entite> List_Idf_V_T V_T B CST_TYPE
%%

S: Block_LIB Block_Prog  { printf("Programme correcte syntaxiquement.\n"); YYACCEPT; };

// PARITE DECLARATION DES BIBLIOTHEQUES
Block_LIB:
    mc_import mc_isil point NOM_BIB pvg Block_LIB | 
    ;

NOM_BIB: 
    mc_lang | 
    mc_io;

// LA STRUCTURE DU PROGRAMME

Block_Prog: mc_programme idf mc_dec Block_DEC PARTIE_INTRUCTIONS;

// PARITE DECLARATION DES VARIABLES

Block_DEC : 
    Block_DEC_Var Block_DEC |
    Block_DEC_Const Block_DEC |
	;

Block_DEC_Var: Type List_Idf_V_T pvg {
    // garder l'@ du premier identificateur apres le mot cle du type
    struct entite* ptr = &($2);

    // parcourir la liste des identificateur declares
    while (ptr != NULL) {
        
        //verifier l'incompatibilite de type en cas d'affectation du valeur initiale
        // si isFloat = -1 alors il n'y a pas une affectation
        if ((ptr->isFloat != -1) && (ptr->isFloat != $1)) {

            char *typeAttendu = ($1) ? "Float" : "Integer";
            printf("Erreur sémantique : type incompatible pour '%s'. Attendu '%s'.\n", ptr->nom, typeAttendu);
            YYABORT;
        }

        // verifier si l'idf est un tableau
        if (ptr->isTableau) {
            // l'inserer dans la table des tableaux
            int status = inserer_tableau(ptr->nom, ptr->isFloat, ptr->index);

            // verifier s'il est deja declare
            if (status == 0) {
                YYABORT;
            }
        } 
        // le variable est simple idf
        else {
            // verifier si aucune valeur est affecte a l'idf
            if (strcmp(ptr->valeur, " ") == 0) {
                // l'inserer dans la table des variables sans valeur
                int status = inserer_variable(ptr->nom, "identificateur", ptr->isFloat, NULL, 0);

                // verifier s'il est deja declare
                if (status == 0) {
                    YYABORT;
                }
            }
            // une valeur initiale est affectee a l'idf
            else {
                int status = inserer_variable(ptr->nom, "identificateur", ptr->isFloat, ptr->valeur, 0);

                // verifier s'il est deja declare
                if (status == 0) {
                    YYABORT;
                }
            }
        }
        ptr = ptr->suivant;
    }
};

Block_DEC_Const: mc_final Type LIST_AFF pvg;				

LIST_AFF : Affect_FINALE C;

C: separateur LIST_AFF 
    |;

Affect_FINALE: idf oper_initialisation CST_TYPE;
			
List_Idf_V_T: 
    V_T separateur List_Idf_V_T {
        // creer le chainage
        $$.suivant = &$3;
    } |
    V_T {
        // copier les infos necessaire
        // si l'idf est le dernier dans la liste de declaration ou il est tout seul
        $$.nom = strdup($1.nom);
        $$.isFloat = $1.isFloat;
        $$.isTableau = $1.isTableau;
        $$.index = $1.index;
        strcpy($$.valeur, $1.valeur);
        $$.suivant = NULL;
    };

V_T: idf B {
    // copier le nom de l'entite
    $$.nom = strdup($1);

    // copier les champs necessaires
    $$.isFloat = $2.isFloat;
    $$.isTableau = $2.isTableau;
    $$.index = $2.index;
    strcpy($$.valeur, $2.valeur);
};

B: 
    crochet_ouv cst_entier crochet_fer {
        // cas de declaration d'un tableau
        $$.isTableau = 1;
        $$.index = $2;
        $$.isFloat = -1;
    } | 
    oper_initialisation CST_TYPE {
        // cas d'initialisation d'une variable simple
        $$.isFloat = $2.isFloat;
        $$.isTableau = 0;
        strcpy($$.valeur, $2.valeur);
    }| {
        // cas d'une declaration sans initialisation
        $$.isTableau = 0;
        $$.isFloat = -1; // la valeur du variable n'est pas initialiser encore
            // -1 veut dire qu'on n'a pas besoin de comparer le type du variable
        strcpy($$.valeur, " "); // 
    };

CST_TYPE :	
    cst_entier {
        $$.isFloat = 0;
        sprintf($$.valeur, "%d", $1); // copier la valeur entiere dans une chaine de caractere
    } |
    cst_reel {
        $$.isFloat = 1;
        gcvt($1, 10, $$.valeur); // copier la valeur reel dans une chaine de caractere
    };

// Equivalent a isFloat
Type: 
    mc_float {$$ = 1;} | 
    mc_int {$$ = 0;};

// PARTIE DES INSTRUCTIONS

PARTIE_INTRUCTIONS: mc_debut BLOC_INSTRUCTIONS mc_fin point;
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

SUITE_IDF: crochet_ouv cst_entier crochet_fer |

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

INSTRUCTION_SORTIE: mc_write parenthese_ouv double_quote chaine_caractere double_quote IDF_WRITE parenthese_fer;

IDF_WRITE: vg idf IDF_WRITE | 
    ;

SIGNE_FORMATTAGE: signe_formattage_entier | signe_formattage_reel;
%%

int main() {
    yyparse();
    afficher_table_variable();
    afficher_table_tableaux();
    return 0;
}
yywrap () {}

void yyerror(const char *msg) {
    printf("Erreur syntaxique : %s à la ligne %d, colonne %d\n", msg, nb_ligne, col);
}