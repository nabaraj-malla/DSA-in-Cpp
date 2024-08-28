// Problem statement
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers),
// find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

// Find the path using BFS and print the shortest path available.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> *getPathBFS(int **edges, int n, int sv, int ev, bool *visited)
{
    vector<int> *v = new vector<int>();
    if (sv == ev)
    {
        v->push_back(sv);
        return v;
    }

    unordered_map<int, int> map;
    visited[sv] = true;
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    bool pathFound = false;
    while (!pendingVertices.empty() && !pathFound)
    {
        int frontVertex = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == frontVertex)
            {
                continue;
            }

            if (edges[frontVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                pendingVertices.push(i);
                map[i] = frontVertex;
                if (i == ev)
                {
                    pathFound = true;
                    break;
                }
            }
        }
    }

    if (pathFound == false)
    {
        return NULL;
    }
    v->push_back(ev);
    int current = ev;
    while (current != sv)
    {
        current = map[current];
        v->push_back(current);
    }
    return v;
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

    vector<int> *v = new vector<int>();
    v = getPathBFS(edges, n, sv, ev, visited);
    if (v != NULL)
    {
        for (int i = 0; i < v->size(); i++)
        {
            cout << v->at(i) << " ";
        }
    }

    delete v;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    return 0;
}