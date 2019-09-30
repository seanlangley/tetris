#pragma once
#include <string>
#include <vector>
#include <array>
typedef enum {
    L, J, I, O, T, S, Z
} piece_types;

class Piece {
public:
    Piece();
    int x() {
        return m_x;
    }
    int y() {
        return m_y;
    }
    std::vector<std::string> *structure() {
        return &m_structure;
    }
    piece_types PieceType() {
        return m_PieceType;
    }
    void MoveDown() {
        ++m_y;
    }
private:
    /* coordinates relative to top left corner of well */
    int m_x;
    int m_y;
    piece_types m_PieceType;
    std::vector<std::string> m_structure;
};

class LPiece : Piece {
public:
    LPiece();
private:
};