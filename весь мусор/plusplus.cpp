
#include <iostream>

int main(){
    //comment
    setlocale(LC_ALL, "RU");

    std::cout << "Hello World!\n" << std::endl;

    std::cout << "sec sentenses";

    return 0;
}

#include <iostream>
#include <cmath>

int main()
{
    int a, i;
    std::cout << "insert a" << std::endl;
    std::cin >> a;
    
    std::cout << "insert i" << std::endl;
    std::cin >> i;
    
   
    int result = std::pow(a, i); 
    std::cout << "a^i = " << result << std::endl;
    
    return 0;
}



#include <iostream>
using std::cin, std::cout, std::endl;
/*Napisz funkcję, która bedzie przyjmowała prędkość
wyrażoną w m/s i zamieniała ją na predkość wyrażoną w k/h
*/
//Deklaracja funcji:
float zmien_predkosc_ms_na_km_h(float);
void zmien_predkosc_ms_na_km_h(float, float);

int main()
{
    float vms=0.0, vkmh=0.0;
    cout<<"Podaj prędkość w m/s:"<<endl;
    cin>>vms;
    cout<<"\nPodałeś następującą wartość: "<<vms<<" m/s"<<endl;
    cout<<vms<<" m/s to: "<<zmien_predkosc_ms_na_km_h(vms)
    <<" km/h.";
    
    zmien_predkosc_ms_na_km_h(vms,vkmh);
    cout<<"\nSposób drugi: "<<vms<<" m/s to: "<<vkmh<<" km/h."<<endl;

    return 0;
}
//Definicja funckji:
float zmien_predkosc_ms_na_km_h(float v_ms){
    return v_ms*3.6;
}

void zmien_predkosc_ms_na_km_h(float vms, float vkmh){
    vkmh=vms*3.6; 
}



#include <iostream>

int main(){

    int num = -45;

    std::cout <<"Num: " << num << std::endl;
    int a, b, c;
    std::cout << "Enter a: " << std::endl;
    std::cin >> a;

    //типы данных

    short num1 = 7;
    unsigned num2 = 100; //неотрицательное
    long num3 = 15200;

    float num7 = 5.3215632f;

    double num8 = 543.136125f;
    //символ
    char sym = 'r'; //обязательно '';

    bool isHappy = true;

    str text = "HEllo wordl"; //???


    return 0;
}
///

#include <iostream>

int main() {
    int num;
    bool is_happy = true;
    std::cout << "Enter your num: ";
    std::cin >> num;

    if (num > 5 || is_happy == true) {  //или 
        std::cout << "Yes";
    }
    else if (is_happy = true && num < 5 ) { //и
        std::cout << "les 5";
    }
    else if (num == 6) {
        std::cout << "is 5";
    }
    else {
        std::cout << "No";
    }
}

/////

#include <iostream>

int main() {
    int num;
    std::cin >> num;
    
    switch(num){
        case 5: std::cout << "Num is 5"; break;
        
        case 10: std::cout << "Num is 10"; break;
        
        default:
        std::cout << "Def";
        
    }
    
}
///
#include <iostream>

int main()
{
    float num1, num2;
    std::cout << "Enter num1: ";
    std::cin >> num1;
    std::cout << "Enter num2: ";
    std::cin >> num2;

    char math;

    std::cout << "Enter math symbol: ";
    std::cin >> math;

    switch (math) {
    case '+':
        std::cout << num1 + num2;
        break;
    case '-':
        std::cout << num1 - num2;
        break;
    case '*':
        std::cout << num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            std::cout << num1 / num2;
        }
        else {
            std::cout << "Division by zero!";
        }
        break;
    default:
        std::cout << "Invalid operation";
        break;
    }

    return 0;
}
///

#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    float res;

    cout << "Ent num1: ";
    cin >> num1;

    cout << "Ent num2: ";
    cin >> num2;

    res = num1 % num2;

    cout << res;

    num1 += 5;
    num1 -= 5;
    num1++;


    return 0;
}

///

#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int a;

    a = 1 + rand() % 20; //rand diapozone 1 - 20;

    cout << a;

    return 0;
}

////

#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    for (int i = 0; i < 10; i++) {
        cout << "El: " << i << endl;
    }

    int a = 0;

    while (a < 10) {
        a++;
        cout << "A: " << a;
    }

    int k = 100;
    do {
        cout << "k: " << k << endl;
        k -= 10;

    } while (k < 10);

    return 0;
}

////

#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    for (int i = 1; i < 15; i++) {
        if (i == 10)
            break;

       

        if (i % 2 == 0)
            continue;

        cout << "El: " << i << endl;
    } 
    
    return 0;
}

////

int main()
{
    int nums[3];

    nums[0] = 56;
    nums[1] = 36;
    nums[2] = 43;

    //cout << nums[2];
    

    float nums_2[5] = { 0, 1, 2, 3 };

    cout << nums_2[3];

    for (int i = 0; i < 3; i++) {
    cout << "El " << i << ": " << nums_2[i] << endl;
}
                       
    return 0;
}

///

int main()
{
    float nums_2[3]; 
    float a = 0; 
    for (int i = 0; i < 3; i++) {
        cout << "Enter " << i << ": ";
        cin >> nums_2[i];

        a += nums_2[i];

        cout << "a: " << a << endl; 
    }

    return 0; 
}

///

int main()
{
    int matrix[3][2] = {
        {12, 5},
        {4, 2},
        {-2, 0}
    };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << endl;
        }
    }
}

////
#include <string>
int main()
{
    char word[] = { 'H', 'i' };

    for (int i = 0; i < 3; i++) {
        cout << word[i];
    }

    string text = "Hello worldаааааааа";
    text[0] = 'T';
    cout << text;
}

///

int print(int a, int b);

int main()
{
    int result = print(13, 3);
    cout << "Result: " << result << endl;
    return 0;
}

int print(int a, int b) {

    return a + b;

}

////

void print(string word);
void print(int num);

int main()
{
    print("Hello");
    print(12);

    return 0;
}

void print(string word) {
    cout << word << endl;
}

void print(int num) {
    cout << num << endl;
}

////

int main()
{
   
    int val = 12;
    int *ptrval = &val;

    cout << "*ptr: " << ptrval << "val" << *ptrval;
         
    return 0;
}
////

void minimal(int* arr, int len) {
    int min = *arr;
    for (int i = 0; i < len; i++) {
        if (min > *(arr + i)) {
            min = *(arr + i);
        }
    }
    cout << "Min: " << min << endl;

}


int main()
{
   
    int arr[] = { 5, 1 ,3, -1, 0 };

    minimal(arr, 5);

    return 0;
}

///

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ofstream file("text.txt", ios_base::out);

	if (file.is_open()) {
		file << "Hello world";
		file.close();
	};
	

	ifstream file("text.txt");
	if(file.is_open()){
		//string temp;
		//file >> temp;
		char temp[100];
		file.getline(temp, 100);
		cout << temp << endl;
		file.close();
	
	}
};

////

struct Point {
	int x, y;

};

struct Tree {
	string name;
	int ages;
	bool is_alive;
	float hright;
	Point plase;

	void get_info() {
		cout << "Name: " << name << "Age: " << ages << "place: " << plase.x << plase.y;
	}
};

int main() {
	Tree dub;
	dub.plase.x = 2;
	dub.plase.y = 11;
	dub.name = "dub";
	dub.ages = 24;
	
	cout << "name: " << dub.name;

	dub.get_info();

}

///

enum Options {
	open = 12, 
	close, //13
	wait, //14
	del //15
};

struct File {
	int weight;
	string name;
	Options options;

};

int main() {
	File my_file;
	my_file.name = "test.txt";
	my_file.options = Options::close;

	//cout << my_file.options;

	if (my_file.options == Options::close) {
		cout << "File closed";
	}
}

//

void divide(float a, float b) {
	if (b == 0) throw("Divide");
	else cout << (a / b);
}

int main() {
	try {
		divide(5.2f, 0.0f);
	}
	catch(string err){
		if (err == "Devide") cout << 'cant';
	}
}

//

int main() {
	//#include <cstring>
	string str1 = "hello";
	string str2 = "world";

	str1.append(str2);
	cout << str1;
	cout << str1 + str2;

	str1.pop_back(); //удаление последнего символа 
	str1.push_back('!'); //добавление
	str1.length(); // длинна сторки
	str1.resize(5); // установление длинны строки
	#include <cmath>;
	pow(5, 2); //степень
	abs(-3); //модуль + на -
	sin(90);
	cos(90); //пиздец
	sqrt(16); //корень
	ceil(1.01f); //округление к большему //2
	floor(1.99f); //округление к меньшему //1
	round(2.5f); //нормальное округление
}
////

class Building {
protected:
public:
	int year;
	string type;
	void get_info() {
		cout << "Type: " << type << ". Year" << year;
	}
	void get_data(int year, string type) {
		this->year = year;
		this->type = type;
	}

	~Building() {
		cout << "Delete object" << endl;
	}
};

int main() {
	Building school;
	// school.type = "public";
	school.get_data(1, "school"); // Вызываем метод get_data() на объекте school
	school.get_info();
}

////

class Car; // Объявляем класс Car, чтобы его можно было использовать в классе Person

class Person {
public:
    int age;
    string name;

    Person(string name, int age) : name(name), age(age) {} // Конструктор класса Person

    friend void get_info(Car& car, Person& person);
};

class Car {
public:
    string name;
    int year; 

    Car(string name, int year) : name(name), year(year) {} // Конструктор класса Car
};

void get_info(Car& car, Person& person) {
    cout << "Human with name: " << person.name << " has car: " << car.name << endl;
}

int main() {
    Car bmw("BMW", 2022); // Создаем объект класса Car
    Person john("John", 43); // Создаем объект класса Person

    get_info(bmw, john); // Вызываем функцию get_info

    return 0;
}

/////

class Person;
class Dog {
private:
    int health = 100;
public:
    friend class Person;

};

class Person {
public:
    void Damage(Dog& dog) {
        dog.health -= 20;
        cout << "Health of animal: " << dog.health << endl;

    }

    void Heal(Dog& dog) {
        dog.health += 10;
        cout << "Health of animal: " << dog.health << endl;
    }
};
int main() {

    Dog skuby;
    Person Alex;
    Alex.Damage(skuby);
    Alex.Heal(skuby);
    Alex.Damage(skuby);
    Alex.Damage(skuby);

    return 0;
}

////
//наследники 

class PC {
private: //protected: 
	int diagonal;
	string os;

public:
	PC(int diagonal, string os) {
		this->diagonal = diagonal;
		this->os = os;
	}

	void get_info() {
		cout << "OS: " << os << "Diagonal: " << diagonal << endl;
	}
};

class Laptop: public PC {
private:
	float weight;
public:
	Laptop(int diagonal, string os, float weight) : PC(diagonal, os) {
		//this->diagonal = 12;
		this->weight = weight;
	};
};

int main() {
	Laptop mac(16, "Mac", 1.5f);
	mac.get_info();
}

//

using namespace std;

template<typename T, typename T2> //создание шаблона 
void print_arr(T* arr, int len) {
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = { 5, 6, 7, 8, 2, -4 };
    print_arr<int, int>(arr1, 6); //t и t2

    float arr2[] = { 5.11f, 6.47f, 7 };
    print_arr<float, int>(arr2, 3); 

    return 0;
}

///

using namespace std;

template <class T, class T2> //шаблон класс по сути просто замена int на T2
class Arrays {
private:
    T2 len;
    T* arr;

public:
    Arrays(T* a, T2 len) {
        this->len = len;
        arr = new T[len];
        for (int i = 0; i < len; i++)
            arr[i] = a[i];
    }

    void get() {
        for (int i = 0; i < len; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~Arrays() {
        delete[] arr;
    }
};

int main() {
    int arr1[] = { 3, 6, 3 };
    Arrays<int, int> obj1(arr1, 3);
    obj1.get();

    float arr2[] = { 3.12f, 6.67f, 3.16f };
    Arrays<float, int> obj2(arr2, 3);
    obj2.get();

    return 0;
}


#include <iostream>
using namespace std;
//deklaracja funkcji:
int wyznaczNWD(int, int);
int main()
{
    int a=0,b=0;
    cout<<"Uruchomiłeś program który odnajduje NWD dwóch liczb.\n";
    cout<<"Podaj pierwszą liczbę: ";
    cin>>a;
    cout<<"Podaj drugą liczbę: ";
    cin>>b;
    cout<<"NWD liczb "<<a<<" i "<<b<<" to: "<<wyznaczNWD(a,b)<<endl;
    return 0;
}
//definicje funkcji:
int wyznaczNWD(int l1, int l2){
    int NWD=1;
    while(l1!=l2){
        if(l1>l2){
            l1=l1-l2;
        } else if (l2>l1){
            l2=l2-l1;
        } 
        if (l1==l2)
            NWD=l1;
    }
    return NWD;
}

#include <iostream>
using namespace std;
//deklaracja funkcji:
int wyznaczNWD(int, int);
int main()
{
    int a=0,b=0;
    cout<<"Uruchomiłeś program który odnajduje NWD dwóch liczb.\n";
    cout<<"Podaj pierwszą liczbę: ";
    cin>>a;
    cout<<"Podaj drugą liczbę: ";
    cin>>b;
    cout<<"NWD liczb "<<a<<" i "<<b<<" to: "<<wyznaczNWD(a,b)<<endl;
    return 0;
}
//definicje funkcji:
int wyznaczNWD(int l1, int l2){
    int NWD=1;
    while(l1!=l2){
        if(l1>l2){
            l1=l1-l2;
        } else if (l2>l1){
            l2=l2-l1;
        } 
        if (l1==l2)
            NWD=l1;
    }
    return NWD;
}

Oto kod w języku C++ realizujący zadanie opisane na tablicy:

#include <iostream>
#include <ctime>

using namespace std;



int main() {
    const int ROZMIAR = 20;
    int wylosowane_liczby[ROZMIAR];

   
    srand(time(NULL));

 
    for (int i = 0; i < ROZMIAR; i++) {
        wylosowane_liczby[i] = rand() % 1000 + 1; 
    }


    cout << "Wygenerowane liczby: ";
    for (int i = 0; i < ROZMIAR; i++) {
        cout << wylosowane_liczby[i] << " ";
    }
    cout << endl;


    int min = wylosowane_liczby[0];
    int max = wylosowane_liczby[0];

    for (int i = 1; i < ROZMIAR; i++) {
        if (wylosowane_liczby[i] < min) {
            min = wylosowane_liczby[i];
        }
        if (wylosowane_liczby[i] > max) {
            max = wylosowane_liczby[i];
        }
    }

    cout << "Najmniejsza wartosc: " << min << endl;
    cout << "Najwieksza wartosc: " << max << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    const int N = 7;
    int tab[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                tab[i][j] = 4;
            }
      
            else if (i == j) {
                tab[i][j] = 2;
            }
         
            else if (i + j == N - 1) {
                tab[i][j] = 2;
            }
            else {
                tab[i][j] = 0;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tab[i][j];
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // wskaźnik do liczb statycznych
    double liczba1 = 100.00;
    double liczba2 = 200.00;
    double* wsk;  

    /* typy na ktory bedzie wskazywal wskaznik
       symbol wskaznika czyli *
       nazwa wskaznika np wsk i srednik na końcu
    */

    wsk = &liczba1; // & - operator pobierania adresu
    // czyli nasz wskaznik zawiera adres zmiennej liczba1
    // (jest on do niego przypisany)
    // wsk = liczba1; ŹLE!! BO wsk nie jest liczbą

    cout << "adres na ktory wskazuje (ktory zawiera) wskaznik to: " << wsk << endl;
    cout << "wartosc kryjaca sie pod tym adresem to: " << *wsk << endl;
    cout << "\n z kolei adres jego to " << &wsk << endl;

    wsk = &liczba2;
    cout << "adres na ktory wskazuje (ktory zawiera) wskaznik to: " << wsk << endl;
    cout << "wartosc kryjaca sie pod tym adresem to: " << *wsk << endl;
    cout << "\n z kolei adres jego to " << &wsk << endl;

    wsk = nullptr;

    if (wsk == nullptr) {
        cout << "wskaznik wskazuje na puste" << endl;
    }

    double tab[] = {1, 4, 5, 2, 1, 4, 6, 8, 0};
    wsk = &tab[4];

    cout << "adres na ktory wskazuje wsk to: " << wsk << endl;
    cout << "adres czwartego elementu tab to: " << &tab[4] << endl;
    cout << "\n pod tym adresem znajduje sie liczba: " << *wsk << endl;
    cout << "\n pod tym adresem znajduje sie liczba: " << tab[4] << endl;
    cout << "adres pierwszego elementu tablicy to: " << &tab[0] << endl;
    cout << "adres drugiego elementu tablicy to: " << &tab[0] + 1 << endl;

    // wskaźnik do zmiennych tworzonych dynamicznie
    float* a = new float; // przydzielimy miejsce statyczne na które bedzie wskazywał wskaźnik, czyli a bedzie wskazywać na float
    *a = 300.0f; // przypisujemy wartość do tego miejsca
    return 0;
    cout << "adres na który wskazuje a to: " << a << endl;
    cout << "wartosc pod tym adresem to: " << *a << endl;       
    delete a; // zwalniamy pamięć
    a = nullptr; // zabezpieczenie'


}




