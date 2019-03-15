#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "chess_board.h"
#include "min_max.h"
#include "chess_moves.h"
#include "chess_moves_save.h"
#include "chess_moves_saves_white.h"
#include "chess_moves_saves_black.h"

int main() {
    chessMoveSave save = make_starting_save();

    chessMove move;

    chessBoard board;
    clear_board(board);
    start_board_no_pawns(board);

    chessBoard boardHighlights;
    clear_board(boardHighlights);
    start_board_no_pawns(boardHighlights );

//    load_piece(board, 4, 4, WHITE_PAWN_NUMBER);
//    load_piece(boardHighlights, 4, 4, WHITE_PAWN_NUMBER);
//
//    load_piece(board, 4, 3, BLACK_PAWN_NUMBER);
//    load_piece(boardHighlights, 4, 3, BLACK_PAWN_NUMBER);


//    load_piece(board, 3, 6, BLACK_PAWN_NUMBER);
//    load_piece(board, 5, 6, BLACK_PAWN_NUMBER);
    int x = save->X;
    int y = save->Y;
    while(save->done != 3){
        get_moves_black_save(board, &move, save);
        if (save->X != x || save->Y != y){
            printf("----------------------------------------\n");
            print_board(boardHighlights);
            clear_board(boardHighlights);
            start_board_no_pawns(boardHighlights);
            x = save->X;
            y = save->Y;
        }
        if (save->done != 3) {
//            printf("MOVE (%d, %d) -> (%d, %d) takes (%c)\n", move.startX, move.startY, move.endX, move.endY, get_piece_char_from_number(move.taken));
//            printf("STATUS (%d, %d) -> (%d, %d) Done:%d\n", save->X, save->Y, save->moveX, save->moveY, save->done);
            highlight_chess_move(boardHighlights, move);
//            printf("MOVE (%d, %d) -> (%d, %d) takes (%c)\n", move.startX, move.startY, move.endX, move.endY, get_piece_char_from_number(move.taken));
        }
//            printf("----------------------------------------\n");

    }

//    printf("empty score: %d\n", score_board(board));
//    print_board(board);

//    start_board(board);
//    printf("\n-------------------------\n");

//    print_board(boardHighlights);

//    printf("starting score: %d\n", score_board(board));
//    int COUNT_OF_NUMBERS = 2000000000;
//
//    int NUMBER_OF_LEAVES = 40;
//
//    int8_t * numbers= malloc(COUNT_OF_NUMBERS);
//    srand(time(0));
//
//
//    printf("Building List of Data\n");
//    for (long number = 0; number < COUNT_OF_NUMBERS; number++){
//        if (number % ((COUNT_OF_NUMBERS / 10) + 1) == 0){
//            printf("Data %li%%\n", 10 * (number / ((COUNT_OF_NUMBERS / 10) + 1)));
//        }
//        int8_t randNumber = rand() % (COUNT_OF_NUMBERS * 2) - COUNT_OF_NUMBERS;
//        numbers[number] = randNumber;
//    }
//
//    long timerStart = 0;
//    long timerEnd = 0;
//
////
////    printf("Building Tree\n");
////    timerStart = time(0);
////    minMaxNode minmaxTree = biuld_min_max_tree(COUNT_OF_NUMBERS, numbers, NUMBER_OF_LEAVES);
////    restructure_min_max_tree(NULL, minmaxTree);
////    timerEnd = time(0);
////    printf("Timer: %li %li - %li \n", timerEnd - timerStart, timerStart, timerEnd);
////    printf("Tree Built\n");
//
//
////    timerStart = time(0);
////    printf("Standard Min Max: %d \n", run_min_max(minmaxTree));
////    timerEnd = time(0);
////    printf("Timer: %li %li - %li \n", timerEnd - timerStart, timerStart, timerEnd);
//
////    print_min_max_tree(minmaxTree, 0);
////
////    printf("THE TEST\n");
////    reset_min_max(minmaxTree);
////    printf("THE TEST\n");
////
////    print_min_max_tree(minmaxTree, 0);
//
////    timerStart = time(0);
////    printf("Alpha Beta: %d \n", run_alpha_beta(minmaxTree, 127, -128));
////    timerEnd = time(0);
////    printf("Timer: %li %li - %li \n", timerEnd - timerStart, timerStart, timerEnd);
//
//    timerStart = time(0);
//    printf("Alpha Beta No Tree: %d \n", treeless_alpha_beta(COUNT_OF_NUMBERS, numbers, NUMBER_OF_LEAVES, 'x', 127, -128));
//    timerEnd = time(0);
//    printf("Timer: %li %li - %li \n", timerEnd - timerStart, timerStart, timerEnd);


//    print_min_max_tree(minmaxTree, 0);
}