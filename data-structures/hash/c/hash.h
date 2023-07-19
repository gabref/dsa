#ifndef HASH_IMP
#define HASH_IMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char * key;
    char * value;
    struct node * next;
} gnode;

typedef struct {
    gnode ** data;
    int size;
} ghash;

ghash * ghash_create(int size);
void ghash_add(ghash *table, char *key, char *value);
int ghash_exists(ghash *table, char *key);
char * ghash_get(ghash *table, char *key);
void ghash_remove(ghash *table, char *key);
void ghash_print(ghash *table);
void ghash_destroy(ghash *table);
int _get_hash(char *key, const int table_size);
gnode * _get(ghash *table, char *key);
void check_address(void * p);

#endif
