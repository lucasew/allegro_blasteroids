#include <signal.h>
#include <blasteroids/utils/signal.h>

#define NULL 0

int catch_signal(int sig, void (*handler)(int)) {
#ifndef WIN32
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
#else
    return signal(SIGINT, handler) ? 0: 1;
#endif
}
