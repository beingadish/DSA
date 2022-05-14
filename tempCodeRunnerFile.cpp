#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[6][6];
  int a,b;
  for(int i=1;i<6;i++)
  {
    for(int j=1;j<6;j++)
    {
      cin>>arr[i][j];
      if(arr[i][j]==1)
      {
        a=i;
        b=j;
      }
    }
  }
  cout<<abs(5-a)+abs(5-b);
}

