#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
  public:

  int val;
  Node* next;
  Node(int val,Node* next){
    this->val = val;
    this->next = next;
  }
};

class LinkedList{
  public:
  Node* START, *LAST;
  LinkedList(){
    START = NULL;
    LAST = NULL;
  }
  void insert(int num){
    Node* node = new Node(num,NULL);
    if(START == NULL){
      START = node;
      LAST = node;
      node->next = START;

    }else{
      LAST->next = node;
      node->next = START;
      LAST = LAST->next;
    }
  }
  void deleteAll2nd(){
    while(START->next != START){
      cout<<START->next->val<<" ";
      Node* temp = START->next;
      START->next = START->next->next;
      START = START->next;
      delete temp;
    }
    cout<<START->val;
    
  }

};
int main(){
  int n;
  cin>>n;
  LinkedList list;
  for(int i = 1; i <= n; i++){

    list.insert(i);
  }
  list.deleteAll2nd();
}