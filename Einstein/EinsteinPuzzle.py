COUNT, FIRST, CENTER = 5, 0, 2
RED, GREEN, WHITE, YELLOW, BLUE = 0, 1, 2, 3, 4
BRIT, SWEDE, DANE, NORWEGIAN, GERMAN = 0, 1, 2, 3, 4
TEA, COFFEE, MILK, JUICE, WATER = 0, 1, 2, 3, 4
PALL_MALL, DUNHILL, BLENDS, BLUE_MASTER, PRINCE = 0, 1, 2, 3, 4
DOG, BIRD, CAT, HORSE = 0, 1, 2, 3
COLOR, NATIONALITY, DRINK, TOBACCO, PET = 0, 1, 2, 3, 4

row_colors = [i for i in range(COUNT)]
row_nationalities = [i for i in range(COUNT)]
row_drinks = [i for i in range(COUNT)]
row_tobaccos = [i for i in range(COUNT)]
row_pets = [i for i in range(COUNT)]

colors = ['red', 'green', 'white', 'yellow', 'blue']
nationalities = ['Brit', 'Swede', 'Dane', 'Norwegian', 'German']
drinks = ['tea', 'coffee', 'milk', 'juice', 'water']
tobaccos = ['Pall_Mall', 'Dunhill', 'Blends', 'Blue_Master', 'Prince']
pets = ['dog', 'bird', 'cat', 'horse', 'fish']

def main() -> None:
    set_colors(0)

def set_colors(index: int) -> None:
    if COUNT == index:
        if 1 == row_colors[WHITE] - row_colors[GREEN]:
            set_nationalities(0)
        return

    set_colors(index + 1)
    for i in range(index + 1, COUNT):
        row_colors[index], row_colors[i] = row_colors[i], row_colors[index]
        set_colors(index + 1)
        row_colors[index], row_colors[i] = row_colors[i], row_colors[index]

def set_nationalities(index: int) -> None:
    if COUNT == index:
        if row_nationalities[BRIT] == row_colors[RED] \
                and FIRST == row_nationalities[NORWEGIAN] \
                and 1 == abs(row_nationalities[NORWEGIAN] - row_colors[BLUE]):
            set_drinks(0)
        return

    set_nationalities(index + 1)
    for i in range(index + 1, COUNT):
        row_nationalities[index], row_nationalities[i] = row_nationalities[i], row_nationalities[index]
        set_nationalities(index + 1)
        row_nationalities[index], row_nationalities[i] = row_nationalities[i], row_nationalities[index]

def set_drinks(index: int) -> None:
    if COUNT == index:
        if row_nationalities[DANE] == row_drinks[TEA] \
                and row_colors[GREEN] == row_drinks[COFFEE] \
                and CENTER == row_drinks[MILK]:
            set_tobaccos(0)
        return

    set_drinks(index + 1)
    for i in range(index + 1, COUNT):
        row_drinks[index], row_drinks[i] = row_drinks[i], row_drinks[index]
        set_drinks(index + 1)
        row_drinks[index], row_drinks[i] = row_drinks[i], row_drinks[index]

def set_tobaccos(index: int) -> None:
    if COUNT == index:
        if row_colors[YELLOW] == row_tobaccos[DUNHILL] \
                and row_tobaccos[BLUE_MASTER] == row_drinks[JUICE] \
                and row_nationalities[GERMAN] == row_tobaccos[PRINCE] \
                and 1 == abs(row_tobaccos[BLENDS] - row_drinks[WATER]):
            set_pets(0)
        return

    set_tobaccos(index + 1)
    for i in range(index + 1, COUNT):
        row_tobaccos[index], row_tobaccos[i] = row_tobaccos[i], row_tobaccos[index]
        set_tobaccos(index + 1)
        row_tobaccos[index], row_tobaccos[i] = row_tobaccos[i], row_tobaccos[index]

def set_pets(index: int) -> None:
    if COUNT == index:
        if row_nationalities[SWEDE] == row_pets[DOG] \
                and row_tobaccos[PALL_MALL] == row_pets[BIRD] \
                and 1 == abs(row_tobaccos[BLENDS] - row_pets[CAT]) \
                and 1 == abs(row_pets[HORSE] - row_tobaccos[DUNHILL]):
            print_result()
        return

    set_pets(index + 1)
    for i in range(index + 1, COUNT):
        row_pets[index], row_pets[i] = row_pets[i], row_pets[index]
        set_pets(index + 1)
        row_pets[index], row_pets[i] = row_pets[i], row_pets[index]

def print_result() -> None:
    owers = [[0 for _ in range(COUNT)] for _ in range(COUNT)]
    for i in range(COUNT):
        owers[row_colors[i]][COLOR] = i
        owers[row_nationalities[i]][NATIONALITY] = i
        owers[row_drinks[i]][DRINK] = i
        owers[row_tobaccos[i]][TOBACCO] = i
        owers[row_pets[i]][PET] = i

    for ower in owers:
        print(colors[ower[COLOR]] + ' ' + \
                nationalities[ower[NATIONALITY]] + ' ' + \
                drinks[ower[DRINK]] + ' ' + \
                tobaccos[ower[TOBACCO]] + ' ' + \
                pets[ower[PET]])

if __name__ == '__main__':
    main()
