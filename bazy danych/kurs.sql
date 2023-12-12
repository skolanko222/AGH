------------------------------------------------------------
--
-- ZAJECIA 3 - BD1
--
------------------------------------------------------------
-- Tworzenie schematu dla bazy danych KURS --
CREATE SCHEMA kurs ;
SET SEARCH_PATH TO kurs ;

-- Tworzenie tabel --
create table uczestnik ( id_uczestnik int, nazwisko varchar(30), imie varchar(30) ) ;
create table kurs ( id_kurs int, id_grupa int, id_nazwa int, termin varchar(30) ) ;
create table wykladowca ( id_wykladowca int, nazwisko varchar(30), imie varchar(30) ) ;
create table kurs_opis ( id_nazwa int, opis varchar(30) ) ;
create table uczest_kurs ( id_uczest int, id_kurs int ) ;
create table wykl_kurs ( id_wykl int, id_kurs int ) ;
--
-- modyfikacja tabel - dodanie klucza glownego --
alter table kurs add primary key (id_kurs) ;
alter table uczestnik add primary key (id_uczestnik) ;
alter table wykladowca add primary key (id_wykladowca) ;
alter table kurs_opis add primary key (id_nazwa) ;
alter table uczest_kurs add primary key (id_uczest, id_kurs) ;
alter table wykl_kurs add primary key (id_wykl, id_kurs) ;
--
-- modyfikacja tabel - dodanie refencji klucza obcego --
alter table uczest_kurs add foreign key (id_uczest) references uczestnik ( id_uczestnik) ;
alter table uczest_kurs add foreign key (id_kurs) references kurs ( id_kurs) ;
alter table wykl_kurs add foreign key (id_kurs) references kurs ( id_kurs) ;
alter table wykl_kurs add foreign key (id_wykl) references wykladowca ( id_wykladowca) ;
alter table kurs add foreign key (id_nazwa) references kurs_opis ( id_nazwa) ;
--
SET SEARCH_PATH TO kurs ;
-- wstawienie danych - tabela uczestnik
insert into uczestnik ( id_uczestnik, nazwisko, imie ) values
( 1, 'Flisikowski', 'Jan'),
( 2, 'Olech', 'Andrzej' ),
( 3, 'Płochocki', 'Piotr' ),
( 4, 'Stachyra', 'Krzysztof' ),
( 5, 'Sztuka', 'Stanisław' ),
( 6, 'Sosin', 'Tomasz' ),
( 7, 'Głowala', 'Paweł' ),
( 8, 'Straszewski', 'Józef' ),
( 9, 'Dwojak', 'Marcin' ),
(10, 'Kotulski', 'Marek' ),
(11, 'Łaski', 'Michał' ),
(12, 'Iwanowicz', 'Grzegorz' ),
(13, 'Barnaś', 'Jerzy' ),
(14, 'Stachera', 'Tadeusz' ),
(15, 'Gzik', 'Adam' ),
(16, 'Całus', 'Łukasz' ),
(17, 'Kołodziejek', 'Zbigniew'),
(18, 'Bukowiecki', 'Ryszard' ),
(19, 'Sielicki', 'Dariusz' ),
(20, 'Radziszewski', 'Henryk'),
(21, 'Szcześniak', 'Mariusz' ),
(22, 'Nawara', 'Kazimierz' ),
(23, 'Kęski', 'Wojciech' ),
(24, 'Rafalski', 'Robert' ),
(25, 'Hołownia', 'Mateusz' ),
(26, 'Niedziałek', 'Marian' ),
(27, 'Matuszczak', 'Rafał' ),
(28, 'Wolf', 'Jacek' ),
(29, 'Kolczyński', 'Janusz' ),
(30, 'Chrobok', 'Mirosław' ) ;
--
-- wstawienie danych - tabela kurs_opis
insert into kurs_opis ( id_nazwa, opis ) values
( 1, 'Język angielski, stopień 1'),
( 2, 'Język angielski, stopień 2'),
( 3, 'Język angielski, stopień 3'),
( 4, 'Język angielski, stopień 4'),
( 5, 'Język angielski, stopień 5'),
( 6, 'Język niemiecki, stopień 1'),
( 7, 'Język niemiecki, stopień 2'),
( 8, 'Język niemiecki, stopień 3'),
( 9, 'Język niemiecki, stopień 4'),
(10, 'Język hiszpański, stopień 1'),
(11, 'Język hiszpański, stopień 2'),
(12, 'Język hiszpański, stopień 3') ;
---- wstawienie danych - tabela wykladowca
insert into wykladowca ( id_wykladowca, imie, nazwisko ) values
( 1, 'Marcin','Szymczak'),
( 2, 'Joanna','Baranowska'),
( 3, 'Maciej','Szczepański'),
( 4, 'Czesław','Wróbel'),
( 5, 'Grażyna','Górska'),
( 6, 'Wanda','Krawczyk'),
( 7, 'Renata','Urbańska'),
( 8, 'Wiesława','Tomaszewska'),
( 9, 'Bożena','Baranowska'),
(10, 'Ewelina','Malinowska'),
(11, 'Anna','Krajewska'),
(12, 'Mieczysław','Zając'),
(13, 'Wiesław','Przybylski'),
(14, 'Dorota','Tomaszewska'),
(15, 'Jerzy','Wróblewski') ;
--
-- wstawienie danych - tabela kurs
insert into kurs ( id_kurs, id_grupa, id_nazwa, termin ) values
( 1, 1, 1, '1.01.2017-31.03.2017'),
( 2, 2, 1, '1.01.2017-31.03.2017'),
( 3, 1, 2, '1.04.2017-30.06.2017'),
( 4, 1, 3, '1.08.2017-10.10.2017'),
( 5, 1, 4, '1.11.2017-23.12.2017'),
( 6, 1, 6, '1.01.2017-31.03.2017'),
( 7, 2, 6, '1.01.2017-31.03.2017'),
( 8, 1, 7, '1.04.2017-30.06.2017'),
( 9, 1, 8, '1.07.2017-31.07.2017'),
(10, 1, 10, '1.02.2017-31.05.2017'),
(11, 1, 11, '1.09.2017-30.11.2017') ;
--
-- wstawienie danych - tabela wykl_kurs - wykladowcy na kursach
insert into wykl_kurs ( id_kurs, id_wykl ) values
( 1, 1 ),
( 2, 2 ),
( 3, 1 ),
( 4, 1 ),
( 5, 3 ),
( 6, 4 ),
( 7, 5 ),
( 8, 4 ),
( 9, 4 ),
(10, 11 ),
(11, 11 ) ;
--
-- wstawienie danych - tabela uczest_kurs - uczestnicy na kursach
insert into uczest_kurs ( id_kurs, id_uczest ) values
-- kurs 1 - angielski 1 gr 1
( 1, 1 ),
( 1, 3 ),
( 1, 5 ),
( 1, 7 ),
( 1, 8 ),
( 1, 10 ),
( 1, 11 ),
( 1, 12 ),
-- kurs 2 - angielski 1 gr 2
( 2, 2 ),
( 2, 16 ),
( 2, 17 ),
( 2, 18 ),
( 2, 20 ),
-- kurs 3 - angielski 2 gr 1
( 3, 1 ),
( 3, 2 ),
( 3, 3 ),
( 3, 5 ),
( 3, 7 ),
( 3, 17 ),
( 3, 18 ),
( 3, 20 ),
-- kurs 4 - angielski 3 gr 1
( 4, 1 ),
( 4, 2 ),
( 4, 3 ),
( 4, 5 ),
( 4, 21 ),
( 4, 22 ),
( 4, 25 ),
-- kurs 5 - angielski 4 gr 1
( 5, 1 ),
( 5, 2 ),
( 5, 3 ),
( 5, 5 ),
( 5, 21 ),
( 5, 22 ),
-- kurs 6 - niemiecki 1 gr 1
( 6, 8 ),
( 6, 9 ),
( 6, 13 ),
( 6, 15 ),
( 6, 19 ),
( 6, 24 ),
( 6, 27 ),
-- kurs 7 - niemiecki 1 gr 2
( 7, 11 ),
( 7, 17 ),
( 7, 18 ),
( 7, 23 ),
( 7, 25 ),
( 7, 28 ),
( 7, 30 ),
-- kurs 8 - niemiecki 2 gr 1
( 8, 8 ),
( 8, 9 ),
( 8, 13 ),
( 8, 15 ),
( 8, 19 ),
( 8, 24 ),
( 8, 27 ),
-- kurs 9 - niemiecki 3 gr 1
( 9, 8 ),
( 9, 9 ),
( 9, 13 ),
( 9, 24 ),
( 9, 27 ),
-- kurs 10 - hiszpanski 1 gr 1
(10, 6 ),
(10, 16 ),
(10, 18 ),
(10, 22 ),
(10, 24 ),
(10, 29 ),
(10, 30 ),
-- kurs 11 - hiszpanski 2 gr 1
(11, 6 ),
(11, 16 ),
(11, 18 ),
(11, 22 ),
(11, 24 ),
(11, 29 ),
(11, 30 ) ;

alter table uczest_kurs add oplata decimal(8,2) ;
alter table uczest_kurs add ocena decimal(5,2) ;

-- wstawienie danych - tabela uczest_kurs - uczestnicy na kursach
-- kurs 1 - angielski 1 gr 1
update uczest_kurs set ( oplata, ocena ) = ( 500., 3 ) where id_kurs=1 and id_uczest=1;
update uczest_kurs set ( oplata, ocena ) = ( 500., 4 ) where id_kurs=1 and id_uczest=3;
update uczest_kurs set ( oplata, ocena ) = ( 500., 5 ) where id_kurs=1 and id_uczest=5;
update uczest_kurs set ( oplata, ocena ) = ( 500., 3 ) where id_kurs=1 and id_uczest=7;
update uczest_kurs set ( oplata, ocena ) = ( 500., 4 ) where id_kurs=1 and id_uczest=8;
update uczest_kurs set ( oplata, ocena ) = ( 500., 4 ) where id_kurs=1 and id_uczest=10;
update uczest_kurs set ( oplata, ocena ) = ( 500., 5 ) where id_kurs=1 and id_uczest=11;
update uczest_kurs set ( oplata, ocena ) = ( 500., 3 ) where id_kurs=1 and id_uczest=12;
-- kurs 2 - angielski 1 gr 2
update uczest_kurs set ( oplata, ocena ) = ( 500., 3 ) where id_kurs=2 and id_uczest=2;
update uczest_kurs set ( oplata, ocena ) = ( 500., 3 ) where id_kurs=2 and id_uczest=16;
update uczest_kurs set ( oplata, ocena ) = ( 500., 5 ) where id_kurs=2 and id_uczest=17;
update uczest_kurs set ( oplata, ocena ) = ( 500., 3 ) where id_kurs=2 and id_uczest=18;
update uczest_kurs set ( oplata, ocena ) = ( 500., 4 ) where id_kurs=2 and id_uczest=20;
-- kurs 3 - angielski 2 gr 1
update uczest_kurs set ( oplata, ocena ) = ( 700., 3 ) where id_kurs=3 and id_uczest=1;
update uczest_kurs set ( oplata, ocena ) = ( 700., 4 ) where id_kurs=3 and id_uczest=2;
update uczest_kurs set ( oplata, ocena ) = ( 700., 5 ) where id_kurs=3 and id_uczest=3;
update uczest_kurs set ( oplata, ocena ) = ( 700., 3 ) where id_kurs=3 and id_uczest=5;
update uczest_kurs set ( oplata, ocena ) = ( 700., 4 ) where id_kurs=3 and id_uczest=7;
update uczest_kurs set ( oplata, ocena ) = ( 700., 4 ) where id_kurs=3 and id_uczest=17;
update uczest_kurs set ( oplata, ocena ) = ( 700., 5 ) where id_kurs=3 and id_uczest=18;
update uczest_kurs set ( oplata, ocena ) = ( 700., 3 ) where id_kurs=3 and id_uczest=20;
-- kurs 4 - angielski 3 gr 1
update uczest_kurs set ( oplata, ocena ) = ( 800., 4 ) where id_kurs=4 and id_uczest=1;
update uczest_kurs set ( oplata, ocena ) = ( 800., 4 ) where id_kurs=4 and id_uczest=2;
update uczest_kurs set ( oplata, ocena ) = ( 800., 4 ) where id_kurs=4 and id_uczest=3;
update uczest_kurs set ( oplata, ocena ) = ( 800., 3 ) where id_kurs=4 and id_uczest=5;
update uczest_kurs set ( oplata, ocena ) = ( 800., 3 ) where id_kurs=4 and id_uczest=21;
update uczest_kurs set ( oplata, ocena ) = ( 800., 5 ) where id_kurs=4 and id_uczest=22;
update uczest_kurs set ( oplata, ocena ) = ( 800., 5 ) where id_kurs=4 and id_uczest=25;
-- kurs 5 - angielski 4 gr 1
update uczest_kurs set ( oplata, ocena ) = ( 850., 4 ) where id_kurs=5 and id_uczest=1;
update uczest_kurs set ( oplata, ocena ) = ( 850., 4 ) where id_kurs=5 and id_uczest=2;
update uczest_kurs set ( oplata, ocena ) = ( 850., 4 ) where id_kurs=5 and id_uczest=3;
update uczest_kurs set ( oplata, ocena ) = ( 850., 3 ) where id_kurs=5 and id_uczest=5;
update uczest_kurs set ( oplata, ocena ) = ( 850., 3 ) where id_kurs=5 and id_uczest=21;
update uczest_kurs set ( oplata, ocena ) = ( 850., 5 ) where id_kurs=5 and id_uczest=22;
-- kurs 6 - niemiecki 1 gr 1
update uczest_kurs set ( oplata, ocena ) = ( 600., 4 ) where id_kurs=6 and id_uczest=8;
update uczest_kurs set ( oplata, ocena ) = ( 600., 3 ) where id_kurs=6 and id_uczest=9;
update uczest_kurs set ( oplata, ocena ) = ( 600., 3 ) where id_kurs=6 and id_uczest=13;
update uczest_kurs set ( oplata, ocena ) = ( 600., 3 ) where id_kurs=6 and id_uczest=15;
update uczest_kurs set ( oplata, ocena ) = ( 600., 5 ) where id_kurs=6 and id_uczest=19;
update uczest_kurs set ( oplata, ocena ) = ( 600., 4 ) where id_kurs=6 and id_uczest=24;
update uczest_kurs set ( oplata, ocena ) = ( 600., 4 ) where id_kurs=6 and id_uczest=27;

-- W ramach tego punktu należy opracować funkcję, która zwraca tablicę z wynikami dla funkcji kwadratowej y = ax2 + bx + c. Parametrami wejściowymi dla funkcji są współczynniki a, b i c, wartość początkowa zmiennej x od której tablicujemy funkcję, wartość przyrostu zmiennej x i na koniec wartość reprezentująca liczbę rekordów w tablicy. Tablica wynikowa zawiera trzy wartości: liczbę porządkową kolejnego rekordu oraz wartości zmiennej x i wyliczonej zmiennej y.
-- > select * from equ_tables(1,2,1,1,1,10);
--  i  | x  |  y
-- ----+----+-----
--   1 |  1 |   4
--   2 |  2 |   9
--   3 |  3 |  16
--   4 |  4 |  25
--   5 |  5 |  36
--   6 |  6 |  49
--   7 |  7 |  64
--   8 |  8 |  81
--   9 |  9 | 100
--  10 | 10 | 121
-- (10 wierszy)

create or replace function equ_tables( a int, b int, c int, x int, dx int, n int )
returns table ( i int, x int, y int )
$$
	declare
		i int := 0;
		y int;
		x int := x;
	begin
		while i < n loop
			i := i + 1;
			x := x + dx;
			y := a*x*x + b*x + c;
			--return as row
			return next;
		end loop;
		return;
	end;

$$
Language plpgsql ;

-- W ramach funkcji należy znaleźć pierwiastki równania kwadratowego. Danymi do funkcji są wartości współczynników równania kwadratowego. Funkcja zwraca pierwiastki w polu tekstowym i w ramach polecenia RAISE INFO wartość wyznacznika i typu zwróconych pierwiastków równania.
-- > select equ_solve(1,10,1);
-- INFORMACJA:  DELTA = 96
-- INFORMACJA:  Rozwiazanie posiada dwa rzeczywiste pierwiastki
-- INFORMACJA:  x1 = -0.101020514433644
-- INFORMACJA:  x2 = -9.89897948556636
--                       equ_solve
-- ------------------------------------------------------
--  (x1 = -0.101020514433644 ),(x2 = -9.89897948556636 )
-- (1 wiersz)
-- > select equ_solve(1,10,1);
-- INFORMACJA:  DELTA = 96
-- INFORMACJA:  Rozwiazanie posiada dwa rzeczywiste pierwiastki
-- INFORMACJA:  x1 = -0.101020514433644
-- INFORMACJA:  x2 = -9.89897948556636
--                       equ_solve
-- ------------------------------------------------------
--  (x1 = -0.101020514433644 ),(x2 = -9.89897948556636 )
-- (1 wiersz)
-- > select equ_solve(10,5,1);
-- INFORMACJA:  DELTA = -15
-- INFORMACJA:  Rozwiazanie w dziedzinie liczb zespolonych
-- INFORMACJA:  x1 = -0.25 + 0.193649167310371i
-- INFORMACJA:  x2 = -0.25 - 0.193649167310371i
--                                equ_solve
-- -----------------------------------------------------------------------
--  (x1 = -0.25 + 0.193649167310371i ),(x2 = -0.25 - 0.193649167310371i )
-- (1 wiersz)

create or replace function equ_solve( a int, b int, c int )
returns text
$$
	declare
		delta int := b*b - 4*a*c;
		x1 numeric;
		x2 numeric;
	begin
		raise info 'DELTA = %', delta;
		if delta > 0 then
			raise info 'Rozwiazanie posiada dwa rzeczywiste pierwiastki';
			x1 := (-b - sqrt(delta)) / (2*a);
			x2 := (-b + sqrt(delta)) / (2*a);
			raise info 'x1 = %', x1;
			raise info 'x2 = %', x2;
			return '(x1 = ' || x1 || ' ),(x2 = ' || x2 || ' )';
		elsif delta = 0 then
			raise info 'Rozwiazanie posiada jeden rzeczywisty pierwiastek';
			x1 := -b / (2*a);
			raise info 'x1 = %', x1;
			return '(x1 = ' || x1 || ' )';
		else
			raise info 'Rozwiazanie w dziedzinie liczb zespolonych';
			x1 := (-b - sqrt(-delta)) / (2*a);
			x2 := (-b + sqrt(-delta)) / (2*a);
			raise info 'x1 = %', x1;
			raise info 'x2 = %', x2;
			return '(x1 = ' || x1 || ' ),(x2 = ' || x2 || ' )';
		end if;
	end;
$$
Language plpgsql ;



	
-- W ramach pracy należy opracować funkcję w języku PL/pgSQL realizującą następującą funkcjonalność.

-- Dodawanie uczestnika do wybranego kursu.
-- Należy opracować funkcję, która doda uczestnika do wybranego kursu. Fukcja posiada dwa argumenty: id_uczestnik i id_kurs. Funkcja zwraca wartość typu "integer". Zwracane wartości: 0 - uczestnik dodany, 1 - uczestnik jest już przypisany do kursu, 2 - brak miejsc na podanym kursie. W przypadku zwracanych wartości większych od 0 funkcja nie modyfikuje tabel w bazie KURS. Dla wartości 0 funkcja dodaje odpowieni rekord do tabeli uczest_kurs i rekordy do tabeli uczest_zaj. Do realizacji zadania należy dodać w tabeli kurs atrybut zawierający maksymalną liczbę uczestników na kursie. Przykład poniżej.
-- ALTER TABLE kurs ADD max_uczest INT ;
-- UPDATE kurs SET max_uczest=10;

CREATE OR REPLACE FUNCTION add_user ( id_uczestnik int, id_kurs int )
RETURNS integer AS $$
	DECLARE
		max_uczest int;
		uczestnik_count int;
		kurs_count int;
		uczestnik_kurs_count int;
	BEGIN
		SELECT max_uczest INTO max_uczest FROM kurs WHERE id_kurs = add_user.id_kurs;
		SELECT count(*) INTO uczestnik_count FROM uczestnik WHERE id_uczestnik = add_user.id_uczestnik;
		SELECT count(*) INTO kurs_count FROM kurs WHERE id_kurs = add_user.id_kurs;
		SELECT count(*) INTO uczestnik_kurs_count FROM uczest_kurs WHERE id_kurs = add_user.id_kurs;
		IF uczestnik_count = 0 THEN
			RETURN 3;
		ELSIF kurs_count = 0 THEN
			RETURN 4;
		ELSIF uczestnik_kurs_count >= max_uczest THEN
			RETURN 2;
		ELSE
			INSERT INTO uczest_kurs ( id_kurs, id_uczest ) VALUES ( add_user.id_kurs, add_user.id_uczestnik );
			RETURN 0;
		END IF;
	END;
$$ LANGUAGE plpgsql ;
