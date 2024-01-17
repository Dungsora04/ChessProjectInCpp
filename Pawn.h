#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece
{
public:
	Pawn(bool);
	bool isValidMove(int, int, int, int, ChessPiece*) override;
};

#endif // !PAWN_H
