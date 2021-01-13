#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int arr[n];
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
    sum += arr[i];
  }
  sort(arr,arr+n);
  if(arr[n-1] >= sum / 2){
    cout<<arr[n-1] * 2;
  }else{
    cout<<sum;
  }
}