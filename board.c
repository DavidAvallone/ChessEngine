#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "piece.h"
#include <ctype.h>

const int SIZE = 8;

//This is the struct for the board class it creates an 8*8 board
//It fills it with the starting postion of a chess game
struct Board createBoard() {
    struct Board board;
    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if ((row + col) % 2 != 0)
                board.chessboard[row][col] = createPiece(0, "\xE2\x96\xA1", true, 's', row, col);
            else
                board.chessboard[row][col] = createPiece(0, "\xE2\x96\xA0", false, 's', row, col);
        }
    }
    int Pieces[8] = {3, 1, 2, 4, 5, 2, 1, 3};
    int Pawns[8] = {0, 0, 0, 0, 0, 0, 0, 0};    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
	    if (row == 0)
                board.chessboard[row][col] = pieceLookup(Pieces[col], false, row, col);
            else if (row == 1)
                board.chessboard[row][col] = pieceLookup(Pawns[col], false, row, col);
            else if (row == 6)
                board.chessboard[row][col] = pieceLookup(Pawns[col], true, row, col);
            else if (row == 7)
                board.chessboard[row][col] = pieceLookup(Pieces[col], true, row, col);
        }
    }
    return board;
}

// This displays the current board state
void printBoard(struct Board board) {
	for (int row = 0; row < SIZE; row++) {
        	for (int col = 0; col < SIZE; col++) {
            	printf("%s ", board.chessboard[row][col].display);
        }
        printf("\n");
    }
}

// This displays the current fen representation of the board
void printFEN(struct Board board) {
    //char pieceSymbols[] = "PNBRQKpnbrqk";
    char fen[71];
    int fenIndex = 0;

    for (int row = 0; row < SIZE; row++) {
        int emptyCount = 0;

        for (int col = 0; col < SIZE; col++) {
            struct Piece piece = board.chessboard[row][col];

            if (piece.type == 's') {  // Check for empty square
                emptyCount++;
            } 
	    else {
                if (emptyCount > 0) {
                    fen[fenIndex++] = '0' + emptyCount;
                    emptyCount = 0;
                }
                fen[fenIndex++] = piece.white ? piece.type : tolower(piece.type);
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

// This is used to make sure the current positions of a piece are correct
void boardDebugger(struct Board board){
	char b = 'b';		
	char w = 'w';
	char color;
	for (int row = 0; row < 8; row++) {
        	for (int col = 0; col < 8; col++) {
			if (board.chessboard[row][col].white)
				color = w;
			else
				color = b;

			printf("%c %c: ", color, board.chessboard[row][col].type);
			printf("%d, %d", board.chessboard[row][col].currentPos[0], board.chessboard[row][col].currentPos[1]);
			printf("%s", "\n");	
		}
	}
}

char* getBoardPosition(struct Board b, int row, int col) {
    struct Piece p = b.chessboard[row][col];
    char c;
    if (p.white)
        c = 'w';
    else
        c = 'b';
    
    char* pos = (char*)malloc(3 * sizeof(char)); // Allocate memory for the string
    
    if (pos == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    
    pos[0] = c;
    pos[1] = p.type;
    pos[2] = '\0';
    
    return pos;
}
