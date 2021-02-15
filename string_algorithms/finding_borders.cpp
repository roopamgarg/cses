#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;

void solve(string str){
  int pre = 0, suf = 0;
  int len = str.length();
  int p = 26;
  for(int i = 0; i < len - 1; i++){
    pre = (((pre * 26) % mod) + str[i]) % mod;
    if(i == 0){
      suf = str[len - i - 1];
    }else{
      suf = (suf + (p * str[len - i - 1]) % mod) % mod;
      p = (p * 26) % mod;
    }
    if(pre == suf){
      cout<<i+1<<" ";
    }
  }
}

int32_t main()
{
  string str;
  cin>>str;
  solve(str);
}