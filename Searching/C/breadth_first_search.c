#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct queue {
    int size;
    int front;
    int rear;
    struct node** array;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct queue* createQueue(int size) {
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    queue->array = (struct node**)malloc(queue->size * sizeof(struct node*));
    return queue;
}

bool isFull(struct queue* queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

bool isEmpty(struct queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(struct queue* queue, struct node* node) {
    if (isFull(queue)) {
        return;
    }
    queue->array[queue->rear] = node;
    queue->rear = (queue->rear + 1) % queue->size;
}

struct node* dequeue(struct queue* queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    struct node* node = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return node;
}

void BFS(struct node* root) {
    struct queue* queue = createQueue(100);
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        struct node* node = dequeue(queue);
        printf("%d ", node->data);

        if (node->left) {
            enqueue(queue, node->left);
        }

        if (node->right) {
            enqueue(queue, node->right);
        }
    }
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    BFS(root);

    return 0;
}
