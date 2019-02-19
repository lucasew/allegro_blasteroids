#include <blasteroids/config.h>
#include <blasteroids/asteroid_struct.h>
#include "blasteroids/spaceship_draw.h"
#include <blasteroids/bullet_struct.h>
#include <blasteroids/bullet_ops.h>
#include <blasteroids/bullet_list.h>
#include <blasteroids/bullet_draw.h>
#include <blasteroids/bullet_generator.h>
#include <blasteroids/asteroid_ops.h>
#include <blasteroids/asteroid_list.h>
#include <blasteroids/asteroid_draw.h>
#include <blasteroids/collision.h>
#include <blasteroids/pos_fixer.h>
#include <blasteroids/text_draw.h>

#include <blasteroids/context.h>

void blasteroids_context__tick(GameContext *ctx) {
    blasteroids_asteroid__update_all(&ctx->asteroids);
    blasteroids_bullet__update_all(&ctx->bullets, ctx->HearthBeat);
    blasteroids_context__update(ctx);
    blasteroids_context__draw(ctx);
}

void blasteroids_context__update(GameContext *ctx) {
    if (blasteroids_is_collision(ctx)) {
        if(0 != blasteroids_asteroid__gc(&ctx->asteroids)) // Ao matar um asteroide gerar outro, para dar mais emoção
            blasteroids_asteroid__generate_and_append(ctx);
        blasteroids_bullet__gc(&ctx->bullets);
    }
    blasteroids_fix_positions(ctx);
}

void blasteroids_context__draw(GameContext *ctx) {
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    blasteroids_ship__draw(&ctx->ship);
    blasteroids_asteroid__draw_all(&ctx->asteroids);
    blasteroids_bullet__draw_all(&ctx->bullets);
    blasteroids_life__draw(ctx);
    blasteroids_score__draw(ctx);
    blasteroids_asteroid__draw_life(ctx);
#ifdef DEBUG_DRAW_COUNTER
    blasteroids_counter__draw(ctx);
#endif
}

int blasteroids_display__w(GameContext *ctx) {
    return al_get_display_width(ctx->display);
}

int blasteroids_display__h(GameContext *ctx) {
    return al_get_display_height(ctx->display);
}

void blasteroids_asteroid__draw_life(GameContext *ctx) {
    if (ctx->asteroids.next == NULL) return;
    struct Asteroid *a = ctx->asteroids.next; // O primeiro só tá lá pra facilitar
    while (a != NULL) {
        ALLEGRO_TRANSFORM t;
        al_identity_transform(&t);
        al_translate_transform(&t, a->sx, a->sy);
        al_use_transform(&t);
        al_draw_textf(ctx->font, al_map_rgb(255, 0, 0), 0, 0, ALLEGRO_ALIGN_CENTER, "%i", a->health);
        a = a->next;
    }
}

void blasteroids_bullet__shot(GameContext *ctx) {
    blasteroids_bullet__append(&ctx->bullets, blasteroids_bullet__generate(ctx->ship));   
}

void blasteroids_asteroid__generate_and_append(GameContext *ctx) {
    struct Asteroid as = blasteroids_asteroid__generate(blasteroids_display__w(ctx), blasteroids_display__h(ctx));
    blasteroids_asteroid__append(&ctx->asteroids, as);
}
