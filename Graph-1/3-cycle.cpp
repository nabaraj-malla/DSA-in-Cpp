// Problem statement
// Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph.
// A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
#include <iostream>
using namespace std;

int threeCycle(int **edges, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i || edges[i][j] == 0)
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if (edges[j][k] == 1 && edges[k][i] == 1)
                {
                    count++;
                }
            }
        }
    }

    return count / 6; // since in single cyle there can be 6 different combinations
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

    cout << threeCycle(edges, n);
    return 0;
}