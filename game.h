#ifndef GAME_H
#define GAME_H

#include "well.h"
#include "DebugMsg.h"
/* Header file for a Tetris game */

class Game {
public:
     Game(int max_y, int max_x);
    ~Game(){};
    void Update();
    int Max_X() {
        return MAX_X;
    }
    int Max_Y() {
        return MAX_Y;
    }
    void GetInput();
    
private:
    int MAX_X;
    int MAX_Y;
    Well m_well;
    DebugMsgQueue m_messages;
};
#endif