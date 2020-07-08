package UVa;

import java.math.BigInteger;
import java.util.Scanner;

public class _763 {

    public static BigInteger[] fibonacci = new BigInteger[121];

    public static void generate() {
        fibonacci[0] = BigInteger.ONE;
        fibonacci[1] = new BigInteger("2");
        for (int i = 2; i < 121; i++) {
            fibonacci[i] = fibonacci[i - 1].add(fibonacci[i - 2]);
        }
    }

    public static BigInteger getFibonacciBigInteger(String s) {
        BigInteger temp = BigInteger.ZERO;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '1') {
                temp = temp.add(fibonacci[s.length() - 1 - i]);
            }
        }
        return temp;
    }

    public static String getFibonary(BigInteger num) {
        if (num.compareTo(BigInteger.valueOf(0)) == 0) {
            return "0";
        }
        StringBuffer sb = new StringBuffer();
        boolean flag = false;
        for (int i = 120; i >= 0; i--) {
            if (fibonacci[i].compareTo(num) != 1) {
                flag = true;
                num = num.subtract(fibonacci[i]);
                sb.append("1");
            } else if (flag) {
                sb.append("0");
            }
        }
        return new String(sb);
    }

    public static void main(String[] args) {
        generate();
        String s1, s2;
        boolean first = true;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            if (first)
                first = false;
            else {
                System.out.println("");
            }
            s1 = sc.nextLine();
            s2 = sc.nextLine();
            if (sc.hasNextLine())
                sc.nextLine();
            System.out.println(getFibonary(getFibonacciBigInteger(s1).add(getFibonacciBigInteger(s2))));
        }
        sc.close();
    }
}