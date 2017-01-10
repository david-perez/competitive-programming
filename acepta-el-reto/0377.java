import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger SIXTEEN = BigInteger.valueOf(16);
        BigInteger FOUR = BigInteger.valueOf(4);
        BigInteger NINE = BigInteger.valueOf(9);
        while (in.hasNextBigInteger()) {
            BigInteger x = in.nextBigInteger();
            BigInteger mod = x.mod(SIXTEEN);
            if (mod.equals(BigInteger.ZERO) || mod.equals(FOUR) || mod.equals(BigInteger.ONE) || mod.equals(NINE)) {
                System.out.println("NO SE");
            } else {
                System.out.println("IMPERFECTO");
            }
        }
    }
}