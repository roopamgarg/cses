#include<iostream>
#define ll long long
using namespace std;

int main(){
  int n, t;
  cin>>n>>t;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
    // if(i > 0){
    //   arr[i] += arr[i-1];
    // }
  }
  int start = 0;
  int end = 0;
  ll sum = arr[0];
  int count = 0;
  while(end < n && start < n){

    if(sum < t){
      end++;
      sum += arr[end];
    }else if(sum > t){
      sum -= arr[start];
      start++;
    }else{
      count++;
      sum -= arr[start++];
      sum += arr[++end];
    }
  }
  cout<<count;
}