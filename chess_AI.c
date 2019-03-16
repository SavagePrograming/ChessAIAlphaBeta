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
#include "chess.h"

#define SEARCH_DEPTH 3

/**
 * gets the chess move for an AI to move
 * @param board The board to use for move calculation
 * @return The move to make
 */
chessMove * get_move_to_move(chessBoard board, char player_turn){
    if (player_turn == WHITE_PLAYERS_TURN){

        chessMove * move = malloc(sizeof(chessMove));

        int8_t out = treeless_chess_alpha_beta(MAX, board, SEARCH_DEPTH, move);

#ifdef DEBUG
        printf("FINAL MAX SCORE: %d\n", out);
        print_move(*move);
#endif

        if (move->taken == 15){
            return NULL;
        }

        return move;
    }else{
        chessMove * move = malloc(sizeof(chessMove));

        int8_t out = treeless_chess_alpha_beta(MIN, board, SEARCH_DEPTH, move);

#ifdef DEBUG
        printf("FINAL MIN SCORE: %d\n", out);
        print_move(*move);
#endif

        if (move->taken == 15){
            return NULL;
        }

        return move;
    }

}

/**
 * Returns the turn after this turn
 * @param player_turn current turn
 * @return the next turn
 */
char get_next_turn(char player_turn){
    if (player_turn == WHITE_PLAYERS_TURN){
        return BLACK_PLAYERS_TURN;
    }else{
        return WHITE_PLAYERS_TURN;
    }
}

/**
 * Runs the AI for a turn
 * @param board The game board
 * @param player_turn The current turn
 * @return True if the game is not done
 */
uint8_t run_AI_turn(chessBoard board, char * player_turn){
    chessMove * move = get_move_to_move(board, *player_turn);
    if (move == NULL){
        return 0;
    }else{
        run_chess_move(board, *move);
        free(move);
        *player_turn = get_next_turn(*player_turn);
        return validate_board(board);
    }
}
