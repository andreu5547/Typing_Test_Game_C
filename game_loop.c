#include "game_loop.h"

void game_loop(FIELD *field, HANDLE ConsoleHandle, TEXT *text, STATS *stats, int time_limit, int error_limit) {
    int fail = 0, enter_fl = 0; // Флаги на проигрыш и для подсчёта слов
    char CurrentChar; // Временная переменная для символа
    POS pos = {0, 0}; // Позиция курсора
    double StartTime = clock(), EndTime = 0; // Начальное и конечное время соответственно, для подсчета пройденного времени

    while (1) { // Цикл игры
        if (kbhit()) { // Проверка на нажатие кнопки
            if (((CurrentChar = getch()) == field->field[pos.y][pos.x].value) ||
                (CurrentChar == 13 && field->field[pos.y][pos.x].value == '\n')) { // Сравнение введённого элемента с тем, на котором курсор (13 код enter'а)
                stats->CountOfTrueSign++; // Если совпал, то прибавляем к кол-ву верных симолов
                field->field[pos.y][pos.x].info = 1; // Красим его в зелёный
            } else {
                stats->CountOfFalseSign++; // Если не совпал, то прибавляем к неправильным
                field->field[pos.y][pos.x].info = 0; // Красим в красный
                if (stats->CountOfFalseSign > error_limit) // Конец игры из-за ошибок проверка
                {
                    fail = 1; // Необходимо для вывода сообщения о поражении
                    break;
                }
            }

            if ((field->field[pos.y][pos.x].value == '\n' || field->field[pos.y][pos.x].value == ' ') && enter_fl) { // Подсчёт слов
                enter_fl = 0;
                stats->CountOfWords++;
            } else enter_fl = 1;

            render_elem(field, ConsoleHandle, pos); // Рендер элемента перекрашенного

            if (field->field[pos.y][pos.x].value == '\n') { // Проверка на конец строки
                pos.y++;
                pos.x = 0;
            } else pos.x++;

            if (pos.x == field->width) { // Проверка на окончание строки
                pos.y++;
                pos.x = 0;
            }

            if (pos.y == field->height) { // Проверка на окончание строк
                pos.x = 0;
                pos.y = 0;
                render_list(field, ConsoleHandle, text); // Перерендер нового листа с данными
            }

            if (field->field[pos.y][pos.x].value == '\0') // Проверка на конец текста
                break;

            render_elem(field, ConsoleHandle, pos); // Реднер нового элемента
        } else { // Если пользователь не вводит ничего, то считаем время
            if (((EndTime - StartTime) / CLK_TCK) > time_limit) // Проверяем истекло ли время
            {
                fail = 1;
                break;
            }
            EndTime = clock(); // Обновляем время последнее
        }
        if (fail) break; // Если есть ключ на проигрыш, то выходим из цикла
    }

    stats->CountOfWords++; // Учитываем последнее слово

    stats->MiddleSpeedOfSign = (stats->CountOfFalseSign + stats->CountOfTrueSign) / ((EndTime - StartTime) / CLK_TCK); // Подсчет средних скоростей ввода символов
    stats->MiddleSpeedOfWords = stats->CountOfWords / ((EndTime - StartTime) / CLK_TCK); // Подсчет средних скоростей ввода слов
    system("cls"); // Очищаем экран
    victory_or_not(fail); // Выводим сообщение о победе или поражении
}