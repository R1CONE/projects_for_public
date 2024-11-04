SELECT vict_age,count(*) FROM crimes GROUP BY vict_age; // выписавает количество сделаных убийств в возрасте

SELECT vict_age,vict_sex,count(*) FROM crimes
GROUP BY vict_age, vict_sex
HAVING count(*) BETWEEN 5000 AND 6000


SELECT occ_date, vict_age, count(*) FROM crimes GROUP BY vict_age; // группировка по возрасту и количеству


CREATE TABLE dane (
    imie VARCHAR(50) NOT NULL,
    nazwisko VARCHAR(50) NOT NULL,
    wiek INT(3) NOT NULL,
    email VARCHAR(50) NOT NULL,
    PRIMARY KEY (nazwisko)
);

SELECT * FROM dane;
SELECT * FROM dane WHERE nazwisko = 'Grant';
SELECT * FROM dane WHERE imie = 'Igor' AND wiek = 52;

CREATE TABLE osoby (
    osobaID int NOT NULL,
    imie varchar(255) NOT NULL,
    nazwisko varchar(255),
    wiek int,
    CONSTRAINT PK_osoby PRIMARY KEY (osobaID, nazwisko)
);
