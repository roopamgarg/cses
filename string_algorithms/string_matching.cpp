#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e17+7;
int match(string text, string pattern){
  int p_hash = pattern[0] - 'a' + 1;
  int p_len = pattern.length();
  vector<int> roll(text.length(),1);
  for(int i = 1; i < text.length(); i++){
    roll[i] = (26 * roll[i-1]) % mod;
  }
  int p = 26;
  for (int i = 1; i < p_len; i++)
  {
    p_hash = (((p_hash * 26) % mod) + (pattern[i] - 'a' + 1)) % mod; 
  }
  
  int hash = 0;
  for(int i = 0; i < p_len; i++){
    hash = ((hash * 26) + (text[i] - 'a' + 1)) % mod; 
  }

  int first_num = roll[roll.size() - 1];
  int count = hash == p_hash;
  for(int i = p_len; i < text.length(); i++){
    hash =  ((hash - roll[p_len-1] * (text[i - p_len] - 'a' + 1)) % mod + mod) % mod;
    hash = (hash * 26) % mod;
    hash = hash + (text[i] - 'a' + 1);
    if(hash == p_hash){
      count++;
    }
  }
  return count;
}

int32_t main()
{
  string text, pattern;
  cin>>text>>pattern;
  cout<<match(text,pattern);
}