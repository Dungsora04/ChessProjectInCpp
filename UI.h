#ifndef UI_H
#define UI_H

#include "Game.h"

class UI
{
public:
	Game game;
	void printBoard() const;
	void run();
};

#endif // !UI_H


