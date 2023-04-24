package main

import (
    "fmt"
    "math"
)

const (
    SIZE  = 100
    CARRY = int64(1e10)
)

func main() {
    eFraction := [SIZE]int64{0}
    for i := getIterations(); i > 1; i-- {
        remainder := calculate(&eFraction, 0, i, 1)
        for j := 1; j < SIZE; j++ {
            remainder = calculate(&eFraction, j, i, remainder)
        }
    }

    result := eFraction[0]
    totalPivot := getTotal(result)
    total := 0
    if isPrime(result) {
        fmt.Println(result)
        total = totalPivot
    }

    digits := [10]int{}
    for _, value := range eFraction[1:] {
        for i := 9; i >= 0; i-- {
            digits[i] = int(value % 10)
            value /= 10
        }

        for _, digit := range digits {
            if 0 != total {
                total += digit - int(result / (CARRY / 10))
                if total == totalPivot {
                    result = (result % (CARRY / 10)) * 10 + int64(digit)
                    fmt.Println(result)
                    return
                }
            }

            result = (result % (CARRY / 10)) * 10 + int64(digit)
            if 0 == total && isPrime(result) {
                fmt.Println(result)
                total = totalPivot
            }
        }
    }
}

func getIterations() int {
    digit := SIZE * 10
    result := 1
    remainder := 1.0 / math.E
    for digit >= 0 {
        for remainder < 1 {
            result += 1
            remainder *= float64(result)
        }
        for remainder >= 1 && digit >= 0 {
            remainder /= 10
            digit -= 1
        }
    }
    return result - 1
}

func calculate(eFraction *[SIZE]int64, index int, iteration int, remainder int64) int64 {
    value := eFraction[index] + remainder * CARRY
    eFraction[index] = value / int64(iteration)
    if eFraction[index] >= CARRY {
        eFraction[index] -= CARRY
        eFraction[index - 1]++
    }
    return value % int64(iteration)
}

func getTotal(value int64) int {
    result := 0
    for 0 != value {
        result += int(value % 10)
        value /= 10
    }
    return result
}

func isPrime(value int64) bool {
    if 0 == (value & 1) {
        return 2 == value
    }

    border := int64(math.Sqrt(float64(value)))
    for i := int64(3); i <= border; i += 2 {
        if 0 == value % i {
            return false
        }
    }
    return 1 != value
}
