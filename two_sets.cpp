#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int main(){
  ll n;
  cin>>n;
  ll target = n * (n+1) / 2;
  if(target % 2 == 1){
    cout<<"NO";
    return 0;
  }else{
    target = target/2;
    ll max = n;
    vector<ll> used, unused;
    while(target > 0){
      while(max > target){
        unused.push_back(max);
        max--;
      }
      target -= max;
      used.push_back(max);
      max--;
    }
     while(max > target){
        unused.push_back(max);
        max--;
      }
    cout<<"YES"<<endl;
    cout<<used.size()<<endl;
    for(ll i = 0; i < used.size(); i++){
      cout<<used[i]<<" ";
    }
    cout<<endl<<unused.size()<<endl;
    for(ll i = 0; i < unused.size(); i++){
      cout<<unused[i]<<" ";
    }
  }
}