code : **insertion dans une liste simplement chainee triee

1. **Structure cellule**:
   
Une cellule (ou nœud) contient :
un entier data
un pointeur suiv vers la cellule suivante

2. **creerCellule(int data)**
   
Alloue dynamiquement une cellule
Initialise ses champs (data et suiv)
Gère l’échec de l’allocation mémoire

3. **insererListe**
   
Insère un nouvel élément dans l’ordre croissant
Si la tête est NULL ou si la nouvelle valeur est plus petite que la tête → insertion en tête
Sinon, on parcourt la liste jusqu'à trouver la bonne place pour insérer

4. **affichelaListe**
   
Affiche les éléments de la liste avec un format valeur -> ... -> NULL
Gère le cas où la liste est vide

5. **main()**

Demande à l'utilisateur combien d’éléments il veut insérer
Crée une liste triée à partir des entrées
Affiche la liste
Permet à l’utilisateur d’insérer des éléments supplémentaires en boucle (tant qu’il répond "1")
Affiche la nouvelle liste finale

**En résumé** :

Le code permet :
de créer une liste chaînée triée,
d’y insérer dynamiquement des éléments,
et de l’afficher proprement.
