#ifndef WELL_H
#define WELL_H

#include <string>
#include <vector>
#include <sstream>
#include "piece.h"
#include "DebugMsg.h"
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
    void PrintPieceData(){
        std::ostringstream str;
        str << "y: " << m_pieces.back().y() << " x: " 
            << m_pieces.back().x() << " &: " << &m_pieces.back();
        if( m_messages.size() == 0 ){
            m_messages.MakeDebugMsg(str.str());
            m_messages.PrintDebugMessages();
        }
        else{
            m_messages.UpdateDebugMsg(0,str.str());
        }

    }
private:
    int m_width;
    int m_height;
    int m_base_x;
    int m_base_y;
    std::vector<std::string> m_structure;
    std::vector<Piece> m_pieces;
    DebugMsgQueue m_messages;

};

#endif