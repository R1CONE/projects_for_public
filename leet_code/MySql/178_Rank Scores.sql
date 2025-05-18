Select Score, DENSE_RANK() OVER (ORDER BY Score Desc) AS "RANK" FROM 
Scores
#вся задача построена вокруг функции DENSE_RANK() которая каждому значению придает свой id и id будет повтаряться если record такой же 
# OVER (ORDER BY Score Desc) то есть over показывает как расставить все рекорды и они были расставлины по убыванию ACS обозначает по возрастанию
