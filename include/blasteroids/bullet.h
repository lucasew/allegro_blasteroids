#ifndef _BLASTEROIDS_BULLET
#define _BLASTEROIDS_BULLET

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

void blasteroids_bullet_draw(struct Bullet *b);

void blasteroids_bullet_draw_all(struct Bullet *b);

void blasteroids_bullet_update(struct Bullet *b, int HearthBeat);

void blasteroids_bullet_update_all(struct Bullet *b, int HearthBeat);

void blasteroids_bullet_append(struct Bullet *old, struct Bullet new);

void blasteroids_destroy_bullet(struct Bullet *b);

void blasteroids_bullet_gc(struct Bullet *b);

#endif
