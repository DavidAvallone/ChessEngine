#include <stdio.h>
#include "board.h"
#include "piece.h"

int main() {
    // Create a new board
    struct Board chessboard = createBoard();
 
    fillBoard(chessboard);

    printBoard(chessboard);    

    return 0;
}
