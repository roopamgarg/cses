#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Value{
  public:
    int value;
    int position;
    Value(int value, int position){
      this->value = value;
      this->position = position;
    }
};

bool comp(Value a, Value b){
  return a.value < b.value;
}

int main(){
  int n,x;
  cin>>n>>x;
  vector<Value> arr;
  for(int i = 0; i < n; i++){
    int num;
    cin>>num;
    arr.push_back(Value(num,i));
  }
  sort(arr.begin(), arr.end(), comp);
  int start = 0, end = n-1; 
  bool isFound = false;

  while(start < end){
    int sum = arr[start].value + arr[end].value;
    if(sum < x){
      start++;
    }else if(sum > x){
      end--;
    }else{
      isFound = true;
      break;
    }
  }
  if(isFound){
    cout<<arr[start].position + 1<< " " <<arr[end].position + 1;
  }else{
    cout<<"IMPOSSIBLE";
  }
}