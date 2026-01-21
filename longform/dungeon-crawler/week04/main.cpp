/*
 * Week 04: File I/O and persistence.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ROWS = 20;
const int MAX_COLS = 40;

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

bool loadMap(const char* filename, char map[MAX_ROWS][MAX_COLS], int& rows, int& cols) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    inFile >> rows >> cols;
    inFile.ignore(1000, '\n');

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        return false;
    }

    for (int r = 0; r < rows; r++) {
        string line;
        getline(inFile, line);
        if (static_cast<int>(line.length()) < cols) {
            return false;
        }
        for (int c = 0; c < cols; c++) {
            map[r][c] = line[c];
        }
    }

    return true;
}

void reveal(const char map[MAX_ROWS][MAX_COLS], bool seen[MAX_ROWS][MAX_COLS], int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return;
    if (map[r][c] == '#') return;
    if (seen[r][c]) return;

    seen[r][c] = true;
    reveal(map, seen, rows, cols, r - 1, c);
    reveal(map, seen, rows, cols, r + 1, c);
    reveal(map, seen, rows, cols, r, c - 1);
    reveal(map, seen, rows, cols, r, c + 1);
}

void printMap(const char map[MAX_ROWS][MAX_COLS], const bool seen[MAX_ROWS][MAX_COLS], int rows, int cols, const Player& player) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
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

bool saveGame(const char* filename, const Player& player) {
    ofstream outFile(filename);
    if (!outFile) {
        return false;
    }

    outFile << player.name << '\n';
    outFile << player.hp << ' ' << player.row << ' ' << player.col << '\n';
    return true;
}

bool loadGame(const char* filename, Player& player) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    inFile.getline(player.name, 40);
    inFile >> player.hp >> player.row >> player.col;
    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    char map[MAX_ROWS][MAX_COLS];
    int rows = 0;
    int cols = 0;

    if (!loadMap("map.txt", map, rows, cols)) {
        cerr << "Could not read map.txt" << endl;
        return 1;
    }

    Player player;
    cout << "Load save? (y/n): ";
    char choice;
    cin >> choice;
    cin.ignore(1000, '\n');

    if (choice == 'y' && loadGame("save.txt", player)) {
        cout << "Loaded save for " << player.name << "." << endl;
    } else {
        cout << "Enter your name: ";
        cin.getline(player.name, 40);
        player.hp = 25;

        player.row = 0;
        player.col = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (map[r][c] == 'S') {
                    player.row = r;
                    player.col = c;
                }
            }
        }
    }

    Monster monster = {0, 0, 12, 3};
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (map[r][c] == 'M') {
                monster.row = r;
                monster.col = c;
            }
        }
    }

    Skill skills[3] = {
        {"Slash", 3, 6},
        {"Heavy Strike", 5, 8},
        {"Quick Jab", 2, 4}
    };

    bool seen[MAX_ROWS][MAX_COLS] = {false};
    reveal(map, seen, rows, cols, player.row, player.col);

    while (true) {
        printMap(map, seen, rows, cols, player);
        cout << "Move (w/a/s/d, q to quit, save: v): ";

        char input;
        cin >> input;
        if (input == 'q') {
            break;
        }

        if (input == 'v') {
            if (saveGame("save.txt", player)) {
                cout << "Game saved." << endl;
            } else {
                cout << "Save failed." << endl;
            }
            continue;
        }

        int newRow = player.row;
        int newCol = player.col;

        if (input == 'w') newRow--;
        else if (input == 's') newRow++;
        else if (input == 'a') newCol--;
        else if (input == 'd') newCol++;

        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
            cout << "Out of bounds!" << endl;
            continue;
        }

        if (map[newRow][newCol] == '#') {
            cout << "Wall!" << endl;
            continue;
        }

        player.row = newRow;
        player.col = newCol;
        reveal(map, seen, rows, cols, player.row, player.col);

        if (map[player.row][player.col] == 'M') {
            fight(player, monster, skills, 3);
            if (player.hp <= 0) {
                cout << "You were defeated." << endl;
                break;
            }
            map[player.row][player.col] = '.';
        }

        if (map[player.row][player.col] == 'T') {
            printMap(map, seen, rows, cols, player);
            cout << player.name << " found the treasure!" << endl;
            break;
        }
    }

    return 0;
}
