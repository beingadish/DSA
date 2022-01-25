#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjLists;
    map<int, bool> visited;

public:
    void edgeAdd(int src, int data);
    void bfs(int vertex);
};

void Graph::edgeAdd(int src, int data)
{
    adjLists[src].push_back(data);
    adjLists[data].push_back(src);
}

void Graph::bfs(int v)
{
    visited[v] = true;
    list<int> queue = adjLists[v];

    cout << v << " ";

    list<int>::iterator i;
    for (i = queue.begin(); i != queue.end(); i++)
    {
        if (visited[*i] != true)
        {
            bfs(*i);
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

    g.bfs(0);

    return 0;
}