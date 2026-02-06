#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>

#define THREADS 5
#define INC_COUNT 1000

int counter = 0;

void* increment(void* arg) {
    (void)arg;
    for (int i = 0; i < INC_COUNT; i++) {
        int temp = counter;
        sched_yield();       // принудительное переключение
        counter = temp + 1;
    }
    return NULL;
}

int main() {
    pthread_t threads[THREADS];

    for (int i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Без мьютекса: counter = %d (ожидалось < %d)\n",
           counter, THREADS * INC_COUNT);

    return 0;
}