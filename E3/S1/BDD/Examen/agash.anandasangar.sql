--  Utilisez le script quidditch.sql afin de créer la base de données qui sera utilisée pour les questions suivantes.
--  Prenez le temps de vous familiariser avec les différentes tables et leur contenu avant de commencer à répondre aux questions.
--  Pour chaque question, donnez la requête SQL permettant d'obtenir le résultat demandé, et ajoutez en commentaire le nombre de lignes renvoyées par cette requête. Pour les requêtes ne renvoyant qu'une seule ligne, indiquez également la ligne renvoyée.
--  Soignez la présentation (indentation, nom des variables, etc.) de vos requêtes. La lisibilité de votre travail sera prise en compte.
--  A la fin du TP, déposez votre fichier dans la zone de rendu prévue à cet effet sur elearning.
--  Pensez à enregistrer régulièrement votre travail afin de ne pas le perdre en cas de panne.
--
--
--1. La liste de toutes les équipes, avec tous leurs attributs.

SELECT * FROM equipe;
-- 12 lignes

--2. La liste des rôles dans une équipe de Quidditch, sans doublons.

SELECT DISTINCT role FROM joueur;
-- 4 lignes

--3. Le nom complet (prénom nom) des joueurs de sexe masculin.

SELECT DISTINCT CONCAT(prenom, ' ',nom) as nom_complet FROM joueur WHERE sexe = 'M';
--61 lignes

--4. La liste des match (idmatch, lieu, date) qui ont eu lieu en décembre 2023.

SELECT idmatch, lieu, date FROM match WHERE date >= '2023-12-01' AND date <= '2023-12-31';
--19 lignes

--5. La liste des batteurs (numlicence, nom, prenom) qui n'ont actuellement pas d'équipe.

SELECT numlicence, nom, prenom FROM joueur WHERE role = 'Batteur' AND idE is NULL;
-- 9 lignes

--6. La liste des équipes (idE, nomE) qui ont marqué au moins 440 points lors d'un match à Paris.

SELECT idE, nomE FROM equipe NATURAL JOIN participe NATURAL JOIN match WHERE score >= 440 AND lieu = 'Paris';
-- 3 lignes

--7. La liste de toutes les équipes (nomE, pays) avec pour chacune le prénom et rôle de son capitaine.

SELECT nomE, pays, prenom, role FROM equipe NATURAL JOIN joueur WHERE capitaine = numlicence;
-- 12 lignes

--8. Le batteur (prenom, nom, date de naissance) le plus jeune.

SELECT prenom, nom, naissance FROM joueur ORDER BY naissance DESC LIMIT 1;
-- 1 ligne

--9. Les équipes (idE, nomE) mixtes, c'est-à-dire qui ont au moins un joueur et une joueuse.

SELECT idE, nomE FROM equipe NATURAL JOIN joueur WHERE sexe = 'F' 
INTERSECT 
SELECT idE, nomE FROM equipe NATURAL JOIN joueur WHERE sexe = 'M'; 
-- 8 lignes

--10. Les villes dans lesquelles l'équipe de France n'a jamais gagné.

SELECT DISTINCT lieu FROM match 
EXCEPT 
SELECT DISTINCT lieu FROM match 
NATURAL JOIN gagnant NATURAL JOIN equipe WHERE pays = 'France';
-- 1 ligne

--11. Le score moyen de l'équipe d'Italie.

SELECT AVG(score) as moyScoreItalie FROM participe NATURAL JOIN equipe WHERE pays = 'Italie';
-- 1 ligne

--12. La liste des villes, avec pour chacune le nombre de matchs qui y ont été joués, triée par nombre de matchs décroissant.

SELECT lieu, COUNT(*) as nbmatch FROM match GROUP BY lieu ORDER BY COUNT(*) DESC;
-- 12 lignes

--13. La liste des équipes (idE, nomE) avec pour chacune le nombre de matchs nuls qu'elle a faits. Attention à ne pas oublier les équipes qui n'ont jamais fait de match nul !

SELECT DISTINCT idE,
                nomE
FROM equipe
NATURAL JOIN participe
NATURAL JOIN MATCH
JOIN
  (SELECT idmatch
   FROM gagnant
   WHERE idE IS NULL) match_null ON match_null.idmatch;
-- 7 lignes

--14. La liste des attrapeurs (numlicence, prenom, nom) qui ont attrapé au moins 30 vifs d'or, triés par nombre de vifs d'or décroissant.

SELECT numlicence,
       prenom,
       nom
FROM joueur
NATURAL JOIN equipe
JOIN MATCH ON vifdor = idE
WHERE ROLE = 'Attrapeur'
GROUP BY numlicence,
         prenom,
         nom
HAVING COUNT(vifdor) >= 30
ORDER BY COUNT(vifdor) DESC;
-- 7 lignes

--15. La liste des matchs dans lesquels le gagnant a battu le perdant de plus de 350 points. On renverra l'identifiant du match, le nom et le score du gagnant, et le nom et le score du perdant.

SELECT p1.idmatch
FROM participe p1,
     participe p2
WHERE p1.score >= p2.score+350
  AND p1.idmatch = p2.idmatch;
-- 19 lignes

--16. Quel est le nombre moyen de matchs organisés par ville ?

SELECT lieu, (COUNT(*)*100/nbtotal) 
FROM match, (SELECT COUNT(*) as nbtotal FROM match) AS nbmatchtotal 
GROUP BY lieu, nbtotal;
-- 12 lignes

--17. En moyenne, quelle est la différence entre les scores des deux équipes dans une partie de Quidditch ?


SELECT AVG(moyscore2.difference2 + moyscore1.difference1)
FROM (SELECT p1.idmatch,
          sum(p1.score-p2.score) AS difference1
   FROM participe p1,
        participe p2
   WHERE p1.idmatch = p2.idmatch
     AND p1.score > p2.score
   GROUP BY p1.idmatch,
            p2.idmatch) AS moyscore1,
    (SELECT p1.idmatch,
          sum(p1.score-p2.score) AS difference2
   FROM participe p1,
        participe p2
   WHERE p1.idmatch = p2.idmatch
     AND p1.score > p2.score
   GROUP BY p1.idmatch,
            p2.idmatch) AS moyscore2;
-- 1 ligne

--18. La liste des équipes (nomE, pays) avec pour chacune son Némésis, c'est-à-dire l'équipe contre laquelle elle a perdu le plus de matchs. Si une équipe a plusieurs Némésis, vous pourrez au choix renvoyer tous les Némésis ou seulement l'un d'entre eux.



--19. La liste des équipes (idE, nomE), avec pour chacune son taux de victoire, c'est-à-dire le pourcentage de matchs qu'elle a gagnés par rapport au nombre total de matchs qu'elle a joués. Le résultat devra être trié par taux de victoire décroissant.



--20. Les équipes qui ont gagné au moins un match dans chacune des villes. Attention, votre requête devra toujours fonctionner si de nouvelles villes sont ajoutées à la base de données.



