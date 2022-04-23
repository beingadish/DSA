#include<bits/stdc++.h>
using namespace std;

#define lli long long int 

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n,minus_ones=0;
        vector<lli> arr(n);
        for(lli i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]==-1)
            minus_ones++;
        }
        if(n%2!=0)
        {
            if(minus_ones==n/2||minus_ones==(n/2+1))
            cout<<"Yes"<<endl;
            else
            cout<<"No"<<endl;   
        }
        else
        {
            lli a=n/2;
            lli b=a+1;
            lli c=a-1;
            if(minus_ones==a||minus_ones==b||minus_ones==c)
            cout<<"Yes"<<endl;
            else
            cout<<"No"<<endl;
        }
    

    }
}