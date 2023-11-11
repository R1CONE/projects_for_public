import java.io.IOException;

public class Dede {
    public static void main(String... args) throws IOException {
        char a = 'h';
        char s;
        System.out.println("Попробуй отгадать букву которую я загадал");
        System.out.print("Какую бкуву я загадал? :");
        s = (char) System.in.read();
        if (s == a) {
            System.out.println("Хорош");
        } else if (s > a) {
            System.out.println("Много");
        } else if (s < a) {
            System.out.println("Мало");
        }
    }
}









import java.util.Scanner;

import static java.lang.Math.sqrt;

public class ds {
    public static void main(String... args) {
        System.out.print("Введите переменную a: ");
        Scanner aum = new Scanner (System.in);
        int a;
        a = aum.nextInt();
        System.out.print("Введите переменную b: ");
        Scanner bum = new Scanner (System.in);
        int b;
        b = bum.nextInt();
        System.out.print("Введите переменную c: ");
        Scanner cum = new Scanner (System.in);
        int c;
        c = cum.nextInt();
        int d = b * b -4 * a * c;
        System.out.println("дискриминант :" + d);
        if (d > 0){
            int x1 = (int) (-b + sqrt(d) / 2 * a);
            int x2 = (int) (-b - sqrt(d) / 2 * a);
            System.out.println("x1 = " + x1);
            System.out.println("x2 = " + x2);
        }

        if (d == 0){
            int x = (int) (-b / 2 * a);
            System.out.println("уравнение имеет 1 корень :" + x);

        }
        if (d < 0){
            System.out.println("уравнение не имеет корней");

        }

    }

}


Scanner scan = new Scanner(System.in);
String name = scan.nextLine();


public class Prev {
    public static void main(String... args){
        public int  d1;
        d1 = 300;
    }

}


public class Boy extends Human {
 TextView hello;
        EditText first;
        EditText second;
        Button jast;
        hello = findViewById(R.id.textView);
        first = findViewById(R.id.editTextTextPersonName);
        second = findViewById(R.id.editTextTextPersonName2);
        jast = findViewById(R.id.button);
        jast.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Float num1 = Float.parseFloat(first.getText().toString());
                Float num2 = Float.parseFloat(second.getText().toString());
                Float fine = num1 + num2;
                hello.setText(String.valueOf(fine));


byte 
short
int
long

float десчятичные и после  число писать f
double сотые и после  число писать d
do => while 
        Scanner drt = new Scanner (System.in);
        char s;
        s = (char) drt.nextInt();
