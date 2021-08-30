#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct CompareWeights {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        return p1.second > p2.second;
    }
};

vector<int> findShortestRoute(vector<vector<pair<int,int>>>& graph, int n){
  priority_queue<pair<int,int>, vector<pair<int,int>>, CompareWeights> queue;
  vector<int> visited(n+1,-1);
  queue.push({1,0});
  while(!queue.empty()){
    pair<int,int> cur = queue.top();
    int node = cur.first;
    int wt = cur.second;
    queue.pop();
    if(visited[node] != -1) continue;
    visited[node] = wt;
    for(pair<int,int> nb: graph[node]){
      queue.push({nb.first,wt+nb.second});
    }
  }
  return visited;
}

int32_t main() {
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> graph(n+1);
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back({b,c});
  }

  vector<int> visited = findShortestRoute(graph,n);
  for(int i = 1; i < visited.size(); i++){
    cout<<visited[i]<<" ";
  }
  return 0;
}