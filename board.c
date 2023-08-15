#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "piece.h"


const int SIZE = 8;

struct Board createBoard() {
    struct Board board;
    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if ((row + col) % 2 != 0)
                board.chessboard[row][col] = createPiece(0, "\xE2\x96\xA1");
            else
                board.chessboard[row][col] = createPiece(0, "\xE2\x96\xA0");
        }
    }
    
    return board;
}

void fillBoard(struct Board *board) {
    int Pieces[8] = {3, 1, 2, 4, 5, 2, 1, 3};
    int Pawns[8] = {0, 0, 0, 0, 0, 0, 0, 0};    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
	    if (row == 0)
                board->chessboard[row][col] = pieceLookup(Pieces[col], false);
            else if (row == 1)
                board->chessboard[row][col] = pieceLookup(Pawns[col], false);
            else if (row == 6)
                board->chessboard[row][col] = pieceLookup(Pawns[col], true);
            else if (row == 7)
                board->chessboard[row][col] = pieceLookup(Pieces[col], true);
        }
    }
}

void printBoard(struct Board board) {
	for (int row = 0; row < SIZE; row++) {
        	for (int col = 0; col < SIZE; col++) {
            	printf("%s ", board.chessboard[row][col].display);
        }
        printf("\n");
    }
}
