import java.util.Arrays;

public class GoogleQuestion {
    private static final int SIZE = 100;
    private static final long CARRY = (long) 1e10;

    public static void main(String[] args) {
        long[] eFraction = new long[SIZE];
        Arrays.fill(eFraction, 0L);
        for (int i = getIterations(); i > 1; --i) {
            long remainder = calculate(eFraction, 0, i, 1L);
            for (int j = 1; j < SIZE; ++j) {
                remainder = calculate(eFraction, j, i, remainder);
            }
        }

        long result = eFraction[0];
        int totalPivot = getTotal(result);
        int total = 0;
        if (isPrime(result)) {
            System.out.println(result);
            total = totalPivot;
        }

        int[] digits = new int[10];
        for (int i = 1; i < SIZE; ++i) {
            long value = eFraction[i];
            for (int j = 9; j >= 0; --j) {
                digits[j] = (int) (value % 10);
                value /= 10;
            }

            for (int digit : digits) {
                if (0 != total) {
                    total += digit - result / (CARRY / 10);
                    if (total == totalPivot) {
                        result = (result % (CARRY / 10)) * 10 + digit;
                        System.out.println(result);
                        return;
                    }
                }

                result = (result % (CARRY / 10)) * 10 + digit;
                if (0 == total && isPrime(result)) {
                    System.out.println(result);
                    total = totalPivot;
                }
            }
        }
    }

    private static int getIterations() {
        int digit = SIZE * 10;
        int result = 1;
        double remainder = 1.0 / Math.E;
        while (digit >= 0) {
            while (remainder < 1) {
                ++result;
                remainder *= result;
            }
            while (remainder >= 1 && digit >= 0) {
                remainder /= 10;
                --digit;
            }
        }
        return result - 1;
    }

    private static long calculate(long[] eFraction, int index, int iteration, long remainder) {
        long value = eFraction[index] + remainder * CARRY;
        eFraction[index] = value / iteration;
        if (eFraction[index] >= CARRY) {
            eFraction[index] -= CARRY;
            ++eFraction[index - 1];
        }
        return value % iteration;
    }

    private static int getTotal(long value) {
        int result = 0;
        while (0 != value) {
            result += value % 10;
            value /= 10;
        }
        return result;
    }

    private static boolean isPrime(long value) {
        if (1 != value % 6 && 5 != value % 6) {
            return 2 == value || 3 == value;
        }

        long border = (long) Math.sqrt(value);
        for (long i = 5L; i <= border; i += 6) {
            if (0 == value % i || 0 == value % (i + 2)) {
                return false;
            }
        }
        return 1 != value;
    }
}
