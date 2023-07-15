#include "queue-array.h"

#define K_MIN_CAP 8

gqueue * gqueue_create() {
    gqueue * queue = (gqueue *) malloc(sizeof(gqueue));
    check_address(queue);

    queue->data = (int *) malloc(sizeof(int) * K_MIN_CAP);
    check_address(queue->data);
    queue->size = 0;
    queue->capacity = K_MIN_CAP;

    return queue;
}

void gqueue_enqueue(gqueue ** queue, int value) {
    // resize capcity
    *((*queue)->data + (*queue)->size) = value;
    (*queue)->size++;
}

int gqueue_dequeue(gqueue ** queue) {
    if ((*queue)->size == 0) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int popped_value = *((*queue)->data + 0);

    for (int i = 0; i < (*queue)->size; i++)
        *((*queue)->data + i) = *((*queue)->data + i + 1);
    (*queue)->size--;

    // resize capacity

    return popped_value;
}

int gqueue_is_empty(gqueue ** queue) {
    return (*queue)->size == 0 ? 1 : 0;
}

void gqueue_print(gqueue ** queue) {
    for (int i = 0; i < (*queue)->size; i++)
        printf("%d -> ", *((*queue)->data + i));
    printf("NULL\n");
}

void gqueue_destroy(gqueue ** queue) {
    free((*queue)->data);
    free(*queue);
}

void check_address(void * p) {
    if (p != NULL) return;
    fprintf(stderr, "Failed do allocate memory\n");
    exit(EXIT_FAILURE);
}
