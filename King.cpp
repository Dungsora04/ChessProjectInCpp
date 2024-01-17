#include <cmath>
#include "King.h"

King::King(bool isWhite)
    :ChessPiece(isWhite)
{
}

bool King::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* destinationPiece)
{
    if (endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7)
    {
        return false;
    }
    if (std::abs(startRow - endRow) <= 1 && std::abs(startCol - endCol) <= 1)
    {
        return true;
    }
    return false;
}