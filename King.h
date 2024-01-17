#ifndef KING_H
#define KING_H

#include "ChessPiece.h"

class King : public ChessPiece
{
public:
	King(bool);
	bool isValidMove(int, int, int, int, ChessPiece*) override;
};

#endif // !KING_H
