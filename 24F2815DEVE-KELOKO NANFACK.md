DOSSIER ALGORITHMIQUE:

PROBLEME: Lire un element et supprimer toutes ces occurences dans une liste simplement chainee.

PRINCIPE: le principe de cet algorithme est de maitriser l'operation d'insertion sur les listes simplement chainee

DICTIONNAIRE DE DONNEES:
 | Nom de la donnée | Type                        | Rôle / Description                                                          |
| ---------------- | --------------------------- | --------------------------------------------------------------------------- |
| `Element`        | `int`                       | Valeur à chercher et supprimer dans la liste chaînée                        |
| `Cellule`        | `struct Cellule`            | Structure représentant un maillon (ou nœud) de la liste                     |
| `val`            | `int`                       | Champ de `Cellule` : contient la valeur stockée                             |
| `suivant`        | `struct Cellule*`           | Champ de `Cellule` : pointeur vers le maillon suivant                       |
| `liste`          | `struct Cellule*`           | Pointeur vers le début de la liste chaînée                                  |
| `tmp`            | `struct Cellule*`           | Pointeur temporaire pour parcourir la liste                                 |
| `precedent`      | `struct Cellule*` (parfois) | Utilisé si on veut gérer la suppression proprement (avec lien vers l’avant) |

  ALGORITHME


  Début
    Lire x  // valeur à supprimer

    // Supprimer les premiers éléments si leur valeur est x
    Tant que liste ≠ NULL ET liste.val = x faire
        temp ← liste
        liste ← liste.suivant
        Libérer(temp)
    Fin Tant que

    // Maintenant on parcourt le reste de la liste
    p ← liste

    Tant que p ≠ NULL ET p.suivant ≠ NULL faire
        Si p.suivant.val = x alors
            temp ← p.suivant
            p.suivant ← p.suivant.suivant
            Libérer(temp)
        Sinon
            p ← p.suivant
        Fin Si
    Fin Tant que
Fin

 COMPLEXITE
 
