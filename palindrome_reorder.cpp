#include <iostream>
#include <vector>
using namespace std;

int main()
{
  string str;
  cin >> str;
  int len = str.length();
  vector<int> alphabets(26, 0);
  char res[len];
  for (int i = 0; i < len; i++)
  {
    alphabets[str[i] - 65]++;
  }
  int start = 0;
  int end = len - 1;
  bool odd_status = false;
  for (int i = 0; i < 26; i++)
  {
    if (alphabets[i] % 2 == 1 && (len % 2 == 0 || odd_status))
    {
      cout << "NO SOLUTION";
      return 0;
    }
    while (alphabets[i] > 0)
    {

      if (alphabets[i] == 1)
      {
        res[len / 2] = (char)(i + 65);
        alphabets[i]--;
        odd_status = true;
      }
      else if (alphabets[i] > 1)
      {
        res[start++] = (char)(i + 65);
        res[end--] = (char)(i + 65);
        //cout<<(char)(i + 65);
        alphabets[i] -= 2;
      }
    }
  }
  for (int i = 0; i < len; i++)
  {
    cout << res[i];
  }
}