set search_path to kurs;

--tworzymy tabele zajecia
CREATE TABLE zajecia ( id_kurs int, id_zaj int );
ALTER TABLE zajecia ADD PRIMARY KEY ( id_kurs, id_zaj ); 
ALTER TABLE zajecia ADD FOREIGN KEY ( id_kurs ) REFERENCES kurs ( id_kurs ) ;

--tworzymy tabele uczest_zaj
CREATE TABLE uczest_zaj ( id_kurs int, id_zaj int, id_uczest int, obec int);
ALTER TABLE uczest_zaj ADD PRIMARY KEY ( id_kurs, id_zaj, id_uczest );
ALTER TABLE uczest_zaj ADD FOREIGN KEY ( id_kurs, id_zaj) REFERENCES zajecia ( id_kurs, id_zaj ) ;
ALTER TABLE uczest_zaj ADD FOREIGN KEY ( id_uczest) REFERENCES uczestnik ( id_uczestnik ) ;

--dodajemy dane
WITH RECURSIVE add_records (id_kurs, n) AS (
     SELECT id_kurs, 1 FROM kurs
     UNION ALL
     SELECT id_kurs, n+1 FROM add_records WHERE n<10 )
INSERT INTO zajecia SELECT * FROM add_records;

INSERT INTO uczest_zaj 
SELECT id_kurs, id_zaj, u.id_uczest, CASE WHEN RANDOM() < .7 THEN 1 ELSE 0 END AS obec
FROM zajecia z JOIN uczest_kurs u USING(id_kurs)
ORDER BY id_kurs, id_zaj, 3 ;

select * from wykl_kurs wk ;