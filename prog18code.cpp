#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

void *producer(void *arg) {
    int produced_item = 0;
    
    while (produced_item < MAX_ITEMS) {
        // Wait for empty space in the buffer
        sem_wait(&empty);
        
        // Acquire mutex to access the buffer
        sem_wait(&mutex);
        
        // Produce item and add to the buffer
        buffer[in] = produced_item;
        printf("Produced item: %d\n", produced_item);
        in = (in + 1) % BUFFER_SIZE;
        produced_item++;
        
        // Release mutex
        sem_post(&mutex);
        
        // Signal that buffer is full
        sem_post(&full);
        
        // Simulate some delay
        sleep(1);
    }
    
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int consumed_item;
    
    while (1) {
        // Wait for items in the buffer
        sem_wait(&full);
        
        // Acquire mutex to access the buffer
        sem_wait(&mutex);
        
        // Consume item from the buffer
        consumed_item = buffer[out];
        printf("Consumed item: %d\n", consumed_item);
        out = (out + 1) % BUFFER_SIZE;
        
        // Release mutex
        sem_post(&mutex);
        
        // Signal that buffer is not full anymore
        sem_post(&empty);
        
        // Simulate some delay
        sleep(2);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;
    
    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    
    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    
    return 0;
}

