/*
 * 03-menu.cpp
 * Simple ncurses menu with arrow keys.
 */

#include <ncurses.h>

int main() {
    const char* options[] = {"Start", "Options", "Quit"};
    const int count = 3;
    int selected = 0;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    while (true) {
        clear();
        printw("Use arrow keys, Enter to select.\n\n");

        for (int i = 0; i < count; i++) {
            if (i == selected) {
                attron(A_REVERSE);
            }
            printw("%s\n", options[i]);
            if (i == selected) {
                attroff(A_REVERSE);
            }
        }

        int ch = getch();
        if (ch == KEY_UP) {
            selected = (selected - 1 + count) % count;
        } else if (ch == KEY_DOWN) {
            selected = (selected + 1) % count;
        } else if (ch == '\n') {
            break;
        }
    }

    printw("You chose: %s\n", options[selected]);
    refresh();
    getch();

    endwin();
    return 0;
}
