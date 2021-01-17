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

  for (ll i = 0; i < n; i++)
  {
    for (ll j = arr[i]; j <= t; j++)
    {
      dp[j] += dp[j-arr[i]];
      if(dp[j] >= mod){
        dp[j] -= mod;
      }
    //  dp[j] %= mod;
    }
  }

  cout << dp[t] % mod;
}