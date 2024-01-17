#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
	Rook(bool);
	bool isValidMove(int, int, int, int, ChessPiece*) override;
};

#endif // !ROOK_H

