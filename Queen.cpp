#include <cmath>
#include "Queen.h"

Queen::Queen(bool isWhite)
    :ChessPiece(isWhite)
{
}

bool Queen::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* destinationPiece)
{
    if (endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7)
    {
        return false;
    }
    if (startRow == endRow || startCol == endCol || (std::abs(startRow - endRow) == std::abs(startCol - endCol)))
    {
        return true;
    }
    return false;
}