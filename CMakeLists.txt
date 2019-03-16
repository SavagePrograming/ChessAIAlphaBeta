# cmake_minimum_required(VERSION <specify CMake version here>)
project(chess C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG") #For Debug mode
set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required
set(CMAKE_C_STANDARD 99)

add_executable(chess main.c chess_board.c chess_moves.c chess_board.h min_max.c min_max.h chess_alpha_beta.c chess_alpha_beta.h chess_moves.h chess_moves_saves_white.c chess_moves_saves_white.h chess_moves_saves_black.c chess_moves_saves_black.h chess_moves_save.h chess_moves_save.c chess_AI.c chess_AI.h chess.c chess.h)