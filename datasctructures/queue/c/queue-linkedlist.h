#ifndef QUEUE_LINKEDLIST
#define QUEUE_LINKEDLIST

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int data;
    struct queue * next;
} gqueue;

gqueue * gqueue_create();
void gqueue_enqueue(gqueue ** queue, int value);
int gqueue_dequeue(gqueue ** queue);
int gqueue_is_empty(gqueue ** queue);
void gqueue_print(gqueue ** queue);
void gqueue_destroy(gqueue ** queue);
void check_address(void * p);

#endif
