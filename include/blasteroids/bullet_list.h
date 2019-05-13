#ifndef _BLASTEROIDS_BULLET_LIST
#define _BLASTEROIDS_BULLET_LIST

#include <blasteroids/bullet_struct.h>

void blasteroids_bullet__gc(struct Bullet **b);

void blasteroids_bullet__append(struct Bullet **old, struct Bullet new);

void blasteroids_bullet__update_all(struct Bullet **b, int HearthBeat);

#endif
