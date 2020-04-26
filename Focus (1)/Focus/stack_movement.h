//
// Created by cianc on 26/04/2020.
//

#ifndef FOCUS_STACK_MOVEMENT_H
#define FOCUS_STACK_MOVEMENT_H

#endif //FOCUS_STACK_MOVEMENT_H

#include "turns.h"

void stackMoveTop(square *orig, square *new);

void stackMoveWhole(square *orig, square *new, int moves);

void reserveAddition(square *zone, player *playernow);

int pieceCount(square zone);

void stackLimiter(square *zone, player *playernow);

void printStack(square zone, int ycoord, int xcoord);