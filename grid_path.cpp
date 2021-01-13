#include <iostream>
#include <vector>
using namespace std;
int count = 0;

void printGrid(vector<vector<int>> dp){
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
      cout<<dp[i][j]<<" ";
    }
      cout<<endl;

  }

      cout<<endl<<endl;

}

int find_total_paths(string& str, vector<vector<int>> &dp, int visited = 0, int index = 0, int row = 0, int col = 0)
{
//  printGrid(dp);

  if (index == str.length() && row == 6 && col == 0)
  {
    return 1;
  }
  else if (index >= str.length() || (row == 6 && col == 0))
  {
    return 0;
  }

  if ((row < 0 || row > 6) || (col < 0 || col > 6))
  {
    return 0;
  }
  //  cout <<index<<" = "<< row<< " " <<col << endl;
  

  if (((row == 0 || row == 6) && (col > 0 && col < 6)) && (dp[row][col - 1] == 0 && dp[row][col + 1] == 0))
  {
    return dp[row][col] = 0;
  }
  else if (((col == 0 || col == 6) && (row > 0 && row < 6)) && (dp[row - 1][col] == 0 && dp[row + 1][col] == 0))
  {
    return dp[row][col] = 0;

  }
  else if (row > 0 && row < 6 && col > 0 && col < 6 && dp[row][col - 1] == 1 && dp[row][col + 1] == 1 && dp[row - 1][col] == 0 && dp[row + 1][col] == 0)
  {
    return dp[row][col] = 0;

  }
  else if (row > 0 && row < 6 && col > 0 && col < 6 && dp[row + 1][col] == 1 && dp[row - 1][col] == 1 && dp[row][col + 1] == 0 && dp[row][col - 1] == 0)
  {
    return dp[row][col] = 0;
  }

  int ch = str[index];
  int sum = 0;
  visited += 1;
  if (ch == '?')
  {
    if(row + 1 <= 6 && dp[row+1][col] == 0){
      dp[row+1][col] = 1;
      sum += find_total_paths(str, dp, visited, index + 1, row + 1, col);
      dp[row+1][col] = 0;
    }

    if(row - 1 >= 0 && dp[row-1][col] == 0){
      dp[row-1][col] = 1;
      sum += find_total_paths(str, dp, visited, index + 1, row - 1, col);
      dp[row-1][col] = 0;
    }

    if(col + 1 <= 6 && dp[row][col+1] == 0){
      dp[row][col+1] = 1;
      sum += find_total_paths(str, dp, visited, index + 1, row, col+1);
      dp[row][col+1] = 0;
    }

    if(col - 1 >= 0 && dp[row][col - 1] == 0){
      dp[row][col - 1] = 1;
      sum += find_total_paths(str, dp, visited, index + 1, row , col - 1);
      dp[row][col - 1] = 0;
    }
  }
  else if (ch == 'D')
  {
    if(row + 1 <= 6 && dp[row+1][col] == 0){
      dp[row+1][col] = 1;
      sum += find_total_paths(str, dp, visited, index + 1, row + 1, col);
      dp[row+1][col] = 0;
    }
  }
  else if (ch == 'R')
  {
    if(col + 1 <= 6 && dp[row][col+1] == 0){
      dp[row][col+1] = 1;
      sum += find_total_paths(str, dp, visited, index + 1, row, col+1);
      dp[row][col+1] = 0;
    }
  }
  else if (ch == 'L')
  {

    if(col - 1 >= 0 && dp[row][col - 1] == 0){
      dp[row][col - 1] = 1;
      sum += find_total_paths(str, dp, visited, index + 1, row , col - 1);
      dp[row][col - 1] = 0;
    }
  }
  else if (ch == 'U')
  {
     if(row - 1 >= 0 && dp[row-1][col] == 0){
      dp[row-1][col] = 1;
      sum += find_total_paths(str, dp, visited, index + 1, row - 1, col);
      dp[row-1][col] = 0;
    }

  }
  dp[row][col] = 0;
  
  return sum;
}
int main()
{
  string str;
  cin >> str;
  vector<vector<int>> dp(7, vector<int>(7, 0));
  dp[0][0] = 1;
  cout << find_total_paths(str, dp, 0, 0, 0, 0);
}