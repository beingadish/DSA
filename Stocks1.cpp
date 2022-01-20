#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int maxprof(int arr[],int n)
{
    int m1=0;
    int m2=arr[0];

    for(int i=0;i<n;i++)
    {
        if(arr[i]<m2)
        {
            m2=arr[i];
        }
        if(m1<(arr[i]-m2))
        {
            m1=arr[i]-m2;
        }
    }
        return m1;
}

int main()
{
    int a[]={3,1,4,9,7,2,5};
    int size=sizeof(a)/sizeof(a[0]);
    int d=maxprof(a,size);
    printf("Maximum Profit is : %d",d);
    return 0;
    getchar();
}