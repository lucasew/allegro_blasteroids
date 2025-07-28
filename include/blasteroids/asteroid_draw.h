#ifndef _BLASTEROIDS_ASTEROID_DRAW
#define _BLASTEROIDS_ASTEROID_DRAW

#include <blasteroids/asteroid_struct.h>
extern const int QTD_POINTS;
extern const float asteroid_points[][2];

void blasteroids_asteroid__draw(struct Asteroid *a);

void blasteroids_asteroid__draw_all(struct Asteroid **a);

#endif
