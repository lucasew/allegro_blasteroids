#include <stdio.h>
#include <signal.h>
#include <blasteroids/config.h>
#include <blasteroids/config.h>
#include <blasteroids/main.h>
#include <stdarg.h>

void debug(const char *message, ...) {
#ifdef DEBUG
    va_list args;
    va_start(args, message);
    printf("DEBUG: ");
    vprintf(message, args);
    printf("\n");
    va_end(args);
#else
    (void)message;
#endif
}

void error(const char *message, ...) {
    va_list args;
    va_start(args, message);
    printf("ERRO: ");
    vprintf(message, args);
    printf("\n");
    va_end(args);
    stop(SIGTERM); // Manda fechar
}

void info(const char *message, ...) {
    va_list args;
    va_start(args, message);
    printf("INFO: ");
    vprintf(message, args);
    printf("\n");
    va_end(args);
}
