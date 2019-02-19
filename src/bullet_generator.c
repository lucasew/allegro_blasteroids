#include <blasteroids/asteroid_struct.h>
#include <blasteroids/bullet_struct.h>
#include <blasteroids/spaceship_struct.h>
#include <blasteroids/util_rand.h>


struct Bullet blasteroids_bullet__generate(struct Spaceship sp) {
    Bullet bt;
    bt.sx = sp.sx;
    bt.sy = sp.sy;
    bt.heading = sp.heading;
    bt.speed = 1 + randomize(100);
    bt.power = 1 + randomize(50);
    bt.color = blasteroids_rand_color();
    bt.next = NULL;
    return bt;
}
