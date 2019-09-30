#include <ncurses.h>
#include "game.h"

Game::Game(int max_y, int max_x)
    :CURSES_MAX_Y(max_y), CURSES_MAX_X(max_x), m_well(max_y / 4, max_x / 4) {
    srand(time(NULL));
    noecho();
    cbreak();
    timeout(100);
    DEBUG.first = CURSES_MAX_Y - 10;
    DEBUG.second = CURSES_MAX_X - 30;
    m_well.DrawWell(CURSES_MAX_X/4, CURSES_MAX_Y/4);
    PrintDebugMessage();
    refresh();
}

void Game::Update() {
    clear();
    m_well.UpdatePieceCoords();
    m_well.DrawWell(CURSES_MAX_X/4, CURSES_MAX_Y/4);
    PrintDebugMessage();
    refresh();
}

void Game::PrintDebugMessage() {
    mvprintw(DEBUG.first, DEBUG.second, "Welcome to tetris!");
    mvprintw(DEBUG.first+1, DEBUG.second, "Press q to quit.");
}