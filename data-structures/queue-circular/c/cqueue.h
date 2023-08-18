#ifndef IMPL_H
#define IMPL_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct queue {
  int head;
  int tail;
  int arr[MAX_SIZE];
} cqueue;


cqueue * create_cqueue();
int enqueue(cqueue *q, int data);
int dequeue(cqueue *q);
int empty(cqueue *q);
int cqueue_size(cqueue *q);
void print_debug(cqueue *q);
void destroy(cqueue *q);
void check_addr(void *p);

#endif
