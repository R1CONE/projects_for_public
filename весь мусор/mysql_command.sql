mysqldump -u root -p baza_osoby > C:\export.sql  ==> export

mysql -u root -p baza_osoby < C:\export.sql  ==> import

UPDATE 'people' SET 'name' = 'Maxim' WHERE id = 5; - обновить табличку table где id = 5 там будет name Mixim


SELECT * FROM users;
INSERT INTO users (name, age) VALUES ('Anna', 25);
UPDATE users SET age = 26 WHERE name = 'Anna';
DELETE FROM users WHERE age < 18;


CREATE TABLE users (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  age INT
);

ALTER TABLE users ADD email VARCHAR(100);
DROP TABLE users;


GRANT SELECT ON users TO guest;
REVOKE SELECT ON users FROM guest;

BEGIN;
UPDATE accounts SET balance = balance - 100 WHERE id = 1;
UPDATE accounts SET balance = balance + 100 WHERE id = 2;
COMMIT;


SELECT users.name, orders.amount
FROM users
JOIN orders ON users.id = orders.user_id
WHERE orders.amount > 100
ORDER BY orders.amount DESC;



SELECT email FROM Person
GROUP BY email
HAVING COUNT(email) > 1;

# Write your MySQL query statement below
SELECT Person.lastName, Person.firstName, Address.City, Address.state 
FROM Person left JOIN Address On Person.personId = Address.personID; 
#у нас есть 2 таблицы и их надо объединить на основании столбиков personId и делается черес структуру Join on
# тут была структура Left Join что объединяет стоки так что бы они были по левой части как есть Right Join и Full Join

Select Score, DENSE_RANK() OVER (ORDER BY Score Desc) AS "RANK" FROM 
Scores
#вся задача построена вокруг функции DENSE_RANK() которая каждому значению придает свой id и id будет повтаряться если record такой же 
# OVER (ORDER BY Score Desc) то есть over показывает как расставить все рекорды и они были расставлины по убыванию ACS обозначает по возрастанию


SELECT e.name AS Employee        -- выбираем имя сотрудника
FROM Employee AS e                  -- таблица сотрудников, псевдоним e
JOIN Employee as r ON e.managerId = r.id  -- соединяем с той же таблицей, чтобы получить данные менеджера
WHERE e.salary > r.salary;       -- сравниваем зарплату сотрудника и менеджера


# Write your MySQL query statement be
SELECT email FROM Person
GROUP BY email
HAVING COUNT(email) > 1;


# Write your MySQL query statement belo
select
(select distinct Salary #distinct берет из столбца запрлат все повторы 
from Employee order by salary desc #desc делает фильтрование по убыванию
limit 1 offset 1 # limit 1 строка offset 2 пропускает 2
) as SecondHighestSalary;



# Write your MySQL query statement below
Select name as Customers FROM Customers WHERE id NOT IN ( Select customerID FROM Orders);


# Write your MySQL query statement below
SELECT w1.id FROM Weather w1 JOIN Weather w2 On DATEDIFF(w1.recordDate, w2.recordDate) = 1
Where w1.temperature > w2.temperature; #ну тут задачка что должна вывести id для если было жарче чем вчера


# Write your MySQL query statement below
SELECT distinct player_id, MIN(event_date) as first_login FROM Activity GROUP BY player_id;

##
SELECT e.name, b.bonus
FROM Employee e
LEFT JOIN Bonus b ON e.empId = b.empId
WHERE b.bonus < 1000 OR b.bonus IS NULL;


# Write your MySQL query statement below
Select name from Customer WHERE referee_id != 2 or referee_id IS NULL;

# Write your MySQL query statement below
SELECT name, population, area FROM World WHERE population >= 25000000 OR area >= 3000000;

# Write your MySQL query statement below
SELECT MAX(num) AS num FROM (SELECT num FROM MyNumbers GROUP BY num HAVING COUNT(num) = 1) as num; ЕСТЬ ОКАЗЫВАЕТСЯ ВОЗМОЖНОСТЬ ФОРМУЛИРОВКИ ВОТ ТАК 
#я когда нидбудь раскину в лит код бля буду 

# Write your MySQL query statement below
SELECT * FROM Cinema WHERE id % 2 = 1 and description != "boring" ORDER BY rating desc;
самая понятная задача?

UPDATE Salary 
SET sex = CASE 
            WHEN sex = 'f' THEN 'm' 
            ELSE 'f' 
          END;


SELECT actor_id, director_id 
FROM ActorDirector 
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3;




SELECT s.price, s.year, p.product_name   
FROM Sales s
JOIN Product p ON s.product_id = p.product_id --кайф задача



SELECT p.project_id, ROUND(AVG(e.experience_years), 2) AS average_years -- ну тут просто надо выбрать аверагу опыта округленную и все
FROM Project p 
JOIN Employee e ON p.employee_id = e.employee_id
GROUP BY p.project_id;



# Write your MySQL query statement bel
SELECT DISTINCT p.product_id, p.product_name
FROM Product p
LEFT JOIN Sales s ON p.product_id = s.product_id -- просто лефт джоин хзывщазывх
WHERE s.sale_date > '2019-01-01' AND s.sale_date < '2019-03-31'
and (p.product_id) 
not in(select product_id from Sales where sale_date>'2019-03-31' or sale_date<'2019-01-01') ; -- самое ублюдское удаление случая что я видел ну да ладно


SELECT p.product_id, IFNULL(ROUND(SUM(p.price * u.units) / SUM(u.units), 2) ,0) AS average_price FROM Prices p
LEFT JOIN UnitsSold u
    On p.product_id = u.product_id
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
    GROUP BY p.product_id;


# Write your MySQL query statement below короче 
SELECT s.student_id, s.student_name, SU.subject_name, COUNT(E.student_id) as attended_exams FROM Students S -- самое конченное в этой задаче непонятная COUNT ну в целом похуй че он считает только бог знает 
CROSS JOIN Subjects SU LEFT JOIN Examinations E ON S.student_id = E.student_id AND -- CROSS 'из названия дураку ясно что это объединение от каждого элемента к каждому элементу
SU.subject_name = E.subject_name 

GROUP BY S.student_id, S.student_name, SU.subject_name
ORDER BY S.student_id, S.student_name, SU.subject_name;


select p.product_name, sum(o.unit) as unit from 
    products p join orders o 
    on p.product_id = o.product_id 
where o.order_date between "2020-02-01" and "2020-02-29" 
group by p.product_id 
having unit>=100; -- задача кажется сложно но много неучетов


select 
eu.unique_id as unique_id, e.name as name
from Employees e left join EmployeeUNI eu on e.id = eu.id -- тут мем в том что можно делать через обычный left join но если у типа нету id то пишется null автоматом


SELECT u.name as name, 
IFNULL(SUM(r.distance),0) --это простой пример проверки на ноль 
as travelled_distance 
FROM Users u LEFT JOIN Rides r 
ON u.id = r.user_id 
GROUP BY r.user_id -- группировка является главной фигней что помогает группировать по отдельности каждую строку
ORDER BY travelled_distance DESC, name ASC; и формирование 



SELECT 
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product ASC SEPARATOR ',') AS products --познакомимся с новой функцией чтопринитает столбец и собирает данные в одну стоку используя сепаратор
FROM Activities
GROUP BY sell_date
ORDER BY sell_date ASC; 



