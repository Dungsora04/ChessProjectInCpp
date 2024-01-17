#include <iostream>
#include "UI.h"

void guide();

void UI::printBoard() const
{
    std::cout << "\t";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "\033[32m" << i + 1 << "\033[0m" << "\t";
    }
    std::cout << "\n\n\n";

    for (int i = 0; i < 8; ++i)
    {
        std::cout << "\033[32m" << i + 1 << "\033[0m" << "\t";
        for (int j = 0; j < 8; ++j)
        {
            ChessPiece* piece = game.gameBoard.getPiece(i, j);
            if (piece != nullptr && !piece->getIsWhite())
            {
                std::cout << "\033[34m";
            }
            if (piece == nullptr)
            {
                std::cout << "." << "\t";
            }
            else if (dynamic_cast<Pawn*>(piece) != nullptr)
            {
                std::cout << "P" << "\t";
            }
            else if (dynamic_cast<Rook*>(piece) != nullptr)
            {
                std::cout << "R" << "\t";
            }
            else if (dynamic_cast<Knight*>(piece) != nullptr)
            {
                std::cout << "N" << "\t";
            }
            else if (dynamic_cast<Bishop*>(piece) != nullptr)
            {
                std::cout << "B" << "\t";
            }
            else if (dynamic_cast<Queen*>(piece) != nullptr)
            {
                std::cout << "Q" << "\t";
            }
            else if (dynamic_cast<King*>(piece) != nullptr)
            {
                std::cout << "K" << "\t";
            }
            if (piece != nullptr && !piece->getIsWhite())
            {
                std::cout << "\033[0m";
            }
        }
        std::cout << "\n\n\n";
    }
}

void UI::run()
{
    while (true)
    {
        system("cls");
        printBoard();

        int startRow, startCol, endRow, endCol;
        std::cout << "Enter two pairs of number (seperate by space)";
        std::cout << "\nEnter " << "\033[32m" << "1 1 1 1" << "\033[0m" << " for game guide";
        std::cout << "\nTo quit, enter " << "\033[32m" << "9 9 9 9" << "\033[0m" << "\n";
        std::cout << "To restart, enter " << "\033[32m" "8 8 8 8" << "\033[0m" << "\n";
        std::cout << "\nYour input: ";
        std::cin >> startRow >> startCol >> endRow >> endCol;


        if (startRow == 9 && startCol == 9 && endRow == 9 && endCol == 9)
        {
            break;
        }
        else if (startRow == 8 && startCol == 8 && endRow == 8 && endCol == 8)
        {
            game.gameBoard.clearBoard();
            game.gameBoard.initializeBoard();
        }
        else if (startRow == 1 && startCol == 1 && endRow == 1 && endCol == 1)
        {
            guide();
        }
        else if (startRow == 50 && startCol == 50 && endRow == 50 && endCol == 50)
        {
            game.gameBoard.clearBoard();
            game.gameBoard.initializeBoard();
            game.makeMove(1, 3, 3, 3); 
            game.makeMove(6, 3, 4, 3);
            game.makeMove(0, 1, 2, 2);
            game.makeMove(7, 6, 5, 5);
            game.makeMove(0, 2, 4, 6);
        }
        else if (startRow == 60 && startCol == 60 && endRow == 60 && endCol == 60)
        {
            game.gameBoard.clearBoard();
            game.gameBoard.initializeBoard();
            game.makeMove(1, 3, 3, 3);
            game.makeMove(6, 3, 4, 3);
            game.makeMove(0, 1, 2, 2);
            game.makeMove(7, 6, 5, 5);
            game.makeMove(0, 2, 3, 5);
            game.makeMove(7, 2, 4, 5);
        }
        else if (startRow == 20 && startCol == 20 && endRow == 20 && endCol == 20)
        {
            game.gameBoard.clearBoard();
            game.gameBoard.queenBoard();
        }
        else if (startRow == 30 && startCol == 30 && endRow == 30 && endCol == 30)
        {
            game.gameBoard.clearBoard();
            game.gameBoard.rookBoard();
        }
        else if (startRow == 40 && startCol == 40 && endRow == 40 && endCol == 40)
        {
            game.gameBoard.clearBoard();
            game.gameBoard.pawnBoard();
        }

        else if (startRow == 1 && startCol == 4 && endRow == 1 && endCol == 2)
        {
            if (!game.castling(1, 1))
            {
                std::cout << "Please try again.\n";
                system("pause");
            }
        }
        else if (startRow == 1 && startCol == 4 && endRow == 1 && endCol == 6)
        {
            if (!game.castling(1, 0))
            {
                std::cout << "Please try again.\n";
                system("pause");
            }
        }
        else if (startRow == 8 && startCol == 4 && endRow == 8 && endCol == 2)
        {
            if (!game.castling(0, 1))
            {
                std::cout << "Please try again.\n";
                system("pause");
            }
        }
        else if (startRow == 8 && startCol == 4 && endRow == 8 && endCol == 6)
        {
            if (!game.castling(0, 0))
            {
                std::cout << "Please try again.\n";
                system("pause");
            }
        }

        else if (game.gameBoard.isPawn(startRow - 1, startCol - 1) && (startRow == 2 || startRow == 7) && endRow > 100)
        {
            int test = endRow;
            if (startRow == 2) endRow = 1;
            if (startRow == 7) endRow = 8;

            char promote = ' ';
            switch (test)
            {
            case 101: promote = 'n'; break;
            case 102: promote = 'b'; break;
            case 103: promote = 'r'; break;
            default: promote = ' ';
            }
            if (!game.makeMove(startRow - 1, startCol - 1, endRow - 1, endCol - 1, promote))
            {
                std::cout << "Please try again.\n";
                system("pause");
            }
        }

        else if (endRow < 1 || endRow > 8 || endCol < 1 || endCol > 8 || startRow < 1 || startRow > 8 || startCol < 1 || startCol > 8)
        {
            std::cout << "Please try again.\n";
            system("pause");
        }

        else if (!game.makeMove(startRow - 1, startCol - 1, endRow - 1, endCol - 1))
        {
            std::cout << "Please try again.\n";
            system("pause");
        }

        system("cls");
        printBoard();

        if (game.isCheckmate(true))
        {
            std::cout << "\nCHECKMATE! Black win.\n\n";
            system("pause");
        }
        if (game.isCheckmate(false))
        {
            std::cout << "\nCHECKMATE! White win.\n\n";
            system("pause");
        }
        if (game.isStalemate(true) || game.isStalemate(false))
        {
            std::cout << "\nSTALEMATE!\n\n";
            system("pause");
        }
    }
}