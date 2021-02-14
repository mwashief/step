import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class _1244C {
    public static ArrayList<BigInteger> egcd(BigInteger a, BigInteger b) {
        ArrayList<BigInteger> res = new ArrayList<>();
        if (b.equals(BigInteger.ZERO)) {
            res.add(a);
            res.add(BigInteger.ONE);
            res.add(BigInteger.ZERO);
            return res;
        }
        BigInteger x1, y1;
        ArrayList<BigInteger> d = egcd(b, a.remainder(b));
        x1 = d.get(1);
        y1 = d.get(2);
        BigInteger x = y1;
        BigInteger y = x1.subtract(y1.multiply(a.divide(b)));
        res.add(d.get(0));
        res.add(x);
        res.add(y);
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger n, p, a, b;
        n = sc.nextBigInteger();
        p = sc.nextBigInteger();
        a = sc.nextBigInteger();
        b = sc.nextBigInteger();
        sc.close();
        ArrayList<BigInteger> res = egcd(a, b);
        BigInteger g = res.get(0);
        if (p.remainder(g).compareTo(BigInteger.ZERO) != 0) {
            System.out.println(-1);
            return;
        }
        BigInteger x0 = res.get(1);
        BigInteger y0 = res.get(2);
        BigInteger d = p.divide(g);
        x0 = x0.multiply(d);
        y0 = y0.multiply(d);
        BigInteger l = x0.multiply(g).divide(b);
        l = l.negate();
        BigInteger r = y0.multiply(g).divide(a);
        r = r.min(n.subtract(x0).multiply(g).divide(b));
        l = l.max(y0.subtract(n).multiply(g).divide(a));

        BigInteger x = BigInteger.ONE.negate();
        BigInteger y = BigInteger.ONE.negate();
        while (l.compareTo(r) != 1) {
            BigInteger mid = l.add(r).divide(BigInteger.TWO);
            x = x0.add(b.multiply(mid).divide(g));
            y = y0.subtract(a.multiply(mid).divide(g));
            if (x.compareTo(BigInteger.ZERO) != -1 && y.compareTo(BigInteger.ZERO) != -1 && x.add(y).compareTo(n) != 1)
                break;
            if (x.compareTo(BigInteger.ZERO) == -1)
                l = mid.add(BigInteger.ONE);
            else if (y.compareTo(BigInteger.ZERO) == -1)
                r = mid.subtract(BigInteger.ONE);
            else if (a.compareTo(b) == 1)
                l = mid.add(BigInteger.ONE);
            else
                r = mid.subtract(BigInteger.ONE);
        }

        if (!(x.compareTo(BigInteger.ZERO) != -1 && y.compareTo(BigInteger.ZERO) != -1 && x.add(y).compareTo(n) != 1)) {
            System.out.println(-1);
            return;
        }

        System.out.println(x + " " + y + " " + n.subtract(x).subtract(y));
    }
}
