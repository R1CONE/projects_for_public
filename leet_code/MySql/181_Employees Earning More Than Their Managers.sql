SELECT e.name AS Employee        -- выбираем имя сотрудника
FROM Employee AS e                  -- таблица сотрудников, псевдоним e
JOIN Employee as r ON e.managerId = r.id  -- соединяем с той же таблицей, чтобы получить данные менеджера
WHERE e.salary > r.salary;       -- сравниваем зарплату сотрудника и менеджера
