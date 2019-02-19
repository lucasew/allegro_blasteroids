#ifndef _BLASTEROIDS_BULLET_OPS
#define _BLASTEROIDS_BULLET_OPS

#include <blasteroids/bullet_struct.h>

void blasteroids_bullet__destroy(struct Bullet *b);

void blasteroids_bullet__update(struct Bullet *b, int HearthBeat);

#endif
