#ifndef MOVES_H
#define MOVES_H

#include <stdbool.h>
#include "piece.h"
#include "board.h"

struct Moves {
	char* pawnMoves;
	char* rookMoves;
	char* knightMoves;
	char* bishopMoves;
	char* queenMoves;
	char* kingMoves;
	bool check;	
};

struct Moves generateMoves(struct Board board);
char* pawnMoves(struct Board board);
char* knightMoves(struct Board board);
char* bishopMoves(struct Board board);
char* rookMoves(struct Board board);
char* queenMoves(struct Board board);
char* kingMoves(struct Board board);

bool check(struct Moves m);
bool gameOver();



#endif
