#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Time
{
public:
  int time;
  bool status;
  Time(int time, bool status)
  {
    this->time = time;
    this->status = status;
  }
};
bool comp(Time a, Time b)
{
  return a.time < b.time;
}
int main()
{
  int n;
  cin >> n;
  vector<Time> timings;
  for (int i = 0; i < n * 2; i++)
  {
    int num;
    cin >> num;
    if (i % 2 == 0)
    {
      Time t(num, true);
      timings.push_back(t);
    }
    else
    {
      Time t(num, false);
      timings.push_back(t);
    }
  }
  sort(timings.begin(),timings.end(), comp);
  int res = 0;
  int max_res = 0;
  for (int i = 0; i < n * 2; i++)
  {
    if(timings[i].status){
      res++;
    }else{
      res--;
    }
    max_res = max(max_res,res);
  }
  cout<<max_res;
}