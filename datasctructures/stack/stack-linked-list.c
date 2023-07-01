#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(int data, struct node ** top) {
    struct node * temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Stack Overflow");
        exit(1);
    }
    temp -> data = data;
    temp -> next = *top;
    *top = temp;
}

int pop(struct node ** top) {
    if (*top == NULL) {
        printf("Stack Underflow");
        exit(1);
    }
    struct node *temp = *top;
    int value = temp -> data;
    *top = (*top) -> next;
    free(temp);
    return value;
}

void print(struct node ** top) {
    struct node *temp = *top;
    for (struct node * temp = *top; temp != NULL; temp = temp -> next)
        printf("%d --> ", temp->data);
    printf("NULL\n");
}

int main() {
    struct node *top = NULL;
    struct node *temp1 = NULL;
    struct node *temp2 = NULL;

    push(1, &top);
    push(2, &top);
    push(3, &top);
    print(&top);

    push(pop(&top), &temp1);
    push(pop(&top), &temp1);
    push(pop(&top), &temp1);

    push(pop(&temp1), &temp2);
    push(pop(&temp1), &temp2);
    push(pop(&temp1), &temp2);

    push(pop(&temp2), &top);
    push(pop(&temp2), &top);
    push(pop(&temp2), &top);

    print(&top);
}
