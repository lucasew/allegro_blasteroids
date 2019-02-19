#include <stdlib.h>
#include <allegro5/allegro.h>

int randomize(int max) {
    int r;
    do {
        r = rand() % max;
    } while (r == 0);
    return r;
}

ALLEGRO_COLOR blasteroids_rand_color() {
    return al_map_rgb(randomize(255), randomize(255), randomize(255));
}
