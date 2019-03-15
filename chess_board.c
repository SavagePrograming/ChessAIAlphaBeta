//
// Created by wills on 2/9/2019X
// Contains Functions for working on a compressed chess board chess pieces are stored as nibbles
//
#include <stdio.h>
#include <stdint.h>
#include "chess_board.h"

//Constant Bitmaps for pulling chess pieces out of a row
#define BM_4_7 (u_int32_t)0b00000000000000000000000000001111
#define BM_4_6 (u_int32_t)0b00000000000000000000000011110000
#define BM_4_5 (u_int32_t)0b00000000000000000000111100000000
#define BM_4_4 (u_int32_t)0b00000000000000001111000000000000
#define BM_4_3 (u_int32_t)0b00000000000011110000000000000000
#define BM_4_2 (u_int32_t)0b00000000111100000000000000000000
#define BM_4_1 (u_int32_t)0b00001111000000000000000000000000
#define BM_4_0 (u_int32_t)0b11110000000000000000000000000000

/**
 * Function for getting a piece out of a chess board
 * @param board The board to get the piece from
 * @param x The x location (column) of the piece
 * @param y The y location (row) of the piece
 * @return The piece number of the piece at (x,y) in board
 */
uint8_t get_piece(chessBoard board, uint8_t x, uint8_t y) {
    switch (x) {
        case 0:
            return (uint8_t)((BM_4_0 & board[y]) >> 28);
        case 1:
            return (uint8_t)((BM_4_1 & board[y]) >> 24);
        case 2:
            return (uint8_t)((BM_4_2 & board[y]) >> 20);
        case 3:
            return (uint8_t)((BM_4_3 & board[y]) >> 16);
        case 4:
            return (uint8_t)((BM_4_4 & board[y]) >> 12);
        case 5:
            return (uint8_t)((BM_4_5 & board[y]) >> 8);
        case 6:
            return (uint8_t)((BM_4_6 & board[y]) >> 4);
        default:
            return (uint8_t)((BM_4_7 & board[y]));
    }
}

/**
 * Loads a piece into a location in a board
 * @param board The board to load the piece into
 * @param x The x location (column) of the space to load
 * @param y The y location (row) of the space to load
 * @param piece_number The piece number to load into the space
 */
void load_piece(chessBoard board, uint8_t x, uint8_t y, uint8_t piece_number) {
    switch (x) {
        case 0:
            board[y] = (board[y] & ~BM_4_0) | (piece_number << 28);
            break;
        case 1:
            board[y] = (board[y] & ~BM_4_1) | (piece_number << 24);
            break;
        case 2:
            board[y] = (board[y] & ~BM_4_2) | (piece_number << 20);
            break;
        case 3:
            board[y] = (board[y] & ~BM_4_3) | (piece_number << 16);
            break;
        case 4:
            board[y] = (board[y] & ~BM_4_4) | (piece_number << 12);
            break;
        case 5:
            board[y] = (board[y] & ~BM_4_5) | (piece_number << 8);
            break;
        case 6:
            board[y] = (board[y] & ~BM_4_6) | (piece_number << 4);
            break;
        default:
            board[y] = (board[y] & ~BM_4_7) | piece_number;
            break;
    }
}

/**
 * Coverts a piece number into the piece character that it responds to
 * @param piece_number The piece number to convert
 * @return The piece character for that piece
 */
char get_piece_char_from_number(uint8_t piece_number) {
    switch (piece_number) {
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

/**
 * Coverts a piece character into a piece number
 * @param piece_char The character to convert
 * @return The piece number that matches with the character
 */
uint8_t get_piece_number_from_char(char piece_char) {
    switch (piece_char) {
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

/**
 * Prints a chess board on to standard out
 * @param board The board to print
 */
void print_board(chessBoard board) {
    for (char y = 0; y < 8; y++) {
        if (y % 2 == 0) {
            printf("|     XXXXX     XXXXX     XXXXX     XXXXX|\n|");
        } else {
            printf("|XXXXX     XXXXX     XXXXX     XXXXX     |\n|");
        }
        for (char x = 0; x < 8; x++) {
            uint8_t piece = get_piece(board, x, y);
            if (piece == 0) {
                if ((x + y) % 2 == 0) {
                    printf("     ");
                } else {
                    printf("XXXXX");
                }
            } else {
                if ((x + y) % 2 == 0) {
                    printf("  %c  ", get_piece_char_from_number(piece));
                } else {
                    printf("X %c X", get_piece_char_from_number(piece));
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

/**
 * Sets all spaces on the chess board to empty
 * @param board The board to score
 */
void clear_board(chessBoard board){
    for (uint8_t i = 0; i < 8; i++){
        board[i] = 0;
    }
}

/**
 * Sets a chess board up with the standard starting positions
 * @param board The board to set up on
 */
void start_board(chessBoard board){
    for (uint8_t x = 0; x < 8; x++){
        load_piece(board, x, 1, get_piece_number_from_char(BLACK_PAWN_CHAR));
        load_piece(board, x, 6, get_piece_number_from_char(WHITE_PAWN_CHAR));
    }
    load_piece(board, 0, 0, get_piece_number_from_char(BLACK_ROOK_CHAR));
    load_piece(board, 7, 0, get_piece_number_from_char(BLACK_ROOK_CHAR));
    load_piece(board, 1, 0, get_piece_number_from_char(BLACK_KNIGHT_CHAR));
    load_piece(board, 6, 0, get_piece_number_from_char(BLACK_KNIGHT_CHAR));
    load_piece(board, 2, 0, get_piece_number_from_char(BLACK_BISHOP_CHAR));
    load_piece(board, 5, 0, get_piece_number_from_char(BLACK_BISHOP_CHAR));
    load_piece(board, 3, 0, get_piece_number_from_char(BLACK_QUEEN_CHAR));
    load_piece(board, 4, 0, get_piece_number_from_char(BLACK_KING_CHAR));

    load_piece(board, 0, 7, get_piece_number_from_char(WHITE_ROOK_CHAR));
    load_piece(board, 7, 7, get_piece_number_from_char(WHITE_ROOK_CHAR));
    load_piece(board, 1, 7, get_piece_number_from_char(WHITE_KNIGHT_CHAR));
    load_piece(board, 6, 7, get_piece_number_from_char(WHITE_KNIGHT_CHAR));
    load_piece(board, 2, 7, get_piece_number_from_char(WHITE_BISHOP_CHAR));
    load_piece(board, 5, 7, get_piece_number_from_char(WHITE_BISHOP_CHAR));
    load_piece(board, 3, 7, get_piece_number_from_char(WHITE_QUEEN_CHAR));
    load_piece(board, 4, 7, get_piece_number_from_char(WHITE_KING_CHAR));

    for (uint8_t i = 2; i < 6; i++){
        board[i] = 0;
    }

}

/**
 * Sets up a board with the standard start positions minus the pawns
 * used for testing
 * @param board The board to set up on
 */
void start_board_no_pawns(chessBoard board){

    for (uint8_t i = 0; i < 8; i++){
        board[i] = 0;
    }

    load_piece(board, 0, 0, get_piece_number_from_char(BLACK_ROOK_CHAR));
    load_piece(board, 7, 0, get_piece_number_from_char(BLACK_ROOK_CHAR));
    load_piece(board, 1, 0, get_piece_number_from_char(BLACK_KNIGHT_CHAR));
    load_piece(board, 6, 0, get_piece_number_from_char(BLACK_KNIGHT_CHAR));
    load_piece(board, 2, 0, get_piece_number_from_char(BLACK_BISHOP_CHAR));
    load_piece(board, 5, 0, get_piece_number_from_char(BLACK_BISHOP_CHAR));
    load_piece(board, 3, 0, get_piece_number_from_char(BLACK_QUEEN_CHAR));
    load_piece(board, 4, 0, get_piece_number_from_char(BLACK_KING_CHAR));

    load_piece(board, 0, 7, get_piece_number_from_char(WHITE_ROOK_CHAR));
    load_piece(board, 7, 7, get_piece_number_from_char(WHITE_ROOK_CHAR));
    load_piece(board, 1, 7, get_piece_number_from_char(WHITE_KNIGHT_CHAR));
    load_piece(board, 6, 7, get_piece_number_from_char(WHITE_KNIGHT_CHAR));
    load_piece(board, 2, 7, get_piece_number_from_char(WHITE_BISHOP_CHAR));
    load_piece(board, 5, 7, get_piece_number_from_char(WHITE_BISHOP_CHAR));
    load_piece(board, 3, 7, get_piece_number_from_char(WHITE_QUEEN_CHAR));
    load_piece(board, 4, 7, get_piece_number_from_char(WHITE_KING_CHAR));
}

/**
 * Gets the score of a single piece character
 * @param peice_char The peice character to be scored
 * @return The score of @param peice_char
 */
int8_t score_peice_char(char peice_char){
    switch (peice_char) {
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

/**
 * Scores a piece number
 * @param piece_number The piece number to be score
 * @return The score of the piece number
 */
int8_t score_peice_number(uint8_t piece_number){
    switch (piece_number) {
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

/**
 * Scores an entire row
 * @param board The board where the row comes from
 * @param row_index The index of the row to score
 * @return The score of the row
 */
int8_t score_row(chessBoard board, int8_t row_index){
    int8_t sum = 0;
    sum += score_peice_number((uint8_t) (board[row_index] & BM_4_0 >> 28));
    sum += score_peice_number((uint8_t) (board[row_index] & BM_4_1 >> 24));
    sum += score_peice_number((uint8_t) (board[row_index] & BM_4_2 >> 20));
    sum += score_peice_number((uint8_t) (board[row_index] & BM_4_3 >> 16));
    sum += score_peice_number((uint8_t) (board[row_index] & BM_4_4 >> 12));
    sum += score_peice_number((uint8_t) (board[row_index] & BM_4_5 >> 8));
    sum += score_peice_number((uint8_t) (board[row_index] & BM_4_6 >> 4));
    sum += score_peice_number((uint8_t) (board[row_index] & BM_4_7));
    return sum;
}

/**
 * Scores an entire board
 * @param board The board to score
 * @return The score of the board
 */
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

/**
 * Tests if a piece is black
 * @param piece_number The piece number to check
 * @return True if the piece is black
 */
int8_t peice_number_is_black(uint8_t piece_number){
    switch (piece_number) {
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

/**
 * Tests if the piece is white
 * @param piece_number The number of the piece to check
 * @return True is the piece is white
 */
int8_t peice_number_is_white(uint8_t piece_number){
    switch (piece_number) {
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

/**
 * Tests if a piece is blank
 * @param piece_number The number of the piece to check
 * @return True if the piece is blank
 */
int8_t peice_number_is_blank(uint8_t piece_number){
    return piece_number == BLANK_NUMBER;
}