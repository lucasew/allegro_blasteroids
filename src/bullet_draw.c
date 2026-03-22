#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <blasteroids/bullet_struct.h>
#include <blasteroids/bullet_draw.h>
#include <blasteroids/util_draw.h>

#define BULLET_LINE_THICKNESS 2.0f

static const int BULLET_LINES_COUNT = 4;
static const float bullet_lines[][4] = {
    {1, 0, 0, 1},
    {0, 1, -1, 0},
    {-1, 0, 0, -1},
    {0, -1, 1, 0}
};


void blasteroids_bullet__draw(struct Bullet *b) {
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_rotate_transform(&t, deg2rad(b->heading));
    al_translate_transform(&t, b->sx, b->sy);
    al_use_transform(&t);

    for (int i = 0; i < BULLET_LINES_COUNT; i++) {
        al_draw_line(
            bullet_lines[i][0], bullet_lines[i][1],
            bullet_lines[i][2], bullet_lines[i][3],
            b->color, BULLET_LINE_THICKNESS
        );
    }
}

void blasteroids_bullet__draw_all(struct Bullet **b) {
    if (b == NULL) return;
    if (*b == NULL) return;
    struct Bullet *tmp = *b;
    while (tmp != NULL) {
        blasteroids_bullet__draw(tmp);
        tmp = tmp->next;
    }
}


