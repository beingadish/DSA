#include<bits/stdc++.h>
using namespace std;

#define lli long long int
const lli inf=1e7;

int main()
{
    lli n,edges;
    printf("Enter number of nodes & Edges: ");
    cin>>n>>edges;
    vector<lli> dist(n+1,inf);
    vector<vector<pair<lli,lli>>> graph(n+1);
    printf("Enter the following:\nu v w\n");
    for(lli i=0;i<edges;i++)
    {
        lli u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    lli source;
    printf("Enter source: ");
    cin>>source;
    dist[source]=0;
    set<pair<lli ,lli>> s;
    s.insert({0,source});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto it: graph[x.second])
        {
            if(dist[it.first]>dist[x.second]+it.second)
            {
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(lli i=1;i<=n;i++)
    {
        if(dist[i]==inf)
        cout<<-1<<endl;
        else
        cout<<dist[i]<<endl;
    }

}