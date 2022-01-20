#include<bits/stdc++.h>

using namespace std;

int count=0;

int solution(int a)
{
    if(a==1)
    {
        count++;
        return;
    }
    else
    {
        if(a%2==0)
        {
            solution(a>>1);
            count+=1;
        }
        else
        {
            count+=1;
            solution(a>>1);
        }
    }
}

int main()
{
    int n=6;
    solution(n);
    return 0;
}