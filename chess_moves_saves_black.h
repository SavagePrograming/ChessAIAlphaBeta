//
// Created by wills on 3/12/2019.
//

#ifndef CHESS_CHESS_MOVES_BLACK_SAVES_H
#define CHESS_CHESS_MOVES_BLACK_SAVES_H

#include <stdint.h>
#include "chess_board.h"
#include "chess_moves.h"
#include "chess_moves_save.h"
//#include "chess_moves_saves_white.h"

void get_moves_black_pawn_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_rook_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_bishop_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_knight_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_queen_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_king_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_save(chessBoard board, chessMove *move, chessMoveSave save);

#endif //CHESS_CHESS_MOVES_SAVES_H
