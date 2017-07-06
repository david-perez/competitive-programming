import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String s = sc.next(), t = sc.next();
            if ("0".equals(s) && "0".equals(t)) break;
            t = t.replace(s, "");
            System.out.println(t.isEmpty() ? BigInteger.ZERO : new BigInteger(t));
        }
    }
}
