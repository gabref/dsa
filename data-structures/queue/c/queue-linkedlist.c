#include "queue-linkedlist.h"

gqueue * gqueue_create() {
    gqueue * queue = (gqueue *) malloc(sizeof(gqueue));
    check_address(queue);

    queue = NULL;
    return queue;
}

void gqueue_enqueue(gqueue ** queue, int value) {
    gqueue * current = *queue;
    while(current != NULL && current->next != NULL)
        current = current->next;

    gqueue * temp = (gqueue *) malloc(sizeof(gqueue));
    temp->data = value;
    temp->next = NULL;

    if ((*queue) == NULL)
        *queue = temp;
    else
        current->next = temp;
}

int gqueue_dequeue(gqueue ** queue) {
    if ((*queue) == NULL) {
        fprintf(stderr, "queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int popped_value = (*queue)->data;
    gqueue * temp = *queue;
    *queue = (*queue)->next;
    free(temp);
    return popped_value;
}

int gqueue_is_empty(gqueue ** queue) {
    return *queue == NULL ? 1 : 0;
}

void gqueue_print(gqueue ** queue) {
    for (gqueue * current = *queue; current; current = current->next)
        printf("%d -> ", current->data);
    printf("NULL\n");
}

void gqueue_destroy(gqueue ** queue) {
    if (*queue == NULL)
        free(*queue);
    gqueue * current = *queue;
    while(current) {
        gqueue * temp = current;
        current = current->next;
        free(temp);
    }
}

void check_address(void * p) {
    if (p != NULL) return;
    fprintf(stderr, "Failed do allocate memory\n");
    exit(EXIT_FAILURE);
}
