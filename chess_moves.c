//
// Created by wills on 2/9/2019.
// Contains functions for generating arrays of possible moves
// Contains functions for running moves on a board
// Contains functions for making a new move struct
//

#include <stdlib.h>
#include <stdio.h>
#include "chess_board.h"
#include "chess_moves.h"

#define MOVES_LENGTH 250

/**
 * Sets up a move given the data to put into it
 * @param new The address of the move to be setup
 * @param start_x The starting x location of the move
 * @param start_y The starting y location of the move
 * @param end_x The ending x location of the move
 * @param end_y The ending y location of the move
 * @param taken The piece that will be taken if the move is made
 */
void make_chess_move(chessMove *new, uint8_t start_x, uint8_t start_y,
                     uint8_t end_x, uint8_t end_y, uint8_t taken) {
    new->startX = start_x;
    new->startY = start_y;
    new->endX = end_x;
    new->endY = end_y;
    new->taken = taken;
}

/**
 * Sets up a move given the data, and using a board to find the taken piece
 * @param new The address of the move to be setup
 * @param start_x The starting x location of the move
 * @param start_y The starting y location of the move
 * @param end_x The ending x location of the move
 * @param end_y The ending y location of the move
 * @param board The board which the move will be made on
 */
void make_chess_move_board(chessMove *new, uint8_t start_x, uint8_t start_Y,
                           uint8_t end_x, uint8_t end_y, chessBoard board) {
    new->startX = start_x;
    new->startY = start_Y;
    new->endX = end_x;
    new->endY = end_y;
    new->taken = get_piece(board, end_x, end_y);
}

/**
 * Given a board @param board,
 * Generates all of the moves of a white pawn at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_white_pawn(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    if (x < 7 && y < 7 && peice_number_is_black(get_piece(board, x + 1, y + 1))) {
        make_chess_move_board(moves + *size, x, y, x + 1, y + 1, board);
        (*size)++;
    }
    if (x > 0 && y < 7 && peice_number_is_black(get_piece(board, x - 1, y + 1))) {
        make_chess_move_board(moves + *size, x, y, x - 1, y + 1, board);
        (*size)++;
    }
    if (y < 7 && peice_number_is_blank(get_piece(board, x, y + 1))) {
        make_chess_move_board(moves + *size, x, y, x, y + 1, board);
        (*size)++;
    }
}

/**
 * Given a board @param board,
 * Generates all of the moves of a white rook at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_white_rook(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;
    for (uint8_t newX = x + 1; newX < 8; newX++) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newX = x - 1; newX >= 0; newX--) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y + 1; newY < 8; newY++) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y - 1; newY >= 0; newY--) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }
}


/**
 * Given a board @param board,
 * Generates all of the moves of a white bishop at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_white_bishop(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;


    uint8_t newX = x + 1;
    uint8_t newY = y + 1;
    while (newX < 8 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY++;
    }

    newX = x - 1;
    newY = y - 1;
    while (newX >= 0 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY--;
    }


    newX = x - 1;
    newY = y + 1;
    while (newX >= 0 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY++;
    }


    newX = x + 1;
    newY = y - 1;
    while (newX < 8 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY--;
    }
}


/**
 * Given a board @param board,
 * Generates all of the moves of a white knight at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_white_knight(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;
    if (x < 7) {
        if (y < 6) {
            piece = get_piece(board, x + 1, y + 2);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y + 2, board);
                (*size)++;
            }
        }
        if (y > 1) {
            piece = get_piece(board, x + 1, y - 2);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y - 2, board);
                (*size)++;
            }
        }
        if (x < 6) {
            if (y < 7) {
                piece = get_piece(board, x + 2, y + 1);
                if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                    make_chess_move_board(moves + *size, x, y, x + 2, y + 1, board);
                    (*size)++;
                }
            }
            if (y > 0) {
                piece = get_piece(board, x + 2, y - 1);
                if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                    make_chess_move_board(moves + *size, x, y, x + 2, y - 1, board);
                    (*size)++;
                }
            }
        }
    }
    if (x > 0) {
        if (y < 6) {
            piece = get_piece(board, x - 1, y + 2);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y + 2, board);
                (*size)++;
            }
        }
        if (y > 1) {
            piece = get_piece(board, x - 1, y - 2);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y - 2, board);
                (*size)++;
            }
        }
        if (x > 1) {
            if (y < 7) {
                piece = get_piece(board, x - 2, y + 1);
                if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                    make_chess_move_board(moves + *size, x, y, x - 2, y + 1, board);
                    (*size)++;
                }
            }
            if (y > 0) {
                piece = get_piece(board, x - 2, y - 1);
                if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                    make_chess_move_board(moves + *size, x, y, x - 2, y - 1, board);
                    (*size)++;
                }
            }
        }
    }
}


/**
 * Given a board @param board,
 * Generates all of the moves of a white queen at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_white_queen(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;
    for (uint8_t newX = x + 1; newX < 8; newX++) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newX = x - 1; newX >= 0; newX--) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y + 1; newY < 8; newY++) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y - 1; newY >= 0; newY--) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }


    uint8_t newX = x + 1;
    uint8_t newY = y + 1;
    while (newX < 8 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY++;
    }

    newX = x - 1;
    newY = y - 1;
    while (newX >= 0 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY--;
    }


    newX = x - 1;
    newY = y + 1;
    while (newX >= 0 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY++;
    }


    newX = x + 1;
    newY = y - 1;
    while (newX < 8 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY--;
    }
}


/**
 * Given a board @param board,
 * Generates all of the moves of a white king at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_white_king(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;
    if (x > 0) {
        piece = get_piece(board, x - 1, y);
        if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x - 1, y, board);
            (*size)++;
        }
        if (y > 0) {
            piece = get_piece(board, x - 1, y - 1);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y - 1, board);
                (*size)++;
            }
        }
        if (y < 7) {
            piece = get_piece(board, x - 1, y);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y + 1, board);
                (*size)++;
            }
        }
    }
    if (x < 7) {
        piece = get_piece(board, x + 1, y);
        if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x + 1, y, board);
            (*size)++;
        }
        if (y > 0) {
            piece = get_piece(board, x + 1, y - 1);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y - 1, board);
                (*size)++;
            }
        }
        if (y < 7) {
            piece = get_piece(board, x + 1, y + 1);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y + 1, board);
                (*size)++;
            }
        }
    }
    if (y > 0) {
        piece = get_piece(board, x, y - 1);
        if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, y - 1, board);
            (*size)++;
        }
    }
    if (y < 7) {
        piece = get_piece(board, x, y + 1);
        if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, y + 1, board);
            (*size)++;
        }
    }
}

/**
 * Given a board @param board,
 * Generates all of the moves of a black pawn at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_black_pawn(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    if (x < 7 && y > 0 && peice_number_is_black(get_piece(board, x + 1, y - 1))) {
        make_chess_move_board(moves + *size, x, y, x + 1, y - 1, board);
        (*size)++;
    }
    if (x > 0 && y > 0 && peice_number_is_black(get_piece(board, x - 1, y - 1))) {
        make_chess_move_board(moves + *size, x, y, x - 1, y - 1, board);
        (*size)++;
    }
    if (y > 0 && peice_number_is_blank(get_piece(board, x, y - 1))) {
        make_chess_move_board(moves + *size, x, y, x, y - 1, board);
        (*size)++;
    }
}

/**
 * Given a board @param board,
 * Generates all of the moves of a black rook at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_black_rook(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;
    for (uint8_t newX = x + 1; newX < 8; newX++) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newX = x - 1; newX >= 0; newX--) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y + 1; newY < 8; newY++) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y - 1; newY >= 0; newY--) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }
}

/**
 * Given a board @param board,
 * Generates all of the moves of a black bishop at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_black_bishop(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;

    uint8_t newX = x + 1;
    uint8_t newY = y + 1;
    while (newX < 8 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY++;
    }

    newX = x - 1;
    newY = y - 1;
    while (newX >= 0 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY--;
    }


    newX = x - 1;
    newY = y + 1;
    while (newX >= 0 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY++;
    }


    newX = x + 1;
    newY = y - 1;
    while (newX < 8 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY--;
    }
}

/**
 * Given a board @param board,
 * Generates all of the moves of a black knight at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_black_knight(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;
    if (x < 7) {
        if (y < 6) {
            piece = get_piece(board, x + 1, y + 2);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y + 2, board);
                (*size)++;
            }
        }
        if (y > 1) {
            piece = get_piece(board, x + 1, y - 2);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y - 2, board);
                (*size)++;
            }
        }
        if (x < 6) {
            if (y < 7) {
                piece = get_piece(board, x + 2, y + 1);
                if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                    make_chess_move_board(moves + *size, x, y, x + 2, y + 1, board);
                    (*size)++;
                }
            }
            if (y > 0) {
                piece = get_piece(board, x + 2, y - 1);
                if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                    make_chess_move_board(moves + *size, x, y, x + 2, y - 1, board);
                    (*size)++;
                }
            }
        }
    }
    if (x > 0) {
        if (y < 6) {
            piece = get_piece(board, x - 1, y + 2);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y + 2, board);
                (*size)++;
            }
        }
        if (y > 1) {
            piece = get_piece(board, x - 1, y - 2);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y - 2, board);
                (*size)++;
            }
        }
        if (x > 1) {
            if (y < 7) {
                piece = get_piece(board, x - 2, y + 1);
                if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                    make_chess_move_board(moves + *size, x, y, x - 2, y + 1, board);
                    (*size)++;
                }
            }
            if (y > 0) {
                piece = get_piece(board, x - 2, y - 1);
                if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                    make_chess_move_board(moves + *size, x, y, x - 2, y - 1, board);
                    (*size)++;
                }
            }
        }
    }
}

/**
 * Given a board @param board,
 * Generates all of the moves of a black queen at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_black_queen(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;
    for (uint8_t newX = x + 1; newX < 8; newX++) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newX = x - 1; newX >= 0; newX--) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y + 1; newY < 8; newY++) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y - 1; newY >= 0; newY--) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }


    uint8_t newX = x + 1;
    uint8_t newY = y + 1;
    while (newX < 8 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY++;
    }

    newX = x - 1;
    newY = y - 1;
    while (newX >= 0 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY--;
    }


    newX = x - 1;
    newY = y + 1;
    while (newX >= 0 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY++;
    }


    newX = x + 1;
    newY = y - 1;
    while (newX < 8 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY--;
    }
}

/**
 * Given a board @param board,
 * Generates all of the moves of a black king at (@param x, @param y)
 * @param board The board to get the moves from
 * @param size A pointer to the first free index in @param moves
 * @param x The x location of the piece to check
 * @param y The y location of the piece to check
 * @param moves The array to store the moves in
 */
void get_moves_black_king(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[MOVES_LENGTH]) {
    uint8_t piece;
    if (x > 0) {
        piece = get_piece(board, x - 1, y);
        if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x - 1, y, board);
            (*size)++;
        }
        if (y > 0) {
            piece = get_piece(board, x - 1, y - 1);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y - 1, board);
                (*size)++;
            }
        }
        if (y < 7) {
            piece = get_piece(board, x - 1, y);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y + 1, board);
                (*size)++;
            }
        }
    }
    if (x < 7) {
        piece = get_piece(board, x + 1, y);
        if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x + 1, y, board);
            (*size)++;
        }
        if (y > 0) {
            piece = get_piece(board, x + 1, y - 1);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y - 1, board);
                (*size)++;
            }
        }
        if (y < 7) {
            piece = get_piece(board, x + 1, y + 1);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y + 1, board);
                (*size)++;
            }
        }
    }
    if (y > 0) {
        piece = get_piece(board, x, y - 1);
        if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, y - 1, board);
            (*size)++;
        }
    }
    if (y < 7) {
        piece = get_piece(board, x, y + 1);
        if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, y + 1, board);
            (*size)++;
        }
    }
}

/**
 * Copies all the moves from a move array into a dynamically allocated array
 * @param moves The array to copy from
 * @param size The size of the array
 * @return A dynamically allocated array of moves of length size
 */
chessMove *copy_chess_moves_to_heap(chessMove *moves, uint8_t size) {
    chessMove *newMoveArray = malloc(size * sizeof(chessMove));
    for (uint8_t index = 0; index < size; index++) {
        newMoveArray[index].taken = moves[index].taken;
        newMoveArray[index].endY = moves[index].endY;
        newMoveArray[index].endX = moves[index].endX;
        newMoveArray[index].startY = moves[index].startY;
        newMoveArray[index].startX = moves[index].startX;
    }
    return newMoveArray;
}

/**
 * Given a board @param board,
 * Generates all of the white moves on a board
 * @param board The board to get the moves from
 * @param size A pointer to the size of the moves returned
 * @return A dynamically allocated array of moves
 */
chessMove * get_moves_white(chessBoard board, uint8_t *size) {
    chessMove moves[MOVES_LENGTH];
    *size = 0;
    uint8_t piece_num;
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 0; y < 8; y++) {
            piece_num = get_piece(board, x, y);
            switch (piece_num) {
                case WHITE_PAWN_NUMBER:
                    get_moves_white_pawn(board, size, x, y, moves);
                    break;
                case WHITE_ROOK_NUMBER:
                    get_moves_white_rook(board, size, x, y, moves);
                    break;
                case WHITE_BISHOP_NUMBER:
                    get_moves_white_bishop(board, size, x, y, moves);
                    break;
                case WHITE_KNIGHT_NUMBER:
                    get_moves_white_knight(board, size, x, y, moves);
                    break;
                case WHITE_QUEEN_NUMBER:
                    get_moves_white_queen(board, size, x, y, moves);
                    break;
                case WHITE_KING_NUMBER:
                    get_moves_white_king(board, size, x, y, moves);
                    break;
                default:
                    break;
            }
        }
    }
    return copy_chess_moves_to_heap(moves, *size);
}

/**
 * Given a board @param board,
 * Generates all of the black moves on a board
 * @param board The board to get the moves from
 * @param size A pointer to the size of the moves returned
 * @return A dynamically allocated array of moves
 */
chessMove * get_moves_black(chessBoard board, uint8_t *size) {
    chessMove moves[MOVES_LENGTH];
    *size = 0;
    uint8_t piece_num;
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 0; y < 8; y++) {
            piece_num = get_piece(board, x, y);
            switch (piece_num) {
                case BLACK_PAWN_NUMBER:
                    get_moves_black_pawn(board, size, x, y, moves);
                    break;
                case BLACK_ROOK_NUMBER:
                    get_moves_black_rook(board, size, x, y, moves);
                    break;
                case BLACK_BISHOP_NUMBER:
                    get_moves_black_bishop(board, size, x, y, moves);
                    break;
                case BLACK_KNIGHT_NUMBER:
                    get_moves_black_knight(board, size, x, y, moves);
                    break;
                case BLACK_QUEEN_NUMBER:
                    get_moves_black_queen(board, size, x, y, moves);
                    break;
                case BLACK_KING_NUMBER:
                    get_moves_black_king(board, size, x, y, moves);
                    break;
                default:
                    break;
            }
        }
    }
    return copy_chess_moves_to_heap(moves, *size);
}

/**
 * Runs a move on a board
 * @param board The board to be changed
 * @param move The move to run
 */
void run_chess_move(chessBoard board, chessMove move) {
    printf("%d\n", get_piece(board, move.startX, move.startY));
    load_piece(board, move.endX, move.endY, get_piece(board, move.startX, move.startY));
    load_piece(board, move.startX, move.startY, BLANK_NUMBER);
}

/**
 * Undoes a move
 * @param board The board to change back
 * @param move The move to undo
 */
void reverse_chess_move(chessBoard board, chessMove move) {
    load_piece(board, move.startX, move.startY, get_piece(board, move.endX, move.endY));
    load_piece(board, move.endX, move.endY, move.taken);
}

/**
 * Places the Other character at the target location of a move
 * Used for debugging moves
 * @param board The board to be changed
 * @param move The move to be highlighted
 */
void highlight_chess_move(chessBoard board, chessMove move) {
    load_piece(board, move.endX, move.endY, OTHER_NUMBER);
}

/**
 * Fixes a board after a highlight
 * @param board The board to fix
 * @param move The move to unhighlight
 */
void reverse_chess_move_highlight(chessBoard board, chessMove move) {
    load_piece(board, move.endX, move.endY, move.taken);
}

/**
 * Copies a move from one address to another
 * @param from the address to copy from
 * @param to the address to copy to
 */
void copy_move(chessMove * from, chessMove * to){
    to->endY = from->endY;
    to->endX = from->endX;
    to->startY = from->startY;
    to->startX = from->startX;
    to->taken = from->taken;
}