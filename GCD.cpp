#include<bits/stdc++.h>
int GCD(int a,int b);
int main()
{
    int a,b;
    printf("Enter the numbers:");
    scanf("%d%d",&a,&b);
    printf("GCD of numbers is =%d",GCD(a,b));
}

int GCD(int a,int b)
{
    if(b==0)
    return a;
    return GCD(b,a%b);
}