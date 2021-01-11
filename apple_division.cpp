#include<iostream>
#include<vector>
#define ll long long

using namespace std;

ll minimum_diff(vector<ll>& arr, ll i, ll a, ll b){
  if(i >= arr.size()){
    return abs(a-b);
  }
  ll group_1 = minimum_diff(arr,i+1, a + arr[i], b);
  ll group_2 = minimum_diff(arr, i+1, a, b + arr[i]);
  return min(group_1,group_2);
}

int main(){
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(ll i = 0; i < n; i++){
    cin>>arr[i];
  }
  cout<<minimum_diff(arr,0,0,0);
}