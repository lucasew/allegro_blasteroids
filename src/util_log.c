#include <stdio.h>
#include <signal.h>
#include <blasteroids/config.h>
#include <blasteroids/config.h>
#include <blasteroids/main.h>
#include <stdarg.h>

void debug(char *message, ...) {
#ifdef DEBUG
    va_list args;
    va_start(args, message);
    printf("DEBUG: ");
    vprintf(message, args);
    printf("\n");
#endif
}

void error(char *message, ...) {
    va_list args;
    va_start(args, message);
    printf("ERRO: ");
    vprintf(message, args);
    printf("\n");
    stop(SIGTERM); // Manda fechar
}

void info(char *message, ...) {
    va_list args;
    va_start(args, message);
    printf("INFO: ");
    vprintf(message, args);
    printf("\n");
}
