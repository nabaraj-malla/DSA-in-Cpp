// Problem statement
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

// Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
// For printing MST follow the steps -

// 1. In one line, print an edge which is part of MST in the format -
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weights, int n, bool *visited)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
        {
            minVertex = i;
        }
    }

    return minVertex;
}

void prims(int **edges, int n)
{
    bool *visited = new bool[n];
    int *weights = new int[n];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    // initializing source vertex weight and parent
    parent[0] = -1;
    weights[0] = 0;

    for (int i = 0; i < n; i++)
    {
        // find min vertex
        int minVertex = findMinVertex(weights, n, visited);
        visited[minVertex] = true;
        // updating the weights of adjacent vertices to minVertex
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[minVertex][i] != 0)
            {
                if (edges[minVertex][i] < weights[i])
                {
                    weights[i] = edges[minVertex][i];
                    parent[i] = minVertex;
                }
            }
        }
    }

    // displaying the MST and we start from 1 because 0 is the source and had no parent
    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weights[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weights[i] << endl;
        }
    }
}

int main()
{
    int n, E;
    cin >> n >> E;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int f, s, wt;
        cin >> f >> s >> wt;
        edges[f][s] = wt;
        edges[s][f] = wt;
    }

    prims(edges, n);
    return 0;
}