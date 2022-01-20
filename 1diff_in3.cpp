#include<bits/stdc++.h>
int main()
{
    unsigned int A[]={2,2,6,6,2,6,7};
    int n=sizeof(A)/sizeof(A[0]);
    int size=8*sizeof(unsigned int);
    int count[size];
    memset(count,0,sizeof(count));

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((A[j]&(1<<i))!=0)
            {
                count[i]++;
            }
        }
    }
    unsigned res=0;
    for(int i=0;i<size;i++)
    {
        res+=(count[i]%3)*(1<<i);
    }
    printf("Diffrent member is :%i",res);
    return 0;
}