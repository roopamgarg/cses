#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

class Node{
  public:
  int value;
  Node* parent;
  Node(int value, Node* parent) : value(value), parent(parent){}
};
vector<int> getPath(Node* node){
  vector<int> path;
  while(node){
    path.push_back(node->value);
    node = node->parent;
  }
  return path;
}
vector<int> solve(int node, vector<vector<int>>& graph, int n){
  queue<Node*> q;
  q.push(new Node(node,NULL));
  vector<bool> visited(n+1,false);
  while(!q.empty()) {
    Node* cur = q.front();
    q.pop();
    if(visited[cur->value]) continue;
    visited[cur->value] = true;
    if(cur->value == n){
      return getPath(cur);
    }
    for(int nb: graph[cur->value]){
      q.push(new Node(nb,cur));
    }
  }

  return {};
}

int32_t main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> graph(n+1);
  for(int i = 0; i < m; i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<int> res = solve(1,graph, n);
  if(res.size()){
    cout<<res.size()<<endl;
    for(int i = res.size() - 1; i >= 0; i--){
      cout<<res[i]<<" ";
    }
  }else{
    cout<<"IMPOSSIBLE";
  }
  return 0;
}