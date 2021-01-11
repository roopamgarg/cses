#include<iostream>
#define ll long long
using namespace std;

int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    if(n <= 9) {
      cout<<n<<endl;
      continue;
    }
    ll cur = 9;
    ll digits = 1;
    ll end = 9;
    n = n - 9;
    while(n - cur * 10 * (++digits) > 0){
      cur = cur * 10;
      end += cur;
      n -= cur * digits;
    }
    end += n / digits;
    //cout<<end<<":"<<endl;
    if(n%digits == 0){
      cout<<end - (end - (end % 10))<<endl;
    }else{
      string str = to_string(end + 1);
      cout<<str[n%digits-1]<<endl;  
    }

  }
}