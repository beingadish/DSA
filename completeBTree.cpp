#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    struct Tree *left ,*right;
    Tree(int a)
    {
        val=a;
        left=NULL;
        right=NULL;
    }
};

Tree *insert(int arr[],Tree *root,int i,int n)
{
    if(i<n)
    {
        root=new Tree(arr[i]);
        root->left=insert(arr,root->left,2*i+1,n);
        root->right=insert(arr,root->right,2*i+2,n);
    }
    return root;
}

void levelOrder(Tree *root)
{
    queue<Tree*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Tree *temp= q.front();
        if(temp==NULL)
        {
            q.pop();
            if(q.empty())
                return;
            q.push(NULL);
            cout<<endl;
            temp=q.front();
        }
        cout<<temp->val<<" ";
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

int main()
{
    Tree *root;
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    root=insert(arr,root,0,size);
    levelOrder(root);
}