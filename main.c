#include <stdio.h>
#include "board.h"
#include "piece.h"

int main() {
    // Create a new board
    struct Board chessboard = createBoard();
    
    // Print the filled board
    printBoard(chessboard);

    // Create and Print white pawn
    printf("%s", "\n\n");

    struct Piece blackPawn = createPiece(100, "\xE2\x99\x99");
    struct Piece whitePawn = createPiece(100, "\xE2\x99\x9F");
    printPiece(whitePawn);
    printf("%s", "\n\n");

    printPiece(blackPawn);
    printf("%s", "\n\n");

    fillBoard(chessboard);
    printBoard(chessboard);    

    return 0;
}
