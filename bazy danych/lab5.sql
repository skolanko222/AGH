--Lista wszystkich uczestników i wykładowców - operator UNION.
SELECT imie, nazwisko, 'U' FROM uczestnik
UNION
SELECT imie, nazwisko, 'W' FROM wykladowca 
ORDER BY 3,2 ;
--Lista wykładowców, którzy nie prowadzą kursów - operator EXCEPT.
SELECT imie, nazwisko FROM wykladowca
EXCEPT 
SELECT imie, nazwisko
FROM wykladowca w JOIN wykl_kurs wk ON w.id_wykladowca = wk.id_wykl
ORDER BY 2;
-- to samo
SELECT imie, nazwisko 
FROM wykladowca w LEFT JOIN wykl_kurs wk ON w.id_wykladowca = wk.id_wykl 
WHERE wk.id_wykl is null ;

-- wykladowcy
SELECT imie, nazwisko, opis from wykladowca w
	right join wykl_kurs wk on id_wykladowca=wk.id_wykl
	join kurs k on k.id_kurs = wk.id_kurs
	join kurs_opis ko on k.id_nazwa = ko.id_nazwa