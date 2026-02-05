#include <fcntl.h>      // open
#include <unistd.h>     // read, write, close
#include <stdio.h>      // perror
#include <stdlib.h>     // exit
#include <string.h>     // strlen

int main() {
    int fd;
    char buffer[32];

    /* 1. Создаём и записываем numbers.txt */
    fd = open("numbers.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open numbers.txt");
        exit(1);
    }

    for (int i = 1; i <= 100; i++) {
        int len = snprintf(buffer, sizeof(buffer), "%d\n", i);
        if (write(fd, buffer, len) == -1) {
            perror("write numbers.txt");
            close(fd);
            exit(1);
        }
    }

    close(fd);

    /* 2. Читаем numbers.txt и считаем сумму */
    fd = open("numbers.txt", O_RDONLY);
    if (fd == -1) {
        perror("open numbers.txt for read");
        exit(1);
    }

    int sum = 0;
    int num = 0;
    char c;

    while (read(fd, &c, 1) == 1) {
        if (c == '\n') {
            sum += num;
            num = 0;
        } else {
            num = num * 10 + (c - '0');
        }
    }

    close(fd);

    /* 3. Записываем сумму в sum.txt */
    fd = open("sum.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open sum.txt");
        exit(1);
    }

    int len = snprintf(buffer, sizeof(buffer), "Sum = %d\n", sum);
    if (write(fd, buffer, len) == -1) {
        perror("write sum.txt");
        close(fd);
        exit(1);
    }

    close(fd);

    return 0;
}
