#include "array.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void run_all_tests() {
    test_determine_capacity();
    test_push();
    test_at();
    test_insert();
    test_prepend();
    test_pop();
    test_delete();
    test_remove();
    test_find();

    printf("\nAll tests ok\n\n");
}

void test_determine_capacity() {
    test_print("\nTesting capacity");

    assert(garray_determine_capacity(5) == 8);
    assert(garray_determine_capacity(8) == 8);
    assert(garray_determine_capacity(9) == 16);
}

void test_push() {
    test_print("Testing push");

    garray * arr = garray_new(5);
    for (int i = 0; i < 32; i++)
        garray_push(arr, i);
    assert(arr->size == 32);
    assert(arr->capacity == 32);
    garray_push(arr, 34);
    assert(arr->size == 33);
    assert(arr->capacity == 64);
    garray_destroy(arr);
}

void test_at() {
    test_print("Testing at");

    garray * arr = garray_new(5);
    for (int i = 0; i < 32; i++)
        garray_push(arr, i);
    assert(garray_at(arr, 5) == 5);
    assert(garray_at(arr, 19) == 19);
    garray_destroy(arr);
}

void test_insert() {
    test_print("Testing insert");

    garray * arr = garray_new(5);
    for (int i = 0; i < 5; i++)
        garray_push(arr, i);

    garray_insert(arr, 4, 100);
    garray_insert(arr, 0, 200);

    assert(garray_at(arr, 5) == 100);
    assert(garray_at(arr, 0) == 200);

    garray_destroy(arr);
}

void test_prepend() {
    test_print("Testing prepend");

    garray * arr = garray_new(5);
    for (int i = 0; i < 5; i++)
        garray_push(arr, i);

    garray_prepend(arr, 100);
    garray_prepend(arr, 200);

    assert(garray_at(arr, 1) == 100);
    assert(garray_at(arr, 0) == 200);

    garray_destroy(arr);
}

void test_pop() {
    test_print("Testing pop");

    garray * arr = garray_new(5);
    for (int i = 0; i < 5; i++)
        garray_push(arr, i);

    assert(garray_pop(arr) == 4);
    assert(garray_pop(arr) == 3);

    garray_destroy(arr);
}

void test_delete() {
    test_print("Testing delete");

    garray * arr = garray_new(5);
    for (int i = 0; i < 5; i++)
        garray_push(arr, i);

    garray_delete(arr, 4);
    garray_delete(arr, 0);
    garray_delete(arr, 1);

    assert(garray_at(arr, 0) == 1);
    assert(garray_at(arr, 1) == 3);

    garray_destroy(arr);
}

void test_remove() {
    test_print("Testing remove");

    garray * arr = garray_new(5);
    int values[] = {5, 5, 4, 3, 2};
    for (int i = 0; i < 5; i++)
        garray_push(arr, values[i]);

    garray_remove(arr, 5);
    garray_remove(arr, 3);
    garray_remove(arr, 2);
    garray_remove(arr, 10);

    assert(garray_at(arr, 0) == 4);

    garray_destroy(arr);
}

void test_find() {
    test_print("Testing find");

    garray * arr = garray_new(5);
    int values[] = {5, 5, 4, 3, 2};
    for (int i = 0; i < 5; i++)
        garray_push(arr, values[i]);

    assert(garray_find(arr, 5) == 0);
    assert(garray_find(arr, 3) == 3);
    assert(garray_find(arr, 2) == 4);
    assert(garray_find(arr, 10) == -1);

    garray_destroy(arr);
}

void test_print(const char * message) {
    if (DEBUG_PRINT)
        printf("%s\n", message);
}
