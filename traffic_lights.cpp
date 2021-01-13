#include<iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
  int x,n;
  multiset<int> lights,sorted_gaps;
  cin>>x>>n;
  lights.insert(0);
  lights.insert(x);
  sorted_gaps.insert(x);
  for(int i = 0; i < n; i++){
    int num;
    cin>>num;
    auto k = lights.upper_bound(num);
    auto prev = k;
    prev--;
    auto cur_gap = sorted_gaps.find(*k - *(prev));
    sorted_gaps.erase(cur_gap);
    sorted_gaps.insert(num - *prev);
    sorted_gaps.insert(*k - num);
    lights.insert(num);
    auto last = sorted_gaps.end();
    last--;
    cout<<*last<< " ";
  }

}
