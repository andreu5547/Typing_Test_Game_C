#ifndef TYPING_TEST_RK1_RENDER_H
#define TYPING_TEST_RK1_RENDER_H

#include "structs.h"
#include <windows.h>
#include <stdio.h>

void render_list(FIELD *field, HANDLE ConsoleHandle, TEXT *text);

void render_elem(FIELD *field, HANDLE ConsoleHandle, POS pos);

#endif //TYPING_TEST_RK1_RENDER_H
