import java.math.BigInteger;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger sv = new BigInteger("17");
        BigInteger b = new BigInteger(sc.next());
        while (!b.equals(BigInteger.ZERO)) {
            System.out.println(b.mod(sv).equals(BigInteger.ZERO) ? "1" : "0");

            b = new BigInteger(sc.next());
        }
    }
}