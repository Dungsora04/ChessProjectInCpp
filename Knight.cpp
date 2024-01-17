#include <cmath>
#include "Knight.h"

Knight::Knight(bool isWhite)
    :ChessPiece(isWhite)
{
}

bool Knight::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* destinationPiece)
{
    if (endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7)
    {
        return false;
    }
    if ((std::abs(startRow - endRow) == 2 && std::abs(startCol - endCol) == 1) ||
        (std::abs(startRow - endRow) == 1 && std::abs(startCol - endCol) == 2))
    {
        return true;
    }
    return false;
}