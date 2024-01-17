#include "Rook.h"

Rook::Rook(bool isWhite)
    :ChessPiece(isWhite)
{
}

bool Rook::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* destinationPiece)
{
    if (endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7)
    {
        return false;
    }
    if (startRow == endRow || startCol == endCol)
    {
        return true;
    }
    return false;
}