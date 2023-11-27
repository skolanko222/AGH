create schema drzewo_gen;
set search_path to drzewo_gen;
CREATE TABLE drzewo_gen.osoba (
                osoba_id INTEGER NOT NULL,
                imie VARCHAR NOT NULL,
                nazwisko VARCHAR NOT NULL,
                data_urodzenia DATE NOT NULL,
                miejsce_urodzenia VARCHAR NOT NULL,
                data_smierci VARCHAR,
                id_matki INTEGER,
                id_ojca INTEGER,
                CONSTRAINT osoba_id PRIMARY KEY (osoba_id)
);


CREATE TABLE drzewo_gen.malzenstwo (
                malzenstwo_id INTEGER NOT NULL,
                id_malzonek2 INTEGER NOT NULL,
                id_malzonek1 INTEGER NOT NULL,
                CONSTRAINT malzenstwo_pk PRIMARY KEY (malzenstwo_id)
);


CREATE TABLE drzewo_gen.dziecko (
                osoba_id INTEGER NOT NULL,
                malzenstwo_id INTEGER NOT NULL,
                CONSTRAINT id_dziecka PRIMARY KEY (osoba_id)
);


ALTER TABLE drzewo_gen.osoba ADD CONSTRAINT osoba_osoba_fk
FOREIGN KEY (id_matki)
REFERENCES drzewo_gen.osoba (osoba_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE drzewo_gen.osoba ADD CONSTRAINT osoba_osoba_fk1
FOREIGN KEY (id_ojca)
REFERENCES drzewo_gen.osoba (osoba_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE drzewo_gen.malzenstwo ADD CONSTRAINT osoba_malzenstwo_fk
FOREIGN KEY (id_malzonek1)
REFERENCES drzewo_gen.osoba (osoba_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE drzewo_gen.malzenstwo ADD CONSTRAINT osoba_malzenstwo_fk1
FOREIGN KEY (id_malzonek2)
REFERENCES drzewo_gen.osoba (osoba_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE drzewo_gen.dziecko ADD CONSTRAINT osoba_dziecko_fk
FOREIGN KEY (osoba_id)
REFERENCES drzewo_gen.osoba (osoba_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE drzewo_gen.dziecko ADD CONSTRAINT malzenstwo_dziecko_fk
FOREIGN KEY (malzenstwo_id)
REFERENCES drzewo_gen.malzenstwo (malzenstwo_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

INSERT INTO drzewo_gen.osoba (osoba_id, imie, nazwisko, data_urodzenia, miejsce_urodzenia, data_smierci, id_matki, id_ojca) 
    VALUES (1, 'Jan', 'Kowalski', '1990-01-01', 'Warszawa', NULL, 6, 5),
            (2,'Anna', 'Nowak', '1992-01-01', 'Kraków', NULL, 4, 3),
            (3,'Andrzej', 'Nowak', '1940-01-01', 'Warszawa', '2022-01-01', NULL, NULL),
            (4,'Jadwiga', 'Nowak', '1950-01-01', 'Warszawa', NULL, NULL, NULL),
            (5,'Stanisław', 'Kowalski', '1950-01-01', 'Warszawa', NULL, NULL, NULL),
            (6,'Maria', 'Kowalski', '1950-01-01', 'Warszawa', NULL, NULL, NULL),
            (7, 'Kamil', 'Nowak - Kowalski', '2022-01-01', 'Gdańsk',NULL, 2, 1),
            (8, 'Krystian', 'Nowak - Kowalski', '2022-01-01', 'Gdańsk',NULL, 2, 1);

INSERT INTO drzewo_gen.malzenstwo (malzenstwo_id, id_malzonek2, id_malzonek1)
    VALUES (1, 1, 2),
            (2, 3, 4),
            (3, 5, 6);

INSERT INTO drzewo_gen.dziecko (malzenstwo_id, osoba_id)
    VALUES (1, 7),
            (1, 8),
            (2, 2),
            (3, 1);

-- zad1 i zad2
select o.imie, o.nazwisko, o.data_urodzenia, o.miejsce_urodzenia, o.data_smierci, m.imie as imie_matki,t.imie as imie_ojca from osoba o
	join (select o1.imie, o1.osoba_id from osoba o1) m on o.id_matki = m.osoba_id
	join (select o2.imie, o2.osoba_id from osoba o2) t on o.id_ojca = t.osoba_id
	where o.osoba_id = 1;

