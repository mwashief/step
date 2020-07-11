package UVa;

import java.math.BigInteger;
import java.util.Scanner;

public class _623 {
    public static BigInteger[] factorial = new BigInteger[1001];

    public static void generate() {
        factorial[0] = BigInteger.ONE;
        for (int i = 1; i <= 1000; i++)
            factorial[i] = factorial[i - 1].multiply(new BigInteger(String.valueOf(i)));
    }

    public static void main(String[] args) {
        generate();
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            String s = sc.nextLine();
            System.out.println(s + "!\n" + factorial[Integer.parseInt(s)]);
        }
        sc.close();
    }
}