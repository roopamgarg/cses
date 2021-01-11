#include<iostream>
#include<stack>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> tower_of_hanoi(int n){
    vector<vector<int>> res;
    if(n == 1){
      vector<int> arr;
      arr.push_back(1);
      arr.push_back(3);
      res.push_back(arr);
      return res;
    }
    vector<vector<int>> prev = tower_of_hanoi(n - 1);
    for(int i = 0; i < prev.size(); i++){
      if(i%2 == 1){
        res.push_back(prev[i]);
        continue;
      }
      int first = prev[i][0];
      int second = prev[i][1];
      int third;
      if(first != 1 && second != 1){
        third = 1;
      }else if(first != 2 && second != 2){
        third = 2;
      }else if(first != 3 && second != 3){
        third = 3;
      } 
      vector<int> up = {first,third};
      vector<int> down = {third, second};

      res.push_back(up);
      res.push_back(prev[i]);
      res.push_back(down);
    }
    return res;
  
}
int main(){
  int n;
  cin>>n;
  vector<vector<int>> res = tower_of_hanoi(n);
  cout<<res.size()<<endl;
  for(int i = 0; i < res.size(); i++){
    cout<<res[i][0] << " "<< res[i][1]<<endl;
  }
}