#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int i, int j, int rows, int cols, int left_diag, int right_diag)
{
  if ((rows & (1 << i)) > 0 || (cols & (1 << j)) > 0 || (left_diag & (1 << (i - j + 7))) > 0 || (right_diag & (1 << (i + j))) > 0)
  {
    return false;
  }
  return true;
}
int res = 0;
void placeQueens(vector<string> board, int row, int rows, int cols, int left_diag, int right_diag)
{
  if(row >= board.size()){
    res++;
    return;
  }
  for (int c = 0; c < 8; c++)
  {
    if (isSafe(row, c, rows, cols, left_diag, right_diag) && board[row][c] != '*')
    {
      rows |= (1 << row);
      cols |= (1 << c);
      left_diag |= (1 << (row - c + 7));
      right_diag |= (1 << (row + c));
      placeQueens(board, row + 1, rows, cols, left_diag, right_diag);
      rows ^= (1 << row);
      cols ^= (1 << c);
      left_diag ^= (1 << (row - c + 7));
      right_diag ^= (1 << (row + c));
    }
  }
}

int main()
{
  vector<string> board(8);
  for (int i = 0; i < 8; i++)
  {
    cin >> board[i];
  }
  placeQueens(board,0,0,0,0,0);
  cout<<res;
}