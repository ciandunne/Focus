//
// Created by cianc on 24/04/2020.
//
#include "stack_movement.h"

void turn(player *playernow, square board [BOARD_SIZE][BOARD_SIZE]){
    printf("%s turn\n", playernow->name);

    //Giving information about who's turn it is
    if(playernow->player_color == RED){
        puts("Colour: RED");
        printf("Captures: %d\n", playernow->captures);
        printf("Reserves: %d\n", playernow->reserves);
    }
    else{
        puts("Colour: GREEN");
        printf("Captures: %d\n", playernow->captures);
        printf("Reserves: %d\n", playernow->reserves);
    }

    int xcoord = 0, ycoord = 0;
    int newxcoord = 0, newycoord = 0;

    //Making the first choice: what they want to do with their turn
    int choice = firstChoice(playernow, board);

    //Functionality to add a reserve piece back into the board
    if(choice == 2){
        while (newxcoord == 0 && newycoord == 0) {
            puts("Input the coordinates of the square you want to add your piece to, starting with the row.");
            scanf("%d%d", &newycoord, &newxcoord);

            if (newxcoord <= 0 || newxcoord > 8 || newycoord <= 0 || newycoord > 8 || board[newxcoord - 1][newycoord - 1].type == INVALID) {
                puts("Invalid square please, try again");
                newxcoord = 0;
                newycoord = 0;
            }
        }
        reserveAddition(&board[newycoord-1][newxcoord-1], playernow);
    }

    //Functionality to move one stack, or one piece from a stack
    else {
        //Reset choice variable for later use
        choice = 0;
        //Allows user to pick the stack they want to move and ensures there is a stack there that they are able to move
        while (xcoord == 0 && ycoord == 0) {
            puts("Input the coordinates of the stack you want to move, starting with the row.");
            scanf("%d%d", &ycoord, &xcoord);

            //Ensures that they have entered a square which is valid
            if (xcoord <= 0 || xcoord > 8 || ycoord <= 0 || ycoord > 8 ||
                board[xcoord - 1][ycoord - 1].type == INVALID) {
                puts("Invalid square please, try again");
                xcoord = 0;
                ycoord = 0;
                continue;
            }
                //Ensures that there is a piece on the square selected
            else if (board[ycoord - 1][xcoord - 1].stack == NULL) {
                puts("There are no pieces to move on this square, please try again");
                xcoord = 0;
                ycoord = 0;
                continue;
            }
                //Ensures the piece on the square is the right colour
            else if (board[ycoord - 1][xcoord - 1].stack->p_color != playernow->player_color) {
                puts("The top piece on this square is not your colour, please try again");
                xcoord = 0;
                ycoord = 0;
                continue;
            }
        }
        //If there is only one piece on the chosen square
        if (board[ycoord - 1][xcoord - 1].num_pieces == 1) {
            //Allows user to move their piece one square in any direction and ensures it is a valid move
            while (choice == 0) {
                puts("What direction do you want to move?\n "
                     "Input 1 to go down,\n"
                     "Input 2 to go up,\n"
                     "Input 3 to go right,\n"
                     "Input 4 to go left.");
                scanf("%d", &choice);

                //Ensures that they have entered a square which is valid
                if (choice < 1 || choice > 4) {
                    puts("Invalid choice, try again");
                    choice = 0;
                    continue;
                }

                //Adjust the coordinates according to the user input
                switch (choice) {
                    case 1:
                        newycoord = ycoord + 1;
                        newxcoord = xcoord;
                        break;
                    case 2:
                        newycoord = ycoord - 1;
                        newxcoord = xcoord;
                        break;
                    case 3:
                        newxcoord = xcoord + 1;
                        newycoord = ycoord;
                        break;
                    case 4:
                        newxcoord = xcoord - 1;
                        newycoord = ycoord;
                        break;
                    default:
                        break;
                }
                //Ensures the square they want to move to is valid
                if (newxcoord <= 0 || newxcoord > 8 || newycoord <= 0 || newycoord > 8) {
                    puts("Cant move off board, please try again");
                    choice = 0;
                    continue;

                } else if (board[newycoord - 1][newxcoord - 1].type == INVALID) {
                    puts("Move is to invalid square, please try again");
                    choice = 0;
                    continue;
                }
            }
            stackMoveTop(&board[ycoord - 1][xcoord - 1], &board[newycoord - 1][newxcoord - 1]);
        }

        else {
            //They can move either the top piece or the whole stack
            while (choice == 0) {
                puts("Input 1 to move the whole stack or 2 to move just the top piece.");
                scanf("%d", &choice);

                if (choice < 1 || choice > 2) {
                    puts("Invalid choice, please try again.");
                    choice = 0;
                    continue;
                }
            }
            //Moving only the top piece
            if (choice == 2) {
                choice = 0;
                while (choice == 0) {
                    puts("What direction do you want to move?\n "
                         "Input 1 to go down,\n"
                         "Input 2 to go up,\n"
                         "Input 3 to go right,\n"
                         "Input 4 to go left.");
                    scanf("%d", &choice);

                    if (choice < 1 || choice > 4) {
                        puts("Invalid choice, try again");
                        choice = 0;
                        continue;
                    }

                    //Adjust the coordinates according to the user input
                    switch (choice) {
                        case 1:
                            newycoord = ycoord + 1;
                            newxcoord = xcoord;
                            break;
                        case 2:
                            newycoord = ycoord - 1;
                            newxcoord = xcoord;
                            break;
                        case 3:
                            newxcoord = xcoord + 1;
                            newycoord = ycoord;
                            break;
                        case 4:
                            newxcoord = xcoord - 1;
                            newycoord = ycoord;
                            break;
                        default:
                            break;
                    }

                    //Ensures the piece on the square is the right colour
                    if (newxcoord <= 0 || newxcoord > 8 || newycoord <= 0 || newycoord > 8) {
                        puts("Cant move off board, please try again");
                        choice = 0;
                        continue;
                    } else if (board[newycoord - 1][newxcoord - 1].type == INVALID) {
                        puts("Move is to invalid square, please try again");
                        choice = 0;
                        continue;
                    }
                }
                stackMoveTop(&board[ycoord - 1][xcoord - 1], &board[newycoord - 1][newxcoord - 1]);
            }
            else {
                //Finds amount of moves they need to make
                int moves = pieceCount(board[ycoord - 1][xcoord - 1]);
                newxcoord = xcoord;
                newycoord = ycoord;

                //Goes through he code to move as many times as moves the player has with the stack they are moving
                for (int i = 0; i < moves; i++) {
                    choice = 0;

                    while (choice == 0) {
                        printf("You have %d moves remaining with your stack\n", moves - i);
                        puts("What is the direction you want to move?\n"
                             "Input 1 to go down,\n"
                             "Input 2 to go up,\n"
                             "Input 3 to go right,\n"
                             "Input 4 to go left.");
                        scanf("%d", &choice);

                        if (choice < 1 || choice > 4) {
                            puts("Invalid choice, please try again");
                            choice = 0;
                            continue;
                        }

                        switch (choice) {
                            case 1:
                                newycoord++;
                                break;
                            case 2:
                                newycoord--;
                                break;
                            case 3:
                                newxcoord++;
                                break;
                            case 4:
                                newxcoord--;
                                break;
                            default:
                                break;
                        }
                        if (newxcoord <= 0 || newxcoord > 8 || newycoord <= 0 || newycoord > 8) {
                            puts("Cant move off board, please try again");
                            choice = 0;
                            continue;
                        } else if (board[newycoord - 1][newxcoord - 1].type == INVALID) {
                            puts("Move is to invalid square, please try again");
                            choice = 0;
                            continue;
                        }
                    }
                }
                stackMoveWhole(&board[ycoord - 1][xcoord - 1], &board[newycoord - 1][newxcoord - 1], moves);
            }
        }
    }
    //Removes items from the stack if it has more than 5 pieces in it
    if (pieceCount(board[newycoord - 1][newxcoord - 1]) > 5)
        stackLimiter(&board[newycoord - 1][newxcoord - 1], playernow);
}

//Manages the first choice every player has to make
int firstChoice(player *playernow, square board[BOARD_SIZE][BOARD_SIZE]) {
    int choice = 0, ycoord = 0, xcoord = 0;


    while (choice == 0 || choice == 1) {
        puts("What would you like to do?\n "
             "Input 1 to investigate a particular square, DOES NOT TAKE UP YOUR TURN\n"
             "Input 2 to place one of your reserve pieces,\n"
             "Input 3 to move a stack.");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            puts("Invalid choice, please try again.");
            choice = 0;
        }
        else if (choice == 1) {
            while (xcoord == 0 && ycoord == 0) {
                puts("Input the coordinates of the stack you want to move, starting with the row.");
                scanf("%d%d", &ycoord, &xcoord);

                //Ensures that they have entered a square which is valid
                if (xcoord <= 0 || xcoord > 8 || ycoord <= 0 || ycoord > 8 ||
                    board[xcoord - 1][ycoord - 1].type == INVALID) {
                    puts("Invalid square please, try again");
                    xcoord = 0;
                    ycoord = 0;
                    continue;
                }
            }
            printStack(board[ycoord - 1][xcoord - 1], ycoord, xcoord);
            //Returns them back to the start of the loop after the stack is printed
            xcoord = 0;
            ycoord = 0;
        }
        //Ensures they have not chosen option 2 with no reserve pieces
        else if (choice == 2 && playernow->reserves==0){
            puts("You have no reserves pieces, please try again.");
            choice = 0;
        }
        //Ensures that they have not chosen to move a stack when they have no stacks they can move on the board
        else if (choice == 3 && winCondition(board, *playernow) == 1){
            puts("No pieces are available to move on the board, you must place your reserve pieces.");
            choice = 0;
        }

    }

    return choice;
}

/*Returns 0 if the player being investigated has pieces on the board they can move yet,
 * or returns 1 if the player doesnt have any pieces on the board to move?
 */
int winCondition(square board[BOARD_SIZE][BOARD_SIZE], player playernow){
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            //If any squares on the board have a top piece colour the same as the player then return 0
            if(board[i][j].stack != NULL && board[i][j].stack->p_color == playernow.player_color) {
                return 0;
            }
        }
    }
    //Otherwise return 1
    return 1;
}