/*
 * Week 02: Structs and simple combat.
 */

#include <iostream>
#include <cstring>
using namespace std;

const int ROWS = 5;
const int COLS = 7;

struct Player {
    char name[40];
    int row;
    int col;
    int hp;
    int attack;
};

struct Monster {
    char symbol;
    int row;
    int col;
    int hp;
    int attack;
};

void printMap(const char map[ROWS][COLS], const Player& player) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (r == player.row && c == player.col) {
                cout << '@';
            } else {
                cout << map[r][c];
            }
        }
        cout << endl;
    }
}

void fight(Player& player, Monster& monster) {
    cout << "A monster appears!" << endl;

    while (player.hp > 0 && monster.hp > 0) {
        monster.hp -= player.attack;
        cout << player.name << " hits for " << player.attack << "." << endl;

        if (monster.hp <= 0) {
            cout << "Monster defeated!" << endl;
            return;
        }

        player.hp -= monster.attack;
        cout << "Monster hits for " << monster.attack << "." << endl;
    }
}

int main() {
    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', '.', '.', '#', 'T', '#'},
        {'#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', 'M', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#'}
    };

    Player player;
    cout << "Enter your name: ";
    cin.getline(player.name, 40);
    player.row = 1;
    player.col = 1;
    player.hp = 20;
    player.attack = 5;

    Monster monster = {'M', 3, 2, 12, 3};

    cout << "Welcome, " << player.name << "!" << endl;
    cout << "HP: " << player.hp << endl;

    while (true) {
        printMap(map, player);
        cout << "Move (w/a/s/d, q to quit): ";

        char input;
        cin >> input;
        if (input == 'q') {
            break;
        }

        int newRow = player.row;
        int newCol = player.col;

        if (input == 'w') newRow--;
        else if (input == 's') newRow++;
        else if (input == 'a') newCol--;
        else if (input == 'd') newCol++;

        if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) {
            cout << "Out of bounds!" << endl;
            continue;
        }

        if (map[newRow][newCol] == '#') {
            cout << "Wall!" << endl;
            continue;
        }

        player.row = newRow;
        player.col = newCol;

        if (map[player.row][player.col] == 'M') {
            fight(player, monster);
            if (player.hp <= 0) {
                cout << "You were defeated." << endl;
                break;
            }
            map[player.row][player.col] = '.';
        }

        if (map[player.row][player.col] == 'T') {
            printMap(map, player);
            cout << player.name << " found the treasure!" << endl;
            break;
        }
    }

    return 0;
}
