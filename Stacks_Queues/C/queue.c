/*
This code creates a queue using a linked list, with the following operations:

- createQueue(): creates a new queue and returns a pointer to it
- createNode(int data): creates a new node with the given data and returns a pointer to it
- isEmpty(struct Queue* q): checks if the queue is empty and returns 1 if it is, 0 otherwise
- enqueue(struct Queue* q, int data): adds a new element to the queue
- dequeue(struct Queue* q): removes and returns the front element of the queue

In the main() function, the queue is created, and it enqueues 3 element and dequeues all 3 elements one by one,
which will give the output as 1 2 3
*/
#include <stdio.h>
#include <stdlib.h>

// define the node structure
struct Node {
    int data;
    struct Node* next;
};

// define the queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// create a new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// enqueue an element
void enqueue(struct Queue* q, int data) {
    struct Node* temp = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    struct Queue* q = createQueue();

    // test example
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));
    printf("%d\n", dequeue(q));

    return 0;
}
