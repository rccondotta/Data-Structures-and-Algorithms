/*
Still a basic implementation, and may want to
add more error handling and edge case handling to fit your specific use case
*/
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }
        Node* last = this->head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }

    void prepend(int data) {
        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
    }

    void insert(int data, int position) {
        if (position < 0) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }
        if (this->head == nullptr) {
            this->append(data);
            return;
        }
        if (position == 0) {
            this->prepend(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = this->head;
        for (int i = 0; i < position - 1; i++) {
            if (current->next == nullptr) {
                std::cerr << "Invalid position" << std::endl;
                return;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void remove_node(int position) {
        if (this->head == nullptr) {
            std::cerr << "The list is empty" << std::endl;
            return;
        }
        if (position < 0) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }
        if (position == 0) {
            this->head = this->head->next;
            return;
        }
        Node* current = this->head;
        for (int i = 0; i < position - 1; i++) {
            if (current->next == nullptr) {
                std::cerr << "Invalid position" << std::endl;
                return;
            }
            current = current->next;
        }
        if (current->next == nullptr) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }
        current->next = current->next->next;
    }
};

int main() {
    LinkedList list;
    int value;

    list.append(1);
    list.append(2);
    list.append(3);
    cout << "List after appending: ";
    for (auto current = list.head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;

    list.prepend(0);
    cout << "List after prepending: ";
    for (auto current = list.head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;

    list.insert(5, 3);
    cout << "List after inserting 5 at position 3: ";
    for (auto current = list.head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;

    list.remove_node(2);
    cout << "List after removing position 2: ";
    for (auto current = list.head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;

    list.insert(5, 20);
    list.remove_node(-1);
}