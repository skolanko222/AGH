--zad1
SELECT ko.opis, ROUND(
( SELECT COUNT(*) FROM uczest_kurs uk WHERE uk.id_kurs=k.id_kurs)
/ cast(( SELECT COUNT(*) FROM uczest_kurs)   as decimal(3)) *100,	1) as "stat_osob",
				ROUND(
( SELECT COUNT(uk.ocena) FROM uczest_kurs uk WHERE uk.id_kurs=k.id_kurs and uk.ocena >= 4)
/ cast(( SELECT COUNT(uk.ocena) FROM uczest_kurs uk WHERE uk.id_kurs=k.id_kurs)   as decimal(3)) *100,	1) as "stat_ocena"
	FROM kurs k 
	JOIN kurs_opis ko ON k.id_nazwa = ko.id_nazwa;

--zad2
SELECT u.imie, u.nazwisko, 
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 1) as "k1",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 2) as "k2",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 3) as "k3",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 4) as "k4",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 5) as "k5",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 6) as "k6",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 7) as "k7",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 8) as "k8",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 9) as "k9",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 10) as "k10",
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 11) as "k11"
FROM uczestnik u

--zad3
SELECT ko.opis, 
( SELECT COUNT(uk.ocena) FROM uczest_kurs uk WHERE uk.id_kurs=k.id_kurs and uk.ocena = 3) as "ocena_3",
( SELECT COUNT(uk.ocena) FROM uczest_kurs uk WHERE uk.id_kurs=k.id_kurs and uk.ocena = 4) as "ocena_4",
( SELECT COUNT(uk.ocena) FROM uczest_kurs uk WHERE uk.id_kurs=k.id_kurs and uk.ocena = 5) as "ocena_5",
( SELECT COUNT(uk.ocena) FROM uczest_kurs uk WHERE uk.id_kurs=k.id_kurs and uk.ocena = NULL) as "ocena_NULL"
	FROM kurs k 
	JOIN kurs_opis ko ON k.id_nazwa = ko.id_nazwa;
