#include <iostream>
#include <map>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];
  map<int, int> occurred;
  int res = 0, last_repeat = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (occurred.find(arr[i]) != occurred.end() && occurred[arr[i]] >= last_repeat)
    {
      last_repeat = occurred[arr[i]] + 1;
      occurred.erase(arr[i]);
    }
    // occurred.insert(pair<int,int>(arr[i], i));
    occurred[arr[i]] = i;
    res = max(res,i - last_repeat + 1);
  }
    // cout<<occurred.max_size()<<endl;
    // cout<<occurred.size()<<endl;

  cout << res;
}