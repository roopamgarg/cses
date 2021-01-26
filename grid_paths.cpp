#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

ll mod = 1000000000 + 7;

int main(){
  ll n;
  cin>>n;
  string board[n];
  ll dp[n][n];
  memset(dp,0,sizeof(dp));
  dp[0][0] = 1;
  for(ll i = 0; i < n; i++){
    cin>>board[i];
  }
  if(board[0][0] == '*'){
    cout<<0;
    return 0;
  }
  for(ll i = 1; i < n; i++){
    if(board[0][i] == '*') break;
    dp[0][i] = 1;
  }
  for(ll i = 1; i < n; i++){
    if(board[i][0] == '*') break;
    dp[i][0] = 1;
  }
  for(ll i = 1; i < n; i++){
    for(ll j = 1; j < n; j++){
      if(board[i][j] == '*'){
        continue;
      }
      dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
    }
  }
  cout<<dp[n-1][n-1] % mod; 
}