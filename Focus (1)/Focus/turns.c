//
// Created by cianc on 24/04/2020.
//

#include "turns.h"

void turn(player *playernow, square board [BOARD_SIZE][BOARD_SIZE]){
    printf("%s turn\n", playernow->name);

    if(playernow->player_color == RED){
        printf("Colour: RED\n"
             "Captures: %d\n", playernow->captures,
             "Reserves: %d\n", playernow->reserves);
    }
    else{
        printf("Colour: GREEN"
             "Captures: %d\n", playernow->captures,
             "Reserves: %d\n", playernow->reserves);
    }

    int xcoord = 0, ycoord = 0;
    int choice = 0;

    while(choice == 0){
        
    }

    while(xcoord==0 && ycoord==0){
        puts("Input the coordinates of the stack you want to move, starting with the row.");
        scanf("%d%d", &ycoord, &xcoord);

        if(xcoord<=0 || xcoord>8 || ycoord<=0 || ycoord>8 || board[xcoord-1][ycoord-1].type == INVALID){
            puts("Invalid square please, try again");
            xcoord = 0;
            ycoord = 0;
            continue;
        }

        else if(board[ycoord-1][xcoord-1].stack == NULL){
            puts("There are no pieces to move on this square, please try again");
            xcoord = 0;
            ycoord = 0;
            continue;
        }

        else if(board[ycoord-1][xcoord-1].stack->p_color != playernow->player_color){
            puts("The top piece on this square is not your colour, please try again");
            xcoord = 0;
            ycoord = 0;
            continue;
        }
    }

    int newxcoord, newycoord;

    if(board[ycoord-1][xcoord-1].num_pieces == 1){
        while(choice==0){
            puts("What direction do you want to move?\n "
                 "Input 1 to go down,\n"
                 "Input 2 to go up,\n"
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
            if(newxcoord<=0 || newxcoord>8 || newycoord<=0 || newycoord>8){
                puts("Cant move off board, please try again");
                choice = 0;
                continue;
            }
            else if(board[newycoord-1][newxcoord-1].type == INVALID) {
                puts("Move is to invalid square, please try again");
                choice = 0;
                continue;
            }
        }
        stackMoveTop(&board[ycoord-1][xcoord-1], &board[newycoord-1][newxcoord-1]);
    }
    else{
        while(choice == 0) {
            puts("Input 1 to move the whole stack or 2 to move just the top piece.");
            scanf("%d", &choice);

            if(choice<1 || choice>2){
                puts("Invalid choice, please try again.");
                choice = 0;
                continue;
            }
        }
        if (choice == 2){
            choice = 0;
            while(choice==0){
                puts("What direction do you want to move?\n "
                     "Input 1 to go down,\n"
                     "Input 2 to go up,\n"
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

                if(newxcoord<=0 || newxcoord>8 || newycoord<=0 || newycoord>8){
                    puts("Cant move off board, please try again");
                    choice = 0;
                    continue;
                }

                else if(board[newycoord-1][newxcoord-1].type == INVALID) {
                    puts("Move is to invalid square, please try again");
                    choice = 0;
                    continue;
                }
            }
            stackMoveTop(&board[ycoord-1][xcoord-1], &board[newycoord-1][newxcoord-1]);
        }
        else{
            int moves = pieceCount(board[ycoord-1][xcoord-1]);
            newxcoord = xcoord;
            newycoord = ycoord;

            for(int i=0; i<moves; i++){
                choice = 0;

                while(choice == 0){
                    printf("You have %d moves remaining with your stack\n", moves-i);
                    puts("What is the direction you want to move?\n"
                         "Input 1 to go down,\n"
                         "Input 2 to go up,\n"
                         "Input 3 to go right,\n"
                         "Input 4 to go left.");
                    scanf("%d", &choice);

                    if(choice<1 || choice>4){
                        puts("Invalid choice, please try again");
                        choice = 0;
                        continue;
                    }

                    switch(choice) {
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
                    if(newxcoord<=0 || newxcoord>8 || newycoord<=0 || newycoord>8){
                        puts("Cant move off board, please try again");
                        choice = 0;
                        continue;
                    }

                    else if(board[newycoord-1][newxcoord-1].type == INVALID) {
                        puts("Move is to invalid square, please try again");
                        choice = 0;
                        continue;
                    }
                }
            }
            stackMoveWhole(&board[ycoord-1][xcoord-1], &board[newycoord-1][newxcoord-1], moves);
        }
    }

    if(pieceCount(board[newycoord-1][newxcoord-1]) > 5)
        stackLimiter(&board[newycoord-1][newxcoord-1], playernow);

}

//Moves one piece from one stack to another
void stackMoveTop(square *orig, square *new){
    //Changing the number of pieces each of the recorded squares has
    new->num_pieces++;
    orig->num_pieces--;

    //Adjusting the stacks
    piece *temp;

    //Adding piece to new stack
    temp = new->stack;
    new->stack = (piece *)malloc(sizeof(piece));
    new->stack->p_color = orig->stack->p_color;
    new->stack->next = temp;

    //Removing top piece from first stack
    temp = orig->stack;
    orig->stack = orig->stack->next;
    free(temp);

}

//Moves entire stack from one square to the other
void stackMoveWhole(square *orig, square *new, int moves){
    //Changing the number of pieces in the stack
    orig->num_pieces = orig->num_pieces-moves;
    new->num_pieces = new->num_pieces+moves;

    //Changing the stack itself
    piece *temp;
    temp = orig->stack;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new->stack;
    new->stack = orig->stack;
    orig->stack = NULL;
}


int pieceCount(square zone){
    piece *temp = zone.stack;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}


void stackLimiter(square *zone, player *playernow){
    piece *curr = zone->stack;
    //Set temp to point to the 5th node in the stack
    for(int i=1; i<5; i++)
        curr = curr->next;

    piece *temp = curr->next;

    //Close the end of the linked list after the 5th node
    curr->next = NULL;
    curr = temp;
    //Keep taking pieces off the end after the first five until there are no more pieces to take
    while(curr != NULL){

        //Adjust the reserved/captured pieces accordingly
        if(curr->p_color == playernow->player_color)
            playernow->reserves++;
        else
            playernow->captures++;

        //Sets currs to point to the next node and frees the last node.
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}