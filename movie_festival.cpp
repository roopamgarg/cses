#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long

using namespace std;

class Time{
  public:
    ll time;
    bool is_started;
    Time *start;
    ll max_watched;
    Time(ll time,bool is_started,Time* start){
      this->time = time;
      this->is_started = is_started;
      this->start = NULL;
      max_watched = 0;
      if(!is_started){
        this->start = start;
       // start->max_watched = 10;
      }
    }
};
bool comp(Time *a,Time *b){
  //cout<<a->time<<endl;
  if(a->time == b->time){
    return (a && a->is_started) ? false : true;
  }
  return a->time < b->time;
}
int main(){
  ll n;
  cin>>n;
  vector<Time*> timings;
  map<int,int> occurred;
  for(ll i = 0; i < n; i++){
    ll start,end;
    cin>>start>>end;
    if(occurred.count(start) && occurred[start] == end) continue;
    else 
      occurred[start] = end;
    Time *start_time = new Time(start,true,NULL);
    timings.push_back(start_time);
    Time *end_time = new Time(end,false,start_time);
    timings.push_back(end_time);

  }
  sort(timings.begin(), timings.end(), comp);

  ll res = 0;
  for(ll i = 0; i < timings.size(); i++){
    if(timings[i]->is_started){
      timings[i]->max_watched = res;
    }else{
      res = max(res,timings[i]->start->max_watched + 1); 
    }
  }
  cout<<res;
}