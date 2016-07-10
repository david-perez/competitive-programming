import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String s = sc.next();
            if (s.charAt(0) == '-') break;
            if (s.length() >= 2 && s.charAt(1) == 'x') {
                System.out.println(Integer.parseInt(s.substring(2, s.length()), 16));
            } else {
                System.out.println("0x" + (Integer.toHexString(Integer.parseInt(s))).toUpperCase());
            }
        }
    }
}
