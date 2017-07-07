import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = 1;
        while (true) {
            int N = sc.nextInt();
            BigInteger F = sc.nextBigInteger();
            if (N == 0 && BigInteger.ZERO.equals(F)) break;
            BigInteger S = BigInteger.ZERO;
            for (int n = 0; n < N; n++)
                S = S.add(sc.nextBigInteger());

            System.out.println("Bill #" + t + " costs " + S + ": each friend should pay " + S.divide(F));
            System.out.println();

            t++;
        }
    }
}
