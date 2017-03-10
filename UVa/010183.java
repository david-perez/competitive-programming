import java.math.BigInteger;
import java.util.NavigableSet;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        BigInteger L = new BigInteger("10").pow(100);
        NavigableSet<BigInteger> s = new TreeSet<>();
        BigInteger f = BigInteger.ONE;
        BigInteger g = f.add(BigInteger.ONE);
        s.add(f);
        while (g.compareTo(L) <= 0) {
            s.add(g);
            BigInteger aux = g;
            g = f.add(g);
            f = aux;
        }

        Scanner sc = new Scanner(System.in);
        while (sc.hasNextBigInteger()) {
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            if (BigInteger.ZERO.equals(a) && BigInteger.ZERO.equals(b)) break;

            System.out.println(s.tailSet(a, true).headSet(b, true).size());
        }
    }
}