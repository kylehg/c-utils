#ifndef LIST_H
#define LIST_H

#define NOT_FOUND -1

typedef struct item_t {
    void *val;                  // An arbitrary pointer
    int n;                      // A integer value
    struct item_t *prev, *next;
} item_t;

typedef struct list_t {
    int len;
    struct list_t *head, *tail;
} list_t;

typedef list_t ilist_t;

// Add the given value to the end of the list
void append(list_t *list, void *val);
void nappend(ilist_t *list, int n);

// Add the given value to the list at the given index
void add(list_t *list, int idx, void *val);
void nadd(ilist_t *list, int idx, int n);

// Add the given value to the end of the list
void prepend(list_t *list, void *val);
void nprepend(ilist_t *list, int n);

// Lookup the value at the given index
void *get(list_t *list, int idx);
int nget(ilist_t *list, int idx);

// Remove the item at the head of the list and return the value
void *pop_first(list_t *list);
int npop_first(ilist_t *list);

// Remove the item at the end of the list and return the value
void *pop_last(list_t *list);
int npop_last(ilist_t *list);

// Remove the item at the given index of the list and return its value
void *pop_idx(list_t *list, int idx);
int npop_idx(ilist_t *list, int idx);

// Remove the first occurence of the given value from the list
// @return The index the item was at, or -1 of not present
int remove(list_t *list, void *val);
int nremove(ilist_t *list, int n);

// Remove the given node from the list (assuming it is already in the list)
void remove_item(list_t *list, item_t *item);

// Convert the list to an array
void **to_arr(list_t *list);
int *to_narr(ilist_t *list);

#endif
