#include<bits/stdc++.h>
int main()
{
    int n;
    bool arr[n+1];
    printf("Enter the number :");
    scanf("%d",&n);
    memset(arr,true,n);
    printf("Array is:");
    for(bool a: arr)
    {
        printf("%s\n",a);
    }
    return 0;
}