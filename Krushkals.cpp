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
    
}