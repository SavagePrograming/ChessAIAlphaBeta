//
// Created by wills on 3/12/2019.
//

#ifndef CHESS_CHESS_MOVES_H
#define CHESS_CHESS_MOVES_H

#include "stdint.h"

typedef struct chess_move{
    uint8_t startX:3;
    uint8_t startY:3;
    uint8_t endX:3;
    uint8_t endY:3;
    uint8_t target:4;
} chessMove;

chessMove make_chess_move(chessMove *new, uint8_t startX, uint8_t startY,
                          uint8_t endX, uint8_t endY, uint8_t target);

chessMove make_chess_move_board(chessMove *new, uint8_t startX, uint8_t startY,
                                uint8_t endX, uint8_t endY, chessBoard board);

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

chessMove * copyChessMovesToHeap(chessMove moves[250], uint8_t size);

chessMove * get_moves_white(chessBoard board, uint8_t *size);

chessMove * get_moves_black(chessBoard board, uint8_t *size);

void runChessMove(chessBoard board, chessMove move);

void reverseChessMove(chessBoard board, chessMove move);

void highlightChessMove(chessBoard board, chessMove move);

void reverseChessMoveHighlight(chessBoard board, chessMove move);

#endif //CHESS_CHESS_MOVES_H
