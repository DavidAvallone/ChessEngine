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

const char PAWN = 'P';
const char KNIGHT = 'N';
const char BISHOP = 'B';
const char ROOK = 'R';
const char QUEEN = 'Q';
const char KING = 'K';

const bool BLACK = false;
const bool WHITE = true;

struct Piece createPiece(int value1, const char *rep, bool color, char type, int row, int col) {
    struct Piece piece;
    piece.type = type;
    piece.white = color;
    piece.value = value1;
    piece.display = rep;
    piece.currentPos[0] = row;
    piece.currentPos[1] = col;
    piece.firstMove = true;
    return piece;
} 

void printPiece(struct Piece p) {
	printf("%s", p.display);
}

struct Piece pieceLookup(int p, bool color, int row, int col) {
	// color == True white
	if (color) {
		// p = 0 pawn		
		if (p == 0)
			return createPiece(100, WHITE_PAWN, WHITE, PAWN, row, col);
		// p = 1 knight 
		else if (p == 1)
			return createPiece(300, WHITE_KNIGHT, WHITE, KNIGHT, row, col);
		// p = 2 bishop
		else if (p == 2)
			return createPiece(300, WHITE_BISHOP, WHITE, BISHOP, row, col);
		// p = 3 rook
		else if (p == 3)
			return createPiece(500, WHITE_ROOK, WHITE, ROOK, row, col);
		// p = 4 queen
		else if (p == 4)
			return createPiece(900, WHITE_QUEEN, WHITE, QUEEN, row, col);
		// p = 5 king
		else if (p == 5)
			return createPiece(1500, WHITE_KING, WHITE, KING, row, col);

	}
	// color == false black
	else {
		// p = 0 pawn		
		if (p == 0)
			return createPiece(100, BLACK_PAWN, BLACK, PAWN, row, col);
		// p = 1 knight
		else if (p == 1)
			return createPiece(300, BLACK_KNIGHT, BLACK, KNIGHT, row, col);
		// p = 2 bishop
		else if (p == 2)
			return createPiece(300, BLACK_BISHOP, BLACK, BISHOP, row, col);
		// p = 3 rook
		else if (p == 3)
			return createPiece(500, BLACK_ROOK, BLACK, ROOK, row, col);
		// p = 4 queen
		else if (p == 4)
			return createPiece(900, BLACK_QUEEN, BLACK, QUEEN, row, col);
		// p = 5 king
		else if (p == 5)
			return createPiece(1500, BLACK_KING, BLACK, KING, row, col);
	}
	return createPiece(0, "", NULL, 'X',9,9); // Adjust the default values as needed
}

struct Board movePiece(struct Piece p, char* move, struct Moves m, struct Board b){
	return b;
}
