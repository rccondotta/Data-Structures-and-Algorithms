/*
This implementation uses a struct called Node to represent each node in the tree.
Each node has an integer value, as well as pointers to its left and right children.

- newNode function is used to create new nodes
- insert function is used to add new values to the tree
- search function can be used to search for a specific value in the tree.
- findMinimum function to print the minimum value in the tree
- findMaximum function to print the maximum value in the tree
- deleteNode function to delete a node with a specific key, and then check if the node is still present in the tree by calling the search function.

Please note that this is just a basic implementation of binary search tree and
you may want to add more features like traversals or handling duplicate keys.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

int search(struct Node* node, int data) {
    if (node == NULL) return 0;
    if (data < node->data)
        return search(node->left, data);
    else if (data > node->data)
        return search(node->right, data);
    else
        return 1;
}

struct Node* findMinimum(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* findMaximum(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int search_value = 20;
    if (search(root, search_value))
        printf("Found %d\n", search_value);
    else
        printf("Not Found\n");

    printf("Minimum value in the tree is: %d\n", findMinimum(root)->data);
    printf("Maximum value in the tree is: %d\n", findMaximum(root)->data);

    int delete_value = 20;
    root = deleteNode(root, delete_value);
    if (search(root, delete_value))
        printf("Found %d\n", delete_value);
    else
        printf("Not Found\n");
    return 0;
}

