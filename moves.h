#ifndef MOVES_H
#define MOVES_H

#include <stdbool.h>
#include "piece.h"
#include "board.h"

struct Moves {
	struct Move legalmoves;
}

struct Moves generateMoves(struct Board board, bool white);

#endif
