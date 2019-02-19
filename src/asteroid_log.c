#include <blasteroids/asteroid_struct.h>
#include <blasteroids/util_log.h>
#include <blasteroids/config.h>

void blasteroids_asteroid__log(char *reason, struct Asteroid *a) {
#ifdef DEBUG_ASTEROID
    debug("asteroid %s (%f, %f) heading:%f speed:%f rot_velocity:%f scale:%f health:%i", reason, a->sx, a->sy, a->heading, a->speed, a->rot_velocity, a->scale, a->health);
#endif
}


