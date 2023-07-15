#ifndef TEST_STACK
#define TEST_STACK

#ifdef LINKEDLIST_IMPLEMENTATION
#include "stack-linkedlist.h"
#endif

#ifdef ARRAY_IMPLEMENTATION
#include "stack-array.h"
#endif

#include <stdio.h>
#include <assert.h>

void run_all_tests();
void test_is_empty();
void test_push();
void test_pop();

#endif
