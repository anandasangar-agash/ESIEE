Exercice 3 : 

2. La méthode copySlow() met environ 1,6s à exécuter tandis que copyFast() met environ 2ms.
3. Si on double la taille de la liste, copySlow() mettra environ 6,4s (vu que la complexité de O(n²), on fais 2² * 1.6).
4. Si on double la taille de la liste, copyFast() mettra environ 4ms (vu que la complexité de O(n), on fais 2 * 2).

Exercice 4 : 

equals renvoie true car on compare le contenu des listes et == renvoie false car on compare leur référence des deux listes.
La différence entre les deux, c'est que comparaison de référence regarde si les deux listes pointent vers la même adresse, si ils pointent vers la même adresse 
ça veut dire qu'ils ont le même contenu et comparaison de contenu on regarde un par un si ils ont les mêmes valeurs.