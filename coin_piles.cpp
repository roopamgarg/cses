#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int x, y;
    cin>>x>>y;
    if((x+y) % 3 == 0 && abs(x-y) <= max(x,y) / 2){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
}