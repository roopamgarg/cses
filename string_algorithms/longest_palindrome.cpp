#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> solve(string str){
  vector<int> longest(str.length(),1);
  int left = 0;
  int right = 0;
  int comp = 0;
  for(int i = 1; i < str.length(); i++){
    if(i > right){
      //  cout<<"prune"<<endl;

      left = right = i;
      while(left >= 0 && right < str.length() && str[left] == str[right]){
        left--;
        right++;
        comp++;
      }
      left++;
      right--;
      longest[i] = right - left + 1;
    }else{
      int dist_from_right = right - i;
      int left_index = left + dist_from_right;
      if(((longest[left_index] - 1) / 2) + i < right){
        // cout<<"saved"<<endl;
        longest[i] = longest[left_index];
      }else{
        //cout<<"prune"<<endl;

        left = i - dist_from_right;
        while(left >= 0 && right < str.length() && str[left] == str[right]){
          left--;
          right++;
          comp++;

        }
        left++;
        right--;
        longest[i] = right - left + 1;
      }
    }
  }
  //cout<<comp<<endl;
  return longest;
}

int32_t main()
{
  string str;
  cin>>str;
  vector<int> res = solve(str);
  string even_str = "#";
  for(char ch:str){
    even_str += ch;
    even_str += '#';

  }
  vector<int> res2 = solve(even_str);
  int final_res = 0;
  int index = 0;
  for(int i = 0;i < res.size(); i++){
    if(res[i] > final_res){
      index = i - res[i]/2;
      final_res = res[i];
    }
  }
  for(int i = 0;i < res2.size(); i++){
   // cout<<res2[i]<<" ";
    if(res2[i]/2 > final_res){
      index = i / 2 - res2[i] / 4;
      final_res = res2[i] / 2;
    }
  }

  cout<<str.substr(index,final_res);
  return 0;
}