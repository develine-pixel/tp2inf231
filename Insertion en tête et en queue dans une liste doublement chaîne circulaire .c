#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int data;
    struct cellule* suiv;
}cellule;

cellule* creerCellule(int data){
    cellule* cel = (cellule*)malloc(sizeof(cellule));
    if(cel == NULL){
        printf("Erreur d'allocation memoire\n");
        exit (1);
        
    }
    cel->data = data;
    cel->suiv = NULL;
    return cel;
}
cellule* insererenTete(cellule* tete, int data){
    cellule* newtete = creerCellule(data);
    newtete->suiv = tete;
    return newtete;
}
void affichelaListe(cellule* tete){
    if(tete == NULL){
        printf("La liste est vide");
        return;
    }
    cellule* courant = tete;
    while (courant != NULL)
    {
        printf("%d -> ", courant->data);
        courant = courant->suiv;
    }
    printf("NULL\n");
}
cellule* supprimeOccurrence(cellule* tete, int val){
    if (tete == NULL)
    {
        printf("La liste est vide rien a supprimer");
        return tete;
    }
    int trouve = 0;
    while (tete != NULL && tete->data == val)
    {
        trouve = 1;
        cellule* temp = tete;
        tete = tete->suiv;
        free(temp);
    }
    cellule* courant = tete;
    while (courant != NULL && courant->suiv != NULL)
    {
        if(courant->suiv->data == val){
            trouve = 1;
            cellule* temp = courant->suiv;
            courant->suiv = courant->suiv->suiv;
            free (temp);
        }else{
            courant = courant->suiv;
        }
    }
    if(!trouve){
        printf("La valeur n'a pas ete trouver dans la liste\n");
    }else{
        printf("Toutes les occurrences de %d ont ete supprimer\n", val);
    }
    return tete;
}

int main(){
    cellule* tete = NULL;
    int data, val, i, n, choix;

    printf("Entrer le nombres d'elements de la liste : ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Entrer l'element %d : ", i+1);
        scanf("%d", &data);
        tete = insererenTete(tete, data);
    }
    printf("La liste initiale est : ");
    affichelaListe(tete);

    do{
        printf("Entrer la valeur a supprimer : ");
        scanf("%d", &val);
        tete = supprimeOccurrence(tete, val);
        printf("Voulez vous supprimer une autre valeur ? (oui = 1, non = 0) : ");
        scanf("%d", &choix);
    }while (choix == 1);
    printf("programme terminer . Voici la liste final : ");
    affichelaListe(tete);
    return 0;
}