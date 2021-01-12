#include <unordered_map>
#include <iostream>
#include<vector>
using namespace std;
int changeGap(vector<int> &gaps, vector<int> &position, int pos, int &count)
{
  int prev = gaps[pos];
  gaps[pos] = position[pos + 1] - position[pos];
  if (prev > 0 && gaps[pos] < 0)
  {
    count++;
  }else if(prev < 0 && gaps[pos] > 0){
    count--;
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> gaps(n + 1), arr(n+1), position(n+1);
  gaps[n] = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    position[arr[i]] = i;
  }
  int count = 0;
  for (int i = 1; i < n; i++)
  {
    gaps[i] = position[i + 1] - position[i];
    if (gaps[i] < 0)
    {
      count++;
    }
  }
  int q[m][2],res[m];
  
  for (int i = 0; i < m; i++)
  {
    cin>>q[i][0]>>q[i][1];
  }
  for (int i = 0; i < m; i++)
  {
    int first = q[i][0], second = q[i][1];
    int num1 = arr[first], num2 = arr[second];
    int temp = position[num1];
    position[num1] = position[num2];
    position[num2] = temp;

    int temp2 = arr[first];
    arr[first] = arr[second];
    arr[second] = temp2;
    changeGap(gaps, position, num1, count);
    if (num1 - 1 > 0)
    {
      changeGap(gaps, position, num1 - 1, count);
    }
    changeGap(gaps, position, num2, count);
    if (num2 - 1 > 0)
    {
      changeGap(gaps, position, num2 - 1, count);
    }
    res[i] = count + 1;
  }
  for(int i = 0; i <m; i++){
    cout<<res[i]<<endl;
  }
}