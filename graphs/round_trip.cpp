#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int res = -1;
deque<int> resultant;
void solve(int root, int parent, vector<vector<int>> &graph, vector<bool> &visited, deque<int> &path)
{

  if (visited[root])
  {
    if (resultant.size() == 0)
    {
      path.push_back(root);
      resultant = path;
      res = root;
      path.pop_back();
    }
    return;
  }
  visited[root] = true;
  path.push_back(root);
  for (int nb : graph[root])
  {
    if (nb == parent)
      continue;
    solve(nb, root, graph, visited, path);
  }
  path.pop_back();
}

int32_t main()
{
  int m, n;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<bool> visited(n + 1, false);
  deque<int> path;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for(int i = 0; i < n; i++){
    if(!visited[i])
    solve(i, -1, graph, visited, path);

  }
  if(res == -1) {
    cout<<"IMPOSSIBLE";
    return 0;
  }

  while(resultant.front() != resultant.back()){
    resultant.pop_front();
  }
  cout<<resultant.size()<<endl;
  for (int node : resultant)
  {
    cout << node << " ";
  }
  return 0;
}