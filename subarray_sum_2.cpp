#include <iostream>
#include <map>
#define ll long long
using namespace std;

int main()
{
  int n, t;
  cin >> n >> t;
  ll arr[n];
  map<ll,int> sums;
  ll count = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];

    if (i > 0)
    {
      
      arr[i] += arr[i - 1];
      if (sums.count(arr[i] - t) == 1)
      {
        //sums[arr[i] - t]++;
        count += sums[arr[i] - t];
      }
      if (arr[i] == t)
      {
        count++;
      }
    }
    else if (arr[i] == t)
    {
      count++;
    }
    sums[arr[i]]++;
  }

  cout << count;
}