--1. La liste de toutes les personnes, avec tous leurs attributs.

SELECT * FROM personne;

--2. La liste des villes où il y a une soirée, sans doublons.

SELECT DISTINCT lieu FROM soiree;

--3. La liste des magasins qui vendent le costume ang82.

SELECT DISTINCT nomMag FROM vendre WHERE modele = 'ang82';

--4. La liste des modèles de déguisements que l'on peut acheter pour moins de 24 euros.

SELECT DISTINCT modele FROM vendre WHERE prix <= 24;

--5. La personne la plus petite (en taille) inscrite dans la base de données.

SELECT DISTINCT modele FROM vendre WHERE prix <= 24;

--6. Les personnes (surnom, nom, prenom) qui se sont déguisées au moins une fois en Elsa et au moins une fois en Anna.

SELECT surnom, nom, prenom FROM personne 
NATURAL JOIN participe WHERE avatar = 'Elsa' 
INTERSECT 
SELECT surnom, nom, prenom FROM personne 
NATURAL JOIN participe WHERE avatar = 'Anna';

--7. Les soirées (ids, lieu, date) dans lesquelles personne n'est déguisé en Rey.

SELECT ids, lieu, date FROM soiree 
EXCEPT 
SELECT ids, lieu, date FROM soiree 
NATURAL JOIN participe WHERE avatar = 'Rey';

--8. Les personnes (surnom, nom, prenom) qui ont organisé au moins une soirée à Marseille.

SELECT surnom, nom, prenom FROM personne JOIN soiree ON surnom = organisateur WHERE lieu = 'Marseille';

--9. La liste des personnes (surnom, nom, prenom, age) d'au moins 25 ans qui ont participé à une soirée déguisées en Daenerys.

SELECT surnom, nom, prenom FROM personne NATURAL JOIN participe WHERE avatar = 'Daenerys' AND age >= 25;

--10. Les soirées (idS, lieu, date) où au moins une personne ne porte pas de déguisement.

SELECT DISTINCT ids, lieu, date FROM soiree NATURAL JOIN participe WHERE avatar is NULL;

--11. La liste de toutes les soirées (ids, lieu, date) avec pour chacune la recette totale des entrées, triée par recette décroissante.

SELECT ids, lieu, date, entree*COUNT(surnom) FROM soiree NATURAL JOIN participe GROUP BY ids, lieu, date, entree ORDER BY entree*COUNT(surnom) DESC;

--12. Le nombre de participants de chaque âge. La liste devra être ordonnée par âges croissants.

SELECT age, COUNT(surnom) FROM personne GROUP BY age ORDER BY age;

--13. La liste des villes avec pour chacune le surnom de l'organisateur et la date de la dernière soirée qui y a eu lieu.

SELECT lieu, organisateur, date FROM soiree s1 WHERE date = (SELECT MAX(date) FROM soiree s2 WHERE s2.lieu = s1.lieu GROUP BY lieu);

--14. Le nombre de personnes qui se sont déguisées au moins une fois en Batman.

SELECT COUNT(surnom) FROM participe WHERE avatar = 'Batman';

--15. Les soirées (ids, lieu, date) qui ont rempli au moins 90% des places disponibles.

SELECT ids, lieu, date FROM soiree NATURAL JOIN participe GROUP BY ids, lieu, date HAVING COUNT(surnom)*100/nbmax >= 90; 

--16. La liste des soirées (ids, lieu, date), avec pour chacune le nombre total de participants, triée par nombre de participants décroissant.

SELECT ids, lieu, date, COUNT(surnom) FROM soiree NATURAL JOIN participe GROUP BY ids, lieu, date ORDER BY COUNT(surnom) DESC;

--17. La liste des participants (surnom) qui vont uniquement à des soirées de forte affluence (au moins 70 participants).

SELECT DISTINCT surnom FROM participe p1 WHERE NOT EXISTS (SELECT surnom FROM participe p2 NATURAL JOIN soiree WHERE p2.surnom = p1.surnom AND nbmax >= 70);

--18. La liste des organisateurs de soirées (surnom), avec pour chacun le nombre de participants à sa soirée la plus fréquentée.

SELECT 
    s.organisateur AS surnom,
    MAX(part_count.nb_participants) AS nb_participants_max
FROM soiree s
JOIN (
    SELECT ids, COUNT(surnom) AS nb_participants
    FROM participe
    GROUP BY ids
) part_count ON s.ids = part_count.ids
GROUP BY s.organisateur;

--19. La liste des soirées (ids, lieu, date) à thème, c'est-à-dire où tous les participants portent le même avatar, avec pour chacune l'avatar en question.

SELECT                                   
    s.idS,
    s.lieu,
    s.date,       
    MIN(p.avatar) AS avatar
FROM soiree s                                       
JOIN participe p ON s.idS = p.ids
GROUP BY s.idS, s.lieu, s.date
HAVING COUNT(DISTINCT p.avatar) = 1;

--20. La liste des soirées (ids, lieu, date) où apparaissent tous les avatars qui sont disponibles dans au moins un magasin.

SELECT s.ids, s.lieu, s.date
FROM soiree s
WHERE NOT EXISTS (
    SELECT d.avatar
    FROM deguisement d
    JOIN vendre v ON v.modele = d.modele
    WHERE NOT EXISTS (
        SELECT 1
        FROM participe p
        WHERE p.ids = s.ids
          AND p.avatar = d.avatar
    )
);