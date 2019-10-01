#include <ncurses.h>
#include "game.h"

Game::Game(int max_y, int max_x)
    :MAX_Y(max_y), MAX_X(max_x), m_well(max_y / 4, max_x / 4),
     m_messages(MAX_Y - 10, MAX_X - 30) {
    srand(time(NULL));
    noecho();
    cbreak();
    m_well.DrawWell(0, 10);
    m_messages.MakeDebugMsg("Welcome to Tetris!");
    m_messages.MakeDebugMsg("Press q to quit.");

    m_messages.PrintDebugMessages();
    refresh();
}

void Game::Update() {
    m_well.UpdatePieceCoords();
    m_well.PrintPieceData();
    m_well.DrawWell(0, 10);
    GetInput();
    m_messages.PrintDebugMessages();
    refresh();
}


void Game::GetInput(){
    if( getch() == ' ' ){
        m_messages.MakeDebugMsg("You hit the space bar");
    }
}