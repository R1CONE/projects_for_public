SELECT vict_age,count(*) FROM crimes GROUP BY vict_age; // выписавает количество сделаных убийств в возрасте

SELECT vict_age,vict_sex,count(*) FROM crimes
GROUP BY vict_age, vict_sex
HAVING count(*) BETWEEN 5000 AND 6000


SELECT occ_date, vict_age, count(*) FROM crimes GROUP BY vict_age; // группировка по возрасту и количеству
