#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void reverseList() {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void testReverseList() {
    // Create a linked list with 3 nodes
    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*) malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*) malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // Print the original list
    printf("Original List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Reverse the list
    reverseList();

    // Print the reversed list
    printf("Reversed List: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    testReverseList();
    return 0;
}
