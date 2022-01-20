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

void printLeft(Node *root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n=q.size();

        for(int i=1;i<=n;i++)
        {
            Node *temp=q.front();
            q.pop();

            if(i==1)
            {
                cout<<temp->data<<" ";
            }
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root;
    root = createTree();
    inorder(root);
    cout << endl;
    
    cout<<"Height is:\t"<<height(root)<<endl;
    cout<<"size of tree is:\t"<<size(root)<<endl;
    printLeft(root);
    return 0;
}