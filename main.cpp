#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Get height of node
int height(Node *n)
{
    return n ? n->height : 0;
}

// Get balance factor
int getBalance(Node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

// Update height of node
void updateHeight(Node *n)
{
    n->height = 1 + max(height(n->left), height(n->right));
}