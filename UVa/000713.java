import java.math.BigInteger;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        while (N-- > 0) {
            BigInteger b1 = new BigInteger((new StringBuilder(sc.next())).reverse().toString());
            BigInteger b2 = new BigInteger((new StringBuilder(sc.next())).reverse().toString());
            System.out.println((new BigInteger(new StringBuilder(b1.add(b2).toString()).reverse().toString())));
        }
    }
}