#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  multiset<int> set;
  for (int i = 0; i < k; i++)
  {
    set.insert(arr[i]);
  }

  auto iter = set.begin();
  advance(iter, k / 2);
  if(k % 2 == 0) iter--;
  //iter--;
  for(int i = k; i <= n; i++){
    int mid = *iter;
    cout << mid << " ";
    set.insert(arr[i]);
    if(mid > arr[i]){
      iter--;
    }
    mid = *iter;
    if(mid >= arr[i-k]){
      iter++;
    }
    set.erase(set.find(arr[i-k]));
  }
}