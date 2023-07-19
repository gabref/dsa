#include "hash.h"

ghash * ghash_create(int size) {
    ghash *table = (ghash *) malloc(sizeof(ghash));
    check_address(table);

    table->size = size;
    table->data = malloc(sizeof(gnode) * size);
    check_address(table->data);

    for (int i = 0; i < size; i++) {
        *(table->data + i) = NULL;
    }

    return table;
}

void ghash_add(ghash *table, char *key, char * value) {
    int idx = _get_hash(key, table->size);

    gnode * node = _get(table, key);

    if (node == NULL) {
        gnode *temp = (gnode *) malloc(sizeof(gnode));
        check_address(temp);

        temp->key = key;
        temp->value = value;
        temp->next = NULL;

        temp->next = *(table->data + idx);
        *(table->data + idx) = temp;
        return;
    }

    node->value = value;
}

int ghash_exists(ghash *table, char *key) {
    return _get(table, key) == NULL ? 0 : 1;
}

char * ghash_get(ghash *table, char *key) {
    gnode * node = _get(table, key);
    return node == NULL ? "" : node->value;
}

void ghash_remove(ghash *table, char *key) {
    gnode * node = _get(table, key);
    if (node == NULL) return;

    int idx = _get_hash(key, table->size);

    gnode *current = *(table->data + idx);
    gnode *prev = (gnode *) malloc(sizeof(gnode));
    check_address(prev);
    prev = NULL;

    while(current) {
        if (strcmp(current->key, key) == 0)
            break;
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        *(table->data + idx) = current->next;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }
}

void ghash_print(ghash *table) {
    for (int i = 0; i < table->size; i++) {
        printf("%d | ", i);
        for (gnode *current = *(table->data + i); current; current = current->next)
            printf("%s : %s | ", current->key, current->value);
        printf("\n");
    }
    printf("\n\n");
}

void ghash_destroy(ghash *table) {
    for (int i = 0; i < table->size; i++) {
        gnode *current = *(table->data + i);
        while (current) {
            gnode *temp = current;
            current = current->next;
            free(temp);
        }
        free(current);
    }
    free(table);
}

int _get_hash(char *key, const int table_size) {
    char character = *(key);
    int hash = 1;
    int i;

    for (i = 0; character != '\0'; i++) {
        hash = hash + character * 2;
        character = *(key + i);
    }
    return (hash % table_size);
}

gnode * _get(ghash *table, char *key) {
    int idx = _get_hash(key, table->size);

    gnode * head = *(table->data + idx);

    for (gnode *current = head; current; current = current->next) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
    }

    return NULL;
}

void check_address(void * p) {
    if (p != NULL) return;
    fprintf(stderr, "Unable to allocate memory\n");
    exit(EXIT_FAILURE);
}
