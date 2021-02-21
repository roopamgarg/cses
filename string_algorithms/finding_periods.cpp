#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> calculateZ(string str){
  int len = str.length();
  vector<int> Z(len,0);
  int left = 0, right = 0;
  for(int i = 1; i < len; i++){
    if(i > right){
      left = right = i;
      while(right < len && str[right] == str[right - i]){
        right++;
      }
      Z[i] = right - left;
      right--;
    }else{
      int diff = i - left;
      if(i + Z[diff] <= right){
        Z[i] = Z[diff];
      }else{
        left = i;
        while(right < len && str[right] == str[right - i]){
          right++;
        }
        Z[i] = right - left;
        right--;
      }
    }
  }
  return Z;
}


bool solve(string str,int len,int index){
  for(int i = 0; i < len; i++){
    if(index + i == str.length()){
      return true;
    }
    if(str[index + i] != str[i]){
      return false;
    }
  }
  return solve(str,len,index + len);
}
int32_t main()
{
  string str;
  cin>>str;
  vector<int> Z = calculateZ(str);
  vector<bool> check(str.length()+1,false);
  check[str.length()] = true;
  // for(int num:Z){
  //   cout<<num<<" ";
  // }
 // cout<<endl;
  for(int i = str.length()  - 1; i > 0 ; i--){
   //  cout<<i<<" ";

    if(Z[i] > 0 && (Z[i] + i >= str.length())){
      check[i] = true;
    }

  }
//  cout<<endl;

  for(int i = 0; i < check.size(); i++){
    if(check[i])
    cout<<i<<" ";
  }
}