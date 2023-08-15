#include <stdio.h>
#include "board.h"
#include "piece.h"

int main() {
    	// Create a new board
    	struct Board chessboard = createBoard();
 
    	printBoard(chessboard);

	printf("%s", "\n");

	printFEN(chessboard);

	//for (int row = 0; row < 8; row++) {
        //	for (int col = 0; col < 8; col++) {
//			printf("%c", chessboard.chessboard[row][col].type);
//		}
//	}

	printf("%s", "\n");

	
    	return 0;
}
