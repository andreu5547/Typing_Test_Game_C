#include "validate.h"

int validate_arguments(int argc, char **argv, char *level, int *time_limit, int *error_limit) { // Функция проверки введённых аргументов
    if ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "help") == 0) || strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "h") == 0) { // Вывод подсказки, если её запросил позьзователь
        print_help();
        return 1;
    }

    if (argc < 4) { // Проверяем, что переданы все 3 аргумента
        printf("Error: not enough arguments provided\n");
        print_help();
        return 1;
    }

    // Проверяем, что первый аргумент является словом "easy", "medium" или "hard"
    if (strcmp(argv[1], "easy") != 0 && strcmp(argv[1], "medium") != 0 && strcmp(argv[1], "hard") != 0) {
        printf("Error: invalid argument for level\n");
        print_help();
        return 1;
    } else {
        strcpy(level, argv[1]); // Если является, сохраняем его
    }

    // Проверяем, что второй аргумент является числом, не меньшим 10 и не большим 300
    int t = atoi(argv[2]);
    if (t < 10 || t > 300) {
        printf("Error: invalid argument for time limit\n");
        print_help();
        return 1;
    } else // Если является, сохраняем его
        *time_limit = t;

    // Проверяем, что третий аргумент является числом, не меньшим 1 и не большим 10
    int e = atoi(argv[3]);
    if (e < 1 || e > 10) {
        printf("Error: invalid argument for error limit\n");
        print_help();
        return 1;
    } else // Если является, сохраняем его
        *error_limit = e;

    return 0; // Если все аргументы прошли проверки, вернём 0
}