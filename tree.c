#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;

    
};
struct Node *Node(int k)
{
    struct Node *root=(struct Node*)malloc(sizeof(struct Node));
    root->data=k;
    root->left=NULL;
    root->right = NULL;
    return (root);
}

struct Node *createTree()
{
    struct Node *root=(struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter the value:\t");
    scanf("%d", &data);
    if (data == -1)
        return NULL;

    root = Node(data);
    printf("Enter left(/) for %d\n", data);
    root->left = createTree();

    printf("Enter right(\\) for %d\n",data);
    root->right = createTree();
    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}

int main()
{
    struct Node *root=(struct Node*)malloc(sizeof(struct Node));
    root = createTree();
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}