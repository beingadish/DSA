#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
    Node(int a)
    {
        data=a;
        left=NULL;
        right=NULL;
        height=1;
    }
};

int max(int a,int b)
{
    return (a>b)?a:b;
}

int height(Node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}

Node *rightRotate(Node *root)
{
    Node *x=root->left;
    Node *temp=x->right;
    x->right=root;
    root->left=temp;
    x->height=max(height(x->right),height(x->left))+1;
    root->height=max(height(root->right),height(root->left))+1;
    return x;
}

Node *leftRotate(Node *root)
{
    Node *x=root->right;
    Node *temp=x->left;
    x->left=root;
    root->right=temp;
    x->height=max(height(x->right),height(x->left))+1;
    root->height=max(height(root->right),height(root->left))+1;
    return x;
}

int balancefac(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return height(root->left)-height(root->right);
}

struct Node *createAVLtree(Node *root,int a)
{
    if(root==NULL)
        return new Node(a);
    if(a<root->data)
        root->left=createAVLtree(root->left,a);
    else if(a>root->data)
        root->right=createAVLtree(root->right,a);
    else
        return root;
    
    root->height=1+max(height(root->left),height(root->right));
    int balanceFactor=balancefac(root);
    if(balanceFactor>1)
    {
        if(a<root->left->data)
            return rightRotate(root);
        else if(a>root->left->data){
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if(balanceFactor<-1)
    {
        if(a>root->right->data)
            return leftRotate(root);
        if(a<root->right->data){
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

void inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void levelOrderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp=q.front();
        if(temp==NULL)
        {
            q.pop();
            if(q.empty())
            {
                return;
            }
            q.push(NULL);
            cout<<endl;
            temp=q.front();
        }
        printf("%d ",temp->data);
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
    
}

int main()
{
    Node *root=NULL;
    int a;
    char m='y';
    while(m=='y'||m=='Y')
    {
        printf("Enter the key:");
        scanf("%d",&a);
        root=createAVLtree(root,a);
        printf("Enter Y or y if You wish to enter more branch:");
        cin>>m;
    }
    inorder(root);
    cout<<endl<<endl;
    levelOrderTraversal(root);
    return 0;
}