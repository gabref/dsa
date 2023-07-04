#ifndef LL_H
#define LL_H

typedef struct node {
    int data;
    struct node * next;
} gnode;

gnode * gll_create();
int gll_size(gnode ** head);
int gll_is_empty(gnode ** head);
int gll_at(gnode ** head, int index);
void gll_push_beg(gnode ** head, int value);
void gll_push_end(gnode ** head, int value);
void gll_print(gnode ** head);
void gll_destroy(gnode ** head);
void check_address(void * p);

#endif
