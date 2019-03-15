//
// Created by William on 3/15/2019.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include <stdint.h>
#include "chess_board.h"

#define WHITE_PLAYERS_TURN 'w'
#define BLACK_PLAYERS_TURN 'b'

#define WHITE_WINS 1
#define BLACK_WINS 2
#define STALEMATE 3

uint8_t validate_board(chessBoard board);

#endif //CHESS_CHESS_H
