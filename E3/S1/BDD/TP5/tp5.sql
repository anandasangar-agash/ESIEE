DROP TABLE IF EXISTS baguette;

CREATE TABLE baguette(
    numbag serial PRIMARY KEY,
    bois varchar(25) NOT NULL,
    coeur varchar(25) NOT NULL,
    longueur float NOT NULL,
    prix float default 25, 
    proprietaire int UNIQUE,
    FOREIGN KEY(proprietaire) REFERENCES eleve(numel)
    ON DELETE SET NULL
);
