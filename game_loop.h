#ifndef TYPING_TEST_RK1_GAME_LOOP_H
#define TYPING_TEST_RK1_GAME_LOOP_H

#include "structs.h"
#include "render.h"
#include <conio.h>
#include <time.h>
#include "helps.h"

void game_loop(FIELD *field, HANDLE ConsoleHandle, TEXT *text, STATS *stats, int time_limit, int error_limit);

#endif //TYPING_TEST_RK1_GAME_LOOP_H
