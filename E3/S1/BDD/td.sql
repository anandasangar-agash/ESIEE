SELECT numEtud FROM examen
    GROUP BY numEtud   
    HAVING count(note) >= 3; 


SELECT numEtud 
    FROM examen e1
    WHERE note-2 >=
    (
        SELECT avg(note)
            FROM examen e2
        WHERE e1.codeCours = e2.codeCours
    )
GROUP BY numEtud
HAVING count(note) >= 3;

SELECT numEtud  
    FROM examen NATURAL JOIN 
    (
        SELECT codeCours, avg(note) as moy
            FROM examen 
            GROUP BY codeCours
    )
    WHERE note-2 >= moy
    GROUP BY numEtud
    HAVING count(note) >= 3;


WITH ects_par_etudiant AS (
    SELECT numEtud, sum(ects) as nb_ects
        FROM examen NATURAL JOIN cours
        WHERE note >= 10
        GROUP BY numEtud
)
SELECT e1.numEtud
    FROM ects_par_etudiant e1
    WHERE e1.nb_ects >= 
    ( 
        SELECT avg(e2.nb_ects)
            FROM ects_par_etudiant
    );


SELECT codeCours
    FROM examen e1
    GROUP BY codeCours  
    HAVING MAX(e1.note) - 4 >=  
    ALL(
        SELECT note
            FROM examen e2
            WHERE e1.numEtud <> e2.numEtud
            AND e2.codeCours = e1.codeCours
    );


-- VUES --

CREATE VIEW nb_inscrit(codeCours, nb_etud_inscrits) AS (
    SELECT codeCours, COUNT(*)
        FROM examen 
        GROUP BY codeCours
);

CREATE VIEW nb_valide(codeCours, nb_etud_valide) AS (
    SELECT codeCours, COUNT(*)
        FROM examen
        WHERE note >= 10
        GROUP BY codeCours
);

CREATE VIEW taux_reussite(codeCours, taux) AS (
    SELECT codeCours, nb_valide.nb_etud_valide / nb_inscrit.nb_etud_inscrits
        FROM nb_inscrit NATURAL JOIN nb_valide
        GROUP BY codeCours
);

CREATE VIEW repart_note(codeCours, note, nb) AS (
    SELECT codeCours, note, count(numEtud)
        FROM examen
        GROUP BY codeCours, note
);