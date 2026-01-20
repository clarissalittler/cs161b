/*
 * 01-hello.cpp
 * Minimal ncurses program: init, print, wait, cleanup.
 */

#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();

    printw("Hello, ncurses! Press any key to exit.");
    refresh();
    getch();

    endwin();
    return 0;
}
