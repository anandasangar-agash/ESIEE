SELECT * FROM cours;

SELECT nom, prenom FROM eleve WHERE maison = 'Gryffondor';

SELECT prenom||' '||nom as nom_complet FRom eleve WHERE maison = 'Gryffondor';

SELECT DISTINCT maison FROM eleve;

SELECT codecours FROM suit WHERE note > 18.0;

SELECT * from familier WHERE proprietaire IS NULL;

SELECT * from familier WHERE description LIKE '%plume%' OR description LIKE '%aile%';

SELECT * FROM eleve ORDER BY datenaissance DESC LIMIT 1;

SELECT intitule, (heurefin - heuredebut) as temps FROM cours ORDER BY temps DESC;

SELECT codeCours, note FROM suit NATURAL JOIN eleve WHERE nom = 'Greenwood' AND prenom = 'Elora';

SELECT DISTINCT maison FROM eleve NATURAL JOIN suit WHERE note = 20.0;

SELECT prenom FROM eleve NATURAL JOIN suit NATURAL JOIN cours WHERE intitule = 'Botanique';

SELECT DISTINCT maison FROM eleve JOIN familier ON numel = proprietaire WHERE espece = 'serpent';

SELECT prenom, sexe, surnom FROM eleve JOIN familier ON numel = proprietaire WHERE sexe = 'F' AND (espece = 'chat' OR espece = 'rat');

SELECT numel FROM suit WHERE codecours = 'arit' INTERSECT SELECT numel FROM suit WHERE codecours = 'rune';

SELECT nom, prenom FROM eleve JOIN familier ON numel = proprietaire WHERE espece = 'chat' INTERSECT SELECT nom, prenom FROM eleve JOIN familier ON numel = proprietaire WHERE espece = 'rat';

SELECT DISTINCT numel from suit where codecours <> 'hdlm';

SELECT DISTINCT numel FROM suit EXCEPT SELECT DISTINCT numel from suit where codecours = 'hdlm';

SELECT numel, nom, prenom FROM eleve NATURAL JOIN suit EXCEPT SELECT numel, nom, prenom from eleve natural join suit where note < 10.0;

SELECT c1.codecours, c2.codecours FROM cours c1, cours c2 WHERE c1.jour = c2.jour AND c1.heuredebut = c2.heuredebut AND c1.heurefin = c2.heurefin AND c1.codecours < c2.codecours;
