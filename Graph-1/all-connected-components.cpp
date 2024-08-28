// Problem statement
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// 2. E is the number of edges present in graph G.
// 3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

void printDFS(int **graph, int v, int s, bool *visited, vector<int> &ans)
{

    ans.push_back(s);
    visited[s] = true;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && graph[s][i] == 1)
            printDFS(graph, v, i, visited, ans);
    }
}

void printDFS(int **graph, int v, int s, bool *visited)
{
    vector<int> ans;
    printDFS(graph, v, s, visited, ans);

    sort(ans.begin(), ans.end());

    for (auto i : ans)
        cout << i << " ";
}

int main()
{
    int V, E;
    cin >> V >> E;

    int **graph = new int *[V];

    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[V] = false;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            printDFS(graph, V, i, visited);
            cout << endl;
        }
    }
}

/*

vector<int> BFS(int **edges, int n, int sv, bool *visited) {
  vector<int> ans;
  visited[sv] = true;
  queue<int> pendingQ;
  pendingQ.push(sv);
  while (!pendingQ.empty()) {
    int front = pendingQ.front();
    pendingQ.pop();
    ans.push_back(front);
    for (int i = 0; i < n; i++) {
      if (edges[front][i] == 1 && !visited[i]) {
        pendingQ.push(i);
        visited[i] = true;
      }
    }
  }
  return ans;
}

void allConnectedComponents(int **edges, int n, bool *visited) {
  vector<vector<int>> v;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      vector<int> ans = BFS(edges, n, i, visited);
      v.push_back(ans);
    }
  }

  for (int i = 0; i < v.size(); i++) {
    sort(v[i].begin(), v[i].end());
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i].at(j) << " ";
    }
    cout << endl;
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  int **edges = new int *[n];
  for (int i = 0; i < n; i++) {
    edges[i] = new int[n];
    for (int j = 0; j < n; j++) {
      edges[i][j] = 0;
    }
  }

  for (int i = 0; i < e; i++) {
    int f, s;
    cin >> f >> s;
    edges[f][s] = 1;
    edges[s][f] = 1;
  }

  bool *visited = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }

  allConnectedComponents(edges, n, visited);

  for (int i = 0; i < n; i++) {
    delete[] edges[i];
  }

  delete[] edges;
  delete[] visited;
  return 0;
}
*/