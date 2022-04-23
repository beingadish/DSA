#include<bits/stdc++.h>
using namespace std;

const int N=100001;
vector<int> primes;

void sieve()
{
    bool arr[N];
    for(int i=0;i<N;i++)
    {
        arr[i]=true;
    }
    arr[0]=arr[1]=false;
    for(int i=2;i*i<N;i++)
    {
        if(arr[i])
        {
            for(int j=i*i;i<N;j+=i)
            {
                arr[j]=false;
            }
        }
    }
    for(int i=2;i<N;i++)
    {
        if(arr[i])
        {
            primes.push_back(arr[i]); 
        }
    }
}

int main()
{

}