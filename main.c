#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int selected = 0;

char *songs[] = {
    "/home/karam/Music/7Weeks"
};

int main(void) {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    clear();
    refresh();
menu:
    printw("Add Music\n[q]uit\nPlay Music\n1 = Add Music, q = [q]uit, 2 = Play Music");
    refresh();
    while(1) {
        int ch = getch();
        if (ch == 'q') {
            clear();
            refresh();
            printw("Add Music\n");
            attron(A_REVERSE);
            printw("[q]uit\n");
            attroff(A_REVERSE);
            printw("Play Music\n1 = Add Music, q = [q]uit, 2 = Play Music");
            refresh();
            selected = 2;
        } else if (ch == '1') {
            clear();
            refresh();
            selected = 1;
            attron(A_REVERSE);
            printw("Add Music\n");
            attroff(A_REVERSE);
            printw("[q]uit\nPlay Music\n1 = Add Music, q = [q]uit, 2 = Play Music");
            refresh();
        } else if (ch == '2') {
            clear();
            refresh();
            selected = 3;
            printw("Add Music\n[q]uit\n");
            attron(A_REVERSE);
            printw("Play Music\n");
            attroff(A_REVERSE);
            printw("1 = Add Music, q = [q]uit, 2 = Play Music");
            refresh();
        }
        else if (ch == '\n') {
            if (selected == 1) {
                clear();
                refresh();
                printw("To add a Song, please change the TTMP source code and recompile it.\nThis shouldn't take long since TTMP is very minimal.\nTo continue, please press any key.");
                refresh();
                getch();
                selected = 0;
                clear();
                refresh();
                goto menu;
            } else if (selected == 2) {
                endwin();
                return 0;
            }
            else {
                clear();
                
                refresh();
                endwin();
                return 0;
            }
        }
    }
}
