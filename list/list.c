#include <assert.h>
#include "list.h"

list_t *init_list() {
    list_t *list = malloc(sizeof(list_t));
    list->len  = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void _append(list_t *list, item_t *item) {
    assert(list != NULL);

    if (list->tail) {
        list->tail->next = item;
    } else {
        list->head = item;
    }

    item->prev = list->tail;
    list->tail = item;
    list->len++;
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
    list->len++;
}

item_t *_find(list_t *list, int (*pred)(item_t *)) {
    item_t *cur;

    assert(list != NULL);
    assert(pred != NULL);

    for (cur = list->head; cur; cur = cur->next) {
        if (pred(cur)) {
            return cur;
        }
    }
    return NULL;
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
    list->len--;
}
