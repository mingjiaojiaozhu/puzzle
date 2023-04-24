import math
from typing import List

SIZE, CARRY = 100, int(1e10)

def main() -> None:
    e_fraction = [0 for _ in range(SIZE)]
    for i in range(get_iterations(), 1, -1):
        remainder = calculate(e_fraction, 0, i, 1)
        for j in range(1, SIZE):
            remainder = calculate(e_fraction, j, i, remainder)

    result = e_fraction[0]
    total_pivot, total = get_total(result), 0
    if is_prime(result):
        print(result)
        total = total_pivot

    digits = [0 for _ in range(10)]
    for value in e_fraction[1:]:
        for i in range(9, -1, -1):
            digits[i] = value % 10
            value //= 10

        for digit in digits:
            if total:
                total += digit - result // (CARRY // 10)
                if total == total_pivot:
                    result = (result % (CARRY // 10)) * 10 + digit
                    print(result)
                    return

            result = (result % (CARRY // 10)) * 10 + digit
            if not total and is_prime(result):
                print(result)
                total = total_pivot

def get_iterations() -> int:
    digit, result, remainder = SIZE * 10, 1, 1.0 / math.e
    while digit >= 0:
        while remainder < 1:
            result += 1
            remainder *= result
        while remainder >= 1 and digit >= 0:
            remainder /= 10
            digit -= 1
    return result - 1

def calculate(e_fraction: List[int], index: int, iteration: int, remainder: int) -> int:
    value = e_fraction[index] + remainder * CARRY
    e_fraction[index] = value // iteration
    if e_fraction[index] >= CARRY:
        e_fraction[index] -= CARRY
        e_fraction[index - 1] += 1
    return value % iteration

def get_total(value: int) -> int:
    result = 0
    while value:
        result += value % 10
        value //= 10
    return result

def is_prime(value: int) -> bool:
    if not (value & 1):
        return 2 == value

    border = int(math.sqrt(value))
    for i in range(3, border + 1, 2):
        if not value % i:
            return False
    return 1 != value

if __name__ == '__main__':
    main()
