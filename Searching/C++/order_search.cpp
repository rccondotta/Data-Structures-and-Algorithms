#include <iostream>

using namespace std;

// structure for a node of the binary tree
struct node {
    int data;
    node *left;
    node *right;
};

// create a new node with the given data
node *newNode(int data) {
    node *node = new struct node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// perform inorder search
void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

// perform preorder search
void preorder(node *root) {
    if (root == NULL)
        return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// perform postorder search
void postorder(node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

// test the binary tree search functions
int main() {
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    std::cout << "Inorder search: ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Preorder search: ";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Postorder search: ";
    postorder(root);
    std::cout << std::endl;

    return 0;
}
