// Problem statement
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers),
// check if there exists any path between them or not. Print true if the path exists and false otherwise.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 2. E is the number of edges present in graph G.
#include <iostream>
using namespace std;

bool hasPath(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        return true;
    }

    if (edges[sv][ev] == 1)
    {
        return true;
    }
    visited[sv] = true;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }

        if (edges[sv][i] == 1 && !visited[i])
        {
            ans = hasPath(edges, n, i, ev, visited);
            if (ans == true)
            {
                return ans;
            }
        }
    }
    return ans;
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

    int sv, ev;
    cin >> sv >> ev;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    bool ans = hasPath(edges, n, sv, ev, visited);
    if (ans == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    return 0;
}