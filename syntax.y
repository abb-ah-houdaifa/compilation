%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables globales pour la gestion des erreurs
int nb_ligne = 1;
int col = 1;

// Déclaration de la fonction d'erreur
void yyerror(const char *msg);
%}

// la structure entite est utilisee lors de la declaration des variables
// elle contient un pointeur pour representer le chainage lors d'une declaration de plusieurs variables sur une meme ligne
// exemple: Integer I1, I2, I3
%code requires {
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
}

%union {
    int entier;
    float real;
    char* str;
    // definir un nouveau type complexe (struct)
    struct entite entite;
    struct tableau tableau;
    struct constante constante;
}

%token mc_import mc_io mc_lang mc_isil mc_programme mc_debut mc_dec mc_fin mc_final <str> mc_int <str> mc_float
%token point pvg vg separateur crochet_ouv crochet_fer parenthese_ouv parenthese_fer aff oper_initialisation double_quote
%token <str> sym_mul sym_div sym_plus sym_moins
%token mc_for mc_do mc_endfor mc_if mc_endif mc_else mc_input mc_write
%token <str> idf <entier> cst_entier <real> cst_reel
%token oper_et oper_ou oper_negation
%token oper_sup_egal oper_inf_egal oper_sup oper_inf oper_inegalite oper_egalite
%token signe_formattage_entier signe_formattage_reel
%token err
%token chaine_caractere
%start S
%right aff
%type <entier> Type
%type <entite> List_Idf_V_T V_T B LIST_AFF Affect_FINALE VARIABLE
%type <tableau> SUITE_IDF
%type <constante> CST_TYPE EXPRESSION_1 EXPRESSION_2 EXPRESSION_ARITHMETIQUE
%%

S: Block_LIB Block_Prog  { printf("Programme Correcte.\n"); YYACCEPT; };

// PARITE DECLARATION DES BIBLIOTHEQUES
Block_LIB:
    mc_import mc_isil point NOM_BIB pvg Block_LIB | 
    ;

NOM_BIB: 
    mc_lang | 
    mc_io;

// LA STRUCTURE DU PROGRAMME

Block_Prog: mc_programme idf mc_dec Block_DEC PARTIE_INTRUCTIONS ;

// PARITE DECLARATION DES VARIABLES

Block_DEC : 
    Block_DEC_Var Block_DEC |
    Block_DEC_Const Block_DEC |
	;

// Declaration d'une variable

Block_DEC_Var: Type List_Idf_V_T pvg {
    // garder l'@ du premier identificateur apres le mot cle du type
    struct entite* ptr = &($2);

    // parcourir la liste des identificateur declares
    while (ptr != NULL) {
        
        //verifier l'incompatibilite de type en cas d'affectation d'une valeur initiale
        // si isFloat = -1 alors il n'y a pas une affectation
        if ((ptr->isFloat != -1) && (ptr->isFloat != $1)) {

            char *typeAttendu = ($1) ? "Float" : "Integer";
            printf("Erreur sémantique : type incompatible pour '%s'. Attendu '%s'.\n", ptr->nom, typeAttendu);
            YYABORT;
        }

        // verifier si l'idf est un tableau
        if (ptr->isTableau) {
            char taille[10]; // convertir la taille du tableau (index) en une chaine de caracteres
            sprintf(taille, "%d", ptr->index);

            // l'inserer dans la table des tableaux
            int status = remplir_variable(ptr->nom, "identificateur", $1, taille, 0, 1);

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
};

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

// la partie qui suit le nom de la variable elle peut prendre ([] (tableau), = (initialisation), epselon (variable non initialisee))
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
        $$.isFloat = -1; // la valeur de la variable n'est pas initialiser encore
            // -1 veut dire qu'on n'a pas besoin de comparer le type de la variable
        strcpy($$.valeur, " "); // 
    };

// Declaration d'une constante

Block_DEC_Const: mc_final Type LIST_AFF pvg {
    // garder l'@ du premier identificateur apres le mot cle du type
    struct entite* ptr = &($3);

    while (ptr != NULL) {
        // comparer la valeur recue et le type declare
        if ($2 != ptr->isFloat) {
            
            // incompatible
            char *typeAttendu = ($2) ? "Float" : "Integer";
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
};				

LIST_AFF : 
    Affect_FINALE {
        // copier les infos necessaire
        // si l'idf est le dernier dans la liste de declaration ou il est tout seul
        $$.nom = strdup($1.nom);
        $$.isFloat = $1.isFloat;
        $$.isTableau = $1.isTableau;
        $$.index = $1.index;
        strcpy($$.valeur, $1.valeur);
        $$.suivant = NULL;
    }|
    Affect_FINALE separateur LIST_AFF {
        $$.suivant = &$3;
    };

Affect_FINALE: idf oper_initialisation CST_TYPE {
    $$.nom = $1;
    
    $$.isFloat = $3.isFloat;
    $$.isTableau = 0;
    strcpy($$.valeur, $3.valeur);
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

INSTRUCTION_AFFECTATION: VARIABLE aff EXPRESSION_ARITHMETIQUE pvg {
    char error[20];

    // verifier si l'identificateur est une constante
    int type = verifier_modification_const($1.nom);

    if (type == -1) {
        sprintf(error, "Modification de la taille d'une constante %s", $1);
        yyerror(error);
        YYABORT;
    }

    // verifier la non compatibilite de type
    if (type != $3.isFloat) {
        char* typeAttendu = type ? "Float" : "Integer";
        char* typeRecu = $3.isFloat ? "Float" : "Integer";

        sprintf(error, "Non compatibilite de type, type attendu (l'identificateur %s): %s, type recu: %s", $1.nom, typeAttendu, typeRecu);
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
};

EXPRESSION_ARITHMETIQUE: 
    EXPRESSION_1 sym_plus EXPRESSION_ARITHMETIQUE {
        // verifier la non-compatibilite de type
        char error[20];

        if ($1.isFloat != $3.isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", $2);
            yyerror(error);
            YYABORT;
        }

        $$.isFloat = $1.isFloat; // passer la valeur au non-terminale suivant
        strcpy($$.valeur, "1");
    }| 
    EXPRESSION_1 sym_moins EXPRESSION_ARITHMETIQUE {
        // verifier la non-compatibilite de type
        char error[20];

        if ($1.isFloat != $3.isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", $2);
            yyerror(error);
            YYABORT;
        }

        $$.isFloat = $1.isFloat; // passer la valeur au non-terminale suivant
        strcpy($$.valeur, "1");
    }|
    EXPRESSION_1 {
        $$.isFloat = $1.isFloat;
        strcpy($$.valeur, $1.valeur);
    };

EXPRESSION_1: 
    EXPRESSION_2 sym_mul EXPRESSION_1 {
        // verifier la non-compatibilite de type
        char error[20];

        if ($1.isFloat != $3.isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", $2);
            yyerror(error);
            YYABORT;
        }

        $$.isFloat = $1.isFloat; // passer la valeur au non-terminale suivant
        strcpy($$.valeur, "1");
    }| 
    EXPRESSION_2 sym_div EXPRESSION_1 {
        // verifier la non-compatibilite de type
        char error[20];

        if ($1.isFloat != $3.isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", $2);
            yyerror(error);
            YYABORT;
        }

        // division par zero
        if (strcmp($3.valeur, "0") == 0) {
            yyerror("Division par 0");
            YYABORT;            
        }

        $$.isFloat = $1.isFloat; // passer la valeur au non-terminale suivant
        strcpy($$.valeur, "1");
    }|
    EXPRESSION_2 {
        $$.isFloat = $1.isFloat;
        strcpy($$.valeur, $1.valeur);
    };

EXPRESSION_2: 
    parenthese_ouv EXPRESSION_ARITHMETIQUE parenthese_fer {
        $$.isFloat = $2.isFloat;
        strcpy($$.valeur, $2.valeur);
    }|
    CST_TYPE {
        $$.isFloat = $1.isFloat; // copier le type de la constante
        strcpy($$.valeur, $1.valeur); // copier la valeur de la constante
    }|
    VARIABLE {
        $$.isFloat = $1.isFloat; // copier le type de la variable Integer ou Float
        strcpy($$.valeur, "1"); // on suppose que la valeur de la variable ne nous concerne pas si elle est egale a 0
    };

VARIABLE: idf SUITE_IDF {
    char error[30];
    // non declaration
    if (verifier_non_declaration($1)) {
        sprintf(error, "Non declaration de l'identificateur %s", $1);
        yyerror(error);
        YYABORT;
    };

    strcpy($$.nom, $1);
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

        $$.isFloat = taille;
        printf("isFloat : %d\n", taille);
    } else {
        taille = verifier_modification_const($1);

        // verifier si l'identificateur est un tableau
        if (verifier_si_tableau($1)) {
            sprintf(error, "Variable %s est un tableau", $1);
            yyerror(error);
            YYABORT;
        }

        $$.isFloat = type_identificateur($1);
    }
};

SUITE_IDF: 
    crochet_ouv cst_entier crochet_fer {
        $$.tableau = 1; // mettre tableau a vrai
        $$.index = $2; // remplir la taille du tableau
    } 
    | {
        $$.tableau = 0; // mettre tableau a faux
    };

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
    CST_TYPE;
    
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
    // afficher_table_separateur_mot();
    afficher_table_variables();
    return 0;
}
yywrap () {}

void yyerror(const char *msg) {
    printf("Erreur syntaxique : %s à la ligne %d, colonne %d\n", msg, nb_ligne, col);
}