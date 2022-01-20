#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int k)
    {
        data=k;
        left=NULL;
        right=NULL;
    }
};

Node *createTree(Node *root) 
{
    int a;
    printf("Enter the value: ");
    scanf("%d",&a);
    if(a==-1)
        return NULL;
    root= new Node(a);
    printf("Enter the left(/) Value Of %d\n",a);
    root->left=createTree(root->left);
    printf("Enter the right(%c) Value of %d\n",char(92),a);
    root->right=createTree(root->right);
    return root;
}

void viewVertical(Node *root,int hdis,map<int,vector<int>> &m)
{
    if(root==NULL)                              //For Saving Verticle nodes in a map 
        return;                                 //for viewing verticle nodes
    m[hdis].push_back(root->data);
    viewVertical(root->left,hdis-1,m);
    viewVertical(root->right,hdis+1,m);
}

void printVerticalView(Node *root,map<int,vector<int>> m)
{
    for(auto &i:m)                              //for printing vertical nodes 
    {                                           //in form of map
        cout<<i.first<<":\t";
        for(auto &j:i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void setBottom(Node *root,int hdi,map<int,int> &m)
{
    if(root==NULL)
        return;                                 //for saving verticle nodes in a map 
    m[hdi]=root->data;                          
    setBottom(root->left,hdi-1,m);
    setBottom(root->right,hdi+1,m);
}

void bottomView(Node *root,map<int,int> m)
{
    for(auto &i:m)                              //for printing verticle nodes  
    {
        cout<<i.second<<"\t";
    }
}

void setTop(Node *root,int hdi,map<int,int> &m)
{
        if(root==NULL)
            return ;
        if(m.count(hdi)==0)
        {
            m[hdi]=root->data;
        }
        setTop(root->left,hdi-1,m);
        setTop(root->right,hdi+1,m);
}

void topView(Node *root,map<int,int> m)
{
    for(auto &i:m)                              //for printing verticle nodes  
    {
        cout<<i.second<<"\t";
    }
}

int main()
{
    Node *root=NULL;
    map<int,vector<int>> m;
    map<int,int> m2;
    map<int,int> m3;
    root=createTree(root);
    cout<<endl;
    viewVertical(root,0,m);
    cout<<endl;
    printVerticalView(root,m);
    cout<<endl;
    setBottom(root,0,m2);

    cout<<"Bottom view:"<<endl;
    bottomView(root,m2);
    cout<<endl;
    setTop(root,0,m3);
    cout<<"Top View:"<<endl;
    topView(root,m3);
    return 0;
}