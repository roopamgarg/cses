#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct CompareWeights
{
  bool operator()(pair<int, int> const &p1, pair<int, int> const &p2)
  {
    return p1.second < p2.second;
  }
};

bool isCyclic(int root, vector<vector<pair<int, int>>> &graph, vector<bool> &visited)
{
  if (visited[root])
    return true;
  visited[root] = true;
  for (pair<int, int> nb : graph[root])
  {
    if (isCyclic(nb.first, graph, visited))
      return true;
  }
  return false;
}

int findShortestRoute(vector<vector<int>> &edges, int n)
{
  vector<int> visited(n + 1, INT_MIN);
  visited[1] = 0;
  for (int i = 0; i <= n; i++)
  {
    for (vector<int> edge : edges)
    {
      if (visited[edge[1]] < visited[edge[0]] + edge[2])
      {
        visited[edge[1]] = visited[edge[0]] + edge[2];
      }
    }
  }
  return visited[n];
}

int32_t main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    edges.push_back({a, b, c});
    // graph[b].push_back({a,c});
  }
  vector<bool> v(n + 1, false);
  if (!isCyclic(1, graph, v) && v[n] == true)
  {

    int res = findShortestRoute(edges, n);
    cout << res;
  }
  else
  {
    cout << -1;
  }
  return 0;
}