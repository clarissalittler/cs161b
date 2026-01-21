/*
 * Week 03: Advanced functions, recursion, and skills.
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 6;
const int COLS = 9;

struct Player {
    char name[40];
    int row;
    int col;
    int hp;
};

struct Monster {
    int row;
    int col;
    int hp;
    int attack;
};

struct Skill {
    const char* name;
    int minDamage;
    int maxDamage;
};

void reveal(const char map[ROWS][COLS], bool seen[ROWS][COLS], int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) return;
    if (map[r][c] == '#') return;
    if (seen[r][c]) return;

    seen[r][c] = true;
    reveal(map, seen, r - 1, c);
    reveal(map, seen, r + 1, c);
    reveal(map, seen, r, c - 1);
    reveal(map, seen, r, c + 1);
}

void printMap(const char map[ROWS][COLS], const bool seen[ROWS][COLS], const Player& player) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (r == player.row && c == player.col) {
                cout << '@';
            } else if (seen[r][c]) {
                cout << map[r][c];
            } else {
                cout << '?';
            }
        }
        cout << endl;
    }
}

int rollDamage(const Skill& skill) {
    int range = skill.maxDamage - skill.minDamage + 1;
    return skill.minDamage + rand() % range;
}

void fight(Player& player, Monster& monster, const Skill skills[], int skillCount) {
    cout << "A monster appears!" << endl;

    while (player.hp > 0 && monster.hp > 0) {
        cout << "HP: " << player.hp << " | Monster: " << monster.hp << endl;
        cout << "Choose a skill:" << endl;
        for (int i = 0; i < skillCount; i++) {
            cout << (i + 1) << ". " << skills[i].name << endl;
        }

        int choice;
        cin >> choice;
        if (choice < 1 || choice > skillCount) {
            cout << "Invalid choice." << endl;
            continue;
        }

        int damage = rollDamage(skills[choice - 1]);
        monster.hp -= damage;
        cout << skills[choice - 1].name << " hits for " << damage << "." << endl;

        if (monster.hp <= 0) {
            cout << "Monster defeated!" << endl;
            return;
        }

        player.hp -= monster.attack;
        cout << "Monster hits for " << monster.attack << "." << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', '.', '.', '#', '.', '.', 'T', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    Player player;
    cout << "Enter your name: ";
    cin.getline(player.name, 40);
    player.row = 1;
    player.col = 1;
    player.hp = 25;

    Monster monster = {3, 1, 14, 3};
    map[monster.row][monster.col] = 'M';

    Skill skills[3] = {
        {"Slash", 3, 6},
        {"Heavy Strike", 5, 8},
        {"Quick Jab", 2, 4}
    };

    bool seen[ROWS][COLS] = {false};
    reveal(map, seen, player.row, player.col);

    while (true) {
        printMap(map, seen, player);
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
        reveal(map, seen, player.row, player.col);

        if (map[player.row][player.col] == 'M') {
            fight(player, monster, skills, 3);
            if (player.hp <= 0) {
                cout << "You were defeated." << endl;
                break;
            }
            map[player.row][player.col] = '.';
        }

        if (map[player.row][player.col] == 'T') {
            printMap(map, seen, player);
            cout << player.name << " found the treasure!" << endl;
            break;
        }
    }

    return 0;
}
