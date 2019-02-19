#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <blasteroids/context.h>

#include <blasteroids/text_draw.h>

void blasteroids_life__draw(GameContext *ctx) {
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_use_transform(&t);
    al_draw_textf(ctx->font, al_map_rgb(0, 0, 255), 10, 10, ALLEGRO_ALIGN_LEFT, "<3 %i", ctx->ship.health);
}

void blasteroids_counter__draw(GameContext *ctx) {
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_use_transform(&t);
    al_draw_textf(ctx->font, al_map_rgb(255, 255, 255), blasteroids_display__w(ctx)/3, 10, ALLEGRO_ALIGN_RIGHT, "C: %i", ctx->HearthBeat);
}

void blasteroids_score__draw(GameContext *ctx) {
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_use_transform(&t);
    al_draw_textf(ctx->font, al_map_rgb(0, 255, 0), 2*blasteroids_display__w(ctx)/3, 10, ALLEGRO_ALIGN_RIGHT, "PTS: %i", ctx->score);
}
