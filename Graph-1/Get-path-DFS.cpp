// Problem statement
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

// Find the path using DFS and print the first path that you encountered.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPathDFS(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        vector<int> ans;
        ans.push_back(sv);
        return ans;
    }

    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }

        if (edges[sv][i] == 1 && !visited[i])
        {
            vector<int> ans = getPathDFS(edges, n, i, ev, visited);
            if (ans.size() != 0)
            {
                ans.push_back(sv);
                return ans;
            }
        }
    }

    return vector<int>();
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

    vector<int> ans = getPathDFS(edges, n, sv, ev, visited);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    return 0;
}