import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            int N = in.nextInt();
            BigInteger A = in.nextBigInteger();
            BigInteger sum = BigInteger.ZERO;

            BigInteger Ai = A;
            for (int i = 1; i <= N; i++) {
                sum = sum.add(BigInteger.valueOf(i).multiply(Ai));
                Ai = Ai.multiply(A);
            }

            System.out.println(sum);
        }
    }
}