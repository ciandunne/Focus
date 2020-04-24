//
// Created by cianc on 24/04/2020.
//

#include "turns.h"

void turn(player playernow, square board [BOARD_SIZE][BOARD_SIZE]){
    int xcoord = 0, ycoord = 0;

    while(xcoord==0 && ycoord==0){
        puts("Input the coordinates of the stack you want to move, starting with the row.");
        scanf("%d%d", &xcoord, &ycoord);

        if(xcoord<=0 || xcoord>8 || ycoord<=0 || ycoord>8 || board[xcoord-1][ycoord-1].type == INVALID){
            puts("Invalid square please, try again");
            xcoord = 0;
            ycoord = 0;
            continue;
        }
        else if(board[xcoord-1][ycoord-1].stack == NULL){
            puts("There are no pieces to move on this square, please try again");
            xcoord = 0;
            ycoord = 0;
            continue;
        }
        else if(board[xcoord-1][ycoord-1].stack->p_color != playernow.player_color){
            puts("The top piece on this square is not your colour, please try again");
            xcoord = 0;
            ycoord = 0;
            continue;
        }
    }

    int choice = 0;
    int newxcoord, newycoord;

    if(board[xcoord-1][ycoord-1].num_pieces == 1){
        while(choice==0){
            puts("What direction do you want to move?\n "
                 "Input 1 to go up,\n"
                 "Input 2 to go down,\n"
                 "Input 3 to go right,\n"
                 "Input 4 to go left.");
            scanf("%d", &choice);

            if(choice<1 || choice>4){
                puts("Invalid choice, try again");
                choice = 0;
                continue;
            }

            switch(choice) {
                case 1:
                    newycoord = ycoord + 1;
                    break;
                case 2:
                    newycoord = ycoord - 1;
                    break;
                case 3:
                    newxcoord = xcoord + 1;
                    break;
                case 4:
                    newxcoord = xcoord - 1;
                    break;
                default:
                    break;
            }
            if(newxcoord<=0 || newxcoord>8 || newycoord<=0 || newycoord>8){
                puts("Cant move off board, please try again");
                choice = 0;
                continue;
            }
            else if(board[newxcoord-1][newycoord-1].type == INVALID) {
                puts("Move is to invalid square, please try again");
                choice = 0;
                continue;
            }
        }
        board[xcoord-1][ycoord-1].num_pieces = 0;
        board[xcoord-1][ycoord-1].stack = NULL;
        
    }
    else{
        puts("Input 1 to move the whole stack or 2 to move just the top piece.");
        for(int i=0; i<board; i++)
    }

}