#include <blasteroids/config.h>
#include <blasteroids/context.h>
#include <blasteroids/util_draw.h>
#include <blasteroids/util_log.h>
#include <blasteroids/asteroid_struct.h>
#include <blasteroids/asteroid_draw.h>
#include <blasteroids/bullet_struct.h>
#include <blasteroids/bullet_list.h>

int blasteroids_check_collision_asteroid_spaceship(GameContext *ctx) {
    int collisions = 0;
    if (ctx->asteroids.next == NULL) return collisions;
    float sx, sy; // Centro da nave
    float ax, ay; // Centro de um asteroide
    sx = ctx->ship.sx;
    sy = ctx->ship.sy;
    float cur_distance, min_distance;
    Asteroid *this = &ctx->asteroids;
    do {
        ax = this->sx;
        ay = this->sy;
        cur_distance = blasteroids_get_distance(sx, sy, ax, ay);
        min_distance = 10 + 22*this->scale;
#ifdef DEBUG_COLLISION_GRAPH
        // Linha entre o asteroide e a nave
        ALLEGRO_TRANSFORM t;
        al_identity_transform(&t); // Base canônica
        al_use_transform(&t);
        al_draw_line(sx, sy, ax, ay, al_map_rgb(255, 255, 255), 1);
#endif
        if (!(cur_distance > min_distance)) {
            if ((ctx->HearthBeat%(FPS/4)) == 0) {
                ctx->ship.health = ctx->ship.health - 1;
                this->health = this->health - 1;
                collisions++;
                ctx->score = ctx->score + 1;
            }
        }
        this = this->next;
    } while(this->next != NULL);
    return collisions;
}

int blasteroids_check_collision_asteroid_bullet(GameContext *ctx) {
    int collisions = 0;
    struct Asteroid *as = ctx->asteroids.next;
    struct Bullet *bu = ctx->bullets.next;
    if (as == NULL || bu == NULL) return collisions;
    float distancia;
    while (as != NULL) {
        bu = &ctx->bullets;
        while (bu != NULL) {
            distancia = blasteroids_get_distance(as->sx, as->sy, bu->sx, bu->sy);
            if (distancia < (22*as->scale)) {
                ctx->score = ctx->score + bu->power;
                as->health = as->health - bu->power;
                bu->power = 0;
                blasteroids_bullet__gc(&ctx->bullets);
                collisions++;
            }
            bu = bu->next;
        }
        as = as->next;
    }
    return collisions;
}

int blasteroids_is_collision(GameContext *ctx) {
    int collisions = 0;
    collisions += blasteroids_check_collision_asteroid_bullet(ctx);
    collisions += blasteroids_check_collision_asteroid_spaceship(ctx);
    if (collisions)
        debug("ACONTECERAM COLISÕES: %i", collisions);
    return collisions;
}
