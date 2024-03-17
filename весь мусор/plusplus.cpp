
#include <iostream>

int main(){
    //comment
    setlocale(LC_ALL, "RU");

    std::cout << "Hello World!\n" << std::endl;

    std::cout << "sec sentenses";

    return 0;
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


