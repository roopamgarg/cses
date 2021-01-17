#include <iostream>
#include <set>
#include <queue>
#define ll long long
using namespace std;

multiset<ll, greater<ll>> low;
multiset<ll> high;
ll lowSum = 0;
ll highSum = 0;
void mallain()
{
  if ((ll)(low.size() - high.size()) > 1)
  {
    auto highest = low.begin();
    ll num = *highest;
    high.insert(num);
    highSum += num;
    low.erase(highest);
    lowSum -= num;
  }
  if ((ll)(high.size() - low.size()) > 0)
  {
    auto first = high.begin();
    ll num = *first;
    low.insert(num);
    lowSum += num;
    high.erase(first);
    highSum -= num;
  }
}
void insert(ll key)
{

  if (low.empty())
  {
    low.insert(key);
    lowSum += key;
  }
  else if (*low.begin() < key)
  {
    high.insert(key);
    highSum += key;
  }
  else
  {
    low.insert(key);
    lowSum += key;

  }
  mallain();
}

void erase(ll key)
{
  auto inLow = low.find(key);
  auto inHigh = high.find(key);
  if (inLow != low.end())
  {
    low.erase(inLow);
    lowSum -= key;
  }
  else if (inHigh != high.end())
  {
    high.erase(inHigh);
    highSum -= key;
  }
  mallain();
}

int main()
{
  ll n, k;
  cin >> n >> k;
  ll arr[n];
  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (ll i = 0; i < k; i++)
  {
    insert(arr[i]);
  }
  for (ll i = k; i <= n; i++)
  {
    ll mid = *(low.begin());
    ll ls = low.size();
    ll hs = high.size();
    cout << (((mid * (ls - 1)) - (lowSum - mid)) + (highSum - (mid * hs))) << " ";
    if(i == n) continue;
    insert(arr[i]);
    erase(arr[i - k]);
  }
}