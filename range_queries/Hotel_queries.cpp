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
    nodes[index] = max(nodes[index * 2 + 1], nodes[index * 2 + 2]);
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
    nodes[index] = max(nodes[index * 2 + 1], nodes[index * 2 + 2]);
  }

  int find(int val, int start, int end, int index = 0)
  {
    //cout<<index<<" :";
    if (val > nodes[index])
    {
      return -1;
    }
    if (start == end)
    {
      update(0, arr.size() - 1, start, arr[start] - val);

      return start;
    }
    int mid = (start + end) / 2;
    if (nodes[index * 2 + 1] >= val)
    {
      return find(val, start, mid, index * 2 + 1);
    }
    else
    {
      return find(val, mid + 1, end, index * 2 + 2);
    }
  }
};

int32_t main()
{
  int n, m;
  cin >> n >> m;
  vector<int> avail(n);
  vector<int> req(m);
  for (int i = 0; i < n; i++)
  {
    cin >> avail[i];
  }
  SegmentTree tree(avail, n);
  for (int i = 0; i < m; i++)
  {
    int q;
    cin >> q;
    cout << tree.find(q, 0, n - 1) + 1 << endl;
  }

  return 0;
}