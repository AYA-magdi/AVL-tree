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

// Insert node and balance AVL Tree
Node *insert(Node *node, int key)
{
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate not allowed

    updateHeight(node);

    int balance = getBalance(node);

    // Balance cases
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}