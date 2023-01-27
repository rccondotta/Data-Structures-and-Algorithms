/*
We use two stacks, stack1 and stack2, to implement the MyQueue.
stack1 is used for pushing elements, and stack2 is used for popping elements.

We also keep track of the top indices of both stacks, top1 and top2, to keep track of the number of elements in each stack.

- myQueueCreate function is used to initialize the MyQueue by allocating memory for the stacks and setting the top indices to -1.
- myQueuePush function pushes an element onto stack1.
- myQueuePop function pops an element from stack2, but if stack2 is empty, it first transfers all elements from stack1 to stack2 before popping an element
- myQueuePeek function works similarly to the myQueuePop function, but it returns the top element of stack2 without removing it
- myQueueEmpty function checks if both stacks are empty
- myQueueFree function frees the memory allocated for the stacks and the MyQueue.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*) malloc(sizeof(MyQueue));
    obj->stack1 = (int*) malloc(sizeof(int) * 100);
    obj->stack2 = (int*) malloc(sizeof(int) * 100);
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}
