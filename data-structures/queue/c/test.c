#include "test.h"

extern gqueue * gqueue_create();
extern void gqueue_print();
extern void gqueue_enqueue();
extern int gqueue_dequeue();
extern void gqueue_destroy();
extern int gqueue_is_empty();

void run_all_tests() {
    gqueue *queue = gqueue_create();

    gqueue_print(&queue);

    assert(gqueue_is_empty(&queue) == 1);

    gqueue_enqueue(&queue, 1);
    gqueue_enqueue(&queue, 2);
    gqueue_enqueue(&queue, 3);
    gqueue_enqueue(&queue, 4);
    gqueue_enqueue(&queue, 5);

    gqueue_print(&queue);

    assert(gqueue_is_empty(&queue) == 0);

    assert(gqueue_dequeue(&queue) == 1);
    assert(gqueue_dequeue(&queue) == 2);

    gqueue_print(&queue);

    assert(gqueue_dequeue(&queue) == 3);
    assert(gqueue_dequeue(&queue) == 4);
    assert(gqueue_dequeue(&queue) == 5);

    gqueue_print(&queue);

    assert(gqueue_is_empty(&queue) == 1);

    gqueue_destroy(&queue);
}
