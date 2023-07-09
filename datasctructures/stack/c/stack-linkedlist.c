#include "stack-linkedlist.h"

gstack * gstack_create() {
    gstack * stack = (gstack *) malloc(sizeof(gstack));
    check_address(stack);
    stack = NULL;
    return stack;
}

void gstack_print(gstack ** stack) {
    for (gstack * current = *stack; current != NULL; current = current->next)
        printf("%d -> ", current->data);
    printf("NULL\n");
}

void gstack_push(gstack ** stack, int value) {
    gstack * new_top = (gstack *) malloc(sizeof(gstack));
    check_address(new_top);

    new_top->data = value;
    new_top->next = *stack;
    *stack = new_top;
}

int gstack_pop(gstack ** stack) {
    gstack * temp = (gstack *) malloc(sizeof(gstack));
    check_address(temp);

    int popped_value = (*stack)->data;

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);

    return popped_value;
}

int gstack_is_emtpy(gstack ** stack) {
    return *stack == NULL ? 1 : 0;
}

void check_address(void * p) {
    if (p == NULL) {
        fprintf(stderr, "Failed to allocate more memory!\n");
        exit(EXIT_FAILURE);
    }
}
