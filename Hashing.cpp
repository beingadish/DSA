#include<bits/stdc++.h>

using namespace std;

void solution(int a[],int n,int sum)
{
    int c=0;
    int start=0;

    unordered_map<int,int> s;
    for(int i=0;i<n;i++)
    {
        c=c+a[i];

        if(c==sum)
        {
            printf("Item found at %d to %d",start,i);
            return;
        }    
        if(s.find(c-sum)!=s.end())
        {
            printf("Sum found at %d to %d",s[c-sum]+1,i);
            return;
        }
        s[c]=i;
    }
    cout<<"No subset have the same"<<endl;
}

int main()
{
    int arr[]={15,10,-5,15,-10,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum=5;
    solution(arr,size,sum);
    return 0;
}