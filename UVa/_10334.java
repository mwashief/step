package UVa;

import java.math.BigInteger;
import java.util.Scanner;

public class _10334 {

    public static BigInteger[] ways = new BigInteger[1001];

    public static void generate() {
        ways[0] = BigInteger.ONE;
        ways[1] = new BigInteger("2");
        ways[2] = new BigInteger("3");
        for (int i = 3; i < 1001; i++) {
            ways[i] = ways[i - 2].add(ways[i - 2]).add(ways[i - 3]);
        }
    }

    public static void main(String[] args) {
        generate();
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            System.out.println(ways[Integer.parseInt(sc.nextLine())]);
        }
        sc.close();
    }
}