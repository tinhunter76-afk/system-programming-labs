#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS 4

void* thread_func(void* arg) {
    int id = *(int*)arg;

    for (int i = 1; i <= 5; i++) {
        printf("Поток %d: %d\n", id, i);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int ids[THREADS];

    for (int i = 0; i < THREADS; i++) {
        ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_func, &ids[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    printf("Все потоки завершены\n");
    return 0;
}