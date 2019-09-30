#ifndef WELL_H
#define WELL_H

#include <string>
#include <vector>
#include "piece.h"

/* Header file for a Tetris well */
#define WELL_WIDTH 24
#define WELL_HEIGHT 40

class Well {
public:
    Well(int base_y, int base_x);
    ~Well(){};
    void DrawWell(int base_x, int base_y);
    void ResetWell();
    piece_types AddPiece();
    void UpdatePieceCoords();
private:
    int m_width;
    int m_height;
    int m_base_x;
    int m_base_y;
    std::vector<std::string> m_structure;
    std::vector<Piece> m_pieces;
};

#endif