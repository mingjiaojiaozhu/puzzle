const SIZE = 100
const CARRY = 1e10

function main() {
    let eFraction = Array(SIZE).fill(0)
    for (let i = getIterations(); i > 1; --i) {
        let remainder = calculate(eFraction, 0, i, 1)
        for (let j = 1; j < SIZE; ++j) {
            remainder = calculate(eFraction, j, i, remainder)
        }
    }

    let result = eFraction[0]
    let totalPivot = getSum(result)
    let total = 0
    if (isPrime(result)) {
        console.log(result)
        total = totalPivot
    }

    let digits = new Array(10)
    for (let value of eFraction.slice(1)) {
        for (let i = 9; i >= 0; --i) {
            digits[i] = value % 10
            value = Math.floor(value / 10)
        }

        for (let digit of digits) {
            if (total) {
                total += digit - Math.floor(result / (CARRY / 10))
                if (total === totalPivot) {
                    result = (result % (CARRY / 10)) * 10 + digit
                    console.log(result)
                    return
                }
            }

            result = (result % (CARRY / 10)) * 10 + digit
            if (!total && isPrime(result)) {
                console.log(result)
                total = totalPivot
            }
        }
    }
}

function getIterations() {
    let digit = SIZE * 10
    let result = 1
    let remainder = 1.0 / Math.E
    while (digit >= 0) {
        while (remainder < 1) {
            ++result
            remainder *= result
        }
        while (remainder >= 1 && digit >= 0) {
            remainder /= 10
            --digit
        }
    }
    return result - 1
}

function calculate(eFraction, index, iteration, remainder) {
    let value = eFraction[index] + remainder * CARRY
    eFraction[index] = Math.floor(value / iteration)
    if (eFraction[index] >= CARRY) {
        eFraction[index] -= CARRY
        ++eFraction[index - 1]
    }
    return value % iteration
}

function getSum(value) {
    let result = 0
    while (value) {
        result += value % 10
        value = Math.floor(value / 10)
    }
    return result
}

function isPrime(value) {
    if (0 === (value & 1)) {
        return 2 === value
    }

    let border = Math.floor(Math.sqrt(value))
    for (let i = 3; i <= border; i += 2) {
        if (!(value % i)) {
            return false
        }
    }
    return 1 !== value
}

main()
