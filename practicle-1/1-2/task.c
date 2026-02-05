#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int i;
    int status;

    for (i = 1; i <= 3; i++) {
        pid = fork();

        if (pid < 0) {
            // ошибка fork
            perror("fork error");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // дочерний процесс
            printf("Дочерний процесс %d: PID=%d, PPID=%d\n",
                   i, getpid(), getppid());

            // заменяем процесс (формально используем exec)
            execl("/bin/echo", "echo", "Процесс завершён", NULL);

            // если exec вернул управление — ошибка
            perror("exec error");
            exit(EXIT_FAILURE);
        }
    }

    // родитель ждёт всех дочерних процессов
    for (i = 0; i < 3; i++) {
        if (wait(&status) < 0) {
            perror("wait error");
            exit(EXIT_FAILURE);
        }
    }

    printf("Все дочерние процессы завершены\n");
    return 0;
}
