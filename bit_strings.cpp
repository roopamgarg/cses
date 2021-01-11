#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int mod = 1000000007; 
  int res = 2;
  while(--n){
    res = (res * 2) % mod;
  }
  cout<<res;
}