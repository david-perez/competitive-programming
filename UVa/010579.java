import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        BigInteger[] sol = new BigInteger[4787];
        sol[0] = BigInteger.ZERO;
        sol[1] = BigInteger.ONE;
        for (int i = 2; i < 4787; i++) sol[i] = sol[i-2].add(sol[i-1]);

        while (sc.hasNext()) System.out.println(sol[sc.nextInt()]);
    }
}
