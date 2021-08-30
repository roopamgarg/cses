#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

bool solve(int node, vector<vector<int>>& graph, vector<int>& res, vector<bool>& visited){
  queue<int> queue;
  queue.push(node);
  int cur = 2;
  while(!queue.empty()){
    int size = queue.size();
    cur = cur == 1 ? 2 : 1;
    while(size--){
      int top = queue.front();
      queue.pop();
      if(visited[top]){
        if(res[top] != cur) return false; 
        continue;
      } 
      visited[top] = true;
      res[top] = cur;
      for(int nb: graph[top]){
        queue.push(nb);
      }
    }
  }
  return true;
}

int32_t main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> graph(n+1);
  vector<int> res(n+1,0);
  vector<bool> visited(n+1,false);

  for(int i = 0; i < m;i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for(int i = 1; i <= n; i++){
    if(!visited[i] && !solve(i,graph,res,visited)){
      cout<<"IMPOSSIBLE";
      return 0;
    }
  }
  for(int i = 1; i <= n; i++){
    cout<<res[i]<<" ";
  }
  return 0;
}