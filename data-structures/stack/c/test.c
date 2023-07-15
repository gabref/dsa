#include "test.h"

extern gstack * gstack_create();
extern void gstack_print(gstack ** stack);
extern void gstack_push(gstack ** stack, int value);
extern int gstack_pop(gstack ** stack);
extern int gstack_is_emtpy(gstack ** stack);

extern void test_flag();

void run_all_tests() {
    printf("Executing Tests:\n");

    printf("\nCreate stack");

    gstack * stack = gstack_create();

    printf("\nCheck is empty");

    gstack_print(&stack);
    assert(gstack_is_emtpy(&stack) == 1);

    printf("\nPush");

    gstack_push(&stack, 1);
    gstack_push(&stack, 2);
    gstack_push(&stack, 3);
    gstack_push(&stack, 4);
    gstack_push(&stack, 5);
    gstack_print(&stack);

    printf("\nCheck is empty");

    assert(gstack_is_emtpy(&stack) == 0);

    printf("\nPop");

    assert(gstack_pop(&stack) == 5);
    assert(gstack_pop(&stack) == 4);
    assert(gstack_pop(&stack) == 3);
    gstack_print(&stack);
    assert(gstack_pop(&stack) == 2);
    assert(gstack_pop(&stack) == 1);

    printf("\nCheck is empty again");

    gstack_print(&stack);
    assert(gstack_is_emtpy(&stack) == 1);

    printf("\n\nAll tests ok\n\n");
}
