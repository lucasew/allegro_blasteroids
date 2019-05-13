#include <blasteroids/bullet_struct.h>
#include <blasteroids/bullet_ops.h>
#include <blasteroids/bullet_log.h>
#include <blasteroids/asteroid_log.h>
#include <blasteroids/util_log.h>


void blasteroids_bullet__gc(struct Bullet **b) {
    debug("Removendo tiros destruidos da memória...");
    if (b == NULL) return;
    if (*b == NULL) return;
    struct Bullet *dummy, *previous = *b, *this = (*b)->next;
    while (this != NULL) {
        if (this->power <= 0) {
            dummy = this;
            previous->next = this->next;
            free(dummy);
            return;
        }
        previous = this;
        this = this->next;
    }
}

void blasteroids_bullet__append(struct Bullet **old, struct Bullet new) {
    blasteroids_bullet__log("append", &new);
    if (old == NULL) return;
    if (*old == NULL ) {
        *old = malloc(sizeof(struct Bullet));
        if (*old == NULL) {
            return;
        }
        *(*old) = new;
        (*old)->next = NULL;
        return;
    }
    struct Bullet *newp = malloc(sizeof(struct Bullet));
    if (newp == NULL)
        return;
    *newp = new;
    newp->next = *old;
    *old = newp;
}

void blasteroids_bullet__update_all(struct Bullet **b, int HearthBeat) {
    if(b == NULL) return;
    if(*b == NULL) return;
    struct Bullet *this = *b;
    while (this != NULL) {
        blasteroids_bullet__update(this, HearthBeat);
        this = this->next;
    }
}
