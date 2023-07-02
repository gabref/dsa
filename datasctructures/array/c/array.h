#ifndef ARRAY_H
#define ARRAY_H

typedef struct garray {
    int size;
    int capacity;
    int *data;
} garray;

garray * garray_new(int capacity);

#endif
