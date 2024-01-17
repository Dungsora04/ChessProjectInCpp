#include <cmath>
#include "Pawn.h"

Pawn::Pawn(bool isWhite)
    :ChessPiece(isWhite)
{
}

bool Pawn::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* destinationPiece)
{
    if (endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7)
    {
        return false;
    }
    if (isWhite ? (endRow - startRow == 1 || (!getHasMoved() && endRow - startRow == 2)) :
        (startRow - endRow == 1 || (!getHasMoved() && startRow - endRow == 2)))
    {
        if (startCol == endCol && destinationPiece == nullptr)
        {
            return true;
        }
        else if (std::abs(startCol - endCol) == 1 && destinationPiece != nullptr &&
            destinationPiece->getIsWhite() != isWhite) 
        {
            return true;
        }
    }
    return false;
}
