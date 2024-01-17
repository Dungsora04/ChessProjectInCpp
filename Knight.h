#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"

class Knight : public ChessPiece
{
public:
	Knight(bool);
	bool isValidMove(int, int, int, int, ChessPiece*) override;
};

#endif // !KNIGHT_H