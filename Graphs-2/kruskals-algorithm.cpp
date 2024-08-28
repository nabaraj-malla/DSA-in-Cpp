// Problem statement
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

// For printing MST follow the steps -

// 1. In one line, print an edge which is part of MST in the format -
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
#include <iostream>
#include <algorithm>
using namespace std;

// we create edge class since graphs is a collection of edge & edge contain multiple datas
class Edge
{
public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int getParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }

    getParent(parent[v], parent);
}

void kruskals(Edge *input, int n, int E)
{
    // sort the input array ascending order based on their weights
    sort(input, input + E, compare);
    // creating an parent array & initially index itself is parent
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    Edge *output = new Edge[n - 1];
    // we retrieve each edges from input array and check their source & dest parents
    // if same we insert it into output array otherwise we discard
    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        Edge currentEdge = input[i];
        int sourceParent = getParent(currentEdge.source, parent);
        int destParent = getParent(currentEdge.dest, parent);
        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent; // we make destparent as parent of sourceParent to connect them
        }
        i++;
    }

    // display MST
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].dest)
        {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main()
{
    int n, E;
    cin >> n >> E;
    // we create  an array of edge type to store all the edges in each array index
    Edge *input = new Edge[E]; // we set E objects in our E size array
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, n, E);
    return 0;
}