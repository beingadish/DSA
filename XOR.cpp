#include<bits/stdc++.h>
int main()
{
    int a[]={5,4,1,4,3,5,1,3,8,6};
    int res=0,x=0,y=0;
    int change;
    for(int i : a)
    {
        res=res^i;
    }
    change=res&~(res-1);
    for(int i:a)
    {
        if(i&change)
        {
            x=x^i;
        }
        else{
            y=y^i;
        }
    }
    printf("Non repeating member sof array are:%d and %d",x,y);
}