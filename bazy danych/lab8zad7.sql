set search_path to kurs;

ALTER TABLE kurs ADD max_uczest INT ;
UPDATE kurs SET max_uczest=10;

CREATE OR REPLACE FUNCTION add_user ( id_uczestnik int, id_kurs int )
RETURNS integer AS $$
	DECLARE
		max_u int;
		uczestnik_count int; -- ilosc osob zapisanych
		kurs_count int;
		czy_uczestnik_w_kursie int = 0;
	BEGIN
		SELECT max_uczest INTO max_u FROM kurs k WHERE k.id_kurs = add_user.id_kurs;
		SELECT count(*) INTO uczestnik_count FROM uczestnik u WHERE u.id_uczestnik = add_user.id_uczestnik;
--		SELECT count(*) INTO kurs_count FROM kurs WHERE id_kurs = add_user.id_kurs;
		SELECT count(*) INTO czy_uczestnik_w_kursie FROM uczest_kurs uk WHERE uk.id_uczest = add_user.id_uczestnik and uk.id_kurs = add_user.id_kurs;
		IF czy_uczestnik_w_kursie > 0 THEN
			RETURN 1;
		ELSIF uczestnik_count = 10 THEN
			RETURN 2;
--		ELSIF uczestnik_kurs_count >= max_uczest THEN
--			RETURN 2;
		ELSE
			INSERT INTO uczest_kurs ( id_kurs, id_uczest ) VALUES ( add_user.id_kurs, add_user.id_uczestnik );
			RETURN 0;
		END IF;
	END;
$$ LANGUAGE plpgsql ;

select u.imie, u.nazwisko, u.id_uczestnik from uczestnik u
	join uczest_kurs uk on uk.id_uczest = u.id_uczestnik
	where uk.id_kurs = 1;


SELECT count(*) FROM uczest_kurs uk WHERE uk.id_uczest = 4 and uk.id_kurs =1;
select add_user(4,1);



