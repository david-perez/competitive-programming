import java.math.BigInteger;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            BigInteger fact = BigInteger.ONE;
            for (int i = 1; i <= n; i++)
                fact = fact.multiply(BigInteger.valueOf(i));

            System.out.println(n + "!");
            System.out.println(fact.toString());
        }
    }
}
