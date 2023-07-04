#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

gnode * gll_create() {
    gnode * head = (gnode *) malloc(sizeof(gnode));
    check_address(head);
    head = NULL;
    return head;
}

int gll_size(gnode ** head) {
    int size = 0;
    for (gnode * current; current != NULL; current = current->next)
        size++;
    return size;
}

int gll_is_empty(gnode ** head) {
    return *head == NULL ? 1 : 0;
}

int gll_at(gnode ** head, int index) {
    if (index < 0) {
        fprintf(stderr, "Index out of bound\n");
        exit(EXIT_FAILURE);
    }
    gnode *current = *head;
    for (int i = 0; i < index; i++) {
        if (current->next == NULL) {
            fprintf(stderr, "Index out of bound\n");
            exit(EXIT_FAILURE);
        }
        current = current->next;
    }
    return current->data;
}

void gll_push_beg(gnode ** head, int value) {
    gnode * temp = (gnode *) malloc(sizeof(gnode));
    check_address(temp);

    temp->data = value;
    temp->next = *head;
    *head = temp;
}

void gll_push_end(gnode ** head, int value) {
    gnode * current = *head;

    gnode * temp = (gnode *) malloc(sizeof(gnode));
    check_address(temp);

    if (current != NULL) {
        while(current->next != NULL)
            current = current->next;

        temp->data = value;
        temp->next = NULL;
        current->next = temp;
    } else {
        temp->data = value;
        temp->next = NULL;
        *head = temp;
    }
}

void gll_print(gnode ** head) {
    printf("\n\n*** LinkedList ***\n");
    for (gnode *current = *head; current != NULL; current = current->next)
        printf("%d -> ", current->data);
    printf("NULL\n\n");
}

void gll_destroy(gnode ** head) {
    gnode * temp = (gnode *) malloc(sizeof(gnode));
    check_address(temp);
    gnode * current = *head;

    while(*head != NULL) {
        temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void check_address(void *p) {
    if (p == NULL) {
        fprintf(stderr, "Failed to allocate more memory!\n");
        exit(EXIT_FAILURE);
    }
}
