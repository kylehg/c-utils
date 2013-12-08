#ifndef VECTOR_H
#define VECTOR_H

typedef struct vect_t {
    void **data;
    int len;
    int cap;
} vect_t;

// Initialize an empty vector
vect_t *vector_init();

// Get the value at the given index, or NULL if out of bounds
void *vget(vect_t *vect, int idx);

// Insert the value at the given index, overwriting any pervious value
void vset(vect_t *vect, int idx, void *val);

// Insert the value at the end of the vector, resizing if necessary
void vadd(vect_t *vect, void *val);

#endif
