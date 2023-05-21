#include "thLib.h"

void * long_thread1(void * notused) {
        int n;
        for (n = 0; n < 5; n++) {
                printf("Eto pervii potok, TID %d - N povtora %d \n", thread_id1, n);
                sleep(2);
        }
}

void * long_thread2(void * notused) {
        int m;
        for (m = 0; m < 5; m++) {
                printf("Eto vtoroi potok, TID %d - N povtora %d \n", thread_id2, m);
                sleep(1);
        }
}