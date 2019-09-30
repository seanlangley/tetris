#include "well.h"
#include <ncurses.h>
#include <cstring>
Well::Well(int base_y, int base_x) 
    :m_width(WELL_WIDTH), m_height(WELL_HEIGHT), m_base_x(base_x), m_base_y(base_y){
    /* Put WELL_HEIGHT strings onto the m_structure vector */
    for( int i = 0; i < WELL_HEIGHT; i++ ) {
        m_structure.push_back("");
    }
    ResetWell();
    AddPiece();
}

void Well::ResetWell() {
    std::string NewString;
    for( int i = 0; i < WELL_HEIGHT; i++ ) {
        NewString = "#";
        for( int j = 0; j < WELL_WIDTH - 2; j++ ) {
            NewString.push_back(' ');
        }
        NewString.push_back('#');
        m_structure[i] = NewString;
    }
    NewString = "";
    for( int i = 0; i < WELL_WIDTH; i++ ) {
        NewString.push_back('#');
    }
    m_structure.back() = NewString;
}

/* base_x and y are the top left coordinates of the well */
void Well::DrawWell(int base_x, int base_y) {
    std::vector<Piece>::iterator CurrPiece = m_pieces.begin();

    ResetWell();
    for(; CurrPiece != m_pieces.end(); CurrPiece++ ) {
        std::vector<std::string> *CurrPieceStructure = CurrPiece->structure();
        /* Pieces guaranteed to be a 4x4 array */
        for( int y = 0; y < 4; y++ ) {
            for( int x = 0; x < 4; x++ ) {
                m_structure[CurrPiece->y() + y][CurrPiece->x()+ x] = 
                            (*CurrPieceStructure)[y][x];
            }
        }
    }

    std::vector<std::string>::iterator well_it = m_structure.begin();
    for(int i = 0; well_it != m_structure.end(); well_it++, i++ ) {
        mvprintw(base_y + i, base_x, "%s", well_it->c_str());
    }
}

piece_types Well::AddPiece() {
    Piece NewPiece;
    m_pieces.push_back(NewPiece);
    return L;
}

void Well::UpdatePieceCoords() {
    std::vector<Piece>::iterator PieceIterator = m_pieces.begin();
    for(; PieceIterator != m_pieces.end(); PieceIterator++ ) {
        if( PieceIterator->y() < WELL_HEIGHT - 5 )
            PieceIterator->MoveDown();
    }
}