#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peek() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return (front == nullptr);
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Front element is: " << q.peek() << std::endl;
    q.dequeue();
    std::cout << "Front element is: " << q.peek() << std::endl;
    q.dequeue();
    std::cout << "Front element is: " << q.peek() << std::endl;
    q.dequeue();
    if (q.isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    }
    return 0;
}
