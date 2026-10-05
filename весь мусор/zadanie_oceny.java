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
            s.add(rand.nextInt(7 ));

        }

        for (int el : s){

            System.out.println( "element: " + el );

            for (int i = 0; i < s.size(); i++) {
            if (s.get(i) == 1) {
                s.set(i, 2);
                }
            }

        }

        if(s.contains(6)){
            System.out.println("jest obecna 6");
        }

        if(s.size() % 2 == 0){

            double del = s.size() / 2;
            double del2 = s.size() / 2 + 1;

            System.out.println("Srednia jest %2: " + (del + del2) / 2);

        }


        if (s.size() % 2 == 1) {
            double index = s.size() / 2;
            double pol1 = s.get((int) (index - 0.5)); 
            double pol2 = s.get((int) (index + 0.5));
            System.out.println("średnia jest %3: " + (pol1 + pol2) / 2);
        }

        
    }

}

