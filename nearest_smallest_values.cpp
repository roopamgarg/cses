#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Pair{
  public:
  int value,pos;
  Pair(int v, int p){
    value = v;
    pos = p;
  }
};

int main(){
  int n;
  cin>>n;
  stack<Pair> stk;

  for(int i = 0; i < n; i++){
    int num;
    cin>>num;
    while(!stk.empty() && stk.top().value >= num){
      stk.pop();
    }
    if(!stk.empty()){
      cout<<stk.top().pos + 1<<" ";
    }else{
      cout<<0<<" ";
    }
    stk.push(Pair(num,i));
  }
}