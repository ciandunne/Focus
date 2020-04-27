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

void turn(player *playernow, square board [BOARD_SIZE][BOARD_SIZE]);

int firstChoice(player *playernow, square board[BOARD_SIZE][BOARD_SIZE]);

int winCondition(square board[BOARD_SIZE][BOARD_SIZE], player playernow);