#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{
  vector<int> nodes, lazy, array;

public:
  SegmentTree(vector<int> arr)
  {
    int size = arr.size();
    array = arr;
    nodes = vector<int>(size * 4, 0);
    lazy = vector<int>(size * 4, 0);
    build(0, size - 1);
  }

private:
  void build(int start, int end, int index = 0)
  {
    if (start == end)
    {
      nodes[index] = array[start];
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, index * 2 + 1);
    build(mid + 1, end, index * 2 + 2);
  }
  void updateLazy(int index, int start, int end)
  {

    if (lazy[index] != 0)
    {
      int prev = lazy[index];
      lazy[index] = 0;
      if (start != end)
      {
        lazy[index * 2 + 1] += prev;
        lazy[index * 2 + 2] += prev;
      }
      nodes[index] += prev;
    }
  }

public:
  void update(int range_start, int range_end, int start, int end, int val, int index = 0)
  {
    updateLazy(index, start, end);
    if (range_start > end || range_end < start) return;
    if (range_start <= start && range_end >= end)
    {
      nodes[index] += val;
      if (start != end)
      {
        lazy[index * 2 + 1] += val;
        lazy[index * 2 + 2] += val;
      }
      return;
    }

    int mid = (start + end) / 2;
    update(range_start, range_end, start, mid, val, index * 2 + 1);
    update(range_start, range_end, mid + 1, end, val, index * 2 + 2);
  }

  int find(int start, int end, int target, int index = 0)
  {
    updateLazy(index, start, end);
    if (start == end)
    {
      return nodes[index];
    }
    int mid = (start + end) / 2;
    if (target > mid)
    {
      return find(mid + 1, end, target, index * 2 + 2);
    }
    else
    {
      return find(start, mid, target, index * 2 + 1);
    }
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
  SegmentTree tree(arr);
  while (q--)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int s, e, v;
      cin >> s >> e >> v;
      tree.update(s - 1, e - 1, 0, n - 1, v);
      //tree.print();
    }
    else
    {
      int t;
      cin >> t;
      cout << tree.find(0, n - 1, t - 1) << endl;
    }
  }
  return 0;
}