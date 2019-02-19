#include <blasteroids/spaceship_struct.h>
#include <blasteroids/util_log.h>
#include <blasteroids/config.h>

void blasteroids_spaceship__log(char *direction, Spaceship *s) {
#ifdef DEBUG_SPACESHIP
    debug("spaceship %s (%f, %f) heading:%f speed:%f health:%i", direction, s->sx, s->sy, s->heading, s->speed, s->health);
#endif
}


