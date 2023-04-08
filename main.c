#include <windows.h>
#include "defines.h"
#include "structs.h"
#include "validate.h"
#include "work_file.h"
#include "work_field.h"
#include "render.h"
#include "game_loop.h"


int main(int argc, char *argv[]) {
    int time_limit, error_limit; // Переменные для аргументов
    char level[20];

    if (validate_arguments(argc, argv, level, &time_limit, &error_limit)) { // Проверка аргументов на корректность
        return 1;
    }

    HANDLE ConsoleOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Получение дескриптора стандартного вывода
    SetConsoleCursorInfo(ConsoleOutputHandle, &(CONSOLE_CURSOR_INFO) {100, 0}); // Делаем каретку невидимой

    STATS stats = {0, 0, 0, 0, 0}; // Статистика

    TEXT *text = get_text_for_level(level); // Получаю текст из файла + проверка на корректность открытия
    if (!text)
        return -1;

    FIELD *field = init_field(HEIGHT, WIDTH); // Инициализирую поле

    render_list(field, ConsoleOutputHandle, text); // Рендерю первую страницу, далее рендер будет в game_loop

    game_loop(field, ConsoleOutputHandle, text, &stats, time_limit, error_limit); // Loop игры

    print_stats(stats); // Вывожу статистику

    system("pause");
    free_field(field); // Очищаю память поля
    CloseHandle(ConsoleOutputHandle); // Делаю дескриптор недействительным
    return 0;
}
