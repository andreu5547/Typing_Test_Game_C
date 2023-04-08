#include "work_file.h"

TEXT *get_text_for_level(char* level) { // Считывание текста из файла
    FILE *fp; // Указатель на файл, который откроем
    TEXT *text; // Указатель на структуру текста
    text = malloc(sizeof(TEXT)); // выделяем память под структуру
    int size; // Переменная для размера файла

    if (strcmp(level, "easy") == 0 || strcmp(level, "medium") == 0 || strcmp(level, "hard") == 0) { // Проверяем валидность названия
        strcat(level, ".txt"); // Собираем название файла
        fp = fopen(level, "r"); // Открываем файл
        if (!fp) { // Проверяем открылся ли файл
            puts("Error file open!");
            return NULL;
        }
    } else return NULL;

    // Определение размера файла
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    text->text = (char*) malloc((size + 1) * sizeof(char)); // Выделение памяти под текст (массив символов)
    char c;
    for (int i = 0; (c = getc(fp)) != EOF; ++i) { // Посимвольное чтение и запись в структуру текста
        text->text[i] = c;
    }
    text->text[size] = '\0'; // Устанавливаем конец строки
    text->current = 0; // Устанавливаем текущий элемент текста
    fclose(fp); // Закрываем файл

    return text; // Возвращаем указатель на структуру текста
}
