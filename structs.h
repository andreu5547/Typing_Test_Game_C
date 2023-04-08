#ifndef TYPING_TEST_RK1_STRUCTS_H
#define TYPING_TEST_RK1_STRUCTS_H

typedef struct POS { // Структура координат
    int y;
    int x;
} POS;

typedef struct TEXT { // Структура для текста
    char *text; // Текст
    int current; // Номер текущего элемента
} TEXT;

typedef struct ELEMENT { // Структура элемента поля
    char value; // Значение элемента
    int info; // Информация об элементе
} ELEMENT;

typedef struct FIELD { // Структура поля
    int height; // Высота (кол-во строк)
    int width; // Ширина строк в элементах
    ELEMENT **field; // Двумерный массив элементов поля
} FIELD;

typedef struct STATS { // Структура статистики
    int CountOfTrueSign; // Кол-во правильно введенных символов
    int CountOfFalseSign; // Кол-во неправильно введенных символов
    int CountOfWords; // Кол-во слов
    double MiddleSpeedOfSign; // Средняя скорость ввода символов
    double MiddleSpeedOfWords; // Средняя скорость ввода слов
} STATS;

#endif //TYPING_TEST_RK1_STRUCTS_H
