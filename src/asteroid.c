#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <blasteroids/main.h>
#include <blasteroids/asteroid.h>
#include <blasteroids/utils.h>
#include <blasteroids/config.h>

void _log_asteroid(char *reason, struct Asteroid *a) {
#ifdef DEBUG_ASTEROID
    debug("asteroid %s (%f, %f) heading:%f speed:%f rot_velocity:%f scale:%f health:%i", reason, a->sx, a->sy, a->heading, a->speed, a->rot_velocity, a->scale, a->health);
#endif
}

const float asteroid_points[ASTEROID_SEGMENTS][2] = {
    {-20, 20},
    {-25, 5},
    {-25, -10},
    {-5, -10},
    {-10, -20},
    {5, -20},
    {20, -10},
    {20, -5},
    {0, 0},
    {20, 10},
    {10, 20},
    {0, 15}
};

void blasteroids_asteroid_draw(struct Asteroid *a) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, deg2rad(a->heading));
    al_translate_transform(&transform, a->sx, a->sy);
    al_use_transform(&transform);
    int i;
    for (i = 0; i < (ASTEROID_SEGMENTS); i++) {
        al_draw_line_scaled(
                asteroid_points[i][0],
                asteroid_points[i][1],
                asteroid_points[(i + 1)%ASTEROID_SEGMENTS][0], // O módulo é para quando ele chegar no final da lista
                asteroid_points[(i + 1)%ASTEROID_SEGMENTS][1],
                a->color, 2.0f, a->scale);
    }
}

void blasteroids_asteroid_draw_all(struct Asteroid *a) {
    struct Asteroid *tmp = a;
    while (tmp != NULL) {
        blasteroids_asteroid_draw(tmp);
        tmp = tmp->next;
    }
}

void blasteroids_asteroid_update(struct Asteroid *a) {
    _log_asteroid("before", a);
    a->heading = a->heading + a->rot_velocity/FPS;
    a->sx = a->sx + blasteroids_get_delta_x(a->speed, a->heading)/FPS;
    a->sy = a->sy + blasteroids_get_delta_y(a->speed, a->heading)/FPS;
    _log_asteroid("after", a);
}

void blasteroids_asteroid_update_all(struct Asteroid *a) {
    struct Asteroid *this = a->next; // Não quero computar o estado do genesis
    while (this != NULL) {
        blasteroids_asteroid_update(this);
        this = this->next;
    }
}

void blasteroids_asteroid_append(struct Asteroid *old, struct Asteroid new) {//  Não é necessário dar malloc
    struct Asteroid *newp = malloc(sizeof(struct Asteroid));
    *newp = new;
    newp->next = old->next;
    debug("append");
    old->next = newp;
}

void blasteroids_destroy_asteroid(struct Asteroid *a) {
    struct Asteroid *dummy;
    a = a->next; // Primeiro asteroide não faz malloc
    while (a != NULL) {
        dummy = a;
        a = a->next;
        free(dummy);
    }
}

int blasteroids_asteroid_gc(struct Asteroid *a) {
    int destroyed = 0;
    debug("Removendo asteroides destruidos da memória...");
    if (a->next == NULL) return destroyed;
    struct Asteroid *previous = a, *this = a->next;
    while (this != NULL) {
        if (this->health <= 0) {
            previous->next = this->next;
            free(this);
            destroyed++;
        }
        previous = this;
        this = this->next;
    }
    return destroyed;
}

struct Asteroid blasteroids_asteroid_generate(int max_x, int max_y) {
    struct Asteroid as;
    as.sx = (float)frand(max_x);
    as.sy = (float)frand(max_y);
    as.heading = (float)frand(360);
    as.speed = ((float)frand(200)/10.0);
    as.rot_velocity = (float)frand(20);
    as.scale = ((float)frand(40))/10 + 0.5;
    as.health = frand(200);
    as.color = rand_color();
    as.next = NULL;
    return as;
}
