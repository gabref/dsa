#ifndef ARRAY_H
#define ARRAY_H

typedef struct garray {
    int size;
    int capacity;
    int *data;
} garray;

#define K_MIN_CAPACITY 1
#define K_GROWTH  2
#define K_SHRINK 4

garray * garray_new(int capacity);
int garray_size(garray * arr);
int garray_capacity(garray * arr);
int garray_is_empty(garray * arr);
void garray_destroy(garray * arr);
void garray_push(garray * arr, int value);
void garray_insert(garray * arr, int index, int value);
void garray_prepend(garray * arr, int value);
int garray_pop(garray * arr);
void garray_delete(garray * arr, int index);
void garray_remove(garray * arr, int value);
int garray_find(garray * arr, int value);
int garray_at(garray * arr, int index);
void garray_print(garray * arr);

// =================
// ===== UTILS =====
// =================

int garray_determine_capacity(int capacity);
void garray_upsize(garray * arr);
void garray_downsize(garray * arr);
void garray_resize_for_size(garray * arr, int candidate_size);
void check_address(void * arr);

#endif
