#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    printf("Enter the length of array:");
    scanf("%d",&n);

    int arr[n+1];
    
    

    arr[0]=false;
    arr[1]=false;

    for(int i=2;i*i<=n;i++)
    {
        for(int j=2*i;j<=n;j+=2)
        {
            arr[j]=1;
        }
    }
    for(int i=0;i<=n;i++)
    {
        printf("%d\t%d\n",i,arr[i]);
    }
    return 0;
}