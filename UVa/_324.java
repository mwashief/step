package UVa;

import java.math.BigInteger;
import java.util.Scanner;

class _324 {
    public static BigInteger[] factorial = new BigInteger[367];

    public static void generate() {
        factorial[0] = BigInteger.ONE;
        for (int i = 1; i <= 366; i++)
            factorial[i] = factorial[i - 1].multiply(new BigInteger(String.valueOf(i)));
    }

    public static void count(int n) {
        BigInteger[] resultAndRemainder;
        BigInteger num = factorial[n];
        int digits[] = new int[10];
        do {
            resultAndRemainder = num.divideAndRemainder(BigInteger.TEN);
            digits[Math.abs(resultAndRemainder[1].intValue())]++;
            num = resultAndRemainder[0];
        } while (num.compareTo(BigInteger.ZERO) != 0);
        System.out.println(n + "! --");
        for (int i = 0; i < 2; i++) {
            for (int j = 5 * i; j < 5 * i + 5; j++) {
                System.out.print("   (" + j + ")" + String.format("%1$4s", digits[j]));
            }
            System.out.println("");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        generate();
        int x;
        while (true) {
            x = Integer.parseInt(sc.nextLine());
            if (x == 0) {
                sc.close();
                return;
            }
            count(x);
        }
    }
}