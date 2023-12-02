set search_path to kurs;
WITH RECURSIVE 
test_with(n) AS ( VALUES(1)
                  UNION
                  SELECT n+1 FROM test_with WHERE n < 100 ) 
SELECT * FROM test_with ORDER BY n;

WITH RECURSIVE Factorial (n, factorial) AS (
    SELECT 1, CAST(1 AS BIGINT)
    UNION ALL
    SELECT n + 1, (n + 1) * factorial
    FROM Factorial WHERE n < 10)
SELECT n, factorial FROM Factorial;

set search_path to recur_kurs;

-- Zapytanie zwracające nazwisko pracownika i jego przełożonego
SELECT e.empno, e.empname, e.mgrno, m.empname
FROM emp e join emp m ON e.mgrno = m.empno;			   
-- Zapytanie zwracające nazwisko pracownika, 
-- nazwisko bezpośredniego przełożonego i poziom w hierarchi 	
WITH RECURSIVE cte  					   
         AS ( SELECT empno, empname, mgrno, ''::varchar(20) as mgrname, 1 lvl from emp where mgrno is null 
              UNION ALL
              SELECT e.empno, e.empname, e.mgrno, c.empname, c.lvl+1 
              FROM emp e inner join cte c on e.mgrno = c.empno 
              WHERE e.mgrno is not null )                                                  
SELECT empname, mgrname, lvl FROM cte ORDER BY lvl; 
-- Zapytanie zwracające nazwisko pracownika,
-- poziom w hierarchi i listę przełożonych 				   
WITH RECURSIVE cte  					   
         AS ( SELECT empno, empname, mgrno, 1 lvl, ''::text as path from emp where mgrno is null 
              UNION ALL
              SELECT e.empno, e.empname, e.mgrno, c.lvl+1, concat( c.path, '->', c.empname ) 
              FROM emp e inner join cte c on e.mgrno = c.empno 
              WHERE e.mgrno is not null )                                                  
SELECT empname, lvl, path FROM cte ORDER BY lvl;

set search_path to kurs;



SELECT u.imie, u.nazwisko, 
	(SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 1) as "k2"
FROM uczestnik u;

SELECT 'x' FROM uczest_kurs uk WHERE uk.id_uczest = u.id_uczestnik and uk.id_kurs = 1;


-- FUNKCJE

set search_path to kurs;
CREATE OR REPLACE FUNCTION sql1 ( ikurs int )
RETURNS SETOF uczestnik AS
$$
    SELECT u.id_uczestnik, u.nazwisko, u.imie 
         FROM uczestnik u JOIN uczest_kurs uk ON u.id_uczestnik = uk.id_uczest
         WHERE uk.id_kurs = ikurs;
$$
LANGUAGE SQL; 

SELECT sql1(1) ; 
select * from sql1(1) where nazwisko like 'F%';


CREATE OR REPLACE FUNCTION fun2a ( int ) 
RETURNS text AS
$$
  DECLARE
     iducz ALIAS FOR $1;
     name uczestnik%ROWTYPE;             -- przypisanie typu atrybutu do typu rekordu  
  BEGIN
     SELECT * INTO name FROM uczestnik 
     WHERE id_uczestnik = iducz ;
     RETURN name.imie || ' ' || name.nazwisko;
  END;
$$ LANGUAGE 'plpgsql';
 
SELECT fun2a(1) ;

DO $$
DECLARE
  i INTEGER := 0;
BEGIN
  LOOP
    EXIT WHEN i>9;
    i := i + 1;
    RAISE NOTICE 'i: %',i;
  END LOOP;
END; $$ ;


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
			raise info 'INFO: x1 = %',|| x1 || ' ' || x2 || 'i';
			raise info 'INFO: x2 = %', || x1 || ' ' || -x2 || 'i';
			return 'INFO: (x1 = ' || x1 || ' ' || x2 || 'i ),(x2 = ' || x1 || ' ' || -x2 ||  'i )';
		end if;
		raise info '\n';
	end;
$$
Language plpgsql ;

select * from equ_solve(10,5,1);

-- zapytanie zwracające listę wykładowców z którymi uczestnik ma zajęcia
select w.imie, w.nazwisko from wykladowca w 
	where w.id_wykladowca in (select k.id_wykladowca from kurs k 
		where k.id_kurs in (select uk.id_kurs from uczest_kurs uk 
			where uk.id_uczest = 1));










