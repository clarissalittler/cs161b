#ifndef GAME_H
#define GAME_H

const int SKILL_COUNT = 3;

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

struct Item {
    char name[24];
    int power;
    Item* next;
};

struct Game {
    char** map;
    bool** seen;
    int rows;
    int cols;
    Player player;
    Monster* monsters;
    int monsterCount;
    Skill skills[SKILL_COUNT];
    Item* inventory;
    int lootFound;
};

bool loadMap(Game& game, const char* filename);
void clearGame(Game& game);
void initSkills(Game& game);
void findStart(Game& game);
void loadMonsters(Game& game);
int monsterIndexAt(const Game& game, int r, int c);
void removeMonster(Game& game, int index);
void reveal(Game& game, int r, int c);
void printMap(const Game& game);
void fight(Game& game, int monsterIndex);
int rollDamage(const Skill& skill);

void grantLoot(Game& game);
void addItem(Game& game, const char* name, int power);
bool useItem(Game& game);
void printInventory(const Game& game);
void clearInventory(Game& game);

bool saveGame(const Game& game, const char* filename);
bool loadGame(Game& game, const char* filename);

#endif
