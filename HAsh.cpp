#include<bits/stdc++.h>
#include<math.h>
int main()
{
    int A,B;
    printf("Enter the Dividend and divisor:");
    scanf("%d%d",&A,&B);

    if(A == 1<<31 && B== -1)
    {
        printf("Answer is:%d",INT_MAX);
        return 0;     
    }

    int sign=((A<0)^(B<0))?-1:1;

    A=abs(A);
    B=abs(B);

    int q=0;
    while(A-B>=0)
    {
        int count=0;
        while(A-(B<<1<<count)>=0)
        {
            count++;
        }
        q+=1<<count;
        A-=B<<count;
    }
    printf("Answer is:%d",q);
    return 0;
}