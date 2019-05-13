#ifndef _BLASTEROIDS_ASTEROID_DRAW
#define _BLASTEROIDS_ASTEROID_DRAW

#include <blasteroids/asteroid_struct.h>
const int QTD_POINTS;
const float asteroid_points;

void blasteroids_asteroid__draw(struct Asteroid *a);

void blasteroids_asteroid__draw_all(struct Asteroid **a);

#endif
