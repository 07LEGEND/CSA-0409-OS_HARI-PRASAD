#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1_function(void *arg) {
    printf("Thread 1 is running\n");
    printf("Thread 1: Hello, world!\n");
    pthread_exit(NULL);
}

void *thread2_function(void *arg) {
    printf("Thread 2 is running\n");
    printf("Thread 2: Goodbye, world!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;


    if (pthread_create(&thread1, NULL, thread1_function, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, thread2_function, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("Main thread exiting\n");

    return 0;
}
