#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Recursive function to traverse the tree in DFS (in-order)
void DFS(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    // Visit the left subtree
    DFS(node->left);
    // Visit the node
    printf("%d ", node->val);
    // Visit the right subtree
    DFS(node->right);
}

int main() {
    // Test example
    // Construct the following binary search tree:
    //      4
    //     / \
    //    2   5
    //   / \
    //  1   3
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 4;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;

    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 5;

    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 1;

    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 3;

    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;

    // Call DFS function to traverse the tree
    DFS(root);
    printf("\n");

    return 0;
}
