public class EinsteinPuzzle {
    private static final int COUNT = 5;
    private static final int FIRST = 0;
    private static final int CENTER = 2;

    private static final int RED = 0;
    private static final int GREEN = 1;
    private static final int WHITE = 2;
    private static final int YELLOW = 3;
    private static final int BLUE = 4;

    private static final int BRIT = 0;
    private static final int SWEDE = 1;
    private static final int DANE = 2;
    private static final int NORWEGIAN = 3;
    private static final int GERMAN = 4;

    private static final int TEA = 0;
    private static final int COFFEE = 1;
    private static final int MILK = 2;
    private static final int JUICE = 3;
    private static final int WATER = 4;

    private static final int PALL_MALL = 0;
    private static final int DUNHILL = 1;
    private static final int BLENDS = 2;
    private static final int BLUE_MASTER = 3;
    private static final int PRINCE = 4;

    private static final int DOG = 0;
    private static final int BIRD = 1;
    private static final int CAT = 2;
    private static final int HORSE = 3;

    private static final int COLOR = 0;
    private static final int NATIONALITY = 1;
    private static final int DRINK = 2;
    private static final int TOBACCO = 3;
    private static final int PET = 4;

    private static final int[] rowColors = {0, 1, 2, 3, 4};
    private static final int[] rowNationalities = {0, 1, 2, 3, 4};
    private static final int[] rowDrinks = {0, 1, 2, 3, 4};
    private static final int[] rowTobaccos = {0, 1, 2, 3, 4};
    private static final int[] rowPets = {0, 1, 2, 3, 4};

    private static final String[] colors = {"red", "green", "white", "yellow", "blue"};
    private static final String[] nationalities = {"Brit", "Swede", "Dane", "Norwegian", "German"};
    private static final String[] drinks = {"tea", "coffee", "milk", "juice", "water"};
    private static final String[] tobaccos = {"Pall_Mall", "Dunhill", "Blends", "Blue_Master", "Prince"};
    private static final String[] pets = {"dog", "bird", "cat", "horse", "fish"};

    public static void main(String[] args) {
        setColors(0);
    }

    private static void setColors(int index) {
        if (COUNT == index) {
            if (1 == rowColors[WHITE] - rowColors[GREEN]) {
                setNationalities(0);
            }
            return;
        }

        setColors(index + 1);
        for (int i = index + 1; i < COUNT; ++i) {
            swap(rowColors, index, i);
            setColors(index + 1);
            swap(rowColors, index, i);
        }
    }

    private static void setNationalities(int index) {
        if (COUNT == index) {
            if (rowNationalities[BRIT] == rowColors[RED]
                    && FIRST == rowNationalities[NORWEGIAN]
                    && 1 == Math.abs(rowNationalities[NORWEGIAN] - rowColors[BLUE])) {
                setDrinks(0);
            }
            return;
        }

        setNationalities(index + 1);
        for (int i = index + 1; i < COUNT; ++i) {
            swap(rowNationalities, index, i);
            setNationalities(index + 1);
            swap(rowNationalities, index, i);
        }
    }

    private static void setDrinks(int index) {
        if (COUNT == index) {
            if (rowNationalities[DANE] == rowDrinks[TEA]
                    && rowColors[GREEN] == rowDrinks[COFFEE]
                    && CENTER == rowDrinks[MILK]) {
                setTobaccos(0);
            }
            return;
        }

        setDrinks(index + 1);
        for (int i = index + 1; i < COUNT; ++i) {
            swap(rowDrinks, index, i);
            setDrinks(index + 1);
            swap(rowDrinks, index, i);
        }
    }

    private static void setTobaccos(int index) {
        if (COUNT == index) {
            if (rowColors[YELLOW] == rowTobaccos[DUNHILL]
                    && rowTobaccos[BLUE_MASTER] == rowDrinks[JUICE]
                    && rowNationalities[GERMAN] == rowTobaccos[PRINCE]
                    && 1 == Math.abs(rowTobaccos[BLENDS] - rowDrinks[WATER])) {
                setPets(0);
            }
            return;
        }

        setTobaccos(index + 1);
        for (int i = index + 1; i < COUNT; ++i) {
            swap(rowTobaccos, index, i);
            setTobaccos(index + 1);
            swap(rowTobaccos, index, i);
        }
    }

    private static void setPets(int index) {
        if (COUNT == index) {
            if (rowNationalities[SWEDE] == rowPets[DOG]
                    && rowTobaccos[PALL_MALL] == rowPets[BIRD]
                    && 1 == Math.abs(rowTobaccos[BLENDS] - rowPets[CAT])
                    && 1 == Math.abs(rowPets[HORSE] - rowTobaccos[DUNHILL])) {
                printResult();
            }
            return;
        }

        setPets(index + 1);
        for (int i = index + 1; i < COUNT; ++i) {
            swap(rowPets, index, i);
            setPets(index + 1);
            swap(rowPets, index, i);
        }
    }

    private static void printResult() {
        int[][] owers = new int[COUNT][COUNT];
        for (int i = 0; i < COUNT; ++i) {
            owers[rowColors[i]][COLOR] = i;
            owers[rowNationalities[i]][NATIONALITY] = i;
            owers[rowDrinks[i]][DRINK] = i;
            owers[rowTobaccos[i]][TOBACCO] = i;
            owers[rowPets[i]][PET] = i;
        }

        for (int[] ower : owers) {
            System.out.println(colors[ower[COLOR]] + " " +
                    nationalities[ower[NATIONALITY]] + " " +
                    drinks[ower[DRINK]] + " " +
                    tobaccos[ower[TOBACCO]] + " " +
                    pets[ower[PET]]);
        }
    }

    private static void swap(int[] arrays, int i, int j) {
        arrays[i] ^= arrays[j];
        arrays[j] ^= arrays[i];
        arrays[i] ^= arrays[j];
    }
}
