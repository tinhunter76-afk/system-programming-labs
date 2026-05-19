#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    const char *fifo_name = "myfifo";

    // создание FIFO
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
    }

    pid_t pid = fork();

    // ошибка fork
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // дочерний процесс — читатель
    if (pid == 0) {

        int fd = open(fifo_name, O_RDONLY);

        if (fd == -1) {
            perror("open read");
            exit(EXIT_FAILURE);
        }

        char buffer[100];

        ssize_t bytes_read =
                read(fd, buffer, sizeof(buffer));

        if (bytes_read < 0) {
            perror("read");
            close(fd);
            exit(EXIT_FAILURE);
        }

        printf("Child received: %s\n", buffer);

        close(fd);
    }

    // родительский процесс — писатель
    else {

        int fd = open(fifo_name, O_WRONLY);

        if (fd == -1) {
            perror("open write");
            exit(EXIT_FAILURE);
        }

        const char *message =
                "Hello through FIFO";

        ssize_t bytes_written =
                write(fd,
                      message,
                      strlen(message) + 1);

        if (bytes_written < 0) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }

        close(fd);

        wait(NULL);

        // удаление FIFO
        if (unlink(fifo_name) == -1) {
            perror("unlink");
        }
    }

    return 0;
}