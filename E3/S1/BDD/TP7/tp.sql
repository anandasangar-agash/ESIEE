--	Utilisez le script soiree_exam.sql afin de créer la base de données qui sera utilisée pour les questions suivantes.
--	Prenez le temps de vous familiariser avec les différentes tables et leur contenu avant de commencer à répondre aux questions.
--	Pour chaque question, donnez la requête SQL permettant d'obtenir le résultat demandé. 
--  Ajoutez en commentaire le nombre de lignes renvoyées par cette requête. Si la requête renvoie une seule ligne, précisez également la ligne renvoyée.
--  Soignez la présentation (indentation, nom des variables, etc.) de vos requêtes. La lisibilité de votre travail sera prise en compte.
-- Exemple :

--0. La liste des étudiants en E3 qui ont suivi le cours de bases de données :

SELECT numEtud
FROM etudiant NATURAL JOIN suit
WHERE etudiant.annee = 'E3'
AND suit.cours = 'Bases de données';
-- 33 lignes

--	A la fin du TP, déposez votre fichier dans la zone de rendu prévue à cet effet sur elearning.
--  Pensez à enregistrer régulièrement votre travail afin de ne pas le perdre en cas de panne.
--
--
--1. La liste de toutes les personnes, avec tous leurs attributs.
SELECT *
FROM Personne;
--500 lignes


--2. La liste des villes où il y a une soirée, sans doublons.
SELECT DISTINCT lieu
FROM Soiree;
--31 lignes

--3. La liste des magasins qui vendent le costume ang82.
SELECT DISTINCT nomMag
FROM Vendre
WHERE modele = 'ang82';
-- 2 lignes

--4. La liste des modèles de déguisements que l'on peut acheter pour moins de 24 euros.
SELECT DISTINCT modele
FROM Vendre
WHERE prix < 24;
-- 16 lignes 

--5. La personne la plus petite (en taille) inscrite dans la base de données.
SELECT MIN(taille)
FROM Personne; 
/* 
 min 
-----
 136
(1 ligne)
*/ 

--6. Les personnes (surnom, nom, prenom) qui se sont déguisées au moins une fois en Elsa et au moins une fois en Anna.
SELECT DISTINCT p.surnom,
                p.nom,
                p.prenom
FROM Personne p
JOIN Participe pa ON p.surnom = pa.surnom
WHERE pa.avatar = 'Elsa'
  AND p.surnom IN
    (SELECT pa2.surnom
     FROM Participe pa2
     WHERE pa2.avatar = 'Anna');
-- ou 
SELECT surnom,
       nom,
       prenom
FROM Personne
WHERE surnom IN
    (SELECT surnom
     FROM Participe
     WHERE avatar = 'Elsa'
     INTERSECT
        SELECT surnom   
        FROM Participe
        WHERE avatar = 'Anna');
-- 18 lignes 

--7. Les soirées (ids, lieu, date) dans lesquelles personne n'est déguisé en Rey.
SELECT idS, lieu, date
FROM soiree
WHERE idS NOT IN (
    SELECT idS
    FROM participe
    WHERE avatar = 'Rey'
);
-- 56 lignes


--8. Les personnes (surnom, nom, prenom) qui ont organisé au moins une soirée à Marseille.
SELECT p.surnom,
       p.nom,
       p.prenom
FROM Personne p
JOIN Soiree s ON p.surnom = s.organisateur
WHERE s.lieu = 'Marseille';
-- 4 lignes 

--9. La liste des personnes (surnom, nom, prenom, age) d'au moins 25 ans qui ont participé à une soirée déguisées en Daenerys.
SELECT DISTINCT p.surnom,
       p.nom,
       p.prenom,
       p.age
FROM Personne p
JOIN Participe pa ON p.surnom = pa.surnom
WHERE pa.avatar = 'Daenerys'
  AND p.age >= 25;
-- 5 lignes

--10. Les soirées (idS, lieu, date) où au moins une personne ne porte pas de déguisement.
SELECT DISTINCT s.idS, s.lieu, s.date
FROM Soiree s
RIGHT JOIN Participe pa
ON s.idS = pa.idS
WHERE Avatar IS NULL;
-- 80 lignes 

--11. La liste de toutes les soirées (ids, lieu, date) avec pour chacune la recette totale des entrées, triée par recette décroissante.
SELECT s.ids, s.lieu, s.date,(s.entree * COUNT(pa.surnom)) as recette_totale
FROM Soiree s
JOIN Participe pa ON s.ids = pa.ids
GROUP BY s.ids, s.lieu, s.date, s.entree
ORDER BY recette_totale DESC;
-- 100 lignes

--12. Le nombre de participants de chaque âge. La liste devra être ordonnée par âges croissants.
SELECT p.age, COUNT(pa.surnom) AS nombre_participants
FROM Personne p
JOIN Participe pa ON p.surnom = pa.surnom
GROUP BY p.age
ORDER BY p.age ASC;
-- 18 lignes

--13. La liste des villes avec pour chacune le surnom de l'organisateur et la date de la dernière soirée qui y a eu lieu.
SELECT lieu, organisateur, date
FROM soiree
WHERE (lieu, date) IN (
    SELECT lieu, MAX(date)
    FROM soiree
    GROUP BY lieu
);
-- 31 lignes 

-- 
SELECT s1.lieu, s1.date, s1.organisateur
FROM soiree s1
WHERE date = (
    SELECT MAX(s2.date)
    FROM soiree s2
    WHERE s2.lieu = s1.lieu
);
-- 31 lignes


--14. Le nombre de personnes qui se sont déguisées au moins une fois en Batman.
SELECT COUNT(DISTINCT surnom) 
FROM Participe
WHERE avatar = 'Batman';
-- 75 lignes 


--15. Les soirées (ids, lieu, date) qui ont rempli au moins 90% des places disponibles.
SELECT s.ids, s.lieu, s.date
FROM Soiree s
JOIN Participe pa ON s.ids = pa.ids
GROUP BY s.ids, s.lieu, s.date, s.nbmax
HAVING COUNT(pa.surnom) >= 0.9 * s.nbmax;
-- ou
SELECT ids FROM soiree s1 WHERE (SELECT count(*) FROM soiree s2 NATURAL JOIN participe WHERE s1.ids = s2.ids) > 0.9*nbmax;
-- 34lignes

--16. La liste des soirées (ids, lieu, date), avec pour chacune le nombre total de participants, triée par nombre de participants décroissant.
SELECT s.ids, s.lieu, s.date, COUNT(pa.surnom) as nombre_participants
FROM Soiree s
JOIN Participe pa
ON s.ids = pa.ids
GROUP BY s.ids, s.lieu, s.date
ORDER BY nombre_participants DESC; 
-- 100 lignes (max 117 (3 soirees))

--17. La liste des participants (surnom) qui vont uniquement à des soirées de forte affluence (au moins 70 participants).
WITH StatsSoiree AS (
    SELECT ids, COUNT(*) as nb_participants
    FROM participe
    GROUP BY ids
)
SELECT p.surnom
FROM participe p
JOIN StatsSoiree ON p.ids = StatsSoiree.ids
GROUP BY p.surnom
HAVING MIN(StatsSoiree.nb_participants) >= 70;
/*
 surnom 
--------
 ric143
(1 ligne)
*/

--18. La liste des organisateurs de soirées (surnom), avec pour chacun le nombre de participants à sa soirée la plus fréquentée.
SELECT s.organisateur, MAX(participant_count) AS max_participants
FROM Soiree s
JOIN (
    SELECT ids, COUNT(*) as participant_count
    FROM Participe
    GROUP BY ids
) AS stats ON s.ids = stats.ids
GROUP BY s.organisateur;
-- 30 lignes 

--19. La liste des soirées (ids, lieu, date) à thème, c'est-à-dire où tous les participants portent le même avatar, avec pour chacune l'avatar en question.
SELECT s.ids, s.lieu, s.date, MIN(p.avatar) AS theme
FROM Soiree s
JOIN Participe p ON s.ids = p.ids
GROUP BY s.ids, s.lieu, s.date
HAVING COUNT(DISTINCT p.avatar) = 1;
-- 5 lignes 

--20. La liste des soirées (ids, lieu, date) où apparaissent tous les avatars qui sont disponibles 
-- dans au moins un magasin. 
SELECT s.ids, s.lieu, s.date
FROM soiree s
WHERE NOT EXISTS (
    SELECT d.avatar
    FROM vendre v
    JOIN deguisement d ON v.modele = d.modele
    WHERE d.avatar NOT IN (
        SELECT p.avatar
        FROM participe p
        WHERE p.ids = s.ids
        AND p.avatar = d.avatar
    )
);
WITH AvatarsMagasin AS (
    SELECT DISTINCT d.avatar
    FROM vendre v
    JOIN deguisement d ON v.modele = d.modele
)
SELECT s.ids, s.lieu, s.date
FROM soiree s
JOIN participe p ON s.ids = p.ids
WHERE p.avatar IN (SELECT avatar FROM AvatarsMagasin)
GROUP BY s.ids, s.lieu, s.date
HAVING COUNT(DISTINCT p.avatar) = (SELECT COUNT(*) FROM AvatarsMagasin);
     
/*
 ids |  lieu  |    date    
-----+--------+------------
  93 | Angers | 2018-04-01
(1 ligne)
*/

