//
// Created by wills on 3/12/2019.
// Header file for functions that run Alpha-Beta on Chess moves
//

#ifndef CHESS_CHESS_ALPHA_BETA_H
#define CHESS_CHESS_ALPHA_BETA_H

#define MIN 'n'
#define MAX 'x'

#include "chess_moves.h"

int8_t treeless_chess_alpha_beta(char min_or_max, uint32_t *board, uint8_t depth, chessMove *move_return);

int8_t treeless_chess_alpha_beta_helper(char min_or_max, uint32_t *board,
                                 int8_t top, int8_t bottom, uint8_t depth);


#endif //CHESS_CHESS_ALPHA_BETA_H
