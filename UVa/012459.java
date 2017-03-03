import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        List<BigInteger> v = new ArrayList<>();
        BigInteger m = BigInteger.ZERO;
        BigInteger f = BigInteger.ONE;
        v.add(m.add(f));
        for (int g = 2; g <= 80; g++) {
            BigInteger t = f;
            f = m.add(f);
            m = t;
            v.add(f.add(m));
        }

        while (sc.hasNextInt()) {
            int g = sc.nextInt();
            if (g == 0) break;

            System.out.println(v.get(g-1));
        }
    }
}