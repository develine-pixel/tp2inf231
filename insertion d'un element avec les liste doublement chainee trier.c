#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int data;
    struct cellule* suiv;
    struct cellule* prec;
}cellule;

cellule* creerCellule(int data){
    cellule* cel = (cellule*)malloc(sizeof(cellule));
    if(cel == NULL){
        printf("Erreur d'allocation memoire\n");
        exit (1);
    }
    cel->data = data;
    cel->suiv = NULL;
    cel->prec = NULL;
    return cel;
}
cellule* insererListe(cellule* tete, int data){
    cellule* newtete = creerCellule(data);
    if(tete == NULL || tete->data > data ){
    newtete->suiv = tete;
    newtete->prec = NULL;
    return newtete;
    }
    cellule* courant = tete;
    while(courant->suiv != NULL && courant->suiv->data < data){
        courant = courant->suiv;
    }
    newtete->suiv = courant->suiv;
    courant->suiv = newtete;
    newtete->prec = courant;
    return tete;
}
void affichelaListe(cellule* tete){
    if(tete == NULL){
        printf("La liste est vide");
        return;
    }
    cellule* courant = tete;
    while (courant != NULL)
    {
        printf("%d <-> ", courant->data);
        courant = courant->suiv;
    }
    printf("NULL\n");
}
int main(){
    cellule* tete = NULL;
    int data, i, n, choix;
    printf("Entrer le nombre d'element de la liste : ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Entrer l'element %d : ", i+1);
        scanf("%d", &data);
        tete = insererListe(tete, data);
    }
    printf("La liste trier est : ");
    affichelaListe(tete);

    do{
        printf("Entrer une valeur a ajouter a la liste : ");
        scanf("%d", &data);
        insererListe(tete, data);
        printf("voulez vous ajouter un element a la liste (1 = oui, 0 = non) ? : ");
        scanf("%d", &choix);
    }while(choix == 1);
    printf("La nouvelle liste trier est : ");
    affichelaListe(tete);
}