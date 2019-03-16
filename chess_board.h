//
// Created by wills on 2/10/2019.
//

#ifndef CHESS_CHESS_BOARD_H
#define CHESS_CHESS_BOARD_H
//=============Debugging=========

//=========CHESS NUMBERS===========
#define BLANK_NUMBER 0

#define WHITE_PAWN_NUMBER 1
#define WHITE_ROOK_NUMBER 2
#define WHITE_BISHOP_NUMBER 3
#define WHITE_KNIGHT_NUMBER 4
#define WHITE_QUEEN_NUMBER 5
#define WHITE_KING_NUMBER 6

#define BLACK_PAWN_NUMBER 9
#define BLACK_ROOK_NUMBER 10
#define BLACK_BISHOP_NUMBER 11
#define BLACK_KNIGHT_NUMBER 12
#define BLACK_QUEEN_NUMBER 13
#define BLACK_KING_NUMBER 14

#define OTHER_NUMBER 15

//=========CHESS CHARS===========
#define BLANK_CHAR ' '

#define WHITE_PAWN_CHAR 'P'
#define WHITE_ROOK_CHAR 'R'
#define WHITE_BISHOP_CHAR 'B'
#define WHITE_KNIGHT_CHAR 'N'
#define WHITE_QUEEN_CHAR 'Q'
#define WHITE_KING_CHAR 'K'

#define BLACK_PAWN_CHAR 'p'
#define BLACK_ROOK_CHAR 'r'
#define BLACK_BISHOP_CHAR 'b'
#define BLACK_KNIGHT_CHAR 'n'
#define BLACK_QUEEN_CHAR 'q'
#define BLACK_KING_CHAR 'k'
#define OTHER_CHAR '-'

//=========PIECE SCORES===========
#define BLANK_SCORE 0

#define PAWN_SCORE 1
#define ROOK_SCORE 5
#define BISHOP_SCORE 5
#define KNIGHT_SCORE 5
#define QUEEN_SCORE 22
#define KING_SCORE 60

#define OTHER_SCORE 0

#include <stdint.h>

/**
 * This is the representation of a board
 * each uint32_t represents a row
 */
typedef uint32_t chessBoard[8];

//==========FUNCTIONS==============
unsigned char get_piece(chessBoard board, unsigned char x, unsigned char y);

void load_piece(chessBoard board, unsigned char x, unsigned char y, unsigned char piece_number);

char get_piece_char_from_number(unsigned char piece_number);

unsigned char get_piece_number_from_char(char piece_char);

void print_board(chessBoard board);

void start_board(chessBoard board);

void clear_board(chessBoard board);

int8_t score_board(chessBoard board);

int8_t score_row(chessBoard board, int8_t row_index);

int8_t score_peice_number(uint8_t piece_number);

int8_t score_peice_char(char peice_char);

int8_t peice_number_is_white(uint8_t piece_number);

int8_t peice_number_is_black(uint8_t piece_number);

int8_t peice_number_is_blank(uint8_t piece_number);

void start_board_no_pawns(chessBoard board);

#endif //CHESS_CHESS_BOARD_H
