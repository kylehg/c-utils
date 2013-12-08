#include <assert.h>
#include "list.h"

list_t *init_list() {
    list_t *list = malloc(sizeof(list_t));
    if (!list) {
        perror("init_list");
        return NULL;
    }

    list->len  = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Initalize an empty list item
item_t *_init_item() {
    item_t *item = malloc(sizeof(item_t));
    if (!item) {
        perror("_init_item");
        return NULL;
    }

    item->n    = DEFAULT_INT;
    item->val  = NULL;
    item->next = NULL;
    item->prev = NULL;
}

// Add a list item to the end of a list
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

void append(list_t *list, void *val) {
    item_t *item = _init_item();
    item->val = val;
    _append(list, item);
}

void nappend(ilist_t *list, int n) {
    item_t *item = _init_item();
    item->n = n;
    _append(list, item);
}

// Add a list item to the beginning of a list
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

void prepend(list_t *list, void *val) {
    item_t *item = _init_item();
    item->val = val;
    _prepend(list, item);
}

void nprepend(ilist_t *list, int n) {
    item_t *item = _init_item();
    item->n = n;
    _prepend(list, item);
}

// Return the list item at the given index, or NULL if index out of bounds
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

void *get(list_t *list, int idx) {
    item_t *item = _get(list, idx);
    return (item ? item->val : NULL);
}

int nget(ilist_t *list, int idx) {
    item_t *item = _get(list, idx);
    return (item ? item->n : NULL);
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

void *pop_idx(list_t *list, int idx) {
    list_t *item = _get(list, idx);
    if (!item) {
        return NULL;
    }

    void *val = item->val;
    remove_item(list, item);
    return val;
}

int npop_idx(ilist_t *list, int idx) {
    list_t *item = _get(list, idx);
    if (!item) {
        return NOT_FOUND;
    }

    int n = item->n;
    remove_item(list, item);
    return n;
}

void *pop_first(list_t *list) {
    return pop_idx(list, 0);
}

int npop_first(ilist_t *list) {
    return npop_idx(list, 0);
}

void *pop_last(list_t *list) {
    return pop_idx(list, (list->len - 1));
}

int npop_last(ilist_t *list) {
    return npop_idx(list, (list->len - 1));
}

int remove(list_t *list, void *val) {
    int idx = 0;
    item_t *cur;

    assert(list != NULL);
    assert(val != NULL);

    for (cur = list->head; cur; cur = cur->next, idx++) {
        if (cur->val == val) {
            return idx;
        }
    }
    return NOT_FOUND;
}

int nremove(ilist_t *list, int n) {
    int idx = 0;
    item_t *cur;

    assert(list != NULL);
    assert(n != DEFAULT_INT);

    for (cur = list->head; cur; cur = cur->next, idx++) {
        if (cur->n == n) {
            return idx;
        }
    }
    return NOT_FOUND;
}

void **to_arr(list_t *list) {
    int idx = 0;
    item_t *cur;
    void **arr;

    assert(list != NULL);

    arr = malloc(list->len);
    if (!arr) {
        perror("to_arr");
        return NULL;
    }

    for (cur = list->head; cur; cur = cur->next, idx++) {
        arr[idx] = cur->val;
    }
    return arr;
}

int *to_narr(ilist_t *list) {
    int idx = 0;
    item_t *cur;
    int *arr;

    assert(list != NULL);

    arr = malloc(list->len);
    if (!arr) {
        perror("to_narr");
        return NULL;
    }

    for (cur = list->head; cur; cur = cur->next, idx++) {
        arr[idx] = cur->n;
    }
    return arr;
}
