#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

int parent[N], sz[N];

int make(int n)
{
    parent[n] = n;
    sz[n] = 1;
}

int find(int n)
{
    if (parent[n] == n)
        return n;
    else
        return parent[n] = find(parent[n]);
}

int Union(int u, int v)
{
    int a = find(u);
    int b = find(v);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int,pair<int,int>>> edges;//Sorting will be done according to first parameter
    for(int i=0;i<k;i++)
    {
        int wt,u,v;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});//we have to sort according to the weights
    }

    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++)
    {
        make(i);
    }

    int count=0;
    for(auto &wt:edges)
    {
        int weight=wt.first;
        int u=wt.second.second;
        int v=wt.second.second;
        if(find(u)==find(v))
            continue;
        count+=weight;
        Union(u,v);
        cout<<u<<" "<<v<<endl;
    }
    cout<<endl;
    cout<<count<<endl;

}

/*6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7*/
