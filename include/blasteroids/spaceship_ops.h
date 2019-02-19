#ifndef _BLASTEROIDS_SPACESHIP_OPS
#define _BLASTEROIDS_SPACESHIP_OPS

#include <blasteroids/spaceship_struct.h>

void blasteroids_ship__get_delta(float *deltax, float *deltay, Spaceship *s);

void blasteroids_ship__left(Spaceship *s);

void blasteroids_ship__right(Spaceship *s);

void blasteroids_ship__up(Spaceship *s);

void blasteroids_ship__down(Spaceship *s);

#endif
