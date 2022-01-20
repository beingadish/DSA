#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int maxSum(int arr[],int n)
{
    int m1=0;
    int m2=INT_MIN;

    for(int i=0;i<n;i++)
    {
        m1+=arr[i];
        if(m1<arr[i])
        {
            m1=arr[i];
        } 
        if(m2<m1)
        {
            m2=m1;
        }
    }
    return m2;
}

void main()
{
    int a[]={-2,-3,-4,-1,-2,-1,-5,-3};
    int size=sizeof(a)/sizeof(a[0]);
    int sum=maxSum(a,size);
    cout<<"Maximum sum is = "<<sum<<endl;
    getchar();
}