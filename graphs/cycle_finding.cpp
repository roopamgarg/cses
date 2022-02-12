#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

int bellmenFord(vector<vector<pair<int, int>>> &graph, vector<vector<int>> &edges, int n)
{
  vector<int> visited(n + 1, INT_MAX);
  for (int i = 0; i < n; i++)
  {
    for (vector<int> edge : edges)
    {
      visited[edge[1]] = min(visited[edge[1]], visited[edge[0]] + edge[2]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (vector<int> edge : edges)
    {
      if (visited[edge[1]] > visited[edge[0]] + edge[2])
        return edge[1];
    }
  }
  return -1;
}

int32_t main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].push_back({v, c});
    edges.push_back({u, v});
  }
  int res = bellmenFord(graph, edges, n);
  if(res == -1){
    cout << 0;
  }
  cout << 1;
  return 0;
}