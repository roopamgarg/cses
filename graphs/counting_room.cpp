#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(vector<string> &grid, vector<vector<bool>> &visited, int row, int col)
{
  int n = grid.size();
  int m = grid[0].length();
  if (row < 0 || row >= n || col < 0 || col >= m)
    return false;
  if (visited[row][col] || grid[row][col] == '#')
    return false;
  return true;
}

void solve(vector<string> &grid, vector<vector<bool>> &visited, int row, int col)
{
  if (!check(grid, visited, row, col))
    return;
  visited[row][col] = true;
  solve(grid, visited, row + 1, col);
  solve(grid, visited, row - 1, col);

  solve(grid, visited, row, col + 1);
  solve(grid, visited, row, col - 1);

}

int32_t main()
{
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  int cnt = 0;
  
  for (int i = 0; i < n; i++)
  {
    cin >> grid[i];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (check(grid, visited, i, j))
      {
        solve(grid, visited, i, j);
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}