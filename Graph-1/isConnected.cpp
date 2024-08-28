// Problem statement
// Given an undirected graph G(V,E), check if the graph G is connected graph or not.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 2. E is the number of edges present in graph G.
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void DFS(int **edges, int n, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }

        if (edges[sv][i] == 1 && !visited[i])
        {
            DFS(edges, n, i, visited);
        }
    }
}

bool isConnected(int **edges, int n, int sv, bool *visited)
{
    DFS(edges, n, sv, visited);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << (isConnected(edges, n, 0, visited) ? "true" : "false");
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    return 0;
}