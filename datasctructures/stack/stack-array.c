#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int);
int pop();
void display();

int main() {
    push(1);
    push(2);
    push(8);
    push(3);
    push(9);

    return 0;
}

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack Overflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow");
        exit(1);
    }
    int value = stack_arr[top];
    top = top - 1;
    return value;
}

void display() {
    if (top == -1) {
        printf("Stack Underflow");
        return;
    }
    for (int i = top; i == 0; i--)
        printf("%d ", stack_arr[i]);
    printf("\n");
}
