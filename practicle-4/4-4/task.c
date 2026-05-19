#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>

// флаг работы демона
volatile sig_atomic_t running = 1;

// обработчик сигнала завершения
void handle_signal(int sig) {

    (void)sig;

    running = 0;
}

int main() {

    pid_t pid;

    // создание дочернего процесса
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // завершение родителя
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // создание новой сессии
    if (setsid() < 0) {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

    // НЕ меняем директорию,
    // чтобы лог создавался рядом с программой

    // сброс маски прав
    umask(0);

    // закрытие стандартных потоков
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // установка обработчиков сигналов
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    // основной цикл демона
    while (running) {

        // открытие лог-файла
        int fd = open(
                "daemon.log",
                O_WRONLY | O_CREAT | O_APPEND,
                0666
        );

        if (fd < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // получение текущего времени
        time_t now = time(NULL);

        if (now == (time_t)-1) {
            perror("time");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // преобразование времени в строку
        char *time_str = ctime(&now);

        if (time_str == NULL) {
            perror("ctime");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // запись времени в файл
        ssize_t bytes_written = write(
                fd,
                time_str,
                strlen(time_str)
        );

        if (bytes_written < 0) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }

        close(fd);

        // ожидание 5 секунд
        sleep(5);
    }

    return 0;
}