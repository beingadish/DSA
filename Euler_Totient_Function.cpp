//Euler totient funtion finds the number which are  coprime to n upto n

#include<bits/stdc++.h>
using namespace std;

const int N=10e6;
int phi[N];

void phi_cal()
{
    for(int i=0;i<N;i++)
    {
        phi[i]=i;
    }
    for(int i=2;i<N;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<N;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}

int main()
{
    phi_cal();
     int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<phi[n]<<endl;
    return 0;
}

 
//phi(N)=N * (P1-1)/P1 * (P2-1)/P2 * ........ * (Pk-1)/Pk