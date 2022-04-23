#include<bits/stdc++.h>
using namespace std;

int phi[10000000];

void gcd()
{
    for(int i=1;i<=10000000;i++)
    {
        phi[i]=i;
    }
    for(int i=2;i<=10000000;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=10000000;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}

int getcount(int d,int n)
{
    return phi[n/d];
}

int main()
{
    gcd();
    int n,sum=0;
    cout<<"enter number : ";
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int d1=i;
            int d2=n/i;

            sum+=d1*getcount(d1,n);//number of values that have d1 as gcd with n and less than n

            if(d1!=d2)
            {
                sum+=d2*getcount(d2,n);
            }
        }
    }
}