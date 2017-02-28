import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int b1 = sc.nextInt();
            int b2 = sc.nextInt();
            String s = sc.next();
            try {
                BigInteger x = new BigInteger(s, b1);
                System.out.println(s + " base " + b1 + " = " + x.toString(b2).toUpperCase() + " base " + b2);
            } catch (NumberFormatException e) {
                System.out.println(s + " is an illegal base " + b1 + " number");
            }
        }
    }
}