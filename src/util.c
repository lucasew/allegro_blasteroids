#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <allegro5/allegro.h>
#include <blasteroids/config.h>
#include <blasteroids/main.h>
#include <blasteroids/util.h>

/* util_draw */
float deg2rad(float deg) {
    return 0.0174532925 * deg;
}

float blasteroids_get_delta_x(float speed, float degrees) {
    return speed * sin((double)deg2rad(degrees));
}

float blasteroids_get_delta_y(float speed, float degrees) {
    return speed * cos((double)deg2rad(degrees)) * -1;
}

float blasteroids_get_distance(float ax, float ay, float bx, float by) {
    float x, y;
    x = ax - bx; // Não temos distancia negativa
    y = ay - by;
    return sqrtf(x*x + y*y); // Vi va pitágoras :p
}

/* util_log */
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

/* util_rand */
int randomize(int max) {
    int r;
    do {
        r = rand() % max;
    } while (r == 0);
    return r;
}

ALLEGRO_COLOR blasteroids_rand_color() {
    return al_map_rgb(randomize(255), randomize(255), randomize(255));
}

/* util_signal */
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
