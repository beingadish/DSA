#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjLists;
    map<int, bool> visited;

public:
    void edgeAdd(int src, int data);
    void dfs(int vertex);
};

void Graph::edgeAdd(int src, int data)
{
    adjLists[src].push_back(data);
    adjLists[data].push_back(src);
}

void Graph::dfs(int v)
{
    visited[v] = true;
    list<int> stack = adjLists[v];

    cout << v << " ";

    list<int>::iterator i;
    for (i = stack.begin(); i != stack.end(); i++)
    {
        if (visited[*i] != true)
        {
            dfs(*i);
        }
    }
}

int main()
{
    Graph g;
    g.edgeAdd(0, 1);
    g.edgeAdd(0, 2);
    g.edgeAdd(0, 5);
    g.edgeAdd(2, 3);
    g.edgeAdd(1, 4);
    g.edgeAdd(5, 4);
    g.edgeAdd(3, 6);
    g.edgeAdd(4 ,6);
    g.edgeAdd(4, 8);

    g.dfs(0);

    return 0;
}