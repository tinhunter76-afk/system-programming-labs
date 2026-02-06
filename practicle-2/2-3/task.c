#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t stop = 0;

void handle_sigint(int sig) {
    (void)sig;  // чтобы не было warning
    const char msg[] = "Caught SIGINT\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
    stop = 1;
}

int main(void) {
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        const char err[] = "sigaction error\n";
        write(STDERR_FILENO, err, sizeof(err) - 1);
        _exit(1);
    }

    while (!stop) {
        write(STDOUT_FILENO, "Working...\n", 11);
        sleep(1);
    }

    return 0;
}