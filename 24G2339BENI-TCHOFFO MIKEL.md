

📌 Résumé Exercice 5 – Insertion tête et queue dans une liste doublement chaînée circulaire

1. Une liste doublement chaînée circulaire est une suite de nœuds reliés entre eux.


2. Chaque nœud contient une valeur, un pointeur vers le suivant (next) et un pointeur vers le précédent (prev).


3. Comme elle est circulaire, le dernier élément pointe vers le premier, et le premier pointe vers le dernier.


4. Quand la liste est vide et qu’on insère, le nœud créé pointe sur lui-même (next = prev = lui-même).


5. Insertion en tête :

Créer un nouveau nœud.

Relier ce nœud à l’ancien premier et au dernier.

Ajuster les pointeurs du dernier et de l’ancien premier.

Mettre à jour la tête (head).



6. Insertion en queue :

Créer un nouveau nœud.

Relier ce nœud au premier et à l’ancien dernier.

Ajuster les pointeurs du premier et de l’ancien dernier.

La tête reste inchangée.



7. Ainsi, l’insertion est possible aux deux extrémités sans parcourir toute la liste.


8. L’affichage se fait en parcourant n éléments à partir de la tête pour éviter une boucle infinie.


9. Ce type de liste est utile car on peut circuler dans les deux sens (avant ↔ arrière).


10. Le code gère correctement les cas particuliers : liste vide ou un seul élément.

Voici par suite l'algorithme du code C de l'exercice 


📌 Algorithme

Début
Définir structure Noeud :

valeur

next

prev


Initialiser head ← NULL



Procédure InsertionEnTete(valeur)

1. Créer nœud N


2. Si head = NULL alors

N.next ← N

N.prev ← N

head ← N



3. Sinon

dernier ← head.prev

N.next ← head

N.prev ← dernier

dernier.next ← N

head.prev ← N

head ← N



Procédure InsertionEnQueue(valeur)

1. Créer nœud N


2. Si head = NULL alors

N.next ← N

N.prev ← N

head ← N



3. Sinon

dernier ← head.prev

N.next ← head

N.prev ← dernier

dernier.next ← N

head.prev ← N


Fin



