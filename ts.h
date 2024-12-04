#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef TS_H_   /* Include guard */
#define TS_H_

// designe une entite de type variable simple
typedef struct SymboleVariable {
    char* nom;              // Nom de l'entité
    char* code;             // Type (idf, const, etc.)
    bool isFloat;           // vrai => float, sinon => integer
    char valeur[10];             // Valeur si constante
    bool isConst;           // vrai si constante, faux sinon
    struct SymboleVariable* suivant;
} SymboleVariable;

SymboleVariable* tete_variables = NULL; // Pointeur vers la tête de la liste
SymboleVariable* queue_variables = NULL; // Pointeur vers la queue de la liste pour faciliter l'ajout

bool inserer_variable(char* nom, char* code, bool isFloat, char* valeur, bool isConst);
SymboleVariable* rechercher_variable(char* nom);
void afficher_table_variable();
bool verifier_double_declaration(char* nom);
bool verifier_non_declaration(char* nom);
bool verifier_type_compatible(char* nom, bool typeAttenduIsFloat);
bool verifier_modification_const(char* nom);
void liberer_table();

// designe une entite de type variable tableau 
typedef struct SymboleTableau {
    char* nom;
    bool isFloat;       // vrai float, sinon integer
    int taille;
    struct SymboleTableau* suivant;
} SymboleTableau;

SymboleTableau* tete_tableaux = NULL;
SymboleTableau* queue_tableaux = NULL;

SymboleTableau* rechercher_tableau(char* nom);
bool inserer_tableau(char* nom, bool isFloat, int taille);
bool verifier_taille_tableau(char* nom, int index);
void afficher_table_variable();

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

SymboleVariable* creer_noeud_symbol_variable(char* nom, char* code, bool isFloat, char valeur[], bool isConst) {
    SymboleVariable* nouveau = (SymboleVariable*)malloc(sizeof(SymboleVariable));

    // verifier si l'espace memoire a ete alloue
    if (nouveau == NULL) {
        printf("Erreur d'allocation memoire!");
        exit(EXIT_FAILURE);
    }
    nouveau->nom = strdup(nom);
    nouveau->code = strdup(code);
    nouveau->isFloat = isFloat;
    strcpy(nouveau->valeur, valeur);
    nouveau->isConst = isConst;
    nouveau->suivant = NULL;

    return nouveau;
}


bool inserer_variable(char* nom, char* code, bool isFloat, char *valeur, bool isConst) {
    // verifier si le nom est deja utilise
    if (rechercher_variable(nom)) {
        printf("Erreur sémantique : identificateur '%s' déjà déclaré.\n", nom);
        return false;
    }

    if (rechercher_tableau(nom)) {
        printf("Erreur sémantique : identificateur '%s' déjà déclaré. comme tableau\n", nom);
        return false;
    }

    // creer le noeud
    SymboleVariable* nouveau = creer_noeud_symbol_variable(nom, code, isFloat, valeur, isConst);

    // ajouter le chainage
    if (tete_variables == NULL) {
        // ajouter dans la tete de la liste
        tete_variables = queue_variables = nouveau;
    } else {
        // ajouter dans la fin de la liste
        queue_variables->suivant = nouveau;
        queue_variables = nouveau;
    }

    return true;
}

bool verifier_double_declaration(char* nom) {
    if (rechercher_variable(nom)) {
        printf("Erreur sémantique : identificateur '%s' déjà déclaré.\n", nom);
        return true;
    }

    return false;
}

bool verifier_non_declaration(char* nom) {
    if (!rechercher_variable(nom)) {
        printf("Erreur sémantique : identificateur '%s' non déclaré.\n", nom);
        return true;
    }

    return false;
}

// typeAttenduIsFloat est un boolean qui designe si la valeur affectee au variable est de type float
// true => float, false => integer 
bool verifier_type_compatible(char* nom, bool typeAttenduIsFloat) {
    SymboleVariable* symbole = rechercher_variable(nom);
    if (!symbole) {
        printf("Erreur sémantique : identificateur '%s' non déclaré.\n", nom);
        return false;
    }

    // comparer les types
    if (symbole->isFloat != typeAttenduIsFloat) {
        // extraire le type attendu
        char* typeAttendu = (symbole->isFloat) ? "FLOAT" : "INTEGER";
        printf("Erreur sémantique : type incompatible pour '%s'. Attendu '%s'.\n", nom, typeAttendu);
        return false;
    }

    return true;
}

bool verifier_modification_const(char* nom) {
    SymboleVariable* symbole = rechercher_variable(nom);
    if (symbole && symbole->isConst) {
        printf("Erreur sémantique : modification de la constante '%s' interdite.\n", nom);
        return true;
    }

    return false;
}

void afficher_table_variable() {
    SymboleVariable* ptr = tete_variables;

    printf("\n\t/***************Table des symboles des variables******************/\n");
    printf("\t______________________________________________________________________________\n");
    printf("\t| NomEntite\t    |   CodeEntite   |  TypeEntite  | ValeurEntite |  Constante |\n");
    printf("\t______________________________________________________________________________\n");
    while (ptr != NULL) {
        char* type = (ptr->isFloat) ? "Float" : "Integer";
        char* constante = (ptr->isConst) ? "Oui" : "Non";
        
        printf("\t|%18s | %10s | %12s | %12s |\t %s \t|\n", ptr->nom, ptr->code, type, ptr->valeur ,constante);
        ptr = ptr->suivant;
    }
    printf("\n\n");
}

// les fonctions de manipulation de la table de symboles des tableaux

SymboleTableau* rechercher_tableau(char* nom) {
    SymboleTableau* ptr = tete_tableaux;

    while (
        ptr != NULL &&
        (strcmp(nom, ptr->nom) != 0)
    ) {
        ptr = ptr->suivant;
    }

    return ptr;
}

SymboleTableau* creer_noeud_symbol_tableau(char* nom, bool isFloat, int taille) {
    SymboleTableau* nouveau = (SymboleTableau*)malloc(sizeof(SymboleTableau));

    // verifier si l'espace memoire a ete alloue
    if (nouveau == NULL) {
        printf("Erreur d'allocation memoire!");
        exit(EXIT_FAILURE);
    }
    nouveau->nom = strdup(nom);
    nouveau->isFloat = isFloat;
    nouveau->taille = taille;
    nouveau->suivant = NULL;

    return nouveau;
}

bool inserer_tableau(char* nom, bool isFloat, int taille) {
    // verifier si le nom est deja utilise
    if (rechercher_variable(nom)) {
        printf("Erreur sémantique : taleau '%s' déjà déclaré comme variable.\n", nom);
        return false;
    }

    if (rechercher_tableau(nom)) {
        printf("Erreur sémantique : taleau '%s' déjà déclaré.\n", nom);
        return false;
    }

    if (taille < 0) {
        printf("Erreur sémantique : la taille du tableau doit etre > 0");
        return false;
    }

    // creer le noeud
    SymboleTableau* nouveau = creer_noeud_symbol_tableau(nom, isFloat, taille);

    // ajouter le chainage
    if (tete_tableaux == NULL) {
        // ajouter dans la tete de la liste
        tete_tableaux = queue_tableaux = nouveau;
    } else {
        // ajouter dans la fin de la liste
        queue_tableaux->suivant = nouveau;
        queue_tableaux = nouveau;
    }

    return true;
}

bool verifier_taille_tableau(char* nom, int index) {
    SymboleTableau* symbole = rechercher_tableau(nom);
	if (symbole && symbole->taille >0 &&  index <=0){
		printf("Erreur sémantique : taille du tableau doit etre positive");
        return false;
	}
		
    if (symbole && symbole->taille > 0 && index >= symbole->taille) {
        printf("Erreur sémantique : dépassement de la taille du tableau '%s'.\n", nom);
        return false;
    }

    return true;
}

void afficher_table_tableaux() {
    SymboleTableau* ptr = tete_tableaux;

    printf("\n\t/***************Table des symboles des tableaux******************/\n");
    printf("\t______________________________________________________\n");
    printf("\t|     NomEntite     |  TypeEntite  |  TailleTableau  |\n");
    printf("\t______________________________________________________\n");

    while (ptr != NULL) {
        char* type = (ptr->isFloat) ? "Float" : "Integer";
        
        printf("\t|%18s | %10s   | %14d  |\n", ptr->nom, type, ptr->taille);
        ptr = ptr->suivant;
    }
    printf("\n\n");
}

#endif
