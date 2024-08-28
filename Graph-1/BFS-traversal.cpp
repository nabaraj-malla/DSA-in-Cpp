// Problem statement
// Given an undirected and disconnected graph G(V, E), print its BFS traversal.

// Note:

// 1. Here you need to consider that you need to print BFS path starting from vertex 0 only.
// 2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 3. E is the number of edges present in graph G.
// 4. Take graph input in the adjacency matrix.
// 5. Handle for Disconnected Graphs as well
#include <iostream>
#include <queue>
using namespace std;

void bfsTraversal(int **edges, int n, int fv, bool *visited)
{
    queue<int> q;
    visited[fv] = true;
    q.push(fv);
    while (!q.empty())
    {
        int frontVertex = q.front();
        q.pop();
        cout << frontVertex << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == frontVertex)
            {
                continue;
            }

            if (edges[frontVertex][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfsTraversal(edges, n, i, visited);
        }
    }
}
int main()
{
    // Write your code here
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

    BFS(edges, n);
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}