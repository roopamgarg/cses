#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree{
  vector<int> nodes,arr;
  public:
  SegmentTree(vector<int> arr, int size){
    this->arr = arr;
    nodes = vector<int>(size*4,0); 
    build(0,size-1);
  }
  private:
  void build(int start, int end, int index = 0){
    if(start == end){
      nodes[index] = 1;
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, index * 2 + 1);
    build(mid + 1, end, index * 2 + 2); 
    nodes[index] = nodes[index * 2 + 1] + nodes[index * 2 + 2];
  }
  public:
  void update(int start, int end, int target, int index = 0){
    if(start == end){
      nodes[index] = 0;
      return;
    }
    int mid = (start + end) / 2;
    if(target > mid){
      update(mid + 1, end, target, index * 2 + 2);
    }else{
      update(start, mid, target,index * 2 + 1);
    }
    nodes[index] = nodes[index * 2 + 1] + nodes[index * 2 + 2];
  }

  int find(int target, int start,int end, int index = 0){
    if(nodes[index] == 0){
      return 0;
    }
    if(start == end){
      int val = arr[start];
      update(0,arr.size() - 1,start);
      return val;
    }
    int left = nodes[index * 2 + 1];
    int right = nodes[index * 2 + 2];
    int mid = (start + end)/2;
    if(left < target){
      target -= left;
      find(target, mid+1,end,index * 2 + 2);
    }else{
      find(target, start,mid,index * 2 + 1);
    }
  }
};


int32_t main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  SegmentTree tree(arr,n);
  for(int i = 0; i < n; i++){
    int q;
    cin>>q;
    cout<<tree.find(q,0,n-1)<<endl;
  }
}