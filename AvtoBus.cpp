#include<bits/stdc++.h>
using namespace std;
 
#define lli long long int
 

 
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        if(n%6!=0||n%4!=0)
        {
            cout<<-1<<endl;
        }
        else
        {
            if(n%6==0&&n%4==0){
                cout<<n/6<<" "<<n/4<<endl;
            }
        }
    }
    return 0;
}