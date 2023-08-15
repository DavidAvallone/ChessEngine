#ifndef PIECE_H
#define PIECE_H

#include <stdbool.h>

struct Piece {
	int value;
	const char* display;
};

struct Piece pieceLookup(int p, bool color);
struct Piece createPiece(int value1, const char *rep);
void printPiece(struct Piece piece);

#endif
