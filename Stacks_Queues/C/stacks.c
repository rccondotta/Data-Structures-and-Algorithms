/*
this implementation has a fixed size, if you want a dynamic size stack you can use linked list or dynamic array.
Time complexity for all operations is O(1)
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int data[MAX_SIZE];
};

void init(struct Stack* stack) {
    stack->top = -1;
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

int is_full(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int item) {
    if (is_full(stack)) {
        printf("Error: Stack is full\n");
        return;
    }
    stack->data[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    struct Stack stack;
    init(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("%d\n", peek(&stack)); // Output: 3
    printf("%d\n", pop(&stack)); // Output: 3
    printf("%d\n", peek(&stack)); // Output: 2
    printf("%d\n", pop(&stack)); // Output: 2
    printf("%d\n", peek(&stack)); // Output: 1
    printf("%d\n", pop(&stack)); // Output: 1
    printf("%d\n", is_empty(&stack)); // Output: 1 (true)
    return 0;
}
