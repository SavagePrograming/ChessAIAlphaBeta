//
// Created by wills on 3/12/2019.
//


#include <stdlib.h>
#include <stdio.h>
#include "chess_board.h"
#include "chess_moves.h"
#include "chess_moves_saves_white.h"

void get_moves_black_pawn_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
//        printf("1>");
        if (save->moveX < 7 && save->moveY > 0 &&
            peice_number_is_white(get_piece(board, save->X + 1, save->Y + 1))) {
//            printf("1>\n");
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
            save->done = 0;
        } else if (save->moveX > 0 && save->moveY > 0 &&
                   peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
//            printf("2>\n");
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
            save->done = 0;
        } else if (save->moveY > 0 &&
                   peice_number_is_blank(get_piece(board, save->X, save->Y + 1))) {
//            printf("3>\n");
            save->moveY = save->Y + 1;
            save->moveX = save->X;
            save->done = 1;
        } else {
//            printf("4>\n");
            save->done = 2;
            return;
        }
    } else if (save->moveX == save->X + 1) {
//        printf("2>");
        if (save->moveX > 0 && save->moveY > 0 &&
            peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
//            printf("2>\n");
            save->moveX = save->X - 1;
            save->done = 0;
        } else if (save->moveY > 0 &&
                   peice_number_is_blank(get_piece(board, save->X, save->Y + 1))) {
//            printf("3>\n");
            save->moveX = save->X;
            save->done = 1;
        } else {
//            printf("4>\n");
            save->done = 2;
            return;
        }
    } else if (save->moveX == save->X - 1) {
//        printf("3>");
        if (save->moveY > 0 &&
            peice_number_is_blank(get_piece(board, save->X, save->Y + 1))) {
//            printf("3>\n");
            save->moveX = save->X;
            save->done = 1;
        } else {
//            printf("4>\n");
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
}

void get_moves_black_rook_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        printf("1>");
        if (save->X < 7 && !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            printf("1>\n");
            save->moveX = save->X + 1;
        } else if (save->X > 0 && !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            printf("2>\n");
            save->moveX = save->X - 1;
        } else if (save->Y < 7 && !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            printf("3>\n");
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 && !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            printf("4>\n");
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            printf("5>\n");
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X) {
        printf("2>");
        if (save->moveX < 7 && (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->Y)))) {
            printf("1>\n");
            save->moveX = save->moveX + 1;
        } else if (save->X > 0 && !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            printf("2>\n");
            save->moveX = save->X - 1;
        } else if (save->Y < 7 && !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            printf("3>\n");
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 && !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            printf("4>\n");
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            printf("5>\n");
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X) {
//        printf("3>");
        if (save->moveX > 0 && (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->Y)))) {
//            printf("2>\n");
            save->moveX = save->moveX - 1;
        } else if (save->Y < 7 && !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
//            printf("3>\n");
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 && !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
//            printf("4>\n");
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
//            printf("5>\n");
            save->done = 2;
            return;
        }

    } else if (save->moveY > save->Y) {
        printf("4>");
        if (save->moveY < 7 && (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->X, save->moveY + 1)))) {
            printf("3>\n");
            save->moveY = save->moveY + 1;
        } else if (save->Y < 0 && !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            printf("4>\n");
            save->moveY = save->Y - 1;
        } else {
            printf("5>\n");
            save->done = 2;
            return;
        }
    } else if (save->moveY < save->Y) {
//        printf("5>");
        if (save->moveY > 0 && (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
             (!peice_number_is_black(get_piece(board, save->X, save->moveY - 1)))) {
//            printf("4>\n");
            save->moveY = save->moveY - 1;
        } else {
//            printf("5>\n");
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}


void get_moves_black_bishop_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        printf("1>");
        if (save->moveX < 7 && save->moveY < 7 &&
            !peice_number_is_black(get_piece(board, save->X + 1, save->Y + 1))) {
            printf("1>\n");
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   save->Y < 7 && !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            printf("2>\n");
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   save->Y > 0 && !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            printf("3>\n");
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X + 1 < 7 &&
                   save->Y > 0 && !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            printf("4>\n");
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            printf("5>\n");
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY > save->Y) {
        printf("2>");
        if (save->moveX < 7 && save->moveY < 7 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->moveY + 1)))) {
            printf("1>\n");
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY + 1;
        } else if (save->X > 0 &&
                   save->Y < 7 && !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            printf("2>\n");
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   save->Y > 0 && !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            printf("3>\n");
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   save->Y > 0 && !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            printf("4>\n");
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY > save->Y) {
        printf("3>");
        if (save->moveX > 0 && save->moveY < 7 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->moveY + 1)))) {
            printf("2>\n");
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY + 1;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            printf("3>\n");
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            printf("4>\n");
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY < save->Y) {
        printf("4>");
        if (save->moveX > 0 && save->moveY > 0 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->moveY - 1)))) {
            printf("3>\n");
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            printf("4>\n");
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            printf("5>\n");
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY < save->Y) {
        printf("5>");
        if (save->moveX < 7 && save->moveY > 0 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->moveY - 1)))) {
            printf("4>\n");
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY - 1;
        } else {
            printf("5>\n");
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

void get_moves_black_knight_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveY == save->Y && save->moveX == save->X) {
        if (save->X < 7 && save->Y < 6 &&
            !peice_number_is_black(get_piece(board, save->X + 1, save->Y + 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 2;
        } else if (save->X > 0 && save->Y < 6 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 2;
        } else if (save->X > 1 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (save->X > 1 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (save->X > 0 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 2 && save->moveX == save->X + 1) {
        if (save->X > 0 && save->Y < 6 &&
            !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 2;
        } else if (save->X > 1 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (save->X > 1 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (save->X > 0 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 2 && save->moveX == save->X - 1) {
        if (save->X > 1 && save->Y < 7 &&
            !peice_number_is_black(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (save->X > 1 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (save->X > 0 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 1 && save->moveX == save->X - 2) {
        if (save->X > 1 && save->Y > 0 &&
            !peice_number_is_black(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (save->X > 0 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X - 2) {
        if (save->X > 0 && save->Y > 1 &&
            !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 7 && save->Y > 1 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 2 && save->moveX == save->X - 1) {
        if (save->X < 7 && save->Y > 1 &&
            !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (save->X < 6 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 2 && save->moveX == save->X + 1) {
        if (save->X < 6 && save->Y > 0 &&
            !peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (save->X < 6 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X + 2) {
        if (save->X < 6 && save->Y < 7 &&
            !peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
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

void get_moves_black_queen_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (save->X < 7 && save->Y < 7 &&
            !peice_number_is_black(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY > save->Y) {
        if (save->moveX < 7 && save->moveY < 7 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->moveY + 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY + 1;
        } else if (save->X > 0 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY > save->Y) {
        if (save->moveX > 0 && save->moveY < 7 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->moveY + 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY + 1;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY < save->Y) {
        if (save->moveX > 0 && save->moveY > 0 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->moveY - 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY < save->Y) {
        if (save->moveX < 7 && save->moveY > 0 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->moveY - 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X) {
        if (save->moveX < 7 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->Y)))) {
            save->moveY = save->Y;
            save->moveX = save->moveX + 1;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X) {
        if (save->moveX > 0 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->Y)))) {
            save->moveY = save->Y;
            save->moveX = save->moveX - 1;
        } else if (save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveY > save->Y) {
        if (save->moveY < 7 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->X, save->moveY + 1)))) {
            save->moveX = save->X;
            save->moveY = save->moveY + 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY < save->Y) {
        if (save->moveY > 0 &&
            (!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->X, save->moveY - 1)))) {
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

void get_moves_black_king_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveY == save->Y && save->moveX == save->X) {
        if (save->X < 7 && save->Y < 7 &&
            !peice_number_is_black(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 1 && save->moveX == save->X + 1) {
        if (save->Y < 7 &&
            !peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 && save->Y < 7 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 1 && save->moveX == save->X) {
        if (save->X > 0 && save->Y < 7 &&
            !peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (save->X > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y + 1 && save->moveX == save->X - 1) {
        if (save->X > 0 &&
            !peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (save->X > 0 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y && save->moveX == save->X - 1) {
        if (save->X > 0 && save->Y > 0 &&
            !peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X - 1) {
        if (save->Y > 0 &&
            !peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 && save->Y > 0 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X) {
        if (save->X < 7 && save->Y > 0 &&
            !peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (save->X < 7 &&
                   !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY == save->Y - 1 && save->moveX == save->X + 1) {
        if (save->X < 7 &&
            !peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
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

void get_moves_black_save(chessBoard board, chessMove *move, chessMoveSave save) {
    uint8_t piece_num;
    printf("Testing (%d, %d) (%d, %d) > %d   %d\n", save->X, save->Y, save->moveX, save->moveY,
           get_piece(board, save->X, save->Y), save->done);
//    printf("Testing %d %d\n", save->X, save->Y);
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
        case BLACK_PAWN_NUMBER:
            printf("PAWN");
            get_moves_black_pawn_save(board, move, save);
            break;
        case BLACK_ROOK_NUMBER:
            printf("ROOK");
            get_moves_black_rook_save(board, move, save);
            break;
        case BLACK_BISHOP_NUMBER:
            printf("BISHOP");
            get_moves_black_bishop_save(board, move, save);
            break;
        case BLACK_KNIGHT_NUMBER:
            printf("KNIGHT");
            get_moves_black_knight_save(board, move, save);
            break;
        case BLACK_QUEEN_NUMBER:
            printf("QUEEN");
            get_moves_black_queen_save(board, move, save);
            break;
        case BLACK_KING_NUMBER:
            printf("KING");
            get_moves_black_king_save(board, move, save);
            break;
        default:
            save->done = 2;
            break;
    }
    if (save->done == 2) {
        get_moves_black_save(board, move, save);
    }
}
