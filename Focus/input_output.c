#include <stdio.h>
#include "input_output.h"

/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
    printf("    1   2   3   4   5   6   7   8  \n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        printf("%d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|   ");
                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| G ");
                    else printf("| R ");
                }
            }
            else
                printf("| - ");
        }
        printf("|\n");
    }
}

//Prints the full contents of a square
void printStack(square zone, int ycoord, int xcoord){
    printf("The square located in row %d, column %d has the following stack\n", ycoord, xcoord);

    piece *temp = zone.stack;

    if(temp == NULL){
        puts("Stack is empty");
    }

    while(temp!=NULL){
        if(temp->p_color == RED)
            puts("Red");
        else
            puts("Green");
        temp = temp->next;
    }
}

