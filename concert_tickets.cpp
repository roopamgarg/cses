#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  multiset <int> tickets;
  int max_val[m];
  bool visited[n];
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    tickets.insert(num);
  }
  for (int i = 0; i < m; i++)
  {
    cin >> max_val[i];
  }

  for (int i = 0; i < m; i++)
  {
    auto k = tickets.lower_bound(max_val[i]);
    if(*k == max_val[i]){
      cout<<*k<<endl;
      tickets.erase(k);
    }else if(k != tickets.begin()){
      k--;
      cout<<*k<<endl;
      tickets.erase(k);
    }else{
      cout<<"-1"<<endl;
    }
   }
}