-- Tworzymy tablicę pracownik zawierającą id pracownika, 
-- nazwisko i id bezpośredniego przełożonego
-- Tabela zawiera połączenie typu self-join
CREATE TABLE emp ( empno INT, empname VARCHAR(20), mgrno INT ) ;
-- Wprowadzamy przykładowe dane
INSERT INTO emp VALUES ( 100, 'Kowalski',    null),
                       ( 101, 'Abacki',      100),
                       ( 102, 'Cabacki',     101),
                       ( 103, 'Dadacki',     102),
                       ( 104, 'Zazadzki',    101),
                       ( 105, 'Stachera',    104),
                       ( 106, 'Flisikowski', 100),
                       ( 107, 'Olech',       106),
                       ( 108, 'Płochocki',   106),
                       ( 109, 'Stachyra',    107),
                       ( 110, 'Sztuka',      109),
                       ( 111, 'Sosin',       110),
                       ( 112, 'Głowala',     110),
                       ( 113, 'Straszewski', 110),
                       ( 114, 'Dwojak',      100),
                       ( 115, 'Kotulski',    114),
                       ( 116, 'Łaski',       115),
                       ( 117, 'Iwanowicz',   115)  ; 
-- Zapytanie zwracające nazwisko pracownika i jego przełożonego
SELECT e.empno, e.empname, e.mgrno, m.empname
FROM emp e JOIN emp m ON e.mgrno = m.empno;

	
-- W ramach pracy należy opracować zapytania SQL do bazy danych KURS zwracające poniższe wyniki. W ramach zadania wykorzystujemy instrukcję CASE oraz wyrażenia CTE. Zadanie rozwiązujemy z wykorzystaniem rozszerzenia baz danych KURS przedstawionego na laboratorium 6.

-- Obecność na zajęciach.
-- Tabela obecności na zajęciach dla wybranego kursu. Wiersze odpowiadają za osobę na zajęciach, kolumny przedstawiają kolejne zajęcia, na przecięciu posiadamy informację o obecności lub nieobecności uczestnika na danych zajęciach.
--   nazwisko   |   imie    |z1 |z2 |z3 |z4 |z5 |z6 |z7 |z8 |z9 |z10|sum
-- -------------+-----------+---+---+---+---+---+---+---+---+---+---+----
--  Flisikowski | Jan       | 0 | 1 | 1 | 1 | 0 | 1 | 1 | 1 | 0 | 1 |  7
--  Głowala     | Paweł     | 0 | 1 | 0 | 1 | 0 | 1 | 1 | 1 | 1 | 0 |  6
--  Iwanowicz   | Grzegorz  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 10
--  Kotulski    | Marek     | 1 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 1 | 1 |  8
--  Łaski       | Michał    | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 1 | 1 |  9
--  Płochocki   | Piotr     | 1 | 0 | 1 | 1 | 1 | 0 | 1 | 1 | 1 | 1 |  8
--  Straszewski | Józef     | 1 | 1 | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 1 |  8
--  Sztuka      | Stanisław | 1 | 1 | 1 | 0 | 1 | 1 | 1 | 1 | 1 | 1 |  9
-- (8 wierszy)

-- Zapytanie SQL zwracające powyższy wynik:


