#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define COUNT 5
#define FIRST 0
#define CENTER 2

#define RED 0
#define GREEN 1
#define WHITE 2
#define YELLOW 3
#define BLUE 4

#define BRIT 0
#define SWEDE 1
#define DANE 2
#define NORWEGIAN 3
#define GERMAN 4

#define TEA 0
#define COFFEE 1
#define MILK 2
#define JUICE 3
#define WATER 4

#define PALL_MALL 0
#define DUNHILL 1
#define BLENDS 2
#define BLUE_MASTER 3
#define PRINCE 4

#define DOG 0
#define BIRD 1
#define CAT 2
#define HORSE 3

#define COLOR 0
#define NATIONALITY 1
#define DRINK 2
#define TOBACCO 3
#define PET 4

static vector<int> row_colors = {0, 1, 2, 3, 4};
static vector<int> row_nationalities = {0, 1, 2, 3, 4};
static vector<int> row_drinks = {0, 1, 2, 3, 4};
static vector<int> row_tobaccos = {0, 1, 2, 3, 4};
static vector<int> row_pets = {0, 1, 2, 3, 4};

static const vector<string> colors = {"red", "green", "white", "yellow", "blue"};
static const vector<string> nationalities = {"Brit", "Swede", "Dane", "Norwegian", "German"};
static const vector<string> drinks = {"tea", "coffee", "milk", "juice", "water"};
static const vector<string> tobaccos = {"Pall_Mall", "Dunhill", "Blends", "Blue_Master", "Prince"};
static const vector<string> pets = {"dog", "bird", "cat", "horse", "fish"};

static void set_colors(int index);
static void set_nationalities(int index);
static void set_drinks(int index);
static void set_tobaccos(int index);
static void set_pets(int index);
static void print_result(void);

int main(int argc, char **argv) {
    set_colors(0);
    return 0;
}

static void set_colors(int index) {
    if (COUNT == index) {
        if (1 == row_colors[WHITE] - row_colors[GREEN]) {
            set_nationalities(0);
        }
        return;
    }

    set_colors(index + 1);
    for (int i = index + 1; i < COUNT; ++i) {
        swap(row_colors[index], row_colors[i]);
        set_colors(index + 1);
        swap(row_colors[index], row_colors[i]);
    }
}

static void set_nationalities(int index) {
    if (COUNT == index) {
        if (row_nationalities[BRIT] == row_colors[RED]
                && FIRST == row_nationalities[NORWEGIAN]
                && 1 == abs(row_nationalities[NORWEGIAN] - row_colors[BLUE])) {
            set_drinks(0);
        }
        return;
    }

    set_nationalities(index + 1);
    for (int i = index + 1; i < COUNT; ++i) {
        swap(row_nationalities[index], row_nationalities[i]);
        set_nationalities(index + 1);
        swap(row_nationalities[index], row_nationalities[i]);
    }
}

static void set_drinks(int index) {
    if (COUNT == index) {
        if (row_nationalities[DANE] == row_drinks[TEA]
                && row_colors[GREEN] == row_drinks[COFFEE]
                && CENTER == row_drinks[MILK]) {
            set_tobaccos(0);
        }
        return;
    }

    set_drinks(index + 1);
    for (int i = index + 1; i < COUNT; ++i) {
        swap(row_drinks[index], row_drinks[i]);
        set_drinks(index + 1);
        swap(row_drinks[index], row_drinks[i]);
    }
}

static void set_tobaccos(int index) {
    if (COUNT == index) {
        if (row_colors[YELLOW] == row_tobaccos[DUNHILL]
                && row_tobaccos[BLUE_MASTER] == row_drinks[JUICE]
                && row_nationalities[GERMAN] == row_tobaccos[PRINCE]
                && 1 == abs(row_tobaccos[BLENDS] - row_drinks[WATER])) {
            set_pets(0);
        }
        return;
    }

    set_tobaccos(index + 1);
    for (int i = index + 1; i < COUNT; ++i) {
        swap(row_tobaccos[index], row_tobaccos[i]);
        set_tobaccos(index + 1);
        swap(row_tobaccos[index], row_tobaccos[i]);
    }
}

static void set_pets(int index) {
    if (COUNT == index) {
        if (row_nationalities[SWEDE] == row_pets[DOG]
                && row_tobaccos[PALL_MALL] == row_pets[BIRD]
                && 1 == abs(row_tobaccos[BLENDS] - row_pets[CAT])
                && 1 == abs(row_pets[HORSE] - row_tobaccos[DUNHILL])) {
            print_result();
        }
        return;
    }

    set_pets(index + 1);
    for (int i = index + 1; i < COUNT; ++i) {
        swap(row_pets[index], row_pets[i]);
        set_pets(index + 1);
        swap(row_pets[index], row_pets[i]);
    }
}

static void print_result(void) {
    vector<vector<int>> owers(COUNT, vector<int>(COUNT));
    for (int i = 0; i < COUNT; ++i) {
        owers[row_colors[i]][COLOR] = i;
        owers[row_nationalities[i]][NATIONALITY] = i;
        owers[row_drinks[i]][DRINK] = i;
        owers[row_tobaccos[i]][TOBACCO] = i;
        owers[row_pets[i]][PET] = i;
    }

    for (vector<int> ower : owers) {
        cout << colors[ower[COLOR]] << " " <<
             nationalities[ower[NATIONALITY]] << " " <<
             drinks[ower[DRINK]] << " " <<
             tobaccos[ower[TOBACCO]] << " " <<
             pets[ower[PET]] << endl;
    }
}
