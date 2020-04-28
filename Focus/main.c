
#include "stack_movement.h"

int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    //Keeps track of who's turn it is
    enum currTurn nowturn = player1;
    print_board(board);

    //Keep calling turn function for each player until one player can no longer make a move
    while(players[0].won == 0 && players[1].won == 0){
        if(nowturn == player1) {
            //Checks if the player has lost in the last turn
            if(players[0].reserves == 0 && winCondition(board, players[0]) == 1){
                players[1].won = 1;
            }
            else {
                turn(&players[0], board);
                nowturn = player2;
            }
        }

        else {
            //Checks if the player has lost in the last turn
            if(players[1].reserves == 0 && winCondition(board, players[1]) == 1) {
                players[0].won = 1;
            }
            else {
                turn(&players[1], board);
                nowturn = player1;
            }
        }
        print_board(board);
    }

    //Printing the winners and scoring information
    printf("WINNER: ");
    if(players[0].won == 1){
        printf("%s\n", players[0].name);
        puts("COLOUR: RED");
        printf("CAPTURES: %d", players[0].captures);
    }
    else{
        printf("%s\n", players[1].name);
        puts("COLOUR: GREEN");
        printf("CAPTURES: %d", players[1].captures);
    }
    return 0;
}
