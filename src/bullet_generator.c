#include <blasteroids/asteroid_struct.h>
#include <blasteroids/bullet_struct.h>
#include <blasteroids/spaceship_struct.h>
#include <blasteroids/util_rand.h>

#define BULLET_SPEED_MAX 100
#define BULLET_POWER_MAX 50

struct Bullet blasteroids_bullet__generate(struct Spaceship sp) {
    Bullet bt;
    bt.sx = sp.sx;
    bt.sy = sp.sy;
    bt.heading = sp.heading;
    bt.speed = 1 + randomize(BULLET_SPEED_MAX);
    bt.power = 1 + randomize(BULLET_POWER_MAX);
    bt.color = blasteroids_rand_color();
    bt.next = NULL;
    return bt;
}
