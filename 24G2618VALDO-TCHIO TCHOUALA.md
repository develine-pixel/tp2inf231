DOSSIER ALGORITHMIQUE 

Problème : Écriture d’un code C qui permettra d’insérer un élément en tête et en queue d’une liste simplement chaînée circulaire.

Principes

Pour l’insertion en tête 
- créer un nouveau nœud
- si la liste est vide, le nouveau nœud pointe sur lui même
- sinon le nouveau nœud pointe vers l’ancien premier nœud, le dernier nœud de la liste doit pointer vers ce nouveau nœud et la tête devient ce nœud.

Pour l’insertion en queue
- créer un nouveau nœud
- s’il n’y a rien dans la liste, il pointe sur lui même.
- sinon, l’ancien dernier pointe sur le nouveau, le nouveau pointe sur la tête, le nouveau devient le dernier.

Dictionnaire de données

Cellule: structure,représente un nœud de la liste circulaire contenant une information et un pointeur.

data: entier,valeur ou donnée stockée dans le nœud

next: pointeur(Cellule*), adresse du noeud suivant dans la liste.

liste: pointeur (Cellule*),pointeur vers le premier element(la tete) de la liste. Elle peut être nulle si la liste est vide

p: pointeur (Cellule*),variable temporaire utilisée lors de l’insertion d’un nouvel element.

t: pointeur (Cellule*),sert a parcourir la liste pour trouver le dernier element.

l: pointeur (Cellule*), variable qui garde l’adresse du premier element de la liste


Algorithmes

1) insertion en tete


cellule:enregistrement
	data: entier;
	suiv: ^cellule;
finenregistrement

liste =^ cellule ;
p,t:liste ;
liste l = NULL ;
procedure insererEnTete(var data : entier)
	allouer(p) ;
	p->data←data ;
	si (l=NULL) alors
		p→next ←p ;
		l←p ;
	sinon
		p→next←l->next ;
		l->next←p ;
	finsi
finprocedure


2) insertion en queue

procedure insererEnQueue(var data : entier)
	allouer(p) ;
	p->data←data ;
	si (l=NULL) alors
		p→next ←p ;
		l←p ;
	sinon
		p→next←l->next ;
		l->next←p ;
		l←p ;
	finsi
finprocedure

procedure afficherListe()
	si (l=NULL) alors
		ecrire(« liste vide ») ;
	finsi
	t = l→nextt ;
	repeter
		ecrire(t→data) ;
		t←t->next ;
	tantque(t<>l→next) ;
	ecrire(« (retourner au debut) ») ;
finprocedure

Debut
	insererEnTete(10) ;
	insererEnQueue(11) ;
	ecrire(« Contenu de la liste circulaire ») ;
	afficherListe() ;
fin

Complexité
1. Insertion en tête
    • Si on ne connaît pas directement le dernier élément, on doit parcourir la liste pour le trouver → O(n) dans le pire des cas (n = nombre d’éléments).
    • Si on garde un pointeur sur le dernier élément (appelé dernier), alors l’insertion en tête devient O(1) (constante).

2. Insertion en queue
    • Même principe :
        ◦ Sans pointeur dernier → on parcourt la liste jusqu’au dernier → O(n).
        ◦ Avec pointeur dernier → on insère directement → O(1)

