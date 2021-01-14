#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool good(ll arr[], ll n, ll k, ll target){
  ll i = 0;
  ll sum = 0;
  ll count = 0;
  while(count < k && i < n){
   // if(count > k) break;
    while(sum + arr[i] <= target){
      sum += arr[i++];
    }
    sum = 0;
    count++;
  }
  return i == n;
}
ll array_divisions(ll arr[],ll n, ll k, ll sum){
  ll start = arr[0];
  ll end = sum;
  ll ans = sum;
  while(start <= end){
    ll mid = (start + end) / 2;
    if(good(arr,n,k,mid)){
      ans = mid;
      end = mid - 1;
    }else{
      start = mid + 1;
    }
  }
  return ans;
}

int main(){
  ll n, k;
  cin>>n>>k;
  ll sum = 0;
  ll arr[n], sum_arr[n];
  for(ll i = 0; i < n; i++){
    cin>>arr[i];
    sum += arr[i];
  }
  cout<<array_divisions(arr,n,k,sum);
}