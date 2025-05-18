# Write your MySQL query statement belo
select
(select distinct Salary #distinct берет из столбца запрлат все повторы 
from Employee order by salary desc #desc делает фильтрование по убыванию
limit 1 offset 1 # limit 1 строка offset 2 пропускает 2
) as SecondHighestSalary;
