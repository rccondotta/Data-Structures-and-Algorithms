/*
Still a basic implementation, and may want to
add more error handling and edge case handling to fit your specific use case
*/#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void append(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    struct Node* last = list->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void prepend(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insert(struct LinkedList* list, int data, int position) {
    if (position < 0) {
        fprintf(stderr, "Invalid position\n");
        return;
    }
    if (list->head == NULL) {
        append(list, data);
        return;
    }
    if (position == 0) {
        prepend(list, data);
        return;
    }
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* current = list->head;
    for (int i = 0; i < position - 1; i++) {
        if (current->next == NULL) {
            fprintf(stderr, "Invalid position\n");
            return;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void remove_node(struct LinkedList* list, int position) {
    if (list->head == NULL) {
        fprintf(stderr, "The list is empty\n");
        return;
    }
    if (position < 0) {
        fprintf(stderr, "Invalid position\n");
        return;
    }
    if (position == 0) {
        list->head = list->head->next;
        return;
    }
    struct Node* current = list->head;
    for (int i = 0; i < position - 1; i++) {
        if (current->next == NULL) {
            fprintf(stderr, "Invalid position\n");
            return;
        }
        current = current->next;
    }
    if (current->next == NULL) {
        fprintf(stderr, "Invalid position\n");
        return;
    }
    current->next = current->next->next;
}

int main() {
    struct LinkedList list;
    list.head = NULL;

    append(&list, 1);
    append(&list, 2);
    append(&list, 3);

    printf("List after appending: ");
    struct Node* current = list.head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    prepend(&list, 0);
    printf("List after prepending: ");
    current = list.head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    insert(&list, -1, 4);
    printf("List after inserting at position 4: ");
    current = list.head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    remove_node(&list, 0);
    printf("List after removing node at position 0: ");
    current = list.head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
