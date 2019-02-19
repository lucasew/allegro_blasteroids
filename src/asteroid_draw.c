#include <allegro5/allegro5.h>
#include <blasteroids/asteroid_struct.h>
#include <blasteroids/util_draw.h>

const int QTD_POINTS = 12;
const float asteroid_points[][2] = {
    {-20, 20},
    {-25, 5},
    {-25, -10},
    {-5, -10},
    {-10, -20},
    {5, -20},
    {20, -10},
    {20, -5},
    {0, 0},
    {20, 10},
    {10, 20},
    {0, 15}
};

void blasteroids_asteroid__draw(struct Asteroid *a) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, deg2rad(a->heading));
    al_translate_transform(&transform, a->sx, a->sy);
    al_use_transform(&transform);
    int i;
    for (i = 0; i < (QTD_POINTS); i++) {
        al_draw_line_scaled(
                asteroid_points[i][0],
                asteroid_points[i][1],
                asteroid_points[(i + 1)%QTD_POINTS][0], // O módulo é para quando ele chegar no final da lista
                asteroid_points[(i + 1)%QTD_POINTS][1],
                a->color, 2.0f, a->scale);
    }
}

void blasteroids_asteroid__draw_all(struct Asteroid *a) {
    struct Asteroid *tmp = a;
    while (tmp != NULL) {
        blasteroids_asteroid__draw(tmp);
        tmp = tmp->next;
    }
}

