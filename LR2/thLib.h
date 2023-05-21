#include <stdio.h>
#include <pthread.h>
#include <sys/neutrino.h>

pthread_t thread_id1;
pthread_t thread_id2;

void * long_thread1(void *);

void * long_thread2(void *);