#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int rainWater(int a[],int n)
{
    int left[n];
    int right[n];
    int ans=0;
    left[0]=a[0];
    right[n-1]=a[n-1]; 
    for(int i=1;i<n;i++)
    {
        if(left[i-1]>a[i])
        left[i]=left[i-1];
        else
        left[i]=a[i];
    }
    for(int i=n-2;i>=0;i--)
    {
        if(right[i+1]<a[i])
        right[i]=a[i];
        else
        right[i]=right[i+1];
    }
    for(int i=0;i<n;i++)
    {
        if(right[i]<left[i])
        {
            ans+=right[i]-a[i];
        }
        else
        {
            ans+=left[i]-a[i];
        }
        //ans+=(right[i]<left[i]?right[i]:left[i])-a[i];
    }
    return ans;
}

int main()
{
    int Arr[]={3,1,2,4,0,1,3,2};
    int n=sizeof(Arr)/sizeof(Arr[0]);
    int max=rainWater(Arr,n);

    printf("Total Water Harvested is : %d",max);
    return 0;
    getchar();
}