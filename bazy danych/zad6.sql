--zad1
WITH uczZaj AS (
  select 
 	imie,
  	nazwisko,
    id_kurs,
    obec,
    uz.id_zaj
  FROM uczestnik u join uczest_zaj uz on u.id_uczestnik = uz.id_uczest
)
SELECT
    nazwisko,
    imie,
    SUM(CASE WHEN uz.id_zaj = 1 THEN uz.obec ELSE 0 END) AS z1,
    SUM(CASE WHEN uz.id_zaj = 2 THEN uz.obec ELSE 0 END) AS z2,
    SUM(CASE WHEN uz.id_zaj = 3 THEN uz.obec ELSE 0 END) AS z3,
    SUM(CASE WHEN uz.id_zaj = 4 THEN uz.obec ELSE 0 END) AS z4,
    SUM(CASE WHEN uz.id_zaj = 5 THEN uz.obec ELSE 0 END) AS z5,
    SUM(CASE WHEN uz.id_zaj = 6 THEN uz.obec ELSE 0 END) AS z6,
    SUM(CASE WHEN uz.id_zaj = 7 THEN uz.obec ELSE 0 END) AS z7,
    SUM(CASE WHEN uz.id_zaj = 8 THEN uz.obec ELSE 0 END) AS z8,
    SUM(CASE WHEN uz.id_zaj = 9 THEN uz.obec ELSE 0 END) AS z9,
    SUM(CASE WHEN uz.id_zaj = 10 THEN uz.obec ELSE 0 END) AS z10,
    SUM(CASE WHEN uz.id_zaj = 11 THEN uz.obec ELSE 0 END) AS k11,
    SUM(uz.obec) AS sum
FROM uczZaj uz where uz.id_kurs = 3 GROUP BY nazwisko, imie order by nazwisko

--zad3
WITH wykTab AS (
  select
 	imie,
  	nazwisko,
    id_wykl,
    id_kurs
  FROM wykl_kurs wk join wykladowca w on wk.id_wykl = w.id_wykladowca
)
SELECT
    nazwisko,
    imie,
    SUM(CASE WHEN id_kurs = 1 THEN 1 ELSE 0 END) AS k1,
    SUM(CASE WHEN id_kurs = 2 THEN 1 ELSE 0 END) AS k2,
    SUM(CASE WHEN id_kurs = 3 THEN 1 ELSE 0 END) AS k3,
    SUM(CASE WHEN id_kurs = 4 THEN 1 ELSE 0 END) AS k4,
    SUM(CASE WHEN id_kurs = 5 THEN 1 ELSE 0 END) AS k5,
    SUM(CASE WHEN id_kurs = 6 THEN 1 ELSE 0 END) AS k6,
    SUM(CASE WHEN id_kurs = 7 THEN 1 ELSE 0 END) AS k7,
    SUM(CASE WHEN id_kurs = 8 THEN 1 ELSE 0 END) AS k8,
    SUM(CASE WHEN id_kurs = 9 THEN 1 ELSE 0 END) AS k9,
    SUM(CASE WHEN id_kurs = 10 THEN 1 ELSE 0 END) AS k10,
    SUM(CASE WHEN id_kurs = 11 THEN 1 ELSE 0 END) AS k11,
    SUM(1) AS sum
FROM wykTab GROUP BY nazwisko, imie order by nazwisko