#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
  if(p1.first == p2.first){
    return p1.second < p2.second; 
  }
  return p1.first < p2.second;
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> avail(n);
    vector<int> req(m);
    for(int i = 0; i < n; i++){
      cin>>avail[i].first;
      avail[i].second = i+1;
    }
    sort(avail.begin(),avail.end(),comp);
    for(int i = 0; i < m; i++){
      int q;
      cin>>q;
      auto index = lower_bound(avail.begin(),avail.end(),q,comp) - avail.begin();
      avail
    }
    
  return 0;
}