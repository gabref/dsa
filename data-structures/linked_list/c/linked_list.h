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
int gll_pop_beg(gnode ** head);
int gll_pop_end(gnode ** head);
int gll_get_beg(gnode ** head);
int gll_get_end(gnode ** head);
void gll_insert(gnode ** head, int index, int value);
void gll_delete(gnode ** head, int index);
void gll_remove(gnode ** head, int value);
int gll_find(gnode ** head, int value);

void gll_print(gnode ** head);
void gll_destroy(gnode ** head);
void check_address(void * p);

#endif
