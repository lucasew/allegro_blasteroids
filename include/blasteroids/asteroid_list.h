#ifndef _BLASTEROIDS_ASTEROID_LIST
#define _BLASTEROIDS_ASTEROID_LIST

#include <blasteroids/asteroid_struct.h>

void blasteroids_asteroid__update_all(struct Asteroid **a);

void blasteroids_asteroid__append(struct Asteroid **old, struct Asteroid new);

int blasteroids_asteroid__gc(struct Asteroid **a);

#endif
