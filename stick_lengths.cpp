#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n;
  cin >> n;
  ll sticks[n];
  for (ll i = 0; i < n; i++)
  {
    cin >> sticks[i];
  }
  sort(sticks,sticks+n);
  ll mid = (n / 2);
  ll sum = 0;
  for (ll i = 0; i < n; i++)
  {
    sum += abs(sticks[i] - sticks[mid]);
  }
  cout << sum;
}