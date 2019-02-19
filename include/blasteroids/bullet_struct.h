#ifndef _BLASTEROIDS_BULLET_STRUCT
#define _BLASTEROIDS_BULLET_STRUCT

#include <allegro5/allegro.h>

struct Bullet {
    float sx;
    float sy;
    float heading;
    float speed;
    int power;
    ALLEGRO_COLOR color;
    struct Bullet *next;
};

typedef struct Bullet Bullet;

#endif
