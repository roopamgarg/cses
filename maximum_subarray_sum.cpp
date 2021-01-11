#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  long sum = INT_MIN;
  long res = INT_MIN;
  for(int i = 0; i < n; i++){
    long num;
    cin>>num;
    sum = max(sum + num,num);
    res = max(res,sum);
  
  }
  cout<<res;
}