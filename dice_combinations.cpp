#include<iostream>
#define ll long long
using namespace std;

ll mod = 1000000000 + 7;

int main(){
  int n;
  cin>>n;
  ll dp[n + 1];
  dp[0] = 0;
  dp[1] = 1;
  ll sum = 1;
  for(int i = 2; i <= n; i++){
      ll res = 0;
      if(i < 7){
        res = (dp[i-1] * 2) % mod;
        sum = (sum + res) % mod;
      }else{       
        res = (sum - dp[i-7]) % mod;
        sum = (sum + res - dp[i-7]) % mod;
      }
      dp[i] = res % mod;
  }
  cout<<dp[n];
}