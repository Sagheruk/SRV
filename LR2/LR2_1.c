#include <stdio.h>
#include <process.h>

int main() {
        pid_t pid;
        if ((pid = fork()) == -1) {
                return 1;
        }
        if (pid == 0) {
                printf("Child process, Skrilnikov, I992\n");
        }
        else {
                printf("Parent process, Ivan A.\n");
        }
        sleep(10);
        return 0;
}