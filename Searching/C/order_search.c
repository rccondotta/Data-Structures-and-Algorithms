#include <stdio.h>
#include <stdlib.h>

// structure for a node of the binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// create a new node with the given data
struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// perform inorder search
void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// perform preorder search
void preorder(struct node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// perform postorder search
void postorder(struct node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// test the binary tree search functions
int main() {
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Inorder search: ");
    inorder(root);
    printf("\n");

    printf("Preorder search: ");
    preorder(root);
    printf("\n");

    printf("Postorder search: ");
    postorder(root);
    printf("\n");
    return 0;
}
