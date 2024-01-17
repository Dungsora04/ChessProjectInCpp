#include <iostream>
#include <cstdlib>
#include <algorithm>

void guide()
{
	system("cls");

	std::cout << "-------------------------------------------GAME GUIDE----------------------------------------";
	std::cout << "\n\n1. PLAYERS' SIDE";
	std::cout << "\nAt the start, White pieces are placed in row 1 and 2. Black pieces are placed in row 7 and 8";
	std::cout << "\nWhite pawns move from row 2 to 8. Black pawns move from row 7 to 1";
	std::cout << "\n\n\n2. MOVING PIECES";
	std::cout << "\nTo move a piece in the board, enter the row and column of the square the piece is currently in, then enter the row and column of the square it will move to.";
	std::cout << "If the move is not valid (either by violating the chess rule or invalid input), you have to try again.";
	std::cout << "\nExample: White pawn is at square (4,3). Enter " << "\033[32m" << "4 3 4 4" << "\033[0m" << " will move the pawn one step forward if square (4,4) is empty and the move does not leave White king in check.";
	std::cout << "\nKings CANNOT be captured. Kings can only be checked (threaten to be captured in the next move)";
	std::cout << "\n\n\n3. CASTLING";
	std::cout << "\nMove your KING two steps either to kingside or queenside for castling (if it's a valid castling).\n";
	std::cout << "\n\n\n4. PAWN PROMOTION";
	std::cout << "\nWhen the pawn is on its seventh row (row 7 for White and row 2 for Black), it will promote to a higher piece in the next move.";
	std::cout << "\nIf you enter your input normally, it will promote to QUEEN automatically.";
	std::cout << "\nIf you wish to promote pawn to a different piece, when entering the next move for the pawn, instead of typing normally, change the THIRD number (which should  be 1 or 8)";
	std::cout << " to either 101, 102, or 103.";
	std::cout << "\n\tIf it's " << "\033[32m" << "101, " << "\033[0m" << "the pawn will promote to KNIGHT";
	std::cout << "\n\tIf it's " << "\033[32m" << "102, " << "\033[0m" << "the pawn will promote to BISHOP";
	std::cout << "\n\tIf it's " << "\033[32m" << "103, " << "\033[0m" << "the pawn will promote to ROOK";
	std::cout << "\n\n\n5. PATTERNS";
	std::cout << "\nEnter as below for some quick patterns: \n";
	std::cout << "\nSpanish opening: \t\t" << "\033[32m" << "50 50 50 50" << "\033[0m" << "\n";
	std::cout << "Italian opening: \t\t" << "\033[32m" << "60 60 60 60" << "\033[0m" << "\n";
	std::cout << "Queen + King vs King endgame: \t" << "\033[32m" << "20 20 20 20" << "\033[0m" << "\n";
	std::cout << "Rook + King vs King endgame: \t" << "\033[32m" << "30 30 30 30" << "\033[0m" << "\n";
	std::cout << "Pawn + King vs King endgame: \t" << "\033[32m" << "40 40 40 40" << "\033[0m" << "\n\n";

	system("pause");
}