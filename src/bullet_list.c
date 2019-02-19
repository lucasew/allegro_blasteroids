#include <blasteroids/bullet_struct.h>
#include <blasteroids/bullet_ops.h>
#include <blasteroids/bullet_log.h>
#include <blasteroids/asteroid_log.h>
#include <blasteroids/util_log.h>


void blasteroids_bullet__gc(struct Bullet *b) {
    debug("Removendo tiros destruidos da memória...");
    if (b == NULL) return;
    struct Bullet *dummy, *previous = b, *this = b->next;
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

void blasteroids_bullet__append(struct Bullet *old, struct Bullet new) { // Eu dou malloc sozinho
    blasteroids_bullet__log("append", &new);
    struct Bullet *tmp = malloc(sizeof(struct Bullet));
    *tmp = new;
    if (old->next != NULL) {
        tmp->next = old->next;
    }
    old->next = tmp;
}

void blasteroids_bullet__update_all(struct Bullet *b, int HearthBeat) {
    struct Bullet *this = b->next; // Next ignora aquele bullet genesis
    while (this != NULL) {
        blasteroids_bullet__update(this, HearthBeat);
        this = this->next;
    }
}
