#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/transformations.h>
#include <stdio.h>
#include <math.h>

#include <blasteroids/spaceship.h>
#include <blasteroids.h>

#define HEADING_STEP 10

void blasteroids_ship_draw(Spaceship *s) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, deg2rad(s->heading));
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);
    al_draw_line(-8, 9, 0, -11, s->color, 3.0f);
    al_draw_line(0, -11, 8, 9, s->color, 3.0f);
    al_draw_line(-6, 4, -1, 4, s->color, 3.0f);
    al_draw_line(6, 4, 1, 4, s->color, 3.0f);
}

void _log_spaceship(char *direction, Spaceship *s) {
    debug("spaceship %s (%f, %f) heading:%f speed:%f gone:%i", direction, s->sx, s->sy, s->heading, s->speed, s->gone);
}

void blasteroids_ship_get_delta(float *deltax, float *deltay, Spaceship *s) {
    blasteroids_get_delta(deltax, deltay, s->speed, s->heading);
    // debug
    Spaceship sp;
    sp.sx = *deltax;
    sp.sy = *deltay;
    sp.heading = s->heading;
    sp.speed = s->speed;
    sp.gone = false;
    _log_spaceship("delta", &sp);
}

void blasteroids_ship_left(Spaceship *s) {
    s->heading = s->heading - HEADING_STEP;
   _log_spaceship("left", s);
}

void blasteroids_ship_right(Spaceship *s) {
    s->heading = s->heading + HEADING_STEP;
    _log_spaceship("right", s);
}

void blasteroids_ship_up(Spaceship *s) {
    float deltax, deltay;
    blasteroids_ship_get_delta(&deltax, &deltay, s);
    s->sx = s->sx + deltax;
    s->sy = s->sy + deltay;
    _log_spaceship("up", s);
}

void blasteroids_ship_down(Spaceship *s) {
    float deltax, deltay;
    blasteroids_ship_get_delta(&deltax, &deltay, s);
    s->sx = s->sx - deltax;
    s->sy = s->sy - deltay;
    _log_spaceship("down", s);
}

void blasteroids_spaceship_get_center(float *cx, float *cy, Spaceship *s) {
#ifndef SPACESHIP_SIZE_X
    error("spaceship_get_center: Constantes não definidas");
#endif
    float dummy; // Lixo
    blasteroids_get_delta(cx, &dummy, (float)SPACESHIP_SIZE_X, s->heading);
    blasteroids_get_delta(&dummy, cy, (float)SPACESHIP_SIZE_Y, s->heading);
    *cy = *cy * -1;
    *cx = *cx + s->sx;
    *cy = *cy + s->sy;
}

