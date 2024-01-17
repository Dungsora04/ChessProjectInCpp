#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

class ChessBoard
{
private:
	ChessPiece* board[8][8] = {};
public:
	ChessBoard();
	~ChessBoard();
	ChessPiece* getPiece(int, int) const;

	void clearBoard();
	void initializeBoard();
	void queenBoard();
	void rookBoard();
	void pawnBoard();

	bool isPawn(int, int) const;
	bool isPathClear(int, int, int, int) const;

	friend class Game;
};

#endif // !CHESSBOARD_H


