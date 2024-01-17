#ifndef GAME_H
#define GAME_H

#include "ChessBoard.h"

class Game
{
public:
	ChessBoard gameBoard;
	Game();
	bool makeMove(int, int, int, int);
	bool makeMove(int, int, int, int, char);

	bool hasValidMove(bool);
	bool isInCheck(bool) const;
	bool isCheckmate(bool);
	bool isStalemate(bool);
	bool castling(bool, bool);
};

#endif // !GAME


