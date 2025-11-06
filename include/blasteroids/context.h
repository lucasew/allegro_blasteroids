#ifndef _BLASTEROIDS_CONTEXT
#define _BLASTEROIDS_CONTEXT

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <blasteroids/asteroid_struct.h>
#include <blasteroids/spaceship_struct.h>
#include <blasteroids/bullet_struct.h>

struct GameContext {
    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font;
    ALLEGRO_FILE *font_memfile;  // Keep memfile open while font is in use
    unsigned char *font_data_copy;  // Writable copy of embedded font data
    struct Spaceship ship;
    struct Asteroid **asteroids;
    struct Bullet **bullets;
    short lifes;
    int HearthBeat;
    int score;
};

typedef struct GameContext GameContext;

void blasteroids_context__tick(GameContext *ctx);

void blasteroids_context__update(GameContext *ctx);

void blasteroids_context__draw(GameContext *ctx);

int blasteroids_display__w(GameContext *ctx);

int blasteroids_display__h(GameContext *ctx);

void blasteroids_asteroid__draw_life(GameContext *ctx);

void blasteroids_bullet__shot(GameContext *ctx);

void blasteroids_asteroid__generate_and_append(GameContext *ctx);

#endif
