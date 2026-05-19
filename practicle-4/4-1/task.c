#include <stdio.h>
#include <stdlib.h>

int main() {

    int *arr;

    // выделение памяти под 100 целых чисел
    arr = (int*)malloc(100 * sizeof(int));

    // проверка выделения памяти
    if (arr == NULL) {
        perror("malloc");
        return 1;
    }

    // заполнение массива числами от 1 до 100
    for (int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }

    // вычисление суммы
    int sum = 0;

    for (int i = 0; i < 100; i++) {
        sum += arr[i];
    }

    // вывод результата
    printf("Sum = %d\n", sum);

    // освобождение памяти
    free(arr);

    return 0;
}