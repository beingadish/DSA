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
            else if(n%6==0){
                cout<<n/6<<" "<<n/6<<endl;
            }
            else{
                cout<<n/4<<" "<<n/4<<endl;
            }
        }
    }
    return 0;
}

//== == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <bits/stdc++.h>
    using namespace std;

#define lli long long int

lli maxi(lli n)
{
    return n / 4;
}

lli mini(lli n)
{
    if (n % 6 != 0)
    {
        return n / 6 + 1;
    }
    else
    {
        return n / 6;
    }
}

int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        if (n % 2 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << mini(n) << " " << maxi(n) << endl;
        }
    }
    return 0;
}