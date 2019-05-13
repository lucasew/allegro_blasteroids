#ifndef _BLASTEROIDS_ASTEROID_OPS
#define _BLASTEROIDS_ASTEROID_OPS

#include <blasteroids/asteroid_struct.h>

void blasteroids_asteroid__log(char *reason, struct Asteroid);

void blasteroids_asteroid__update(struct Asteroid *a);

void blasteroids_asteroid__destroy(struct Asteroid **a);

struct Asteroid blasteroids_asteroid__generate(int max_x, int max_y);

#endif
