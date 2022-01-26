#include<bits/stdc++.h>
using namespace std;


void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(vector<int> &arr,int i)
{
    int size=arr.size();
    int l=(i*2)+1;
    int r=(i*2)+2;
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

void insert(vector<int> &arr,int val)
{
    int size = arr.size();
    if(size==0)
    {
        arr.push_back(val);
    }
    else
    {       
        arr.push_back(val);
        for(int i=size/2-1;i>=0;i--)
        {
            heapify(arr,i);
        }
    }
}


int main()
{
   
    vector<int> arr;
    insert(arr ,3);
    insert(arr, 4);
    insert(arr, 9);
    insert(arr, 5);
    insert(arr, 2);


    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}