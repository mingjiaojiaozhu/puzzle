const COUNT = 5
const FIRST = 0
const CENTER = 2

const RED = 0
const GREEN = 1
const WHITE = 2
const YELLOW = 3
const BLUE = 4

const BRIT = 0
const SWEDE = 1
const DANE = 2
const NORWEGIAN = 3
const GERMAN = 4

const TEA = 0
const COFFEE = 1
const MILK = 2
const JUICE = 3
const WATER = 4

const PALL_MALL = 0
const DUNHILL = 1
const BLENDS = 2
const BLUE_MASTER = 3
const PRINCE = 4

const DOG = 0
const BIRD = 1
const CAT = 2
const HORSE = 3

const COLOR = 0
const NATIONALITY = 1
const DRINK = 2
const TOBACCO = 3
const PET = 4

const rowColors = [0, 1, 2, 3, 4]
const rowNationalities = [0, 1, 2, 3, 4]
const rowDrinks = [0, 1, 2, 3, 4]
const rowTobaccos = [0, 1, 2, 3, 4]
const rowPets = [0, 1, 2, 3, 4]

const colors = ['red', 'green', 'white', 'yellow', 'blue']
const nationalities = ['Brit', 'Swede', 'Dane', 'Norwegian', 'German']
const drinks = ['tea', 'coffee', 'milk', 'juice', 'water']
const tobaccos = ['Pall_Mall', 'Dunhill', 'Blends', 'Blue_Master', 'Prince']
const pets = ['dog', 'bird', 'cat', 'horse', 'fish']

function main() {
    setColors(0)
}

function setColors(index) {
    if (COUNT === index) {
        if (1 === rowColors[WHITE] - rowColors[GREEN]) {
            setNationalities(0)
        }
        return
    }

    setColors(index + 1)
    for (let i = index + 1; i < COUNT; ++i) {
        swap(rowColors, index, i)
        setColors(index + 1)
        swap(rowColors, index, i)
    }
}

function setNationalities(index) {
    if (COUNT === index) {
        if (rowNationalities[BRIT] === rowColors[RED]
                && FIRST === rowNationalities[NORWEGIAN]
                && 1 === Math.abs(rowNationalities[NORWEGIAN] - rowColors[BLUE])) {
            setDrinks(0)
        }
        return
    }

    setNationalities(index + 1)
    for (let i = index + 1; i < COUNT; ++i) {
        swap(rowNationalities, index, i)
        setNationalities(index + 1)
        swap(rowNationalities, index, i)
    }
}

function setDrinks(index) {
    if (COUNT === index) {
        if (rowNationalities[DANE] === rowDrinks[TEA]
                && rowColors[GREEN] === rowDrinks[COFFEE]
                && CENTER === rowDrinks[MILK]) {
            setTobaccos(0)
        }
        return
    }

    setDrinks(index + 1)
    for (let i = index + 1; i < COUNT; ++i) {
        swap(rowDrinks, index, i)
        setDrinks(index + 1)
        swap(rowDrinks, index, i)
    }
}

function setTobaccos(index) {
    if (COUNT === index) {
        if (rowColors[YELLOW] === rowTobaccos[DUNHILL]
                && rowTobaccos[BLUE_MASTER] === rowDrinks[JUICE]
                && rowNationalities[GERMAN] === rowTobaccos[PRINCE]
                && 1 === Math.abs(rowTobaccos[BLENDS] - rowDrinks[WATER])) {
            setPets(0)
        }
        return
    }

    setTobaccos(index + 1)
    for (let i = index + 1; i < COUNT; ++i) {
        swap(rowTobaccos, index, i)
        setTobaccos(index + 1)
        swap(rowTobaccos, index, i)
    }
}

function setPets(index) {
    if (COUNT === index) {
        if (rowNationalities[SWEDE] === rowPets[DOG]
                && rowTobaccos[PALL_MALL] === rowPets[BIRD]
                && 1 === Math.abs(rowTobaccos[BLENDS] - rowPets[CAT])
                && 1 === Math.abs(rowPets[HORSE] - rowTobaccos[DUNHILL])) {
            printResult()
        }
        return
    }

    setPets(index + 1)
    for (let i = index + 1; i < COUNT; ++i) {
        swap(rowPets, index, i)
        setPets(index + 1)
        swap(rowPets, index, i)
    }
}

function printResult() {
    let owers = Array.from(Array(COUNT), () => Array(COUNT))
    for (let i = 0; i < COUNT; ++i) {
        owers[rowColors[i]][COLOR] = i
        owers[rowNationalities[i]][NATIONALITY] = i
        owers[rowDrinks[i]][DRINK] = i
        owers[rowTobaccos[i]][TOBACCO] = i
        owers[rowPets[i]][PET] = i
    }

    for (let ower of owers) {
        console.log(colors[ower[COLOR]] + ' ' +
                nationalities[ower[NATIONALITY]] + ' ' +
                drinks[ower[DRINK]] + ' ' +
                tobaccos[ower[TOBACCO]] + ' ' +
                pets[ower[PET]])
    }
}

function swap(arrays, i, j) {
    arrays[i] ^= arrays[j]
    arrays[j] ^= arrays[i]
    arrays[i] ^= arrays[j]
}

main()
