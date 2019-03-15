//
// Created by wills on 3/12/
// Contains fuctions for running Alpha-Beta on chess moves
//
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "min_max.h"
#include "chess_alpha_beta.h"
#include "chess_board.h"
#include "chess_moves_save.h"
#include "chess_moves_saves_black.h"
#include "chess_moves_saves_white.h"
#include "chess_alpha_beta.h"

#define SIZE 5



int8_t treelessChessAlphaBeta(char min_or_max, chessBoard board,
                              int8_t top, int8_t bottom, uint8_t depth, chessMove * move_return){
    if (depth > 0){
        if (move_return != NULL) {
            chessMoveSave save = make_starting_save();
            chessMove *move = malloc(sizeof(chessMove));

            if (min_or_max == MAX) {
                get_moves_white_save(board, move, save);
            } else {
                get_moves_black_save(board, move, save);
            }

            while (save->done != 3) {
                run_chess_move(board, *move);
                int8_t out = treelessChessAlphaBeta(get_min_or_max(min_or_max), board, top, bottom, depth - 1, NULL);
                reverse_chess_move(board, *move);
                if (min_or_max == MIN) {
                    if (bottom > out) {
                        break_down_save(save);
                        copy_move(move, move_return);
                        free(move);
                        return out;
                    }
                    if (top > out) {
                        copy_move(move, move_return);
                        top = out;
                    }
                } else {
                    if (top < out) {
                        break_down_save(save);
                        copy_move(move, move_return);
                        free(move);
                        return out;
                    }
                    if (bottom < out) {
                        copy_move(move, move_return);
                        bottom = out;
                    }
                }

                if (min_or_max == MAX) {
                    get_moves_white_save(board, move, save);
                } else {
                    get_moves_black_save(board, move, save);
                }
            }

            break_down_save(save);
            free(move);

            if (min_or_max == MIN) {
                return top;
            } else {
                return bottom;
            }
        }else{
            chessMoveSave save = make_starting_save();
            chessMove *move = malloc(sizeof(chessMove));

            if (min_or_max == MAX) {
                get_moves_white_save(board, move, save);
            } else {
                get_moves_black_save(board, move, save);
            }

            while (save->done != 3) {
                run_chess_move(board, *move);
                int8_t out = treelessChessAlphaBeta(get_min_or_max(min_or_max), board, top, bottom, depth - 1, NULL);
                reverse_chess_move(board, *move);
                if (min_or_max == MIN) {
                    if (bottom > out) {
                        break_down_save(save);
                        free(move);
                        return out;
                    }
                    if (top > out) {
                        top = out;
                    }
                } else {
                    if (top < out) {
                        break_down_save(save);
                        free(move);
                        return out;
                    }
                    if (bottom < out) {
                        bottom = out;
                    }
                }

                if (min_or_max == MAX) {
                    get_moves_white_save(board, move, save);
                } else {
                    get_moves_black_save(board, move, save);
                }
            }

            break_down_save(save);
            free(move);

            if (min_or_max == MIN) {
                return top;
            } else {
                return bottom;
            }
        }
    }else{
        return score_board(board);
    }
}

