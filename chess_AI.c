//
// Created by William on 3/15/2019.
// Contains functions for running the AI
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
#include "chess_AI.h"

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

char get_next_turn(char player_turn){
    if (player_turn == WHITE_PLAYERS_TURN){
        return BLACK_PLAYERS_TURN;
    }else{
        return WHITE_PLAYERS_TURN;
    }
}

void run_AI_turn(chessBoard board, char * player_turn){
    chessMove * move = get_move_to_move(board, *player_turn);
    run_chess_move(board, *move);
    free(move);
    *player_turn = get_next_turn(*player_turn);
}