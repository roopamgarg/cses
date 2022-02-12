#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

class Node
{
public:
  int val;
  int total_cost;
  bool is_ticket_used;
  Node(int val, int total_cost, bool is_ticket_used) : val(val), total_cost(total_cost), is_ticket_used(is_ticket_used) {}
};

struct CompareWeights
{
  bool operator()(Node *const &p1, Node *const &p2)
  {
    return p1->total_cost > p2->total_cost;
  }
};

int dijkstra(vector<vector<pair<int, int>>> &graph)
{
  priority_queue<Node *, vector<Node *>, CompareWeights> queue;
  queue.push(new Node(1, 0, false));
  vector<vector<int>> visited(graph.size(), vector<int>(2,LLONG_MAX));
  while (queue.size())
  {
    Node *current = queue.top();
    queue.pop();
    if (visited[current->val][current->is_ticket_used] <= current->total_cost)
      continue;
    visited[current->val][current->is_ticket_used] = current->total_cost;
    for (pair<int, int> nb : graph[current->val])
    {
      if(nb.first == current->val) continue;
      if (current->is_ticket_used)
      {
        queue.push(new Node(nb.first, current->total_cost + nb.second, true));
      }
      else
      {
        queue.push(new Node(nb.first, current->total_cost + nb.second, false));
        queue.push(new Node(nb.first, current->total_cost + (nb.second / 2), true));
      }
    }
  }
  return visited[graph.size() - 1][1];
}

int32_t main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  for (int i = 0; i < m; i++)
  {
    int v, u, c;
    cin >> v >> u >> c;
    graph[v].push_back({u, c});
  }
  cout<<dijkstra(graph);
  return 0;
}