import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String s = sc.next();
            int b1 = sc.nextInt();
            int b2 = sc.nextInt();
            BigInteger x = new BigInteger(s, b1);
            String t = x.toString(b2).toUpperCase();
            System.out.println(String.format("%7s", t.length() > 7 ? "ERROR" : t));
        }
    }
}