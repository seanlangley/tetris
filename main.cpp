#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include "game.h"

int main() {
    int ch, max_x, max_y;
    initscr();
    getmaxyx(stdscr, max_y, max_x);
    Game TheGame(max_y, max_x);

    while(1) {
        TheGame.Update();
        if( getch() == 'q' ) 
            break;
        usleep(100);
    }
    
    endwin();
    return 0;
}
