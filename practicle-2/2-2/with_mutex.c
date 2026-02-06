#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5
#define INC_COUNT 1000

int counter = 0;
pthread_mutex_t mutex;

void* increment(void* arg) {
    (void)arg;
    for (int i = 0; i < INC_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("С мьютексом: counter = %d (ожидалось %d)\n",
           counter, THREADS * INC_COUNT);

    return 0;
}