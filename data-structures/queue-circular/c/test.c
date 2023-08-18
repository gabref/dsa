#include "test.h"
#include "cqueue.h"

void run_all_tests() {
    printf("running tests\n\n");

    cqueue *q = create_cqueue();

    assert(enqueue(q, 1) == 0);
    assert(enqueue(q, 2) == 0);
    assert(enqueue(q, 3) == 0);
    assert(enqueue(q, 4) == 0);
    assert(enqueue(q, 5) == 0);
    assert(enqueue(q, 5) == -1);

    print_debug(q);

    assert(dequeue(q) == 1);
    assert(dequeue(q) == 2);
    assert(dequeue(q) == 3);
    assert(dequeue(q) == 4);
    assert(dequeue(q) == 5);
    assert(dequeue(q) == -1);

    assert(enqueue(q, 1) == 0);
    assert(enqueue(q, 2) == 0);
    assert(enqueue(q, 3) == 0);
    assert(enqueue(q, 4) == 0);
    assert(enqueue(q, 5) == 0);
    assert(dequeue(q) == 1);
    assert(dequeue(q) == 2);
    assert(dequeue(q) == 3);
    assert(enqueue(q, 1) == 0);
    assert(enqueue(q, 2) == 0);
    assert(enqueue(q, 3) == 0);
    assert(enqueue(q, 3) == -1);

    print_debug(q);

    assert(dequeue(q) == 4);
    assert(dequeue(q) == 5);
    assert(dequeue(q) == 1);
    assert(dequeue(q) == 2);
    assert(dequeue(q) == 3);

    assert(dequeue(q) == -1);

    destroy(q);

    printf("\n\nall tests ok\n");
}
