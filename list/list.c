#include <assert.h>
#include "list.h"

void _append(list_t *list, item_t *item) {
    assert(list != NULL);

    if (list->tail) {
        list->tail->next = item;
    } else {
        list->head = item;
    }

    item->prev = list->tail;
    list->tail = item;
}

void _prepend(list_t *list, item_t *item) {
    assert(list != NULL);

    if (list->head) {
        list->head->prev = item;
    } else {
        list->tail = item;
    }

    item->next = list->head;
    list->head = item;
}

item_t *_get(list_t *list, int idx) {
    int i = 0;
    item_t *cur;

    assert(list != NULL);

    // Start from the beginning if looking in the first half,
    // otherwise from the end
    if (idx < (list->size >> 1)) {
        for (cur = list->head; cur; cur = cur->next) {
            if (i == idx) {
                return cur;
            }
            i++;
        }
    } else {
        for (cur = list->tail; cur; cur = cur->prev) {
            if (i == idx) {
                return cur;
            }
            i--;
        }
    }
    return NULL;
}

void remove_item(list_t *list, item_t *item) {
    assert(list != NULL);
    assert(item != NULL);

    if (item->prev) {
        item->prev->next = item->next;
    } else {
        list->head = item->next;
    }

    if (item->next) {
        item->next->prev = item->prev;
    } else {
        list->tail = item->prev;
    }
    free(item);
}