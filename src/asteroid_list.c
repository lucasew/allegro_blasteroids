#include <blasteroids/asteroid_struct.h>
#include <blasteroids/asteroid_ops.h>
#include <blasteroids/util_log.h>

void blasteroids_asteroid__update_all(struct Asteroid *a) {
    struct Asteroid *this = a->next; // Não quero computar o estado do genesis
    while (this != NULL) {
        blasteroids_asteroid__update(this);
        this = this->next;
    }
}

void blasteroids_asteroid__append(struct Asteroid *old, struct Asteroid new) {//  Não é necessário dar malloc
    struct Asteroid *newp = malloc(sizeof(struct Asteroid));
    *newp = new;
    newp->next = old->next;
    debug("append");
    old->next = newp;
}

int blasteroids_asteroid__gc(struct Asteroid *a) {
    int destroyed = 0;
    debug("Removendo asteroides destruidos da memória...");
    if (a->next == NULL) return destroyed;
    struct Asteroid *previous = a, *this = a->next;
    while (this != NULL) {
        if (this->health <= 0) {
            previous->next = this->next;
            free(this);
            destroyed++;
        }
        previous = this;
        this = this->next;
    }
    return destroyed;
}

