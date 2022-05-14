#include<bits/stdc++.h>

using namespace std;

void nodeInsert(vector<int> arr[],int a,int b)
{
    arr[a].push_back(b);
   // arr[b].push_back(a);
}

void show(vector<int> arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Vertices of"<<i<<"\n head";
        for(auto x:arr[i])
        {
            cout<<"->"<<x;
        }
        cout<<endl;
    }
}

int main()
{
    int n,a,b;
    printf("Enter number:-");
    scanf("%d",&n);
    vector<int> arr[n];
    nodeInsert(arr, 0, 1);
    nodeInsert(arr, 0, 4);
    nodeInsert(arr, 1, 2);
    nodeInsert(arr, 1, 3);
    nodeInsert(arr, 1, 4);
    nodeInsert(arr, 2, 3);
    nodeInsert(arr, 3, 4);

    show(arr,n);
    return 0;

}