#ifndef BOARD_H
#define BOARD_H

#include "piece.h" // Include the Piece struct definition

struct Board {
	struct Piece chessboard[8][8];
};

struct Board createBoard();
void fillBoard();
void printBoard(struct Board board);

#endif
