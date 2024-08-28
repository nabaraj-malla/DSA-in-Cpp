// Problem statement
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int n, bool *visited, int *distance)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }

    return minVertex;
}

void dijkstra(int **edges, int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[0] = 0;
    // retrieve each minVertex from vertex set
    for (int i = 0; i < n; i++)
    {
        int minVertex = findMinVertex(n, visited, distance);
        visited[minVertex] = true;
        // exploring all the adjacent vertices to minVertex
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[minVertex][i] != 0)
            {
                int currentDistance = distance[minVertex] + edges[minVertex][i];
                if (currentDistance < distance[i])
                {
                    distance[i] = currentDistance;
                }
            }
        }
    }

    // displaying the all vertices and its cost path from source to that vertex
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
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

    dijkstra(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}