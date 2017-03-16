import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            BigInteger N = sc.nextBigInteger();
            int D = sc.nextInt();

            if (BigInteger.ZERO.equals(N) && D == 0) break;

            System.out.println(N.pow(D));
        }
    }
}