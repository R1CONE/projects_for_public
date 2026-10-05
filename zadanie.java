import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class GFG {
    public static void main(String[] args) {



        ArrayList<Integer> s = new ArrayList<>();

        System.out.println("Napisz ilosc ocen");
        Scanner aum = new Scanner (System.in);
        int ilosc = aum.nextInt();
        Random rand = new Random();    
        for(int a = 0; a < ilosc; a++){
            s.add(rand.nextInt(7));

        }

        for (int el : s){

            System.out.println( "element: " + el );

        }

        if(s.size() % 2 == 0){
            int del = s.size() / 2;
            int mid = s.indexOf(del-1);
            int mid2 = s.indexOf(del);

            System.out.println("Srednia jest: " + (mid + mid2) / 2);
        }


        if (s.size() % 2 == 0) {
            int pol1 = s.get(s.size() / 2 - 1);
            int pol2 = s.get(s.size() / 2);

            double srednia = (pol1 + pol2) / 2.0;

            System.out.println("średnia jest: " + srednia);
}
    }

}

