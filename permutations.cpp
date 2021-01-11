#include<iostream>

using namespace std;

int main(){
  int n;
  cin>>n; 
  if(n == 1){
    cout<<1;
    return 0;
  }
  if(n <= 3){
    cout<<"NO SOLUTION";
    return 0;
  }
  if(n == 4){

    for(int i = 2;i >= 1; i--){
      for(int j = i; j <= n; j+=2){
        cout<<j<<" ";
      }
    }
    return 0;
  }
  for(int i = 1;i <= 2; i++){
    for(int j = i; j <= n; j+=2){
      cout<<j<<" ";
    }
  }
}