//
// Created by wills on 2/9/2019.
//


#include <stdlib.h>
#include "chess_board.h"
#include "chess_moves.h"

chessMove make_chess_move(chessMove *new, uint8_t startX, uint8_t startY,
                          uint8_t endX, uint8_t endY, uint8_t target) {
    new->startX = startX;
    new->startY = startY;
    new->endX = endX;
    new->endY = endY;
    new->target = target;
}

chessMove make_chess_move_board(chessMove *new, uint8_t startX, uint8_t startY,
                                uint8_t endX, uint8_t endY, chessBoard board) {
    new->startX = startX;
    new->startY = startY;
    new->endX = endX;
    new->endY = endY;
    new->target = get_piece(board, endX, endY);
}


void get_moves_white_pawn(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    if (x < 7 && y < 7 && peice_number_is_black(get_piece(board, x + 1, y + 1))) {
        make_chess_move_board(moves + *size, x, y, x + 1, y + 1, board);
        (*size)++;
    }
    if (x > 0 && y < 7 && peice_number_is_black(get_piece(board, x - 1, y + 1))) {
        make_chess_move_board(moves + *size, x, y, x - 1, y + 1, board);
        (*size)++;
    }
    if (y < 7 && peice_number_is_blank(get_piece(board, x, y + 1))) {
        make_chess_move_board(moves + *size, x, y, x, y + 1, board);
        (*size)++;
    }
}

void get_moves_white_rook(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;
    for (uint8_t newX = x + 1; newX < 8; newX++) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newX = x - 1; newX >= 0; newX--) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y + 1; newY < 8; newY++) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y - 1; newY >= 0; newY--) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }
}

void get_moves_white_bishop(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;


    uint8_t newX = x + 1;
    uint8_t newY = y + 1;
    while (newX < 8 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY++;
    }

    newX = x - 1;
    newY = y - 1;
    while (newX >= 0 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY--;
    }


    newX = x - 1;
    newY = y + 1;
    while (newX >= 0 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY++;
    }


    newX = x + 1;
    newY = y - 1;
    while (newX < 8 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY--;
    }
}

void get_moves_white_knight(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;
    if (x < 7) {
        if (y < 6) {
            piece = get_piece(board, x + 1, y + 2);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y + 2, board);
                (*size)++;
            }
        }
        if (y > 1) {
            piece = get_piece(board, x + 1, y - 2);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y - 2, board);
                (*size)++;
            }
        }
        if (x < 6) {
            if (y < 7) {
                piece = get_piece(board, x + 2, y + 1);
                if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                    make_chess_move_board(moves + *size, x, y, x + 2, y + 1, board);
                    (*size)++;
                }
            }
            if (y > 0) {
                piece = get_piece(board, x + 2, y - 1);
                if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                    make_chess_move_board(moves + *size, x, y, x + 2, y - 1, board);
                    (*size)++;
                }
            }
        }
    }
    if (x > 0) {
        if (y < 6) {
            piece = get_piece(board, x - 1, y + 2);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y + 2, board);
                (*size)++;
            }
        }
        if (y > 1) {
            piece = get_piece(board, x - 1, y - 2);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y - 2, board);
                (*size)++;
            }
        }
        if (x > 1) {
            if (y < 7) {
                piece = get_piece(board, x - 2, y + 1);
                if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                    make_chess_move_board(moves + *size, x, y, x - 2, y + 1, board);
                    (*size)++;
                }
            }
            if (y > 0) {
                piece = get_piece(board, x - 2, y - 1);
                if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                    make_chess_move_board(moves + *size, x, y, x - 2, y - 1, board);
                    (*size)++;
                }
            }
        }
    }
}

void get_moves_white_queen(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;
    for (uint8_t newX = x + 1; newX < 8; newX++) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newX = x - 1; newX >= 0; newX--) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y + 1; newY < 8; newY++) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y - 1; newY >= 0; newY--) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }


    uint8_t newX = x + 1;
    uint8_t newY = y + 1;
    while (newX < 8 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY++;
    }

    newX = x - 1;
    newY = y - 1;
    while (newX >= 0 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY--;
    }


    newX = x - 1;
    newY = y + 1;
    while (newX >= 0 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY++;
    }


    newX = x + 1;
    newY = y - 1;
    while (newX < 8 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY--;
    }
}

void get_moves_white_king(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;
    if (x > 0) {
        piece = get_piece(board, x - 1, y);
        if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x - 1, y, board);
            (*size)++;
        }
        if (y > 0) {
            piece = get_piece(board, x - 1, y - 1);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y - 1, board);
                (*size)++;
            }
        }
        if (y < 7) {
            piece = get_piece(board, x - 1, y);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y + 1, board);
                (*size)++;
            }
        }
    }
    if (x < 7) {
        piece = get_piece(board, x + 1, y);
        if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x + 1, y, board);
            (*size)++;
        }
        if (y > 0) {
            piece = get_piece(board, x + 1, y - 1);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y - 1, board);
                (*size)++;
            }
        }
        if (y < 7) {
            piece = get_piece(board, x + 1, y + 1);
            if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y + 1, board);
                (*size)++;
            }
        }
    }
    if (y > 0) {
        piece = get_piece(board, x, y - 1);
        if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, y - 1, board);
            (*size)++;
        }
    }
    if (y < 7) {
        piece = get_piece(board, x, y + 1);
        if (peice_number_is_blank(piece) || peice_number_is_black(piece)) {
            make_chess_move_board(moves + *size, x, y, x, y + 1, board);
            (*size)++;
        }
    }
}


void get_moves_black_pawn(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    if (x < 7 && y > 0 && peice_number_is_black(get_piece(board, x + 1, y - 1))) {
        make_chess_move_board(moves + *size, x, y, x + 1, y - 1, board);
        (*size)++;
    }
    if (x > 0 && y > 0 && peice_number_is_black(get_piece(board, x - 1, y - 1))) {
        make_chess_move_board(moves + *size, x, y, x - 1, y - 1, board);
        (*size)++;
    }
    if (y > 0 && peice_number_is_blank(get_piece(board, x, y - 1))) {
        make_chess_move_board(moves + *size, x, y, x, y - 1, board);
        (*size)++;
    }
}

void get_moves_black_rook(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;
    for (uint8_t newX = x + 1; newX < 8; newX++) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newX = x - 1; newX >= 0; newX--) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y + 1; newY < 8; newY++) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y - 1; newY >= 0; newY--) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }
}

void get_moves_black_bishop(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;

    uint8_t newX = x + 1;
    uint8_t newY = y + 1;
    while (newX < 8 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY++;
    }

    newX = x - 1;
    newY = y - 1;
    while (newX >= 0 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY--;
    }


    newX = x - 1;
    newY = y + 1;
    while (newX >= 0 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY++;
    }


    newX = x + 1;
    newY = y - 1;
    while (newX < 8 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY--;
    }
}

void get_moves_black_knight(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;
    if (x < 7) {
        if (y < 6) {
            piece = get_piece(board, x + 1, y + 2);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y + 2, board);
                (*size)++;
            }
        }
        if (y > 1) {
            piece = get_piece(board, x + 1, y - 2);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y - 2, board);
                (*size)++;
            }
        }
        if (x < 6) {
            if (y < 7) {
                piece = get_piece(board, x + 2, y + 1);
                if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                    make_chess_move_board(moves + *size, x, y, x + 2, y + 1, board);
                    (*size)++;
                }
            }
            if (y > 0) {
                piece = get_piece(board, x + 2, y - 1);
                if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                    make_chess_move_board(moves + *size, x, y, x + 2, y - 1, board);
                    (*size)++;
                }
            }
        }
    }
    if (x > 0) {
        if (y < 6) {
            piece = get_piece(board, x - 1, y + 2);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y + 2, board);
                (*size)++;
            }
        }
        if (y > 1) {
            piece = get_piece(board, x - 1, y - 2);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y - 2, board);
                (*size)++;
            }
        }
        if (x > 1) {
            if (y < 7) {
                piece = get_piece(board, x - 2, y + 1);
                if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                    make_chess_move_board(moves + *size, x, y, x - 2, y + 1, board);
                    (*size)++;
                }
            }
            if (y > 0) {
                piece = get_piece(board, x - 2, y - 1);
                if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                    make_chess_move_board(moves + *size, x, y, x - 2, y - 1, board);
                    (*size)++;
                }
            }
        }
    }
}

void get_moves_black_queen(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;
    for (uint8_t newX = x + 1; newX < 8; newX++) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newX = x - 1; newX >= 0; newX--) {
        piece = get_piece(board, newX, y);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, y, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y + 1; newY < 8; newY++) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }

    for (uint8_t newY = y - 1; newY >= 0; newY--) {
        piece = get_piece(board, x, newY);
        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }
    }


    uint8_t newX = x + 1;
    uint8_t newY = y + 1;
    while (newX < 8 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY++;
    }

    newX = x - 1;
    newY = y - 1;
    while (newX >= 0 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY--;
    }


    newX = x - 1;
    newY = y + 1;
    while (newX >= 0 && newY < 8) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX--;
        newY++;
    }


    newX = x + 1;
    newY = y - 1;
    while (newX < 8 && newY >= 0) {
        piece = get_piece(board, newX, newY);

        if (peice_number_is_blank(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
        } else if (peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, newX, newY, board);
            (*size)++;
            break;
        } else {
            break;
        }

        newX++;
        newY--;
    }
}

void get_moves_black_king(chessBoard board, uint8_t *size, uint8_t x, uint8_t y, chessMove moves[250]) {
    uint8_t piece;
    if (x > 0) {
        piece = get_piece(board, x - 1, y);
        if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x - 1, y, board);
            (*size)++;
        }
        if (y > 0) {
            piece = get_piece(board, x - 1, y - 1);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y - 1, board);
                (*size)++;
            }
        }
        if (y < 7) {
            piece = get_piece(board, x - 1, y);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x - 1, y + 1, board);
                (*size)++;
            }
        }
    }
    if (x < 7) {
        piece = get_piece(board, x + 1, y);
        if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x + 1, y, board);
            (*size)++;
        }
        if (y > 0) {
            piece = get_piece(board, x + 1, y - 1);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y - 1, board);
                (*size)++;
            }
        }
        if (y < 7) {
            piece = get_piece(board, x + 1, y + 1);
            if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
                make_chess_move_board(moves + *size, x, y, x + 1, y + 1, board);
                (*size)++;
            }
        }
    }
    if (y > 0) {
        piece = get_piece(board, x, y - 1);
        if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, y - 1, board);
            (*size)++;
        }
    }
    if (y < 7) {
        piece = get_piece(board, x, y + 1);
        if (peice_number_is_blank(piece) || peice_number_is_white(piece)) {
            make_chess_move_board(moves + *size, x, y, x, y + 1, board);
            (*size)++;
        }
    }
}

chessMove * copyChessMovesToHeap(chessMove moves[250], uint8_t size){
    chessMove * newMoveArray = malloc(size * sizeof(chessMove));
    for (uint8_t index = 0; index < size; index++){
        newMoveArray[index].target = moves[index].target;
        newMoveArray[index].endY = moves[index].endY;
        newMoveArray[index].endX = moves[index].endX;
        newMoveArray[index].startY = moves[index].startY;
        newMoveArray[index].startX = moves[index].startX;
    }
    return newMoveArray;
}

chessMove * get_moves_white(chessBoard board, uint8_t *size) {
    chessMove moves[250];
    *size = 0;
    uint8_t piece_num;
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 0; y < 8; y++) {
            piece_num = get_piece(board, x, y);
            switch (piece_num) {
                case WHITE_PAWN_NUMBER:
                    get_moves_white_pawn(board, size, x, y, moves);
                    break;
                case WHITE_ROOK_NUMBER:
                    get_moves_white_rook(board, size, x, y, moves);
                    break;
                case WHITE_BISHOP_NUMBER:
                    get_moves_white_bishop(board, size, x, y, moves);
                    break;
                case WHITE_KNIGHT_NUMBER:
                    get_moves_white_knight(board, size, x, y, moves);
                    break;
                case WHITE_QUEEN_NUMBER:
                    get_moves_white_queen(board, size, x, y, moves);
                    break;
                case WHITE_KING_NUMBER:
                    get_moves_white_king(board, size, x, y, moves);
                    break;
                default:
                    break;
            }
        }
    }
    return copyChessMovesToHeap(moves, *size);
}

chessMove * get_moves_black(chessBoard board, uint8_t *size) {
    chessMove moves[250];
    *size = 0;
    uint8_t piece_num;
    for (uint8_t x = 0; x < 8; x++) {
        for (uint8_t y = 0; y < 8; y++) {
            piece_num = get_piece(board, x, y);
            switch (piece_num) {
                case BLACK_PAWN_NUMBER:
                    get_moves_black_pawn(board, size, x, y, moves);
                    break;
                case BLACK_ROOK_NUMBER:
                    get_moves_black_rook(board, size, x, y, moves);
                    break;
                case BLACK_BISHOP_NUMBER:
                    get_moves_black_bishop(board, size, x, y, moves);
                    break;
                case BLACK_KNIGHT_NUMBER:
                    get_moves_black_knight(board, size, x, y, moves);
                    break;
                case BLACK_QUEEN_NUMBER:
                    get_moves_black_queen(board, size, x, y, moves);
                    break;
                case BLACK_KING_NUMBER:
                    get_moves_black_king(board, size, x, y, moves);
                    break;
                default:
                    break;
            }
        }
    }
    return copyChessMovesToHeap(moves, *size);
}

void runChessMove(chessBoard board, chessMove move){
    load_piece(board, move.endX, move.endY, get_piece(board, move.startX, move.startX));
    load_piece(board, move.startX, move.startY, BLANK_NUMBER);
}

void reverseChessMove(chessBoard board, chessMove move){
    load_piece(board, move.startX, move.startY, get_piece(board, move.endX, move.endY));
    load_piece(board, move.endX, move.endY, move.target);
}

void highlightChessMove(chessBoard board, chessMove move){
    load_piece(board, move.endX, move.endY, OTHER_NUMBER);
}

void reverseChessMoveHighlight(chessBoard board, chessMove move){
    load_piece(board, move.endX, move.endY, move.target);
}
