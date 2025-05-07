mysqldump -u root -p baza_osoby > C:\export.sql  ==> export

mysql -u root -p baza_osoby < C:\export.sql  ==> import

UPDATE 'people' SET 'name' = 'Maxim' WHERE id = 5; - обновить табличку table где id = 5 там будет name Mixim



