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

// Right rotate
Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left rotate
Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}