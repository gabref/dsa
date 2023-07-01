#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack_arr[MAX];
int bottom = -1;

void push(int data) {
    bottom++;
    for (int i = bottom; i > 0; i--)
        stack_arr[i] = stack_arr[i - 1];
    stack_arr[0] = data;
}

int pop() {
    int value = stack_arr[0];
    for (int i = 0; i < bottom; i++)
        stack_arr[i] = stack_arr[i + 1];
    bottom--;
    return value;
}

void print() {
    if (bottom == -1) {
        printf("Stack Underflow");
        exit(1);
    }
    for (int i = 0; i <= bottom; i++)
        printf("%d ", stack_arr[i]);
    printf("\n");
}

int main() {

    return 0;
}
