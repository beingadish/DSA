#include<bits/stdc++.h>
using namespace std;


//ax+by=gcd(a,b)
//x=y1
//y=x1-(a/b)*y1

struct triplet
{
    int gcd,x,y;
};

triplet extendedEuclidsAlgo(int a,int b)
{
    if(b==0)
    {
        triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
    }
    triplet temp=extendedEuclidsAlgo(b,a%b);
    triplet ans;
    ans.gcd=temp.gcd;
    ans.x=temp.y;
    ans.y=temp.x-(a/b)*temp.y;
    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;
    triplet ans=extendedEuclidsAlgo(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
    return 0;
}