#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

pthread_mutex_t mutex; 

void* printNumbers(void* threadID) {
    int id = ((int)threadID);

    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex); 
        printf("Thread %d: %d\n", id, i);

        pthread_mutex_unlock(&mutex); 
        usleep(100000);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL); 
    for (int i = 0; i < NUM_THREADS; i++) {
        threadIDs[i] = i + 1;
        pthread_create(&threads[i], NULL, printNumbers, (void*)&threadIDs[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex); 

    return 0;
}
