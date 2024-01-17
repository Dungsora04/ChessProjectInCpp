#include <iostream>
#include <algorithm>
#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
    //initializeBoard();
}

ChessBoard::~ChessBoard()
{
    clearBoard();
}

void ChessBoard::clearBoard()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; j++)
        {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}

bool ChessBoard::isPawn(int row, int col) const
{
    if (row < 0 || col < 0 || row > 7 || col > 7) return false;
    return (dynamic_cast<Pawn*>(board[row][col]) != nullptr);
}

ChessPiece* ChessBoard::getPiece(int row, int col) const
{
    if (row >= 0 && col >= 0 && row < 8 && col < 8) return board[row][col];
    return nullptr;
}

void ChessBoard::initializeBoard()
{
    board[0][0] = new Rook(true);
    board[0][7] = new Rook(true);
    board[7][0] = new Rook(false);
    board[7][7] = new Rook(false);

    board[0][1] = new Knight(true);
    board[0][6] = new Knight(true);
    board[7][1] = new Knight(false);
    board[7][6] = new Knight(false);

    board[0][2] = new Bishop(true);
    board[0][5] = new Bishop(true);
    board[7][2] = new Bishop(false);
    board[7][5] = new Bishop(false);

    board[0][4] = new Queen(true);
    board[7][4] = new Queen(false);

    board[0][3] = new King(true);
    board[7][3] = new King(false);

    for (int i = 0; i < 8; ++i)
    {
        board[1][i] = new Pawn(true);
        board[6][i] = new Pawn(false);
    }
}

void ChessBoard::queenBoard()
{
    board[2][7] = new King(false);
    board[5][4] = new King(true);
    board[6][5] = new Queen(true);
    board[7][2] = new Pawn(true);

    board[2][7]->setHasMoved();
    board[5][4]->setHasMoved();
    board[6][5]->setHasMoved();
}

void ChessBoard::rookBoard()
{
    board[2][7] = new King(false);
    board[5][4] = new King(true);
    board[6][5] = new Rook(true);

    board[2][7]->setHasMoved();
    board[5][4]->setHasMoved();
    board[6][5]->setHasMoved();
}

void ChessBoard::pawnBoard()
{
    board[5][3] = new King(false);
    board[3][3] = new King(true);
    board[1][3] = new Pawn(true);

    board[5][3]->setHasMoved();
    board[3][3]->setHasMoved();
}

bool ChessBoard::isPathClear(int startRow, int startCol, int endRow, int endCol) const
{
    int directionX = (endRow - startRow > 0) ? 1 : -1;
    int directionY = (endCol - startCol > 0) ? 1 : -1;

    if (startRow == endRow) //horizontally
    {
        for (int i = startCol + directionY; i != endCol; i += directionY)
        {
            if (board[startRow][i] != nullptr)
            {
                return false;
            }
        }
    }
    else if (startCol == endCol) //vertically
    {
        for (int i = startRow + directionX; i != endRow; i += directionX)
        {
            if (board[i][startCol] != nullptr)
            {
                return false;
            }
        }
    }
    else //diagonally
    {
        for (int i = startRow + directionX, j = startCol + directionY; i != endRow; i += directionX, j += directionY)
        {
            if (board[i][j] != nullptr)
            {
                return false;
            }
        }
    }
    return true;
}