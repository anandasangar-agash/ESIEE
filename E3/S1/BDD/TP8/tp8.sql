SELECT lieu, ROUND(AVG(entree),2) FROM soiree GROUP BY lieu;

SELECT prenom FROM personne NATURAL JOIN participe NATURAL JOIN 
soiree WHERE lieu = 'paris' AND avatar = 'Père Noël';

SELECT * FROM soiree WHERE lieu LIKE 't%';

SELECT DISTINCT lieu FROM soiree WHERE nbmax >= 145;

SELECT surnom, prenom FROM personne 
NATURAL JOIN participe NATURAL JOIN soiree 
WHERE age = 18 AND lieu = 'lyon' AND avatar is NULL;

SELECT DISTINCT lieu, SUM(entree) as depense FROM soiree 
NATURAL JOIN participe 
GROUP BY lieu HAVING SUM(entree) >= 1000;

SELECT surnom, COUNT(soiree.ids) FROM personne 
NATURAL JOIN participe NATURAL JOIN soiree WHERE lieu = 'marseille' 
GROUP BY surnom HAVING COUNT(soiree.ids) >= 3 
ORDER BY COUNT(soiree.ids) DESC;

WITH agemoy AS (
    SELECT DISTINCT organisateur, age FROM soiree 
    JOIN personne ON organisateur = surnom) 
SELECT round(avg(age),2) FROM agemoy;

SELECT DISTINCT ids FROM participe p1 WHERE avatar = ALL (
    SELECT avatar FROM participe p2 WHERE p1.ids = p2.ids);

SELECT ids FROM participe 
GROUP BY ids HAVING COUNT(*) = COUNT(DISTINCT avatar);

SELECT surnom FROM participe
WHERE avatar = 'Leia'
INTERSECT
SELECT surnom FROM participe
WHERE avatar = 'citrouille';

SELECT DISTINCT ids FROM participe p1
WHERE
(
SELECT count(*) FROM participe p2
WHERE avatar = 'citrouille' and p2.ids = p1.ids
) >= 30;

SELECT ids FROM soiree s WHERE EXISTS 
(
    SELECT ids FROM participe p 
    WHERE p.surnom = s.organisateur AND p.avatar = 'alien'
);

SELECT surnom FROM participe 
EXCEPT 
SELECT surnom FROM participe WHERE avatar = 'Leila';

SELECT d.avatar, d.modele, MIN(v.prix) AS prix_min
FROM deguisement d
NATURAL JOIN vendre v 
GROUP BY d.avatar, d.modele
HAVING MIN(v.prix) = (
    SELECT MIN(v2.prix)
    FROM deguisement d2
    NATURAL JOIN vendre v2
    WHERE d2.avatar = d.avatar
);

SELECT pe.surnom,
       COUNT(p.ids) AS nb_soirees_citrouille
FROM personne pe
LEFT JOIN participe p
       ON p.surnom = pe.surnom
      AND p.avatar = 'citrouille'
GROUP BY pe.surnom;

SELECT AVG(s.entree) AS prix_moyen
FROM soiree s
WHERE EXISTS (
    SELECT *
    FROM participe p
    WHERE p.ids = s.ids
      AND p.avatar = 'Père Noël'
);

SELECT DISTINCT p1.ids
FROM participe p1
JOIN personne pe1 ON pe1.surnom = p1.surnom
JOIN participe p2 ON p2.ids = p1.ids
JOIN personne pe2 ON pe2.surnom = p2.surnom
WHERE pe1.nom = pe2.nom
  AND pe1.prenom = pe2.prenom
  AND pe1.surnom <> pe2.surnom;

SELECT idS FROM soiree s 
WHERE NOT EXISTS (
    SELECT * FROM participe p 
    WHERE p.ids = s.idS 
      AND (p.avatar <> 'schtroumpf' OR p.avatar IS NULL)
)                           
AND EXISTS (
    SELECT * FROM participe p 
    WHERE p.ids = s.idS AND p.avatar = 'schtroumpf'
);