#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1000000007;

class Node
{
public:
  char data;
  unordered_map<char, Node *> childrens;
  bool isTerminal;
  Node()
  {
    data = '\0';
    isTerminal = false;
  }
  Node(char ch)
  {
    data = ch;
    isTerminal = false;
  }
};
class Trei
{
  Node *ROOT;
  vector<int> dp;

public:
  Trei(int word_size)
  {
    ROOT = new Node();
    dp = vector<int>(word_size, -1);
  }
  void insert(Node *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }
    char ch = word[0];
    string left = word.substr(1);
    if (!root->childrens.count(ch))
    {
      root->childrens[ch] = new Node(ch);
    }
    insert(root->childrens[ch], left);
  }
  void display(Node* root, string osf = ""){
    if(root->isTerminal){
      cout<<osf<<endl;
    }
    for(pair<char,Node*> node : root->childrens){
      display(node.second,osf+node.first);
    }
  }
  int check(Node *root, string word, int index = 0)
  {
    if (word.length() == index) return 1;
    
    if (dp[index] != -1)
      return dp[index];

    Node *temp = root;
    int ans = 0;

    for (int i = index; i < word.length(); i++)
    {
      if (temp->childrens.count(word[i]))
      {
        temp = temp->childrens[word[i]];
        if (temp->isTerminal)
        {

          ans = (ans + check(ROOT, word, i+1)) % mod;
        }
      }
      else
      {
        break;
      }
    }
    // cout<<word[index]<<" "<<ans<<endl;

    return dp[index] = ans;
  }

  void insert(string &word)
  {
    insert(ROOT, word);
  }

  int check(string &word)
  {
    return check(ROOT, word);
  }
  void display(){
    display(ROOT);
  }
};

int32_t main()
{
  clock_t begin = clock();

  string str;
  cin >> str;
  int n;
  cin >> n;
  Trei set(str.length());
  unordered_map<string, int> cache;
  for (int i = 0; i < n; i++)
  {
    string word;
    cin >> word;
    set.insert(word);
  }
 // set.display();
  cout << set.check(str);
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}