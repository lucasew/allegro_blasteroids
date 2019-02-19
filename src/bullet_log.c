#include <blasteroids/bullet_struct.h>
#include <blasteroids/config.h>
#include <blasteroids/util_log.h>

void blasteroids_bullet__log(char *reason, struct Bullet *b) {
#ifdef DEBUG_BULLET
    debug("bullet %s (%f, %f) h:%f s:%f pw:%i", reason, b->sx, b->sy, b->heading, b->speed, b->power);
#endif
}
