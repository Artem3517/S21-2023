#include "draw.h"

// Отрисовка графика
void out(char* postfix) {
    double results[200];  // Массив с результатами в 80 шагов
    int count = 0;
    // Собственно цикл для заполнения массива, он гоняет x с шагом pi/20
    for (double x = 0.0; x < 4.0 * M_PI; x += 4.0 * M_PI / 80.0) results[count++] = calculate(postfix, x);
    // 2 цикла для вывода, 0.0814 это +-1/12, у меня только так все правильно работает))
    for (double y = 1; y >= -1; y -= 0.0814) {
        for (int x = 0; x < 80; x++) {
            // 0.05 - погрешность сравнения. <0.05 не работает пограничный случай 0-1
            // >0.05 график становится слишком неточным
            if (results[x] <= y + 0.05 && results[x] >= y - 0.05) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}
