string str;

        int a, b;

        Console.WriteLine("Set number 1: ");

        str = Console.ReadLine();

        a = Convert.ToInt32(str);

        Console.WriteLine("Set number 2");

        str = Console.ReadLine();

        b = Convert.ToInt32(str);

        int result = a + b;

        Console.WriteLine("result: " + result);



Math.PI

Math.Pow(a, 2) - степени

num1 = Convert.ToInt32(Console.ReadLine);

if(a == 5){
}
else if{
}
else if{ ---- 2
}
else{
не равно 5}

!= - не равно



int re = 0;

        while (re < 10)
            {
            Console.WriteLine(re++);
        }


 for(int re = 0; re < 10; re++)
        {
            //if (re > 5)

            //  break;

            if (re % 2 == 0)
                continue;
            Console.WriteLine(": " + re);
        }


int[] ints = new int[10];

        int[] nums = { 1, 2, 3, 4, };

        Console.WriteLine(nums[3]); 

int[] nums = { 1, 2, 3, 4, };

        foreach(int el in nums)
        {
            Console.WriteLine("Числа: " + el);
        }  

int[,] nums = {
        {1,2, 3, 4},
        {12, 123, 13, 12},
        };

        foreach (int el in nums)
        {
            Console.WriteLine("Ht: " + el);
        }


using System;
using System.Collections.Generic;

internal class Program
{
    static void Main(string[] args)
    {

        List<int> numbers = new List<int>()
        {
            4, 5, 6, 7
        };
        //выделяем память

        numbers.Add(40);
        numbers.Add(100);
        numbers.Add(5);

        numbers.Remove(100);

        foreach(int i in numbers)
        {
            System.Console.WriteLine("i:" + i);    
        }

    }
}

numbers.Sort(); 
        //Сортировка


numbers.Reverse();
        //перевернуть

numbers.CopyTo();
        //очистка


public static void Main(string[] args)
    {
        Print("Hello");
        
    }

    public static void Print(string word)
    {
        Console.WriteLine(word);
    }


public static void Main(string[] args)
    {
        Summa(5, 6);

        int a = 4; int b = 5;
        
        Summa(a, b);    

    }

    public static void Summa(int x, int y)
    {

        int res = x + y;   

        Console.WriteLine("Resultat: " + res);
    }



 public static void Main(string[] args)
    {
        int a = Summa(5, 9);

        Console.WriteLine(a);   

    }

    public static int Summa(int x, int y)
    {
        return x + y;
    }





static void Main(string[] args)
    {
        byte[] nums = { 5, 7, 6, 3, 2, 1, };
        byte res1 = Summa(nums);

        Console.WriteLine(res1);

    }
    public static byte Summa(byte[] digits)
    {
        byte summ = 0;  
        foreach(byte el in digits)
            summ += el;
        return summ;
    }

Console.WriteLine(word[3]); -- буква
Console.WriteLine(word.Length);

Console.WriteLine(String.Concat(word,"!!"));

string names = "Oleg, George, Nigga";
        string[] names2 = names.Split(new char[] { ',' });
