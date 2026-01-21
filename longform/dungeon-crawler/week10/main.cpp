/*
 * Week 10: ncurses UI with a small template helper.
 */

#include "game.h"

#include <ncurses.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

static int countItems(const Game& game) {
    int count = 0;
    Item* current = game.inventory;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

static void drawStatus(const Game& game, const char* message, int row) {
    move(row, 0);
    clrtoeol();
    mvprintw(row, 0, "HP: %d  Monsters: %d  Items: %d",
             game.player.hp, game.monsterCount, countItems(game));

    move(row + 1, 0);
    clrtoeol();
    if (message) {
        mvprintw(row + 1, 0, "%s", message);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Game game = {};

    if (!loadMap(game, "map.txt")) {
        fprintf(stderr, "Could not read map.txt\n");
        return 1;
    }

    initSkills(game);
    findStart(game);
    loadMonsters(game);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    bool loaded = false;
    mvprintw(0, 0, "Load save? (y/n): ");
    refresh();
    int ch = getch();
    if ((ch == 'y' || ch == 'Y') && loadGame(game, "save.txt")) {
        loaded = true;
    }

    if (!loaded) {
        mvprintw(1, 0, "Enter your name: ");
        echo();
        getnstr(game.player.name, 39);
        noecho();
        game.player.hp = 25;
        findStart(game);
    }

    reveal(game, game.player.row, game.player.col);

    const int statusRow = 0;
    const int mapTop = 3;
    const int mapLeft = 0;
    bool running = true;
    bool won = false;
    bool lost = false;
    const char* message = "WASD/arrow keys move, q quit, v save, i inventory, u use";

    while (running) {
        clear();
        drawStatus(game, message, statusRow);
        printMap(game, mapTop, mapLeft);
        mvprintw(mapTop + game.rows + 1, 0, "WASD/arrow keys move, q quit, v save, i inventory, u use");
        refresh();

        int input = getch();
        int newRow = game.player.row;
        int newCol = game.player.col;
        bool moved = false;

        if (input == 'q' || input == 'Q') {
            running = false;
            message = "Goodbye.";
            break;
        } else if (input == 'v' || input == 'V') {
            if (saveGame(game, "save.txt")) {
                message = "Game saved.";
            } else {
                message = "Save failed.";
            }
            continue;
        } else if (input == 'i' || input == 'I') {
            clear();
            printInventory(game, 0, 0);
            int itemCount = countItems(game);
            int pauseRow = (itemCount > 0) ? itemCount + 1 : 1;
            mvprintw(pauseRow + 1, 0, "Press any key to return.");
            refresh();
            getch();
            message = "Inventory checked.";
            continue;
        } else if (input == 'u' || input == 'U') {
            if (useItem(game)) {
                message = "Used an item.";
            } else {
                message = "No items to use.";
            }
            continue;
        } else if (input == 'w' || input == 'W' || input == KEY_UP) {
            newRow--;
            moved = true;
        } else if (input == 's' || input == 'S' || input == KEY_DOWN) {
            newRow++;
            moved = true;
        } else if (input == 'a' || input == 'A' || input == KEY_LEFT) {
            newCol--;
            moved = true;
        } else if (input == 'd' || input == 'D' || input == KEY_RIGHT) {
            newCol++;
            moved = true;
        } else {
            message = "Use WASD or arrow keys.";
            continue;
        }

        if (!moved) {
            continue;
        }

        if (newRow < 0 || newRow >= game.rows || newCol < 0 || newCol >= game.cols) {
            message = "Out of bounds.";
            continue;
        }

        if (game.map[newRow][newCol] == '#') {
            message = "Wall.";
            continue;
        }

        game.player.row = newRow;
        game.player.col = newCol;
        reveal(game, game.player.row, game.player.col);
        message = "";

        int monsterIndex = monsterIndexAt(game, game.player.row, game.player.col);
        if (monsterIndex != -1) {
            fight(game, monsterIndex);
            if (game.player.hp <= 0) {
                lost = true;
                running = false;
                continue;
            }

            if (game.monsters[monsterIndex].hp <= 0) {
                game.map[game.player.row][game.player.col] = '.';
                removeMonster(game, monsterIndex);
                message = "Monster defeated.";
            }
        }

        if (game.map[game.player.row][game.player.col] == 'L') {
            grantLoot(game);
            game.map[game.player.row][game.player.col] = '.';
            message = "Loot added to inventory.";
        }

        if (game.map[game.player.row][game.player.col] == 'T') {
            won = true;
            running = false;
        }
    }

    clear();
    if (won) {
        mvprintw(0, 0, "%s found the treasure!", game.player.name);
    } else if (lost) {
        mvprintw(0, 0, "%s was defeated.", game.player.name);
    } else {
        mvprintw(0, 0, "Thanks for playing.");
    }
    mvprintw(1, 0, "Press any key to exit.");
    refresh();
    getch();

    endwin();
    clearGame(game);
    return 0;
}
