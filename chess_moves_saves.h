//
// Created by wills on 3/12/2019.
//

#ifndef CHESS_CHESS_MOVES_SAVES_H
#define CHESS_CHESS_MOVES_SAVES_H


//#include <stdint.h>

typedef struct chess_move_save{
    uint8_t X:3;
    uint8_t Y:3;
    uint8_t moveX:3;
    uint8_t moveY:3;
    uint8_t done:4;
} * chessMoveSave;

chessMoveSave makeStartingSave();

void get_moves_white_pawn_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_rook_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_bishop_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_knight_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_queen_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_king_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_pawn_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_rook_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_bishop_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_knight_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_queen_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_king_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_white_save(chessBoard board, chessMove *move, chessMoveSave save);

void get_moves_black_save(chessBoard board, chessMove *move, chessMoveSave save);

#endif //CHESS_CHESS_MOVES_SAVES_H
