package UVa;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

class _787 {

    public static <T> T[] concat(T[] first, T[] second) {
        T[] result = Arrays.copyOf(first, first.length + second.length);
        System.arraycopy(second, 0, result, first.length, second.length);
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            String[] nums = sc.nextLine().split(" ");
            while (!nums[nums.length - 1].equals("-999999")) {
                nums = concat(nums, sc.nextLine().split(" "));
            }

            BigInteger highest = new BigInteger("-999999");
            BigInteger curPos = new BigInteger("-999999");
            BigInteger curNeg = new BigInteger("-999999");

            for (int i = 0; i < nums.length - 1; i++) {
                BigInteger a = new BigInteger(nums[i]);

                if (a.compareTo(BigInteger.ZERO) == 0) {
                    curPos = new BigInteger("-999999");
                    curNeg = new BigInteger("-999999");
                    highest = highest.max(a);
                } else if (a.compareTo(BigInteger.ZERO) == -1) {
                    if (curNeg.compareTo(new BigInteger("-999999")) != 0) {
                        if (curPos.compareTo(new BigInteger("-999999")) != 0) {
                            BigInteger temp = curPos;
                            curPos = curNeg.multiply(a);
                            curNeg = temp.multiply(a);
                        } else {
                            curPos = curNeg.multiply(a);
                            curNeg = a;
                        }
                    } else {
                        if (curPos.compareTo(new BigInteger("-999999")) != 0) {
                            curNeg = curPos.multiply(a);
                        } else {
                            curNeg = a;
                        }
                        curPos = new BigInteger("-999999");
                    }
                } else {
                    if (curPos.compareTo(new BigInteger("-999999")) != 0) {
                        curPos = curPos.multiply(a);
                    } else {
                        curPos = a;
                    }
                    if (curNeg.compareTo(new BigInteger("-999999")) != 0) {
                        curNeg = curNeg.multiply(a);
                    }
                }

                highest = highest.max(curPos);
                highest = highest.max(curNeg);
            }
            System.out.println(highest);
        }
        sc.close();
    }
}