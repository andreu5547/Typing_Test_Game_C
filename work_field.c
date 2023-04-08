#include "work_field.h"

FIELD *init_field(int height, int width){ // Инициализация поля
    FIELD *field = malloc(sizeof(FIELD)); // Выделение памяти под поле

    field->field = malloc(height * sizeof(ELEMENT **)); // Выделение памяти под массив элементов поля
    for (int i = 0; i < height; ++i)
        field->field[i] = malloc((width + 1) * sizeof(ELEMENT*)); // Выделение памяти под элементы поля


    for (int i = 0; i < height; ++i) // Заполняем поле #
        for (int j = 0; j < width; ++j) {
            field->field[i][j].value = '#';
            field->field[i][j].info = 2;
        }


    field->width = width; // Устанавливаем ширину
    field->height = height; // Устанавливаем высоту

    return field; // Возвращаем указатель на поле
}

void free_field(FIELD *field) { // Функция очистки памяти поля
    for (int i = 0; i < field->height; ++i)
        free(field->field[i]);
    free(field->field);
    free(field);
}