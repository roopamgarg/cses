#include <iostream>
#include<vector>
#include <map>
using namespace std;

void create_string(map<char, int> freq, string str, int size, vector<string>& res)
{
  if(size == 0){
    res.push_back(str);
    //cout<<str<<endl;
    return;
  }
  for (const auto &ch : freq)
  {
    if (ch.second > 0)
    {
      freq[ch.first]--;
      create_string(freq, str + ch.first, size - 1,res);
      freq[ch.first]++;
    }
  }
}

int main()
{
  string str;
  cin >> str;
  map<char, int> freq;
  for (int i = 0; i < str.length(); i++)
  {
    freq[str[i]]++;
  }
  vector<string> res;
  create_string(freq,"",str.size(), res);
  cout<<res.size()<<endl;
  for(int i = 0; i < res.size(); i++){
    cout<<res[i]<<endl;
  }
}