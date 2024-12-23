%{
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
%}

// la structure entite est utilisee pour representer une entite

%code requires {
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
}

%union {
    int entier;
    float real;
    char* str;
    // definir un nouveau type complexe (struct)
    struct entite entite;
    struct constante constante;
}

%token mc_import mc_io mc_lang mc_isil mc_programme mc_debut mc_dec mc_fin mc_final <str> mc_int <str> mc_float
%token point pvg vg separateur crochet_ouv crochet_fer parenthese_ouv parenthese_fer aff inc oper_initialisation
%token <str> sym_mul sym_div sym_plus sym_moins
%token mc_for mc_do mc_endfor mc_if mc_endif mc_else mc_input mc_write
%token <str> idf <entier> cst_entier <real> cst_reel
%token oper_et oper_ou oper_negation
%token <str> oper_sup_egal oper_inf_egal oper_sup oper_inf oper_inegalite oper_egalite
%token err
%token <str> chaine_caractere
%right aff

%start S

%type <entier> Type COMPARAISON COMPARAISON1
%type <entite> VARIABLE
%type <constante> CST_TYPE EXPRESSION_1 EXPRESSION_2 EXPRESSION_ARITHMETIQUE
%type <str> INCREMENTATION_COMPTEUR INITIALISATION_COMPTEUR
%%

S: Block_LIB Block_Prog  { printf("Programme Correcte.\n"); YYACCEPT; };

// PARITE DECLARATION DES BIBLIOTHEQUES
Block_LIB:
    mc_import mc_isil point NOM_BIB pvg Block_LIB | 
    ;

NOM_BIB: 
    mc_lang {
        // la bibliotheque est deja declare
        if (!declarer_biblio_lang()) {
            erreur_semantique("La bibliotheque lang est deja declaree");
            return;
        }
    }| 
    mc_io {
        if (!declarer_biblio_io()) {
            erreur_semantique("La bibliotheque io est deja declaree");
            return;
        }
    };

// LA STRUCTURE DU PROGRAMME

Block_Prog: mc_programme idf mc_dec Block_DEC PARTIE_INTRUCTIONS ;

// PARITE DECLARATION DES VARIABLES

Block_DEC : 
    Block_DEC_Var Block_DEC |
    Block_DEC_Const Block_DEC |
	;

// Declaration d'une variable
Block_DEC_Var: Type List_Idf_V_T pvg;

List_Idf_V_T: 
    V_T separateur List_Idf_V_T |
    V_T;

V_T: idf SUITE_VT {
    char *typeAttendu = (isFloat == 1) ? "Float" : "Integer";
    if (isFloat != typeRecuIsFloat && isTableau == 0) {
        sprintf(error, "Erreur sémantique : type incompatible. Attendu '%s'.", typeAttendu);
        erreur_semantique(error);
        return;
    }

    int status = remplir_variable($1, "identificateur", isFloat, valeur, 0, isTableau);

    if (status == 0) {
        sprintf(error, "Double declaration de l'identificateur: %s", $1);
        erreur_semantique(error);
        return;
    }
};

// la partie qui suit le nom de la variable elle peut prendre ([] (tableau), = (initialisation), epsilon (variable non initialisee))
SUITE_VT: 
    crochet_ouv cst_entier crochet_fer {
        isTableau = 1;
        sprintf(valeur, "%d", $2);
    } | 
    oper_initialisation CST_TYPE {
        isTableau = 0;
    } | {
        isTableau = 0;
        strcpy(valeur, " ");
    };

// Declaration d'une constante
// le meme processus que celui des variables
Block_DEC_Const: mc_final Type LIST_AFF pvg;				

LIST_AFF : 
    Affect_FINALE |
    Affect_FINALE separateur LIST_AFF;

Affect_FINALE: idf oper_initialisation CST_TYPE {
    char *typeAttendu = (isFloat == 1) ? "Float" : "Integer";
    if (isFloat != typeRecuIsFloat) {
        sprintf(error, "Erreur sémantique : type incompatible. Attendu '%s'.", typeAttendu);
        erreur_semantique(error);
        return;
    }
    int status = remplir_variable($1, "identificateur", isFloat, valeur, 1, 0);

    if (status == 0) {
        sprintf(error, "Double declaration de l'identificateur: %s", $1);
        erreur_semantique(error);
        return;
    }
};

// les constantes reelles et entiere
CST_TYPE :	
    cst_entier {
        typeRecuIsFloat = 0;
        $$.isFloat = 0;

        sprintf(valeur, "%d", $1); // copier la valeur entiere dans une chaine de caractere
        strcpy($$.valeur, valeur);
    } |
    cst_reel {
        typeRecuIsFloat = 1;
        $$.isFloat = 1;

        gcvt($1, 10, valeur); // copier la valeur reelle dans une chaine de caractere
        strcpy($$.valeur, valeur);
    };

// Le mot cle qui definie le type Integer, Float
// Equivalent a isFloat
Type: 
    mc_float {isFloat = 1;} | 
    mc_int {isFloat = 0;};

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
    
    if (!$1.isTableau) {
        if (verifier_modification_const($1.nom) == -1) {
            sprintf(error, "Modification de la valeur d'une constante %s", $1.nom);
            erreur_semantique(error);
            return;
        }
    }
    
    int type = $1.isFloat;
    // verifier la non compatibilite de type
    if (type != $3.isFloat) {
        char* typeAttendu = type ? "Float" : "Integer";
        char* typeRecu = $3.isFloat ? "Float" : "Integer";

        sprintf(error, "Non compatibilite de type, type attendu (l'identificateur %s): %s, type recu: %s", $1.nom, typeAttendu, typeRecu);
        erreur_semantique(error);
        return;
    }
};

EXPRESSION_ARITHMETIQUE: 
    EXPRESSION_1 sym_plus EXPRESSION_ARITHMETIQUE {
        // verifier la non-compatibilite de type

        if ($1.isFloat != $3.isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", $2);
            erreur_semantique(error);
            return;
        }

        $$.isFloat = $1.isFloat; // passer la valeur au non-terminale suivant
        strcpy($$.valeur, "1");
    }| 
    EXPRESSION_1 sym_moins EXPRESSION_ARITHMETIQUE {
        // verifier la non-compatibilite de type

        if ($1.isFloat != $3.isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", $2);
            erreur_semantique(error);
            return;
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

        if ($1.isFloat != $3.isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", $2);
            erreur_semantique(error);
            return;
        }

        $$.isFloat = $1.isFloat; // passer la valeur au non-terminale suivant
        strcpy($$.valeur, "1");
    }| 
    EXPRESSION_2 sym_div EXPRESSION_1 {
        // verifier la non-compatibilite de type

        if ($1.isFloat != $3.isFloat) {
            sprintf(error, "Non-compatibilite de type dans l'operation : %s", $2);
            erreur_semantique(error);
            return;
        }

        // division par zero
        if (strcmp($3.valeur, "0") == 0) {
            yyerror("Division par 0");
            return;            
        }

        $$.isFloat = $1.isFloat; // passer la valeur au non-terminale suivant
        strcpy($$.valeur, "1");
    }|
    EXPRESSION_2 {
        if (!verifier_biblio_lang_declaree()) {
            erreur_semantique("La bibliotheque lang n'est pas declaree");
            return;
        }

        $$.isFloat = $1.isFloat;
        strcpy($$.valeur, $1.valeur);
    };

EXPRESSION_2: 
    parenthese_ouv EXPRESSION_ARITHMETIQUE parenthese_fer {
        $$ = $2;
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
    // non declaration
    if (verifier_non_declaration($1)) {
        sprintf(error, "Non declaration de l'identificateur %s", $1);
        erreur_semantique(error);
        return;
    };

    // si l'entite est un tableau
    if (isTableau == 1) {
        int taille;
        // verifier le depassement de la taille
        taille = verifier_taille_tableau($1, indiceTableau);

        // traitement des erreurs semantiques
        if (taille == -1) {
            sprintf(error, "Depassement de la taille du tableau %s", $1);
            erreur_semantique(error);
            return;
        } else if (taille == -2) {
            sprintf(error, "Variable %s n'est pas un tableau", $1);
            erreur_semantique(error);
            return;
        }

        $$.isFloat = taille;
    } else {

        // verifier si l'identificateur est un tableau
        if (est_tableau($1)) {
            sprintf(error, "Variable %s est un tableau", $1);
            erreur_semantique(error);
            return;
        }

        $$.isFloat = type_variable($1);
    }

    strcpy($$.nom, $1);
    $$.isTableau = isTableau;
};

SUITE_IDF: 
    crochet_ouv cst_entier crochet_fer {
        isTableau = 1;
        indiceTableau = $2;
    } 
    | {
        isTableau = 0; // mettre tableau a faux
    };

// on suppose que la variable de la partie initialisation doit figurer dans la partie incrementation
INSTRUCTION_FOR: mc_for parenthese_ouv PARAMETRE_BOUCLE parenthese_fer mc_do BLOC_INSTRUCTIONS mc_endfor;

PARAMETRE_BOUCLE: INITIALISATION_COMPTEUR pvg CONDITION pvg INCREMENTATION_COMPTEUR {
    if (strcmp($1, $5) != 0) {
        sprintf(error, "La varaible %s de la partie initialisation doit etre incrementee", $1);
        erreur_semantique(error);
        return;
    }
};

INITIALISATION_COMPTEUR: idf aff EXPRESSION_ARITHMETIQUE {
    int type = type_variable($1);

    // verifier l'inexistance
    if (type == -1) {
        sprintf(error, "Non declaration de l'identificateur %s", $1);
        erreur_semantique(error);
        return;
    }
    
    // verifier s'il s'agit d'un tableau
    if (est_tableau($1)) {
        sprintf(error, "Compteur %s ne doit pas etre un tableau", $1);
        erreur_semantique(error);
        return;
    }

    // le compteur doit etre un Integer
    if (type == 1) {
        sprintf(error, "Compteur %s doit etre un Integer", $1);
        erreur_semantique(error);
        return;
    }

    // l'affectation recue est de type Float
    if (type != $3.isFloat) {
        char* typeAttendu = type ? "Float" : "Integer";
        char* typeRecu = $3.isFloat ? "Float" : "Integer";

        sprintf(error, "Non compatibilite de type, type attendu (l'identificateur %s): %s, type recu: %s", $1, typeAttendu, typeRecu);
        erreur_semantique(error);
        return;
    }

    $$ = $1;
};

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
    COMPARAISON1 oper_inf COMPARAISON {
        if ($1 != $3) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", $2);
            erreur_semantique(error);
            return;
        }
    } |
    COMPARAISON1 oper_inf_egal COMPARAISON  {
        if ($1 != $3) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", $2);
            erreur_semantique(error);
            return;
        }
    }|
    COMPARAISON1 oper_sup COMPARAISON  {
        if ($1 != $3) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", $2);
            erreur_semantique(error);
            return;
        }
    }|
    COMPARAISON1 oper_sup_egal COMPARAISON  {
        if ($1 != $3) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", $2);
            erreur_semantique(error);
            return;
        }
    }|
    COMPARAISON1 oper_egalite COMPARAISON  {
        if ($1 != $3) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", $2);
            erreur_semantique(error);
            return;
        }
    }|
    COMPARAISON1 oper_inegalite COMPARAISON  {
        if ($1 != $3) {
            sprintf(error, "Non compatibilite de type dans la comparaison %s", $2);
            erreur_semantique(error);
            return;
        }
    }|
    COMPARAISON1 {$$ = $1;};

COMPARAISON1:
    VARIABLE {
        $$ = type_variable($1.nom);
    }|
    CST_TYPE {$$ = $1.isFloat;};

INCREMENTATION_COMPTEUR: idf inc {
    $$ = $1;
};

INSTRUCTION_IF: 
    mc_if parenthese_ouv CONDITION parenthese_fer mc_do BLOC_INSTRUCTIONS mc_endif |
    mc_if parenthese_ouv CONDITION parenthese_fer mc_do BLOC_INSTRUCTIONS mc_else BLOC_INSTRUCTIONS mc_endif;

INSTRUCTION_ENTREE_SORTIE:
    INSTRUCTION_ENTREE pvg {
        // verifier si la bib io est declaree
        if (!verifier_biblio_io_declaree()) {
            erreur_semantique("La bibliotheque io n'est pas declaree");
            return;
        }

        // initialiser les compteurs
        cpt_idf_ES = 0;
        cpt_signe_format = 0;
    }|
    INSTRUCTION_SORTIE pvg {
        // verifier si la bib io est declaree
        if (!verifier_biblio_io_declaree()) {
            erreur_semantique("La bibliotheque io n'est pas declaree");
            return;
        }

        // initialiser les compteurs
        cpt_idf_ES = 0;
        cpt_signe_format = 0;
    };

INSTRUCTION_ENTREE: mc_input parenthese_ouv chaine_caractere IDF_INPUT parenthese_fer {
    int i;

    // parcourir la chaine de caractere pour compter les signes de formattage
    for (i = 0; i < strlen($3) - 1; i++) {
        if ($3[i] == '%') {
            // un entier
            if ($3[i + 1] == 'd') {
                list_signe_format[cpt_signe_format] = 0;
                cpt_signe_format++;
                i++;
            } 
            // un reel
            else if ($3[i + 1] == 'f') {
                list_signe_format[cpt_signe_format] = 1;
                cpt_signe_format++;
                i++;
            } 
            // signe invalid
            else {
                sprintf(error, "Signe de formattage inexistant %c%c", '%', $3[i + 1]);
                erreur_semantique(error);
                return;
            }
        } 
        // si la chaine contient autre que les blancs et les signes
        else if ($3[i] != ' '){
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
};

IDF_INPUT: 
    vg VARIABLE IDF_INPUT {
        // verifier si l'idf est une constante
        if (verifier_modification_const($2.nom) == -1) {
            sprintf(error, "Modification de la valeur d'une constante %s", $2.nom);
            erreur_semantique(error);
            return;
        }

        // inserer les types dans la fin du tableau
        list_type_idf_ES[19 - cpt_idf_ES] = type_variable($2.nom);
        cpt_idf_ES++;
    }|
    vg VARIABLE {
        // verifier si l'idf est une constante
        if (verifier_modification_const($2.nom) == -1) {
            sprintf(error, "Modification de la valeur d'une constante %s", $2.nom);
            erreur_semantique(error);
            return;
        }

        // inserer les types dans la fin du tableau
        list_type_idf_ES[19 - cpt_idf_ES] = type_variable($2.nom);
        cpt_idf_ES++;
    };

INSTRUCTION_SORTIE: mc_write parenthese_ouv chaine_caractere IDF_WRITE parenthese_fer {
    int i;

    for (i = 0; i < strlen($3); i++) {
        // compter les signes de formattage
        if ($3[i] == '%' && i < strlen($3) - 1) {
            // un entier
            if ($3[i + 1] == 'd') {
                list_signe_format[cpt_signe_format] = 0;
                cpt_signe_format++;
                i++;
            } 
            // un reel
            else if ($3[i + 1] == 'f') {
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
};

IDF_WRITE: 
    vg VARIABLE IDF_WRITE {
        // inserer les types dans la fin du tableau
        list_type_idf_ES[19 - cpt_idf_ES] = type_variable($2.nom);
        cpt_idf_ES++;
    } | ;
%%

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