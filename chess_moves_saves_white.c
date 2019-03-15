//
// Created by wills on 3/12/2019.
// Contains functions for generating White moves using a save
//

#include <stdlib.h>
#include <stdio.h>
#include "chess_board.h"
#include "chess_moves.h"
#include "chess_moves_saves_white.h"

/**
 * Given a board @param board and a move save @param save
 * Generates the next move of a white pawn, at the location in @param save
 * @param board The board used to calculate the move
 * @param move The move to setup
 * @param save The save to use in calculating the next move
 */
void get_moves_white_pawn_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (save->X < 7 && save->Y < 7 &&
            peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
            save->done = 0;
        } else if (save->X > 0 && save->Y < 7 &&
                   peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
            save->done = 0;
        } else if (save->Y < 7 &&
                   peice_number_is_blank(get_piece(board, save->X, save->Y - 1))) {
            save->moveY = save->Y - 1;
            save->moveX = save->X;
            save->done = 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX == save->X + 1) {
        if (save->X > 0 && save->Y < 7 &&
            peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveY = save->Y - 1;
            save->moveX = save->X - 1;
            save->done = 0;
        } else if (save->Y < 7 &&
                   peice_number_is_blank(get_piece(board, save->X, save->Y - 1))) {
            save->moveY = save->Y - 1;
            save->moveX = save->X;
            save->done = 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX == save->X - 1) {
        if (save->Y < 7 &&
            peice_number_is_blank(get_piece(board, save->X, save->Y - 1))) {
            save->moveY = save->Y - 1;
            save->moveX = save->X;
            save->done = 1;
        } else {
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
}

/**
 * Given a board @param board and a move save @param save
 * Generates the next move of a white rook, at the location in @param save
 * @param board The board used to calculate the move
 * @param move The move to setup
 * @param save The save to use in calculating the next move
 */
void get_moves_white_rook_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (save->moveX < 7 && !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
        } else if (save->X > 0 && !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
        } else if (save->Y < 7 && !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 && !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X) {
        if (save->moveX < 7 && (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->Y)))) {
            save->moveX = save->moveX + 1;
        } else if (save->X > 0 && !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
        } else if (save->Y < 7 && !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 && !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X) {
        if (save->moveX > 0 && (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->Y)))) {
            save->moveX = save->moveX - 1;
        } else if (save->Y < 7 && !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 && !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveY > save->Y) {
        if (save->moveY < 7 && (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->X, save->moveY + 1)))) {
            save->moveY = save->moveY + 1;
        } else if (save->Y > 0 && !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY < save->Y) {
        if (save->moveY > 0 && (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->X, save->moveY - 1)))) {
            save->moveY = save->moveY - 1;
        } else {
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

/**
 * Given a board @param board and a move save @param save
 * Generates the next move of a white bishop, at the location in @param save
 * @param board The board used to calculate the move
 * @param move The move to setup
 * @param save The save to use in calculating the next move
 */
void get_moves_white_bishop_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (save->moveX < 7 && save->moveY < 7 &&
            !peice_number_is_white(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   save->Y < 7 && !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   save->Y > 0 && !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X + 1 < 7 &&
                   save->Y > 0 && !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY > save->Y) {
        if (save->moveX < 7 && save->moveY < 7 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->moveY + 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY + 1;
        } else if (save->X > 0 &&
                   save->Y < 7 && !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   save->Y > 0 && !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   save->Y > 0 && !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY > save->Y) {
        if (save->moveX > 0 && save->moveY < 7 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->moveY + 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY + 1;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY < save->Y) {
        if (save->moveX > 0 && save->moveY > 0 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->moveY - 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY < save->Y) {
        if (save->moveX < 7 && save->moveY > 0 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->moveY - 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY - 1;
        } else {
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

/**
 * Given a board @param board and a move save @param save
 * Generates the next move of a white knight, at the location in @param save
 * @param board The board used to calculate the move
 * @param move The move to setup
 * @param save The save to use in calculating the next move
 */
void get_moves_white_knight_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveY == save->Y && save->moveX == save->X) {
        if (save->X < 7 && save->Y < 6 &&
            !peice_number_is_white(get_piece(board, save->X + 1, save->Y + 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 2;
        } else if (save->X > 0 && save->Y < 6 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 2;
        } else if (save->X > 1 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (save->X > 1 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (save->X > 0 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 2 && save->moveX == save->X + 1) {
        if (save->X > 0 && save->Y < 6 &&
            !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 2;
        } else if (save->X > 1 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (save->X > 1 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (save->X > 0 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 2 && save->moveX == save->X - 1) {
        if (save->X > 1 && save->Y < 7 &&
            !peice_number_is_white(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (save->X > 1 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (save->X > 0 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 1 && save->moveX == save->X - 2) {
        if (save->X > 1 && save->Y > 0 &&
            !peice_number_is_white(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (save->X > 0 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X - 2) {
        if (save->X > 0 && save->Y > 1 &&
            !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 2 && save->moveX == save->X - 1) {
        if (save->X < 7 && save->Y > 1 &&
            !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 2 && save->moveX == save->X + 1) {
        if (save->X < 6 && save->Y > 0 &&
            !peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X + 2) {
        if (save->X < 6 && save->Y < 7 &&
            !peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else {
        save->done = 2;
        return;
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

/**
 * Given a board @param board and a move save @param save
 * Generates the next move of a white queen, at the location in @param save
 * @param board The board used to calculate the move
 * @param move The move to setup
 * @param save The save to use in calculating the next move
 */
void get_moves_white_queen_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (save->X < 7 && save->Y < 7 &&
            !peice_number_is_white(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if ( save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY > save->Y) {
        if (save->moveX < 7 && save->moveY < 7 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->moveY + 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY + 1;
        } else if (save->X > 0 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                    !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY > save->Y) {
        if (save->moveX > 0 && save->moveY < 7 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->moveY + 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY + 1;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY < save->Y) {
        if (save->moveX > 0 && save->moveY > 0 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->moveY - 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY < save->Y) {
        if (save->moveX < 7 && save->moveY > 0 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->moveY - 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X) {
        if (save->moveX < 7 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->Y)))) {
            save->moveY = save->Y;
            save->moveX = save->moveX + 1;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X) {
        if (save->moveX > 0 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->Y)))) {
            save->moveY = save->Y;
            save->moveX = save->moveX - 1;
        } else if (save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveY > save->Y) {
        if (save->moveY < 7 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->X, save->moveY + 1)))) {
            save->moveX = save->X;
            save->moveY = save->moveY + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY < save->Y) {
        if (save->moveY > 0 &&
            (!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->X, save->moveY - 1)))) {
            save->moveX = save->X;
            save->moveY = save->moveY - 1;
        } else {
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

/**
 * Given a board @param board and a move save @param save
 * Generates the next move of a white king, at the location in @param save
 * @param board The board used to calculate the move
 * @param move The move to setup
 * @param save The save to use in calculating the next move
 */
void get_moves_white_king_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveY == save->Y && save->moveX == save->X) {
        if (save->X < 7 && save->Y < 7 &&
            !peice_number_is_white(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 1 && save->moveX == save->X + 1) {
        if (save->Y < 7 &&
            !peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y < 7 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 1 && save->moveX == save->X) {
        if (save->X > 0 && save->Y < 7 &&
            !peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 1 && save->moveX == save->X - 1) {
        if (save->X > 0 &&
            !peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y && save->moveX == save->X - 1) {
        if (save->X > 0 && save->Y > 0 &&
            !peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X - 1) {
        if (save->Y > 0 &&
            !peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X) {
        if (save->X < 7 && save->Y > 0 &&
            !peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X + 1) {
        if (save->X < 7 &&
            !peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else {
        save->done = 2;
        return;
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

/**
 * Given a board @param board and a move save @param save
 * Generates the next move of a white piece
 * @param board The board used to calculate the move
 * @param move The move to setup
 * @param save The save to use in calculating the next move
 */
void get_moves_white_save(chessBoard board, chessMove *move, chessMoveSave save) {
    uint8_t piece_num;
    if (save->done) {
        if (save->X >= 7) {
            if (save->Y >= 7) {
                save->done = 3;
                return;
            }
            save->X = 0;
            save->Y++;
        } else {
            save->X++;
        }
        save->moveY = save->Y;
        save->moveX = save->X;
        save->done = 0;
    }
    piece_num = get_piece(board, save->X, save->Y);
    switch (piece_num) {
        case WHITE_PAWN_NUMBER:
            get_moves_white_pawn_save(board, move, save);
            break;
        case WHITE_ROOK_NUMBER:
            get_moves_white_rook_save(board, move, save);
            break;
        case WHITE_BISHOP_NUMBER:
            get_moves_white_bishop_save(board, move, save);
            break;
        case WHITE_KNIGHT_NUMBER:
            get_moves_white_knight_save(board, move, save);
            break;
        case WHITE_QUEEN_NUMBER:
            get_moves_white_queen_save(board, move, save);
            break;
        case WHITE_KING_NUMBER:
            get_moves_white_king_save(board, move, save);
            break;
        default:
            save->done = 2;
            break;
    }
    if (save->done == 2) {
        get_moves_white_save(board, move, save);
    }
}
