//
// Created by cianc on 24/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"

#ifndef FOCUS_TURNS_H
#define FOCUS_TURNS_H

#endif //FOCUS_TURNS_H

typedef enum currTurn{
    player1,
    player2
}currTurn;

void turn(player player1, square board [BOARD_SIZE][BOARD_SIZE]);

void moveChoice(int choice);

void stackMoveTop(square *orig, square *new);

void stackMoveWhole(square *orig, square *new, int moves);

int pieceCount(square zone);