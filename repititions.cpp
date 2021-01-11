#include<iostream>

using namespace std;
int main(){
  string dna;
  cin>>dna;
  int longest = 1;
  int res = 1;
  for(int i = 1;i < dna.size(); i++){
    if(dna[i] == dna[i-1]){
      longest++;
    }else{
      longest = 1;
    }
    res = max(res,longest);
  }

  cout<<res;
}