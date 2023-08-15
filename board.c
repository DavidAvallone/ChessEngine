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
                board.chessboard[row][col] = createPiece(0, "\xE2\x96\xA1", true, 's');
            else
                board.chessboard[row][col] = createPiece(0, "\xE2\x96\xA0", false, 's');
        }
    }
    int Pieces[8] = {3, 1, 2, 4, 5, 2, 1, 3};
    int Pawns[8] = {0, 0, 0, 0, 0, 0, 0, 0};    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
	    if (row == 0)
                board.chessboard[row][col] = pieceLookup(Pieces[col], false);
            else if (row == 1)
                board.chessboard[row][col] = pieceLookup(Pawns[col], false);
            else if (row == 6)
                board.chessboard[row][col] = pieceLookup(Pawns[col], true);
            else if (row == 7)
                board.chessboard[row][col] = pieceLookup(Pieces[col], true);
        }
    }
    return board;
}

void printBoard(struct Board board) {
	for (int row = 0; row < SIZE; row++) {
        	for (int col = 0; col < SIZE; col++) {
            	printf("%s ", board.chessboard[row][col].display);
        }
        printf("\n");
    }
}

void printFEN(struct Board board) {
    char pieceSymbols[] = "PNBRQKpnbrqk";
    char fen[71];
    int fenIndex = 0;

    for (int row = 0; row < SIZE; row++) {
        int emptyCount = 0;

        for (int col = 0; col < SIZE; col++) {
            struct Piece piece = board.chessboard[row][col];

            if (piece.type == 's') {  // Check for empty square
                emptyCount++;
            } else {
                if (emptyCount > 0) {
                    fen[fenIndex++] = '0' + emptyCount;
                    emptyCount = 0;
                }
                fen[fenIndex++] = piece.white ? pieceSymbols[(int)(piece.type - 'P')] : pieceSymbols[(int)(piece.type - 'P') + 6];
            }
        }

        if (emptyCount > 0) {
            fen[fenIndex++] = '0' + emptyCount;
        }

        if (row < SIZE - 1) {
            fen[fenIndex++] = '/';
        }
    }

    fen[fenIndex] = '\0';

    printf("FEN: %s\n", fen);
}
