#include "game.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

static const int LOOT_COUNT = 4;
static const char* LOOT_NAMES[LOOT_COUNT] = {"Potion", "Dagger", "Charm", "Elixir"};
static const int LOOT_POWER[LOOT_COUNT] = {6, 3, 2, 10};

static void allocateMap(Game& game, int rows, int cols) {
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
}

static void clearMap(Game& game) {
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

void clearInventory(Game& game) {
    while (game.inventory) {
        Item* current = game.inventory;
        game.inventory = game.inventory->next;
        delete current;
    }
    game.inventory = nullptr;
}

void clearGame(Game& game) {
    clearMap(game);

    delete[] game.monsters;
    game.monsters = nullptr;
    game.monsterCount = 0;

    clearInventory(game);
    game.lootFound = 0;
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

    clearGame(game);
    allocateMap(game, rows, cols);

    for (int r = 0; r < rows; r++) {
        string line;
        getline(inFile, line);
        if (static_cast<int>(line.length()) < cols) {
            clearGame(game);
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

void loadMonsters(Game& game) {
    delete[] game.monsters;
    game.monsters = nullptr;
    game.monsterCount = 0;

    for (int r = 0; r < game.rows; r++) {
        for (int c = 0; c < game.cols; c++) {
            if (game.map[r][c] == 'M') {
                game.monsterCount++;
            }
        }
    }

    if (game.monsterCount == 0) {
        return;
    }

    game.monsters = new Monster[game.monsterCount];
    int index = 0;
    for (int r = 0; r < game.rows; r++) {
        for (int c = 0; c < game.cols; c++) {
            if (game.map[r][c] == 'M') {
                game.monsters[index].row = r;
                game.monsters[index].col = c;
                game.monsters[index].hp = 12;
                game.monsters[index].attack = 3;
                index++;
            }
        }
    }
}

int monsterIndexAt(const Game& game, int r, int c) {
    for (int i = 0; i < game.monsterCount; i++) {
        if (game.monsters[i].row == r && game.monsters[i].col == c) {
            return i;
        }
    }
    return -1;
}

void removeMonster(Game& game, int index) {
    if (index < 0 || index >= game.monsterCount) {
        return;
    }

    int newCount = game.monsterCount - 1;
    if (newCount == 0) {
        delete[] game.monsters;
        game.monsters = nullptr;
        game.monsterCount = 0;
        return;
    }

    Monster* fresh = new Monster[newCount];
    int out = 0;
    for (int i = 0; i < game.monsterCount; i++) {
        if (i == index) {
            continue;
        }
        fresh[out++] = game.monsters[i];
    }

    delete[] game.monsters;
    game.monsters = fresh;
    game.monsterCount = newCount;
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

void fight(Game& game, int monsterIndex) {
    cout << "A monster appears!" << endl;

    Monster& monster = game.monsters[monsterIndex];

    while (game.player.hp > 0 && monster.hp > 0) {
        cout << "HP: " << game.player.hp << " | Monster: " << monster.hp << endl;
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
        monster.hp -= damage;
        cout << game.skills[choice - 1].name << " hits for " << damage << "." << endl;

        if (monster.hp <= 0) {
            cout << "Monster defeated!" << endl;
            return;
        }

        game.player.hp -= monster.attack;
        cout << "Monster hits for " << monster.attack << "." << endl;
    }
}

void addItem(Game& game, const char* name, int power) {
    Item* item = new Item;
    strncpy(item->name, name, sizeof(item->name) - 1);
    item->name[sizeof(item->name) - 1] = '\0';
    item->power = power;
    item->next = game.inventory;
    game.inventory = item;
}

void grantLoot(Game& game) {
    int index = game.lootFound % LOOT_COUNT;
    addItem(game, LOOT_NAMES[index], LOOT_POWER[index]);
    game.lootFound++;
}

bool useItem(Game& game) {
    if (!game.inventory) {
        return false;
    }

    Item* item = game.inventory;
    game.inventory = item->next;
    game.player.hp += item->power;
    cout << "Used " << item->name << ", +" << item->power << " HP." << endl;
    delete item;
    return true;
}

void printInventory(const Game& game) {
    if (!game.inventory) {
        cout << "Inventory empty." << endl;
        return;
    }

    cout << "Inventory:" << endl;
    int index = 1;
    Item* current = game.inventory;
    while (current) {
        cout << index << ". " << current->name << " (" << current->power << ")" << endl;
        current = current->next;
        index++;
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
