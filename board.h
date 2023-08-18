#ifndef BOARD_H
#define BOARD_H

#include "piece.h" // Include the Piece struct definition
#include "moves.h"

struct Board {
	struct Piece chessboard[8][8];
};

struct Board createBoard();
void printBoard(struct Board board);
void printFEN(struct Board board);
void boardDebugger(struct Board board);
char * getBoardPosition(struct Board board, int row, int col);
#endif
