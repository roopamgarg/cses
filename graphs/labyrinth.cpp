#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

class Node
{
public:
  int row;
  int col;
  char psf;
  Node* parent;
  Node(int r, int c, char str, Node* p)
  {
    row = r;
    col = c;
    psf = str;
    parent = p;
  }
};

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

vector<char> solve(vector<string> &grid, vector<vector<bool>> &visited, int row, int col, char psf)
{
  queue<Node*> q;
  q.push(new Node(row, col, psf,NULL));
  while (!q.empty())
  {
    Node* top = q.front();
    int r = top->row;
    int c = top->col;
    //cout<<r<<" "<<c<<endl;
    char psf = top->psf;
    q.pop();
    if (!check(grid, visited, r, c))
      continue;

    if (grid[r][c] == 'B'){
      vector<char> res;
      
      while(top->parent){
        res.push_back(top->psf);
        top = top->parent;
      }
      return res;
    }
      
    visited[r][c] = true;
    if (check(grid, visited, r + 1, c)){
      q.push(new Node(r + 1, c, 'D', top));
    }
    if (check(grid, visited, r - 1, c)){
      q.push(new Node(r - 1, c, 'U', top));
    }
    if (check(grid, visited, r, c + 1)){
      q.push(new Node(r, c + 1, 'R', top));
    }
    if (check(grid, visited, r, c - 1)){
      q.push(new Node(r, c - 1, 'L', top));
    }
  }
  return {};
}

int32_t main()  
{
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  vector<char> psf;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  int cnt = 0;
  vector<char> res;
  for (int i = 0; i < n; i++)
  {
    cin >> grid[i];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 'A')
      {
        res = solve(grid, visited, i, j, '\0');
        break;
      }
    }
  }
  if (res.size() > 0)
  {
    cout << "YES" << endl
         << res.size() << endl;
    for(int i = res.size() - 1; i >= 0; i--){
      cout<<res[i];
    }
  }
  else
  {
    cout << "NO";
  }
  return 0;
}