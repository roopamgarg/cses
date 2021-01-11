#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n,x;
  cin>>n>>x;
  ll arr[n];
  for(ll i = 0; i < n; i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  ll start = 0;
  ll end = n-1;
  ll count = 0;
  while(start <= end){
    if(start != end && arr[start] + arr[end] <= x){
      count++;
      start++;
      end--;
    }
    else if(arr[end] <= x){
      count++;
      end--;
    }
  
  }
  cout<<count;
}