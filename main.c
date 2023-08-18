#include <stdio.h>
#include "board.h"
#include "piece.h"

int main() {
    	// Create a new board
    	struct Board chessboard = createBoard();
 
    	printBoard(chessboard);

	printf("%s", "\n");

	printFEN(chessboard);
	
	printf("%s", "\n");

	boardDebugger(chessboard);

	
    	return 0;
}
