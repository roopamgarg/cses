#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1000000000 + 7;
int main()
{
  ll n, t;
  cin >> n >> t;
  ll arr[n], dp[t + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  for (ll i = 1; i <= t; i++)
  {
    for (ll j = 0; j < n; j++)
    {
      if(i >= arr[j]){
        dp[i] = (dp[i] + dp[i - arr[j]]);
      }
    }
    
    dp[i] = dp[i] % mod;
  }
  
  cout << dp[t];
}