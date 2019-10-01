#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include "game.h"

int main(int argc, char **argv) {
    int ch, max_x, max_y;
    initscr();
    getmaxyx(stdscr, max_y, max_x);
    curs_set(0);
    if( argc == 2 && strcmp(argv[1], "-t") == 0 ) {
        notimeout(stdscr, true);
    }
    else{
        timeout(50);
    }
    Game TheGame(max_y, max_x);

    while(1) {
        TheGame.Update();
        if( getch() == 'q' ) 
            break;
    }
    
    endwin();
    return 0;
}
