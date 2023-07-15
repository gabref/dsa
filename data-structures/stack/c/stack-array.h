#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int * data;
    int size;
    int capacity;
} gstack;

gstack * gstack_create();
void gstack_print(gstack ** stack);
void gstack_push(gstack ** stack, int value);
int gstack_pop(gstack ** stack);
int gstack_is_emtpy(gstack ** stack);
void check_address(void * p);

#endif
