#ifndef _BLASTEROIDS_EVENT
#define _BLASTEROIDS_EVENT

#include <allegro5/events.h>
#include <blasteroids/context.h>

void event_loop_once(GameContext *ctx, ALLEGRO_EVENT *event);

void handle_event(ALLEGRO_EVENT *ev, GameContext *ctx);

#endif
