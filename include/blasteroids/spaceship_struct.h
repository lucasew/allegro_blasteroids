#ifndef _BLASTEROIDS_SPACESHIP_STRUCT
#define _BLASTEROIDS_SPACESHIP_STRUCT

#include <allegro5/allegro5.h>

// Quantos graus a nave vai virar a cada vez que apertamos direita ou esquerda
#define HEADING_STEP 10

// Colisão
#define SPACESHIP_SIZE_X 8 // -8
#define SPACESHIP_SIZE_Y 10 // -10

struct Spaceship {
    float sx;
    float sy;
    float heading;
    float speed;
    int health;
    ALLEGRO_COLOR color;
};

typedef struct Spaceship Spaceship;

#endif
