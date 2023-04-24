#include <stdio.h>
#include <math.h>

#define SIZE 100
#define CARRY (long long) 1e10

static int get_iterations(void);
static long long calculate(long long *e_fraction, int index, int iteration, long long remainder);
static int get_total(long long value);
static int is_prime(long long value);

int main(int argc, char **argv) {
    long long e_fraction[SIZE] = {0};
    for (int i = get_iterations(); i > 1; --i) {
        long long remainder = calculate(e_fraction, 0, i, 1L);
        for (int j = 1; j < SIZE; ++j) {
            remainder = calculate(e_fraction, j, i, remainder);
        }
    }

    long long result = e_fraction[0];
    int total_pivot = get_total(result);
    int total = 0;
    if (is_prime(result)) {
        printf("%lld\n", result);
        total = total_pivot;
    }

    int digits[10] = {};
    for (int i = 1; i < SIZE; ++i) {
        long long value = e_fraction[i];
        for (int j = 9; j >= 0; --j) {
            digits[j] = (int) (value % 10);
            value /= 10;
        }

        for (int j = 0; j < 10; ++j) {
            if (total) {
                total += digits[j] - (int) (result / (CARRY / 10));
                if (total == total_pivot) {
                    result = (result % (CARRY / 10)) * 10 + digits[j];
                    printf("%lld\n", result);
                    return 0;
                }
            }

            result = (result % (CARRY / 10)) * 10 + digits[j];
            if (!total && is_prime(result)) {
                printf("%lld\n", result);
                total = total_pivot;
            }
        }
    }
    return 0;
}

static int get_iterations(void) {
    int digit = SIZE * 10;
    int result = 1;
    double remainder = 1.0 / M_E;
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

static long long calculate(long long *e_fraction, int index, int iteration, long long remainder) {
    long long value = e_fraction[index] + remainder * CARRY;
    e_fraction[index] = value / iteration;
    if (e_fraction[index] >= CARRY) {
        e_fraction[index] -= CARRY;
        ++e_fraction[index - 1];
    }
    return value % iteration;
}

static int get_total(long long value) {
    int result = 0;
    while (value) {
        result += (int) (value % 10);
        value /= 10;
    }
    return result;
}

static int is_prime(long long value) {
    if (!(value & 1)) {
        return (2L == value) ? 1 : 0;
    }

    long long border = (long long) sqrt(value);
    for (long long i = 3L; i <= border; i += 2) {
        if (!(value % i)) {
            return 0;
        }
    }
    return (1 != value) ? 1 : 0;
}
