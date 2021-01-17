#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n, t;
  cin >> n >> t;
  ll arr[n], dp[t + 1];
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  for (ll i = 0; i < n; i++)
  {
    for (ll j = arr[i]; j <= t; j++)
    {
      if (dp[j] == -1 && dp[j - arr[i]] != -1)
      {
        dp[j] = dp[j - arr[i]] + 1;
      }
      else if(dp[j - arr[i]] != -1)
      {
        dp[j] = min(dp[j], dp[j - arr[i]] + 1);
      }
    }
  }

  // for(int i = 0; i <= t; i++){
  //   cout<<dp[i]<<endl;
  // }
  cout << dp[t];
}