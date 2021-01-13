#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Pair{
  public:
  int num,pos;
  Pair(int n,int p){
    num = n;
    pos = p;
  }
};
bool comp(Pair p1, Pair p2){
  return p1.num < p2.num;
}
bool compPos(Pair p1, Pair p2){
  return p1.pos < p2.pos;
}
vector<Pair> twoSum(vector<Pair> arr, ll target, int start, int end)
{
  vector<Pair> res;
  while (start < end)
  {
    if (arr[start].num + arr[end].num < target)
    {
      start++;
    }
    else if (arr[start].num + arr[end].num > target)
    {
      end--;
    }
    else
    {
      res = {arr[start], arr[end]};
      return res;
    }
  }
  return res;
}
vector<Pair> threeSum(vector<Pair> arr,ll target, int start){
  vector<Pair> res;
  for(int i = start; i < arr.size() - 2; i++){
    ll sum = arr[i].num;
    vector<Pair> rest = twoSum(arr,target - arr[i].num, i+1, arr.size() - 1);
    if(rest.size() == 2){
      sum += rest[0].num + rest[1].num;
      if(sum == target){
        res = {arr[i],rest[0], rest[1]};
        return res;
      }
    }
  }
  return res;
}
vector<Pair> fourSum(vector<Pair> arr,ll target){
  vector<Pair> res;
  for(int i = 0; i < arr.size() - 3; i++){
    ll sum = arr[i].num;
    vector<Pair> rest = threeSum(arr,target - arr[i].num, i+1);
    if(rest.size() == 3){
      sum += rest[0].num + rest[1].num + rest[2].num;
      if(sum == target){
        res = {arr[i],rest[0], rest[1], rest[2]};
        return res;
      }
    }
  }
  return res;
}
int main()
{
  int n, t;
  cin>>n>>t;
  if(n < 3){
    cout<<"IMPOSSIBLE";
    return 0;
  }
  vector<Pair> arr;

  for(int i = 0; i < n; i++){
    int num;
    cin>>num;
    arr.push_back(Pair(num,i));
  }
  sort(arr.begin(),arr.end(),comp);
  vector<Pair> res = fourSum(arr,t);
  if(res.size() == 4){
    sort(res.begin(),res.end(),compPos);
    cout<<res[0].pos + 1<<" "<<res[1].pos + 1<<" "<<res[2].pos + 1<<" "<< res[3].pos + 1;
  }else{
    cout<<"IMPOSSIBLE";
  }
}