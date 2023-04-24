package main

import (
    "fmt"
    "math"
)

const (
    COUNT = 5
    FIRST = 0
    CENTER = 2

    RED = 0
    GREEN = 1
    WHITE = 2
    YELLOW = 3
    BLUE = 4

    BRIT = 0
    SWEDE = 1
    DANE = 2
    NORWEGIAN = 3
    GERMAN = 4

    TEA = 0
    COFFEE = 1
    MILK = 2
    JUICE = 3
    WATER = 4

    PALL_MALL = 0
    DUNHILL = 1
    BLENDS = 2
    BLUE_MASTER = 3
    PRINCE = 4

    DOG = 0
    BIRD = 1
    CAT = 2
    HORSE = 3

    COLOR = 0
    NATIONALITY = 1
    DRINK = 2
    TOBACCO = 3
    PET = 4
)

var rowColors = [COUNT]int{0, 1, 2, 3, 4}
var rowNationalities = [COUNT]int{0, 1, 2, 3, 4}
var rowDrinks = [COUNT]int{0, 1, 2, 3, 4}
var rowTobaccos = [COUNT]int{0, 1, 2, 3, 4}
var rowPets = [COUNT]int{0, 1, 2, 3, 4}

var colors = [COUNT]string{"red", "green", "white", "yellow", "blue"}
var nationalities = [COUNT]string{"Brit", "Swede", "Dane", "Norwegian", "German"}
var drinks = [COUNT]string{"tea", "coffee", "milk", "juice", "water"}
var tobaccos = [COUNT]string{"Pall_Mall", "Dunhill", "Blends", "Blue_Master", "Prince"}
var pets = [COUNT]string{"dog", "bird", "cat", "horse", "fish"}

func main() {
    setColors(0)
}

func setColors(index int) {
    if COUNT == index {
        if 1 == rowColors[WHITE] - rowColors[GREEN] {
            setNationalities(0)
        }
        return
    }

    setColors(index + 1)
    for i := index + 1; i < COUNT; i++ {
        rowColors[index], rowColors[i] = rowColors[i], rowColors[index]
        setColors(index + 1)
        rowColors[index], rowColors[i] = rowColors[i], rowColors[index]
    }
}

func setNationalities(index int) {
    if COUNT == index {
        if rowNationalities[BRIT] == rowColors[RED] &&
                FIRST == rowNationalities[NORWEGIAN] &&
                1 == math.Abs(float64(rowNationalities[NORWEGIAN]-rowColors[BLUE])) {
            setDrinks(0)
        }
        return
    }

    setNationalities(index + 1)
    for i := index + 1; i < COUNT; i++ {
        rowNationalities[index], rowNationalities[i] = rowNationalities[i], rowNationalities[index]
        setNationalities(index + 1)
        rowNationalities[index], rowNationalities[i] = rowNationalities[i], rowNationalities[index]
    }
}

func setDrinks(index int) {
    if COUNT == index {
        if rowNationalities[DANE] == rowDrinks[TEA] &&
                rowColors[GREEN] == rowDrinks[COFFEE] &&
                CENTER == rowDrinks[MILK] {
            setTobaccos(0)
        }
        return
    }

    setDrinks(index + 1)
    for i := index + 1; i < COUNT; i++ {
        rowDrinks[index], rowDrinks[i] = rowDrinks[i], rowDrinks[index]
        setDrinks(index + 1)
        rowDrinks[index], rowDrinks[i] = rowDrinks[i], rowDrinks[index]
    }
}

func setTobaccos(index int) {
    if COUNT == index {
        if rowColors[YELLOW] == rowTobaccos[DUNHILL] &&
                rowTobaccos[BLUE_MASTER] == rowDrinks[JUICE] &&
                rowNationalities[GERMAN] == rowTobaccos[PRINCE] &&
                1 == math.Abs(float64(rowTobaccos[BLENDS]-rowDrinks[WATER])) {
            setPets(0)
        }
        return
    }

    setTobaccos(index + 1)
    for i := index + 1; i < COUNT; i++ {
        rowTobaccos[index], rowTobaccos[i] = rowTobaccos[i], rowTobaccos[index]
        setTobaccos(index + 1)
        rowTobaccos[index], rowTobaccos[i] = rowTobaccos[i], rowTobaccos[index]
    }
}

func setPets(index int) {
    if COUNT == index {
        if rowNationalities[SWEDE] == rowPets[DOG] &&
                rowTobaccos[PALL_MALL] == rowPets[BIRD] &&
                1 == math.Abs(float64(rowTobaccos[BLENDS]-rowPets[CAT])) &&
                1 == math.Abs(float64(rowPets[HORSE] - rowTobaccos[DUNHILL])) {
            printResult()
        }
        return
    }

    setPets(index + 1)
    for i := index + 1; i < COUNT; i++ {
        rowPets[index], rowPets[i] = rowPets[i], rowPets[index]
        setPets(index + 1)
        rowPets[index], rowPets[i] = rowPets[i], rowPets[index]
    }
}

func printResult() {
    owers := [COUNT][COUNT]int{}
    for i := 0; i < COUNT; i++ {
        owers[rowColors[i]][COLOR] = i
        owers[rowNationalities[i]][NATIONALITY] = i
        owers[rowDrinks[i]][DRINK] = i
        owers[rowTobaccos[i]][TOBACCO] = i
        owers[rowPets[i]][PET] = i
    }

    for _, ower := range owers {
        fmt.Println(colors[ower[COLOR]] + " " +
                nationalities[ower[NATIONALITY]] + " " +
                drinks[ower[DRINK]] + " " +
                tobaccos[ower[TOBACCO]] + " " +
                pets[ower[PET]])
    }
}
