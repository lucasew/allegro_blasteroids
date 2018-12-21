#include <blasteroids/pos_fixer.h>
#include <blasteroids/context.h>
#include <blasteroids/spaceship.h>
#include <blasteroids/asteroid.h>
#include <blasteroids/bullet.h>

void constraint2zero(float *in, float lim) {
    if (*in > lim) *in = 0;
    if (*in < 0) *in = lim;
}

void blasteroids_fix_positions(GameContext *ctx) {
    int w = blasteroids_display_w(ctx);
    int h = blasteroids_display_h(ctx);
    constraint2zero(&ctx->ship.sx, w);
    constraint2zero(&ctx->ship.sy, h);
    Asteroid *adummy = ctx->asteroids.next;
    while (adummy != NULL) {
        constraint2zero(&adummy->sx, w);
        constraint2zero(&adummy->sy, h);
        adummy = adummy->next;
    }
    Bullet *bdummy = ctx->bullets.next;
    while (bdummy != NULL) {
        constraint2zero(&bdummy->sx, w);
        constraint2zero(&bdummy->sy, h);
        bdummy = bdummy->next;
    }
}
