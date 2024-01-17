#include <algorithm>
#include "Game.h"

Game::Game()
{
    gameBoard.initializeBoard();
}

bool Game::makeMove(int startRow, int startCol, int endRow, int endCol)
{
    return makeMove(startRow, startCol, endRow, endCol, 'q');
}

bool Game::makeMove(int startRow, int startCol, int endRow, int endCol, char promotionPiece)
{
    ChessPiece* startPiece = gameBoard.board[startRow][startCol];
    ChessPiece* destinationPiece = gameBoard.board[endRow][endCol];

    if (startPiece != nullptr && dynamic_cast<King*>(destinationPiece) == nullptr &&    //King can't be captured
        startPiece->isValidMove(startRow, startCol, endRow, endCol, destinationPiece) &&
        (dynamic_cast<Knight*>(startPiece) != nullptr || gameBoard.isPathClear(startRow, startCol, endRow, endCol)))
    {
        if (destinationPiece != nullptr &&
            destinationPiece->getIsWhite() == startPiece->getIsWhite())
        {
            return false;
        }

        gameBoard.board[endRow][endCol] = startPiece;
        gameBoard.board[startRow][startCol] = nullptr;


        if (isInCheck(startPiece->getIsWhite()))
        {
            gameBoard.board[startRow][startCol] = startPiece;
            gameBoard.board[endRow][endCol] = destinationPiece;
            return false;
        }

        if (dynamic_cast<Pawn*>(gameBoard.board[endRow][endCol]) != nullptr && (endRow == 0 || endRow == 7))
        {
            ChessPiece* temp = gameBoard.board[endRow][endCol];
            switch (promotionPiece)
            {
            case 'q': gameBoard.board[endRow][endCol] = new Queen(gameBoard.board[endRow][endCol]->getIsWhite());  delete temp;  break;
            case 'r': gameBoard.board[endRow][endCol] = new Rook(gameBoard.board[endRow][endCol]->getIsWhite()); delete temp; break;
            case 'b': gameBoard.board[endRow][endCol] = new Bishop(gameBoard.board[endRow][endCol]->getIsWhite()); delete temp;  break;
            case 'n': gameBoard.board[endRow][endCol] = new Knight(gameBoard.board[endRow][endCol]->getIsWhite()); delete temp; break;
            default: gameBoard.board[startRow][startCol] = temp;  gameBoard.board[endRow][endCol] = destinationPiece; return false;
            }
        }

        if (destinationPiece != nullptr) delete destinationPiece;
        startPiece->setHasMoved();

        return true;
    }
    else
    {
        return false;
    }
}

bool Game::hasValidMove(bool isWhite)
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            ChessPiece* piece = gameBoard.board[i][j];
            if (piece != nullptr && piece->getIsWhite() == isWhite)
            {
                for (int k = 0; k < 8; ++k)
                {
                    for (int l = 0; l < 8; ++l)
                    {
                        if (piece->isValidMove(i, j, k, l, gameBoard.board[k][l]) && 
                            (dynamic_cast<Knight*>(piece) != nullptr || gameBoard.isPathClear(i, j, k, l)) &&
                            (gameBoard.board[k][l] == nullptr || gameBoard.board[k][l]->getIsWhite() != isWhite))
                        {
                            ChessPiece* temp = gameBoard.board[k][l];
                            gameBoard.board[k][l] = piece;
                            gameBoard.board[i][j] = nullptr;
                            bool check = isInCheck(isWhite);

                            gameBoard.board[i][j] = piece;
                            gameBoard.board[k][l] = temp;

                            if (!check)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Game::isInCheck(bool isWhite) const
{
    int kingRow, kingCol;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            ChessPiece* piece = gameBoard.board[i][j];
            if (piece != nullptr && piece->getIsWhite() == isWhite && dynamic_cast<King*>(piece) != nullptr)
            {
                kingRow = i;
                kingCol = j;
                break;
            }
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            ChessPiece* piece = gameBoard.board[i][j];
            if (piece != nullptr && piece->getIsWhite() != isWhite &&
                piece->isValidMove(i, j, kingRow, kingCol, gameBoard.board[kingRow][kingCol]) &&
                (dynamic_cast<Knight*>(piece) != nullptr || gameBoard.isPathClear(i, j, kingRow, kingCol)))
            {
                return true;
            }
        }
    }
    return false;
}

bool Game::isCheckmate(bool isWhite)
{
    return (isInCheck(isWhite) && !hasValidMove(isWhite));
}

bool Game::isStalemate(bool isWhite)
{
    return (!isInCheck(isWhite) && !hasValidMove(isWhite));
}

bool Game::castling(bool isWhite, bool isKingSide)
{
    int row = isWhite ? 0 : 7;
    int kingCol = 3;
    int rookCol = isKingSide ? 0 : 7;
    int newKingCol = isKingSide ? 1 : 5;
    int newRookCol = isKingSide ? 2 : 4;

    ChessPiece* king = gameBoard.board[row][kingCol];
    ChessPiece* rook = gameBoard.board[row][rookCol];

    if (king == nullptr || rook == nullptr)
    {
        return false;   // empty squares
    }

    if (!dynamic_cast<King*>(king) || !dynamic_cast<Rook*>(rook))
    {
        return false;   //king or rook isn't at their starting position
    }

    if (king->getIsWhite() != isWhite || rook->getIsWhite() != isWhite)
    {
        return false;   //it's not their own pieces
    }

    if (king->getHasMoved() || rook->getHasMoved())
    {
        return false;   //it's not their first move
    }

    for (int i = std::min(kingCol, rookCol) + 1; i < std::max(kingCol, rookCol); ++i)
    {
        if (gameBoard.board[row][i] != nullptr)
        {
            return false;   //there're piece(s) in the way
        }
    }

    if (kingCol < rookCol)
    {
        for (int i = kingCol; i <= newKingCol; ++i)  
        {
            gameBoard.board[row][kingCol] = nullptr; 
            gameBoard.board[row][i] = king; 
            if (isInCheck(isWhite))
            {
                gameBoard.board[row][i] = nullptr;
                gameBoard.board[row][kingCol] = king; 
                return false;   //the king is passing through check (queenside)
            }
            gameBoard.board[row][i] = nullptr; 
            gameBoard.board[row][kingCol] = king; 
        }
    }
    else
    {
        for (int i = kingCol; i >= newKingCol; --i)
        {
            gameBoard.board[row][kingCol] = nullptr;
            gameBoard.board[row][i] = king;
            if (isInCheck(isWhite))
            {
                gameBoard.board[row][i] = nullptr;
                gameBoard.board[row][kingCol] = king;
                return false;   //the king is passing through check (kingside)
            }
            gameBoard.board[row][i] = nullptr;
            gameBoard.board[row][kingCol] = king;
        }
    }

    //Castling is valid
    gameBoard.board[row][kingCol] = nullptr;
    gameBoard.board[row][newKingCol] = king;
    gameBoard.board[row][rookCol] = nullptr;
    gameBoard.board[row][newRookCol] = rook;

    return true;
}