#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud
typedef struct Cellule {
    int data;
    struct Cellule* next;
} Cellule;

// Pointeur vers le dernier nœud (circulaire)
Cellule* l = NULL;

// Fonction pour insérer en tête
void insererEnTete(int data) {
    Cellule* p = (Cellule*)malloc(sizeof(Cellule));
    p->data = data;

    if (l == NULL) {
        // Liste vide
        p->next = p;
        l = p;
    } else {
        p->next = l->next;
        l->next = p;
    }
}

// Fonction pour insérer en queue
void insererEnQueue(int data) {
    Cellule* p = (Cellule*)malloc(sizeof(Cellule));
    p->data = data;

    if (l == NULL) {
        // Liste vide
        p->next = p;
        l = p;
    } else {
        p->next = l->next;
        l->next = p;
        l = p;
    }
}

// Fonction pour afficher la liste
void afficherListe() {
    if (l == NULL) {
        printf("Liste vide.\n");
        return;
    }

    Cellule* t = l->next;
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while (t != l->next);
    printf("(retour au début)\n");
}

// Exemple d'utilisation
int main() {
    insererEnQueue(10);
    insererEnTete(5);
    insererEnQueue(15);
    insererEnTete(1);

    printf("Contenu de la liste circulaire :\n");
    afficherListe();

    return 0;
}
