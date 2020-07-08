package UVa;

import java.math.BigInteger;
import java.util.Scanner;

public class _11955 {
    public static BigInteger c[][] = new BigInteger[51][51];

    public static BigInteger C(int n, int k) {
        if (c[n][k] != null)
            return c[n][k];
        if (k == 0 || n == k)
            return c[n][k] = BigInteger.ONE;
        return c[n][k] = C(n - 1, k - 1).add(C(n - 1, k));
    }

    public static void main(String[] args) {
        int T;
        Scanner sc = new Scanner(System.in);
        T = Integer.parseInt(sc.nextLine());
        for (int t = 1; t <= T; t++) {
            String input[] = sc.nextLine().split("\\^");
            String variables[] = input[0].split("\\+");
            variables[0] = variables[0].substring(1);
            variables[1] = variables[1].substring(0, variables[1].length() - 1);
            int power = Integer.parseInt(input[1]);
            System.out.print("Case " + t + ": " + variables[0]);
            if (power != 1) {
                System.out.print("^" + power);
            }
            for (int i = 1; i < power; i++) {
                BigInteger coeff = C(power, i);
                System.out.print("+");
                System.out.print(coeff + "*");
                System.out.print(variables[0]);
                if (power - i != 1) {
                    System.out.print("^" + (power - i));
                }
                System.out.print("*");
                System.out.print(variables[1]);
                if (i != 1) {
                    System.out.print("^" + i);
                }
            }
            System.out.print("+" + variables[1]);
            if (power != 1) {
                System.out.print("^" + power);
            }
            System.out.println("");
        }
        sc.close();
    }
}