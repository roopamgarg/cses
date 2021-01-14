#include <iostream>
#include <map>
#define ll long long
using namespace std;

int main()
{
  ll n;
  cin >> n;
  ll t = n;
  ll arr[n];
  map<ll, ll> sums;
  ll count = 0;
  ll sum = 0;
  sums[0] = 1;
  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum = (sum + (arr[i]));

      int rem = sum % t;
      if(rem < 0){
        rem += t;
      }
    if (i > 0)
    {
      if (sums.count(rem))
        count += sums[rem];
    }
    else if (rem == 0)
    {
      count++;
    }
    sums[rem]++;
  }
  // for (ll i = 0; i < n; i++)
  // {
  //   cout << arr[i] << " ";
  // }
  cout << count;
}