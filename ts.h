#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// todo regler le probleme des float
// taches restantes :
/*
    1. Instruction For
    2. Instruction If
    3. les bibliotheques
    4. les entrees sorties
*/

// designe une entite de type variable simple
typedef struct SymboleVariable {
    bool status;            // le champ est-il rempli
    char* nom;              // Nom de l'entité
    char* code;             // Type (idf, const, etc.)
    bool isFloat;           // vrai => float, sinon => integer
    bool isConst;           // vrai si constante, faux sinon
    bool isTableau;         // vrai si la variable est un tableau
    char valeur[10];        // Valeur si c'est une varibale, indice si c'est un tableau
    struct SymboleVariable* suivant;
} SymboleVariable;

SymboleVariable* tete_variables = NULL; // Pointeur vers la tête de la liste des variables simples
SymboleVariable* queue_variables = NULL; // Pointeur vers la queue de la liste pour faciliter l'ajout

bool remplir_variable(char* nom, char* code, bool isFloat, char* valeur, bool isConst, bool isTableu);
void inserer_variable(char* nom);
SymboleVariable* rechercher_variable(char* nom);
void afficher_table_variables();
bool verifier_double_declaration(char* nom);
bool verifier_non_declaration(char* nom);
int type_variable(char* nom);
bool verifier_type_compatible(char* nom, bool typeAttenduIsFloat);
int verifier_modification_const(char* nom);
bool verifier_si_tableau(char* nom);
int verifier_taille_tableau(char* nom, int index);
void afficher_table_variables();

SymboleVariable* rechercher_variable(char* nom) {
    SymboleVariable *ptr = tete_variables;

    // parcourir le tableau
    while (
        ptr != NULL && 
        (strcmp(ptr->nom, nom) != 0)    
    ) {
        ptr = ptr->suivant;
    }

    return ptr;
}

SymboleVariable* creer_noeud_symbol_variable(char* nom) {
    SymboleVariable* nouveau = (SymboleVariable*)malloc(sizeof(SymboleVariable));

    // verifier si l'espace memoire a ete alloue
    if (nouveau == NULL) {
        printf("Erreur d'allocation memoire!");
        exit(EXIT_FAILURE);
    }
    
    nouveau->nom = strdup(nom);
    nouveau->code = "identificateur";
    nouveau->status = false;
    strcpy(nouveau->valeur, "");
    nouveau->isConst = false;
    nouveau->isFloat = false;
    nouveau->isTableau = false;
    nouveau->suivant = NULL;

    return nouveau;
}

void inserer_variable(char* nom) {

    if (rechercher_variable(nom) != NULL) {
        return;
    }
    // creer le noeud
    SymboleVariable* nouveau = creer_noeud_symbol_variable(nom);

    // ajouter le chainage
    if (tete_variables == NULL) {
        // ajouter dans la tete de la liste
        tete_variables = queue_variables = nouveau;
    } else {
        // ajouter dans la fin de la liste
        queue_variables->suivant = nouveau;
        queue_variables = nouveau;
    }
}

bool remplir_variable(char* nom, char* code, bool isFloat, char *valeur, bool isConst, bool isTableau) {
    SymboleVariable* symbole = rechercher_variable(nom);
    
    // erreur nom reconnue
    if (symbole == NULL) {
        printf("Erreur sémantique : identificateur '%s' n'est pas reconnu.\n", nom);
        return false;
    }

    // idf deja declare
    if (symbole->status) {
        return false;
    }

    // remplir les champs
    symbole->status = true;
    strcpy(symbole->valeur, valeur);
    symbole->isConst = isConst;
    symbole->code = code;
    symbole->isFloat = isFloat;
    symbole->isTableau = isTableau;

    return true;
}

bool verifier_double_declaration(char* nom) {
    SymboleVariable* existant = rechercher_variable(nom);

    if (existant->status) {
        return true;
    }

    return false;
}

bool verifier_non_declaration(char* nom) {
    SymboleVariable* existant = rechercher_variable(nom);

    // si le champ n'est pas rempli => status = 0 = false
    if (!existant->status) {
        return true;
    }

    return false;
}

// retourne le type de l'entite
// -1 si l'identificateur n'existe pas
int type_variable(char* nom) {
    SymboleVariable* variable = rechercher_variable(nom);

    // verifier l'existance
    if (!variable->status) {
        return -1;
    }

    return variable->isFloat;
}

// verifier si l'identificateur est un tableau
int est_tableau(char* nom) {
    SymboleVariable* variable = rechercher_variable(nom);

    // verifier l'existance
    if (!variable->status) {
        return -1;
    }

    return variable->isTableau;
}

// typeAttenduIsFloat est un boolean qui decrit le type de la valeur affectee a la variable
// true => float, false => integer 
bool verifier_type_compatible(char* nom, bool typeAttenduIsFloat) {
    SymboleVariable* symbole = rechercher_variable(nom);
    if (!symbole) {
        printf("Erreur sémantique : identificateur '%s' non déclaré.\n", nom);
        return false;
    }

    // comparer les types
    if (symbole->isFloat != typeAttenduIsFloat) {
        return false;
    }

    return true;
}

// verifier si l'entite est une constante et retourne -1
// sinon elle retourne le type de l'entite
int verifier_modification_const(char* nom) {
    SymboleVariable* entite = rechercher_variable(nom);

    if (entite->isTableau) {
        return -2;
    }
    if (entite->isConst) {
        return -1;
    }

    return entite->isFloat;
}

bool verifier_si_tableau(char* nom) {
    SymboleVariable* entite = rechercher_variable(nom);

    return entite->isTableau;
}

// verifier si la taille du tableau ete depasse et retourne -1
// sinon elle retroune le type de l'entite Float ou Integer
int verifier_taille_tableau(char* nom, int index) {
    SymboleVariable* entite = rechercher_variable(nom);

    int tailleTableau = atoi(entite->valeur);

    // verifier si l'entite est un tableau
    if (!entite->isTableau) {
        return -2;
    }

    // verifier le depassement de la taille
    if (tailleTableau <= index || index < 0) {
        return -1;
    }
    return entite->isFloat;
}

void afficher_table_variables() {
    SymboleVariable* ptr = tete_variables;

    printf("\n\t/***************Table des symboles des variables******************/\n");
    printf("\t________________________________________________________________________________________________\n");
    printf("\t| NomEntite\t    |   CodeEntite   |  TypeEntite  | ValeurEntite |  Constante |    Tableau    |\n");
    printf("\t|___________________|________________|______________|______________|____________|_______________|\n");
    while (ptr != NULL) {
        char* type = (ptr->isFloat) ? "Float" : "Integer";
        char* constante = (ptr->isConst) ? "Oui" : "Non";
        char* tableau = (ptr->isTableau) ? "Oui": "Non";
        char* valeur = (ptr->valeur == NULL) ? "" : ptr->valeur;
        
        printf("\t|%18s | %10s | %12s | %12s |\t %s \t|\t %s \t|\n", ptr->nom, ptr->code, type, ptr->valeur ,constante, tableau);
        ptr = ptr->suivant;
    }

printf("\t|___________________|________________|______________|______________|____________|_______________|\n");    printf("\n\n");
}

typedef struct TypeSM{
    char nom[20];
    char type[20];
    struct TypeSM* suivant;
} TypeSM;

TypeSM* tete_separateurs = NULL;
TypeSM* queue_separateurs = NULL;

TypeSM* tete_mots_cles = NULL;
TypeSM* queue_mots_cles = NULL;

TypeSM* rechercher_mots_separateurs(bool isSeparateur, char nom[]);
TypeSM* creer_noeud_separateur_mots_separateurs(bool isSeparateur, char nom[]);
void inserer_mots_separateurs(bool isSeparateur, char nom[]);
void afficher_table_separateur_mot();

TypeSM* rechercher_mots_separateurs(bool isSeparateur, char nom[]) {
    TypeSM* ptr = (isSeparateur) ? tete_separateurs : tete_mots_cles;

    while ((ptr != NULL) && (strcmp(nom, ptr->nom) != 0)) {
        ptr = ptr->suivant;
    }

    return ptr;
}

TypeSM* creer_noeud_separateur_mots_separateurs(bool isSeparateur, char nom[]) {
    TypeSM* nouveau = (TypeSM*)malloc(sizeof(TypeSM));
    
    // verifier si l'espace memoire a ete alloue
    if (nouveau == NULL) {
        printf("Erreur d'allocation memoire!");
        exit(EXIT_FAILURE);
    }

    char type[20];
    strcpy(type, ((isSeparateur) ? "Separateur" : "Mot cle"));

    strcpy(nouveau->nom, nom);
    strcpy(nouveau->type, type);

    nouveau->suivant = NULL;

    return nouveau;
}

void inserer_mots_separateurs(bool isSeparateur, char nom[]) {
    // verifier si l'entite est deja inseree
    if (rechercher_mots_separateurs(isSeparateur, nom) != NULL) {
        return;
    }

    TypeSM* nouveau = creer_noeud_separateur_mots_separateurs(isSeparateur, nom);

    if (isSeparateur && tete_separateurs == NULL) {
        tete_separateurs = queue_separateurs = nouveau;
        return;
    } 
    
    if (!isSeparateur && tete_mots_cles == NULL) {
        tete_mots_cles = queue_mots_cles = nouveau;
        return;
    }

    TypeSM* queue = (isSeparateur) ? queue_separateurs : queue_mots_cles;
    queue->suivant = nouveau;
    
    if (isSeparateur) {
        queue_separateurs = nouveau;
    } else {
        queue_mots_cles = nouveau;
    }
}


void afficher_table_separateur_mot() {
    TypeSM* ptr = tete_mots_cles;

    printf("\n/***************Table des symboles mots cles*************/\n");
    printf("\t___________________________\n");
    printf("\t| NomEntite |  CodeEntite | \n");
    printf("\t|___________|_____________|\n");
    
    while (ptr != NULL) { 
        printf("\t|%10s |%12s | \n",ptr->nom, ptr->type);
        ptr = ptr->suivant;       
    }

    printf("\t|_________________________|\n");
    printf("\n\n");

    ptr = tete_separateurs;

    printf("\n/***************Table des symboles separateurs*************/\n");
    printf("\t___________________________\n");
    printf("\t| NomEntite |  CodeEntite | \n");
    printf("\t|___________|_____________|\n");
    
    while (ptr != NULL) { 
        printf("\t|%10s |%12s | \n",ptr->nom, ptr->type);
        ptr = ptr->suivant;       
    }

    printf("\t|_________________________|\n");
}
