#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            arr[i]={u,v};
        }    
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int x1=arr[i].first;
                    int x2=arr[j].first;
                    int x3=arr[k].first;
                    int y1=arr[i].second;
                    int y2=arr[j].second;
                    int y3=arr[k].second;
                    if(((y2-y1)*(y3-y2))==((x2-x1)*(x2-x3)))
                    count++;
                    else if(((y3-y1)*(y3-y2))==((x1-x3)*(x3-x2)))
                }
            }
        }
        cout<<count<<endl;
    }
}