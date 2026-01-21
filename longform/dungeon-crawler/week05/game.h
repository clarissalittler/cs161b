#ifndef GAME_H
#define GAME_H

const int MAX_ROWS = 20;
const int MAX_COLS = 40;
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
    bool alive;
};

struct Skill {
    const char* name;
    int minDamage;
    int maxDamage;
};

struct Game {
    char map[MAX_ROWS][MAX_COLS];
    bool seen[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
    Player player;
    Monster monster;
    Skill skills[SKILL_COUNT];
};

bool loadMap(Game& game, const char* filename);
void initSkills(Game& game);
void findStart(Game& game);
void findMonster(Game& game);
void reveal(Game& game, int r, int c);
void printMap(const Game& game);
void fight(Game& game);
int rollDamage(const Skill& skill);

bool saveGame(const Game& game, const char* filename);
bool loadGame(Game& game, const char* filename);

#endif
