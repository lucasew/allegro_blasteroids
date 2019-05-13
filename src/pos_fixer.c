#include <blasteroids/context.h>
#include <blasteroids/spaceship_struct.h>
#include <blasteroids/asteroid_struct.h>
#include <blasteroids/bullet_struct.h>

void constraint2zero(float *in, float lim) {
    if (*in > lim) *in = 0;
    if (*in < 0) *in = lim;
}

void blasteroids_fix_positions(GameContext *ctx) {
    int w = blasteroids_display__w(ctx);
    int h = blasteroids_display__h(ctx);
    constraint2zero(&ctx->ship.sx, w);
    constraint2zero(&ctx->ship.sy, h);
    if (ctx->asteroids && *ctx->asteroids) {
        Asteroid *adummy = *ctx->asteroids;
        while (adummy != NULL) {
            constraint2zero(&adummy->sx, w);
            constraint2zero(&adummy->sy, h);
            adummy = adummy->next;
        }
    }
    if (ctx->bullets != NULL && *ctx->bullets != NULL) {
        Bullet *bdummy = *ctx->bullets;
        while (bdummy != NULL) {
            constraint2zero(&bdummy->sx, w);
            constraint2zero(&bdummy->sy, h);
            bdummy = bdummy->next;
        }
    }
}
