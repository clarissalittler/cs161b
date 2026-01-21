/*
 * Week 07: Dynamic monster arrays and resizing.
 */

#include "game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Game game = {};

    if (!loadMap(game, "map.txt")) {
        cerr << "Could not read map.txt" << endl;
        clearGame(game);
        return 1;
    }

    initSkills(game);
    findStart(game);
    loadMonsters(game);

    cout << "Load save? (y/n): ";
    char choice;
    cin >> choice;
    cin.ignore(1000, '\n');

    if (choice == 'y' && loadGame(game, "save.txt")) {
        cout << "Loaded save for " << game.player.name << "." << endl;
    } else {
        cout << "Enter your name: ";
        cin.getline(game.player.name, 40);
        game.player.hp = 25;
        findStart(game);
    }

    reveal(game, game.player.row, game.player.col);

    while (true) {
        printMap(game);
        cout << "Move (w/a/s/d, q to quit, save: v): ";

        char input;
        cin >> input;
        if (input == 'q') {
            break;
        }

        if (input == 'v') {
            if (saveGame(game, "save.txt")) {
                cout << "Game saved." << endl;
            } else {
                cout << "Save failed." << endl;
            }
            continue;
        }

        int newRow = game.player.row;
        int newCol = game.player.col;

        if (input == 'w') newRow--;
        else if (input == 's') newRow++;
        else if (input == 'a') newCol--;
        else if (input == 'd') newCol++;

        if (newRow < 0 || newRow >= game.rows || newCol < 0 || newCol >= game.cols) {
            cout << "Out of bounds!" << endl;
            continue;
        }

        if (game.map[newRow][newCol] == '#') {
            cout << "Wall!" << endl;
            continue;
        }

        game.player.row = newRow;
        game.player.col = newCol;
        reveal(game, game.player.row, game.player.col);

        int monsterIndex = monsterIndexAt(game, game.player.row, game.player.col);
        if (monsterIndex != -1) {
            fight(game, monsterIndex);
            if (game.player.hp <= 0) {
                cout << "You were defeated." << endl;
                break;
            }

            if (game.monsters[monsterIndex].hp <= 0) {
                game.map[game.player.row][game.player.col] = '.';
                removeMonster(game, monsterIndex);
            }
        }

        if (game.map[game.player.row][game.player.col] == 'T') {
            printMap(game);
            cout << game.player.name << " found the treasure!" << endl;
            break;
        }
    }

    clearGame(game);
    return 0;
}
