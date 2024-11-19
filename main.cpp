#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

int shared_data = 0;

void* Thread_1_writes(void* arg) {



    pthread_mutex_lock(&mutex);

    shared_data = 100;
    printf("Thread_1: Writing to shared data: %d\n", shared_data);
  

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* Thread_2_reads(void* arg) {
   

    pthread_mutex_lock(&mutex);

    printf("Thread_2: Reading from shared data: %d\n", shared_data);
   

    pthread_mutex_unlock(&mutex);


    return NULL;
}

int main() {
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, Thread_1_writes, NULL);
    pthread_create(&t2, NULL, Thread_2_reads, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}