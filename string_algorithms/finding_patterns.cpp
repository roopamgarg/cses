#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

class Vertex
{
public:
  char data;
  int parentIndex;
  unordered_map<char, int> childrens;
  bool isTerminal;
  int suffixLink;
  int outputLink;
  vector<int> wordsId;

  Vertex()
  {
    data = '\0';
    parentIndex = -1;
    isTerminal = false;
    suffixLink = 0;
    outputLink = 0;
    //wordId = -1;
  }
  Vertex(char ch, int pi)
  {
    data = ch;
    parentIndex = pi;
    isTerminal = false;
    suffixLink = -1;
    outputLink = -1;
   // wordId = -1;
  }
};

class Aho
{
public:
  vector<Vertex *> trei;
  vector<int> wordLength;
  int size = 0;
  int root = 0;
  Aho()
  {
    trei = vector<Vertex *>(1, new Vertex());
    wordLength = vector<int>(1, 0);
    size = 1;
  }
  void insert(string word, int wordId)
  {
    int cur_root = root;
    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      if (!trei[cur_root]->childrens.count(ch))
      {
        trei.push_back(new Vertex(ch, cur_root));
        trei[cur_root]->childrens[ch] = size++;
      }
      cur_root = trei[cur_root]->childrens[ch];
    }
    trei[cur_root]->isTerminal = true;
    trei[cur_root]->wordsId.push_back(wordId);
    wordLength.push_back(word.length());
  }

  void calculateSuffixLink(int vertexLink)
  {
    Vertex *vertex = trei[vertexLink];
    if (vertexLink == root)
    {
      vertex->outputLink = root;
      vertex->suffixLink = root;
      return;
    }
    if (vertex->parentIndex == root)
    {
      vertex->suffixLink = root;
      if (vertex->isTerminal)
      {
        vertex->outputLink = vertexLink;
      }
      else
      {
        vertex->outputLink = trei[vertex->suffixLink]->outputLink; // root
      }
      return;
    }

    int parentSuffixLink = trei[vertex->parentIndex]->suffixLink;
    while (true)
    {
      if (trei[parentSuffixLink]->childrens.count(vertex->data))
      {
        vertex->suffixLink = trei[parentSuffixLink]->childrens[vertex->data];
        break;
      }
      if (parentSuffixLink == root)
      {
        vertex->suffixLink = root;
        break;
      }
      parentSuffixLink = trei[parentSuffixLink]->suffixLink;
    }
    if (vertex->isTerminal)
    {
      vertex->outputLink = vertexLink;
    }
    else
    {
      vertex->outputLink = trei[vertex->suffixLink]->outputLink;
    }
  }

  void prepareAho()
  {
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      Vertex *curVertex = trei[cur];
      calculateSuffixLink(cur);
      for (pair<char, int> child : curVertex->childrens)
      {
        q.push(child.second);
      }
    }
  }

  void processString(string text,bool *res)
  {
    int cur_root = root;
    unordered_set<int> foundedIds;
    for (int i = 0; i < text.length(); i++)
    {
      char cur_char = text[i];
      while(true){
        Vertex* vertex = trei[cur_root];
        if(vertex->childrens.count(cur_char)){
          cur_root = vertex->childrens[cur_char];
         
          break;
        }

        if(cur_root == root){
          break;
        }
        cur_root = vertex->suffixLink;
      }

      int check_root = cur_root;
      while(true){
        check_root = trei[check_root]->outputLink;

        if(check_root == root){
          break;
        }
        vector<int> ids = trei[check_root]->wordsId;
        for(int i = 0; i < ids.size(); i++){
              if(foundedIds.count(ids[i])) break;
             res[ids[i]] = true;
             foundedIds.insert(ids[i]);
        }
        // for(int id: trei[check_root]->wordsId){
        //   res[id] = true;
        // }
        check_root = trei[check_root]->suffixLink;
      }
    }
    //return res;

  }
};

int32_t main()
{
  Aho aho;
  string str;
  cin >> str;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string dict_word;
    cin >> dict_word;
    aho.insert(dict_word, i);
  }
  aho.prepareAho();
  bool res[n];
  memset(res,0,sizeof(res)); 
  aho.processString(str,res);
  
  for(int i = 0; i < n; i++){
    if(res[i]){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
}