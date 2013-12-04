#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef list_t queue_t;
typedef list_t iqueue_t;

void enqueue(queue_t *queue, void *val);
void nenqueue(iqueue_t *queue, int n);
void *dequeue(queue_t *queue);
int ndequeue(iqueue_t *queue);
void *peek(queue_t *queue);
int npeek(iqueue_t *queue);

#endif
