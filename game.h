#ifndef GAME_H
#define GAME_H

#include "well.h"
/* Header file for a Tetris game */

class Game {
public:
     Game(int max_y, int max_x);
    ~Game(){};
    void Update();
    void PrintDebugMessage();
    int Max_X() {
        return CURSES_MAX_X;
    }
    int Max_Y() {
        return CURSES_MAX_Y;
    }
private:
    int CURSES_MAX_X;
    int CURSES_MAX_Y;
    Well m_well;
    /* y,x */
    std::pair<int, int> DEBUG;
};

#endif