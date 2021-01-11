#include<iostream>
#include<vector>
using namespace std;

vector<string> grey_codes(int n) {
  vector<string> arr;
  if(n == 1){
    arr.push_back("0");
    arr.push_back("1");
    return arr;
  }
  vector<string> prev = grey_codes(n-1);
  for(int i = 0; i < prev.size(); i++){
    arr.push_back("0" + prev[i]);
  }
  for(int i = prev.size() - 1; i >= 0; i--){
    arr.push_back("1" + prev[i]);
  }
  return arr;
}
int main(){
  int n;
  cin>>n;
  vector<string> codes = grey_codes(n);
  for(int i = 0; i < codes.size(); i++){
    cout<<codes[i]<<endl;
  }
}