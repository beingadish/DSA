#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int k)
    {
        data = k;
        left = NULL;
        right = NULL;
    }
};

struct Node *insert(struct Node *root, int a)
{
    if (root == NULL)
    {
        return new Node(a);
    }

    if (a < root->data)
    {
        root->left = insert(root->left, a);
    }
    if (a > root->data)
    {
        root->right = insert(root->right, a);
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << "->";
    inorder(root->right);
}

int main()
{
    struct Node *root;
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 0);
    root = insert(root, 5);
    inorder(root);
    return 0;
}