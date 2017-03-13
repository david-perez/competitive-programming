import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        while (N-- > 0) {
            BigInteger p = sc.nextBigInteger();
            sc.next();
            BigInteger q = sc.nextBigInteger();
            BigInteger _gcd= p.gcd(q);
            System.out.println(p.divide(_gcd).toString() + " / " + q.divide(_gcd).toString());
        }
    }
}