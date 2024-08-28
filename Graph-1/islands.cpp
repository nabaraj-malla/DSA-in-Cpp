// Problem statement
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if
// we can reach from any given island to any other island in the same group . Given V islands (numbered from 0 to V-1)
// and E connections or edges between islands. Can you count the number of connected groups of islands.
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<int> BFS(int **edges, int n, int sv, bool *visited)
{
    vector<int> ans;
    visited[sv] = true;
    queue<int> pendingQ;
    pendingQ.push(sv);
    while (!pendingQ.empty())
    {
        int front = pendingQ.front();
        pendingQ.pop();
        ans.push_back(front);
        for (int i = 0; i < n; i++)
        {
            if (edges[front][i] == 1 && !visited[i])
            {
                pendingQ.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
}

void islands(int **edges, int n, bool *visited)
{
    vector<vector<int>> output;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> ans = BFS(edges, n, i, visited);
            output.push_back(ans);
        }
    }

    cout << output.size();
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

    islands(edges, n, visited);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    return 0;
}