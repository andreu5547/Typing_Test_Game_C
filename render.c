#include "render.h"

void put_list(FIELD *field) { // Вывод нового поля на экран
    for (int i = 0; i < field->height; ++i) {
        int j = 0;
        for (j = 0; j < field->width; ++j) {
            if (field->field[i][j].value != '\0' && field->field[i][j - 1].value != '\n') // Проверка на конец текста и строки
                putchar(field->field[i][j].value);
            else break;
        }
        if (field->field[i][j].value == '\0') // Проверка на конец строки
            break;
    }
}

void render_list(FIELD *field, HANDLE ConsoleHandle, TEXT *text) { // Рендер нового поля
    system("cls"); // Очистка экрана
    SetConsoleCursorPosition(ConsoleHandle,(COORD){0,0}); // Установка курсора в 0, 0
    int num_ws = 0; // Временная переменная для обработки не вмещающихся слов
    for (int i = 0; i < field->height; ++i) { // Перебор строк
        for (int j = 0; j < field->width - 1; ++j) { // Перебор символов в строке
            field->field[i][j].value = text->text[text->current]; // Запись символа из текста в наше поле на место (i, j)
            field->field[i][j].info = 2; // Задаём базовый окрас
            if (text->text[text->current] == '\0') // Обработка конца текста
                break;
            text->current++; // Сдвигаем счётчик текущего символа в строке на 1 вправо
            field->field[i][j + 1].value = '\n'; // Установка перехода на новою строку на следующий символ
            field->field[i][j + 1].info = 2; // Задаём базовый цвет

            if ((j == field->width - 2) && text->text[text->current] != ' ' && text->text[text->current] != '\0') { // Обработка не вмещающихся слов
                while (text->text[text->current] != ' ') { // Ищем первый пробел слева от слова
                    j--;
                    text->current--;
                }
                text->current++; // Обработка пробела, который вошёл в while

                if (text->text[text->current] == ' ') //считаем сколько было пробелов всего (если были)
                    while (text->text[text->current - num_ws] == ' ')
                        num_ws++;

                field->field[i][j - num_ws + 2].value = '\n'; // Установка конца строки в новое место (до пробелов)
                field->field[i][j - num_ws + 2].info = 2; // Задаём базовый цвет
                num_ws = 0; // Обнуляем временную переменную
                break;
            }
        }
        if (text->text[text->current] == '\0') // обработка конца текста
            break;
    }
    put_list(field); // Вывод нового поля на экран
    SetConsoleCursorPosition(ConsoleHandle,(COORD){0,0}); // Установка курсора в 0, 0
}

void render_elem(FIELD *field, HANDLE ConsoleHandle, POS pos) { // Функция рендера отдельного элемента
    SetConsoleCursorPosition(ConsoleHandle,(COORD){pos.x, pos.y}); // Переводим курсор на нужный символ
    switch (field->field[pos.y][pos.x].info) { // Перебор возможный цветов
        case 1: // Зелёный - успешный
            if(field->field[pos.y][pos.x].value != ' ' && field->field[pos.y][pos.x].value != '\n') // Если не пробел и не новая строка - символ, перекрашенный
                printf("\033[32m%c\033[0m",field->field[pos.y][pos.x].value);
            else if (field->field[pos.y][pos.x].value == '\n') // Если новая строка - пробел, перекрашенный
                printf("\033[0;42m \033[0m");
            else // Если пробел - нижнее подчёркивание перекрашенное
                printf("\033[0;32m_\033[0m");
            break;
        case 2: // Синий - текущий символ
            if(field->field[pos.y][pos.x].value != ' ' && field->field[pos.y][pos.x].value != '\n') // Если не пробел и не новая строка - символ, перекрашенный
                printf("\033[0;44m%c\033[0m",field->field[pos.y][pos.x].value);
            else if (field->field[pos.y][pos.x].value == '\n') // Если новая строка - пробел, перекрашенный
                printf("\033[0;44m_\033[0m");
            else // Если пробел - нижнее подчёркивание перекрашенное
                printf("\033[0;44m \033[0m");
            break;
        default: // Красный - ошибка
            if(field->field[pos.y][pos.x].value != ' ' && field->field[pos.y][pos.x].value != '\n') // Если не пробел и не новая строка - символ, перекрашенный
                printf("\033[31m%c\033[0m",field->field[pos.y][pos.x].value);
            else if (field->field[pos.y][pos.x].value == '\n') // Если новая строка - пробел, перекрашенный
                printf("\033[0;41m \033[0m");
            else // Если пробел - нижнее подчёркивание перекрашенное
                printf("\033[0;31m_\033[0m");
            break;

    }
    SetConsoleCursorPosition(ConsoleHandle,(COORD){pos.x, pos.y});  // Переводим курсор вновь на нужный символ
}