//
// Created by cianc on 26/04/2020.
//

#include "stack_movement.h"

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
    if(orig != new) {
        //Changing the number of pieces in the stack
        orig->num_pieces = orig->num_pieces - moves;
        new->num_pieces = new->num_pieces + moves;

        //Changing the stack itself
        piece *temp;
        temp = orig->stack;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new->stack;
        new->stack = orig->stack;
        orig->stack = NULL;
    }
}

//Allows players to add their reserve pieces back onto the board
void reserveAddition(square *zone, player *playernow){
    //Reduce the amount of reserves the player has
    playernow->reserves--;

    //Add the new piece to the top of the stack and give it the correct colour
    piece *temp = zone->stack;
    zone->stack = (piece*)malloc(sizeof(piece));
    zone->stack->next = temp;
    zone->stack->p_color = playernow->player_color;
}

//Counts the number of pieces in a stack
int pieceCount(square zone){
    piece *temp = zone.stack;
    int count = 0;

    while(temp!=NULL){
        temp = temp->next;
        count++;
    }

    return count;
}

//Removes the bottom pieces from the stack until there are only 5 pieces in the stack
void stackLimiter(square *zone, player *playernow){
    piece *curr = zone->stack;
    //Set temp to point to the 5th node in the stack
    for(int i=1; i<5; i++)
        curr = curr->next;

    piece *temp = curr->next;
    int reserves = 0, captures = 0;

    //Close the end of the linked list after the 5th node
    curr->next = NULL;
    curr = temp;
    //Keep taking pieces off the end after the first five until there are no more pieces to take
    while(curr != NULL){

        //Adjust the reserved/captured pieces accordingly
        if(curr->p_color == playernow->player_color) {
            playernow->reserves++;
            reserves++;
        }
        else {
            playernow->captures++;
            captures++;
        }

        //Sets currs to point to the next node and frees the last node.
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    printf("This stack has been shortened and you have been give %d reserve pieces and have captured %d opponent pieces\n", reserves, captures);
}

