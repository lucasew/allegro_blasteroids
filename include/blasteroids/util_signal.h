#ifndef _BLASTEROIDS_UTIL_SIGNAL
#define _BLASTEROIDS_UTIL_SIGNAL

#include <signal.h>

int catch_signal(int sig, void(*handler)(int));

#endif
