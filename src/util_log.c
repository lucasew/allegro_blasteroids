#include <stdio.h>
#include <signal.h>
#include <blasteroids/config.h>
#include <stdlib.h>
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
    va_end(args);
#endif
}

void error(char *message, ...) {
    va_list args;
    va_start(args, message);
    fprintf(stderr, "ERRO: ");
    vfprintf(stderr, message, args);
    fprintf(stderr, "\n");
    va_end(args);
    stop(SIGTERM); // Manda fechar
    exit(EXIT_FAILURE);
}

void info(char *message, ...) {
    va_list args;
    va_start(args, message);
    printf("INFO: ");
    vprintf(message, args);
    printf("\n");
    va_end(args);
}
