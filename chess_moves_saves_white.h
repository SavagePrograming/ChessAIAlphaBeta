//
// Created by wills on 3/12/2019.
//

#ifndef CHESS_CHESS_MOVES_WHITE_SAVES_H
#define CHESS_CHESS_MOVES_WHITE_SAVES_H

#include <stdint.h>
#include "chess_board.h"
#include "chess_moves.h"
#include "chess_moves_save.h"

void get_moves_white_pawn_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_rook_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_bishop_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_knight_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_queen_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_king_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_save(chessBoard board, chessMove *move, chessMoveSave save);

#endif //CHESS_CHESS_MOVES_SAVES_H
