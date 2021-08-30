#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(vector<vector<int>> &graph, int n)
{
  vector<vector<int>> distance(n + 1, vector<int>(n + 1, LLONG_MAX));
  for (int k = 1; k <= n; k++)
  {

    for (int i = 1; i <= n; i++)
    {
      distance[i][k] = graph[i][k];
      distance[k][i] = graph[k][i];
    }

    for (int i = 1; i <= n; i++)
    {
      distance[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = i; j <= n; j++)
      {
        if (j == k || i == k || graph[i][k] == LLONG_MAX || graph[k][j] == LLONG_MAX)
        {
          distance[i][j] = distance[j][i] = graph[i][j];
        }
        else if (i == j)
        {
          distance[i][j] = 0;
        }
        else
        {
          distance[i][j] = distance[j][i] = min({graph[i][k] + graph[k][j], graph[i][j]});
        }
      }
    }
    graph = distance;
  }
}
int32_t main()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> graph(n + 1, vector<int>(n + 1, LLONG_MAX));
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a][b] = graph[b][a] = min(c,graph[a][b]);
  }
  solve(graph, n);
  for (int i = 0; i < q; i++)
  {
    int from, to;
    cin >> from >> to;
    if (graph[from][to] == LLONG_MAX)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << graph[from][to] << endl;
    }
  }
  return 0;
}
