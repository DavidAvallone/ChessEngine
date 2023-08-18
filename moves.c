#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "piece.h"
#include "board.h"
#include "moves.h"

const char * FILE_LIST = "abcdefhg";

struct Moves generateMoves(struct Board board) {
	struct Moves legalMoves;
	//int moveCount = 0;
	legalMoves.pawnMoves = pawnMoves(board);
	legalMoves.knightMoves = knightMoves(board);
	legalMoves.bishopMoves = bishopMoves(board);
	legalMoves.rookMoves = rookMoves(board);
	legalMoves.queenMoves = queenMoves(board);
	legalMoves.kingMoves = kingMoves(board);
	legalMoves.check = check(legalMoves);
	return legalMoves;
}

char* pawnMoves(struct Board board){
	int whiteCount;
	int blackCount;
	for (int row = 0; row < 8; row++) {
        	for (int col = 0; col < 8; col++) {
			struct Piece piece = board.chessboard[row][col];
			if (piece.type == 'P' && piece.white)
				whiteCount++;
			else if (piece.type == 'P' && piece.white == false)
				blackCount++;
		}
	}
	struct Piece whitePawns[whiteCount];
	struct Piece blackPawns[blackCount];
	for (int row = 0; row < 8; row++) {
        	for (int col = 0; col < 8; col++) {
			struct Piece piece = board.chessboard[row][col];
			if (piece.type == 'P' && piece.white) {
				whiteCount-=1;
				whitePawns[whiteCount] = piece;
			}	
			else  if (piece.type == 'P' && piece.white == false){
				blackCount-=1;
				blackPawns[blackCount] = piece;
			}

		}
	}
	// now to gather all of the moves for each pawn
	for (int curr = 0; curr < whiteCount; curr++){
		struct Piece piece = whitePawns[curr]; // check if the pawn can move 2 forward		
		if (piece.firstMove){ // if its the pawns first move you have to check 4 positions
			if (piece.currentPos[1] == 0 || piece.currentPos[1] == 7){ //if its in the A file only need to check 3 positions
				// postion 1 2 forward
				char* pos1 = getBoardPosition(board, piece.currentPos[0]-2, piece.currentPos[1]);
				if (pos1[1] == 's') {
					// add move to the list of moves in this case a4
					char move[3]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = piece.currentPos[0] + '1'; // Convert integer to character
					move[2] = '\0'; // Null-terminate the string
					printf("%s", move);
				}

				// postion 2 1 forward
				char* pos2 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]);
				if (pos2[1] == 's'){
					// add move to the list of moves in this case a3
					char move[3]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = piece.currentPos[0] + '1'; // Convert integer to character
					move[2] = '\0'; // Null-terminate the string
					printf("%s", move);
					
				}
				
				if (piece.currentPos[1] == 0){ 
					// postion 3 1 diagonal capture
					char* pos3 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]+1);
					if (pos3[1] != 's' && pos3[0] == 'b'){
						// add capture move to the list of moves in this case axb3
						char move[4]; // Allocate memory for the concatenated string (2 characters + null terminator)

						move[0] = FILE_LIST[piece.currentPos[1]];
						move[1] = 'x';
						move[2] = piece.currentPos[0] + '1'; // Convert integer to character
						move[3] = '\0'; // Null-terminate the string
						printf("%s", move);
						
					}
				}
				else if (piece.currentPos[1] == 7){
					// postion 4 1 diagonal capture
					char* pos4 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]-1);
					if (pos4[1] != 's' && pos4[0] == 'b'){
						// add capture move to the list of moves in this case hxg3
						char move[4]; // Allocate memory for the concatenated string (2 characters + null terminator)

						move[0] = FILE_LIST[piece.currentPos[1]];
						move[1] = 'x';
						move[2] = piece.currentPos[0] + '1'; // Convert integer to character
						move[3] = '\0'; // Null-terminate the string
						printf("%s", move);
						
					}
				}
			}
			else{// you have to check the 4 positions	
				// postion 1 2 forward
				char* pos1 = getBoardPosition(board, piece.currentPos[0]-2, piece.currentPos[1]);
				if (pos1[1] == 's'){
					// add move to the list of moves in this case h4
					char move[3]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = piece.currentPos[0] + '1'; // Convert integer to character
					move[2] = '\0'; // Null-terminate the string
					printf("%s", move);
					
				}

				// postion 2 1 forward
				char* pos2 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]);
				if (pos2[1] == 's') {
					char move[3]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = piece.currentPos[0] + '1'; // Convert integer to character
					move[2] = '\0'; // Null-terminate the string
					printf("%s", move);
					
				}

				// postion 3 1 right diagonal capture
				char* pos3 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]+1);
				if (pos3[1] != 's' && pos3[0] == 'b'){
					char move[3]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = piece.currentPos[0] + '1'; // Convert integer to character
					move[2] = '\0'; // Null-terminate the string
					printf("%s", move);
					
				}

				// postion 3 1 left diagonal capture
				char* pos4 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]-1);
				if (pos4[1] != 's' && pos4[0] == 'b'){
					char move[4]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = 'x';
					move[2] = piece.currentPos[0] + '1'; // Convert integer to character
					move[3] = '\0'; // Null-terminate the string
					printf("%s", move);
					
				}
			}
		}
		else{ // if its the pawns second move you check 3 positions
			if (piece.currentPos[1] == 0 || piece.currentPos[1] == 7){ //if its in the A file only need to check 3 positions
				// postion 1 1 forward
				char* pos2 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]);
				if (pos2[1] == 's'){
					// add move to the list of moves in this case a3
					char move[3]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = piece.currentPos[0] + '1'; // Convert integer to character
					move[2] = '\0'; // Null-terminate the string
					printf("%s", move);
					
				}
				
				if (piece.currentPos[1] == 0){ 
					// postion 3 1 diagonal capture
					char* pos3 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]+1);
					if (pos3[1] != 's' && pos3[0] == 'b'){
						// add capture move to the list of moves in this case axb3
						char move[4]; // Allocate memory for the concatenated string (2 characters + null terminator)

						move[0] = FILE_LIST[piece.currentPos[1]];
						move[1] = 'x';
						move[2] = piece.currentPos[0] + '1'; // Convert integer to character
						move[3] = '\0'; // Null-terminate the string
						printf("%s", move);
						
					}
				}
				else if (piece.currentPos[1] == 7){
					// postion 4 1 diagonal capture
					char* pos4 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]-1);
					if (pos4[1] != 's' && pos4[0] == 'b'){
						// add capture move to the list of moves in this case hxg3
						char move[4]; // Allocate memory for the concatenated string (2 characters + null terminator)

						move[0] = FILE_LIST[piece.currentPos[1]];
						move[1] = 'x';
						move[2] = piece.currentPos[0] + '1'; // Convert integer to character
						move[3] = '\0'; // Null-terminate the string
						printf("%s", move);
						
					}
				}
			}
			else{// you have to check the 3 positions
				// postion 2 1 forward
				char* pos2 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]);
				if (pos2[1] == 's') {
					char move[3]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = piece.currentPos[0] + '1'; // Convert integer to character
					move[2] = '\0'; // Null-terminate the string
					printf("%s", move);
					
				}

				// postion 3 1 right diagonal capture
				char* pos3 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]+1);
				if (pos3[1] != 's' && pos3[0] == 'b'){
					char move[3]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = piece.currentPos[0] + '1'; // Convert integer to character
					move[2] = '\0'; // Null-terminate the string
					printf("%s", move);					
				}
				
				// postion 3 1 left diagonal capture
				char* pos4 = getBoardPosition(board, piece.currentPos[0]-1, piece.currentPos[1]-1);
				if (pos4[1] != 's' && pos4[0] == 'b'){
					char move[4]; // Allocate memory for the concatenated string (2 characters + null terminator)

					move[0] = FILE_LIST[piece.currentPos[1]];
					move[1] = 'x';
					move[2] = piece.currentPos[0] + '1'; // Convert integer to character
					move[3] = '\0'; // Null-terminate the string
					printf("%s", move);
					
				}
			}		
		}	
	}
	free(pos1);
	free(pos2);
	free(pos3);
	free(pos4;
	char* moveList = "hi";
	return moveList;
}

char* knightMoves(struct Board board){
	char* moveList = "hi";
	return moveList;
}

char* bishopMoves(struct Board board){
	char* moveList = "hi";
	return moveList;

}

char* rookMoves(struct Board board){
	char* moveList = "hi";
	return moveList;

}

char* queenMoves(struct Board board){
	char* moveList = "hi";
	return moveList;

}

char* kingMoves(struct Board board){
	char* moveList = "hi";
	return moveList;

}
