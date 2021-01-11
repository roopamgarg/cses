#include<iostream>
typedef long long ll;
using namespace std;

int main(){
  ll t;
  cin>>t;
  while(t--){
    ll row,col;
    cin>>row>>col;
    row = row-1;
    col = col-1;
    if(row >= col){
      ll max = (ll)((row + 1) * (row + 1));
      ll min = (row * row) + 1; 
      if((row & 1) == 0){
        cout<<(ll)(min + col)<<endl;
      }else{
        cout<<(ll)(max - col)<<endl;
      }
    }else{
      ll max = (ll)((col + 1) * (col + 1));
      ll min = (col * col) + 1; 
      if((col & 1) == 0){
        cout<<(ll)(max - row)<<endl;
      }else{
        cout<<(ll)(min + row)<<endl;
      }
    }
  }
}