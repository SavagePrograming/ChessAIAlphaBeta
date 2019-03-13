//
// Created by wills on 3/13/2019.
//
#include "chess_moves_save.h"
#include <stdlib.h>

chessMoveSave makeStartingSave() {
    chessMoveSave new = malloc(sizeof(struct chess_move_save));
    new->Y = 0;
    new->X = 0;
    new->moveX = 0;
    new->moveY = 0;
    new->done = 0;
}
