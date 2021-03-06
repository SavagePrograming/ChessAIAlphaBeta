//
// Created by wills on 3/13/2019.
//

#ifndef CHESS_CHESS_MOVES_WHITE_SAVE_H
#define CHESS_CHESS_MOVES_WHITE_SAVE_H

#include <stdint.h>

/**
 * A save structure that helps with generating one move at a time
 */
typedef struct chess_move_save{
    uint8_t X:3;
    uint8_t Y:3;
    uint8_t moveX:3;
    uint8_t moveY:3;
    uint8_t done:4;
} * chessMoveSave;

chessMoveSave make_starting_save();

void break_down_save(chessMoveSave chess_move_save);

#endif //CHESS_CHESS_MOVES_SAVE_H
