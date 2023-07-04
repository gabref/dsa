#ifndef ARRAY_TESTS_H
#define ARRAY_TESTS_H

#define DEBUG_PRINT 1

// runs all the defined tests
void run_all_tests();

void test_print(const char *message);
void test_determine_capacity();
void test_push();
void test_at();
void test_insert();
void test_prepend();
void test_pop();
void test_delete();
void test_remove();
void test_find();

#endif
