-- zad 1 --
select ko.opis as "nazwa_kursu", count(u.id_uczestnik) as "liczba_osĂłb" from uczestnik u
	join uczest_kurs uk on uk.id_uczest = u.id_uczestnik
	join kurs k on k.id_kurs = uk.id_kurs
	join kurs_opis ko on ko.id_nazwa = k.id_nazwa
	group by ko.opis;

-- zad 2 --
select ko.opis as "nazwa_kursu", sum(uk.oplata) as "suma_opĹ‚at" from uczestnik u
	join uczest_kurs uk on uk.id_uczest = u.id_uczestnik
	join kurs k on k.id_kurs = uk.id_kurs
	join kurs_opis ko on ko.id_nazwa = k.id_nazwa
	group by ko.opis;

-- zad 3 --
select ko.opis as "nazwa_kursu", avg(uk.ocena) as "Ĺ›rednia_ocen" from uczestnik u
	join uczest_kurs uk on uk.id_uczest = u.id_uczestnik
	join kurs k on k.id_kurs = uk.id_kurs
	join kurs_opis ko on ko.id_nazwa = k.id_nazwa
	group by ko.opis;

-- zad 4 --
select w.imie, w.nazwisko, count(k.id_kurs) as "liczba_kursĂłw" from wykladowca w
	join wykl_kurs wk on wk.id_wykl = w.id_wykladowca
	join kurs k on k.id_kurs = wk.id_kurs
	group by id_wykladowca 
	having count(k.id_kurs) >= 1;

-- zad 5 --
select w.imie, w.nazwisko from wykladowca w
	left join wykl_kurs wk on wk.id_wykl = w.id_wykladowca
	left join kurs k on k.id_kurs = wk.id_kurs
	group by id_wykladowca 
	having count(k.id_kurs) = 0;

-- zad 6 --
select u.imie, u.nazwisko from uczestnik u
	left join uczest_kurs uk on uk.id_uczest = u.id_uczestnik 
	left join kurs k on k.id_kurs = uk.id_kurs
	group by u.id_uczestnik
	having count(k.id_kurs) >= 2;

-- zad 7 --
select u.imie, u.nazwisko, count(k.id_kurs) as "liczba_kursĂłw", sum(uk.oplata) as "suma_opĹ‚at", avg(uk.ocena) as "Ĺ›rednia_oc", min(uk.ocena) as "min_oc", max(uk.ocena) as "max_oc" from uczestnik u
	left join uczest_kurs uk on uk.id_uczest = u.id_uczestnik 
	left join kurs k on k.id_kurs = uk.id_kurs
	group by u.id_uczestnik
	
-- zad 8 --
select u.imie, u.nazwisko, sum(uk.oplata) as "kwota" from uczestnik u
	left join uczest_kurs uk on uk.id_uczest = u.id_uczestnik 
	left join kurs k on k.id_kurs = uk.id_kurs
	group by u.id_uczestnik
	having sum(uk.oplata) is not null
	order by sum(uk.oplata) desc
	limit 1

-- zad 9 --
select  w.id_wykladowca as "id_w", w.imie as "imie_w", w.nazwisko as "nazwisko_w", u.id_uczestnik as "id_u", u.imie as "imie_u", u.nazwisko as "nazwisko_u"  from wykladowca w 
	join wykl_kurs wk on wk.id_wykl = w.id_wykladowca
	join kurs k on k.id_kurs = wk.id_kurs 
	join uczest_kurs uk on uk.id_kurs = k.id_kurs 
	join uczestnik u on u.id_uczestnik = uk.id_uczest 
	group by w.id_wykladowca, u.id_uczestnik 
	order by W.id_wykladowca
-- zad 10 
select "data".id_w, "data".imie_w, "data".nazwisko_w, count("data".id_u) as "liczba_u" from (
    select w.id_wykladowca as id_w, w.imie as imie_w, w.nazwisko as nazwisko_w, u.id_uczestnik as id_u, u.imie as imie_u, u.nazwisko as nazwisko_u from wykladowca w 
    join wykl_kurs wk on wk.id_wykl = w.id_wykladowca
    join kurs k on k.id_kurs = wk.id_kurs 
    join uczest_kurs uk on uk.id_kurs = k.id_kurs 
    join uczestnik u on u.id_uczestnik = uk.id_uczest 
    group by w.id_wykladowca, u.id_uczestnik
) as "data"
group by "data".id_w, "data".imie_w, "data".nazwisko_w
order by "data".id_w;