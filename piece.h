#ifndef PIECE_H
#define PIECE_H

#include <stdbool.h>
#include "board.h"
#include "moves.h"

struct Piece {
	char type;
	bool white;
	int value;
	const char* display;
	int currentPos[2];
	bool firstMove;
};

struct Piece pieceLookup(int p, bool color, int row, int col);
struct Piece createPiece(int value1, const char *rep, bool color, char type, int row, int col);
void printPiece(struct Piece piece);
struct Board movePiece(struct Piece p, char* move, struct Moves m, struct Board b);

#endif
