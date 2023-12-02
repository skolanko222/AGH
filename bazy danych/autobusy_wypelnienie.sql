SET SEARCH_PATH TO autobusy;

INSERT INTO autobusy.Przystanek (przystanek_id, nazwa_przystanku) VALUES (1, 'Lipińskiego');
INSERT INTO autobusy.Przystanek (przystanek_id, nazwa_przystanku) VALUES (2, 'Szwedzka');
INSERT INTO autobusy.Przystanek (przystanek_id, nazwa_przystanku) VALUES (3, 'Rondo Grunwaldzkie');
INSERT INTO autobusy.Przystanek (przystanek_id, nazwa_przystanku) VALUES (4, 'AGH');
INSERT INTO autobusy.Przystanek (przystanek_id, nazwa_przystanku) VALUES (5, 'Czarnowiejska');
INSERT INTO autobusy.Przystanek (przystanek_id, nazwa_przystanku) VALUES (6, 'Biprostal');
INSERT INTO autobusy.Przystanek (przystanek_id, nazwa_przystanku) VALUES (7, 'Rondo Matecznego');

INSERT INTO autobusy.Linia (linia_id) VALUES (194);
INSERT INTO autobusy.Linia (linia_id) VALUES (144);

--linia 194
INSERT INTO autobusy.przejazd_lini (przejazd_id, linia_id) VALUES (1, 194);

INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (1, 1, 1, '8:00:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (2, 2, 1, '8:05:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (3, 3, 1, '8:07:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (4, 4, 1, '8:16:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (5, 5, 1, '8:20:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (6, 6, 1, '8:22:00');

--linia 194
INSERT INTO autobusy.przejazd_lini (przejazd_id, linia_id) VALUES (2, 144);

INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (7, 7, 2, '8:00:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (8, 3, 2, '8:05:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (9, 4, 2, '8:07:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (10, 5, 2, '8:16:00');
INSERT INTO autobusy.zatrz_na_przystanku (zatrzymanie_id, przystanek_id, przejazd_id, czas_zatrzymania) VALUES (11, 6, 2, '8:20:00');


-- select 1
SELECT linia_id FROM autobusy.zatrz_na_przystanku 
	JOIN przejazd_lini on przejazd_lini.przejazd_id = zatrz_na_przystanku.przejazd_id 
	join Przystanek on zatrz_na_przystanku.przystanek_id = Przystanek.przystanek_id
	WHERE nazwa_przystanku = 'Rondo Matecznego';

-- select 2
select czas_zatrzymania from zatrz_na_przystanku
	join Przystanek on Przystanek.przystanek_id = zatrz_na_przystanku.przystanek_id
	join przejazd_lini on przejazd_lini.przejazd_id = zatrz_na_przystanku.przejazd_id
	WHERE nazwa_przystanku = 'Szwedzka' and linia_id = 194; 

-- select 3
select czas_zatrzymania, nazwa_przystanku from zatrz_na_przystanku
	join Przystanek on Przystanek.przystanek_id = zatrz_na_przystanku.przystanek_id
	join przejazd_lini on przejazd_lini.przejazd_id = zatrz_na_przystanku.przejazd_id
	WHERE linia_id = 194; 