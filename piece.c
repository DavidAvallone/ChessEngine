#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "piece.h"

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
			return createPiece(100, "\xE2\x99\x9F");
		// p = 1 knight 
		else if (p == 1)
			return createPiece(300, "\xE2\x99\x9E");
		// p = 2 bishop
		else if (p == 2)
			return createPiece(300, "\xE2\x99\x9D");
		// p = 3 rook
		else if (p == 3)
			return createPiece(500, "\xE2\x99\x9C");
		// p = 4 queen
		else if (p == 4)
			return createPiece(900, "\xE2\x99\x9B");
		// p = 5 king
		else if (p == 5)
			return createPiece(1500, "\xE2\x99\x9A");

	}
	// color == false blacik
	else {
		// p = 0 pawn		
		if (p == 0)
			return createPiece(100, "\xE2\x99\x99");
		// p = 1 knight
		else if (p == 1)
			return createPiece(300, "\xE2\x99\x98");
		// p = 2 bishop
		else if (p == 1)
			return createPiece(300, "\xE2\x99\x97");
		// p = 3 rook
		else if (p == 3)
			return createPiece(500, "\xE2\x99\x96");
		// p = 4 queen
		else if (p == 4)
			return createPiece(900, "\xE2\x99\x95");
		// p = 5 king
		else if (p == 5)
			return createPiece(1500, "\xE2\x99\x94");
	}
}
