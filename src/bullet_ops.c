#include <blasteroids/bullet_struct.h>
#include <blasteroids/bullet_log.h>
#include <blasteroids/util_draw.h>
#include <blasteroids/config.h>

void blasteroids_bullet__destroy(struct Bullet **b) {
    if (b == NULL) return;
    if (*b == NULL) return;
    struct Bullet *dummy, *this = *b;
    while (this != NULL) {
        dummy = this;
        this = this->next;
        free(dummy);
    }
}

void blasteroids_bullet__update(struct Bullet *b, int HearthBeat) {
    if (b == NULL) return;
    b->sx = b->sx + blasteroids_get_delta_x(b->speed, b->heading)/FPS;
    b->sy = b->sy + blasteroids_get_delta_y(b->speed, b->heading)/FPS;
    if(!(HearthBeat%60)) {
        b->power--;
        blasteroids_bullet__log("update", b);
    }
}
