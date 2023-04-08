#include "helps.h"

void print_help() { // Сообщение - помощь
    puts("Usage: typing-speed-test <difficulty> <time_limit> <error_limit>\n");
    puts("Arguments:");
    puts("<difficulty>: Difficulty level of the test. Can be 'easy', 'medium', or 'hard'.");
    puts("<time_limit>: Time limit in seconds. Must be a positive integer.");
    puts("<error_limit>: Error limit. Must be a positive integer.");
    puts("\nExample: typing-speed-test medium 60 5");
    puts("\nTo see this message again usage: typing-speed-test --help");
}

void victory_or_not(int fail) { // Сообщение о победе или поражении + покраска в цвет
    char win[] = "Congratulations! You win!";
    int color = 32;
    if (fail) puts("\033[31mD E F E A T ! T r y  a g a i n !\033[0m");
    else {
        for (int i = 0; win[i] != '\0'; i++) {
            printf("\033[%dm%c \033[0m", color, win[i]);
            color++;
            if (color > 37)color = 32;
        }
        putchar('\n');
    }
}

void print_rainbow_line(int n) { // Вывод радужных линий
    int color = 32;
    for (int i = 0; i < n; i++) {
        printf("\033[%dm-\033[0m", color);
        color++;
        if (color > 37)color = 32;
    }
    putchar('\n');
}

void print_stats(STATS stats) { // Вывод статистики
    print_rainbow_line(60);
    printf("The number of characters entered correctly: %d \nThe number of incorrectly entered characters: %d \nNumber of characters entered: %d \nAverage character input speed: %f \nAverage word input speed: %f \n",
           stats.CountOfTrueSign, stats.CountOfFalseSign, stats.CountOfFalseSign + stats.CountOfTrueSign,
           stats.MiddleSpeedOfSign, stats.MiddleSpeedOfWords);
    print_rainbow_line(60);
}

