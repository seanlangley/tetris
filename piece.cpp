#include "piece.h"

Piece::Piece() 
    :m_x(3), m_y(0), m_PieceType(L) {
    std::string TheString[] = {
        " #  ",
        " #  ",
        " #  ",
        " #  ",
    };
    m_structure.assign(TheString, TheString+4);
}