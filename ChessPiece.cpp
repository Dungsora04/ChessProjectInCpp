#include "ChessPiece.h"

ChessPiece::ChessPiece(bool isWhite)
	:isWhite(isWhite), hasMoved(false)
{
}

ChessPiece::~ChessPiece()
{
}

void ChessPiece::setHasMoved()
{
	this->hasMoved = true;
}

bool ChessPiece::getHasMoved() const
{
	return this->hasMoved;
}

bool ChessPiece::getIsWhite() const
{
	return this->isWhite;
}