#ifndef CHESSPIECE_H
#define CHESSPIECE_H

class ChessPiece
{
protected:
	bool isWhite;
	bool hasMoved;
public:
	ChessPiece(bool);
	virtual ~ChessPiece();
	bool getIsWhite() const;
	bool getHasMoved() const;
	void setHasMoved();
	virtual bool isValidMove(int, int, int, int, ChessPiece*) = 0;
};

#endif // !CHESSPIECE_H
