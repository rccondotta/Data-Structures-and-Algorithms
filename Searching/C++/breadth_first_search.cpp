#include <iostream>
#include <queue>

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void BFS(Node *root) {
    if (root == nullptr)
        return;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        std::cout << temp->data << " ";
        q.pop();

        if (temp->left != nullptr)
            q.push(temp->left);

        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    BFS(root);

    return 0;
}
