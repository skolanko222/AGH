--zad1
create or replace function equ_tables( a int, b int, c int, x1 int, dx int, n int )
returns table ( i int, x int, y int ) AS
$$
	declare
		iter int := 0;
	begin
		x := x1;
		iter := 0;
		while iter < n loop
			i := iter + 1;
			x := x + dx;
			y := a*x*x + b*x + c;
			iter := iter + 1;
			return next;
		end loop;
		return;
	end;

$$
Language plpgsql ;

select * from equ_tables(1,2,1,0,1,12);


--zad2
create or replace function equ_solve( a int, b int, c int )
returns text as
$$
	declare
		delta int := b*b - 4*a*c;
		x1 numeric;
		x2 numeric;
	begin
		raise info 'INFO: DELTA = %', delta;
		if delta > 0 then
			raise info 'INFO: Rozwiazanie posiada dwa rzeczywiste pierwiastki';
			x1 := (-b - sqrt(delta)) / (2.0*a);
			x2 := (-b + sqrt(delta)) / (2.0*a);
			raise info 'x1 = %', x1;
			raise info 'x2 = %', x2;
			return 'INFO: (x1 = ' || x1 || ' ),(x2 = ' || x2 || ' )';
		elsif delta = 0 then
			raise info 'Rozwiazanie posiada jeden rzeczywisty pierwiastek';
			x1 := -b / (2.0*a);
			raise info 'x1 = %', x1;
			return 'INFO: (x1 = ' || x1 || ' )';
		elseif delta < 0 then
			raise info 'INFO: Rozwiazanie w dziedzinie liczb zespolonych';
			x1 := -b / (2.0*a);
			x2 := (sqrt(-delta)) / (2*a);
			raise info 'INFO: x1 = % + % i', x1,x2;
			raise info 'INFO: x2 = % %', x1,-x2;
			return 'INFO: (x1 = ' || x1 || ' +' || x2 || 'i ),(x2 = ' || x1 || ' ' || -x2 ||  'i )';
		end if;
		raise info '\n';
	end;
$$
Language plpgsql ;

select * from equ_solve(1,10,1);

--zad3

set search_path to kurs;
create or replace function uczest_wykladowca( a int )
returns table ( w_nazwisko VARCHAR, w_imie VARCHAR) as
$$
	select w.imie, w.nazwisko from wykladowca w 
		where w.id_wykladowca in (select k.id_kurs from kurs k 
			where k.id_kurs in (select uk.id_kurs from uczest_kurs uk 
				where uk.id_uczest = a));
$$
language sql;

select * from uczest_wykladowca(1);

--zad4

create or replace function uczest_kurs( a int )
returns table ( z_opis VARCHAR) as
$$
	select ko.opis from kurs_opis ko
		where ko.id_nazwa in (select k.id_kurs from kurs k 
			where k.id_kurs in (select uk.id_kurs from uczest_kurs uk 
				where uk.id_uczest = a));
$$
language sql;

select * from uczest_kurs(2);

--zad5

create or replace function lista_obec( a int )
returns table ( s_nazwisko VARCHAR, s_imie VARCHAR, z1 int,z2 int,z3 int,z4 int,z5 int,z6 int,z7 int,z8 int,z9 int,z10 int,sum int) as
$$
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
	    SUM(uz.obec) AS sum
	FROM uczZaj uz where uz.id_kurs = 1 GROUP BY nazwisko, imie order by nazwisko

$$
language sql;

select * from lista_obec(1);
