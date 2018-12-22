#include <stdlib.h>
#include <allegro5/allegro.h>

int frand(int max) {
    int r;
    do {
        r = rand() % max;
    } while (r == 0);
    return r;
}

ALLEGRO_COLOR rand_color() {
    return al_map_rgb(frand(255), frand(255), frand(255));
}
