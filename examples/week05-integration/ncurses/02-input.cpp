/*
 * 02-input.cpp
 * Reading keys with ncurses.
 */

#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    printw("Press a key (q to quit).\n");
    refresh();

    int ch;
    while ((ch = getch()) != 'q') {
        if (ch == KEY_UP) {
            printw("Up\n");
        } else if (ch == KEY_DOWN) {
            printw("Down\n");
        } else if (ch == KEY_LEFT) {
            printw("Left\n");
        } else if (ch == KEY_RIGHT) {
            printw("Right\n");
        } else {
            printw("Key: %c (code %d)\n", ch, ch);
        }
        refresh();
    }

    endwin();
    return 0;
}
