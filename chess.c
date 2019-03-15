//
// Created by William on 3/15/2019.
// Contains functions for general game control
//

#include <stdint.h>
#include "chess_board.h"

#include "chess.h"


/**
 * Checks that the game has not ended
 * @param board The board to check
 * @return True if both kings are on the board
 */
uint8_t validate_board(chessBoard board){
    uint8_t has_king_white = 0;
    uint8_t has_king_black = 0;

    for (uint8_t x = 0; x < 8; x++){
        for (uint8_t y = 0; y < 8; y++){
            switch (get_piece(board,x,y)){
                case WHITE_KING_NUMBER:
                    has_king_white = 1;
                    if (has_king_black){
                        return 1;
                    }
                    break;
                case BLACK_KING_NUMBER:
                    has_king_black = 1;
                    if (has_king_white){
                        return 1;
                    }
                default:break;
            }
        }
    }
    return has_king_black && has_king_white;
}


/**
 * Figures out who Won the game
 * @param board The board to check
 * @return WHITE_WINS, BLACK_WINS or STALEMATE
 */
uint8_t get_winner(chessBoard board){
    uint8_t has_king_white = 0;
    uint8_t has_king_black = 0;

    for (uint8_t x = 0; x < 8; x++){
        for (uint8_t y = 0; y < 8; y++){
            switch (get_piece(board,x,y)){
                case WHITE_KING_NUMBER:
                    has_king_white = 1;
                    break;
                case BLACK_KING_NUMBER:
                    has_king_black = 1;
                default:break;
            }
        }
    }
    if (has_king_white && has_king_black){
        return STALEMATE;
    }else if (has_king_black){
        return BLACK_WINS;
    }else{
        return WHITE_WINS;
    }
}