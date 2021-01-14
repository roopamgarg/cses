#include <iostream>
#include <map>
#include <set>
#include <deque>
#define ll long long
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  deque<int> Q;
  map<int, int> set;
  int distinct = 0;
  ll count = 0;
  for (int i = 0; i < n; i++)
  {

    int cur = arr[i];
    if (!set.count(cur) || (set.count(cur) && set[cur] == 0))
    {
      distinct++;
      int top = Q.front();
      if (distinct > k)
      {
        while (!Q.empty() && set[top] != 1)
        {
          set[top]--;
          Q.pop_front();
          top = Q.front();
        }
        set[top]--;
        Q.pop_front();
        top = Q.front();
      }
    }

    set[cur]++;
    Q.push_back(cur);
   // cout << Q.size() << " ";
    count += Q.size();
  }
  cout << count;
}