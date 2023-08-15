#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "piece.h"

const char * BLACK_SQUARE = "\xE2\x96\xA0";
const char * WHITE_SQUARE = "\xE2\x96\xA1";

const char * WHITE_PAWN = "\xE2\x99\x9F";
const char * BLACK_PAWN = "\xE2\x99\x99";

const char * WHITE_KNIGHT = "\xE2\x99\x9E";
const char * BLACK_KNIGHT = "\xE2\x99\x98";

const char * WHITE_BISHOP = "\xE2\x99\x9D";
const char * BLACK_BISHOP = "\xE2\x99\x97";

const char * WHITE_ROOK = "\xE2\x99\x9C";
const char * BLACK_ROOK = "\xE2\x99\x96";

const char * WHITE_QUEEN = "\xE2\x99\x9B";
const char * BLACK_QUEEN = "\xE2\x99\x95";

const char * WHITE_KING = "\xE2\x99\x9A";
const char * BLACK_KING = "\xE2\x99\x94";


struct Piece createPiece(int value1, const char *rep) {
    struct Piece piece;
    piece.value = value1;
    piece.display = rep;
    return piece;
} 

void printPiece(struct Piece p) {
	printf("%s", p.display);
}

struct Piece pieceLookup(int p, bool color) {
	// color == True white
	if (color) {
		// p = 0 pawn		
		if (p == 0)
			return createPiece(100, WHITE_PAWN);
		// p = 1 knight 
		else if (p == 1)
			return createPiece(300, WHITE_KNIGHT);
		// p = 2 bishop
		else if (p == 2)
			return createPiece(300, WHITE_BISHOP);
		// p = 3 rook
		else if (p == 3)
			return createPiece(500, WHITE_ROOK);
		// p = 4 queen
		else if (p == 4)
			return createPiece(900, WHITE_QUEEN);
		// p = 5 king
		else if (p == 5)
			return createPiece(1500, WHITE_KING);

	}
	// color == false black
	else {
		// p = 0 pawn		
		if (p == 0)
			return createPiece(100, BLACK_PAWN);
		// p = 1 knight
		else if (p == 1)
			return createPiece(300, BLACK_KNIGHT);
		// p = 2 bishop
		else if (p == 2)
			return createPiece(300, BLACK_BISHOP);
		// p = 3 rook
		else if (p == 3)
			return createPiece(500, BLACK_ROOK);
		// p = 4 queen
		else if (p == 4)
			return createPiece(900, BLACK_QUEEN);
		// p = 5 king
		else if (p == 5)
			return createPiece(1500, BLACK_KING);
	}
	return createPiece(0, ""); // Adjust the default values as needed
}
