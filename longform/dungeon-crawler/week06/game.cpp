#include "game.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

static bool allocateMap(Game& game, int rows, int cols) {
    game.map = new char*[rows];
    game.seen = new bool*[rows];
    for (int r = 0; r < rows; r++) {
        game.map[r] = new char[cols];
        game.seen[r] = new bool[cols];
        for (int c = 0; c < cols; c++) {
            game.seen[r][c] = false;
        }
    }
    game.rows = rows;
    game.cols = cols;
    return true;
}

void clearMap(Game& game) {
    if (game.map) {
        for (int r = 0; r < game.rows; r++) {
            delete[] game.map[r];
        }
        delete[] game.map;
    }

    if (game.seen) {
        for (int r = 0; r < game.rows; r++) {
            delete[] game.seen[r];
        }
        delete[] game.seen;
    }

    game.map = nullptr;
    game.seen = nullptr;
    game.rows = 0;
    game.cols = 0;
}

bool loadMap(Game& game, const char* filename) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    int rows = 0;
    int cols = 0;
    inFile >> rows >> cols;
    inFile.ignore(1000, '\n');

    if (rows <= 0 || cols <= 0) {
        return false;
    }

    clearMap(game);
    allocateMap(game, rows, cols);

    for (int r = 0; r < rows; r++) {
        string line;
        getline(inFile, line);
        if (static_cast<int>(line.length()) < cols) {
            clearMap(game);
            return false;
        }
        for (int c = 0; c < cols; c++) {
            game.map[r][c] = line[c];
            game.seen[r][c] = false;
        }
    }

    return true;
}

void initSkills(Game& game) {
    game.skills[0] = {"Slash", 3, 6};
    game.skills[1] = {"Heavy Strike", 5, 8};
    game.skills[2] = {"Quick Jab", 2, 4};
}

void findStart(Game& game) {
    game.player.row = 0;
    game.player.col = 0;
    for (int r = 0; r < game.rows; r++) {
        for (int c = 0; c < game.cols; c++) {
            if (game.map[r][c] == 'S') {
                game.player.row = r;
                game.player.col = c;
            }
        }
    }
}

void findMonster(Game& game) {
    game.monster.alive = false;
    for (int r = 0; r < game.rows; r++) {
        for (int c = 0; c < game.cols; c++) {
            if (game.map[r][c] == 'M') {
                game.monster.row = r;
                game.monster.col = c;
                game.monster.hp = 12;
                game.monster.attack = 3;
                game.monster.alive = true;
            }
        }
    }
}

void reveal(Game& game, int r, int c) {
    if (r < 0 || r >= game.rows || c < 0 || c >= game.cols) return;
    if (game.map[r][c] == '#') return;
    if (game.seen[r][c]) return;

    game.seen[r][c] = true;
    reveal(game, r - 1, c);
    reveal(game, r + 1, c);
    reveal(game, r, c - 1);
    reveal(game, r, c + 1);
}

void printMap(const Game& game) {
    for (int r = 0; r < game.rows; r++) {
        for (int c = 0; c < game.cols; c++) {
            if (r == game.player.row && c == game.player.col) {
                cout << '@';
            } else if (game.seen[r][c]) {
                cout << game.map[r][c];
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

void fight(Game& game) {
    cout << "A monster appears!" << endl;

    while (game.player.hp > 0 && game.monster.hp > 0) {
        cout << "HP: " << game.player.hp << " | Monster: " << game.monster.hp << endl;
        cout << "Choose a skill:" << endl;
        for (int i = 0; i < SKILL_COUNT; i++) {
            cout << (i + 1) << ". " << game.skills[i].name << endl;
        }

        int choice;
        cin >> choice;
        if (choice < 1 || choice > SKILL_COUNT) {
            cout << "Invalid choice." << endl;
            continue;
        }

        int damage = rollDamage(game.skills[choice - 1]);
        game.monster.hp -= damage;
        cout << game.skills[choice - 1].name << " hits for " << damage << "." << endl;

        if (game.monster.hp <= 0) {
            cout << "Monster defeated!" << endl;
            game.monster.alive = false;
            return;
        }

        game.player.hp -= game.monster.attack;
        cout << "Monster hits for " << game.monster.attack << "." << endl;
    }
}

bool saveGame(const Game& game, const char* filename) {
    ofstream outFile(filename);
    if (!outFile) {
        return false;
    }

    outFile << game.player.name << '\n';
    outFile << game.player.hp << ' ' << game.player.row << ' ' << game.player.col << '\n';
    return true;
}

bool loadGame(Game& game, const char* filename) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    inFile.getline(game.player.name, 40);
    inFile >> game.player.hp >> game.player.row >> game.player.col;
    return true;
}
