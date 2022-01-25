#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    struct Tree *left;
    struct Tree *right;
    
    Tree(int a)
    {
        val=a;
        left=NULL;
        right=NULL;
    }
};

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(vector<int> &arr,int i)
{
    int size=arr.size();
    int l=(i<<1)+1;
    int r=(i<<1)+2;
    int large=i;
    if(l<size&&arr[l]>arr[large])
        large=l;
    if(r<size&&arr[r]>arr[large])
        large=r;
    if(large!=i)
    {
        swap(&arr[i],&arr[large]);
        heapify(arr,large);
    }
}

void insert(vector<int> arr,int val)
{
    if(arr.empty())
    {
        arr.push_back(val);
        return;
    }
    int size=arr.size();
    arr.push_back(val);
    for(int i=size/2-1;i>=0;i++)
    {
        heapify(arr,i);
    }
}

Tree *insertTree(vector<int> arr,Tree *root,int i,int n)
{
    if(i<n)
    {
        root=new Tree(arr[i]);
        root->left=insertTree(arr,root->left,2*i+1,n);
        root->right=insertTree(arr,root->right,2*i+2,n);
    }
    return root;
}

void print(Tree *root)
{
    std::queue<Tree*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Tree *cur = q.front();
        if(cur==NULL)
        {
            q.pop();
            if(q.empty())
            return;
            q.push(NULL);
            cout<<endl;
            cur=q.front();
        }
        printf("%d ", cur->val);
        q.pop();

        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
    }
}

int main()
{
    Tree *root;
    vector<int> arr;
    insert(arr ,3);
    insert(arr, 4);
    insert(arr, 9);
    insert(arr, 5);
    insert(arr, 2);

    int size=sizeof(arr)/sizeof(arr[0]);
    insertTree(arr,root,0,size);

    print(root);

    return 0;
}