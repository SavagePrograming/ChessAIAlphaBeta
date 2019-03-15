//
// Created by wills on 3/13/2019.
// Has functions shared by black and white move generation based on saves
//
#include "chess_moves_save.h"
#include <stdlib.h>

/**
 * Makes a new move save
 * @return A dynamically allocated save
 */
chessMoveSave make_starting_save() {
    chessMoveSave new = malloc(sizeof(struct chess_move_save));
    new->Y = 0;
    new->X = 0;
    new->moveX = 0;
    new->moveY = 0;
    new->done = 0;
}

/**
 * Breaks down and frees a save
 * @param chess_move_save The save to break down
 */
void break_down_save(chessMoveSave chess_move_save){
    free(chess_move_save);
}