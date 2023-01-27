#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

void reverseList() {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
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
    Node* node1 = new Node();
    node1->data = 1;
    head = node1;
    Node* node2 = new Node();
    node2->data = 2;
    node1->next = node2;
    Node* node3 = new Node();
    node3->data = 3;
    node2->next = node3;
    node3->next = NULL;

    // Print the original list
    cout << "Original List: ";
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Reverse the list
    reverseList();

    // Print the reversed list
    cout << "Reversed List: ";
    current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    testReverseList();
    return 0;
}
