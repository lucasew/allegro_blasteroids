#include <blasteroids/spaceship_struct.h>
#include <allegro5/allegro_primitives.h>
#include <blasteroids/util_draw.h>

#define SPACESHIP_LINE_THICKNESS 3.0f

static const int SPACESHIP_LINES_COUNT = 4;
static const float spaceship_lines[][4] = {
    {-8, 9, 0, -11},
    {0, -11, 8, 9},
    {-6, 4, -1, 4},
    {6, 4, 1, 4}
};

void blasteroids_ship__draw(Spaceship s) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, deg2rad(s.heading));
    al_translate_transform(&transform, s.sx, s.sy);
    al_use_transform(&transform);

    for (int i = 0; i < SPACESHIP_LINES_COUNT; i++) {
        al_draw_line(
            spaceship_lines[i][0], spaceship_lines[i][1],
            spaceship_lines[i][2], spaceship_lines[i][3],
            s.color, SPACESHIP_LINE_THICKNESS
        );
    }
}


