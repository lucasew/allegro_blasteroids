#include <blasteroids/asteroid_struct.h>
#include <blasteroids/asteroid_ops.h>
#include <blasteroids/util_log.h>

void blasteroids_asteroid__update_all(struct Asteroid **a) {
    if (a == NULL) return;
    if (*a == NULL) return;
    struct Asteroid *this;
    this = *a;
    while (this != NULL) {
        blasteroids_asteroid__update(this);
        this = this->next;
    }
}

void blasteroids_asteroid__append(struct Asteroid **old, struct Asteroid new) {
    if (old == NULL) return;
    if (*old == NULL) {
        *old = malloc(sizeof(struct Asteroid));
        if (*old == NULL) return;
        *(*old) = new;
        (*old)->next = NULL;
        return;
    }
    struct Asteroid *newp = malloc(sizeof(struct Asteroid));
    if (newp == NULL)
        return;
    *newp = new;
    newp->next = *old;
    *old = newp;
    debug("append");
}

int blasteroids_asteroid__gc(struct Asteroid **a) {
    if (a == NULL)
        return 0;
    if (*a == NULL)
        return 0;
    int destroyed = 0;
    debug("Removendo asteroides destruidos da memória...");
    struct Asteroid *previous = *a, *this = (*a)->next;
    while (this != NULL) {
        if (this->health <= 0) {
            previous->next = this->next;
            free(this);
            destroyed++;
        }
        previous = this;
        this = this->next;
    }
    if ((*a)->health <= 0) {
        struct Asteroid *dummy = (*a)->next;
        free(*a);
        *a = dummy;
        destroyed++;
    }
    return destroyed;
}

