
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



#include <iostream>
using namespace std;

class Osoba{ //nazwy klas zapisujemy z dużej litery
    /*
    SPECYFIKATORY DOSTĘPU DO SKŁADNIKÓW KLASY
    public - dostęp do składników klasy jest publiczny (możliwy z
         zewnatrz)
    private - dostęp do składników klasy jest prywatny
    (tylko wewnątrz danej klasy mamy dostęp do składników z taką 
    etykietą)
    protected - dostęp do składników klasy jest możliwy wewnątrz
    danej klasy oraz przy dziedziczeniu - dla klasy pochodnej
    domyślnym specyfikatorem dostępu jest private
    */
    //private:
    public:
    short sprawdz_wiek(short wiek);
    //gettery:
    string pobierz_imie(){
        return imie;
    }
    string pobierz_nazwisko(){
        return nazwisko;
    }
    int pobierz_wiek(){
        return wiek;
    }
    string pobierz_pesel(){
        return pesel;
    }
    string pobierz_kolor_skory(){
        return kolor_skory;
    }

    string pobierz_dane_osoby(){
        return imie+" "+nazwisko+", lat "+to_string(wiek)+"\n"
        "PESEL: "+pesel+", kolor skóry: "+kolor_skory;
    }



    //settery:
    void ustaw_imie(string imie){
        this->imie=imie;
    }
    void ustaw_nazwisko(string nazwisko){
        this->nazwisko=nazwisko;
    }
    void ustaw_wiek(short wiek){
        this->wiek=wiek;
    }
    void ustaw_pesel(string pesel){
        this->pesel=pesel;
    }
    void ustaw_kolor_skory(string kolor_skory){
        this->kolor_skory=kolor_skory;
    }   
    


    private: //ale nie jest to konieczne, bo taki jest domyślny spec.
    string imie;
    string nazwisko;
    short wiek;
    string pesel; //sprawdź czy kobieta
    string kolor_skory;

};

int main()
{   
    //Tworzenie obiektu klasy osoba:
    Osoba person1; //nazwa_typu nazwa_zmiennej

    /*
    person1.imie="Matylda";
    person1.nazwisko="Szczęśniak";
    person1.wiek=30;
    person1.pesel="94070708214";
    person1.kolor_skory="biały";

    
    cout<<"Cechy osoby:"<<endl;
    cout<<"imię: "<<person1.imie<<endl;
    cout<<"nazwisko: "<<person1.nazwisko<<endl;
    cout<<"wiek: "<<person1.wiek<<", pesel: "<<person1.pesel
    <<", kolor skóry: "<<person1.kolor_skory<<endl;
    */
    
    //Wywołanie setterów na obiekcie:
    person1.ustaw_imie("Matylda");
    person1.ustaw_nazwisko("Szczęśniak");
    person1.ustaw_wiek(130);
    person1.ustaw_pesel("94070708214");
    person1.ustaw_kolor_skory("biały");
    
    //Wywołanie geterów - wywołujemy je na obiekcie:
    cout<<"Cechy osoby:"<<endl;
    cout<<"imię: "<<person1.pobierz_imie()<<endl;
    cout<<"nazwisko: "<<person1.pobierz_nazwisko()<<endl;
    cout<<"wiek: "<<person1.pobierz_wiek()<<", pesel: "
    <<person1.pobierz_pesel()<<", kolor skóry: "
    <<person1.pobierz_kolor_skory()<<endl;

    cout<<"\nA teraz to samo z użyciem jedenj funkcji: "<<endl;
    cout<<person1.pobierz_dane_osoby();

    return 0;
}

/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Osoba{ //nazwy klas zapisujemy z dużej litery
    /*
    SPECYFIKATORY DOSTĘPU DO SKŁADNIKÓW KLASY
    public - dostęp do składników klasy jest publiczny (możliwy z
         zewnatrz)
    private - dostęp do składników klasy jest prywatny
    (tylko wewnątrz danej klasy mamy dostęp do składników z taką 
    etykietą)
    protected - dostęp do składników klasy jest możliwy wewnątrz
    danej klasy oraz przy dziedziczeniu - dla klasy pochodnej
    domyślnym specyfikatorem dostępu jest private
    */
    //private:
    public:
    short sprawdz_wiek(short wiek);
    //gettery:
    string pobierz_imie(){
        return imie;
    }
    string pobierz_nazwisko(){
        return nazwisko;
    }
    int pobierz_wiek(){
        return wiek;
    }
    string pobierz_pesel(){
        return pesel;
    }
    string pobierz_kolor_skory(){
        return kolor_skory;
    }

    string pobierz_dane_osoby(){
        return imie+" "+nazwisko+", lat "+to_string(wiek)+"\n"
        "PESEL: "+pesel+", kolor skóry: "+kolor_skory;
    }



    //settery:
    void ustaw_imie(string imie){
        this->imie=imie;
    }
    void ustaw_nazwisko(string nazwisko){
        this->nazwisko=nazwisko;
    }
    void ustaw_wiek(short wiek){
        this->wiek=wiek;
    }
    void ustaw_pesel(string pesel){
        this->pesel=pesel;
    }
    void ustaw_kolor_skory(string kolor_skory){
        this->kolor_skory=kolor_skory;
    }   
    


    private: //ale nie jest to konieczne, bo taki jest domyślny spec.
    string imie;
    string nazwisko;
    short wiek;
    string pesel; //sprawdź czy kobieta
    string kolor_skory;

};

int main()
{   
    //Tworzenie obiektu klasy osoba:
    Osoba person1; //nazwa_typu nazwa_zmiennej

    /*
    person1.imie="Matylda";
    person1.nazwisko="Szczęśniak";
    person1.wiek=30;
    person1.pesel="94070708214";
    person1.kolor_skory="biały";

    
    cout<<"Cechy osoby:"<<endl;
    cout<<"imię: "<<person1.imie<<endl;
    cout<<"nazwisko: "<<person1.nazwisko<<endl;
    cout<<"wiek: "<<person1.wiek<<", pesel: "<<person1.pesel
    <<", kolor skóry: "<<person1.kolor_skory<<endl;
    */
    
    //Wywołanie setterów na obiekcie:
    person1.ustaw_imie("Matylda");
    person1.ustaw_nazwisko("Szczęśniak");
    person1.ustaw_wiek(130);
    person1.ustaw_pesel("08212415274");
    person1.ustaw_kolor_skory("biały");
    
    //Wywołanie geterów - wywołujemy je na obiekcie:
    cout<<"Cechy osoby:"<<endl;
    cout<<"imię: "<<person1.pobierz_imie()<<endl;
    cout<<"nazwisko: "<<person1.pobierz_nazwisko()<<endl;
    cout<<"wiek: "<<person1.pobierz_wiek()<<", pesel: "
    
    
    
    <<person1.pobierz_pesel()<<", kolor skóry: "
    <<person1.pobierz_kolor_skory()<<endl;

    cout<<"\nA teraz to samo z użyciem jedenj funkcji: "<<endl;
    cout<<person1.pobierz_dane_osoby();
    
    string pesel_sprw = person1.pobierz_pesel();

    // Sprawdzenie długości
    if(pesel_sprw.length() != 11){
        cout << "Nieprawidłowa długość PESEL" << endl;
        return 0;
    }

    int wagi[10] = {1,3,7,9,1,3,7,9,1,3};
    int suma = 0;

    for(int i=0; i<10; i++){
        int cyfra = pesel_sprw[i] - '0'; // zamiana znaku na cyfrę
        suma += cyfra * wagi[i];
    }

    int cyfra_kontrolna = (10 - (suma % 10)) % 10;
    int ostatnia_cyfra = pesel_sprw[10] - '0'; // ← poprawka

    cout << "Suma kontrolna: " << suma << endl;

    if(cyfra_kontrolna == ostatnia_cyfra){
        cout << "PESEL jest poprawny ✅" << endl;
    } else {
        cout << "PESEL jest niepoprawny ❌" << endl;
    }
}


#include <iostream>
#include <string>
#include <cmath> 

using namespace std;

class Pracownik
{
public:

    Pracownik(string imie, string nazwisko, int wiek, string stanowisko, float wynagrodzenie, float premia) {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->wiek = wiek;
        this->stanowisko = stanowisko;
        this->wynagrodzenie = wynagrodzenie;
        this->premia = premia;
    }


    string wyswietl() {
        return imie + " " + nazwisko + "\n" +
               "wiek: " + to_string(wiek) + "\n" +
               "stanowisko: " + stanowisko + "\n" +
               "wynagrodzenie: " + to_string((int)round(wynagrodzenie)) +
               " zł (do pełnych złotych)\n" +
               "premia: " + to_string((int)round(premia)) +
               " zł (do pełnych złotych)\n";
    }


    void zmien_wynagrodzenie() {
        float dodatek;
        cout << "Podaj kwotę, o którą chcesz zwiększyć wynagrodzenie: ";
        cin >> dodatek;

        wynagrodzenie += dodatek;
    }

    void zmien_nazwisko() {
        string dodatek;
        cout << "Podaj nowe nazwisko: ";
        cin >> dodatek;

        nazwisko = dodatek;
    }

private:
    string imie;
    string nazwisko;
    int wiek;
    string stanowisko;
    float wynagrodzenie;
    float premia;
};


int main() { 

    Pracownik p1("Kasia", "Kowalska", 52, "Dyrektor", 7800.50, 1200.75);

    cout << "== Dane pracownika ==" << endl;
    cout << p1.wyswietl() << endl;

    p1.zmien_wynagrodzenie();
    p1.zmien_nazwisko();

    cout << "== Po zmianie wynagrodzenia i nazwiska ==" << endl;
    cout << p1.wyswietl() << endl;

    return 0;
}




#include <iostream>
using namespace std;

int main() {
    int j, i;
    cout << "liczba 1: ";
    cin >> j;
    cout << "liczba 2: ";
    cin >> i;
    int** tab = new int*[j];
    for (int a = 0; a < j; a++) {
        tab[a] = new int[i];
    }

    for (int a = 0; a < j; a++) {
        for (int b = 0; b < i; b++) {
            tab[a][b] = a * b; 
        }
    }


    for (int a = 0; a < j; a++) {
        for (int b = 0; b < i; b++) {
            cout << tab[a][b] << "\k";
        }
        cout << endl;
    }

    for (int a = 0; a < j; a++) {
        delete[] tab[a];
    }
    delete[] tab;

    return 0;
}


#include <iostream>
#include <vector> 

using namespace std;

int main() {
    float l, a;

    cout << "Wpisz dlugosc: ";
    cin >> l;

    cout << "Wpisz wysokosc: ";
    cin >> a;

    vector<vector<float>> tab(a, vector<float>(l));


    for (float i = 1.0; i < l; i++) {
        for (int j = 0; j < a; j++) {
            float** tab[i][j] = (i * j) / 10; 
            cout << tab[i][j] << " ";
        }
        cout << endl;  
    }

    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<float>> tab(5, vector<float>(5));
                                                    
    float tab_2[25];
    int index = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tab[i][j] = (i * j) / 10.0f;   // dlugosc * szerokosz / 10 
            cout << tab[i][j] << " ";

            tab_2[index] = tab[i][j];
            index++;



        cout << endl;
    }

    for (int k = 0; k < 25; k++) {
        cout << "Jednowymiarowa tablica: ";
        cout << tab_2[k] << " ";

        cout << "Jednowymiarowa tablica największa: " << tab_2[24];
        cout << "Jednowymiarowa tablica najmniejsza: " << tab_2[0];
        cout << "Jednowymiarowa tablica: przedostatnia: " << tab_2[23];
        cout << "Jednowymiarowa tablica: druga: " << tab_2[1];
    }

    return 0;
}





#include <iostream>
using namespace std;

int main() {
    int j, i;
    cout << "liczba 1: ";
    cin >> j;
    cout << "liczba 2: ";
    cin >> i;
    int** tab = new int*[j];
    for (int a = 0; a < j; a++) {
        tab[a] = new int[i];
    }

    for (int a = 0; a < j; a++) {
        for (int b = 0; b < i; b++) {
            tab[a][b] = a * b; 
        }
    }


    for (int a = 0; a < j; a++) {
        for (int b = 0; b < i; b++) {
            cout << tab[a][b] << "\t";
        }
        cout << endl;
    }

    for (int a = 0; a < j; a++) {
        delete[] tab[a];
    }
    delete[] tab;

    return 0;
}



#include <iostream>
using namespace std;

class Player {
public:
    int id_gracza;
    string nazwa;
    int hp;
    int armor;
    int sila_ataku;
    float skutecznosc;

    
    Player(int id, string n, int h, int a, int sa, float s)
        : id_gracza(id), nazwa(n), hp(h), armor(a), sila_ataku(sa), skutecznosc(s) {}

  
    void dodaj_hp() {
        int dodac_hp;
        cout << "Dodaj HP: ";
        cin >> dodac_hp;
        hp += dodac_hp;
    }

    void odejmij_hp() {
        int odejmij;
        cout << "Odejmij HP: ";
        cin >> odejmij;
        hp -= odejmij;
    }

    void dodaj_armor() {
        int dodaj;
        cout << "Dodaj armor: ";
        cin >> dodaj;
        armor += dodaj;
    }

    void odejmij_armor() {
        int odejmij;
        cout << "Odejmij armor: ";
        cin >> odejmij;
        armor -= odejmij;
    }

    void wprowadz_atak() {
        int atak;
        cout << "Wprowadz atak: ";
        cin >> atak;
        sila_ataku = atak;
    }

    void przyjmij_atak() {
        int atak;
        cout << "Przyjmij atak: ";
        cin >> atak;
        hp -= atak;
    }

    void znaleziono_apteczke() {
        int leczenie;
        cout << "Znaleziono apteczke: ";
        cin >> leczenie;
        hp += leczenie;
    }

    void full_opis_gracza() {
        cout << "ID gracza: " << id_gracza << endl;
        cout << "Nazwa: " << nazwa << endl;
        cout << "HP: " << hp << endl;
        cout << "Armor: " << armor << endl;
        cout << "Sila ataku: " << sila_ataku << endl;
        cout << "Skutecznosc: " << skutecznosc << endl;
    }
};

int main() {
    Player gracz1(123123123, "Wojownik", 100, 50, 0, 0.80);

    gracz1.full_opis_gracza();

    gracz1.dodaj_hp();
    gracz1.znaleziono_apteczke();
    gracz1.odejmij_hp();

    gracz1.full_opis_gracza();

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    // --- CZĘŚĆ 1: Tablica statyczna ---
    const int WIERSZE = 2;
    const int KOLUMNY = 3;
    int tablicaStatyczna[WIERSZE][KOLUMNY];

    cout << "Wprowadz dane do tablicy statycznej (" << WIERSZE << "x" << KOLUMNY << "):" << endl;
    for (int i = 0; i < WIERSZE; i++) {
        for (int j = 0; j < KOLUMNY; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> tablicaStatyczna[i][j];
        }
    }

    cout << "\nZawartosc tablicy statycznej:" << endl;
    for (int i = 0; i < WIERSZE; i++) {
        for (int j = 0; j < KOLUMNY; j++) {
            cout << tablicaStatyczna[i][j] << " ";
        }
        cout << endl;
    }

    // --- CZĘŚĆ 2: Tablica dynamiczna ---
    int wiersze, kolumny;
    cout << "\nPodaj liczbe wierszy i kolumn tablicy dynamicznej: ";
    cin >> wiersze >> kolumny;

    // Tworzenie tablicy dynamicznej
    int** tablicaDynamiczna = new int*[wiersze];
    for (int i = 0; i < wiersze; i++) {
        tablicaDynamiczna[i] = new int[kolumny];
    }

    cout << "Wprowadz dane do tablicy dynamicznej (" << wiersze << "x" << kolumny << "):" << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> tablicaDynamiczna[i][j];
        }
    }

    cout << "\nZawartosc tablicy dynamicznej:" << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            cout << tablicaDynamiczna[i][j] << " ";
        }
        cout << endl;
    }

    // Zwolnienie pamięci po tablicy dynamicznej
    for (int i = 0; i < wiersze; i++) {
        delete[] tablicaDynamiczna[i];
    }
    delete[] tablicaDynamiczna;

    return 0;
}


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int SZEROKOSC, WYSOKOSC;

    cout << "Wrowadz dane szerokosci" << endl;
    cin >> SZEROKOSC;

    cout << "Wrowadz dane wysokosci" << endl;
    cin >> WYSOKOSC;


    char** tablica = new char*[WYSOKOSC];
    for (int i = 0; i < WYSOKOSC; i++) {
        tablica[i] = new char[SZEROKOSC];
    }

 
    srand(time(nullptr));


    for (int i = 0; i < SZEROKOSC; i++) {
        tablica[0][i] = '#';
        tablica[WYSOKOSC - 1][i] = '#';
    }


    for (int i = 0; i < WYSOKOSC; i++) {
        tablica[i][0] = '#';
        tablica[i][SZEROKOSC - 1] = '#';
    }


    for (int i = 1; i < WYSOKOSC - 1; i++) {
        for (int j = 1; j < SZEROKOSC - 1; j++) {
            int random = rand() % 2;
            if (random == 0) {
                tablica[i][j] = '.';
            } else {
                tablica[i][j] = '$';
            }
        }
    }


    for (int i = 0; i < WYSOKOSC; i++) {
        for (int j = 0; j < SZEROKOSC; j++) {
            cout << tablica[i][j];
        }
        cout << endl;
    }


    for (int i = 0; i < WYSOKOSC; i++) {
        delete[] tablica[i];
    }
    delete[] tablica;

    return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int SZEROKOSC, WYSOKOSC;

    cout << "Wrowadz dane szerokosci" << endl;
    cin >> SZEROKOSC;

    cout << "Wrowadz dane wysokosci" << endl;
    cin >> WYSOKOSC;


    char** tablica = new char*[WYSOKOSC];
    for (int i = 0; i < WYSOKOSC; i++) {
        tablica[i] = new char[SZEROKOSC];
    }

 
    srand(time(nullptr));


    for (int i = 0; i < SZEROKOSC; i++) {
        tablica[0][i] = '#';
        tablica[WYSOKOSC - 1][i] = '#';
    }


    for (int i = 0; i < WYSOKOSC; i++) {
        tablica[i][0] = '#';
        tablica[i][SZEROKOSC - 1] = '#';
    }


    for (int i = 1; i < WYSOKOSC - 1; i++) {
        for (int j = 1; j < SZEROKOSC - 1; j++) {
            int random = rand() % 2;
            if (random == 0) {
                tablica[i][j] = '.';
            } else {
                tablica[i][j] = '$';
            }
        }
    }


    for (int i = 0; i < WYSOKOSC; i++) {
        for (int j = 0; j < SZEROKOSC; j++) {
            cout << tablica[i][j];
        }
        cout << endl;
    }


    for (int i = 0; i < WYSOKOSC; i++) {
        delete[] tablica[i];
    }
    delete[] tablica;

    return 0;
}

0     	sz
0##########
#	 #
#
#		dl
#
##########



	#include <iostream>
#include <string>

using namespace std;



char* fillCharArray(char* tab, unsigned int size) {
    for (int i = 0; i < size; i++) {
        tab[i] = char((i % 26) + 65);
    }

    return tab;
}

double arrayAverage(double* tab, unsigned int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + tab[i];
    }

    return sum / size;
}
double arrayMin(double* tab, unsigned int size) {
    double min = 1e+300;
    for (int i = 0; i < size; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
    }

    return min;
}
double arrayMax(double* tab, unsigned int size) {
    double max = -1e+300;
    for (int i = 0; i < size; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}

void displayArray(char* tab, unsigned int size) {
    for (int i = 0; i < size; i++) {
        cout << tab[i];
        if (i < size-1) {
            cout << "; ";
        } else {
            cout << "\n";
        }
    }
}
void displayArray(double* tab, unsigned int size) {
    for (int i = 0; i < size; i++) {
        cout << tab[i];
        if (i < size-1) {
            cout << "; ";
        } else {
            cout << "\n";
        }
    }
}

int main()
{
    const unsigned int CHAR_TAB_SIZE = 52;
    char tab[CHAR_TAB_SIZE];

    fillCharArray(tab, CHAR_TAB_SIZE);
    displayArray(tab, CHAR_TAB_SIZE);


    int dyn_size = 0;
    while (dyn_size < 1) {
        cout << "Input array size: ";
        cin >> dyn_size;
    }
    double* dyn_tab = new double[dyn_size];

    for (int i = 0; i < dyn_size; i++) {
        cout << "Input element #" + to_string(i) + ": ";
        cin >> dyn_tab[i];
    }
    displayArray(dyn_tab, dyn_size);

    double average = arrayAverage(dyn_tab, dyn_size);
    double smallest = arrayMin(dyn_tab, dyn_size);
    double largest = arrayMax(dyn_tab, dyn_size);
    cout << "Average: " + to_string(average) << "; Smallest: " << to_string(smallest) << "; Largest: " << to_string(largest) << "\n";


    delete [] dyn_tab;

    return 0;
}\



#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int SZEROKOSC, WYSOKOSC;

    cout << "Podaj szerokosc: "; cin >> SZEROKOSC;
    cout << "Podaj wysokosc: "; cin >> WYSOKOSC;

    srand(time(NULL));

    int** tablica = new int*[WYSOKOSC];
    for (int i = 0; i < WYSOKOSC; i++) {
        tablica[i] = new int[SZEROKOSC];
    }

    for (int i = 0; i < WYSOKOSC - 1; i++) {
        for (int j = 0; j < SZEROKOSC - 1; j++) {
            tablica[i][j] = rand() % 100;
        }
    }


    for (int i = 0; i < WYSOKOSC - 1; i++) {
        int suma = 0;
        for (int j = 0; j < SZEROKOSC - 1; j++) {
            suma += tablica[i][j];
        }
        tablica[i][SZEROKOSC - 1] = suma;
    }


    for (int j = 0; j < SZEROKOSC; j++) {
        int suma = 0;
        for (int i = 0; i < WYSOKOSC - 1; i++) {
            suma += tablica[i][j];
        }
        tablica[WYSOKOSC - 1][j] = suma;
    }

    cout << "\nWynik:\n";
    for (int i = 0; i < WYSOKOSC; i++) {
        for (int j = 0; j < SZEROKOSC; j++) {
            cout << tablica[i][j] << "\t";
        }
        cout << endl;
    }

    
    for (int i = 0; i < WYSOKOSC; i++) {
        delete[] tablica[i];
    }
    delete[] tablica;

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;


class Connection{
private:
    static int count;

    static int max_connection;
    bool is_active = true;

public:
    static void New_max_connection(int new_max_connection) {
        new_max_connection = max_connection;
        cout << "Maksymalna liczba polaczen: " << new_max_connection << endl;
    
    }

    static void Status_of_connection() {
        cout << "Aktualna liczba polaczen: " << count << endl;
    }

    Connection() {
        if (count < max_connection) {
            is_active = true;
            count++;
        } else {
            is_active = false;
            cout << "Osiagnieto limit polaczen! Tworze nieaktywne polaczenie." << endl;
        }
    }
};
 int Connection::count = 0; 
 int Connection::max_connection = 100; 

int main() {
    vector<Connection> connections;
    for (int i = 0; i < 120; ++i) {
        connections.emplace_back();
    }
    Connection::New_max_connection(150);
    Connection::Status_of_connection();

    return 0;


}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pacjent {
private:
    static int id;
    static string imie;
    static string nazwisko;
    static string do_poradni;
    static int nr_w_kolejce;
    static bool czy_w_kolejce;
    static int ostatnie_id;
    static int liczba_kardiologia;
    static int liczba_neurologia;
    static int max_connection;
    static bool is_active;

public:

    static void pokaz_Dane() {
        cout << "id" << id << endl;
        cout << "imie" << imie << endl;
        cout << "nazwisko" << nazwisko << endl;
    }

public:

    Pacjent(string imie, string nazwisko, string poradnia, bool is_active = true, int id = 0, int nr_w_kolejce = 0) {
        Pacjent::imie = imie;
        Pacjent::nazwisko = nazwisko;
        Pacjent::do_poradni = poradnia;
        Pacjent::is_active = is_active;
        Pacjent::id = id;

        ostatnie_id++;
        Pacjent::id = ostatnie_id;

        if (poradnia == "kardiologia") {
            if (liczba_kardiologia > 0) {
                liczba_kardiologia--;
                czy_w_kolejce = true;
                Pacjent::nr_w_kolejce = 5 - liczba_kardiologia;
            } else {
                cout << "Limit pacjentów do kardiologii wyczerpany!" << endl;
                czy_w_kolejce = false;
                Pacjent::nr_w_kolejce = -1;
            }
        }
        else if (poradnia == "neurologia") {
            if (liczba_neurologia > 0) {
                liczba_neurologia--;
                czy_w_kolejce = true;
                Pacjent::nr_w_kolejce = 5 - liczba_neurologia;
            } else {
                cout << "Limit pacjentów do neurologii wyczerpany!" << endl;
                czy_w_kolejce = false;
                Pacjent::nr_w_kolejce = -1;
            }
        }
        else {
            cout << "Nie ma takiej poradni!" << endl;
            czy_w_kolejce = false;
            Pacjent::nr_w_kolejce = -1;
        }



    
    }

    void pokazDane() {
        cout << "ID: " << id << endl;
        cout << "Imię: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Poradnia: " << do_poradni << endl;

        if (czy_w_kolejce)
            cout << "Numer w kolejce: " << nr_w_kolejce << endl;
        else
            cout << "Pacjent nie został dodany do kolejki." << endl;
    }

    static void pokazLiczbePacjentowSzpitala() {
        cout << endl;
        cout << "Pozostało miejsc w kardiologii: " << liczba_kardiologia << endl;
        cout << "Pozostało miejsc w neurologii: " << liczba_neurologia << endl;
    }

    static void usun_pacjenta_z_kolejki(vector<Pacjent>& pacjenci, string imie_poszukiwane, string nazwisko_poszukiwane) {

        for(int i = 0; i < pacjenci.size(); i++) {
            if(pacjenci[i].imie == imie_poszukiwane && pacjenci[i].nazwisko == nazwisko_poszukiwane) {
                if(pacjenci[i].do_poradni == "kardiologia") {
                    liczba_kardiologia++;
                } else if(pacjenci[i].do_poradni == "neurologia") {
                    liczba_neurologia++;
                }
                pacjenci.erase(pacjenci.begin() + i);
                cout << "Pacjent " << imie_poszukiwane << " " << nazwisko_poszukiwane << " został usunięty z kolejki." << endl;
                return;
            }
        }

        
    }
};

int Pacjent::id = 0;
string Pacjent::imie = "";
string Pacjent::nazwisko = "";
string Pacjent::do_poradni = "";
int Pacjent::nr_w_kolejce = 1;
bool Pacjent::czy_w_kolejce = false;
int Pacjent::ostatnie_id = 10;
int Pacjent::liczba_kardiologia = 5;
int Pacjent::liczba_neurologia = 5;
int Pacjent::max_connection = 10;
bool Pacjent::is_active = true;

int main() {
    vector<Pacjent*> pacjenci = {
        new Pacjent ("Fred" "asdasd" "kardiologia"),
        new Pacjent ("Fred" "asdasd" "kardiologia"),
        new Pacjent ("Fred" "asdasd" "kardiologia"),
        new Pacjent ("Fred" "asdasd" "kardiologia"),
        new Pacjent ("Fred" "asdasd" "kardiologia"),

        new Pacjent ("Fred" "asdasd" "neurologia"),
        new Pacjent ("Fred" "asdasd" "neurologia"),
        new Pacjent ("Fred" "asdasd" "neurologia"),
        new Pacjent ("Fred" "asdasd" "neurologia"),
        new Pacjent ("Fred" "asdasd" "neurologia"),
        new Pacjent ("Fred" "asdasd" "neurologia"),

    }
    

    
    Pacjent p1(imie, nazwisko, poradnia, true);

    Pacjent::pokazLiczbePacjentowSzpitala();

    cout << "Podaj imie pacjenta do usunięcia z kolejki: ";
    cin >> imie;
    cout << "Podaj nazwisko pacjenta do usunięcia z kolejki: ";
    cin >> nazwisko;

    Pacjent::usun_pacjenta_z_kolejki(pacjenci, imie, nazwisko);

    Pacjent::pokaz_Dane();
}



 /// 
#include <iostream>
#include <string>
using namespace std;

class Przedmiot {
    private:
        string nazwa;
        int wartosc;
        double waga;
    
    public:

    string getNazwa() {
        return nazwa;
    }
    int getWatrosc() {
        return wartosc;
    }

    double getWaga() {
        return waga;
    }

    Przedmiot(string n, int w, double wg) : 
    nazwa(n), wartosc(w), waga(wg) {}

    Przedmiot (){
        if(nazwa.empty()){
            nazwa = "Nieznany";
            wartosc = 0;
            waga = 0.0;
        }
    }

    string pobierzNazwe() {
        cout << "Nazwa przedmiotu: ";
        string nazwa;
        cin >> nazwa;
        cout << "Podana nazwa to: " << nazwa << endl;
        return nazwa;
        
    }

    int pobierzWartosc() {
        cout << "Wartosc przedmiotu: ";
        int wartosc;
        cin >> wartosc;
        cout << "Podana wartosc to: " << wartosc << endl;
        return wartosc;
    }

    double pobierzWage() {
        cout << "Waga przedmiotu: ";
        double waga;
        cin >> waga;
        cout << "Podana waga to: " << waga << endl;

        return waga;
    }

    static void ustawWartosc(int nowaWartosc) {
        if(nowaWartosc < 0) {
            nowaWartosc = 0;
        }

        int wartosc = nowaWartosc;
        cout << "Wartosc przedmiotu to: " << wartosc << endl;

    }

    static void ustawWage(double nowaWaga) {
        if(nowaWaga < 0) {
            nowaWaga = 0.0;
        }

        int waga = nowaWaga;

        cout << "Waga przedmiotu to: " << waga << endl;
        
    }


        
    string wyswietlInformacje(){
        return "Nazwa: " + nazwa + ", Wartosc: " + to_string(wartosc) + ", Waga: " + to_string(waga);
    }

};

    

int main() {

    Przedmiot* Magiczny_Miecz = new Przedmiot("Magiczny Miecz", 150, 12.5);
    
    cout << Magiczny_Miecz->wyswietlInformacje() << endl;

    cout << "Podaj nowe wartosc przedmiotu: ";
    int nowaWartosc;
    cin >> nowaWartosc;
    Magiczny_Miecz.ustawWartosc(nowaWartosc);
    cout << "Podaj nowa wage przedmiotu: ";
    double nowaWaga;
    cin >> nowaWaga;

    Magiczny_Miecz.ustawWage(nowaWaga);

    cout << "Aktualna wartość przedmiotu po zmianach: " << Magiczny_Miecz.getWartosc() << endl;


    delete Magiczny_Miecz;
    return 0;


}



//////////////////////////


#include <iostream>
#include <string>
#include <iomanip> 
#include <ctime> 
#include <cstdlib> 
#include <vector>
#include <algorithm>
using namespace std;


int** utworz_tablice(int stroki) {
    int kolumn = 6;
    srand(time(nullptr));
    int** tablica = new int*[stroki];
    for (int i = 0; i < stroki; i++) {
        tablica[i] = new int[kolumn];
        for (int j = 0; j < kolumn; j++) {
            int random = rand() % 49 + 1;
            tablica[i][j] = random;
            
        }
    }



    return tablica;
}

int** filtracja_tablicy(int** Tablica, int kolumn, int stroki) {

    vector<int> used_nums;
    vector<int> full_nums;

    for (int a = 1; a < 50; a++) {
        full_nums.push_back(a);
    }

    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < kolumn; j++) {

            used_nums.push_back(Tablica[i][j]);

            // УБИРАЕМ значение из full_nums
            full_nums.erase(
                remove(full_nums.begin(), full_nums.end(), Tablica[i][j]),
                full_nums.end()
            );
        }
    }

    
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < kolumn; j++) {

            for (int x = 0; x < stroki; x++) {
                for (int y = 0; y < kolumn; y++) {

                    if (i == x && j == y) continue;

                    if (Tablica[i][j] == Tablica[x][y]) {

                        cout << "Powtorzenie: " << Tablica[i][j] << endl;

                        if (!full_nums.empty()) {
                            Tablica[i][j] = full_nums[rand() % full_nums.size()];
                        }

                        
                    }
                }
            }
        
        }
    }

    return Tablica;
}

void wypis_tablicy(int** Tablica, int kolumn, int stroki){
    for(int i = 0; i < stroki; i++){
        cout << "\n " << endl;
        for(int j = 0; j < kolumn; j++){
            cout << "n1: " << Tablica[i][j] << " ";
        }
    }
}   



int main() {
    srand(time(nullptr));
    int strok;
    cout << "napisz ilosc strok";
    cin >> strok;

    int** Tablica = utworz_tablice(strok);
    int** Tablica_bez_powtarzen = filtracja_tablicy(Tablica, 6, strok);


    int kolumn = 6;
    wypis_tablicy(Tablica_bez_powtarzen, kolumn, strok);


}

////////////////

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //Ogólna deklaracja: vector<typ_danych_w_wektorze>nazwa_wektora;
    vector <int> wLiczb; //deklaracja wektora liczb całkowitych;
    vector <string> marki_aut = {"Volvo","BMW","Mercedes","Peugeot","Mazda"}; 
    //deklaracja wektora stringów i inicjalizacja wartościami
    vector <char> wZnakow(10,'K'); //utworzenie 10 elementowego wektora znaków 'K'
    vector <bool> wLogiczne(40); //utworzenie 40 elementowego wektora wartości log.

    /*
    Sprawdzanie liczby elementów wektora - użyj funkcji size() wywołanej na obiekcie
    typu wektor.
    */
    cout<<"Wektor marek aut liczy: "<<marki_aut.size()<<" elementów."<<endl;
    cout<<"Wektor znaków liczy: "<<wZnakow.size()<<" elementów."<<endl;
    cout<<"Wektor wartości logicznych liczy: "<<wLogiczne.size()<<" elementów."<<endl;
    cout<<"Wektor liczb całkowitych: "<<wLiczb.size()<<" elementów."<<endl<<endl;

    //Sprawdzanie czy wektor jest pusty: 1 - pusty, 0 - nie jest pusty
    cout<<"Czy wektor marek aut jest pusty? "<<marki_aut.empty()<<endl;
    string odpowiedz = wLiczb.empty()?"Tak, jest pusty.":"Nie, nie jest pusty.";
    cout<<"Czy wektor liczb jest pusty? "<<odpowiedz<<endl;

    /*
    Jak dodać elementy na koniec wektora? 
    Używamy funkcji push_back("wartość") na obiekcie typu wektor.
    */
    wLiczb.push_back(10); //funkcja push_back('x') dodaje element na koniec wektora
    wLiczb.push_back(13);
    wLiczb.push_back(15);
    wLiczb.push_back(18);

    //Wyświetlenie zawartości wektora - z użyciem pętli (1):
    cout<<"Wyświetlam zawartość wektora liczb: "<<endl;
    for(int i=0; i<wLiczb.size(); i++){
        if(i+1==wLiczb.size())
            cout<<wLiczb[i]<<"."; //użycie operatora tablicowego []
        else 
            cout<<wLiczb[i]<<" ";    
        }
    cout<<endl;

    for(size_t i=0; i<wLiczb.size(); i++){ //typ size_t to wbudowany typ liczbowy 
        if(i+1==wLiczb.size())             //bez znaku (możemy tym typem zastapić int)
            cout<<wLiczb.at(i)<<"."; //z użyciem funkcji at(), która jednocześnie
                                    //zapobiega wyjściu poza wektor.
        else 
            cout<<wLiczb.at(i)<<" ";    
    }
    cout<<endl;
    cout<<"Wektor liczb ma "<<wLiczb.size()<<" elementów."<<endl;
    //cout<<wLiczb[10]<<endl; //proszę przetestować
    //cout<<wLiczb.at(10)<<endl; //proszę przetestować
    cout<<wLiczb[2]<<"; "<<wLiczb.at(2)<<endl;
    cout<<wLiczb[wLiczb.size()-1]<<endl;
    cout<<wLiczb.at(wLiczb.size()-1)<<endl;

////////////////////////////////////////////////////////////////
    int x;
    cout << "wpisz x elementow";
    cin >> x;
    int a = x;
    srand(time(nullptr));
    vector<int> Tablica;
    for(int a = 0; a < x; a++){
        Tablica.push_back(rand() % 9 + 1);
        cout << "element tablicy :" << Tablica[a] << "\n";
    }

    for(int x; x > 0; x--){
        Tablica.pop_back();
        for(int i = 0; i < a; i++){
        cout << "wartosc tablicy: " << Tablica[i] << "\n";
    }
}

    return 0;
}


#include <iostream> 
#include <fstream> 
#include <string>   

using namespace std;

int main() {
 
    string myText;

    string filePath = "C:\\myprogs\\text_dla_pobierania.txt"; 

    ifstream MyReadFile(filePath);

    if (!MyReadFile.is_open()) {
        cerr << "Error: Could not open file " << filePath << endl;
        return 1; 
    }


    while (getline(MyReadFile, myText)) {

        cout << myText << endl;
    }


    MyReadFile.close();

    return 0;
}


#include<iostream>
#include <fstream>
 
using namespace std;

int main(){

    ifstream plik("dane2.txt", ios::in | ios::out); //tworzę strumień do odczytu pliku
    //"C://Users//Karol//OneDrive//Pulpit//IV rok - technika//Kody biezace//dane.txt";

    if(!plik.is_open())
    {   cout<<"Nie udało się otworzyć pliku dane.txt, program zostanie zamknięty"<<endl;
        return 1;
    }

    int x;
    double suma=0.0;
    while(plik>>x){ //domyślnym separatorem przy wczytywaniu jest spacja
        cout<<"Wczytałem: "<<x<<endl;
        suma+=x;
        //cout<<suma<<endl;
    }
    cout<<"Suma wartości liczbowych w wczytanym pliku to: "<<suma<<endl;
    
    //A co zrobić aby wczytać ten sam plik ponownie?
    plik.clear(); //żeby usnąć ustawioną flagę końca pliku
    plik.seekg(0,plik.beg); //żeby przejść na początek pliku 
    /*
    argument 0 oznacza przesunięcie o 0 bajtów względem punktu odniesienia, 
    którym w tym przypadku jest początek pliku (is.beg).
    Przetestuj: 987654321
    seekg(pos, dir) ustawia pozycję kursora odczytu w strumieniu.
    dir określa punkt odniesienia:
    is.beg → początek pliku
    is.cur → bieżąca pozycja
    is.end → koniec pliku
    pos to liczba bajtów, o które przesuwasz się od tego punktu odniesienia.
    */
    
    string y; //do double można wczytać dane z kropką! Jeżeli mamy inne znaki to
    //korzystamy ze string
    while(plik>>y){
        cout<<"Wczytałem: "<<y<<" ";
    }
    plik.close(); //zamykam strumień



    return 0;
}


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // ===============================
    // 1️⃣ ЧТЕНИЕ ТЕКСТОВОГО ФАЙЛА ПО СТРОКАМ
    // ===============================

    ifstream readText("input.txt");   // файл для чтения

    if (!readText.is_open()) {
        cout << "Nie udało się otworzyć pliku input.txt" << endl;
        return 1;
    }

    cout << "=== Odczyt liniami ===" << endl;

    string line;
    while (getline(readText, line)) {
        cout << line << endl;
    }

    // ===============================
    // 2️⃣ ПОВТОРНОЕ ЧТЕНИЕ ТОГО ЖЕ ФАЙЛА
    // ===============================

    readText.clear();                  // czyszczenie flag EOF
    readText.seekg(0, readText.beg);   // powrót na początek pliku

    cout << "\n=== Odczyt jako pojedyncze elementy (string) ===" << endl;

    string word;
    while (readText >> word) {         // domyślny separator: spacja
        cout << word << " ";
    }
    cout << endl;

    readText.close(); // zamykamy plik wejściowy


    // ===============================
    // 3️⃣ ЧТЕНИЕ ЧИСЕЛ И СУММИРОВАНИЕ
    // ===============================

    ifstream readNumbers("numbers.txt");

    if (!readNumbers.is_open()) {
        cout << "Nie udało się otworzyć pliku numbers.txt" << endl;
        return 1;
    }

    cout << "\n=== Odczyt liczb ===" << endl;

    int x;
    double suma = 0.0;

    while (readNumbers >> x) {
        cout << "Wczytałem: " << x << endl;
        suma += x;
    }

    cout << "Suma: " << suma << endl;
    readNumbers.close();


    // ===============================
    // 4️⃣ ZAPIS DO NOWEGO PLIKU
    // ===============================

    ofstream saveFile("output.txt");   // tworzy plik lub nadpisuje

    saveFile << "To jest plik wynikowy" << endl;
    saveFile << "Suma z pliku numbers.txt: " << suma << endl;

    saveFile.close();


    // ===============================
    // 5️⃣ DOPISYWANIE DO ISTNIEJĄCEGO PLIKU (append)
    // ===============================

    ofstream appendFile("output.txt", ios::app);

    appendFile << "Dopisano nowa linie do pliku" << endl;

    appendFile.close();


    // ===============================
    // 6️⃣ KOPIOWANIE ZAWARTOŚCI JEDNEGO PLIKU DO DRUGIEGO
    // ===============================

    ifstream source("input.txt");
    ofstream destination("copy.txt");

    if (source.is_open() && destination.is_open()) {
        string temp;
        while (getline(source, temp)) {
            destination << temp << endl;
        }
    }

    source.close();
    destination.close();


    cout << "\nProgram zakonczyl dzialanie poprawnie." << endl;

    return 0;
}
