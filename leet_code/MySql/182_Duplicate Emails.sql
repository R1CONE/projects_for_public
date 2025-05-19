# Write your MySQL query statement be
SELECT email FROM Person
GROUP BY email
HAVING COUNT(email) > 1;
