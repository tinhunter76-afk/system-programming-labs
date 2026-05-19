#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    // ввод размера массива
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // проверка корректности размера
    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    // динамическое выделение памяти
    int *arr = (int *)malloc(n * sizeof(int));

    // проверка выделения памяти
    if (arr == NULL) {
        perror("malloc");
        return 1;
    }

    // заполнение массива
    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // вывод массива
    printf("Array elements:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // вычисление суммы
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);

    // освобождение памяти
    free(arr);

    return 0;
}