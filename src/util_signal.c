#include <signal.h>

int catch_signal(int sig, void (*handler)(int)) {
#ifndef WIN32
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, 0); // 0 == NULL
#else
    return signal(SIGINT, handler) ? 0: 1;
#endif
}
