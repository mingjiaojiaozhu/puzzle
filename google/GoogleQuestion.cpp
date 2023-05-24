#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define SIZE 100
#define CARRY (long long) 1e10

static int get_iterations(void);
static long long calculate(vector<long long> &e_fraction, int index, int iteration, long long remainder);
static int get_total(long long value);
static bool is_prime(long long value);

int main(int argc, char **argv) {
    vector<long long> e_fraction(SIZE, 0L);
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
        cout << result << endl;
        total = total_pivot;
    }

    vector<int> digits(10);
    for (vector<long long>::iterator p = e_fraction.begin() + 1; p != e_fraction.end(); ++p) {
        long long value = *p;
        for (int i = 9; i >= 0; --i) {
            digits[i] = (int) (value % 10);
            value /= 10;
        }

        for (int digit : digits) {
            if (total) {
                total += digit - (int) (result / (CARRY / 10));
                if (total == total_pivot) {
                    result = (result % (CARRY / 10)) * 10 + digit;
                    cout << result << endl;
                    return 0;
                }
            }

            result = (result % (CARRY / 10)) * 10 + digit;
            if (!total && is_prime(result)) {
                cout << result << endl;
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

static long long calculate(vector<long long> &e_fraction, int index, int iteration, long long remainder) {
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

static bool is_prime(long long value) {
    if (1 != value % 6 && 5 != value % 6) {
        return 2 == value || 3 == value;
    }

    long long border = (long long) sqrt(value);
    for (long long i = 5L; i <= border; i += 6) {
        if (!(value % i) || !(value % (i + 2))) {
            return false;
        }
    }
    return 1 != value;
}
