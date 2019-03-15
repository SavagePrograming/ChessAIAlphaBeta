//
// Created by wills on 2/9/2019X
//
#include <stdio.h>
#include <stdint.h>
#include "chess_board.h"

#define BM_4_7 (u_int32_t)0b00000000000000000000000000001111
#define BM_4_6 (u_int32_t)0b00000000000000000000000011110000
#define BM_4_5 (u_int32_t)0b00000000000000000000111100000000
#define BM_4_4 (u_int32_t)0b00000000000000001111000000000000
#define BM_4_3 (u_int32_t)0b00000000000011110000000000000000
#define BM_4_2 (u_int32_t)0b00000000111100000000000000000000
#define BM_4_1 (u_int32_t)0b00001111000000000000000000000000
#define BM_4_0 (u_int32_t)0b11110000000000000000000000000000

unsigned char get_piece(chessBoard board, unsigned char x, unsigned char y) {
    // row = y * 3
    switch (x) {
        case 0:
            return (unsigned char)((BM_4_0 & board[y]) >> 28);
        case 1:
            return (unsigned char)((BM_4_1 & board[y]) >> 24);
        case 2:
            return (unsigned char)((BM_4_2 & board[y]) >> 20);
        case 3:
            return (unsigned char)((BM_4_3 & board[y]) >> 16);
        case 4:
            return (unsigned char)((BM_4_4 & board[y]) >> 12);
        case 5:
            return (unsigned char)((BM_4_5 & board[y]) >> 8);
        case 6:
            return (unsigned char)((BM_4_6 & board[y]) >> 4);
        default:
            return (unsigned char)((BM_4_7 & board[y]));
    }
}

void load_piece(chessBoard board, unsigned char x, unsigned char y, unsigned char piece) {
    // row = y * 3
    switch (x) {
        case 0:
            board[y] = (board[y] & ~BM_4_0) | (piece << 28);
            break;
        case 1:
            board[y] = (board[y] & ~BM_4_1) | (piece << 24);
            break;
        case 2:
            board[y] = (board[y] & ~BM_4_2) | (piece << 20);
            break;
        case 3:
            board[y] = (board[y] & ~BM_4_3) | (piece << 16);
            break;
        case 4:
            board[y] = (board[y] & ~BM_4_4) | (piece << 12);
            break;
        case 5:
            board[y] = (board[y] & ~BM_4_5) | (piece << 8);
            break;
        case 6:
            board[y] = (board[y] & ~BM_4_6) | (piece << 4);
            break;
        default:
            board[y] = (board[y] & ~BM_4_7) | piece;
            break;
    }
}

char name_piece(unsigned char piece_num) {
    switch (piece_num) {
        case BLANK_NUMBER:
            return BLANK_CHAR;
        case WHITE_PAWN_NUMBER:
            return WHITE_PAWN_CHAR;
        case WHITE_ROOK_NUMBER:
            return WHITE_ROOK_CHAR;
        case WHITE_BISHOP_NUMBER:
            return WHITE_BISHOP_CHAR;
        case WHITE_KNIGHT_NUMBER:
            return WHITE_KNIGHT_CHAR;
        case WHITE_QUEEN_NUMBER:
            return WHITE_QUEEN_CHAR;
        case WHITE_KING_NUMBER:
            return WHITE_KING_CHAR;
        case BLACK_PAWN_NUMBER:
            return BLACK_PAWN_CHAR;
        case BLACK_ROOK_NUMBER:
            return BLACK_ROOK_CHAR;
        case BLACK_BISHOP_NUMBER:
            return BLACK_BISHOP_CHAR;
        case BLACK_KNIGHT_NUMBER:
            return BLACK_KNIGHT_CHAR;
        case BLACK_QUEEN_NUMBER:
            return BLACK_QUEEN_CHAR;
        case BLACK_KING_NUMBER:
            return BLACK_KING_CHAR;
        default:
            return OTHER_CHAR;
    }
}

unsigned char num_piece(char piece_name) {
    switch (piece_name) {
        case BLANK_CHAR:
            return BLANK_NUMBER;
        case WHITE_PAWN_CHAR:
            return WHITE_PAWN_NUMBER;
        case WHITE_ROOK_CHAR:
            return WHITE_ROOK_NUMBER;
        case WHITE_BISHOP_CHAR:
            return WHITE_BISHOP_NUMBER;
        case WHITE_KNIGHT_CHAR:
            return WHITE_KNIGHT_NUMBER;
        case WHITE_QUEEN_CHAR:
            return WHITE_QUEEN_NUMBER;
        case WHITE_KING_CHAR:
            return WHITE_KING_NUMBER;
        case BLACK_PAWN_CHAR:
            return BLACK_PAWN_NUMBER;
        case BLACK_ROOK_CHAR:
            return BLACK_ROOK_NUMBER;
        case BLACK_BISHOP_CHAR:
            return BLACK_BISHOP_NUMBER;
        case BLACK_KNIGHT_CHAR:
            return BLACK_KNIGHT_NUMBER;
        case BLACK_QUEEN_CHAR:
            return BLACK_QUEEN_NUMBER;
        case BLACK_KING_CHAR:
            return BLACK_KING_NUMBER;
        default:
            return OTHER_NUMBER;
    }
}

void print_board(chessBoard board) {
    for (char y = 0; y < 8; y++) {
        if (y % 2 == 0) {
            printf("|     XXXXX     XXXXX     XXXXX     XXXXX|\n|");
        } else {
            printf("|XXXXX     XXXXX     XXXXX     XXXXX     |\n|");
        }
        for (char x = 0; x < 8; x++) {
            unsigned char piece = get_piece(board, x, y);
            if (piece == 0) {
                if ((x + y) % 2 == 0) {
                    printf("     ");
                } else {
                    printf("XXXXX");
                }
            } else {
                if ((x + y) % 2 == 0) {
                    printf("  %c  ", name_piece(piece));
                } else {
                    printf("X %c X",name_piece(piece));
                }
            }
        }
        printf("|\n");
        if (y % 2 == 0) {
            printf("|     XXXXX     XXXXX     XXXXX     XXXXX|\n");
        } else {
            printf("|XXXXX     XXXXX     XXXXX     XXXXX     |\n");
        }
    }
}

void clear_board(chessBoard board){
    for (unsigned char i = 0; i < 8; i++){
        board[i] = 0;
    }
}

void start_board(chessBoard board){
    for (unsigned char x = 0; x < 8; x++){
        load_piece(board, x, 1, num_piece(BLACK_PAWN_CHAR));
        load_piece(board, x, 6, num_piece(WHITE_PAWN_CHAR));
    }
    load_piece(board, 0, 0, num_piece(BLACK_ROOK_CHAR));
    load_piece(board, 7, 0, num_piece(BLACK_ROOK_CHAR));
    load_piece(board, 1, 0, num_piece(BLACK_KNIGHT_CHAR));
    load_piece(board, 6, 0, num_piece(BLACK_KNIGHT_CHAR));
    load_piece(board, 2, 0, num_piece(BLACK_BISHOP_CHAR));
    load_piece(board, 5, 0, num_piece(BLACK_BISHOP_CHAR));
    load_piece(board, 3, 0, num_piece(BLACK_QUEEN_CHAR));
    load_piece(board, 4, 0, num_piece(BLACK_KING_CHAR));

    load_piece(board, 0, 7, num_piece(WHITE_ROOK_CHAR));
    load_piece(board, 7, 7, num_piece(WHITE_ROOK_CHAR));
    load_piece(board, 1, 7, num_piece(WHITE_KNIGHT_CHAR));
    load_piece(board, 6, 7, num_piece(WHITE_KNIGHT_CHAR));
    load_piece(board, 2, 7, num_piece(WHITE_BISHOP_CHAR));
    load_piece(board, 5, 7, num_piece(WHITE_BISHOP_CHAR));
    load_piece(board, 3, 7, num_piece(WHITE_QUEEN_CHAR));
    load_piece(board, 4, 7, num_piece(WHITE_KING_CHAR));

}


void start_board_no_pawns(chessBoard board){
    load_piece(board, 0, 0, num_piece(BLACK_ROOK_CHAR));
    load_piece(board, 7, 0, num_piece(BLACK_ROOK_CHAR));
    load_piece(board, 1, 0, num_piece(BLACK_KNIGHT_CHAR));
    load_piece(board, 6, 0, num_piece(BLACK_KNIGHT_CHAR));
    load_piece(board, 2, 0, num_piece(BLACK_BISHOP_CHAR));
    load_piece(board, 5, 0, num_piece(BLACK_BISHOP_CHAR));
    load_piece(board, 3, 0, num_piece(BLACK_QUEEN_CHAR));
    load_piece(board, 4, 0, num_piece(BLACK_KING_CHAR));

    load_piece(board, 0, 7, num_piece(WHITE_ROOK_CHAR));
    load_piece(board, 7, 7, num_piece(WHITE_ROOK_CHAR));
    load_piece(board, 1, 7, num_piece(WHITE_KNIGHT_CHAR));
    load_piece(board, 6, 7, num_piece(WHITE_KNIGHT_CHAR));
    load_piece(board, 2, 7, num_piece(WHITE_BISHOP_CHAR));
    load_piece(board, 5, 7, num_piece(WHITE_BISHOP_CHAR));
    load_piece(board, 3, 7, num_piece(WHITE_QUEEN_CHAR));
    load_piece(board, 4, 7, num_piece(WHITE_KING_CHAR));

}

int8_t score_peice(char peice){
    switch (peice) {
        case BLANK_CHAR:
            return BLANK_SCORE;
        case WHITE_PAWN_CHAR:
            return PAWN_SCORE;
        case WHITE_ROOK_CHAR:
            return ROOK_SCORE;
        case WHITE_BISHOP_CHAR:
            return BISHOP_SCORE;
        case WHITE_KNIGHT_CHAR:
            return KNIGHT_SCORE;
        case WHITE_QUEEN_CHAR:
            return QUEEN_SCORE;
        case WHITE_KING_CHAR:
            return KING_SCORE;
        case BLACK_PAWN_CHAR:
            return -PAWN_SCORE;
        case BLACK_ROOK_CHAR:
            return -ROOK_SCORE;
        case BLACK_BISHOP_CHAR:
            return -BISHOP_SCORE;
        case BLACK_KNIGHT_CHAR:
            return -KNIGHT_SCORE;
        case BLACK_QUEEN_CHAR:
            return -QUEEN_SCORE;
        case BLACK_KING_CHAR:
            return -KING_SCORE;
        default:
            return OTHER_SCORE;
    }
}

int8_t score_peice_number(uint8_t piece_num){
    switch (piece_num) {
        case BLANK_NUMBER:
            return BLANK_SCORE;
        case WHITE_PAWN_NUMBER:
            return PAWN_SCORE;
        case WHITE_ROOK_NUMBER:
            return ROOK_SCORE;
        case WHITE_BISHOP_NUMBER:
            return BISHOP_SCORE;
        case WHITE_KNIGHT_NUMBER:
            return KNIGHT_SCORE;
        case WHITE_QUEEN_NUMBER:
            return QUEEN_SCORE;
        case WHITE_KING_NUMBER:
            return KING_SCORE;
        case BLACK_PAWN_NUMBER:
            return -PAWN_SCORE;
        case BLACK_ROOK_NUMBER:
            return -ROOK_SCORE;
        case BLACK_BISHOP_NUMBER:
            return -BISHOP_SCORE;
        case BLACK_KNIGHT_NUMBER:
            return -KNIGHT_SCORE;
        case BLACK_QUEEN_NUMBER:
            return -QUEEN_SCORE;
        case BLACK_KING_NUMBER:
            return -KING_SCORE;
        default:
            return OTHER_SCORE;
    }
}

int8_t score_row(chessBoard board, int8_t row){
    int8_t sum = 0;
    sum += score_peice_number((uint8_t) (board[row] & BM_4_0 >> 28));
    sum += score_peice_number((uint8_t) (board[row] & BM_4_1 >> 24));
    sum += score_peice_number((uint8_t) (board[row] & BM_4_2 >> 20));
    sum += score_peice_number((uint8_t) (board[row] & BM_4_3 >> 16));
    sum += score_peice_number((uint8_t) (board[row] & BM_4_4 >> 12));
    sum += score_peice_number((uint8_t) (board[row] & BM_4_5 >> 8));
    sum += score_peice_number((uint8_t) (board[row] & BM_4_6 >> 4));
    sum += score_peice_number((uint8_t) (board[row] & BM_4_7));
    return sum;
}

int8_t score_board(chessBoard board){
    int8_t sum = 0;
    sum += score_row(board, 0);
    sum += score_row(board, 1);
    sum += score_row(board, 2);
    sum += score_row(board, 3);
    sum += score_row(board, 4);
    sum += score_row(board, 5);
    sum += score_row(board, 6);
    sum += score_row(board, 7);
    return sum;
}

int8_t peice_number_is_black(uint8_t piece_num){
    switch (piece_num) {
        case BLACK_PAWN_NUMBER:
            return 1;
        case BLACK_ROOK_NUMBER:
            return 1;
        case BLACK_BISHOP_NUMBER:
            return 1;
        case BLACK_KNIGHT_NUMBER:
            return 1;
        case BLACK_QUEEN_NUMBER:
            return 1;
        case BLACK_KING_NUMBER:
            return 1;
        default:
            return 0;
    }
}

int8_t peice_number_is_white(uint8_t piece_num){
    switch (piece_num) {
        case WHITE_PAWN_NUMBER:
            return 1;
        case WHITE_ROOK_NUMBER:
            return 1;
        case WHITE_BISHOP_NUMBER:
            return 1;
        case WHITE_KNIGHT_NUMBER:
            return 1;
        case WHITE_QUEEN_NUMBER:
            return 1;
        case WHITE_KING_NUMBER:
            return 1;
        default:
            return 0;
    }
}

int8_t peice_number_is_blank(uint8_t piece_num){
    return !piece_num;
}