#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1000000007;
int solve(int n,int m){
  int len = n - m + 1; // 2
  
  vector<int> prefix(len,26); //[26,26]
  vector<int> suffix(len,26); //[26,26]
  prefix[0] = 1; //[ 1,26]
  suffix[len-1] = 1; //[26,1]
  for(int i = 1; i < len; i++){
    prefix[i] = ((prefix[i-1] % mod) * (prefix[i] % mod)) % mod;
  }
  for(int i = len-2; i >= 0; i--){
    suffix[i] = ((suffix[i+1] % mod) * (suffix[i] % mod)) % mod;
  }
  int res = 0;
  for(int p:prefix){
    cout<<p<<" ";
  }
  cout<<endl;

  for(int p:suffix){
    cout<<p<<" ";
  }
  cout<<endl;
  res += suffix[0] % mod;

  for(int i = 1; i < len-1; i++){
      res += ((prefix[i-1] % mod) * (suffix[i+1] % mod)) % mod;
  }
  res += prefix[len-1] % mod;

  return res;
}

  
int32_t main()
{
  int n;
  cin>>n;
  string str;
  cin>>str;
  int m = str.length();
  cout<<solve(n,m);
  return 0;
}