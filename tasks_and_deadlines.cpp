#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Pair{
  public:
  int time,deadline;
  Pair(int t, int d){
    time = t;
    deadline = d;
  }
};
bool comp(Pair a, Pair b){
  if(a.time == b.time){
    return a.deadline < b.deadline;
  }
  return a.time < b.time;
}
int main(){
  int n;
  cin>>n;
  vector<Pair> arr;
  for(int i = 0; i < n; i++){
    int t,d;
    cin>>t>>d;
    arr.push_back(Pair(t,d));
  }
  sort(arr.begin(),arr.end(),comp);
  ll res = 0;
  ll pos = 0;
  for(int i = 0; i < n; i++){
    pos += arr[i].time;
    res += arr[i].deadline - pos;
  }
  cout<<res;
}