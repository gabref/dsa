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

int gll_pop_beg(gnode ** head) {
    if (*head == NULL) {
        fprintf(stderr, "LinkedList is empty\n");
        exit(EXIT_FAILURE);
    }
    gnode *temp = *head;
    *head = temp->next;
    int popped_value = temp->data;
    free(temp);
    return popped_value;
}

int gll_pop_end(gnode ** head) {
    if (*head == NULL) {
        fprintf(stderr, "LinkedList is empty\n");
        exit(EXIT_FAILURE);
    }
    gnode *current = *head;
    gnode *prev = NULL;
    while(current->next != NULL) {
        prev = current;
        current = current->next;
    }

    int popped_value = current->data;

    // linkedlist has only 1 element
    if (prev == NULL) *head = NULL;
    else prev->next = NULL;

    free(current);
    return popped_value;
}

int gll_get_beg(gnode ** head) {
    if (*head == NULL) {
        fprintf(stderr, "LinkedList is empty\n");
        exit(EXIT_FAILURE);
    }
    gnode *current = *head;
    return current->data;
}

int gll_get_end(gnode ** head) {
    if (*head == NULL) {
        fprintf(stderr, "LinkedList is empty\n");
        exit(EXIT_FAILURE);
    }
    gnode *current = *head;

    while(current->next)
        current = current->next;
    return current->data;
}

void gll_insert(gnode ** head, int index, int value) {
    if (index < 0) {
        fprintf(stderr, "Index out of bound\n");
        exit(EXIT_FAILURE);
    }
    gnode *current = *head;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            fprintf(stderr, "Index out of bound\n");
            exit(EXIT_FAILURE);
        }
        current = current->next;
    }

    gnode *temp = (gnode *) malloc(sizeof(gnode));
    check_address(temp);

    temp->data = value;
    
    if (current == NULL || current->next == NULL) {
        temp->next = current;
        *head = temp;
    } else {
        temp->next = current->next;
        current->next = temp;
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
