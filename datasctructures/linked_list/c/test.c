#include "test.h"
#include "linked_list.h"
#include <assert.h>
#include <stdio.h>

void run_all_tests() {
    printf("\nRunning Tests:\n");

    test_create();
    test_push_beg();
    test_push_end();
    test_size();
    test_is_empty();
    test_at();

    printf("\n\nAll tests ok\n\n");
}

void test_create() {
    printf("\nTesting create\n");

    gnode * myLL = gll_create();
    assert(myLL == NULL);

    gll_destroy(&myLL);
}

void test_push_beg() {
    printf("Testing push begin\n");

    gnode * myLL = gll_create();

    gll_push_beg(&myLL, 10);
    gll_push_beg(&myLL, 20);
    gll_push_beg(&myLL, 30);
    assert(myLL->data == 30);
    assert(myLL->next->data == 20);

    gll_destroy(&myLL);
}

void test_push_end() {
    printf("Testing push end\n");

    gnode * myLL = gll_create();

    gll_push_end(&myLL, 10);
    gll_push_end(&myLL, 20);
    gll_push_end(&myLL, 30);
    gll_push_end(&myLL, 40);
    assert(myLL->data == 10);
    assert(myLL->next->data == 20);
    assert(gll_at(&myLL, 3) == 40);

    gll_destroy(&myLL);
}

void test_size() {
    printf("Testing size\n");

    gnode * myLL = gll_create();

    assert(gll_size(&myLL) == 0);
    gll_push_beg(&myLL, 10);
    gll_push_beg(&myLL, 20);
    gll_push_beg(&myLL, 30);
    assert(gll_size(&myLL) == 3);

    gll_destroy(&myLL);
}

void test_is_empty() {
    printf("Testing is empty\n");

    gnode * myLL = gll_create();

    assert(gll_is_empty(&myLL) == 1);

    for (int i = 0; i < 4; i++)
        gll_push_beg(&myLL, i * 10);

    assert(gll_is_empty(&myLL) == 0);

    gll_destroy(&myLL);
}

void test_at() {
    printf("Testing is empty\n");

    gnode * myLL = gll_create();

    for (int i = 4; i >= 0; i--)
        gll_push_beg(&myLL, i * 10);

    assert(gll_at(&myLL, 0) == 0);
    assert(gll_at(&myLL, 2) == 20);
    assert(gll_at(&myLL, 4) == 40);

    gll_destroy(&myLL);
}
