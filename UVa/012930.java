import java.math.BigDecimal;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int t = 1; in.hasNextBigDecimal(); t++) {
            BigDecimal a = in.nextBigDecimal();
            BigDecimal b = in.nextBigDecimal();
            int res = a.compareTo(b);
            if (res == 1) System.out.println("Case " + t + ": Bigger");
            else if (res == -1) System.out.println("Case " + t + ": Smaller");
            else System.out.println("Case " + t + ": Same");
        }
    }
}