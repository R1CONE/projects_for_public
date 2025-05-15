# Write your MySQL query statement below
SELECT Person.lastName, Person.firstName, Address.City, Address.state 
FROM Person left JOIN Address On Person.personId = Address.personID; 
#у нас есть 2 таблицы и их надо объединить на основании столбиков personId и делается черес структуру Join on
# тут была структура Left Join что объединяет стоки так что бы они были по левой части как есть Right Join и Full Join
