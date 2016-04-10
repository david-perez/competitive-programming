import java.math.BigInteger;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger num = BigInteger.ZERO;
        while (in.hasNext()) {
            BigInteger buff = in.nextBigInteger();
            if (buff.equals(BigInteger.ZERO)) break;
            num = num.add(buff);
        }
        System.out.println(num);
    }
}
