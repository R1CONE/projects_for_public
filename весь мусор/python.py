#SDFSDF
print("Hello", 2, "as", sep = ":", end = "\n" )
print("Sec \" line")
\n - след строка 
\t - пропуск


a = input("Введи число")

if 5 == 5:
    print("yes")

a = int(input("Введите число:"))
!=  - неравенство
if a < 9:  #если работает это
    print("Yes")  
    if a == 10:   #работает это
       print("number is 10")


if a == 10 and #or a == 11:
    print("YES")
elif a == 0:
    print("ELIF")
else: 
    print("NO")

for i in range(1, 6, 2):
    print(i)

word = "Hello!"

for i in word:
    print(i)


for i in word:
    if i == "!":
        print("Yes")

count = 0

for i in word:
    if i =="W":
        count += 1;


 print(count)

a = 5

while a < 15:
    print(a)
    a += 2

isHasCar = True

while isHasCar:
    if input("Введите занчения: ") == "stop":
        isHasCar = False #вводищь все пока не закончится


for i in range(1, 11):
    if i == 5:
        break

    if i % 2 == 0:
        continue

print(i)

found = None

for i in "Hello":
    if i == "l":
        found = True
        break

else:
    found = False

print(found)

num = [5, 7, 2,4, 7, True, "Hello", 6.7]
nums[2] = 100
print(nums[2])

nums.append(100) #добавляет в список

nums.insert(1, True)  # элемент 1 заменен на True

nums.sort; # сортировка 

nums.pop; # уберает последний символ

nums.remove(7);

for el in num:
    el *= 2
    print(el)

n = int(input("Enter leight: "))
user_list = []
i = 0
while i < n:
    string = "Enter element #" + str(i+1) + ": "
    user_list.append(input(string))
    i += 1

print(user_list)
sent = "Kin, Ok, hooho"
word = "Hello"
print(word[1])
print(len(word))
print(word.count("p"))
print(word.isupper())
print(word.capitalize())
print(word.find('Hello'))
hobby = (sent.split(","))
print(hobby[1])

word = 'Football'

print(word[0:-1]) #-1 -- предпоследний символ 

list = [6, 4, "Stroka", True, 6.5]

print(list[2: -1])

data = (4,5,6,7,8, True, 5.6, "Hello")

print(data[2])

print(data.count(6))

print(len(data))

for el in data:
    print(el)

new_data = truple(nums)
print(new_data)

country = {4: 3} # 4 - номер,  3 - значение
print(country[4]) # -- 3
country = dict(code='RU', name = 'Russia')
country = {'code': 'RU', 'name': 'Russia', 'population' : 144}
    print(country.items)
print(country['population'])


print(country)

for el, value in country.items:
    print(el, "-", value)

print(country.get('code'))

country.clear() # -- очистка
country.pop('name')
country.popiten();

print(country.keys())
print(country.values())
print(country.items())

country['code'] = 'None'

person = {
    'user_1': {
        'first name' : 'John',
        'last_name' : 'Marley'
        'address' : ['г. Тюмень', 'Негр']
        
    
    },
    'user_2':{
        
        
        }
}

data = set('hello')
data = {5,3,2,16,5}

data.add(32)
data.update(['32', True, 4,6])
data.pop()
data.clear
print(data)

nums = [5, 7 , 3, 4]
nums = set(nums)

print(nums)


new_data = frozenset([5,3,1, '32', True, 4,6])

print(new_data)

def test_func(word):
    print('Hello', end = "!")
    print(word)
pass - ничего   

   

test_func("hi") #будет выводится Hello! hi!



def summa(a, b):
    res = a + b
    print("Result:" res)

summa(5, 7)
nums1 = [2.2,3.5,4.2,5.1,6.2,11.1]

min = nums1[0]

for el in nums1:
    if el < min:
        min = el

print(min)

nums1 = [2.2,3.5,4.2,5.1,6.2,11.1]

def minimal(l):
    min_number = l[0]
    for el  in l:
        if el < min_number:
            min_number = el
    print(min_number)


minimal(nums1)

func = lambda x, y: x * y
print(func(1,2))

data = input('Введите текст: ')

file = open('data/text.txt', 'a') #'a' - добавка инфы 'w' -- читать
file.write(data)
file.write("Hello\n")
file.write('!!!')

file.close()

file = open('data/text.txt', 'r') #r -- создает если нет

print(file.read(20)) # 20 - 20 символов будет выведено

for line in file:
    print(line, end = "")
file.close()

try: 
    x = int(input('Введите число:'))
    x += 2 
    print(x)
except ValueError:
    print("Введите число")

x = 0
while x == 0:
    try: 
        x = int(input("Введите число"))
        x += 5
        print(x)
    except ValueError:
            print("Введите число, а не строку")

try:
    x = 5 / 0
except ZeroDivisionError:
    print("Деление Польши")
except ValueError:
    print("Что-то не так")
else: 
    print('else')
finally:
    print("Finaly")
try:
    with open('data/text.txt', 'r', encoding = 'utf-8') as file:
        print(file.read())
except FileNotFoundError:
    print('Файл не найден')

import time 
time.sleep(3) #Время блять, ахуеть
print("Hello")


import datetime as d, sys
import os  #псевдоним
import platform
import random
from math import sqrt, ceil


print(d.datetime.now().time().hour)

print(sys.path) #- путь к проекту
print(os.name) #- имя операционки

print(platform.system())

print(s(25))

import mymodule as my

print(my.name)

from mymodule import add_three_numbers as ad 

print(add(5, 3, 0))

import cowsay as c
c.cow('сквизли')

class Cat:
    name = None
    age = None
    isHappy = None

    def __init__(self, name = None, age = None, isHappy = None):
        
        self.set_data
        self.get_data()

    def set_data(self, name = None, age = None, isHappy = None):
        self.name = name
        self.age = age
        self.isHappy = isHappy

    def get_data(self):
        print(self.name, 'age:', self.age, 'isHappy:', self.isHappy)

cat1 = Cat('Barsik', 3, True)

cat1.set_data('Barsik', 3, True)
cat1.set_data('Barsik', 3, True)

cat1.get_data()











cat1 = Cat()
cat1.name = 'Barsik'
cat1.age = 3
cat1.isHappy = True

cat2 = Cat()

cat2.name = 'Murza'
cat2.age = 4
cat2.isHappy = False


class Building:
    __year = None #ты забанен блять
    city = None

    def __init__ (self,year,city):
        self.year = year 
        self.city = city

    def get_info(self):
        print("year: ", self.year, "City: ", self.city)

class School(Building):
    pupils = 0

    def __init__(self, pupils, year, city):
        super(School, self).__init__(year, city)
        self.pupils = pupils

    def get_info(self):
        super().get_info()
        print('Pupils: ', self.pupils)

class House(School): #можно и buildings
    pass
class Shop(Building):
    pass



school = School(100, 2000, "Moscow")
school.get_info
print(school.__year)  дай текст без символа
house = House(2000, "Moscow")
shop = Building(2000, "Moscow")
import webbrowser

def validator(func):
    def wrapper(url):
       if "." in url:
           func(url)
       else:
          print('incorrect url')
        
    return wreapper
@validator
def open_url(url):
    webbrowser.open(url)

open_url('https://www.youtube.com/watch?v=85oWKqSczD4')



thisset.update(["dict",  "class",  "int"])


thisset.add(["dict",  "class",  "int"])

////////
# Пример 1: Простая итерация по последовательности чисел от 0 до 4
for i in range(5):
    print(i)  # Выведет числа от 0 до 4

# Пример 2: Итерация по последовательности чисел от 1 до 10 с шагом 2
for i in range(1, 11, 2):
    print(i)  # Выведет нечетные числа от 1 до 9

# Пример 3: Итерация в обратном порядке
for i in range(5, 0, -1):
    print(i)  # Выведет числа от 5 до 1 в обратном порядке
