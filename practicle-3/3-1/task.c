#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {

    int fd[2];

    // создание канала
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    // ошибка fork
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // дочерний процесс
    if (pid == 0) {

        close(fd[1]); // закрываем запись

        char buffer[100];

        ssize_t bytes_read =
                read(fd[0], buffer, sizeof(buffer));

        if (bytes_read < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child received: %s\n", buffer);

        close(fd[0]);
    }

    // родительский процесс
    else {

        close(fd[0]); // закрываем чтение

        const char *message =
                "Hello from parent";

        ssize_t bytes_written =
                write(fd[1],
                      message,
                      strlen(message) + 1);

        if (bytes_written < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(fd[1]);
    }

    return 0;
}