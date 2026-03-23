SELECT nom, prenom 
FROM client NATURAL JOIN facture 
WHERE idmag = 17;

SELECT DISTINCT idmag, nom, ville 
FROM magasin NATURAL JOIN stocke NATURAL JOIN produit 
WHERE libelle = 'souris';

SELECT DISTINCT nom, ville, prixUnit 
FROM magasin NATURAL JOIN stocke NATURAL JOIN produit 
WHERE libelle = 'souris' and couleur = 'vert' 
ORDER BY prixUnit LIMIT 1;

SELECT idpro, libelle, prixUnit, client.nom 
FROM produit NATURAL JOIN contient NATURAL JOIN facture 
NATURAL JOIN client
WHERE prixUnit > 120;

SELECT idpro, libelle, prixUnit 
FROM stocke NATURAL JOIN produit 
WHERE prixUnit < 5 
ORDER BY prixUnit;

SELECT libelle FROM produit WHERE couleur = 'jaune' 
INTERSECT 
SELECT libelle FROM produit WHERE couleur = 'bleu';

SELECT numcli, nom, prenom FROM client 
NATURAL JOIN facture NATURAL JOIN contient NATURAL JOIN produit 
WHERE libelle = 'bureau';

SELECT numcli, nom, prenom FROM client 
EXCEPT
SELECT numcli, nom, prenom FROM client 
NATURAL JOIN facture NATURAL JOIN contient NATURAL JOIN produit 
WHERE libelle = 'bureau';

SELECT COUNT(idfac) AS nb_facture 
FROM facture;

SELECT nom, COUNT(DISTINCT ville) as nb_ville 
FROM magasin 
GROUP BY nom;

SELECT client.numcli, client.nom, COUNT(idfac) 
FROM client 
LEFT JOIN facture ON client.numcli = facture.numcli
GROUP BY client.numcli, client.nom; 

SELECT AVG(prixUnit), MIN(prixUnit), MAX(prixUnit) 
FROM stocke NATURAL JOIN magasin NATURAL JOIN produit 
WHERE libelle = 'bureau' AND ville = 'paris';

SELECT libelle, MAX(prixUnit) 
FROM produit NATURAL JOIN stocke
GROUP BY libelle;

SELECT nom, prenom, SUM(prixUnit * quantite) AS total 
FROM client NATURAL JOIN facture NATURAL JOIN contient 
GROUP BY nom, prenom, idfac
ORDER BY total DESC; 

SELECT nom, COUNT(DISTINCT libelle) as nb_produit 
FROM magasin NATURAL JOIN stocke NATURAL JOIN produit 
GROUP BY nom 
HAVING COUNT(DISTINCT libelle) >= 20;

SELECT numcli, nom, prenom, SUM(prixUnit * quantite) 
FROM client NATURAL JOIN facture NATURAL JOIN contient 
WHERE ville = 'paris'
GROUP BY numcli, nom, prenom 
HAVING SUM(prixUnit * quantite) >= 3000;