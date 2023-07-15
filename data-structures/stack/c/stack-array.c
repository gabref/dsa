#include "stack-array.h"
#include <stdlib.h>

#define K_MIN_CAP 4

gstack * gstack_create() {
    gstack *stack = (gstack *) malloc(sizeof(gstack));
    check_address(stack);

    stack->data = (int *) malloc(sizeof(int) * K_MIN_CAP);
    check_address(stack->data);

    stack->size = 0;
    stack->capacity = K_MIN_CAP;

    return stack;
}

void gstack_print(gstack ** stack) {
    printf("\n");
    for (int i = 0; i < (*stack)->size; i++)
        printf("%d -> ", *((*stack)->data + i));
    printf("NULL\n");
}

void gstack_push(gstack ** stack, int value) {
    // resize
    *((*stack)->data + (*stack)->size) = value;
    (*stack)->size++;
}

int gstack_pop(gstack ** stack) {
    int popped_value = *((*stack)->data + (*stack)->size - 1);
    (*stack)->size--;
    // resize
    return popped_value;
}

int gstack_is_emtpy(gstack ** stack) {
    return (*stack)->size == 0 ? 1 : 0;
}

void check_address(void * p) {
    if (p == NULL) {
        fprintf(stderr, "Failed to alloc memory\n");
        exit(EXIT_FAILURE);
    }
}
