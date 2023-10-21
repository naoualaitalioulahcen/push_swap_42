# push_swap_42

Le projet "push_swap" est un exercice de programmation qui fait partie du cursus de l'école 42, un établissement d'enseignement supérieur en informatique. Il vise à évaluer les compétences des étudiants en matière d'algorithmes et de manipulation de données.

Voici une définition détaillée du projet "push_swap" :

Nom du Projet: Push_swap

Objectif:

Le but de ce projet est de trier une pile d'entiers en utilisant deux piles distinctes (A et B) ainsi qu'un ensemble d'instructions spécifiques pour déplacer les éléments entre les piles. L'objectif est d'effectuer ces opérations de manière à ce que la pile A soit triée dans l'ordre croissant.

Fonctionnement:

Les Piles:

La pile A contient un ensemble d'entiers non triés au début du programme.
La pile B est initialement vide et servira comme une pile auxiliaire pour faciliter le tri.
Les Instructions:

L'exercice fournit un ensemble d'instructions qui permettent de manipuler les piles. Les instructions de base sont généralement limitées à :
sa: swap A - échange les deux premiers éléments de la pile A.
sb: swap B - échange les deux premiers éléments de la pile B.
ss: fait sa et sb en même temps.
pa: push A - déplace le premier élément de B vers A.
pb: push B - déplace le premier élément de A vers B.
ra: rotate A - déplace le premier élément de A à la fin.
rb: rotate B - déplace le premier élément de B à la fin.
rr: fait ra et rb en même temps.
rra: reverse rotate A - déplace le dernier élément de A au début.
rrb: reverse rotate B - déplace le dernier élément de B au début.
rrr: fait rra et rrb en même temps.
Objectif Final:

L'objectif est de trouver une séquence d'instructions qui permet de trier la pile A dans l'ordre croissant, en utilisant le moins d'opérations possible.
Contraintes:

Vous devez minimiser le nombre d'opérations.
Vous devez gérer les erreurs et les cas limites (comme une pile vide ou un seul élément).
Le programme doit être capable de gérer une pile d'un million d'entiers.
Évaluation:

Le projet "push_swap" est évalué en fonction de la qualité du code, de l'efficacité des algorithmes utilisés, et de la capacité à minimiser le nombre d'opérations nécessaires pour trier la pile. Les solutions qui effectuent le tri avec le moins d'opérations sont considérées comme les meilleures.

En résumé, le projet "push_swap" est un défi de programmation qui met l'accent sur la conception d'algorithmes efficaces pour résoudre un problème spécifique de manipulation de piles. Il encourage les étudiants à développer des compétences en algorithmique et en optimisation.
