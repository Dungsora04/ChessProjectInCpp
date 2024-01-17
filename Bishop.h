#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
	Bishop(bool);
	bool isValidMove(int, int, int, int, ChessPiece*) override;
};

#endif // !BISHOP_H