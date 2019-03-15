//
// Created by William on 3/15/2019.
//

#ifndef CHESS_CHESS_AI_H
#define CHESS_CHESS_AI_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "min_max.h"
#include "chess_alpha_beta.h"
#include "chess_board.h"
#include "chess_moves_save.h"
#include "chess_moves_saves_black.h"
#include "chess_moves_saves_white.h"
#include "chess_alpha_beta.h"
#include "chess_AI.h"

#define WHITE_PLAYERS_TURN 'w'
#define BLACK_PLAYERS_TURN 'b'

chessMove * get_move_to_move(chessBoard board, char player_turn);

char get_next_turn(char player_turn);

uint8_t run_AI_turn(chessBoard board, char * player_turn);

#endif //CHESS_CHESS_AI_H
