#include <cmath>
#include "Bishop.h"

Bishop::Bishop(bool isWhite)
    :ChessPiece(isWhite)
{
}

bool Bishop::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* destinationPiece)
{
    if (endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7)
    {
        return false;
    }
    if (std::abs(startRow - endRow) == std::abs(startCol - endCol))
    {
        return true;
    }
    return false;
} 