#include<iostream>
#include<cstring>
using namespace std;

// int collecting_numbers(int arr[], int n){
//   int dp[n+1];
//   memset(dp,-1,sizeof(dp));
//   int rounds = 0;
//   for(int i = 0; i < n; i++){
//     if(dp[arr[i] - 1] == -1){
//       dp[arr[i]] = ++rounds;
//     }else{
//       dp[arr[i]] = dp[arr[i] - 1];
//     }
//   } 
//   return rounds;
// }

int collecting_numbers(int arr[], int n){
  int dp[n+1];
  memset(dp,-1,sizeof(dp));
  int rounds = 1;
  int min = arr[0];
  for(int i = 0; i < n; i++){
    if(arr[i] < min){
      min = arr[i];
      rounds++;
    }
  } 
  return rounds;
}

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  cout<<collecting_numbers(arr,n);
}