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
#define DEBUG_IGNORE_DEPTH -1

/**
 * Internal function for running AlphaBeta treeless for chess
 * @param min_or_max
 * @param board
 * @param top
 * @param bottom
 * @param depth
 * @return
 */
int8_t treeless_Chess_alpha_beta_helper(char min_or_max, chessBoard board,
                                        int8_t top, int8_t bottom, uint8_t depth) {

#ifdef DEBUG
    if (depth > DEBUG_IGNORE_DEPTH) {
        for (uint8_t i = 5 - depth; i > 0; i--) {
            printf("\t");
        }
        printf("depth %d %c\n", depth, min_or_max);
    }
    print_board_compressed(board, 5 - depth);
#endif
    if (depth > 0) {
        chessMoveSave save = make_starting_save();
        chessMove *move = malloc(sizeof(chessMove));

        if (min_or_max == MAX) {
            get_moves_white_save(board, move, save);
        } else {
            get_moves_black_save(board, move, save);
        }
        uint8_t run = 0;
        while (save->done != 3) {
            run = 1;
#ifdef DEBUG
            if (depth > DEBUG_IGNORE_DEPTH) {
                for (uint8_t i = 5 - depth; i > 0; i--) {
                    printf("\t");
                }
                print_move(*move);
            }
#endif
            run_chess_move(board, *move);
            int8_t out = treeless_Chess_alpha_beta_helper(get_min_or_max(min_or_max), board, top, bottom, depth - 1);
            reverse_chess_move(board, *move);
#ifdef DEBUG
            if (depth > DEBUG_IGNORE_DEPTH) {
                for (uint8_t i = 5 - depth; i > 0; i--) {
                    printf("\t");
                }
                printf("Score %d\n", out);
            }
#endif
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
        if (run) {
            if (min_or_max == MIN) {
                return top;
            } else {
                return bottom;
            }
        } else {
            if (min_or_max == MIN) {
                return KING_SCORE;
            } else {
                return -KING_SCORE;
            }
        }
    } else {
#ifdef DEBUG
        int8_t score = score_board(board);
        if (depth > DEBUG_IGNORE_DEPTH) {
            for (uint8_t i = 5 - depth; i > 0; i--) {
                printf("\t");
            }
            printf("score %d\n", score);
        }
        return score;
#else
        return score_board(board);
#endif
    }
}

/**
 * Sets up and runs Alpha-Beta on chess
 * @param min_or_max
 * @param board
 * @param depth
 * @param move_return
 * @return
 */
int8_t treeless_chess_alpha_beta(char min_or_max, uint32_t *board,
                                 uint8_t depth, chessMove *move_return) {
    int8_t top = MAX_VALUE_DEFAULT;
    int8_t bottom = MIN_VALUE_DEFAULT;
#ifdef DEBUG
    printf("depth %d\n");
#endif
    if (depth > 0) {
        chessMoveSave save = make_starting_save();
        chessMove *move = malloc(sizeof(chessMove));

        if (min_or_max == MAX) {
            get_moves_white_save(board, move, save);
        } else {
            get_moves_black_save(board, move, save);
        }
        uint8_t run = 0;
        while (save->done != 3) {
            run = 1;
//            print_move(*move);
//            for (uint8_t i = 5 - depth; i > 0; i--){
//                printf("\t");
//            }
#ifdef DEBUG
            print_move(*move);
#endif
            run_chess_move(board, *move);
            int8_t out = treeless_Chess_alpha_beta_helper(get_min_or_max(min_or_max), board, top, bottom, depth - 1);

#ifdef DEBUG
            printf("Score %d \n", out);
#endif
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
        if (run) {
            if (min_or_max == MIN) {
                return top;
            } else {
                return bottom;
            }
        } else {
            move_return->startX = 0;
            move_return->startY = 0;
            move_return->endY = 0;
            move_return->endX = 0;
            move_return->taken = 15;
            if (min_or_max == MIN) {
                return KING_SCORE;
            } else {
                return -KING_SCORE;
            }
        }
    } else {
#ifdef DEBUG
        int8_t score = score_board(board);
        printf("score %d\n", score);
        return score;
#else
        return score_board(board);
#endif
    }
}

