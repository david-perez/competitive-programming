import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigInteger max = new BigInteger("2147483647");
        while (in.hasNext()) {
            String s1 = in.next();
            String op = in.next();
            String s2 = in.next();
            BigInteger a = new BigInteger(s1);
            BigInteger b = new BigInteger(s2);
            System.out.println(s1 + " " + op + " " + s2);
            if (a.compareTo(max) > 0)
                System.out.println("first number too big");
            if (b.compareTo(max) > 0)
                System.out.println("second number too big");

            BigInteger res;
            if (op.equals("+"))
                res = a.add(b);
            else
                res = a.multiply(b);
            if (res.compareTo(max) > 0) {
                System.out.println("result too big");
            }
        }
    }
}