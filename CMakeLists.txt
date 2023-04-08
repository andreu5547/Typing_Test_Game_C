cmake_minimum_required(VERSION 3.24)
project(Typing_Test_Game_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Typing_Test_Game_C main.c validate.c validate.h helps.c helps.h work_file.c work_file.h structs.h work_field.h work_field.c render.c render.h defines.h game_loop.c game_loop.h)
