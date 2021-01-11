#include<iostream>
typedef long long ll;

using namespace std;

int main(){
  ll n,num, sum;
  cin>>n;
  sum = 0;
  for(int i = 0; i < n-1; i++){
    cin>>num;
    sum += num;
  }
  cout<<((n*(n+1))/2) - sum;
}