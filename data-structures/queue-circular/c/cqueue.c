#include "cqueue.h"
#include <stdlib.h>

cqueue * create_cqueue() {
    cqueue *q = (cqueue *) malloc(sizeof(cqueue));
    check_addr(q);

    q->head = -1;
    q->tail = -1;

    return q;
}

int enqueue(cqueue *q, int data) {
    // check if full
    if ((q->tail + 1) % MAX_SIZE == q->head) {
        printf("circular queue full\n");
        return -1;
    }

    if (q->head == -1 && q->tail == -1) {
        q->head = 0;
        q->tail = 0;
    } else {
        q->tail = (q->tail + 1) % MAX_SIZE;
    }

    q->arr[q->tail] = data;

    return 0;
}

int dequeue(cqueue *q) {
    // check if empty
    if (q->head == -1) {
        printf("circular queue empty\n");
        return -1;
    }

    // if 1 element
    if (q->head == q->tail) {
        int temp = *(q->arr + q->head);
        q->head = -1;
        q->tail = -1;
        return temp;
    }

    int temp = *(q->arr + q->head);
    q->head = (q->head + 1) % MAX_SIZE;
    return temp;
}

int cqueue_size(cqueue *q) {
    int size;

    if (q->head < q->tail)
        size = q->tail - q->head + 1;
    else if (q-> head > q->tail)
        size = (q->tail + MAX_SIZE) - q->head + 1;
    else
        if (q->head == -1) size = 0;
        else size = 1;

    return size;
}

void print_debug(cqueue *q) {

    int size = cqueue_size(q);

    for (int i = q->head; i < q->head + size; i++) {
        int index = i >= MAX_SIZE ? i % MAX_SIZE : i;

        if (i != q->head)
            printf("-> %d ", q->arr[index]);
        else
            printf("%d ", q->arr[index]);
    }
    printf("\n");
}

void destroy(cqueue *q) {
    free(q);
}

void check_addr(void *p) {
    if (p != NULL) return;
    fprintf(stderr, "Unable do allocate memory\n");
    exit(EXIT_FAILURE);
}
