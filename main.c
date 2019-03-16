#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "chess_board.h"
#include "chess_AI.h"
#include "chess.h"

#define WHITE_WIN_MESSAGE "White Wins\n"
#define BLACK_WIN_MESSAGE "Black Wins\n"
#define STATLEMATE_MESSAGE "Stalemate\n"

int main() {
    char turn = WHITE_PLAYERS_TURN;
    chessBoard board;
//    clear_board(board);
    start_board(board);
    chessMove *moves[250];
    uint8_t size = 0;


//    start_board_no_pawns(board);

//    load_piece(board, 2,2,WHITE_QUEEN_NUMBER);
//    load_piece(board, 5,5,WHITE_ROOK_NUMBER);
//    printf("SCORE %d", score_board(board));
//    return 0;
    print_board(board);

//    chessMove * move = get_move_to_move(board, turn);
//    turn = get_next_turn(turn);
//
//    while (move != NULL && validate_board(board)) {
//        run_chess_move(board, *move);
//        moves[size++] = move;
//        print_board(board);
////        char wait = getchar();
//
//        move = get_move_to_move(board, turn);
//        turn = get_next_turn(turn);
//    }
//    printf("REVERSING\n");
//    switch (get_winner(board)){
//        case WHITE_WINS:
//            printf(WHITE_WIN_MESSAGE);
//            break;
//        case BLACK_WINS:
//            printf(BLACK_WIN_MESSAGE);
//            break;
//        default:
//            printf(STATLEMATE_MESSAGE);
//            break;
//    }
//    while (size > 0) {
//        printf("SIZE %d\n", size);
//        reverse_chess_move(board, *(moves[--size]));
//        free(moves[size]);
//        print_board(board);
//    }
    while (run_AI_turn(board, &turn)) {
        print_board(board);
//        char wait = getchar();
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