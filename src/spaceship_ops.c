#include <blasteroids/spaceship_struct.h>
#include <blasteroids/util_draw.h>
#include <blasteroids/spaceship_log.h>

void blasteroids_ship__get_delta(float *deltax, float *deltay, Spaceship *s) {
    // debug
    Spaceship sp;
    sp.sx = blasteroids_get_delta_x(s->speed, s->heading);
    sp.sy = blasteroids_get_delta_y(s->speed, s->heading);
    sp.heading = s->heading;
    sp.speed = s->speed;
    sp.health = 1;
    blasteroids_spaceship__log("delta", &sp);
    *deltax = sp.sx;
    *deltay = sp.sy;
}
void blasteroids_ship__left(Spaceship *s) {
    s->heading = s->heading - HEADING_STEP;
   blasteroids_spaceship__log("left", s);
}

void blasteroids_ship__right(Spaceship *s) {
    s->heading = s->heading + HEADING_STEP;
    blasteroids_spaceship__log("right", s);
}

void blasteroids_ship__up(Spaceship *s) {
    float deltax, deltay;
    blasteroids_ship__get_delta(&deltax, &deltay, s);
    s->sx = s->sx + deltax;
    s->sy = s->sy + deltay;
    blasteroids_spaceship__log("up", s);
}

void blasteroids_ship__down(Spaceship *s) {
    float deltax, deltay;
    blasteroids_ship__get_delta(&deltax, &deltay, s);
    s->sx = s->sx - deltax;
    s->sy = s->sy - deltay;
    blasteroids_spaceship__log("down", s);
}

