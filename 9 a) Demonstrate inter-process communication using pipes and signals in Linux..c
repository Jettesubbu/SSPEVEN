#include <stdio.h>
#include <string.h>

char pipe_buffer[256];
int data_ready = 0;

void parent_write(const char *msg) {
    strcpy(pipe_buffer, msg);
    printf("Parent: Written message into pipe.\n");
}

void parent_send_signal() {
    printf("Parent: Sending SIGUSR1 signal to child.\n");
    data_ready = 1;
}

void child_wait_for_signal() {
    printf("Child: Waiting for signal from parent...\n");
    if (data_ready == 1) {
        printf("Child: Received SIGUSR1 signal!\n");
        printf("Child: Reading from pipe -> \"%s\"\n", pipe_buffer);
    } else {
        printf("Child: No signal received, nothing to read.\n");
    }
}

int main() {
    printf("=== Simulated Inter-Process Communication (IPC) ===\n\n");

    parent_write("Hello child, this is your parent speaking!");
    parent_send_signal();
    child_wait_for_signal();

    printf("\n=== End of Simulation ===\n");
    return 0;
}
