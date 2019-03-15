//
// Created by wills on 3/12/2019.
//

#ifndef CHESS_CHESS_MOVES_H
#define CHESS_CHESS_MOVES_H

#include "stdint.h"
#include "chess_board.h"

/**
 * The structure for a chess move
 * startX is the start x location
 * startX is the start y location
 * endX is the end x location
 * endY is the end y location
 * taken is the piece the move will take
 */
typedef struct chess_move{
    uint8_t startX:3;
    uint8_t startY:3;
    uint8_t endX:3;
    uint8_t endY:3;
    uint8_t taken:4;
} chessMove;

void make_chess_move(chessMove *new, uint8_t startX, uint8_t start_y,
                          uint8_t end_x, uint8_t end_y, uint8_t taken);

void make_chess_move_board(chessMove *new, uint8_t start_x, uint8_t start_Y,
                                uint8_t end_x, uint8_t end_y, chessBoard board);

void get_moves_white_pawn(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_white_rook(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_white_bishop(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_white_knight(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_white_queen(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_white_king(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_black_pawn(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_black_rook(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_black_bishop(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_black_knight(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_black_queen(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

void get_moves_black_king(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]);

chessMove * copy_chess_moves_to_heap(chessMove *moves, uint8_t size);

chessMove * get_moves_white(chessBoard board, uint8_t *size);

chessMove * get_moves_black(chessBoard board, uint8_t *size);

void run_chess_move(chessBoard board, chessMove move);

void reverse_chess_move(chessBoard board, chessMove move);

void highlight_chess_move(chessBoard board, chessMove move);

void reverse_chess_move_highlight(chessBoard board, chessMove move);

void copy_move(chessMove * from, chessMove * to);

void print_move(chessMove move);

#endif //CHESS_CHESS_MOVES_H
