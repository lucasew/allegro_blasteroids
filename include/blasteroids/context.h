#ifndef _BLASTEROIDS_CONTEXT
#define _BLASTEROIDS_CONTEXT

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <blasteroids/spaceship.h>
#include <blasteroids/asteroid.h>
#include <blasteroids/bullet.h>

struct GameContext {
    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font;
    struct Spaceship ship;
    struct Asteroid asteroids;
    struct Bullet bullets;
    short lifes;
    int HearthBeat;
    int score;
};

typedef struct GameContext GameContext;

void blasteroids_context_tick(GameContext *ctx);

void blasteroids_context_update(GameContext *ctx);

void blasteroids_context_draw(GameContext *ctx);

int blasteroids_display_w(GameContext *ctx);

int blasteroids_display_h(GameContext *ctx);

void blasteroids_asteroid_draw_life(GameContext *ctx);

void blasteroids_bullet_shot(struct GameContext *ctx);

void blasteroids_asteroid_generate_and_append(GameContext *ctx);

#endif
