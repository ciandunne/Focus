#include "turns.h"

int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    int i=0;
    enum currTurn nowturn = player1;
    print_board(board);

    //Keep calling turn function for each player until one player can no longer make a move
    while(i<20){
        if(nowturn == player1) {
            turn(players[0], board);
            nowturn = player2;
        }

        else {
            turn(players[1], board);
            nowturn = player1;
        }
        print_board(board);
    }

    return 0;
}
