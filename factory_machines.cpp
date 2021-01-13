#include <iostream>
#include <queue>
#include <vector>
#define ll long long
using namespace std;

// class Machine
// {
// public:
//   ll time_for_one_product, total_time;
//   Machine(ll time)
//   {
//     time_for_one_product = time;
//     total_time = time;
//   }
// };

// struct compare
// {
//   bool operator()(Machine m1, Machine m2)
//   {
//     if (m1.total_time == m2.total_time)
//     {
//       return m1.time_for_one_product > m2.time_for_one_product;
//     }
//     return m1.total_time > m2.total_time;
//   }
// };

int main()
{
  ll n, t;
  cin >> n >> t;
  ll res = 0;
  ll high = 1e18, low = 0;
  ll arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  while (low <= high)
  {
    ll mid = (high + low) / 2;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += mid / arr[i];
      if (sum >= t)
      {
        break;
      }
    }
    if (sum >= t)
    {
      res = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  // priority_queue<Machine, vector<Machine>,compare> Q;
  // for(ll i = 0; i < n; i++){
  //   ll num;
  //   cin>>num;
  //   Q.push(Machine(num));
  // }
  // for(ll i = 0; i < t; i++){
  //   Machine m = Q.top();
  //   m.total_time += m.time_for_one_product;
  //   Q.pop();
  //   Q.push(m);
  // }
  // ll res = 0;
  // while(!Q.empty()){
  //   Machine top = Q.top();
  //   res = max(res,top.total_time - top.time_for_one_product);
  //   Q.pop();
  // }
  cout << res;
}