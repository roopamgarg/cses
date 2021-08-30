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

int findShortestRoute(vector<vector<pair<int, int>>> &graph, vector<vector<int>> &edges, int n)
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
  if(visited[1] != 0) return -1;
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

  int res = findShortestRoute(graph, edges, n);
  cout << res;
  return 0;
}