#include <blasteroids/spaceship_struct.h>
#include <allegro5/allegro_primitives.h>
#include <blasteroids/util_draw.h>

void blasteroids_ship__draw(Spaceship s) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, deg2rad(s.heading));
    al_translate_transform(&transform, s.sx, s.sy);
    al_use_transform(&transform);
    al_draw_line(-8, 9, 0, -11, s.color, 3.0f);
    al_draw_line(0, -11, 8, 9, s.color, 3.0f);
    al_draw_line(-6, 4, -1, 4, s.color, 3.0f);
    al_draw_line(6, 4, 1, 4, s.color, 3.0f);
}


