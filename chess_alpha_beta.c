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

/**
 * gets the chess move for an AI to move
 * @param board The board to use for move calculation
 * @return The move to make
 */
chessMove * get_move_to_move(chessBoard board, char player_turn){
    if (player_turn == WHITE_PLAYERS_TURN){
        chessMoveSave save = make_starting_save();
        chessMove * move = malloc(sizeof(chessMove));
        get_moves_white_save(board, move, save);
        break_down_save(save);
        return move;
    }else{
        chessMoveSave save = make_starting_save();
        chessMove * move = malloc(sizeof(chessMove));
        get_moves_black_save(board, move, save);
        break_down_save(save);
        return move;
    }

}


//int8_t treelessChessAlphaBeta(char minOrMax, chessBoard board,
//                              int8_t top, int8_t bottom){
//    if (size > childrenNumber){
//        for (uint16_t childNumber = 0; childNumber < childrenNumber - 1; childNumber++){
//            int8_t out = treelessChessAlphaBeta(size / childrenNumber,
//                                                childNumber * (size / childrenNumber) + numbers,
//                                                childrenNumber, get_min_or_max(minOrMax), top, bottom);
//            if (minOrMax == MIN){
//                if (bottom > out){
//                    return out;
//                }
//                if (top > out){
//                    top = out;
//                }
//            }else{
//                if (top < out){
//                    return out;
//                }
//                if (bottom < out){
//                    bottom = out;
//                }
//            }
//        }
//
//        int8_t out = treelessChessAlphaBeta(size - (childrenNumber - 1) * (size / childrenNumber),
//                                            (childrenNumber - 1) * (size / childrenNumber) + numbers,
//                                            childrenNumber, get_min_or_max(minOrMax), top, bottom);
//        if (minOrMax == MIN){
//            if (bottom > out){
//                return out;
//            }
//
//            if (top > out){
//                top = out;
//            }
//        }else{
//            if (top < out){
//                return out;
//            }
//
//            if (bottom < out){
//                bottom = out;
//            }
//        }
//
//        if (minOrMax == MIN){
//            return top;
//        }else{
//            return bottom;
//        }
//    }else if (size > 1){
//        for (uint16_t childNumber = 0; childNumber < size; childNumber++){
//            int8_t out = treelessChessAlphaBeta(1, childNumber + numbers, childrenNumber, get_min_or_max(minOrMax), top,
//                                                bottom);
//            if (minOrMax == MIN){
//                if (bottom > out){
//                    return out;
//                }
//
//                if (top > out){
//                    top = out;
//                }
//            }else{
//                if (top < out){
//                    return out;
//                }
//
//                if (bottom < out){
//                    bottom = out;
//                }
//            }
//        }
//
//        if (minOrMax == MIN){
//            return top;
//        }else{
//            return bottom;
//        }
//    }else{
//        return numbers[0];
//    }
//}

