#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
	Queen(bool);
	bool isValidMove(int, int, int, int, ChessPiece*) override;
};

#endif // !QUEEN_H
