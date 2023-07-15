#ifndef TEST_QUEUE
#define TEST_QUEUE

#ifdef LINKEDLIST_IMPLEMENTATION
#include "queue-linkedlist.h"
#endif

#ifdef ARRAY_IMPLEMENTATION
#include "queue-array.h"
#endif

#include <stdio.h>
#include <assert.h>

void run_all_tests();

#endif
