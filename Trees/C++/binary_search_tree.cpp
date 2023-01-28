/*
BinarySearchTree class with a private Node class that has three members data
left and right which represent the data stored in the node,
a pointer to left child node and a pointer to right child node

BinarySearchTree class has two main public functions: insert and inOrder
- insert function takes an integer as an argument and it insert that integer into the tree in the correct place
- inOrder function is used to traverse the tree in-order and print the data stored in each node.
*/
#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertHelper(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insertHelper(node->left, data);
        } else if (data > node->data) {
            node->right = insertHelper(node->right, data);
        }
        return node;
    }

    void inOrderHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        inOrderHelper(node->left);
        std::cout << node->data << " ";
        inOrderHelper(node->right);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertHelper(root, data);
    }

    void inOrder() {
        inOrderHelper(root);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(17);

    std::cout << "In-Order Traversal: ";
    bst.inOrder();
    return 0;
}
