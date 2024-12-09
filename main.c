#include <stdio.h>
#include "ts.h"

int main() {
    // Test des fonctions
    if (ajouter("variable1")) {
        printf("Ajout de 'variable1' réussi.\n");
    } else {
        printf("'variable1' existe déjà.\n");
    }

    if (ajouter("variable2")) {
        printf("Ajout de 'variable2' réussi.\n");
    } else {
        printf("'variable2' existe déjà.\n");
    }

    if (ajouter("variable1")) {
        printf("Ajout de 'variable1' réussi.\n");
    } else {
        printf("'variable1' existe déjà.\n");
    }

    // Affichage des entités dans la table des symboles
    afficherTS();

    return 0;
}