#include <blasteroids/config.h>
#include <blasteroids/asteroid_log.h>
#include <blasteroids/util_draw.h>
#include <blasteroids/util_rand.h>

void blasteroids_asteroid__update(struct Asteroid *a) {
    blasteroids_asteroid__log("before", a);
    a->heading = a->heading + a->rot_velocity/FPS;
    a->sx = a->sx + blasteroids_get_delta_x(a->speed, a->heading)/FPS;
    a->sy = a->sy + blasteroids_get_delta_y(a->speed, a->heading)/FPS;
    blasteroids_asteroid__log("after", a);
}

void blasteroids_asteroid__destroy(struct Asteroid *a) {
    struct Asteroid *dummy;
    a = a->next; // Primeiro asteroide não faz malloc
    while (a != NULL) {
        dummy = a;
        a = a->next;
        free(dummy);
    }
}

struct Asteroid blasteroids_asteroid__generate(int max_x, int max_y) {
    struct Asteroid as;
    as.sx = (float)randomize(max_x);
    as.sy = (float)randomize(max_y);
    as.heading = (float)randomize(360);
    as.speed = ((float)randomize(200)/10.0);
    as.rot_velocity = (float)randomize(20);
    as.scale = ((float)randomize(40))/10 + 0.5;
    as.health = randomize(200);
    as.color = blasteroids_rand_color();
    as.next = NULL;
    return as;
}

