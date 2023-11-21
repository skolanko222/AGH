CREATE SCHEMA autobusy;

SET SEARCH_PATH TO autobusy;
CREATE TABLE autobusy.Przystanek (
                przystanek_id INTEGER NOT NULL,
                nazwa_przystanku VARCHAR NOT NULL,
                CONSTRAINT przystanek_id PRIMARY KEY (przystanek_id)
);


CREATE TABLE autobusy.Linia (
                linia_id INTEGER NOT NULL,
                CONSTRAINT linia_id PRIMARY KEY (linia_id)
);


CREATE TABLE autobusy.przejazd_lini (
                przejazd_id INTEGER NOT NULL,
                linia_id INTEGER NOT NULL,
                CONSTRAINT przejazd_id PRIMARY KEY (przejazd_id)
);


CREATE TABLE autobusy.zatrz_na_przystanku (
                zatrzymanie_id INTEGER NOT NULL,
                przystanek_id INTEGER NOT NULL,
                przejazd_id INTEGER NOT NULL,
                czas_zatrzymania TIME NOT NULL,
                data_zatrzymania DATE,
                CONSTRAINT zatrzymanie_id PRIMARY KEY (zatrzymanie_id)
);


ALTER TABLE autobusy.zatrz_na_przystanku ADD CONSTRAINT przystanek_zatrz_na_przystanku_fk
FOREIGN KEY (przystanek_id)
REFERENCES autobusy.Przystanek (przystanek_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE autobusy.przejazd_lini ADD CONSTRAINT linia_przejazd_lini_fk
FOREIGN KEY (linia_id)
REFERENCES autobusy.Linia (linia_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE autobusy.zatrz_na_przystanku ADD CONSTRAINT przejazd_lini_zatrz_na_przystanku_fk
FOREIGN KEY (przejazd_id)
REFERENCES autobusy.przejazd_lini (przejazd_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;