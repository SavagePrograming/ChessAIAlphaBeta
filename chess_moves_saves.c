//
// Created by wills on 3/12/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "chess_board.h"
#include "chess_moves.h"
#include "chess_moves_saves.h"

chessMoveSave makeStartingSave(){
    chessMoveSave new = malloc(sizeof(struct chess_move_save));
    new->Y = 0;
    new->X = 0;
    new->moveX = 0;
    new->moveY = 0;
    new->done = 0;
}

void get_moves_white_pawn_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        printf("1>");
        if (peice_number_is_black(get_piece(board, save->X + 1, save->Y + 1))) {
            printf("1>\n");
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
            save->done = 0;
        } else if (peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            printf("2>\n");
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
            save->done = 0;
        } else if (peice_number_is_blank(get_piece(board, save->X, save->Y + 1))) {
            printf("3>\n");
            save->moveY = save->Y + 1;
            save->moveX = save->X;
            save->done = 1;
        } else {
            printf("4>\n");
            save->done = 2;
            return;
        }
    } else if (save->moveX == save->X + 1) {
        printf("2>");
        if (peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            printf("2>\n");
            save->moveX = save->X - 1;
            save->done = 0;
        } else if (peice_number_is_blank(get_piece(board, save->X, save->Y + 1))) {
            printf("3>\n");
            save->moveX = save->X;
            save->done = 1;
        } else {
            printf("4>\n");
            save->done = 2;
            return;
        }
    } else if (save->moveX == save->X - 1) {
        printf("3>");
        if (peice_number_is_blank(get_piece(board, save->X, save->Y + 1))) {
            printf("3>\n");
            save->moveX = save->X;
            save->done = 1;
        } else {
            printf("4>\n");
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
}

void get_moves_white_rook_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->Y)))) {
            save->moveX = save->moveX + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->Y)))) {
            save->moveX = save->moveX - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveY > save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->X, save->moveY + 1)))) {
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY < save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
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


void get_moves_white_bishop_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY > save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->moveY + 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY > save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->moveY + 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY < save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->moveY - 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY < save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
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

void get_moves_white_knight_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveY == save->Y && save->moveX == save->X){
        if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y + 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 2;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 2;
        } else if (!peice_number_is_white(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 2 && save->moveX == save->X + 1){
        if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 2;
        } else if (!peice_number_is_white(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 2 && save->moveX == save->X - 1){
        if (!peice_number_is_white(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 1 && save->moveX == save->X - 2){
        if (!peice_number_is_white(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X - 2){
        if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 2 && save->moveX == save->X - 1){
        if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 2 && save->moveX == save->X + 1){
        if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X + 2){
        if (!peice_number_is_white(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else{
        save->done = 2;
        return;
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

void get_moves_white_queen_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY > save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->moveY + 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY > save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->moveY + 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY < save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->moveY - 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY < save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->moveY - 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX + 1, save->Y)))) {
            save->moveY = save->Y;
            save->moveX = save->moveX + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->moveX - 1, save->Y)))) {
            save->moveY = save->Y;
            save->moveX = save->moveX - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveY > save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_white(get_piece(board, save->X, save->moveY + 1)))) {
            save->moveX = save->X;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY < save->Y) {
        if ((!peice_number_is_black(get_piece(board, save->moveX, save->moveY))) &&
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

void get_moves_white_king_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveY == save->Y && save->moveX == save->X){
        if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 1 && save->moveX == save->X + 1){
        if (!peice_number_is_white(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 1 && save->moveX == save->X){
        if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 1 && save->moveX == save->X - 1){
        if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y && save->moveX == save->X - 1){
        if (!peice_number_is_white(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X - 1){
        if (!peice_number_is_white(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X){
        if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X + 1){
        if (!peice_number_is_white(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else{
        save->done = 2;
        return;
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}


void get_moves_black_pawn_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (peice_number_is_blank(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX == save->X + 1) {
        if (peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
        } else if (peice_number_is_blank(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX == save->X - 1) {
        if (peice_number_is_blank(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
        } else {
            save->done = 2;
            return;
        }
    }
    save->done = 0;
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
}

void get_moves_black_rook_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->Y)))) {
            save->moveX = save->moveX + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->Y)))) {
            save->moveX = save->moveX - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveY > save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->X, save->moveY + 1)))) {
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY > save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->X, save->moveY - 1)))) {
            save->moveY = save->moveY - 1;
        } else {
            save->done = 2;
            return;
        }
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

void get_moves_black_bishop_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY > save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->moveY + 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY > save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->moveY + 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY < save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->moveY - 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY < save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->moveY - 1)))) {
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

void get_moves_black_knight_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveY == save->Y && save->moveX == save->X){
        if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y + 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 2;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 2;
        } else if (!peice_number_is_black(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 2 && save->moveX == save->X + 1){
        if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 2;
        } else if (!peice_number_is_black(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 2 && save->moveX == save->X - 1){
        if (!peice_number_is_black(get_piece(board, save->X - 2, save->Y + 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 1 && save->moveX == save->X - 2){
        if (!peice_number_is_black(get_piece(board, save->X - 2, save->Y - 1))) {
            save->moveX = save->X - 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X - 2){
        if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 2))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 2 && save->moveX == save->X - 1){
        if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 2))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 2;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 2 && save->moveX == save->X + 1){
        if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y - 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X + 2){
        if (!peice_number_is_black(get_piece(board, save->X + 2, save->Y + 1))) {
            save->moveX = save->X + 2;
            save->moveY = save->Y + 1;
        } else {
            save->done = 2;
            return;
        }
    }else{
        save->done = 2;
        return;
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}


void get_moves_black_queen_save(chessBoard board, chessMove *move, chessMoveSave save) {
    if (save->moveX == save->X && save->moveY == save->Y) {
        if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY > save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->moveY + 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY > save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->moveY + 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X && save->moveY < save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->moveY - 1)))) {
            save->moveX = save->moveX - 1;
            save->moveY = save->moveY - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X && save->moveY < save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->moveY - 1)))) {
            save->moveX = save->moveX + 1;
            save->moveY = save->moveY - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveX > save->X) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX + 1, save->Y)))) {
            save->moveY = save->Y;
            save->moveX = save->moveX + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveX < save->X) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->moveX - 1, save->Y)))) {
            save->moveY = save->Y;
            save->moveX = save->moveX - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }

    } else if (save->moveY > save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
            (!peice_number_is_black(get_piece(board, save->X, save->moveY + 1)))) {
            save->moveX = save->X;
            save->moveY = save->moveY + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else {
            save->done = 2;
            return;
        }
    } else if (save->moveY < save->Y) {
        if ((!peice_number_is_white(get_piece(board, save->moveX, save->moveY))) &&
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
    if (save->moveY == save->Y && save->moveX == save->X){
        if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y + 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 1 && save->moveX == save->X + 1){
        if (!peice_number_is_black(get_piece(board, save->X, save->Y + 1))) {
            save->moveX = save->X;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 1 && save->moveX == save->X){
        if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y + 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y + 1;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y + 1 && save->moveX == save->X - 1){
        if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y;
        } else if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y && save->moveX == save->X - 1){
        if (!peice_number_is_black(get_piece(board, save->X - 1, save->Y - 1))) {
            save->moveX = save->X - 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X - 1){
        if (!peice_number_is_black(get_piece(board, save->X , save->Y - 1))) {
            save->moveX = save->X;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X){
        if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y - 1))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y - 1;
        } else if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else if (save->moveY == save->Y - 1 && save->moveX == save->X + 1){
        if (!peice_number_is_black(get_piece(board, save->X + 1, save->Y))) {
            save->moveX = save->X + 1;
            save->moveY = save->Y;
        } else {
            save->done = 2;
            return;
        }
    }else{
        save->done = 2;
        return;
    }
    make_chess_move_board(move, save->X, save->Y, save->moveX, save->moveY, board);
    save->done = 0;
}

void get_moves_white_save(chessBoard board, chessMove *move, chessMoveSave save) {
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
        case WHITE_PAWN_NUMBER:
            return get_moves_white_pawn_save(board, move, save);
        case WHITE_ROOK_NUMBER:
            return get_moves_white_rook_save(board, move, save);
        case WHITE_BISHOP_NUMBER:
            return get_moves_white_bishop_save(board, move, save);
        case WHITE_KNIGHT_NUMBER:
            return get_moves_white_knight_save(board, move, save);
        case WHITE_QUEEN_NUMBER:
            return get_moves_white_queen_save(board, move, save);
        case WHITE_KING_NUMBER:
            return get_moves_white_king_save(board, move, save);
        default:
            save->done = 2;
            break;
    }
    if (save->done == 2) {
        return get_moves_white_save(board, move, save);
    }
}

void get_moves_black_save(chessBoard board, chessMove *move, chessMoveSave save) {
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
    }
    piece_num = get_piece(board, save->X, save->Y);
    switch (piece_num) {
        case BLACK_PAWN_NUMBER:
            get_moves_black_pawn_save(board, move, save);
            break;
        case BLACK_ROOK_NUMBER:
            get_moves_black_rook_save(board, move, save);
            break;
        case BLACK_BISHOP_NUMBER:
            get_moves_black_bishop_save(board, move, save);
            break;
        case BLACK_KNIGHT_NUMBER:
            get_moves_black_knight_save(board, move, save);
            break;
        case BLACK_QUEEN_NUMBER:
            get_moves_black_queen_save(board, move, save);
            break;
        case BLACK_KING_NUMBER:
            get_moves_black_king_save(board, move, save);
            break;
        default:
            break;
    }
    if (save->done == 2) {
        return get_moves_black_save(board, move, save);
    }
}