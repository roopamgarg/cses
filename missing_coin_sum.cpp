#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n;
  cin>>n;
  ll arr[n];
  ll sum = 0;
  for(ll i = 0; i < n; i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  bool isFound = false;
  for(ll i = 0; i < n; i++){
    if(arr[i] - sum <= 1){
      sum += arr[i];
    }else{
      cout<<sum+1;
      isFound = true;
      break;
    }
  }

    if(!isFound){
      cout<<sum+1;
    }

}