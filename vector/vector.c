#include "vector.h"

vect_t *vector_init(int capacity) {
    vect_t *vect = malloc(sizeof(vect_t));
    if (!vect) {
        perror("vector_init");
        return NULL;
    }

    vect->data = calloc(capacity, sizeof(void *));
    vect->cap  = capacity;
    vect->size = 0;
    return vect;
}

void *vget(vect_t *vect, int idx);

void vset(vect_t *vect, int idx, void *val);

void vadd(vect_t *vect, void *val);

#endif
