#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{
  vector<int> nodes, arr;

public:
  // create segment tree
  SegmentTree(){}
  SegmentTree(vector<int> arr)
  {
    int size = arr.size();
    this->arr = arr;
    nodes = vector<int>(size * 4, 0);
    build(0, size - 1);
  }

  // copy segment tree
  SegmentTree(vector<int>& nodes, int size)
  {
    this->nodes = nodes;
    this->arr = vector<int>(size);
    buildFromTree(0, size - 1);
  }

private:
  void build(int start, int end, int index = 0)
  {
    if (start == end)
    {
      nodes[index] = arr[start];
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, index * 2 + 1);
    build(mid + 1, end, index * 2 + 2);
    nodes[index] = nodes[index * 2 + 1] + nodes[index * 2 + 2];
  }
  void buildFromTree(int start, int end, int index = 0)
  {
    if (start == end)
    {
      arr[start] = nodes[index];
      return;
    }
    int mid = (start + end) / 2;
    buildFromTree(start, mid, index * 2 + 1);
    buildFromTree(mid + 1, end, index * 2 + 2);
  }

public:
  void update(int start, int end, int target, int value, int index = 0)
  {
    if (start == end)
    {
      nodes[index] = value;
      arr[target] = value;
      return;
    }
    int mid = (start + end) / 2;
    if (target > mid)
    {
      update(mid + 1, end, target, value, index * 2 + 2);
    }
    else
    {
      update(start, mid, target, value, index * 2 + 1);
    }
    nodes[index] = nodes[index * 2 + 1] + nodes[index * 2 + 2];
  }

  int find(int range_start, int range_end, int start, int end, int index = 0)
  {
    if (range_end < start || range_start > end)
    {
      return 0;
    }
    if (range_start <= start && range_end >= end)
    {
      return nodes[index];
    }
    int mid = (start + end) / 2;
    int left = find(range_start, range_end, start, mid, index * 2 + 1);
    int right = find(range_start, range_end, mid + 1, end, index * 2 + 2);
    return left + right;
  }

  int top()
  {
    return nodes[0];
  }
  int size()
  {
    return nodes.size();
  }
  void print(){
    for(int cur: nodes){
      cout<<cur<<" ";
    }
    cout<<endl;
  }
  vector<int> getCopy()
  {
    return nodes;
  }
  int getVal(int index){
    if(index < arr.size())
      return arr[index];
    return -1;
  }
  SegmentTree operator+(SegmentTree& tree)
  {
    vector<int> newTree = vector<int>(size());
    vector<int> secondTree = tree.getCopy();
  
    for (int i = 0; i < size(); i++)
    {
      newTree[i] = this->nodes[i] + secondTree[i];

    }
   SegmentTree copy(newTree, arr.size());
   return copy;
  }
};

class SegmentTree2D
{
  vector<SegmentTree> nodes;
  vector<vector<int>> matrix;

public:
  SegmentTree2D(vector<vector<int>>& matrix)
  {
    nodes = vector<SegmentTree>(matrix.size() * 4);
    this->matrix = matrix;
    build(0,matrix.size() - 1);
    
  }

private:
  void build(int row_start, int row_end, int index = 0)
  {
    if (row_start == row_end)
    {
      nodes[index] = SegmentTree(matrix[row_start]);
    
      return;
    }
    int mid = (row_start + row_end) / 2;
    build(row_start, mid, index * 2 + 1);
    build(mid + 1, row_end, index * 2 + 2);
    nodes[index] = nodes[index * 2 + 1] + nodes[index * 2 + 2];
  
  }

public:
  void update(int row_start, int row_end, int target_row, int target_col, int index = 0)
  {
    int curr = matrix[target_row][target_col];
    if (row_start == row_end)
    {
      nodes[index].update(0, matrix[target_row].size() - 1, target_col, !curr);
      matrix[target_row][target_col] = !curr;
      return;
    }
    int mid = (row_start + row_end) / 2;
    if (target_row > mid)
    {
      update(mid + 1, row_end, target_row, target_col, index * 2 + 2);
    }
    else
    {
      update(row_start, mid, target_row, target_col, index * 2 + 1);
    }
    if(curr == 1){
      nodes[index].update(0,matrix.size() - 1,target_col, nodes[index].getVal(target_col) - 1);
    }else{
      nodes[index].update(0,matrix.size() - 1,target_col, nodes[index].getVal(target_col) + 1);
    }
  }

  int find(int row_range_start, int row_range_end, int col_range_start, int col_range_end, int row_start, int row_end, int index = 0)
  {
    if(row_range_start > row_end || row_range_end < row_start){
      return 0;
    }
    
    if(row_range_start <= row_start && row_range_end >= row_end){
      int res = nodes[index].find(col_range_start, col_range_end, 0, matrix.size() - 1);
     
      return res;
    }
    int mid = (row_start + row_end) / 2;
    int left = find(row_range_start, row_range_end, col_range_start,col_range_end,row_start,mid, index * 2 + 1);
    int right = find(row_range_start, row_range_end, col_range_start,col_range_end,mid+1,row_end, index * 2 + 2);
    return left + right;
  }
};

int32_t main()
{
  int n,q;
  cin>>n>>q;
  vector<string> str(n);
  for(int i = 0; i < n; i++){
    cin>>str[i];
  }
  vector<vector<int>> matrix(n,vector<int>(n,0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(str[i][j] == '*'){
        matrix[i][j] = 1;
      }
    }
  }
  SegmentTree2D tree(matrix);
  while(q--){
    int type;
    cin>>type;
    if(type == 2){

    int row_start,col_start,row_end,col_end;
    cin>>row_start>>col_start>>row_end>>col_end;
    cout<<tree.find(row_start-1,row_end-1,col_start-1,col_end-1,0,n-1)<<endl;
    }else{
        int row,col;
        cin>>row>>col;
        tree.update(0,n-1,row-1,col-1);
    }
  }
  return 0;
}