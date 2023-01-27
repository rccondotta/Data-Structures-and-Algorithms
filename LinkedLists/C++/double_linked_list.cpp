#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DLL {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DLL() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
        size++;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = tail;
        newNode->next = NULL;
        if (tail != NULL) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == NULL) {
            head = newNode;
        }
        size++;
    }

    void insertAtPosition(int data, int position) {
        if (position < 1 || position > size + 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 1) {
            insertAtHead(data);
            return;
        }
        if (position == size + 1) {
            insertAtTail(data);
            return;
        }
        Node* current = head;
        int i = 1;
        while (i < position - 1) {
            current = current->next;
            i++;
        }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }

    void deleteAtPosition(int position) {
        if (position < 1 || position > size) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 1) {
            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }
            size--;
            return;
        }
        if (position == size) {
            tail = tail->prev;
            tail->next = NULL;
            size--;
            return;
        }
        Node* current = head;
        int i = 1;
        while (i < position) {
            current = current->next;
            i++;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        size--;
    }

    void display() {
        Node* current = head;
        while (current!= NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
    DLL dll;
    dll.insertAtHead(5);
    dll.insertAtTail(10);
    dll.insertAtTail(15);

    dll.insertAtPosition(12, 2);
    dll.insertAtPosition(20, 5);
    dll.insertAtPosition(0, 0); // Invalid position
    dll.insertAtPosition(25, 6); // Invalid position

    dll.display(); // 5 12 10 15 20 25
    cout << "Size: " << dll.getSize() << endl; // 5

    dll.deleteAtPosition(1);
    dll.deleteAtPosition(5);
    dll.deleteAtPosition(6); // Invalid position

    dll.display(); // 12 10 15 20
    cout << "Size: " << dll.getSize() << endl; // 3

    return 0;
}