#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_init.h"

//Initialises players
void initialize_players(player players[PLAYERS_NUM]){
    players[0].player_color = RED;
    players[1].player_color = GREEN;

    printf("Enter the name of the red player: ");
    fgets(&players[0].name, 20, stdin);

    printf("Enter the name of the green player: ");
    fgets(&players[1].name, 20, stdin);

    //removing \n from read in name
    char *ix;

    //strchr finds the first instance of '\n' in the given string and sets the char pointer ix to hold the address of that location. Then we set this locations item to the null terminator
    for(int i=0; i<2; i++) {
        while ((ix = strchr(players[i].name, '\n')) != NULL) {
            *ix = '\0';
        }
    }

    for(int i=0; i<2; i++){
        players[i].captures = 0;
        players[i].reserves = 0;
        players[i].won = 0;
    }
}

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }


    }


}

