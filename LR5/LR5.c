#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>

#define SEC_NSEC 1000000000LL

void * long_thread(void *not_used) {
	printf("Etot potok vipolnaetsa bolee 10 sekynd\n");
	printf("I992, Skrilnikov I.A.\n");
	sleep(20);
}

int main(void) {
	uint64_t timeout;
	struct sigevent event;
	int rval;
	pthread_t thread_id;

	printf("Prog timer \n");
	event.sigev_notify = SIGEV_UNBLOCK;
	pthread_create(&thread_id, NULL, long_thread, NULL);

	timeout = 10LL*SEC_NSEC;
	TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
	rval = pthread_join(thread_id, NULL);
	if(rval == ETIMEDOUT) {
		printf("istekli 10 sec, potok %d vipoln-a! \n", thread_id);
	}
	sleep(5);

	TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
	rval = pthread_join(thread_id, NULL);
	if (rval == ETIMEDOUT) {
		printf("potok %d > 25 sec!", thread_id);
	}
	else {
		printf("Potok %d zavershon kak nado \n", thread_id);
	}
	return 1;
}