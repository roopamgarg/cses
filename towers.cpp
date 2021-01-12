#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  multiset<int> towers;
  for (int i = 0; i < n; i++)
  {
    int cube;
    cin >> cube;
    auto k = towers.upper_bound(cube);
    if (k == towers.end())
    {
      towers.insert(cube);
    }
    else
    {
      towers.insert(cube);
      towers.erase(k);
    }
  }
  cout << towers.size();
}