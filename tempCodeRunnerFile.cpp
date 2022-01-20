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

Node *createTree()
{
    Node *root;
    int data;
    printf("Enter the value:\t");
    scanf("%d", &data);
    if (data == -1)
        return NULL;

    root = new Node(data);
    printf("Enter left(/) for %d\n", data);
    root->left = createTree();

    printf("Enter right(%c) for %d\n", char(92),data);
    root->right = createTree();
    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << "->";
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "->";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << "->";
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int size(struct Node* root)
{
    if(root==NULL)
        return 0;
    return size(root->left)+size(root->right)+1;
}



int main()
{
    Node *root;
    root = createTree();
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout<<"Height is:\t"<<height(root)<<endl;
    cout<<"size of tree is:\t"<<size(root)<<endl;
    return 0;
}