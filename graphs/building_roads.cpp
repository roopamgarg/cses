#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(int node, vector<vector<int>>& graph,vector<bool>& visited){
  if(visited[node]) return;
  visited[node] = true;
  for(int nb: graph[node]){
    solve(nb, graph, visited);
  }
}

int32_t main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> graph(n+1);
  vector<bool> visited(n+1,false);
  for(int i = 0; i < m; i++){
    int v,u;
    cin>>v>>u;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }
  vector<pair<int,int>> edges;
  int prev = -1;
  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      solve(i,graph,visited);
      if(prev != -1){
          edges.push_back({prev,i});
      }
      prev = i;
    }
  }
  cout<<edges.size()<<endl;
  for(pair<int,int> p:edges){
    cout<<p.first<<" "<<p.second<<endl;
  }
  return 0;
}