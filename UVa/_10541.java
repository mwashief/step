import java.math.BigInteger;
import java.util.Scanner;

public class _10541 {

    public static BigInteger C(int n, int k) {
        BigInteger result = BigInteger.ONE;
        if (k > n - k) {
            for (int i = k + 1; i <= n; i++) {
                result = result.multiply(new BigInteger(String.valueOf(i)))
                        .divide(new BigInteger(String.valueOf(i - k)));
            }
        } else {
            for (int i = n - k + 1; i <= n; i++) {
                result = result.multiply(new BigInteger(String.valueOf(i)))
                        .divide(new BigInteger(String.valueOf(i - n + k)));
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int T;
        Scanner sc = new Scanner(System.in);
        T = Integer.parseInt(sc.nextLine());
        while (T > 0) {
            T--;
            int b = 0;
            String input[] = sc.nextLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int k = Integer.parseInt(input[1]);
            if (k != 0) {
                for (int i = 2; i < input.length; i++) {
                    b += Integer.parseInt(input[i]);
                }
            }
            if (N < b + k - 1)
                System.out.println(0);
            else
                System.out.println(C(N - b + 1, k));
        }
        sc.close();
    }
}
