#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

class Node{
  public:
  int row;
  int col;
  Node* parent;
  char dir;
  Node(int row, int col, Node* parent, char dir) : row(row), col(col), parent(parent), dir(dir){}
};

bool check(vector<string>& grid,vector<vector<bool>> &v, int r, int c)
{
  int rows = v.size();
  int cols = v[0].size();
  return r >= 0 && r < rows && c >= 0 && c < cols && v[r][c] == false && grid[r][c] != '#';
}

vector<char> solve(vector<string>& grid)
{
  queue<pair<int, int>> lava;
  queue<Node*> person;
  int rows = grid.size();
  int cols = grid[0].size();
  vector<vector<bool>> spread(rows, vector<bool>(cols, false));
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  for (int row = 0; row < grid.size(); row++)
  {
    for (int col = 0; col < grid[0].size(); col++)
    {
      if (grid[row][col] == 'M')
      {
        // lava.push({row,col});
        spread[row][col] = true;
        if (check(grid,spread, row, col + 1))
          lava.push({row, col + 1});
        if (check(grid,spread, row, col - 1))
          lava.push({row, col - 1});
        if (check(grid,spread, row + 1, col))
          lava.push({row + 1, col});
        if (check(grid,spread, row - 1, col))
          lava.push({row - 1, col});
      }
      else if (grid[row][col] == 'A')
      {
        person.push(new Node(row, col, NULL, '\0'));
        visited[row][col] = true;
      }
    }
  }
  while (!person.empty())
  {
    int size = lava.size();
    while (size--)
    {
      pair<int, int> current = lava.front();
      int row = current.first;
      int col = current.second;
      spread[row][col] = true;
      lava.pop();
      if (check(grid,spread, row, col + 1))
        lava.push({row, col + 1});
      if (check(grid,spread, row, col - 1))
        lava.push({row, col - 1});
      if (check(grid,spread, row + 1, col))
        lava.push({row + 1, col});
      if (check(grid,spread, row - 1, col))
        lava.push({row - 1, col});
    }
    int posSize = person.size();
    while(posSize--){
      Node* current = person.front();
      int row = current->row;
      int col = current->col;
      visited[row][col] = true;
      person.pop();
      if(row == 0 || col == 0 || row == rows - 1 || col == cols - 1){
        Node* cur = current;
        vector<char> res;
        while(cur){
          res.push_back(cur->dir);
          cur = cur->parent;
        }
        return res;
      }
      
      if (check(grid,spread, row, col + 1) && check(grid,visited, row, col + 1))
        person.push(new Node(row, col + 1,current,'R'));
      if (check(grid,spread, row, col - 1) && check(grid,visited, row, col - 1))
        person.push(new Node(row, col - 1,current,'L'));
      if (check(grid,spread, row + 1, col) && check(grid,visited, row + 1, col))
        person.push(new Node(row + 1, col,current,'D'));
      if (check(grid,spread, row - 1, col) && check(grid,visited, row - 1, col))
        person.push(new Node(row - 1, col,current,'U'));
    }
  }
  return {};
}

int32_t main()
{
  int m, n;
  cin >> m >> n;
  vector<string> grid(m);
  for (int i = 0; i < m; i++)
  {
    cin >> grid[i];
  }
  vector<char> res = solve(grid);
  if(res.size() > 0){
    cout<<"YES"<<endl<<res.size() - 1<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  for(int i = res.size() - 2; i >= 0; i--){
    cout<<res[i];
  }
  return 0;
}