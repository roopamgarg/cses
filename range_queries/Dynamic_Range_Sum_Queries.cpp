#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{
  vector<int> nodes, arr;

public:
  SegmentTree(vector<int> arr, int size)
  {
    this->arr = arr;
    nodes = vector<int>(size * 4, 0);
    build(0, size - 1);
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
};

int32_t main()
{
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  SegmentTree tree(arr, n);
  while (q--)
  {
    int type;
    cin >> type;
    if (type == 2)
    {
      int x, y;
      cin >> x >> y;
      cout << tree.find(x - 1, y - 1, 0, n - 1) << endl;
    }
    else
    {
      int k, u;
      cin >> k >> u;
      tree.update(0,n-1,k-1,u);
    }
  }
}