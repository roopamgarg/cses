#include<iostream>
typedef long long ll;
using namespace std;

int main(){
  ll n;
  cin>>n;
  while(n != 1){
    cout<<n<<" ";
    if((n & 1) == 0){
      n /= 2;
    }else{
      n = n*3 + 1;
    }
  }
  cout<<n;
}