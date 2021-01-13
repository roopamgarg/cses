#include <iostream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class People
{
public:
  ll arrival, departure, room;
  People(ll a, ll d)
  {
    arrival = a;
    departure = d;
    room = -1;
  }
};

struct CompareDeparture
{
  bool operator()(People *p1, People *p2)
  {

    if (p1->departure == p2->departure)
    {
      return p1->arrival > p2->arrival;
    }

    return p1->departure > p2->departure;
  }
};

bool comp(People *p1, People *p2)
{
  return p1->arrival < p2->arrival;
}
int main()
{
  ll n;
  cin >> n;
  vector<People *> peoples, peoples_sorted;

  for (ll i = 0; i < n; i++)
  {
    ll a, d;
    cin >> a >> d;
    peoples.push_back(new People(a, d));
    peoples_sorted.push_back(peoples[i]);
  }
  sort(peoples_sorted.begin(), peoples_sorted.end(), comp);
  priority_queue<People *, vector<People *>, CompareDeparture> Q;
  ll max_size = 0;
  for (ll i = 0; i < n; i++)
  {
  
    if (Q.size() == 0)
    {
      peoples_sorted[i]->room = 1;
      Q.push(peoples_sorted[i]);
    }
    else if (peoples_sorted[i]->arrival <=   Q.top()->departure)
    { 
      peoples_sorted[i]->room = Q.size() + 1;
      Q.push(peoples_sorted[i]);
    }
    else
    {
      People *prev = Q.top();
      peoples_sorted[i]->room = prev->room;
      Q.pop();
      Q.push(peoples_sorted[i]);
    }
    max_size = max(max_size, (ll)Q.size());
  }
  cout << max_size << endl;
  for (ll i = 0; i < n; i++)
  {
    cout << peoples[i]->room << " ";
  }
}