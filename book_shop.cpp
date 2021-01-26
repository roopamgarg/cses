#include <iostream>
#include <cstring>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> book1, vector<int> book2)
{
  return book1[0] < book2[0];
}
int main()
{
  int n, x;
  cin >> n >> x;
  vector<vector<int>> books(n,vector<int>(2,0));
  for (int i = 0; i < n; i++)
  {
    cin >> books[i][0];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> books[i][1];
  }
  int dp[n][x + 1];
  memset(dp, 0, sizeof(dp));
  sort(books.begin(),books.end(), comp);
  for (int j = 0; j <= x; j++)
  {
    int amount = books[0][0];
    int pages = books[0][1];
    if (amount > j)
    {
      dp[0][j] = 0;
    }
    else
    {
      dp[0][j] = pages;
    }
    //  cout<<dp[0][j]<<" ";

  }
  // cout<<endl;
  for (int i = 1; i < n; i++)
  {

    int amount = books[i][0];
    int pages = books[i][1];
    for (int j = 0; j <= x; j++)
    {
      if (amount > j)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        dp[i][j] = max(pages + dp[i - 1][j - amount], dp[i - 1][j]);
      }
      // cout<<dp[i][j]<<" ";
    }
    // cout<<endl;
  }
  cout<<dp[n-1][x];
}