#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int dp[n+1];
  dp[0] = 0;
  for(int i = 1; i <= n; i++){
    if(i < 10){
      dp[i] = 1;
    }else{
      int temp = i;
      dp[i] = INT_MAX;
      while(temp > 0){
        int cur = temp % 10;
        if(cur > 0){
          dp[i] = min(dp[i],dp[i - cur] + 1);
        }
        temp = temp / 10;
      }
    }
  }
  cout<<dp[n];
}