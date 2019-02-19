#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <blasteroids/bullet_struct.h>
#include <blasteroids/bullet_draw.h>
#include <blasteroids/util_draw.h>


void blasteroids_bullet__draw(struct Bullet *b) {
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_rotate_transform(&t, deg2rad(b->heading));
    al_translate_transform(&t, b->sx, b->sy);
    al_use_transform(&t);
    al_draw_line(1, 0, 0, 1, b->color, 2.0f);
    al_draw_line(0, 1, -1, 0, b->color, 2.0f);
    al_draw_line(-1, 0, 0, -1, b->color, 2.0f);
    al_draw_line(0, -1, 1, 0, b->color, 2.0f);
}

void blasteroids_bullet__draw_all(struct Bullet *b) {
    struct Bullet *tmp = b->next;
    while (tmp != NULL) {
        blasteroids_bullet__draw(tmp);
        tmp = tmp->next;
    }
}


