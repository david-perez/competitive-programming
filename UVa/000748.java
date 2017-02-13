import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextBigDecimal()) {
            BigDecimal R = in.nextBigDecimal();
            int n = in.nextInt();
            String res = R.pow(n).stripTrailingZeros().toPlainString();
            if (res.charAt(0) == '0')
                res = res.substring(1);
            System.out.println(res);
        }
    }
}