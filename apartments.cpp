#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  int req[n],avail[m];
  for(int i = 0; i <n; i++){
    cin>>req[i];
  }
  sort(req,req + n);
  for(int j = 0; j < m; j++){
    cin>>avail[j];
  }
  sort(avail,avail + m);
  int start = 0;
  int count = 0;
  for(int i = 0; i < n; i++){
    if(start >= m) break;
    else if(avail[start] < req[i] - k){
      start++;
      i--;
    }else if(avail[start] > req[i] + k){
      continue;
    }else{
      count++;
      start++;
    }
  }
  cout<<count;
}