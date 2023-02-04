#include <iostream>
#include <stack>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative function to traverse the tree in DFS (in-order)
void DFS(TreeNode* root) {
    std::stack<TreeNode*> s;
    TreeNode* curr = root;

    while (curr != NULL || !s.empty()) {

        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        std::cout << curr->val << " ";
        curr = curr->right;
    }
}

int main() {
    // Test example
    // Construct the following binary search tree:
    //      4
    //     / \
    //    2   5
    //   / \
    //  1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Call DFS function to traverse the tree
    DFS(root);
    std::cout << std::endl;
    return 0;
}
