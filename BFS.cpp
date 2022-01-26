#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numVertex;
    bool *visited;
    list<int> *adjLists;

public:
    Graph(int v);
    void edgeAdd(int src, int data);
    void BFS(int v);
};

Graph::Graph(int v)
{
    numVertex = v;
    adjLists = new list<int>[numVertex];
}

void Graph::edgeAdd(int src, int data)
{
    adjLists[src].push_back(data);
    adjLists[data].push_back(src);
}

void Graph::BFS(int vertex)
{
    visited = new bool[numVertex];
    for(int i=0;i<numVertex;i++)
    {
        visited[i]=false;
    }

    visited[vertex]=true;
    list<int> queue;
    queue.push_back(vertex);

    list<int>::iterator i;
    while(!queue.empty())
    {
        int cur=queue.front();
        cout<<cur<<" ";

        queue.pop_front();

        for(i=adjLists[cur].begin();i!=adjLists[cur].end();i++)
        {
            int a=*i;
            if(!visited[a])
            {
                visited[a]=true;
                
                queue.push_back(a);
            }
        }
    } 
}
int main()
{
    Graph g(9);
    g.edgeAdd(0, 1);
    g.edgeAdd(0, 2);
    g.edgeAdd(0, 5);
    g.edgeAdd(2, 3);
    g.edgeAdd(1, 4);
    g.edgeAdd(5, 4);
    g.edgeAdd(3, 6);
    g.edgeAdd(3, 4);
    g.edgeAdd(4, 8);

    g.BFS(0);
    return 0;
}
