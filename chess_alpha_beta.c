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

#define SIZE 5

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

