#ifndef _BLASTEROIDS_ASTEROID_STRUCT
#define _BLASTEROIDS_ASTEROID_STRUCT

#include <allegro5/allegro.h>

struct Asteroid {
    float sx;
    float sy;
    float heading;
    float speed;
    float rot_velocity;
    float scale;
    int health;
    ALLEGRO_COLOR color;
    struct Asteroid *next;
};

typedef struct Asteroid Asteroid;

#endif
